#include "api.h" 

int Api::userDoHead(){
  
    EthernetClient client;
    IPAddress ip(192, 168, 0, 177);
    byte mac[] = { 0xDE, 0xAD, 0xBE, 0xEF, 0xFE, 0xED };
    char server[] = "tubairapp-tubair.rhcloud.com";   

    int code = 404 ; 
    String request = "HEAD /ws/v1/user?username="; 
    request = request + USERNAME + "&password=" + PASSWORD + " HTTP/1.1" ; 
    if (Ethernet.begin(mac) == 0) {
      Ethernet.begin(mac, ip);
    }
    delay(30000);
    if (client.connect(server, 80)) {
      client.println(request);
      client.println("Host: tubairapp-tubair.rhcloud.com");
      client.println("Connection: close");
      client.println();
    } else {
      // if you didn't get a connection to the server:
    }
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
    }
  
    return code ; 
  
}; 

