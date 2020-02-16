#include <ArduinoJson.h>
#include <ESP8266WiFi.h>
#include <WiFiClient.h>
#include <ESP8266HTTPClient.h>
#include <vector>

const char* apSsid     = "";
const char* apPassword = "";
const char* clientSsid     = "";
const char* clientPassword = "";
String mac = "";
String rssi = "";
String mac_aparelho = "";

HTTPClient http;

WiFiEventHandler probeRequestPrintHandler;

String macToString(const unsigned char* mac) {
  char buf[20];
  snprintf(buf, sizeof(buf), "%02x:%02x:%02x:%02x:%02x:%02x",
           mac[0], mac[1], mac[2], mac[3], mac[4], mac[5]);
  return String(buf);
}

std::vector<WiFiEventSoftAPModeProbeRequestReceived> myList;

void onProbeRequestPrint(const WiFiEventSoftAPModeProbeRequestReceived& evt) {
  myList.push_back(evt);
}

void setup() {
  Serial.begin(115200);
  Serial.println("Hello!");

  // Don't save WiFi configuration in flash - optional
  WiFi.persistent(false);

  WiFi.mode(WIFI_AP_STA);
  WiFi.softAP(apSsid, apPassword);
  WiFi.begin(clientSsid, clientPassword);
  while (WiFi.status() != WL_CONNECTED) {
    Serial.print(".");
    delay(100);
  }
  Serial.println("");
  probeRequestPrintHandler = WiFi.onSoftAPModeProbeRequestReceived(&onProbeRequestPrint);
}

void loop() {
  delay(3000);
  String json = "";
  DynamicJsonBuffer jsonBuffer;
  JsonObject& root = jsonBuffer.createObject();
  JsonArray& probes = root.createNestedArray("probes");
  for(WiFiEventSoftAPModeProbeRequestReceived w : myList){
    JsonObject& probe = probes.createNestedObject();
    mac = macToString(w.mac);
    rssi = w.rssi;
    mac_aparelho = MacEsp();
    
  }
  myList.clear();
  root.printTo(json);
  //Serial.println("json:" + json);
  String body = "mac="+mac+"&rssi="+rssi+"&mac_aparelho="+mac_aparelho;
  http.begin();
  http.addHeader("Content-Type", "application/x-www-form-urlencoded");
  http.POST(body);
  String response =  http.getString();
  Serial.println(response);
  http.end();
}

String MacEsp (){
  String mac = String(WiFi.macAddress());
  return mac;
}
