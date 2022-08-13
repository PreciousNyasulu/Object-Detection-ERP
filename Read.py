import serial
import requests # importing the requests library

ser = serial.Serial("COM9", 9600)
while True:
     cc=str(ser.readline())
     print(cc[2:][:-5])

     if(str(ser.readline()) == "10CM"):
          # defining the api-endpoint 
          API_ENDPOINT = "http://127.0.0.1/api/tickets/add"
                    
          # data to be sent to api
          data = {
               'api_option':'paste',
               'api_paste_code':"source_code",
               'api_paste_format':'python'}
          
          # sending post request and saving response as response object
          r = requests.post(url = API_ENDPOINT, data = data)
          
          # extracting response text 
          pastebin_url = r.text
          print("The pastebin URL is:%s"%pastebin_url)
