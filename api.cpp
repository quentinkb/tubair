#include "api.h"

/**
 * fonction : userDoHead()
 * @description : "Effectue une requête HEAD au serveur, vérifiant que le compte avec les identifiants transmis dans le fichier 'api.h' est bien enregistré sur le serveur"
 * @paramètres : /
 * @retour : int (200 si tout est ok, 404 sinon)
 */
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

/**
 * fonction : mesureDoPost()
 * @decription : "Poste sur le serveur les mesures effectuées"
 * @paramètres :
 *  - nom : valeur, type : String, @description : "valeur retournée par le capteur"
 *  - nom : id_capteurs, type : String, @description : "id du capteur"
 *  - nom : polluant, type, String, @description : "nom du polluant"
 *  - nom : secutiry, type : int, @description : "sécurité permettant de passer une valeur si l'envoi au serveur est impossible après un certains nombre d'essais"
 *  @retour : void
 */
void Api::mesureDoPost(String valeur,String id_capteurs,String polluant, int security){
  if (security < 10) {
      EthernetClient client;
      IPAddress ip(192, 168, 0, 177);
      byte mac[] = { 0xDE, 0xAD, 0xBE, 0xEF, 0xFE, 0xED };
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
        client.println("Host: tubair-tubair.rhcloud.com");
        client.println("Connection: close");
        client.println();
      } else {
        // if you didn't get a connection to the server:
      }
      unsigned long longDelayInSeconds = 10; // 10 secondes;
      int p = 0;
      while(!client.available()){
        delay(1000);
        p++;
        if(p > longDelayInSeconds){
          return Api::mesureDoPost(valeur,id_capteurs,polluant,security++);
        }
      }
      //while(client.available()) {
        //char c = client.read();
        //if( c == '5' ){
          //Api::mesureDoPost(valeur,id_capteurs,po lluant,security++);
        //}
      //}
  }
};
