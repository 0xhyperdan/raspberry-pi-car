//
//  car.h
//  raspberry-pi-car
//
//  Created by 丛晓丹 on 2019/2/19.
//  Copyright © 2019 丛晓丹. All rights reserved.
//

#ifndef car_h
#define car_h

#define EN_A 4
#define EN_B 5

#define IN_1 0
#define IN_2 1
#define IN_3 2
#define IN_4 3

//#define EXIT 0

#include <stdio.h>
#include <stdlib.h>
#include <wiringPi.h>
#include <softPwm.h>

#endif /* car_h */
// 前进
void forward(void);
// 倒车
void back(void);
// 左转
void left(void);
// 右转
void right(void);
// 停车
void stop(void);
// 初始化
void initCar(void);
