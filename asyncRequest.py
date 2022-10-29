import asyncio 
import aiohttp
import serial

ser = serial.Serial("COM3", 9600) #serial port initialization

#Request to the api endpoint
async def main():
    async with aiohttp.ClientSession() as session:
        async with session.put('http://127.0.0.1:8000/api/Tickets/Update') as response:

            print("Status:", response.status)
            html = await response.text()
            print("Body:", html)


while True:
    cc=str(ser.readline())
    _Value =cc[2:][:-5]
    print(_Value , "CM")

    if(int(_Value) <= 10):
        loop = asyncio.get_event_loop()
        loop.run_until_complete(main())