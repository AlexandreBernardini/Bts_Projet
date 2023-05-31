#ifndef ECRAN_H
#define ECRAN_H

#include <TouchScreen.h>
#include <Adafruit_GFX.h>    // Core graphics library
#include <Adafruit_TFTLCD.h> // Hardware-specific library
#include <SPI.h>

#define LCD_CS A3
#define LCD_CD A2
#define LCD_WR A1
#define LCD_RD A0
#define LCD_RESET A4

#define TS_MINX 140
#define TS_MINY 184
#define TS_MAXX 912
#define TS_MAXY 863

#define YP A3
#define XM A2
#define YM 9
#define XP 8

#define BLACK 0x0000
#define RED 0xF800
#define GREEN 0x07E0
#define CYAN 0x07FF
#define MAGENTA 0xF81F
#define YELLOW 0xFFE0
#define WHITE 0xFFFF
#define BLEU 0x0000FF
#define ORANGEFONCER 0xFF320
#define ORANGECLAIRE 0XFFE60

class EcranTactileG
{
private:
    int centaine;
    int dizaine;
    int unite;
    String teststr;
    String valeurUnite;
    Adafruit_TFTLCD tft = Adafruit_TFTLCD(LCD_CS, LCD_CD, LCD_WR, LCD_RD, LCD_RESET);
    TouchScreen ts = TouchScreen(XP, YP, XM, YM, 364);

public:
    EcranTactileG();
    void init();
    void ihm();                // Initialise L'écran tactile avec tout les boutons qu'on aura besoin
    bool TactilePlus1();       // Boutons pour augmenter la force de pression sur les capteurs le + a gauche
    bool TactilePlus2();       // Boutons pour augmenter la force de pression sur les capteurs le + au millieu
    bool TactilePlus3();       // Boutons pour augmenter la force de pression sur les capteurs le + a droite
    bool TactileMoin1();       // Boutons pour diminuer la force de pression sur les capteurs le - a gauche
    bool TactileMoin2();       // Boutons pour diminuer la force de pression sur les capteurs le - au millieu
    bool TactileMoin3();       // Boutons pour diminuer la force de pression sur les capteurs le - a droite
    void ChangementCentaine(); // permet de modifier la centaine et de l'afficher sur l'écran
    void Changementdizaine();  // permet de modifier la dizaine et de l'afficher sur l'écran
    void ChangementUnite();    // permet de modifier la unité et de l'afficher sur l'écran
    bool BoutonsOK();          // boutons Ok pour validier les valeurs des centaines, dizaines, unités
    void EnvoyerValeur();      // Envoie les valeurs pour validier les centaines, dizaines, unités au raspberry
    void ChangementEnKilo();   // Change le pourcentage (%) en kilo (kg)
    bool BoutonsFinDeSeance();        // Le boutons T permet d'envoyer le mot pour la tare
    void EnvoyerFinDeSeance();        // Envoie un mot pour que la tare soit effectuer
    void EnvoyerOK();     // Recois un ACK si ça marche ou un NACK si ça ne marche pas
    void RemiseDeLaTransmission(); // Après d'avoir appuyer sur le F et d'avoir reçus le ACK on affiche "fin seance"
    void PortSurEcoute(); 
    
};

#endif