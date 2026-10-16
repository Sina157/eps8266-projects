#include <ESP8266WiFi.h>
#include <ESP8266HTTPClient.h>
#define LED 2

const char* ssid = "WIFI_NAME";
const char* password = "PASSWORD";

void setup() {
  Serial.begin(9600);
  pinMode(LED, OUTPUT);
  Serial.println("Connecting to WiFi...");

  WiFi.begin(ssid, password);

  while (WiFi.status() != WL_CONNECTED) {
    digitalWrite(LED, HIGH);
    delay(500);
    digitalWrite(LED, LOW);
    Serial.print(".");
  }
  digitalWrite(LED, LOW);
  Serial.println();
  Serial.println("WiFi connected!");
  Serial.print("IP address: ");
  Serial.println(WiFi.localIP());
  bool re = SendTelegramMessage("Hello from ESP8266");
  Serial.println(re);
}

void loop() {
}


bool SendTelegramMessage(String message)
{
  if (WiFi.status() != WL_CONNECTED) {
    Serial.println("WiFi is not connected!");
    return false;
  }

  WiFiClientSecure client;
  client.setInsecure();

  HTTPClient http;

  // تبدیل فاصله و بعضی کاراکترهای URL
  message.replace(" ", "%20");
  message.replace("\n", "%0A");

  String url = "YOUR CLOUDFLARE WORKER LINK" + message;

  Serial.println("Sending Telegram message...");

  if (!http.begin(client, url)) {
    Serial.println("HTTP begin failed!");
    return false;
  }

  int httpCode = http.GET();

  Serial.print("HTTP Code: ");
  Serial.println(httpCode);

  String response = http.getString();

  Serial.println("Response:");
  Serial.println(response);

  http.end();

  return httpCode == 200;
}
