//Created by Team !ABHIMANYU
#include <ESP8266WiFi.h>



String  str;
WiFiServer server(80);

float a = 0, b = 0;
int c, d;

void setup()
{
  str = "";

  Serial.begin(115200);
  pinMode(4, OUTPUT);
  WiFi.disconnect();
  delay(2000);
  WiFi.begin("purushotamhonor9n", "Pka@1234");
  while ((!(WiFi.status() == WL_CONNECTED))) {
    delay(300);

  }
  server.begin();

}


void loop()
{

  WiFiClient client = server.available();
  if (!client) {
    return;
  }
  while (!client.available()) {
    delay(1);
  }
  str = (client.readStringUntil('\r'));
  client.println(str);

  str.remove(0, 5);
  str.remove(str.length() - 9, 9);

  //str += '\n';

  Serial.println(str);

  // if a <=4 -> forward
  // if a >=6 -> backward
  // if b >=1 && d == 2 -> right
  // if b >=1 && d == 1 -> left


}
