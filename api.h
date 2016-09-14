#include <Ethernet.h>

/**
 * nom : USERNAME
 * type : String
 * @description : "identifiant : nom du compte utilisateur, nécessaire pour l'authentification"
 * 
 * nom : PASSWORD
 * type : String
 * @description : "identifiant : mot de passe du compte utilisateur, nécessaire pour l'authentification"
 */
#define USERNAME "tuba"
#define PASSWORD "tubatest"

class Api {
  public : 
  int userDoHead();
  void mesureDoPost(String valeur,String id_capteurs,String polluant, int security);
}; 
