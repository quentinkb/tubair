#include "tubair.h" 

const int GREEN_LED = 2 ;
const int RED_LED = 4 ; 
int RETURN_CODE_LOGIN = 0; 



Api api_manager; 
DHT dht(DHTPIN, DHTTYPE);
MQ2 mq2(PIN_MQ2);

void setup() {
  
  Serial.begin(9600);
  while (!Serial) {
    ; // wait for serial port to connect. Needed for native USB port only
  }
  mq2.calibrate();
  pinMode(GREEN_LED,OUTPUT); 
  pinMode(RED_LED,OUTPUT); 
  Serial.println("Welcome"); 
  updateLedLogin(); 

}
int userDoHead(){
  return api_manager.userDoHead(); 
}

void updateLedLogin()
{
  int code = userDoHead() ;
  if(code == 200){
    RETURN_CODE_LOGIN = 1 ; 
  }
  else{
    RETURN_CODE_LOGIN = 0 ; 
  }
  digitalWrite(GREEN_LED,RETURN_CODE_LOGIN); 
  digitalWrite(RED_LED,!RETURN_CODE_LOGIN); 
  
}
void loop() {
  if(RETURN_CODE_LOGIN)
  {
    Serial.println("i'm sending data"); 
    Serial.print(" Smoke: ");
    Serial.print(mq2.readSmoke());
    /*String temperature = ""; 
    temperature = temperature + dht.readTemperature(); 
    api_manager.mesureDoPost(temperature,"1","T"); 
    Serial.println("data sent"); 
    unsigned long longDelayInSeconds = 60*15; // 15 minutes; 
    int p = 0 ;   
    while (p < longDelayInSeconds) {
        delay(1000);
        p++;

    }*/
  }
}
