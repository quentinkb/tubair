#include "tubair.h" 

const int GREEN_LED = 2 ;
const int RED_LED = 4 ; 
int RETURN_CODE_LOGIN = 0; 


Api api_manager; 
DHT dht(DHTPIN, DHTTYPE);
MQ2 mq2(PIN_MQ2);
MQ7 mq7(PIN_MQ7);
MQ3 mq3(PIN_MQ3);


void setup() {
  
  Serial.begin(9600);
  while (!Serial) {
    ; // wait for serial port to connect. Needed for native USB port only
  }
  mq2.calibrate();
  mq3.calibrate();
  mq7.calibrate();
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
  Serial.println(code);
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
    Serial.println("\nI'm sending data");
    Serial.print("Temperature: ");
    Serial.println(dht.readTemperature());
    Serial.print("Humidity: ");
    Serial.println(dht.readHumidity());
    Serial.print("Smoke: ");
    Serial.println(mq2.readSmoke());
    Serial.print("CarbonMonoxide: ");
    Serial.println(mq7.readCarbonMonoxide());
    Serial.print("Alcool: ");
    Serial.println(mq3.readAlcoholPpm());
    String Temperature = "";
    String Humidity = "";
    String Smoke = "";
    String CarboneMonoxide = "";
    String AlcoholPpm = "";
    Temperature = Temperature + dht.readTemperature();
    Humidity = Humidity + dht.readHumidity();
    Smoke = Smoke + mq2.readSmoke();
    CarboneMonoxide = CarboneMonoxide + mq7.readCarbonMonoxide();
    AlcoholPpm = AlcoholPpm + mq3.readAlcoholPpm();
    api_manager.mesureDoPost(Temperature,"1","T");
    api_manager.mesureDoPost(Humidity,"1","H");
    api_manager.mesureDoPost(Smoke,"1","S");
    api_manager.mesureDoPost(CarboneMonoxide,"1","CO");
    api_manager.mesureDoPost(AlcoholPpm,"1","A");
    Serial.println("data sent");
    unsigned long longDelayInSeconds = 60*15; // 15 minutes; 
    int p = 0 ;   
    while (p < longDelayInSeconds) {
        delay(1000);
        p++;
    }
  }
}
