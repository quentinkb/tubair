![](http://nsa38.casimages.com/img/2016/12/09/161209110930948111.jpg)

# TUB'AIR
## Tutoriel d'installation, de configuraton et de construction du projet Tub'Air !




### Prérequis


#### Matériel

Pour construire votre propre Tub'Air, vous aurez besoin des composants suivants :

*Carte Arduino "Uno"

![](http://nsa37.casimages.com/img/2016/11/22/161122104322408995.jpg)

*Carte Arduino "Ethernet Shield"

![](http://nsa38.casimages.com/img/2016/11/22/16112210441874942.jpg)

Petite précision concernant la carte Ethernet Shield sur l’image ci-dessous : Le zone en vert représente les sorties numériques, celle en rouge, les sorties analogiques.

![](http://nsa37.casimages.com/img/2016/12/09/mini_161209114051630413.jpg)

*Les capteurs MQ, de catégories 2, 3 et 7, pour mesurer respectivement la fumée, l’alcool et le monoxyde de carbone

![](http://nsa37.casimages.com/img/2016/11/22/161122104559607718.jpg)

*Capteur DHT11, pour la température et l'humidité

![](http://nsa37.casimages.com/img/2016/11/22/161122104701625131.jpg)

*Deux LEDS de couleur différentes, disons une rouge et une verte

![](http://nsa38.casimages.com/img/2016/11/22/161122104728925534.png)

![](http://nsa38.casimages.com/img/2016/11/22/161122104753354765.png)

Ah oui, petite précision pour les LEDS, il y a toujours une tige plus longue que l’autre. Le courant doit rentrer du côté de la tige la plus longue, et ressortir du côté de la tige la plus courte.

*Une pegboard électronique

![](http://nsa38.casimages.com/img/2016/11/22/161122104815425934.png)

Petite précision aussi pour le breadboard, afin que nous nous comprenions bien par la suite (se reporter à l’image ci-dessous). On appellera respectivement les zones bleues et rouges, les bandes « - » et « + ». On appellera la zone orange, la « masse ».
![](http://nsa38.casimages.com/img/2016/12/09/161209111312720688.png)

Concernant le fonctionnement du breadboard, il est en réalité très simple. Observez cette image :
![](http://nsa38.casimages.com/img/2016/12/09/161209111400214979.png)

Si on se réfère à l’image ci-dessus, on peut dire que dans les bandes « + » et « - », le courant circule « verticalement ». En revanche, dans la « masse », le courant circule « horizontalement ». Il sera donc important pour la suite, de ne pas placer par exemple les LEDS et les capteurs sur les mêmes lignes horizontales dans la « masse » !
Vous pouvez observer que le capteur en haut de l’image possède plusieurs terminaisons électriques. Il est important que chacune soit sur des lignes horizontales de la « masse » différentes !


*18 fils mâle-mâle

![](http://nsa37.casimages.com/img/2016/11/22/161122105844916536.jpg)



#### Compte Tub'Air, logiciel et fichiers essentiels
 
*Créez un compte Tub'Air sur notre site Web : tubair.bitbucket.org

*Téléchargez et installez la dernière version d'Arduino : https://www.arduino.cc/en/Main/Software

*Clonez sur votre machine notre dépôt de fichiers à disposition sur ce lien : https://github.com/quentinkb/tubair

*Ouvrez le fichier « sketch_aug09a.ino » (dans le dossier que vous venez de télécharger) avec le logiciel Arduino. Remplacez les variables « USERNAME » et « PASSWORD » écrits entre guillemets dans le fichier « api.h », par les identifiants de votre compte Tub’Air créé précédemment

![](http://nsa38.casimages.com/img/2016/08/17/160817104452784409.png)




### Construction du module Arduino

Dans cette seconde partie, pour une meilleure clarté des images, je me permets de ne pas représenter de nouveau les branchements des étapes de constructions précédentes.

#### Premières étapes jusqu'à connection du module

*Assemblez vos deux cartes Arduino (l'"Ethernet Shield" sur la "Uno"), ce qui devrai donner ceci :

![](http://nsa38.casimages.com/img/2016/08/17/mini_160817114924506168.jpg)

Je vous conseille de positionner préalablement le breadboard et la carte arduino comme sur l’image suivante (la bande « - » extérieure sur la droite, la carte Arduino à droite du breadboard).
![](http://nsa37.casimages.com/img/2016/12/09/161209111702953539.png)

Mettez sous tension le breadboard à l’aide de deux fils : un partant du port 5V de la carte Arduino, allant en bas de la bande « + », l’autre partant du port GND (juste à côté du 5V) et allant en bas de la bande « - ».

*Branchez les LEDS sur le breadboard, et reliez-les vers le module Arduino. La LED verte sur la sortie numérique 2, et la LED rouge sur la 4

![](http://nsa38.casimages.com/img/2016/11/22/161122111907378510.png)

Vous vous souvenez qu’il y a une tige plus longue pour chaque LED ? Oui ? Alors, pour chaque LED, branchez cette tige plus longue dans la masse, et la tige plus courte dans la bande « - ».
IMPORTANT : les fils doivent partir de la même ligne que les LED (vous voyez les lignes légèrement vertes sur l’image ci-dessus, eh bien voilà, ces lignes-là).

*Ouvrez le fichier "sketch_aug09a.ino" avec le logiciel Arduino téléchargé et installé précédemment

![](http://nsa38.casimages.com/img/2016/08/17/160817121848377371.png)

*Reliez votre module Arduino à votre ordinateur grâce au cable Arduino / USB.
Branchez également un cable Ethernet à votre module.

![](http://nsa38.casimages.com/img/2016/08/30/mini_160830030623301908.jpg)

Veillez à vérifier dans l’onglet « outils » / « port » qu’un port est bien sélectionné une fois votre module branché.

Cliquez sur le bouton "Téléverser" et attendez qu'une des deux LEDS s'allume (ce ne devrai pas prendre plus de deux minutes)

![](http://nsa37.casimages.com/img/2016/08/17/160817122152909792.png)

Si la LED verte s’allume, alors la connexion à notre serveur est réussie ! En revanche, si la LED rouge s’allume, cela signifie que vous n’avez pas créé votre compte ou bien que vous avec mal recopié vos identifiants dans le fichier « api.h ». Réglez le problème, puis appuyez de nouveau sur « Téléverser ». Une fois la LED verte allumée, débranchez votre module Arduino, car nous allons brancher les autres capteurs !



#### Installation du capteur de température et d'humidité

*Branchez votre capteur de température et d’humidité (DHT11) du même côté du breadboard que les LEDS (mais attention, rappelez-vous, pas sur les mêmes lignes horizontales que les LEDS dans la « masse »). Reliez le capteur comme sur l’image, aux bandes « + » et « - », ainsi qu’à la sortie numérique 5.

![](http://nsa37.casimages.com/img/2016/11/22/161122112536707832.png)

Petite précision, je vous conseille de placer le capteur de sorte à ce que les tiges pour le brancher soient du côté extérieur du breadboard. Cela sera sûrement plus clair en image :

![](http://nsa38.casimages.com/img/2016/12/09/mini_161209114534541471.jpg)
![](http://nsa37.casimages.com/img/2016/12/09/mini_161209114611614575.jpg)

#### Alimentation de l'autre côté du breadboard

*Pour cette partie, très simple rassurez-vous, il suffit de faire communiquer les bandes de chaque côté du breadboard grâce à deux fils

![](http://nsa38.casimages.com/img/2016/12/09/mini_161209114714613327.jpg)

#### Installation des capteurs MQ

*Branchez les autres capteurs de l’autre côté du breadboard. Le capteur MQ2 sur la sortie analogique A0, MQ7 sur A1 et MQ3 sur A2 (attention à l’ordre, c’est important !), comme sur l’image ci-dessous.

NB : ces trois capteurs se branchent exactement de la même manière.

![](http://nsa38.casimages.com/img/2016/12/09/161209112503630404.png)

Petite précision comme pour le capteur DHT11, les tiges des capteurs vers l’extérieur du breadboard.

![](http://nsa38.casimages.com/img/2016/12/09/mini_161209114757410893.jpg)
![](http://nsa38.casimages.com/img/2016/12/09/mini_161209114735316714.jpg)

#### Connection finale du module

*Rebranchez votre module Arduino comme à l'étape du test des LEDS !

*Cliquez sur "Téléverser", et les mesures devraient commencer à être prises et envoyées au serveur !

![](http://nsa38.casimages.com/img/2016/08/30/mini_160830030623301908.jpg)

FIN !

Rendez-vous sur tubair.bitbucket.org
Connectez-vous avec vos identifiants Tub'Air, et visualisez vos données
