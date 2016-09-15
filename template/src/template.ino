// Auto-generated by ArduinoGen

// Includes
#include "Servo.h"
#include "Stepper.h"
#include <Wire.h>
#include "I2CEncoder.h"
#include "Motor.h"
#include "Encoder.h"

#include "NewPing.h"
#include "PID.h"
#include "vPID.h"
#include "Arm.h";
#include "VelocityControlledMotor.h";
#include "FourWheelDrive.h"

#define STR1(x)  #x
#define STR(x)  STR1(x)

// Globals
int ledState = HIGH;
// Command parsing
const int MAX_ARGS = 6;
String args[MAX_ARGS];
int numArgs = 0;

// Pin definitions
const char LED = 13;
const char template_servo_pin = 5;

const char template_line_sensor1_pin = 13;
const char template_line_sensor0_pin = 4;

const char template_stepper_pinA = 16;
const char template_stepper_pinB = 14;
const char template_stepper_pinC = 6;
const char template_stepper_pinD = 9;

const char template_encoder0_pinA = 4;
const char template_encoder0_pinB = 8;
const char template_encoder1_pinA = 16;
const char template_encoder1_pinB = 6;

const char template_ultrasonic_pin = 8;

const char template_button0_pin = 10;
const char template_button1_pin = 15;
const char template_button2_pin = 15;
const char template_button3_pin = 14;
const char template_limit_switch0_pin = 9;
const char template_limit_switch1_pin = 5;
const char template_limit_switch2_pin = 10;
const char template_limit_switch3_pin = 14;
const char template_switch0_pin = 4;
const char template_switch1_pin = 2;
const char template_switch2_pin = 5;
const char template_switch3_pin = 14;


// Constructors
const char template_servo_index = 0;
char servo_pins[1] = {
	template_servo_pin
};
Servo servos[1];

const char template_line_sensor1_index = 0;
char digital_linesensors[1] = {
	template_line_sensor1_pin
};
const char template_line_sensor0_index = 0;
char analog_linesensors[1] = {
	template_line_sensor0_pin
};

const char template_stepper_index = 0;
Stepper steppers[1] = {
	Stepper(3, template_stepper_pinA, template_stepper_pinB, template_stepper_pinC, template_stepper_pinD)
};

const char template_i2c_encoder1_index = 0;
const char template_i2c_encoder0_index = 1;
I2CEncoder i2cencoders[2];

const char template_monster_moto_motor0_index = 0;
const char template_monster_moto_motor1_index = 1;
const char template_rover_five_motor0_index = 2;
const char template_rover_five_motor1_index = 3;
Motor motors[4] = {
	Motor(9, 13, 5, 0, MonsterMoto),
	Motor(12, 16, 10, 1, MonsterMoto),
	Motor(10, -1, 8, 0, RoverFive),
	Motor(11, -1, 15, 1, RoverFive)
};

const char template_encoder0_index = 0;
const char template_encoder1_index = 1;
Encoder encoders[2] = {
	Encoder(template_encoder0_pinA, template_encoder0_pinB),
	Encoder(template_encoder1_pinA, template_encoder1_pinB)
};

const char template_ultrasonic_index = 0;
NewPing ultrasonics[1] = {
	NewPing(template_ultrasonic_pin, template_ultrasonic_pin)
};

const char template_pid0_index = 0;
const char template_pid3_index = 1;
double lastPositions_vpid[2];
double Inputs_vpid[2], Setpoints_vpid[2], Outputs_vpid[2];
vPID vpids[2] = {
	vPID(&Inputs_vpid[template_pid0_index], &Outputs_vpid[template_pid0_index], &Setpoints_vpid[template_pid0_index], 4.100000, 0.200000, 2.100000, DIRECT),
	vPID(&Inputs_vpid[template_pid3_index], &Outputs_vpid[template_pid3_index], &Setpoints_vpid[template_pid3_index], 4.100000, 0.200000, 2.100000, DIRECT)
};
const char template_pid1_index = 0;
const char template_pid2_index = 1;
double lastPositions_pid[2];
double Inputs_pid[2], Setpoints_pid[2], Outputs_pid[2];
PID pids[2] = {
	PID(&Inputs_pid[template_pid1_index], &Outputs_pid[template_pid1_index], &Setpoints_pid[template_pid1_index], 4.100000, 0.200000, 2.100000, REVERSE),
	PID(&Inputs_pid[template_pid2_index], &Outputs_pid[template_pid2_index], &Setpoints_pid[template_pid2_index], 4.100000, 0.200000, 2.100000, REVERSE)
};

const char template_button0_index = 0;
const char template_button1_index = 1;
const char template_button2_index = 2;
const char template_button3_index = 3;
const char template_limit_switch0_index = 4;
const char template_limit_switch1_index = 5;
const char template_limit_switch2_index = 6;
const char template_limit_switch3_index = 7;
const char template_switch0_index = 8;
const char template_switch1_index = 9;
const char template_switch2_index = 10;
const char template_switch3_index = 11;
char switches[12] = {
	template_button0_pin,
	template_button1_pin,
	template_button2_pin,
	template_button3_pin,
	template_limit_switch0_pin,
	template_limit_switch1_pin,
	template_limit_switch2_pin,
	template_limit_switch3_pin,
	template_switch0_pin,
	template_switch1_pin,
	template_switch2_pin,
	template_switch3_pin
};

Arm arms[1] = {
	Arm(template_servo_index, template_servo_index, template_servo_index, template_servo_index, template_servo_index, servo_pins, servos)
};

VelocityControlledMotor vcms[1] = {
	VelocityControlledMotor(motors[template_rover_five_motor0_index], i2cencoders[template_i2c_encoder0_index], vpids[template_pid0_index], &Inputs_vpid[template_pid0_index], &Setpoints_vpid[template_pid0_index], &Outputs_vpid[template_pid0_index])
};

FourWheelDrive fwds = {{
	FourWheelDrive(&motors[template_monster_moto_motor0_index], &motors[template_monster_moto_motor0_index], &motors[template_monster_moto_motor0_index], &motors[template_monster_moto_motor0_index]),
	FourWheelDrive(&vcms[template_velocity_controlled_motor_index], &vcms[template_velocity_controlled_motor_index], &vcms[template_velocity_controlled_motor_index], &vcms[template_velocity_controlled_motor_index])
}};


void setup() {
    // Init LED pin
    pinMode(LED, OUTPUT);

	servos[template_servo_index].attach(template_servo_pin);

	pinMode(template_stepper_pinA, OUTPUT);
	pinMode(template_stepper_pinB, OUTPUT);
	pinMode(template_stepper_pinC, OUTPUT);
	pinMode(template_stepper_pinD, OUTPUT);
	steppers[template_stepper_index].setSpeed(9.000000);

    Wire.begin();
	i2cencoders[template_i2c_encoder1_index].init(MOTOR_393_TORQUE_ROTATIONS, MOTOR_393_TIME_DELTA);
	i2cencoders[template_i2c_encoder0_index].init(MOTOR_393_TORQUE_ROTATIONS, MOTOR_393_TIME_DELTA);
	i2cencoders[template_i2c_encoder1_index].setReversed(true);
	i2cencoders[template_i2c_encoder1_index].zero();
	i2cencoders[template_i2c_encoder0_index].zero();

	pinMode(9, OUTPUT);
	pinMode(13, OUTPUT);
	pinMode(5, OUTPUT);
	pinMode(12, OUTPUT);
	pinMode(16, OUTPUT);
	pinMode(10, OUTPUT);
	pinMode(10, OUTPUT);
	pinMode(11, OUTPUT);
	pinMode(template_encoder0_pinA, INPUT);
	pinMode(template_encoder0_pinB, INPUT);
	pinMode(template_encoder1_pinA, INPUT);
	pinMode(template_encoder1_pinB, INPUT);
	pinMode(template_button0_pin, INPUT_PULLUP);
	pinMode(template_button1_pin, INPUT);
	pinMode(template_button2_pin, INPUT);
	pinMode(template_button3_pin, INPUT_PULLUP);
	pinMode(template_limit_switch0_pin, INPUT_PULLUP);
	pinMode(template_limit_switch1_pin, INPUT);
	pinMode(template_limit_switch2_pin, INPUT);
	pinMode(template_limit_switch3_pin, INPUT_PULLUP);
	pinMode(template_switch0_pin, INPUT_PULLUP);
	pinMode(template_switch1_pin, INPUT);
	pinMode(template_switch2_pin, INPUT);
	pinMode(template_switch3_pin, INPUT_PULLUP);

    //Init Serial
    Serial.begin(115200);
}

/* The loop is set up in two parts. First the Arduino does the work it needs to
 * do for every loop, next is runs the checkInput() routine to check and act on
 * any input from the serial connection.
 */
void loop() {
    int inbyte;

    // Accept and parse serial input
    checkInput();
    for(int i = 0; i < 1; i++) {
			vcms[i].runVPID();
		}

}

void parse_args(String command) {
    numArgs = 0;
    int beginIdx = 0;
    int idx = command.indexOf(" ");

    String arg;
    char charBuffer[16];

    while (idx != -1)
    {
        arg = command.substring(beginIdx, idx);

        // add error handling for atoi:
        args[numArgs++] = arg;
        beginIdx = idx + 1;
        idx = command.indexOf(" ", beginIdx);
    }

    arg = command.substring(beginIdx);
    args[numArgs++] = arg;
}

/* This routine checks for any input waiting on the serial line. If any is
 * available it is read in and added to a 128 character buffer. It sends back
 * an error should the buffer overflow, and starts overwriting the buffer
 * at that point. It only reads one character per call. If it receives a
 * newline character is then runs the parseAndExecuteCommand() routine.
 */
void checkInput() {
    int inbyte;
    static char incomingBuffer[128];
    static char bufPosition=0;

    if(Serial.available()>0) {
        // Read only one character per call
        inbyte = Serial.read();
        if(inbyte==10||inbyte==13) {
            // Newline detected
            incomingBuffer[bufPosition]='\0'; // NULL terminate the string
            bufPosition=0; // Prepare for next command

            // Supply a separate routine for parsing the command. This will
            // vary depending on the task.
            parseAndExecuteCommand(String(incomingBuffer));
        }
        else {
            incomingBuffer[bufPosition]=(char)inbyte;
            bufPosition++;
            if(bufPosition==128) {
                Serial.println("error: command overflow");
                bufPosition=0;
            }
        }
    }
}

/* This routine parses and executes any command received. It will have to be
 * rewritten for any sketch to use the appropriate commands and arguments for
 * the program you design. I find it easier to separate the input assembly
 * from parsing so that I only have to modify this function and can keep the
 * checkInput() function the same in each sketch.
 */
void parseAndExecuteCommand(String command) {
    Serial.println("> " + command);
    parse_args(command);
    if(args[0].equals(String("ping"))) {
        if(numArgs == 1) {
            Serial.println("ok");
        } else {
            Serial.println("error: usage - 'ping'");
        }
    }
    else if(args[0].equals(String("le"))) { // led set
        if(numArgs == 2) {
            if(args[1].equals(String("on"))) {
                ledState = HIGH;
                digitalWrite(LED,HIGH);
                Serial.println("ok");
            } else if(args[1].equals(String("off"))) {
                ledState = LOW;
                digitalWrite(LED,LOW);
                Serial.println("ok");
            } else {
                Serial.println("error: usage - 'le [on/off]'");
            }
        } else {
            Serial.println("error: usage - 'le [on/off]'");
        }
    }
    else if(args[0].equals(String("rl"))) { // read led
        if(numArgs == 1) {
            Serial.println(ledState);
        } else {
            Serial.println("error: usage - 'rl'");
        }
    }
		else if(args[0].equals(String("ss"))){ // set servo
        if(numArgs == 3){
            int indexNum = args[1].toInt();
            if(indexNum > -1 && indexNum < 1){
                int value = args[2].toInt();
                if(!servos[indexNum].attached()){
                    servos[indexNum].attach(servo_pins[indexNum]);
                }
                servos[indexNum].write(value);
                Serial.println("ok");
            } else {
                Serial.println("Error: usage - ss [id] [value]");
            }
        } else {
            Serial.println("Error: usage - ss [id] [value]");
        }
    }
    else if(args[0].equals(String("sd"))){ // detach servo
        if(numArgs == 2){
            int indexNum = args[1].toInt();
            if(indexNum > -1 && indexNum < 1){
                servos[indexNum].detach();
                Serial.println("ok");
            } else {
                Serial.println("Error: usage - sd [id]");
            }
        } else {
            Serial.println("Error: usage - sd [id]");
        }
    }
		else if(args[0].equals(String("rdls"))){ // read digital linesensors
        if(numArgs == 2){
            int indexNum = args[1].toInt();
            if(indexNum > -1 && indexNum < 1){
                Serial.println(digitalRead(digital_linesensors[indexNum]));
            } else {
                Serial.println("Error: usage - rdls [id]");
            }
        } else {
            Serial.println("Error: usage - rdls [id]");
        }
    }
		else if(args[0].equals(String("rals"))){ // read analog linesensors
        if(numArgs == 2){
            int indexNum = args[1].toInt();
            if(indexNum > -1 && indexNum < 1){
                Serial.println(analogRead(analog_linesensors[indexNum]));
            } else {
                Serial.println("Error: usage - rals [id]");
            }
        } else {
            Serial.println("Error: usage - rals [id]");
        }
    }
		else if(args[0].equals(String("sssp"))){ // set stepper speed
    if(numArgs == 3){
        int indexNum = args[1].toInt();
        if(indexNum > -1 && indexNum < 1){
            int value = args[2].toInt();
            steppers[indexNum].setSpeed(balue);
            Serial.println("ok");
        } else {
            Serial.println("Error: usage - sssp [id] [value]");
        }
    } else {
        Serial.println("Error: usage - sssp [id] [value]");
    }
}
else if(args[0].equals(String("sss"))){ // step stepper
    if(numArgs == 3){
        int indexNum = args[1].toInt();
        if(indexNum > -1 && indexNum < 1){
            int value = args[2].toInt();
            stepper[indexNum].step(value);
            Serial.println("ok");
        } else {
            Serial.println("Error: usage - sss [id] [value]");
        }
    } else {
        Serial.println("Error: usage - sss [id] [value]");
    }
}
		else if(args[0].equals(String("sa"))) { // set arm
        if(numArgs == 7) {
            int indexNum = args[1].toInt();
            if(indexNum > -1 && indexNum < 1){
                int posbase = args[2].toInt();
                int posshoulder = args[3].toInt();
                int poselbow = args[4].toInt();
                int poswrist = args[5].toInt();
                int poswristrotate = args[6].toInt();

                arms[indexNum].set(posbase, posshoulder, poselbow, poswrist, poswristrotate);
                Serial.println("ok");
            } else {
                Serial.println("error: usage - 'sa [id] [base] [shoulder] [elbow] [wrist] [wristrotate]'");
            }
        } else {
            Serial.println("error: usage - 'sa [id] [base] [shoulder] [elbow] [wrist] [wristrotate]'");
        }
    }
    else if(args[0].equals(String("das"))) { // detach arm servos
        if(numArgs == 2) {
            int indexNum = args[1].toInt();
            if(indexNum > -1 && indexNum < 1){
                arms[indexNum].detach();
                Serial.println("ok");
            } else {
                Serial.println("error: usage - 'ds [id]'");
            }
        } else {
            Serial.println("error: usage - 'ds [id]'");
        }
    }
		else if(args[0].equals(String("vcmd"))) { // set velocity controlled motor voltage (no pid)
        if(numArgs == 7) {
            int indexNum = args[1].toInt();
            if(indexNum > -1 && indexNum < 1){
                int value = args[2].toInt();
                if( value < -1023 || value > 1023) {
                    Serial.println("Error: usage - vcmd [id] [value]");
                } else {
                    vcms[indexNum].setValue(value);
                    Serial.println("ok");
                }
            } else {
                Serial.println("error: usage - 'vcmd [id] [value]'");
            }
        } else {
            Serial.println("error: usage - 'vcmd [id] [value]'");
        }
    }
    else if(args[0].equals(String("vcms"))){ // set velocity controlled motor to stop
        if(numArgs == 2) {
            int indexNum = args[1].toInt();
            if(indexNum > -1 && indexNum < 1) {
                vcms[indexNum].stop();
                Serial.println("ok");
            } else {
                Serial.println("Error: usage - vcms [id]");
            }
        } else {
            Serial.println("Error: usage - vcms [id]");
        }
    }
    else if(args[0].equals(String("vcmsv"))){ // set velocity controlled motor's velocity
        if(numArgs == 3) {
            int indexNum = args[1].toInt();
            if(indexNum > -1 && indexNum < 1) {
                vcms[indexNum].setVelocity(toDouble(args[2]));
                Serial.println("ok");
            } else {
                Serial.println("Error: usage - vcmsv [id] [vel]");
            }
        } else {
            Serial.println("Error: usage - vcmsv [id] [vel]");
        }
    }
    else if(args[0].equals(String("vcmgv"))){ // get velocity controlled motor's velocity
        if(numArgs == 2) {
            int indexNum = args[1].toInt();
            if(indexNum > -1 && indexNum < 1) {
                char dts[256];
                dtostrf(vcms[indexNum].getVelocity(), 0, 6, dts);
                Serial.println(dts);
            } else {
                Serial.println("Error: usage - vcmgv [id]");
            }
        } else {
            Serial.println("Error: usage - vcmgv [id]");
        }
    }
    else if(args[0].equals(String("vcmgp"))){ // get velocity controlled motor's position
        if(numArgs == 2) {
            int indexNum = args[1].toInt();
            if(indexNum > -1 && indexNum < 1) {
                char dts[256];
                dtostrf(vcms[indexNum].getPosition(), 0, 6, dts);
                Serial.println(dts);
            } else {
                Serial.println("Error: usage - vcmgp [id]");
            }
        } else {
            Serial.println("Error: usage - vcmgp [id]");
        }
    }
		else if(args[0].equals(String("dfwd"))){ // drive four wheel drivebase
        if(numArgs == 6){
            int indexNum = args[1].toInt();
            if(indexNum > -1 && indexNum < 2){
                int leftfront = args[2].toInt();
                int rightfront = args[3].toInt();
                int leftback = args[4].toInt();
                int rightback = args[5].toInt();

                if(leftfront > -1024 && leftfront < 1024 &&
                   rightfront > -1024 && rightfront < 1024 &&
                   leftback > -1024 && leftback < 1024 &&
                   rightback > -1024 && rightback < 1024) {
                    fwds[indexNum].drive(leftfront, rightfront, leftback, rightback)
                    Serial.println("ok");
                } else {
                    Serial.println("Error: usage - dfwd [id] [lf] [rf] [lb] [rb]");
                }
            } else {
                Serial.println("Error: usage - dfwd [id] [lf] [rf] [lb] [rb]");
            }
        } else {
            Serial.println("Error: usage - dfwd [id] [lf] [rf] [lb] [rb]");
        }
    }
    else if(args[0].equals(String("sfwd"))){ // stop four wheel drivebase
        if(numArgs == 2){
            int indexNum = args[1].toInt();
            if(indexNum > -1 && indexNum < 2){
                fwds[indexNum].stop()
                Serial.println("ok");
            } else {
                Serial.println("Error: usage - sfwd [id]");
            }
        } else {
            Serial.println("Error: usage - sfwd [id]");
        }
    }
    else if(args[0].equals(String("dfwdp"))){ // drive four wheel drivebase with pid
        if(numArgs == 6){
            int indexNum = args[1].toInt();
            if(indexNum > -1 && indexNum < 2){
                double leftfront = toDouble(args[2]);
                double rightfront = toDouble(args[3]);
                double leftback = toDouble(args[4]);
                double rightback = toDouble(args[5]);

                fwds[indexNum].drivePID(leftfront, rightfront, leftback, rightback)
                Serial.println("ok");
            } else {
                Serial.println("Error: usage - dfwdp [id] [lf] [rf] [lb] [rb]");
            }
        } else {
            Serial.println("Error: usage - dfwdp [id] [lf] [rf] [lb] [rb]");
        }
    }
    else if(args[0].equals(String("fwdfl"))){ // get left side position
        if(numArgs == 2){
            int indexNum = args[1].toInt();
            if(indexNum > -1 && indexNum < 2){
                char dts[256];
                dtostrf(fwds[indexNum].getLeftPosition(), 0, 6, dts);
                Serial.println(dts);
            } else {
                Serial.println("Error: usage - dfwdp [id]");
            }
        } else {
            Serial.println("Error: usage - dfwdp [id]");
        }
    }
    else if(args[0].equals(String("fwdgr"))){ // get right side position
        if(numArgs == 2){
            int indexNum = args[1].toInt();
            if(indexNum > -1 && indexNum < 2){
                char dts[256];
                dtostrf(fwds[indexNum].getRightPosition(), 0, 6, dts);
                Serial.println(dts);
            } else {
                Serial.println("Error: usage - fwdgr [id]");
            }
        } else {
            Serial.println("Error: usage - fwdgr [id]");
        }
    }
		else if(args[0].equals(String("ep"))){ // i2c encoder position (in rotations)
        if(numArgs == 2){
            int indexNum = args[1].toInt();
            if(indexNum > -1 && indexNum < 2){
                char dts[256];
                dtostrf(i2cencoders[indexNum].getPosition(), 0, 6, dts);
                Serial.println(dts);
            } else {
                Serial.println("Error: usage - ep [id]");
            }
        } else {
            Serial.println("Error: usage - ep [id]");
        }
    }
    else if(args[0].equals(String("erp"))){ // i2c encoder raw position (in ticks)
        if(numArgs == 2){
            int indexNum = args[1].toInt();
            if(indexNum > -1 && indexNum < 2){
                char dts[256];
                dtostrf(i2cencoders[indexNum].getRawPosition(), 0, 6, dts);
                Serial.println(dts);
            } else {
                Serial.println("Error: usage - erp [id]");
            }
        } else {
            Serial.println("Error: usage - erp [id]");
        }
    }
    else if(args[0].equals(String("es"))){ // i2c encoder speed (in revolutions per minute)
        if(numArgs == 2){
            int indexNum = args[1].toInt();
            if(indexNum > -1 && indexNum < 2){
                char dts[256];
                dtostrf(i2cencoders[indexNum].getSpeed(), 0, 6, dts);
                Serial.println(dts);
            } else {
                Serial.println("Error: usage - es [id]");
            }
        } else {
            Serial.println("Error: usage - es [id]");
        }
    }
    else if(args[0].equals(String("ev"))){ // i2c encoder velocity (in revolutions per minute)
        if(numArgs == 2){
            int indexNum = args[1].toInt();
            if(indexNum > -1 && indexNum < 2){
                char dts[256];
                dtostrf(i2cencoders[indexNum].getVelocity(), 0, 6, dts);
                Serial.println(dts);
            } else {
                Serial.println("Error: usage - ev [id]");
            }
        } else {
            Serial.println("Error: usage - ev [id]");
        }
    }
    else if(args[0].equals(String("ez"))){ // i2c encoder zero
        if(numArgs == 2){
            int indexNum = args[1].toInt();
            if(indexNum > -1 && indexNum < 2){
                i2cencoders[indexNum].zero();
                Serial.println("ok");
            } else {
                Serial.println("Error: usage - ez [id]");
            }
        } else {
            Serial.println("Error: usage - ez [id]");
        }
    }
		else if(args[0].equals(String("mod"))){ // motor drive
        if(numArgs ==  3) {
            int indexNum = args[1].toInt();
            if(indexNum > -1 && indexNum < 4) {
                int value = args[2].toInt();
                if( value < -1023 || value > 1023) {
                    Serial.println("Error: usage - mod [id] [value]");
                } else {
                    motors[indexNum].drive(value);
                    Serial.println("ok");
                }
            } else {
                Serial.println("Error: usage - mod [id] [value]");
            }
        } else {
            Serial.println("Error: usage - mod [id] [value]");
        }
    }
    else if(args[0].equals(String("mos"))){ // motor stop
        if(numArgs == 2) {
            int indexNum = args[1].toInt();
            if(indexNum > -1 && indexNum < 4) {
                motors[indexNum].stop();
                Serial.println("ok");
            } else {
                Serial.println("Error: usage - mos [id]");
            }
        } else {
            Serial.println("Error: usage - mos [id]");
        }
    }
		else if(args[0].equals(String("re"))){ // read encoders
        if(numArgs == 2){
            int indexNum = args[1].toInt();
            if(indexNum > -1 && indexNum < 2){
                Serial.println(encoders[indexNum].read());
            } else {
                Serial.println("Error: usage - re [id]");
            }
        } else {
            Serial.println("Error: usage - re [id]");
        }
    }
    else if(args[0].equals(String("ze"))){ // zero encoders
        if(numArgs == 2){
            int indexNum = args[1].toInt();
            if(indexNum > -1 && indexNum < 2){
                encoders[indexNum].write(0);
                Serial.println("ok");
            } else {
                Serial.println("Error: usage - ze [id]");
            }
        } else {
            Serial.println("Error: usage - ze [id]");
        }
    }
		else if(args[0].equals(String("rus"))){ // read ultrasonics
        if(numArgs == 2){
            int indexNum = args[1].toInt();
            if(indexNum > -1 && indexNum < 1){
                unsigned int response = ultrasonics[indexNum].ping();
                Serial.println(response);
            } else {
                Serial.println("Error: usage - rus [id]");
            }
        } else {
            Serial.println("Error: usage - rus [id]");
        }
    }
    else if (args[0].equals(String("pc"))) { // Modify the pid constants
    if (numArgs == 5) {
      int indexNum = args[1].toInt();
      if (indexNum > -1 && indexNum < 2) {
        pids[indexNum].SetTunings(toDouble(args[2]), toDouble(args[3]), toDouble(args[4]));
        Serial.println("ok");
      } else {
        Serial.println(F("error: usage - 'pc [index] [kp] [ki] [kd]'"));
      }
    } else {
      Serial.println(F("error: usage - 'pc [index] [kp] [ki] [kd]'"));
    }
  }
  else if (args[0].equals(String("ps"))) { // Set the setpoint for a specific PID
    if (numArgs == 3) {
      int indexNum = args[1].toInt();
      if (indexNum > -1 && indexNum < 2) {
        pids[indexNum].SetMode(AUTOMATIC);
        Setpoints_pid[indexNum] = toDouble(args[2]);
        Serial.println(F("ok"));
      } else {
        Serial.println(F("error: usage - 'ps [index] [setpoint]'"));
      }
    } else {
      Serial.println(F("error: usage - 'ps [index] [setpoint]'"));
    }
  }
  else if (args[0].equals(String("poff"))) { // Turn off the PID
    if (numArgs == 2) {
      int indexNum = args[1].toInt();
      if (indexNum > -1 && indexNum < 2) {
        pids[indexNum].SetMode(MANUAL);
        Serial.println(F("ok"));
      } else {
        Serial.println(F("error: usage - 'poff [index]'"));
      }
    } else {
      Serial.println(F("error: usage - 'poff [index]'"));
    }
  }
  else if (args[0].equals(String("pd"))) { // Display Inputs, Setpoints, and Outputs
    if (numArgs == 2) {
      int indexNum = args[1].toInt();
      if (indexNum > -1 && indexNum < 2) {
        String ret = "";
        char dts[256];
        dtostrf(Inputs_pid[indexNum], 0, 6, dts);
        ret += dts;
        ret += " ";
        dtostrf(Setpoints_pid[indexNUm], 0, 6, dts);
        ret += dts;
        ret += " ";
        dtostrf(Outputs_pid[indexNum], 0, 6, dts);
        ret += dts;
        Serial.println(ret);
        } else {
        Serial.println(F("error: usage - 'pd [index]'"));
      }
    } else {
      Serial.println(F("error: usage - 'pd [index]'"));
    }
    }
    else if (args[0].equals(String("vpc"))) { // Modify the velocity pid constants
    if (numArgs == 5) {
      int indexNum = args[1].toInt();
      if (indexNum > -1 && indexNum < 2) {
        vpids[indexNum].SetTunings(toDouble(args[2]), toDouble(args[3]), toDouble(args[4]));
        Serial.println("ok");
      } else {
        Serial.println(F("error: usage - 'vpc [index] [kp] [ki] [kd]'"));
      }
    } else {
      Serial.println(F("error: usage - 'vpc [index] [kp] [ki] [kd]'"));
    }
  }
  else if (args[0].equals(String("vps"))) { // Set the setpoint for a specific PID
    if (numArgs == 3) {
      int indexNum = args[1].toInt();
      if (indexNum > -1 && indexNum < 2) {
        vpids[indexNum].SetMode(AUTOMATIC);
        Setpoints_vpid[indexNum] = toDouble(args[2]);
        Serial.println(F("ok"));
      } else {
        Serial.println(F("error: usage - 'vps [index] [setpoint]'"));
      }
    } else {
      Serial.println(F("error: usage - 'vps [index] [setpoint]'"));
    }
  }
  else if (args[0].equals(String("vpoff"))) { // Turn off the PID
    if (numArgs == 2) {
      int indexNum = args[1].toInt();
      if (indexNum > -1 && indexNum < 2) {
        vpids[indexNum].SetMode(MANUAL);
        Serial.println(F("ok"));
      } else {
        Serial.println(F("error: usage - 'vpoff [index]'"));
      }
    } else {
      Serial.println(F("error: usage - 'vpoff [index]'"));
    }
  }
  else if (args[0].equals(String("vpd"))) { // Display Inputs, Setpoints, and Outputs
    if (numArgs == 2) {
      int indexNum = args[1].toInt();
      if (indexNum > -1 && indexNum < 2) {
        String ret = "";
        char dts[256];
        dtostrf(Inputs_vpid[indexNum], 0, 6, dts);
        ret += dts;
        ret += " ";
        dtostrf(Setpoints_vpid[indexNum], 0, 6, dts);
        ret += dts;
        ret += " ";
        dtostrf(Outputs_vpid[indexNum], 0, 6, dts);
        ret += dts;
        Serial.println(ret);
      } else {
        Serial.println(F("error: usage - 'vpd [index]'"));
      }
    } else {
      Serial.println(F("error: usage - 'vpd [index]'"));
    }
}
		else if(args[0].equals(String("rs"))){ // read switches
        if(numArgs == 2){
            int indexNum = args[1].toInt();
            if(indexNum > -1 && indexNum < 12){
                Serial.println(digitalRead(switches[indexNum]));
            } else {
                Serial.println("Error: usage - rs [id]");
            }
        } else {
            Serial.println("Error: usage - rs [id]");
        }
    }
    else if(args[0].equals(String("ver"))) { // version information
        if(numArgs == 1) {
            String out = "Source last modified: ";
            out += __TIMESTAMP__;
            out += "\r\nPreprocessor timestamp: " __DATE__ " " __TIME__;
            out += "\r\nSource code line number: ";
            out += __LINE__;
            out += "\r\nUsername: " STR(__USER__);
            out += "\r\nDirectory: " STR(__DIR__);
            out += "\r\nGit hash: " STR(__GIT_HASH__);
            Serial.println(out);
        } else {
            Serial.println("error: usage - 'ver'");
        }
    }
    else {
        // Unrecognized command
        Serial.println("error: unrecognized command");
    }
}

double toDouble(String s)
{
  char buf[s.length() + 1];
  s.toCharArray(buf, s.length() + 1);
  return atof(buf);
}
