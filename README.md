# Android-controlled-car-with-speedcontrol
An android controlled automobile allows the user to control a battery power automobile wirelessly through an Android device. This system has a Bluetooth module as a medium of data transfer between the automobile and the Android device. The data received by the Bluetooth are processed by (8051 or atmega) microcontroller which performs the desired action. 
The Android device has an application which provides the user with a GUI (Graphic User Interface) to send the commands using their touch gesture. The commands are sent to the automobile through an active Bluetooth device in the form of string variables.
The robot is designed using DC motors and the direction of DC motors will be controlled by the commands received from the android application. The status of the robot is also sent back to the Android app.

![](https://github.com/Sankul2699/Android-controlled-car-with-speedcontrol/blob/master/images/bot%20image.jpeg)

## Video Demonstration
[RC Car with speed control using 8051](https://www.youtube.com/watch?v=-ZegOrQuoXg)


## HC-05 Bluetooth Module:
HC-05 is a serial Bluetooth module. It can be configured using AT commands. It can work in three different configurations (Master, Slave, Loop back). In our project we will be using it as a slave. The features of HC-05 module includes,
-Typical -80dBm sensitivity.
-	Default baud rate: 9600bps, 8 data bits, 1 stop bit, no parity.
-	Auto-pairing pin code: “1234” default pin code
-	It has 6 pins.
-	Vcc and Gnd pins are used for powering the HC-05.
-	Tx and Rx pins are used for communicating with the microcontroller.
-	Enable pin for activating the HC-05 module. when it is low , the module is disabled
-	State pin acts status indicator. When it is not paired/connected with any other Bluetooth device, LED flashes continuously. When it is connected/paired with any other Bluetooth device, then the LED flashes with the constant delay of 2 seconds.

![](https://github.com/Sankul2699/Android-controlled-car-with-speedcontrol/blob/master/images/hc05.JPG)

# L293D Motor Driver IC:
L293D is a dual H-bridge motor driver IC. This acts as a current amplifier, the output of L293D drives the DC Motors. It contains two inbuilt H-bridge circuits. In common mode of operation , it can drive two dc motors simultaneously in both the directions. The below table shows the pin description of L293D IC. 


![](https://github.com/Sankul2699/Android-controlled-car-with-speedcontrol/blob/master/images/motor_driver.JPG)
# Working

In this Smart Phone controlled Robot, the user of android app sends the data to 8051 microcontroller through HC-05 module. The received data is compared in 8051 microcontroller and the decision is made accordingly. The below table shows the direction of motors and status of robot for different received characters.

![](https://github.com/Sankul2699/Android-controlled-car-with-speedcontrol/blob/master/images/table.JPG)

The Bluetooth terminal app allows us to emulate a Bluetooth terminal. This app supports bidirectional communication and this app is compatible with most of the devices.
The steps below show how to install and use this app.
- Download and install Bluetooth terminal app on your android phone. The app can be downloaded from the Google  play store.
  [Bluetooth terminal app](https://play.google.com/store/apps/details?id=ptah.apps.bluetoothterminal)
- After installing the app, open the app and turn on Bluetooth.
- Select the device and click on connect option. After successful connection, we  can start sending data to HC-05 module.
  In our project we have used  the concept of pulse width modulation so that our robot can accelerate
 And can move in different speeds depending on the character sent by Bluetooth terminal.
Ex: ‘l’ for low speed
‘a’ for acceleration 



