/*

Code Arduino de test module

*/

#include <Arduino.h>
#include <ADS1X15.h>
#include <SPI.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>
#include <Wire.h>

#define SCREEN_WIDTH 128
#define SCREEN_HEIGHT 64

#define OLED_MOSI 23
#define OLED_CLK  18
#define OLED_DC   16
#define OLED_CS   5
#define OLED_RESET 17

Adafruit_SSD1306 display(SCREEN_WIDTH, SCREEN_HEIGHT, OLED_MOSI, OLED_CLK, OLED_DC, OLED_RESET, OLED_CS);

ADS1115 ADS(0x48);


void setup() 
{
  if(!display.begin(SSD1306_SWITCHCAPVCC)){
    Serial.println(F("SSD1306 allocation failed"));
    for(;;); // Don't proceed, loop forever
  }
  else{
    Serial.println(F("SSD1306 allocation successful"));
  }
  display.clearDisplay();
  display.setTextSize(1);
  display.setTextColor(SSD1306_WHITE);
  display.setCursor(0,0);
  display.println("ADS1X15 Test");
  display.display();

    Wire.begin(21, 22);        // ESP32 default SDA=21, SCL=22 — change if needed
  Wire.setClock(400000);    // optional: set I2C speed to 400kHz
  Serial.begin(115200);
  Serial.println(__FILE__);
  Serial.print("ADS1X15_LIB_VERSION: ");
  Serial.println(ADS1X15_LIB_VERSION);

  ADS.begin();
  delay(1000);
}


void loop() 
{
  display.clearDisplay();
  ADS.setGain(0);

  int16_t val_0 = ADS.readADC(0);  
  int16_t val_1 = ADS.readADC(1);  
  int16_t val_2 = ADS.readADC(2);  
  int16_t val_3 = ADS.readADC(3);  

  float f = ADS.toVoltage(1);  // voltage factor

  /*
  Serial.print("\tAnalog0: "); Serial.print(val_0); Serial.print('\t'); Serial.println(val_0 * f, 3);
  Serial.print("\tAnalog1: "); Serial.print(val_1); Serial.print('\t'); Serial.println(val_1 * f, 3);
  Serial.print("\tAnalog2: "); Serial.print(val_2); Serial.print('\t'); Serial.println(val_2 * f, 3);
  Serial.print("\tAnalog3: "); Serial.print(val_3); Serial.print('\t'); Serial.println(val_3 * f, 3);
  Serial.println(); 
  */
  display.setCursor(0,0);
  //display.println("ADS1X15 Test");
  display.print("A0: "); display.print(val_0); display.print('\t'); display.println(val_0 * f, 3);
  display.setCursor(0,10);
  display.print("A1: "); display.print(val_1); display.print('\t'); display.println(val_1 * f, 3  );
  display.setCursor(0,20);
  display.print("A2: "); display.print(val_2); display.print('\t'); display.println(val_2 * f, 3);
  display.setCursor(0,30);
  display.print("A3: "); display.print(val_3); display.print('\t'); display.println(val_3 * f, 3);
  display.display();    


  delay(1000);
}