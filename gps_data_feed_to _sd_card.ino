#include "TinyGPS++.h"
#include "SoftwareSerial.h"
#include <SPI.h>
#include <SD.h>

const int chipSelect = 10;

SoftwareSerial serial_connection(3, 4); //RX=pin 3, TX=pin 4
TinyGPSPlus gps;//This is the GPS object that will pretty much do all the grunt work with the NMEA data

void setup()
{
  Serial.begin(9600);//This opens up communications to the Serial monitor in the Arduino IDE

  Serial.print("Initializing SD card...");
  if (!SD.begin(chipSelect)) // see if the card is present and can be initialized:
  {
    Serial.println("Card failed, or not present");
    return;// don't do anything more
  }
  Serial.println("card initialized.");

  File dataFile = SD.open("data.txt", FILE_WRITE);
  if (dataFile) // if the file is available, write to it
  {
    dataFile.println("Satellite Count,Latitude,Longitude,Speed MPH,Altitude Feet");
    dataFile.close();
  }
  else // if the file isn't open, pop up an error:
  {
    Serial.println("error opening datalog.txt");
    return;// don't do anything more
  }
  serial_connection.begin(9600);//This opens up communications to the GPS
  Serial.println("GPS Start");//Just show to the monitor that the sketch has started
}

void loop()
{
  
  while(serial_connection.available())//While there are characters to come from the GPS
  {
    gps.encode(serial_connection.read());//This feeds the serial NMEA data into the library one char at a time
  }
  
  if(gps.location.isUpdated())
  {
    double altitude = gps.altitude.feet();
    File dataFile = SD.open("data.txt", FILE_WRITE);

    // WRITING TO FILE ON SD CARD
    if (dataFile) 
    {
      dataFile.print(gps.satellites.value());
      dataFile.print(", ");
      dataFile.print(gps.location.lat(), 6);
      dataFile.print(", ");
      dataFile.print(gps.location.lng(), 6);
      dataFile.print(", ");
      dataFile.print(gps.speed.mph());
      dataFile.print(", ");
      dataFile.print(gps.altitude.feet());
      dataFile.println(",");
      dataFile.close();
    }
    else 
    {
      Serial.println("error opening datalog.txt");
    }

    //PRINTING TO SERIAL
    Serial.print(gps.satellites.value());
    Serial.print(", ");
    Serial.print(gps.location.lat(), 6);
    Serial.print(", ");
    Serial.print(gps.location.lng(), 6);
    Serial.print(", ");
    Serial.print(gps.speed.mph());
    Serial.print(", ");
    Serial.print(gps.altitude.feet());
    Serial.println(",");

    //Serial.print("Altitude: ");
    //Serial.println(altitude);
  }
}
