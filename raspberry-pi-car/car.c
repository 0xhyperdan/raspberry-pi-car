//
//  car.c
//  raspberry-pi-car
//
//  Created by 丛晓丹 on 2019/2/19.
//  Copyright © 2019 丛晓丹. All rights reserved.
//

#include "car.h"

int main(int argc, const char * argv[]) {
    initCar();
    char input;
    for (;;) {
        scanf("%c", &input);
        printf("input commond :%c\n", input);
        switch (input) {
            case 'w': // forward
                forward();
                break;
            case 'a': // left
                left();
                break;
            case 'd': // right
                right();
                break;
            case 's': // stop
                stop();
                break;
            default:
                break;
        }
    }
    return EXIT;
}

void initCar(){
    printf("initCar\n");
    wiringPiSetup();
    
    // L298N PWM
    softPwmCreate (EN_A ,0, 100);
    softPwmCreate (EN_B ,0, 100);
    // Motor
    pinMode(IN_1, OUTPUT);
    digitalWrite(IN_1, LOW);
    pinMode(IN_2, OUTPUT);
    digitalWrite(IN_2, LOW);
    pinMode(IN_3, OUTPUT);
    digitalWrite(IN_3, LOW);
    pinMode(IN_4, OUTPUT);
    digitalWrite(IN_4, LOW);
}

void forward(){
    printf("forward\n");
    // pwm
    softPwmWrite(EN_A, 100);
    softPwmWrite(EN_B, 100);
    // left
    digitalWrite(IN_1, HIGH);
    digitalWrite(IN_2, HIGH);
    // right
    digitalWrite(IN_3, HIGH);
    digitalWrite(IN_4, LOW);
}

void right(){
    printf("right\n");
    // pwm
    softPwmWrite(EN_A, 60);
    softPwmWrite(EN_B, 30);
    // left
    digitalWrite(IN_1, HIGH);
    digitalWrite(IN_2, HIGH);
    // right
    digitalWrite(IN_3, LOW);
    digitalWrite(IN_4, HIGH);
}

void left(){
    printf("left\n");
    // pwm
    softPwmWrite(EN_A, 30);
    softPwmWrite(EN_B, 60);
    // left
    digitalWrite(IN_1, LOW);
    digitalWrite(IN_2, HIGH);
    // right
    digitalWrite(IN_3, HIGH);
    digitalWrite(IN_4, LOW);
}

void back(){
    printf("back\n");
    // pwm
    softPwmWrite(EN_A, 50);
    softPwmWrite(EN_B, 50);
    // left
    digitalWrite(IN_1, LOW);
    digitalWrite(IN_2, HIGH);
    // right
    digitalWrite(IN_3, LOW);
    digitalWrite(IN_4, HIGH);
}

void stop(){
    printf("stop\n");
    // pwm
    softPwmWrite(EN_A, 0);
    softPwmWrite(EN_B, 0);
    // left
    digitalWrite(IN_1, LOW);
    digitalWrite(IN_2, LOW);
    // right
    digitalWrite(IN_3, LOW);
    digitalWrite(IN_4, LOW);
}
