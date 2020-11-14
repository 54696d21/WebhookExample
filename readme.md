# ESP8266 webhook example

an easy way to trigger an event on a ESP8266 by making a http request to it (with the option of transmitting data to it).

this code example implements 2 urls that can be called to trigger a function

## Getting started

1. git clone https://github.com/54696d21/WebhookExample

2. fill in our wifi credentials 

3. flash it on an ESP8266 either using the Arduino IDE (using the `WebhookExample.ino` file ) or PlatformIO (by opening this repo in PlatformIO)

4. once the ESP8266 is connected to your local network, you can make a get request to  
`<your ESP8266's IP>/webhook1` or `http://esp8266.local/webhook1`
to execute a function

and 

`http://esp8266.local/webhook1?myArg1=HelloWorld` to execute the function and print out "HelloWorld" to the command line