# raspberry-pi-car
🚗 树莓派小车(use wiringPi)

## Circuit diagram

![circuit diagram](/RaspberryCar_bb.png)

* NOTE: raspberry pi GND must be connect L298N GND interface. 

## Build

1. git clone this repo
2. cd project dir  `respberry-pi-car/respberry-pi-car/car/*`
3. run commond  `cc -o car car.c -lwiringPi -lpthread`
4. run commond  `sudo ./car`
5. keyboard input 'w' = forward、's' = back 、'a' = left 、 'd' = right 、 'space' or 'other' = stop , ANSI code control car.

* NOTE: your raspberry pi has the wiringPi library installed.

## EOF
