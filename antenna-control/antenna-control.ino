#include <Stepper.h>

const int stepsPerRevolution = 20;  // the number of steps per revolution

Stepper myStepper(stepsPerRevolution, 6, 7, 8, 9);

int x_status = 0;
int y_status = 0;

void setup() {
    // myStepper.setSpeed(60); // rpm
    Serial.begin(9600);
}

void motor_run(int speed, int direction) {
    myStepper.setSpeed(speed);
    if (direction>0)
        myStepper.step(stepsPerRevolution);
    else if (direction<0)
        myStepper.step(-stepsPerRevolution);
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

    // if (y_axis > 1000)
    // {
    //   y_status = 1;
    // }
    // else if (y_axis < 50)
    // {
    //   y_status = -1;
    // }
    // else
    // {
    //   y_status = 0;
    // }

    Serial.print(x_status);
    Serial.print(", ");
    Serial.println(y_status);
    delay(1);

    if (x_status == 1)
    {
        motor_run(200,1);
    }
    else if (x_status == -1)
    {
        motor_run(200,-1);
    }
    else if (x_status == 2)
    {
        motor_run(400,1);
    }
    else if (x_status == -2)
    {
        motor_run(400,-1);
    }
}

