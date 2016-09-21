import os
import json

CURRENT_DIR = os.path.dirname(os.path.realpath(__file__))
CURRENT_ARDUINO_CODE_DIR = "/Robot/CurrentArduinoCode"


class Generator:
    def __init__(self, appendage_dict):
        self.appendage_dict = appendage_dict

    def add_header(self):
        return "// Auto-generated by ArduinoGen\n\n"

    def add_includes(self):
        rv = "// Includes\n"
        rv += '#include "CmdMessenger.h"\n'
        keys = list(self.appendage_dict.keys())
        for i in range(1, 4):
            for key in keys:
                if not self.appendage_dict[key].TIER == i:
                    continue
                include = self.appendage_dict[key].get_includes()
                if include != "":
                    rv += include
        rv += "\n\n"

        rv += "// Globals\n"
        rv += "int ledState = HIGH;\n\n"

        return rv

    def add_pins(self):
        rv = "// Pin definitions\nconst char LED = 13;\n\n"
        for appendage in self.appendage_dict.values():
            pins = appendage.get_pins()
            if not pins == "":
                rv += pins
        rv += "\n"
        return rv

    def add_constructors(self):

        self.commands = {}

        rv = "// Constructors\n"
        rv += "// Attach a new CmdMessenger object to the default Serial port\n"
        rv += "CmdMessenger cmdMessenger = CmdMessenger(Serial);\n\n"
        rv += ("// This is the list of recognized commands. These can be " +
               "commands that can either be sent or received.\n")
        rv += ("// In order to receive, attach a callback function to these events\n")
        rv += "enum {\n"
        rv += "\tkAcknowledge,\n"
        self.commands['kAcknowledge'] = 0
        rv += "\tkError,\n"
        self.commands['kError'] = 1
        rv += "\tkUnknown,\n"
        self.commands['kUnknown'] = 2
        rv += "\tkSetLed,\n"
        self.commands['kSetLed'] = 3
        rv += "\tkPing,\n"
        self.commands['kPing'] = 4
        rv += "\tkPingResult,\n"
        self.commands['kPingResult'] = 5
        rv += "\tkPong,\n"
        self.commands['kPong'] = 6
        cmd_idx = 7
        for appendage in self.appendage_dict.values():
            cmds = appendage.get_commands()
            rv += cmds
            cmds = cmds.split(',\n')
            for cmd in cmds:
                cmd = cmd.replace('\t', '').replace('\n', '').replace(',', '')
                if not cmd == "":
                    self.commands[cmd] = cmd_idx
                    cmd_idx += 1
        rv = rv[:-2] + "\n};\n"

        for i in range(1, 4):
            for appendage in self.appendage_dict.values():
                if not appendage.TIER == i:
                    continue
                constructor = appendage.get_constructor()
                if not constructor == "":
                    rv += constructor + "\n"
        rv += "\n"
        return rv

    def add_setup(self):
        rv = "void setup() {\n\t// Init LED pin\n\tpinMode(LED, OUTPUT);\n\n"
        for appendage in self.appendage_dict.values():
            rv += appendage.get_setup()
        rv += "\t// Initialize Serial Communication\n\tSerial.begin(115200);\n\n"
        rv += "\t// Attach callback methods\n\tattachCommandCallbacks();\n\n"
        rv += "\n\t// Flash led 3 times at the end of setup\n"
        rv += "\tfor(int i = 0; i < 3; i++) {\n"
        rv += "\t\tdigitalWrite(LED, HIGH);\n"
        rv += "\t\tdelay(250);\n"
        rv += "\t\tdigitalWrite(LED, LOW);\n"
        rv += "\t\tdelay(250);\n"
        rv += "\t}\n"
        rv += "\tledState = LOW;\n"
        rv += "}\n"
        return rv

    def add_loop(self):
        rv = "void loop() {\n"
        rv += "\t// Process incoming serial data, and perform callbacks\n"
        rv += "\tcmdMessenger.feedinSerialData();\n"
        for appendage in self.appendage_dict.values():
            rv += appendage.get_loop_functions()
        rv += "}\n"
        return rv

    def add_commands(self):
        rv = "// Callbacks define on which received commands we take action\n"
        rv += "void attachCommandCallbacks() {\n"
        rv += "\t// Attach callback methods\n"
        rv += "\tcmdMessenger.attach(unknownCommand);\n"
        rv += "\tcmdMessenger.attach(kPing, ping);\n"
        rv += "\tcmdMessenger.attach(kSetLed, setLed);\n"
        for appendage in self.appendage_dict.values():
            rv += appendage.get_command_attaches()
        rv += "}\n\n"

        rv += "// Called when a received command has no attached function\n"
        rv += "void unknownCommand() {\n"
        rv += "\tcmdMessenger.sendCmd(kError, kUnknown);\n"
        rv += "}\n\n"

        rv += "// Called upon initialization of Spine to check connection\n"
        rv += "void ping() {\n"
        rv += "\tcmdMessenger.sendBinCmd(kAcknowledge, kPing);\n"
        rv += "\tcmdMessenger.sendBinCmd(kPingResult, kPong);\n"
        rv += "}\n\n"

        rv += "// Callback function that sets led on or off\n"
        rv += "void setLed() {\n"
        rv += "\t// Read led state argument, interpret string as boolean\n"
        rv += "\tledState = cmdMessenger.readBoolArg();\n"
        rv += "\tdigitalWrite(LED, ledState);\n"
        rv += "\tcmdMessenger.sendBinCmd(kAcknowledge, kSetLed);\n"
        rv += "}\n\n"
        for appendage in self.appendage_dict.values():
            rv += appendage.get_command_functions()
        return rv

    def add_extra_functions(self):
        rv = ""
        for appendage in self.appendage_dict.values():
            rv += appendage.get_extra_functions()
        return rv

    def write_shell_scripts(self, writeTo, arduino):
        upload_fo = open("{0:s}/upload.sh".format(writeTo), 'w')
        upload_fo.write("#!/usr/bin/env bash\n")
        upload_fo.write("cd {0:s}/{1:s}\n".format(CURRENT_ARDUINO_CODE_DIR, arduino))
        upload_fo.write("git add -A\n")
        upload_fo.write('git commit -m "new uploaded arduino code for %s"\n' % arduino)
        upload_fo.write("git push\n")
        upload_fo.write("pio run -t upload\n")
        upload_fo.close()
        os.chmod("{0:s}/upload.sh".format(writeTo), 0o777)

        serial_fo = open("{0:s}/serial.sh".format(writeTo), 'w')
        serial_fo.write("#!/usr/bin/env bash\n")
        serial_fo.write("picocom /dev/%s -b 115200 --echo\n" % arduino)
        serial_fo.close()
        os.chmod("{0:s}/serial.sh".format(writeTo), 0o777)

    def write_core_config_file(self, writeTo, arduino):
        core_config = {}
        core_config['appendages'] = []

        for appendages in self.appendage_dict.values():
            for appendage in appendages.get_core_values():
                core_config['appendages'].append(appendage)

        core_config['commands'] = self.commands

        with open("{0:s}/{1:s}_core.json".format(writeTo, arduino), 'w') as fo:
            fo.write(json.dumps(core_config, indent=4))
        os.chmod("{0:s}/{1:s}_core.json".format(writeTo, arduino), 0o777)
