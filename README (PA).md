# Parking-Assistance---Arduino

**_AIM:_** Assist the parking of a vehicle(auto) by measuring its distance from the obstruction with an ultra-sonic sensor and also by calculating the speed.

**_Equipments:_** Arduino board, Ultra sonic sensor, Beeper, Bread board, Battery (2xAA), Connecting wires

**_Design Proposed:_**
 
![pa design_bb](https://cloud.githubusercontent.com/assets/18714629/17560256/ae063134-5f21-11e6-8155-8f940dcc6126.png)

**_Schematic Representation of Design:_**

![image](https://cloud.githubusercontent.com/assets/18714629/17560117/1df0453a-5f21-11e6-9501-cfed436af316.png)
 
**_Steps Followed:_**

1)	Connect all the wires between the equipments based on pin arrangement shown in the design

2)	Download & Install Arduino IDE in the system

3)	Write & Upload the code to the Arduino board

4)	Test the model

**_Description:_**

The main function of this project is to assist the vehicle to be parked away from any obstruction using the ultrasonic sensor, buzzer and power source (2xAA batteries) which are connected to an arduino board via the breadboard.

Ultrasonic sensor is connected to the arduino board via 2 digital i/o pins. It has a transmitter (trigger) and a receiver (echo) which is connected to pins 4 and 2 of the board respectively. Trigger will send out a signal and listens for the echo which will gives us the time travelled by signal to reach the obstruction. This will help us determine the distance between the vehicle and the obstruction using the value for the speed of sound (1/29 cm/microseconds).  

If there is any obstruction (detected by the echo), the buzzer connected to the arduino board at pin 8 will start beeping. There is also an increase/decrease in the frequency of the beep sound (in Hz) based on the distance and speed calculated after the sensing by the ultrasonic sensor thus assisting the parking of the vehicle more efficiently.

**_Image of Project:_**

 ![img_20160810_111317](https://cloud.githubusercontent.com/assets/18714629/17559989/8dd3a96a-5f20-11e6-8613-6b60b43b51fc.jpg)
