/*******************************************************************************
 * ESP8266 Blynk Home Security -> An IOT Project
 * 
 * This project uses Blynk IOT platform and sends email and mobile
 * notification when an intruder is detected via PIR Sensor. The email sent
 * contains the time when the intruder was detected by fetching the current 
 * time from http://pool.ntp.org/ via NTPClient. 
 * 
 * Before uploading enter the credentials in config.h in include folder.
 * Upload the project using platformio run
 * 
 * The Project is licensed under MIT license.
 * Project made and maintained by Kumar Aditya https://github.com/kumaraditya303
 *******************************************************************************


/* Comment this out to disable prints and save space */
#define BLYNK_PRINT Serial

/* Include Header files */
#include <Arduino.h>
#include <BlynkSimpleEsp8266.h>
#include <WiFiUdp.h>
#include <NTPClient.h>
#include <config.h>
/* Initialize NTP Client */
WiFiUDP ntpUDP;
NTPClient timeClient(ntpUDP, "pool.ntp.org", 19800, 60000);

/* Send email and mobile notifications */
ICACHE_RAM_ATTR void sendEmail()
{
  // Send email
  Blynk.email(email, "⚠ Alert ", "Intruder was detected at " + timeClient.getFormattedTime());
  // Send notification to App
  Blynk.notify("⚠ Alert! Intruder was detected at " + timeClient.getFormattedTime());
}

void setup()
{
  // Debug Console
  Serial.begin(115200);
  // Setting up Blynk
  Blynk.begin(auth, ssid, password);
  timeClient.begin();
  pinMode(LED_BUILTIN, OUTPUT);
  pinMode(PIR_PIN, INPUT_PULLUP);
  // Attach Interrupt on the PIR_PIN
  attachInterrupt(digitalPinToInterrupt(PIR_PIN), sendEmail, RISING);
  digitalWrite(LED_BUILTIN, LOW);
  // Notification for startup!
  Blynk.email(email, "ESP8266 Blynk Security System", "System is working properly and is connected to network " + WiFi.SSID() + " with strength of " + WiFi.RSSI());
}

void loop()
{ // Run Blynk
  Blynk.run();
  timeClient.update();
  Serial.print(system_adc_read());
}
