#include "api.h"

int Api::userDoHead(){
    EthernetClient client;
    IPAddress ip(192, 168, 0, 178);
    byte mac[] = { 0xDA, 0xAD, 0xBE, 0xEF, 0xFE, 0xED };
    char server[] = "tubair-tubair.rhcloud.com";
    int code = 404 ;
    String request = "HEAD /users/";
    request = request + USERNAME + "/" + PASSWORD + " HTTP/1.1" ;
    if (Ethernet.begin(mac) == 0) {
      Ethernet.begin(mac, ip);
    }
    delay(30000);
    if (client.connect(server, 80)) {
      client.println(request);
      client.println("Host: tubair-tubair.rhcloud.com");
      client.println("Connection: close");
      client.println();
    } else {
      // if you didn't get a connection to the server:
    }
    unsigned long longDelayInSeconds = 10; // 10 secondes;
    int p = 0 ;
    while(!client.available()){
      delay(1000);
      p++;
      if(p > longDelayInSeconds){
        return 404;
      }
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

void Api::mesureDoPost(String valeur,String id_capteurs,String polluant){
    EthernetClient client;
    IPAddress ip(192, 168, 0, 177);
    byte mac[] = { 0xDE, 0xAD, 0xBE, 0xEF, 0xFE, 0xED };
    char server[] = "tubairserver-tubair.rhcloud.com";
    String request = "POST /ws/v1/mesures?valeur=";
    request = request + valeur + "&email_user=" + USERNAME + "&id_capteurs=" + id_capteurs + "&polluant=" + polluant + "&password=" + PASSWORD ;
    request = request + " HTTP/1.1" ;
    if (Ethernet.begin(mac) == 0) {
      Ethernet.begin(mac, ip);
    }
    delay(2000);
    if (client.connect(server, 80)) {
      client.println(request);
      client.println("Host: tubairserver-tubair.rhcloud.com");
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
      if( c == '5' ){
        Api::mesureDoPost(valeur,id_capteurs,polluant);
      }
    }
};

