/*
  2013/4/22  
  Coded by Yasuhiro ISHII
*/

// if you use Standard Arduino except Leonardo,comment this out below;
#define USE_LEONARDO

#define PIN_LED_INDICATOR 3

// ----------------------------------------------------------

#ifdef USE_LEONARDO
#define SERIAL_IF  Serial1
#else
#define SERIAL_IF  Serial
#endif

void setup()
{
  SERIAL_IF.begin(115200);
  pinMode(PIN_LED_INDICATOR,OUTPUT);
  digitalWrite(PIN_LED_INDICATOR,HIGH);

  // for Arduino Leonardo,need to wait until establish VCP connection
  //while(!Serial);
}

void loop()
{
  unsigned char readdata;
  
  SERIAL_IF.write("HTTPGET http://www.yishii.jp/data/flag\n");

  if(SERIAL_IF.available() > 0){
    readdata = SERIAL_IF.read();
    //Serial.write(readdata);
    if(readdata == '0'){
      digitalWrite(PIN_LED_INDICATOR,LOW);
    } else if (readdata == '1'){
      digitalWrite(PIN_LED_INDICATOR,HIGH);
    }
  }
  
  delay(400);
}

