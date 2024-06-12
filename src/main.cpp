/*
 ESP32 Web Server - STA Mode
 modified on 25 MAy 2019
 by Mohammadreza Akbari @ Electropeak
 https://electropeak.com/learn
*/
// SSID & Password


#include <WiFi.h>
#include <WebServer.h>

// SSID & Password
const char* ssid ="MIWIFI_2G_Tepa";  // Enter your SSID here
const char* password = "dHtaUGse";  //Enter your Password here

WebServer server(80);  // Objeto del servidor web (puerto HTTP, 80 es el predeterminado)

// HTML & CSS que se mostrará en el servidor web
String HTML = "<!DOCTYPE html>\
<html>\
<body>\
<h1>Hola nen t'estimo molt;</h1>\
</body>\
</html>";

void handle_root() {
    server.send(200, "text/html", HTML);
}

void setup() {
    Serial.begin(115200);
    Serial.println("Intentando conectar a ");
    Serial.println(ssid);

    WiFi.begin(ssid, password);

    while (WiFi.status() != WL_CONNECTED) {
        delay(1000);
        Serial.print(".");
    }
    Serial.println("");
    Serial.println("Conexión WiFi exitosa");
    Serial.print("IP obtenida: ");
    Serial.println(WiFi.localIP());

    server.on("/", handle_root);

    server.begin();
    Serial.println("Servidor HTTP iniciado");
    delay(100); 
}

void loop() {
    server.handleClient();
}
