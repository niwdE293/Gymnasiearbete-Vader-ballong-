/*needed libraries 
Adafruit BMP3XX
Adafruit Unified Sensor*/

#include <Wire.h>
#include <SPI.h>
#include <Adafruit_Sensor.h>
#include "Adafruit_BMP3XX.h"

#define BMP_SCK 13 //SC/SCK - This is the SPI Clock pin, its an input to the chip and can use 3 - 5V logic.
#define BMP_MISO 12 //SDO - this is the Serial Data Out / Microcontroller In Sensor Out pin, for data sent from the BMP3xx to your processor. Logic level is 3.3V output, so can be read by 5V microcontrollers.
#define BMP_MOSI 11 //SDA - this is the Serial Data In / Microcontroller Out Sensor In pin, for data sent from your processor to the BMP3xx. Its an input to the chip and can use 3 - 5V logic. (SDI on original version)
#define BMP_CS 10 //CS - this is the Chip Select pin, drop it low to start an SPI transaction. Its an input to the chip and can use 3 - 5V logic.

#define SEALEVELPRESSURE_HPA (1013.25)

Adafruit_BMP3XX bmp;

void setup() {
  // put your setup code here, to run once:
   Serial.begin(115200);
  while (!Serial);
  Serial.println("Adafruit BMP388 / BMP390 test");

  if (!bmp.begin_I2C()) {   // hardware I2C mode, can pass in address & alt Wire
  //if (! bmp.begin_SPI(BMP_CS)) {  // hardware SPI mode  
  //if (! bmp.begin_SPI(BMP_CS, BMP_SCK, BMP_MISO, BMP_MOSI)) {  // software SPI mode
    Serial.println("Could not find a valid BMP3 sensor, check wiring!");
    while (1);
  }

  // Set up oversampling and filter initialization
  

}

void loop() {
  // put your main code here, to run repeatedly:

  get_pressure();
}

void get_pressure() {
  if (! bmp.performReading()) {
    Serial.println("Failed to perform reading :(");
    return;

  Serial.println(bmp.pressure / 100.0);
  delay(1000);
}
