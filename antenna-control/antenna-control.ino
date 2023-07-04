#include <Stepper.h>

const int stepsPerRevolution = 20;  // the number of steps per revolution

Stepper stepper_1(stepsPerRevolution, 6, 7, 8, 9);
Stepper stepper_2(stepsPerRevolution, 2, 3, 4, 5);

int x_status = 0;
int y_status = 0;

void setup() {
    Serial.begin(9600);
}

void motor_1_run(int speed, int direction) {
    stepper_1.setSpeed(speed);
    if (direction>0)
        stepper_1.step(stepsPerRevolution);
    else if (direction<0)
        stepper_1.step(-stepsPerRevolution);
}

void motor_2_run(int speed, int direction) {
    stepper_2.setSpeed(speed);
    if (direction>0)
        stepper_2.step(stepsPerRevolution);
    else if (direction<0)
        stepper_2.step(-stepsPerRevolution);
}

void loop() {
    int x_axis = analogRead(A0);
    int y_axis = analogRead(A1);

    Serial.print(x_axis);
    Serial.print(", ");
    Serial.println(y_axis);

    x_status = 0;
    y_status = 0;

    if (x_axis > 700)
    {
        x_status = 1;
    }
    if (x_axis > 1000)
    {
        x_status = 2;
    }
    if (x_axis < 350)
    {
        x_status = -1;
    }
    if (x_axis < 100)
    {
        x_status = -2;
    }


    if (y_axis > 700)
    {
        y_status = 1;
    }
    if (y_axis > 1000)
    {
        y_status = 2;
    }
    if (y_axis < 350)
    {
        y_status = -1;
    }
    if (y_axis < 100)
    {
        y_status = -2;
    }

    Serial.print(x_status);
    Serial.print(", ");
    Serial.println(y_status);
    delay(1);

    if (x_status == 1)
    {
        motor_1_run(200,1);
    }
    else if (x_status == -1)
    {
        motor_1_run(200,-1);
    }
    else if (x_status == 2)
    {
        motor_1_run(400,1);
    }
    else if (x_status == -2)
    {
        motor_1_run(400,-1);
    }

    if (y_status == 1)
    {
        motor_2_run(200,1);
    }
    else if (y_status == -1)
    {
        motor_2_run(200,-1);
    }
    else if (y_status == 2)
    {
        motor_2_run(400,1);
    }
    else if (y_status == -2)
    {
        motor_2_run(400,-1);
    }
}

