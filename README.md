# cell-phone-controlled-car <img align="right" src="https://visitor-badge.glitch.me/badge?page_id=pravesh-pandey.Cell_Phone_Controlled_car"/>

Project description-
   This project will consists two part, one is 3 wheeled car and the other is a mobile application which will control the car. We will be sending accelerometer data from our mobile via WiFi to the car ( NodeMCU module). and then after getting the data, on board micro controller (Arduino UNO) will navigate the car accordingly.

Project details and working-
  This project is an application of IoT. We are using Arduino UNO  as a micro- controller and ![Node MCU] (1.0 12E) as a WiFi module. The whole project consist of two part, i.e, app and car.

~App detail-
In this project we make our app using MIT app inventor. The app is design such as, it will fetch accelerometer data from the accelerometer sensor of our mobile phone and print it on the screen of the phone. Along with that it will send the same data to the NODE MCU in every 100ms in the form of string like -->
{ --x-axis--/--y-axis--/--z-axis--}  
   We have to just enter the local IP of the Node MCU and focus the switch when the WiFi module is connected.
~Car Details-
Node MCU will get some data through the app and then The on board micro- controller receives the data from Node MCU by Serial-communication and apply some linear equations to, generate a voltage signal which vary on a scale of 0 to 5 Volts on the basis of magnitude and sign of the data of X and Y axis. The signal then sent to the on board motor driver (L298N) which amplify the voltage on a scale of 0 to 12 Volts. This voltage is then sent to the motors. The same motor driver can send different data to the two motors which helps to change the direction and speed of the car.the car is powered by a on board 11.5V LiPo battery.

Components Used
1.Arduino UNO
2.L298N
3.Node MCU 1.0 12E
4.LiPo Battery
5.Two DC motors
6.Two Wheels
7.Castor Wheel 
8.Breadboard
9.Jumper Wires
10.Chassis


