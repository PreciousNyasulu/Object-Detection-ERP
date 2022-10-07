# Object-Detection

This is a simulation of an industrial smart conveyor belt that detects product(Objects) when they pass on the conveyor belt. The conveyor belt is simulated using arduino the following **Electronic components**:

* [Arduino UNO](https://www.arduino.cc/)
* Ultrasonic Sensor
* Buzzer
* LED
* Motors and Drivers

The aim is to register in the database once an object has been detected, the Ultrasonic sensor is given a parameter in which an object is expected to be detected in this case my parameter was set to 10 Centimeters. The arduino is connected to the computer through a serial, a python script is supposed to read the serial output being **echoed** through the serial port. The script compares the serial output with the conditions.

``` Python
import serial
import requests #import http requests library

ser = serial.Serial("COM PORT NUMBER eg:COM3", 9600)
while True:
     cc=str(ser.readline())
     _Value =cc[2:][:-5] #gets only the number from the serial output
     
```

The serial output is constantly read through an infinite-loop. The loops checks for a matching condition constantly.
When the condition matches, the request is sent to and endpoint of a customized API, the API increments the counted value every time a condition is met. The API response printed unto the console.

```python
if(int(_Value) <= 10):
          # defining the api-endpoint 
          
          API_ENDPOINT = "http://localhost:8000/api/Object/Detected"
          r = requests.put(url = API_ENDPOINT,data = {})
          print(r)
```
