#include <IHMD.h>

EcranTactile::EcranTactile()
{
    centaine = 0;
    dizaine = 5;
    unite = 0;
    valeurUnite = "DP&";
}

void EcranTactile::init()
{
    tft.reset();
    tft.fillScreen(BLACK);
    uint16_t identifier = tft.readID();
    tft.begin(identifier);
}

void EcranTactile::ihm()
{
    // Page d'affichage
    tft.fillScreen(BLACK);
    tft.fillRect(10, 10, 140, 60, ORANGECLAIRE);  // Bouton G
    tft.fillRect(20, 250, 60, 60, GREEN);        // Bouton +1
    tft.fillRect(170, 250, 60, 60, BLEU);        // Bouton -1
    tft.fillRect(20, 180, 60, 60, GREEN);        // Bouton +2
    tft.fillRect(170, 180, 60, 60, BLEU);        // Bouton -2
    tft.fillRect(20, 110, 60, 60, GREEN);        // Bouton +3
    tft.fillRect(170, 110, 60, 60, BLEU);        // Bouton -3
    tft.fillRect(170, 10, 60, 60, ORANGEFONCER); // OK


    // Bouton G
    tft.setCursor(270, 70);
    tft.setRotation(3);
    tft.setTextColor(WHITE);
    tft.setTextSize(5);
    tft.print("T");

    // le +1
    tft.setCursor(30, 30);
    tft.setTextColor(WHITE);
    tft.setTextSize(5);
    tft.print("+");

    // le -1
    tft.setCursor(30, 185);
    tft.setTextColor(WHITE);
    tft.setTextSize(5);
    tft.print("-");

    // le +2
    tft.setCursor(95, 30);
    tft.setTextColor(WHITE);
    tft.setTextSize(5);
    tft.print("+");

    // le -2
    tft.setCursor(95, 185);
    tft.setTextColor(WHITE);
    tft.setTextSize(5);
    tft.print("-");

    // le +3
    tft.setCursor(165, 30);
    tft.setTextColor(WHITE);
    tft.setTextSize(5);
    tft.print("+");

    // le -3
    tft.setCursor(165, 185);
    tft.setTextColor(WHITE);
    tft.setTextSize(5);
    tft.print("-");

    // Centieme
    tft.setCursor(20, 100);
    tft.setTextColor(WHITE);
    tft.setTextSize(6);
    tft.print(centaine);

    // Dixieme
    tft.setCursor(90, 100);
    tft.setTextColor(WHITE);
    tft.setTextSize(6);
    tft.print(dizaine);

    // Unite
    tft.setCursor(165, 100);
    tft.setTextColor(WHITE);
    tft.setTextSize(6);
    tft.print(unite);

    // kilo
    tft.setCursor(205, 120);
    tft.setTextColor(WHITE);
    tft.setTextSize(3);
    tft.print("%");

    // OK
    tft.setCursor(260, 185);
    tft.setTextColor(WHITE);
    tft.setTextSize(4);
    tft.print("OK");

   
}

bool EcranTactile::TactilePlus1()
{
    TSPoint p = ts.getPoint();

    if (p.z > ts.pressureThreshhold)
    {
        
        p.x = map(p.x, TS_MAXX, TS_MINX, 0, 320);
        p.y = map(p.y, TS_MAXY, TS_MINY, 0, 480);

        if (p.x > 250 && p.x < 310 && p.y > 400 && p.y < 490)
        {

            pinMode(XM, OUTPUT);
            pinMode(YP, OUTPUT);
            centaine = centaine + 1;

            if (centaine > 1)
            {
                centaine = 1;
            }

            if (centaine == 1)
            {
                unite = 0;
                ChangementUnite();
                dizaine = 0;
                Changementdizaine();
                ChangementCentaine();
                delay(100);
            }
        }
        return true;
    }
    else
        return false;
}

bool EcranTactile::TactileMoin1()
{
    TSPoint p = ts.getPoint();

    if (p.z > ts.pressureThreshhold)
    {

        p.x = map(p.x, TS_MAXX, TS_MINX, 0, 320);
        p.y = map(p.y, TS_MAXY, TS_MINY, 0, 480);

        if (p.x > 0 && p.x < 70 && p.y > 400 && p.y < 490)
        {

            pinMode(XM, OUTPUT);
            pinMode(YP, OUTPUT);
            centaine = centaine - 1;
            if (centaine < 0)
            {
                centaine = 0;
            }
            ChangementCentaine();
            delay(200);
        }
        return true;
    }
    else
        return false;
}

void EcranTactile::ChangementCentaine()
{
    tft.fillRect(10, 90, 60, 60, BLACK);
    tft.setCursor(20, 100);
    tft.setRotation(3);
    tft.setTextColor(WHITE);
    tft.setTextSize(6);
    tft.println(centaine);
    // tft.setRotation(1);
}

bool EcranTactile::TactilePlus2()
{
    TSPoint p = ts.getPoint();

    if (p.z > ts.pressureThreshhold)
    {

        p.x = map(p.x, TS_MAXX, TS_MINX, 0, 320);
        p.y = map(p.y, TS_MAXY, TS_MINY, 0, 480);

        if (p.x > 260 && p.x < 300 && p.y > 340 && p.y < 390)
        {

            pinMode(XM, OUTPUT);
            pinMode(YP, OUTPUT);
            dizaine = dizaine + 1;
            if (dizaine > 9)
            {
                dizaine = 0;
            }
            Changementdizaine();
            delay(200);
        }

        return true;
    }
    else
        return false;
}

bool EcranTactile::TactileMoin2()
{
    TSPoint p = ts.getPoint();

    if (p.z > ts.pressureThreshhold)
    {

        p.x = map(p.x, TS_MAXX, TS_MINX, 0, 320);
        p.y = map(p.y, TS_MAXY, TS_MINY, 0, 480);

        if (p.x > 20 && p.x < 60 && p.y > 340 && p.y < 400)
        {

            pinMode(XM, OUTPUT);
            pinMode(YP, OUTPUT);
            dizaine = dizaine - 1;
            if (dizaine < 0)
            {
                dizaine = 9;
            }
            if (centaine == 1)
            {
                if (dizaine == 9)
                {
                    centaine =0;
                    ChangementCentaine();
                }
            }
            Changementdizaine();
            delay(200);
        }

        return true;
    }
    else
        return false;
}

void EcranTactile::Changementdizaine()
{
    tft.fillRect(80, 90, 60, 60, BLACK);
    tft.setRotation(3);
    tft.setCursor(90, 100);
    tft.setTextColor(WHITE);
    tft.setTextSize(6);
    tft.println(dizaine);
    // tft.setRotation(1);
}

bool EcranTactile::TactilePlus3()
{
    TSPoint p = ts.getPoint();

    if (p.z > ts.pressureThreshhold)
    {

        p.x = map(p.x, TS_MAXX, TS_MINX, 0, 320);
        p.y = map(p.y, TS_MAXY, TS_MINY, 0, 480);

        if (p.x > 260 && p.x < 300 && p.y > 220 && p.y < 260)
        {

            pinMode(XM, OUTPUT);
            pinMode(YP, OUTPUT);
            unite = unite + 1;
            if (unite > 9)
            {
                unite = 0;
            }
            ChangementUnite();
            delay(150);
        }

        return true;
    }
    else
        return false;
}

bool EcranTactile::TactileMoin3()
{
    TSPoint p = ts.getPoint();

    if (p.z > ts.pressureThreshhold)
    {

        p.x = map(p.x, TS_MAXX, TS_MINX, 0, 320);
        p.y = map(p.y, TS_MAXY, TS_MINY, 0, 480);

        if (p.x > 20 && p.x < 60 && p.y > 200 && p.y < 240)
        {

            pinMode(XM, OUTPUT);
            pinMode(YP, OUTPUT);
            unite = unite - 1;
            if (unite < 0)
            {
                unite = 9;
            }
            if (centaine == 1)
            {
                if(unite == 9)
                {
                    
                    if (dizaine == 0)
                    {
                        centaine = 0;
                        ChangementCentaine();
                        dizaine = 9;
                        Changementdizaine();
                    }
                }
            }
            ChangementUnite();
            delay(150);
        }
        return true;
    }
    else
        return false;
}

void EcranTactile::ChangementUnite()
{
    tft.fillRect(140, 90, 60, 60, BLACK);
    tft.setCursor(165, 100);
    tft.setRotation(3);
    tft.setTextColor(WHITE);
    tft.setTextSize(6);
    tft.println(unite);
    // tft.setRotation(1);
}

bool EcranTactile::BoutonsOK()
{
    TSPoint p = ts.getPoint();

    if (p.z > ts.pressureThreshhold)
    {

        p.x = map(p.x, TS_MAXX, TS_MINX, 0, 320);
        p.y = map(p.y, TS_MAXY, TS_MINY, 0, 480);

        if (p.x > 10 && p.x < 60 && p.y > 10 && p.y < 60)
        {

            pinMode(XM, OUTPUT);
            pinMode(YP, OUTPUT);
            EnvoyerValeur();

            delay(1000);
            if (Serial.available() > 0)
            {
                if (Serial.readString() == "ACK")
                {
                    EnvoyerOK();
                    delay(200);
                    delay(2000);
                    tft.fillRect(250, 150, 20, 20, BLACK);
                    tft.fillRect(265, 150, 20, 20, BLACK);
                    
                }
            }
            else
            {
                if (Serial.readString() == "NACK")
                {
                }
            }
        }

        return true;
    }
    else
        return false;
}

void EcranTactile::EnvoyerOK()
{
    tft.fillRect(250, 150, 20, 20, BLACK);
    tft.fillRect(265, 150, 20, 20, BLACK);
    tft.setCursor(250, 160);
    tft.setRotation(3);
    tft.setTextColor(WHITE);
    tft.setTextSize(1);
    tft.println("OK");
}

void EcranTactile::RemiseDeLaTransmission()
{
    tft.fillRect(250, 150, 20, 20, BLACK);
    tft.fillRect(265, 150, 20, 20, BLACK);
    tft.setCursor(250, 160);
    tft.setRotation(3);
    tft.setTextColor(WHITE);
    tft.setTextSize(1);
    tft.println("TARE");
    
}

void EcranTactile::EnvoyerValeur()
{
    Serial.print(centaine);
    Serial.print(dizaine);
    Serial.print(unite);
    Serial.print(valeurUnite);
    delay(500);
}

void EcranTactile::EnvoyerTare()
{
    Serial.print("GM&");
    delay(500);
}
bool EcranTactile::BoutonsTare()
{
    TSPoint p = ts.getPoint();

    if (p.z > ts.pressureThreshhold)
    {

        p.x = map(p.x, TS_MAXX, TS_MINX, 0, 320);
        p.y = map(p.y, TS_MAXY, TS_MINY, 0, 480);

        if (p.x > 170 && p.x < 320 && p.y > 20 && p.y < 60)
        {

            pinMode(XM, OUTPUT);
            pinMode(YP, OUTPUT);
            Serial.print("TareD&");
            delay(50);
            if (Serial.available() > 0)
            {
                if (Serial.readString() == "ACK")
                {
                    RemiseDeLaTransmission();
                    delay(50);
                    EnvoyerTare();
                    delay(500);
                    tft.fillRect(250, 150, 20, 20, BLACK);
                    tft.fillRect(265, 150, 20, 20, BLACK);
                    
                }
            }
            else
            {
                if (Serial.readString() == "NACK")
                {
                }
            }
        }
        return true;
    }
    else
        return false;
}