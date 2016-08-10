#define USERNAME "toto" 
#define PASSWORD "toto" 

#include <Ethernet.h>

const int GREEN_LED = 2 ;
const int RED_LED = 4 ; 
int RETURN_CODE_LOGIN = 0; 

EthernetClient client;
IPAddress ip(192, 168, 0, 177);
byte mac[] = { 0xDE, 0xAD, 0xBE, 0xEF, 0xFE, 0xED };
char server[] = "tubairapp-tubair.rhcloud.com";   


void setup() {
  
  Serial.begin(9600);
  while (!Serial) {
    ; // wait for serial port to connect. Needed for native USB port only
  }
  pinMode(GREEN_LED,OUTPUT); 
  pinMode(RED_LED,OUTPUT); 
  Serial.println("Welcome"); 
  updateLedLogin(); 

}
int callApi(){
  Serial.println("here"); 
  int code = 404 ; 
  String request = "HEAD /ws/v1/user?username="; 
  request = request + USERNAME + "&password=" + PASSWORD + " HTTP/1.1" ; 
  Serial.println(request); 
  if (Ethernet.begin(mac) == 0) {
    Serial.println("ethernet failed"); 
    Serial.println("Failed to configure Ethernet using DHCP");
    // try to congifure using IP address instead of DHCP:
    Ethernet.begin(mac, ip);
  }
  // give the Ethernet shield a second to initialize:$=$=
  Serial.println("waiting"); 
  delay(2000);
  Serial.println("connecting...");
  if (client.connect(server, 80)) {
    Serial.println("connected");
    // Make a HTTP request:
    client.println(request);
    client.println("Host: tubairapp-tubair.rhcloud.com");
    client.println("Connection: close");
    client.println();
  } else {
    // if you didn't get a connection to the server:
    Serial.println("connection failed");
  }
  Serial.println("before loop"); 
  while(!client.available()){
    // do nothing 
  }
  while(client.available()) {
  
    char c = client.read();
    if( c == '4' ){
      // error
      return 404; 
    }
    if( c == '2'){
      // ok 
      return 200; 
    }
    Serial.print(c);
  }

  return code ; 
}
void updateLedLogin()
{
  int code = callApi() ; // replace by call block 
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
    
  }
}
