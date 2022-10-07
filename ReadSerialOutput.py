import serial
import time
import requests #importing the requests library

ser = serial.Serial("COM3", 9600)
while True:
     cc=str(ser.readline())
     _Value =cc[2:][:-5]
     print(_Value)

     if(int(_Value) <= 10):
          # defining the api-endpoint 
          
          API_ENDPOINT = "http://localhost:8000/api/Tickets/Update"
          
          # data to be sent to api
          # data = {
          #      'api_option':'paste',
          #      'api_paste_code':"source_code",
          #      'api_paste_format':'python'}
          
          # sending post request and saving response as response object
          r = requests.put(url = API_ENDPOINT,data = {})
          print(r)
          time.sleep(2);
          # extracting response text 
          # pastebin_url = r.text
