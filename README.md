# DIY-Thermostat (Work In Progress)
A STANDALONE DIY thermostat based on ESP32 - ESPHOME - ESPNOW - HOME ASSISTANT

![image](https://github.com/user-attachments/assets/2d613e74-fc37-4b2b-af7e-91b413f95aa8)

***Relay logic is shown in the state diagram. The logic will avoid output of cooling and heating at the same time. It also provides redundancy circuit to some extent, such that C1 has to be in ON condition for entire operation of HVAC. If C1 and C2 is ON, it will start the heating with H/C in OFF state. Heating is choosen to be on the NC state of H/C Relay to cover the case where if the H/C relay has failed operationally, by deafult heat will be ON when ever required. The logic is that one cannot survive without heating in winters, can even cause freezing of pipes.*** 

***Relay board used in this project***  
This relay board works over i2c and this repo contains code `i2cRelay.h` to control it from ESPHOME yaml file.  
[Manual/Guide](https://wiki.52pi.com/index.php?title=EP-0099) for this relay board. [Instruction](https://www.instructables.com/I2C-Relay-Met-Arduino-IDE/) on how to use it with Arduino/Esp32

![image](https://github.com/user-attachments/assets/e320cf01-6b68-4306-b356-32270b1868a9)


**Logic and build instruction**

For two stage thermostat, we can program the HVAC unit to automatically handle the shifting from stage 1 to stage 2 based on its internal timing. Read the manual of HVAC unit for guide on how to do it. By doing so, we just need to control the `W` output for 2 stage heating.

Master ESP32 should have a hard wired temperature sensor and 4 relays to perform the operation. The on board temperature sensor will ensure that we always have atleast one temperature reading. Master ESP32 will use ESPNOW to get data from remote temperature sensors (slave esp32). Master ESP32 will be connected to Home Assistant to program and configure thermostat. This allows controling HVAC from any local/remote device. The system is stanalone and does not require Home Assistant to be always on.

We will, optionally, use Slave ESP32 with temperature sensor on board. This device can be placed in different rooms and can communicate with Master ESP32 over ESPNOW. Master ESP32 will average out all the temperature readings received and perform the heating/cooling accordingly.

Slave ESP32 will perform the reading of temperature at fixed interval and go into deep sleep mode. This allows slave esp32 to operate on the battery and run for months. The update interval is programmable.

**Picture of existing dashboard**
![image](https://github.com/user-attachments/assets/4225c642-3512-4e4a-81da-58b5c69642f9)

***YAML files, if uploaded on this repo are work in progress. I will notify of stable release after testing.***

To Do
1)  Support various algorithms to control heat/cooling
2)  Support 2 Stage heating logic with customizable options. (Right now HVAC should be programmed to take care of it).
