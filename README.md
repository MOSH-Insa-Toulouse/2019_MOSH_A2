# 2019_MOSH_A2
## 5-ISS FU Yimin , ALBERTI Johan
## 1.Sensor
   The internet of things field knows an exponential growth and the application are numerous, especially in public health-care. The development of high sensitivity and accuracy sensors are a huge interest for gas pollution detection. This sensor was developed using the INSA Toulouse AIME (Atelier Interuniversitaire de Micro-nano Electronique) facilities and based on the Jeremie Grisolia’s work. It is composed of silicon rods and WO3 nanoparticles sensitive to gas and a heating resistor.<br>
   <br>
   ![](https://github.com/MOSH-Insa-Toulouse/2019_MOSH_A2/blob/master/Pics/Screen%20Shot%202020-01-21%20at%209.51.03%20AM.png)
   ![](https://github.com/MOSH-Insa-Toulouse/2019_MOSH_A2/blob/master/Pics/Screen%20Shot%202020-01-21%20at%209.51.12%20AM.png)
   <br>Here is the data we get of the features of our sensor
   ![](https://github.com/MOSH-Insa-Toulouse/2019_MOSH_A2/blob/master/Pics/DATA.png)
## 2.Arduino
## 3.Kicad
##Schematic

This shield is composed of:

    a LoRa Module (RN2483) as transceiver
    a Gas sensor
    an amplifier (LTC1050)
    a buzzer warning users depending on gas sensor value

First, we created the project with an arduino UNO

Then, we created a library symbol for LTC 1050 and RN2483 Breakout

Afterwards, we created the following circuit decomposed in 3 parts : 

1. Arduino part :
![](https://github.com/MOSH-Insa-Toulouse/2019_MOSH_A2/blob/master/Pics/montage%20arduino.JPG)

2. Sensor part :
![](https://github.com/MOSH-Insa-Toulouse/2019_MOSH_A2/blob/master/Pics/montage%20capteur.JPG)

3. Buzzer part :
![](https://github.com/MOSH-Insa-Toulouse/2019_MOSH_A2/blob/master/Pics/montage%20buzzer.JPG)

##PCB

We first created all the footrpints needed. According the fact we needed to do the routage mostly on one layer (green). The red layer correspond to jumper added after PCB printing.
![](https://github.com/MOSH-Insa-Toulouse/2019_MOSH_A2/blob/master/Pics/PCBLayout.PNG)

Finally, this what we got in 2D without ground :
![](https://github.com/MOSH-Insa-Toulouse/2019_MOSH_A2/blob/master/Pics/pcb%202d%20sans%20masse.JPG)

And with ground :
![](https://github.com/MOSH-Insa-Toulouse/2019_MOSH_A2/blob/master/Pics/pcb%202d%20avec%20masse.JPG)
And in 3D : 
![](https://github.com/MOSH-Insa-Toulouse/2019_MOSH_A2/blob/master/Pics/pcb%203D%201.JPG)

![](https://github.com/MOSH-Insa-Toulouse/2019_MOSH_A2/blob/master/Pics/pcb%203D%202.JPG)
