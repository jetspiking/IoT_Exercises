# IoT Exercises repository description
This course has a mixed bag of example projects for the IoT-Avans-Course. The course starts with a relatively simple introduction with different programming exercises. The Espressif ESP32 Dev Module has been used for the wiring.   

All exercises have been programmed in Visual Studio Code with the PlatformIO plugin.  

# Finite State Machine

**Project Description**  
This project applies the FSM design pattern in combination with two (mini) traffic lights. These lights can switch states, depending on a button press or timer. 

The following states and transitions have been implemented for each traffic light:
| State | Transitions To State | Cause Of Transition | 
| :---: | :---: | :---: |
| Out Of Order | Red | Boot |
| Red | Green | Button press |
| Green | Orange | Button press |  
| Orange | Red | Delay | 

**Hardware Overview**
| Parts | Amount | Description |
| :---: | :---: | :---: |
| ESP32 | 1 | Board | 
| 10K Ohm resistor | 2x | One for each tactile button | 
| 100 Ohm resistor | 6x | One for each LED | 
| Red 1.8 mm LED, Orange 1.8 mm LED, Green 1.8 mm LED | 2x | Three for each traffic light |
| Tactile button | 2x | One for each traffic light | 

*Hardware Connections* 

