# TUB'AIR
## Tutoriel d'installation, de configuraton et de construction du projet Tub'Air !



### Prérequis

#### Matériel

Pour construire votre propre Tub'Air, vous aurez besoin des composants suivants :

*Carte Arduino "Uno"

![](http://nsa38.casimages.com/img/2016/08/30/160830025224881695.jpg)

*Carte Arduino "Ethernet Shield"

![](http://nsa38.casimages.com/img/2016/08/30/160830025442342397.jpg)

*Capteurs MQ 2, 3 et 7, pour la fumée, le monoxyde de carbone et l'alcool

![](http://nsa38.casimages.com/img/2016/08/30/mini_16083003012993680.jpg)

*Capteur DTH11, pour la température et l'humidité

![](http://nsa37.casimages.com/img/2016/08/30/mini_160830030001605707.jpg)

*Une LED rouge et une LED verte

![](http://nsa37.casimages.com/img/2016/09/01/160901040551782599.png)

![](http://nsa38.casimages.com/img/2016/09/01/160901040438910070.png)

*Une pegboard électronique

![](http://nsa38.casimages.com/img/2016/09/01/mini_16090104452149580.png)


#### Compte Tub'Air, logiciel et fichiers essentiels
 
*Créez un compte Tub'Air sur notre site Web : tubair.bitbucket.org

*Téléchargez et installez la dernière version d'Arduino : https://www.arduino.cc/en/Main/Software

*Clonez sur votre machine notre dépôt de fichiers à disposition sur ce lien : https://github.com/quentinkb/tubair

*Remplacez dans le fichier "api.h" les mots "USERNAME" et "PASSWORD" par les identifiants de votre compte Tub'Air créé précédemment

![](http://nsa38.casimages.com/img/2016/08/17/160817104452784409.png)


### Construction du module Arduino


#### Premières étapes jusqu'à connection du module

*Assemblez vos deux cartes Arduino (l'"Ethernet Shield" sur la "Uno"), ce qui devrai donner ceci :

![](http://nsa38.casimages.com/img/2016/08/17/mini_160817114924506168.jpg)

*Branchez la LED verte sur la sortie numérique GPIO 2, et la rouge sur la GPIO 4

![](http://nsa38.casimages.com/img/2016/08/17/160817121623409266.png)

*Ouvrez le fichier "sketch_aug09a.ino" avec le logiciel Arduino téléchargé et installé précédemment

![](http://nsa38.casimages.com/img/2016/08/17/160817121848377371.png)

*Reliez votre module Arduino à votre ordinateur grâce au cable Arduino / USB.
Branchez également un cable Ethernet à votre module.

![](http://nsa38.casimages.com/img/2016/08/30/mini_160830030623301908.jpg)

*Cliquez sur le bouton "Téléverser" et attendez qu'une des deux LEDS s'allume (ce ne devrai pas prendre plus de deux minutes environ)

![](http://nsa37.casimages.com/img/2016/08/17/160817122152909792.png)

*Si la LED verte d'allume, alors la connection à notre serveur est réussie ! En revanche, si la LED rouge s'allume, cela signifie que vous n'avez pas créé votre compte ou bien que vous avez mal recopié vos identidiants dans le fichier "api.h". Rêglez le problème, puis appuyez de nouveau sur le bouton "Téléverser".

*Une fois la LED verte allumée, débranchez votre module Arduino, nous allons installer les capteurs !


#### Installation du capteur de température et d'humidité

*Branchez votre capteur de température et d'humidité du même côté de la "board" que les LEDS, comme on peut le voir ci-dessous :

![](http://nsa38.casimages.com/img/2016/08/17/160817025413718421.png)

#### Autres capteurs

*Branchez les autres capteurs de l'autre côté, mais toujours avec la même méthode, comme ci-dessous :

![](http://nsa37.casimages.com/img/2016/08/17/160817031113671585.png)

#### Connection du module

*Rebranchez votre module Arduino comme à l'étape du test des LEDS !

*Cliquez sur "Téléverser", et les mesures devraient commencer à être prises et envoyées au serveur !

![](http://nsa38.casimages.com/img/2016/08/30/mini_160830030623301908.jpg)

FIN !

Vous pouvez désormais télécharger notre application pour visualiser vos données !
