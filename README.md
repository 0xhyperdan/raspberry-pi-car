# raspberry-pi-car
🚗 树莓派小车(use wiringPi)

## Circuit diagram

![circuit diagram](/RaspberryCar_bb.png)

* NOTE: raspberry pi GND must be connect L298N GND interface. 

## Build keyboard control

1. git clone this repo
2. cd project dir  `raspberry-pi-car/respberry-pi-car/car/*`
3. run commond  `gcc -o car car.c -lwiringPi -lpthread`
6. run commond  `sudo ./car`
7. keyboard input 'w' = forward、's' = back 、'a' = left 、 'd' = right 、 'space' or 'other' = stop , ANSI code control car.

* NOTE: remember comment unselect "main" method.

## Build android client control with socket

1. git clone this repo
2. cd project dir  `raspberry-pi-car/raspberry-pi-car/server/* `
3. run commond `gcc -o server server.c ../car/car.c -lwiringPi -lpthread`
4. run commond  `sudo ./server`
5. socket send  commond to server 'w' = forward、's' = back 、'a' = left 、 'd' = right 、 'space' or 'other' = stop , ANSI code control car.

* NOTE: your raspberry pi has the wiringPi library installed.

## EOF
