#include <ESP8266WiFi.h>
#include <WiFiClient.h>
#include <ESP8266WebServer.h>
#include <ESP8266mDNS.h>

MDNSResponder mdns;

const char* ssid = "AnonymousWifi";
const char* password = "Rpfy$)3TTG4r39aY_4o;&+2V";

ESP8266WebServer server(80);

void setup(void){

  Serial.begin(115200);
  WiFi.begin(ssid, password);
  Serial.println("");

  // Wait for connection
  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
    Serial.print(".");
  }

  // serial output of connection details
  Serial.println("");
  Serial.print("Connected to ");
  Serial.println(ssid);
  Serial.print("IP address: ");
  Serial.println(WiFi.localIP());

  if (mdns.begin("esp8266", WiFi.localIP())) {
    Serial.println("MDNS responder started");
  }

  // this page is loaded when accessing the root of esp8266´s IP
  server.on("/", [](){
    server.send(200, "text/html", "ok");
  });

    server.on("/webhook1", []{ //lambda function syntax
      server.send(200, "text/html", "ok");
      Serial.println("webhook1 called");

      if (server.hasArg("plain")== false){ //Check if body received
            server.send(200, "text/plain", "Body not received");
            Serial.println("no accepted http parameter found");
            return;
      }
            String message = server.arg("telephone");
             Serial.println(message);
    });

    server.on("/webhook2", []{ //lambda function syntax
      server.send(200, "text/html", "ok");
      Serial.println("webhook2 called");

      if (server.hasArg("plain")== false){ //Check if body received
            server.send(200, "text/plain", "Body not received");
            Serial.println("no accepted http parameter found");
            return;
      }
            String message = server.arg("telephone");
             Serial.println(message);
    });

  server.begin();
  Serial.println("HTTP server started");
}

void loop(void){
  mdns.update();
  server.handleClient();
}
