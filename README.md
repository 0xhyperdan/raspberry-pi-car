# raspberry-pi-car
🚗 树莓派小车(use wiringPi)

## Circuit diagram

![circuit diagram](/RaspberryCar_bb.png)

## Build

1. git clone this repo
2. cd project dir  `respberry-pi-car/respberry-pi-car/car/*`
3. run commond  `cc -o car car.c -lwiringPi -lpthread`
4. run commond  `sudo ./car`
5. keyboard input 'w' 、's' 、'a' 、 'd' 、 ' ' , ANSI code control car 'forward','back','left','right'.

* NOTE: your raspberry pi has the wiringPi library installed.

## EOF
