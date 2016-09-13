#include "api.h" 
#include "TroykaMQ.h"
#define DHTTYPE DHT11
#include "DHT.h"

/**
 * nom : GREEN_LED
 * type : int
 * @description : "LED témoin d'une authentification réussie"
 * 
 * nom : RED_LED
 * type : int
 * @description : "LED témoin d'une mauvaise authentification"
 * 
 * nom : START_LED
 * type : int
 * @description : "LED clignotant une fois pour montrer que le sketch est en cours d'exécution, puis restant allumée le temps de l'authentification"
 */
#define GREEN_LED 2
#define RED_LED 4
#define START_LED 6

/**
 * nom : PIN_MQ2
 * @description : "capteur de fumée"
 * 
 * nom : PIN_MQ3
 * @description : "capteur d'alcool"
 * 
 * nom : PIN_MQ7
 * @description : "capteur de monoxyde de carbone"
 * 
 * nom : DHTPIN
 * @description : "capteur de température et d'humidité"
 */
#define PIN_MQ2 A0
#define PIN_MQ3 A2
#define PIN_MQ7 A1
#define DHTPIN 5
