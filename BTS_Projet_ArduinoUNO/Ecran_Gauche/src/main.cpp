#include <IHMG.h>

EcranTactileG Ecran;
void setup()
{
  Serial.begin(9600); //vitesse de transmission en bit/s
  Ecran.init();
  Ecran.ihm();
}
void loop()
{
  Ecran.TactilePlus1();
  Ecran.TactileMoin1();
  Ecran.TactilePlus2();
  Ecran.TactileMoin2();
  Ecran.TactilePlus3();
  Ecran.TactileMoin3();

  Ecran.BoutonsOK();
  Ecran.BoutonsFinDeSeance();
  Ecran.PortSurEcoute();
}
