#include "tubair.h"
/**
 * nom : RETURN_CODE_LOGIN
 * type : int
 * @description : "Code d'erreur renvoyé après authentification (1 si réussie, 0 si échec)"
 */
int RETURN_CODE_LOGIN = 0;

Api api_manager;
DHT dht(DHTPIN, DHTTYPE);
MQ2 mq2(PIN_MQ2);
MQ7 mq7(PIN_MQ7);
MQ3 mq3(PIN_MQ3);

/**
 * fonction : setup()
 * @description : "Initialise les capteurs, les emplacements de LEDS, appel de la fonction d'authentification"
 * @paramètres : /
 * @retour : void
 */

void doPost(String valeur,String id_capteurs,String polluant, int security){
  //Serial.println("here");
  if (security < 10) {
      //Serial.println("secure pass");
      EthernetClient client;
      IPAddress ip(192, 168, 0, 177);
      byte mac[] = { 0xAC, 0xAD, 0xBE, 0xEF, 0xFE, 0xED };
      char server[] = "tubair-tubair.rhcloud.com";
      String request = "POST /mesures/";
      request = request + USERNAME + "/" + valeur + "/" + polluant;
      request = request + " HTTP/1.1" ;
      if (Ethernet.begin(mac) == 0) {
        Ethernet.begin(mac, ip);
      }
      delay(2000);
      if (client.connect(server, 80)) {
        client.println(request);
        //Serial.println(request); 
        client.println("Host: tubair-tubair.rhcloud.com");
        client.println("Connection: close");
        client.println();
      } else {
        //Serial.println("over there"); 
        // if you didn't get a connection to the server:
      }
      /*unsigned long longDelayInSeconds = 10; // 10 secondes;
      int p = 0;
      while(!client.available()){
        delay(1000);
        p++;
        if(p > longDelayInSeconds){
          return Api::mesureDoPost(valeur,id_capteurs,polluant,security++);
        }
      }*/
      /*Serial.println("waiting for server to respond"); 
      while(client.available()) {
        char c = client.read();
        Serial.print(c); 
      }*/
  }
};
void setup() {
  /*Serial.begin(9600);
  while (!Serial) {
    ;// wait for serial port to connect. Needed for native USB port only
  }
  Serial.println("welcome");*/
  mq2.calibrate();
  mq3.calibrate();
  mq7.calibrate();
  pinMode(GREEN_LED,OUTPUT);
  pinMode(RED_LED,OUTPUT);
  pinMode(START_LED,OUTPUT);
  //Serial.println("Welcome");
  digitalWrite(START_LED,LOW);
  delay(1000);
  digitalWrite(START_LED,HIGH);
  delay(1000);
  digitalWrite(START_LED,LOW); // make it blink at start
  delay(1000);
  digitalWrite(START_LED,HIGH); // light it up after 2 minutes delay (ethernet connexion latency)
  updateLedLogin();
  digitalWrite(START_LED,LOW);
}

/**
 * fonction : userDoHead()
 * @description : "appelle la fonction d'authenfication"
 * @paramètres : none
 * @retour : int : retourne le code d'erreur d'authentification, donné par la fonction api_manager.userDoHead() (200 en cas de réussite, 404 en cas d'échec)
 */
int userDoHead(){
  return api_manager.userDoHead();
}

/**
 * fonction : updateLedLogin()
 * @description : "appelle la fonction d'authenfication, évalue le code de retour de l'authentification, allume les LEDS selon le résultat de l'authentification"
 * @paramètres : /
 * @retour : void
 */
void updateLedLogin()
{
  int code = userDoHead();
  //Serial.println(code);
  if(code == 200){
    RETURN_CODE_LOGIN = 1;
  }
  else{
    RETURN_CODE_LOGIN = 0;
  }
  digitalWrite(GREEN_LED,RETURN_CODE_LOGIN);
  digitalWrite(RED_LED,!RETURN_CODE_LOGIN);
}

/**
 * fonction : loop()
 * @description : "Effectue les mesures, et appelle la fonction pour envoyer ces mesures au serveur, variable de délai 'longDelayInSeconds' pour la fréquence des mesures"
 * @paramètres : /
 * @retour : void
 */
void loop() {
  if(RETURN_CODE_LOGIN)
  {
    /*Serial.println("\nI'm sending data");
    Serial.print("Temperature: ");
    Serial.println(dht.readTemperature());
    Serial.print("Humidity: ");
    Serial.println(dht.readHumidity());
    Serial.print("Smoke: ");
    Serial.println(mq2.readSmoke());
    Serial.print("CarbonMonoxide: ");
    Serial.println(mq7.readCarbonMonoxide());
    Serial.print("Alcool: ");
    Serial.println(mq3.readAlcoholPpm());*/
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
    
    doPost(Temperature,"1","T",0);
    //doPost(Temperature,"1","T",0);
    delay(5000);
    doPost(Humidity,"1","H",0);
    //doPost(Humidity,"1","H",0);
    delay(5000);
    //doPost(Smoke,"1","S",0);
    doPost(Smoke,"1","S",0);
    delay(5000);
    //doPost(CarboneMonoxide,"1","CO",0);
    doPost(CarboneMonoxide,"1","CO",0);
    delay(5000);
    //doPost(AlcoholPpm,"1","A",0);
    doPost(AlcoholPpm,"1","A",0);
    delay(5000);
    digitalWrite(START_LED,LOW);
    delay(1000);
    digitalWrite(START_LED,HIGH);
    delay(1000);
    digitalWrite(START_LED,LOW);
    delay(1000);
    //Serial.println("data sent");
    unsigned long longDelayInSeconds = 60*15; // 15 minutes;
    int p = 0 ;
    while (p < longDelayInSeconds) {
        delay(1000);
        p++;
    }
  }


}

