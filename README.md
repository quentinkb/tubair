# TUB'AIR
Arduino open source code for TUB'AIR project
## v0.0.1



### Prerequisites

#### Materials

To build your proper Tub'Air, you will need :

*an Arduino Uno card

![](http://nsa38.casimages.com/img/2016/08/30/160830025224881695.jpg)

*an Arduino ethernet shield card

![](http://nsa38.casimages.com/img/2016/08/30/160830025442342397.jpg)

*MQ 2, 3, 7 sensors

![](http://nsa38.casimages.com/img/2016/08/30/160830025613784264.jpg)

*DTH11 sensor

![](http://nsa37.casimages.com/img/2016/08/30/160830030001605707.jpg)

#### Account and files
 
*Create an account on tubair.bitbucket.org.

*Download and install the last version of Arduino : https://www.arduino.cc/en/Main/Software

*Clone all the repository on this link : https://github.com/quentinkb/tubair

*Replace USERNAME and PASSWORD variables into api.h file by your TUB'AIR account IDs.

![](http://nsa38.casimages.com/img/2016/08/17/160817104452784409.png)


### Arduino boards building


#### First steps and log in

*Connect your Arduino boards (the ethernet shield one on the top) :

![](http://nsa38.casimages.com/img/2016/08/17/mini_160817114924506168.jpg)

*Branch one green led on GPIO 2 and one red led on GPIO 4. 

![](http://nsa38.casimages.com/img/2016/08/17/160817121623409266.png)

*Launch the sketch_aug09a.ino arduino file.

![](http://nsa38.casimages.com/img/2016/08/17/160817121848377371.png)

*Click this button and wait a led lights up (about 2 minutes maximum).

![](http://nsa37.casimages.com/img/2016/08/17/160817122152909792.png)

*If the green led lights up, the connexion to our server is well initialized. If the red led lights up, you may have set a wrong username or password into the api.h file. Replace them with your TUB'AIR account IDs and try again to click the button.


#### Humidity and temperature sensor installation

*Branch your humidity and temperature sensor on the same side as old connections in previous step.

![](http://nsa38.casimages.com/img/2016/08/17/160817025413718421.png)

#### Other sensors

*Branch other sensors on the other side. Connect both sides and connect sensors as follow :

![](http://nsa37.casimages.com/img/2016/08/17/160817031113671585.png)



END !

You can now download our App and see your stats !
