// A simple NTP based clock for ESP8266/ESP32
// This switches two displays to show the time and data.
// Decimal points are used to separate the time and date fields.
// It takes a few seconds for the time to sync with the ntp server.
// Displayes just Time and Date, Temperature is not displayed! 

  #include <Arduino.h>
  #include <MAX72XX.h>
  #include <time.h>                             // time() ctime()
  #include <Ticker.h>
  #include <WiFiMulti.h>
  WiFiMulti wifiMulti;                          // create WiFi object
                          
  int wistat = 0;                               //0 not connected, 3 connected, 4 failed, 5 lost, 6 disconnected 
  int lightPin = 34;                            //light sensor pin
  int lightValue = 0;                           //light sensor value
  int dispIntensity = 0;                        //intensity of 7 segment Led display
  const int senMin = 500;                       //minimum intensity
  const int senMax = 4000;                      //maximum intensity
  const int ledPin = 32;                        //LED indicator ERROR
  const int tempPin = 5;                        //optional temperature sensor DS18B20
  
  constexpr uint8_t latchPin = 16;              // change to reflect your latchPin
  constexpr auto STASSID = "ID";
  constexpr auto STAPSK = "Password";

  #define TZ_Europe_Bratislava  PSTR("CET-1CEST,M3.5.0,M10.5.0/3")    //change to your timezone

  constexpr uint8_t numDevices = 1; // the number of devices
  constexpr uint8_t numDigits = 6;

  // for software SPI
  constexpr uint8_t dataPin = 17;   // change to reflect your dataPin
  constexpr uint8_t clockPin = 21;  // change to reflect your clockPin

  // create the object for the device chain
  MAX72XX dispChain(dataPin, clockPin, latchPin, numDevices, numDigits);

  // create the time displays
  MAX72XXDisplay  leftDisp(&dispChain, 4, 2);
  MAX72XXDisplay  midDisp(&dispChain, 2, 2);
  MAX72XXDisplay  rightDisp(&dispChain, 0, 2);

  // create the ticker to update the displays
  Ticker updateTicker;

void setup() {
  wifiMulti.addAP(STASSID, STAPSK); // add the ssid and secret
  WiFi.mode(WIFI_STA); // set the wifi type to station
  
  // setup ntp sync
  configTzTime(TZ_Europe_Bratislava, "pool.ntp.org");
  dispChain.setIntensity(1); // set the intensity for all the devices

  // this ticker is called every 500ms to update the time and date
  updateTicker.attach_ms(500, []() {
  // get the time
  auto now = time(nullptr);
  const tm* tm = localtime(&now);

  // hour
  static int currHour = 1;
   if (currHour != tm->tm_hour) {
      currHour = tm->tm_hour;
      int32_t hour = currHour; ((tm->tm_hour % 12) != 0) ? tm->tm_hour % 12 : 12;        
    }

  // minute
   static int currMin = -1;
    if (currMin != tm->tm_min) {
      currMin = tm->tm_min;
      }
      int32_t hour = currHour; 
     
  // date, update if the day or year changes
   static int currDay = -1;
   static int currYear = -1;
    
    if (currDay != tm->tm_mday || currYear != tm->tm_year) {
      currDay = tm->tm_mday;
      currYear = tm->tm_year;
      
    }
    if (tm->tm_sec >52 & tm->tm_sec <59)  {
           
      leftDisp.writeNumber(tm->tm_mday, MAX72XX::Character::BLANK, 0);
      midDisp.writeNumber(tm->tm_mon + 1, MAX72XX::Character::BLANK, 0);           
      rightDisp.writeNumber(tm->tm_year-100, MAX72XX::Character::BLANK);                                                 
    } else {
      leftDisp.writeNumber(hour, MAX72XX::Character::BLANK, 0); 
      midDisp.writeNumber(tm->tm_min, MAX72XX::Character::ZERO, 0);
      rightDisp.writeNumber(tm->tm_sec, MAX72XX::Character::ZERO);     
    }
  });
}

  void loop() {
    
  wistat = WiFi.status();
    if (wistat != 3)  {
    digitalWrite(ledPin, HIGH);
    }
    else {
    digitalWrite(ledPin, LOW);
    } 

    lightValue = analogRead(lightPin);
    dispIntensity = (map(lightValue, senMin, senMax, 5, 0) - 1);
    dispChain.setIntensity(dispIntensity);

  wifiMulti.run();            // conenct to wifi with reconnect if required
  delay(100);                 // prevent unexpected display state during start
}
