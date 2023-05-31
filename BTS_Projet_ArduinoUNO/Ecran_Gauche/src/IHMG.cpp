#include <IHMG.h>

EcranTactileG::EcranTactileG()
{
    centaine = 0;
    dizaine = 5;
    unite = 0;
    valeurUnite = "GM&";
}

void EcranTactileG::init()
{
    tft.reset();
    tft.fillScreen(BLACK);
    uint16_t identifier = tft.readID();
    tft.begin(identifier);
}

void EcranTactileG::ihm()
{
    // Page d'affichage
    tft.fillScreen(BLACK);
    tft.setRotation(2);

    tft.fillRect(10, 10, 140, 60, ORANGECLAIRE); // Bouton T
    tft.fillRect(20, 250, 60, 60, GREEN);        // Bouton +1
    tft.fillRect(170, 250, 60, 60, BLEU);        // Bouton -1
    tft.fillRect(20, 180, 60, 60, GREEN);        // Bouton +2
    tft.fillRect(170, 180, 60, 60, BLEU);        // Bouton -2
    tft.fillRect(20, 110, 60, 60, GREEN);        // Bouton +3
    tft.fillRect(170, 110, 60, 60, BLEU);        // Bouton -3
    tft.fillRect(170, 10, 60, 60, ORANGEFONCER); // OK

    // Bouton T
    tft.setCursor(267, 70);
    tft.setRotation(1);
    tft.setTextColor(WHITE);
    tft.setTextSize(5);
    tft.print("F");

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

    // Kilo
    tft.setCursor(205, 120);
    tft.setTextColor(WHITE);
    tft.setTextSize(3);
    tft.print("kg");

    // OK
    tft.setCursor(260, 185);
    tft.setTextColor(WHITE);
    tft.setTextSize(4);
    tft.print("OK");

}

bool EcranTactileG::TactilePlus1()
{
    TSPoint p = ts.getPoint();

    if (p.z > ts.pressureThreshhold)
    {
        //Serial.print("avant map p.x = " + String(p.x) + " p.y = " + String(p.y)+ "\n");
        p.x = map(p.x, TS_MAXX, TS_MINX, 0, 320);
        p.y = map(p.y, TS_MAXY, TS_MINY, 0, 480);
        //Serial.print("apres map p.x = " + String(p.x) + " p.y = " + String(p.y)+ "\n\n");

        if (p.x > 20 && p.x < 80 && p.y > 20 && p.y < 80)
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
                dizaine = 0;
                Changementdizaine();
                unite = 0;
                ChangementUnite();
                ChangementCentaine();
            }
        }
        return true;
    }
    else
        return false;
}

bool EcranTactileG::TactileMoin1()
{
    TSPoint p = ts.getPoint();

    if (p.z > ts.pressureThreshhold)
    {

        p.x = map(p.x, TS_MAXX, TS_MINX, 0, 320);
        p.y = map(p.y, TS_MAXY, TS_MINY, 0, 480);

        if (p.x > 250 && p.x < 320 && p.y > 20 && p.y < 80)
        {

            pinMode(XM, OUTPUT);
            pinMode(YP, OUTPUT);
            centaine = centaine - 1;
            if (centaine < 0)
            {
                centaine = 0;
            }
            ChangementCentaine();
            delay(100);
        }
        return true;
    }
    else
        return false;
}

void EcranTactileG::ChangementCentaine()
{
    tft.fillRect(10, 100, 60, 60, BLACK);
    tft.setCursor(20, 100);
    tft.setRotation(1);
    tft.setTextColor(WHITE);
    tft.setTextSize(6);
    tft.println(centaine);
    tft.setRotation(1);
}

bool EcranTactileG::TactilePlus2()
{
    TSPoint p = ts.getPoint();

    if (p.z > ts.pressureThreshhold)
    {
        //Serial.print("avant map p.x = " + String(p.x) + " p.y = " + String(p.y)+ "\n");
        p.x = map(p.x, TS_MAXX, TS_MINX, 0, 320);
        p.y = map(p.y, TS_MAXY, TS_MINY, 0, 480);
        //Serial.print("apres map p.x = " + String(p.x) + " p.y = " + String(p.y)+ "\n\n");

        if (p.x > 30 && p.x < 70 && p.y > 140 && p.y < 200)
        {

            pinMode(XM, OUTPUT);
            pinMode(YP, OUTPUT);
            dizaine = dizaine + 1;
            if (dizaine > 9)
            {
                dizaine = 0;
            }
            Changementdizaine();
            delay(100);
        }

        return true;
    }
    else
        return false;
}

bool EcranTactileG::TactileMoin2()
{
    TSPoint p = ts.getPoint();

    if (p.z > ts.pressureThreshhold)
    {

        p.x = map(p.x, TS_MAXX, TS_MINX, 0, 320);
        p.y = map(p.y, TS_MAXY, TS_MINY, 0, 480);

        if (p.x > 250 && p.x < 320 && p.y > 160 && p.y < 220)
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
        }
        Changementdizaine();
        delay(100);
        return true;
    }
    else
        return false;
}

void EcranTactileG::Changementdizaine()
{
    tft.fillRect(70, 100, 60, 60, BLACK);
    tft.setCursor(90, 100);
    tft.setRotation(1);
    tft.setTextColor(WHITE);
    tft.setTextSize(6);
    tft.println(dizaine);
    tft.setRotation(1);
}

bool EcranTactileG::TactilePlus3()
{
    TSPoint p = ts.getPoint();

    if (p.z > ts.pressureThreshhold)
    {
        //Serial.print("avant map p.x = " + String(p.x) + " p.y = " + String(p.y)+ "\n");
        p.x = map(p.x, TS_MAXX, TS_MINX, 0, 320);
        p.y = map(p.y, TS_MAXY, TS_MINY, 0, 480);
        //Serial.print("apres map p.x = " + String(p.x) + " p.y = " + String(p.y)+ "\n\n");

        if (p.x > 30 && p.x < 70 && p.y > 270 && p.y < 330)
        {

            pinMode(XM, OUTPUT);
            pinMode(YP, OUTPUT);
            unite = unite + 1;
            if (unite > 9)
            {
                unite = 0;
            }
            ChangementUnite();
            delay(100);
        }

        return true;
    }
}

bool EcranTactileG::TactileMoin3()
{
    TSPoint p = ts.getPoint();

    if (p.z > ts.pressureThreshhold)
    {

        p.x = map(p.x, TS_MAXX, TS_MINX, 0, 320);
        p.y = map(p.y, TS_MAXY, TS_MINY, 0, 480);

        if (p.x > 250 && p.x < 320 && p.y > 280 && p.y < 320)
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
            delay(100);
        }
        return true;
    }
    else
        return false;
}

void EcranTactileG::ChangementUnite()
{
    tft.fillRect(140, 100, 60, 60, BLACK);
    tft.setCursor(165, 100);
    tft.setRotation(1);
    tft.setTextColor(WHITE);
    tft.setTextSize(6);
    tft.println(unite);
    tft.setRotation(1);
}

bool EcranTactileG::BoutonsOK()
{
    TSPoint p = ts.getPoint();

    if (p.z > ts.pressureThreshhold)
    {

        p.x = map(p.x, TS_MAXX, TS_MINX, 0, 320);
        p.y = map(p.y, TS_MAXY, TS_MINY, 0, 480);

        if (p.x > 250 && p.x < 310 && p.y > 460 && p.y < 520)
        {

            pinMode(XM, OUTPUT);
            pinMode(YP, OUTPUT);
            EnvoyerValeur();
            delay(50);
            if (Serial.available() > 0)
            {
                if (Serial.readString() == "ACK")
                {
                    EnvoyerOK();
                    delay(500);
                    ChangementEnKilo();
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

void EcranTactileG::EnvoyerValeur()
{
    Serial.print(centaine);
    Serial.print(dizaine);
    Serial.print(unite);
    Serial.print(valeurUnite);
    delay(500);
}
void EcranTactileG::ChangementEnKilo()
{
    tft.fillRect(205, 120, 40, 40, BLACK);
    tft.setCursor(210, 120);
    tft.setRotation(1);
    tft.setTextColor(WHITE);
    tft.setTextSize(3);
    tft.println("%");
    tft.setRotation(1);
    valeurUnite = "GP&";
}
void EcranTactileG::EnvoyerFinDeSeance()
{
    tft.fillRect(200, 120, 50, 50, BLACK);
    tft.setCursor(210, 120);
    tft.setRotation(1);
    tft.setTextColor(WHITE);
    tft.setTextSize(3);
    tft.println("kg");
    tft.setRotation(1);
    valeurUnite = "GM&";
}

void EcranTactileG::EnvoyerOK()
{
    tft.fillRect(250, 150, 20, 20, BLACK);
    tft.fillRect(270, 150, 20, 20, BLACK);
    tft.setCursor(255, 160);
    tft.setRotation(1);
    tft.setTextColor(WHITE);
    tft.setTextSize(1);
    tft.println("OK");
    tft.setRotation(1);
}

void EcranTactileG::RemiseDeLaTransmission()
{
    tft.fillRect(250, 150, 20, 20, BLACK);
    tft.fillRect(270, 150, 20, 20, BLACK);
    tft.setCursor(255, 160);
    tft.setRotation(1);
    tft.setTextColor(WHITE);
    tft.setTextSize(1);
    tft.println("fin seance");
    tft.setRotation(1);
}

bool EcranTactileG::BoutonsFinDeSeance()
{
    TSPoint p = ts.getPoint();

    if (p.z > ts.pressureThreshhold)
    {

        p.x = map(p.x, TS_MAXX, TS_MINX, 0, 320);
        p.y = map(p.y, TS_MAXY, TS_MINY, 0, 480);

        if (p.x > 10 && p.x < 150 && p.y > 460 && p.y < 520)
        {

            pinMode(XM, OUTPUT);
            pinMode(YP, OUTPUT);
            Serial.print("FIN&");
            delay(50);
            if (Serial.available() > 0)
            {
                if (Serial.readString() == "ACK")
                {
                    RemiseDeLaTransmission();
                    delay(50);
                    EnvoyerFinDeSeance();
                    delay(500);
                    tft.fillRect(250, 150, 20, 20, BLACK);
                    tft.fillRect(265, 150, 20, 20, BLACK);
                    tft.fillRect(275, 150, 20, 20, BLACK);
                    tft.fillRect(285, 150, 20, 20, BLACK);
                    tft.fillRect(295, 150, 20, 20, BLACK);
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

void EcranTactileG::PortSurEcoute()
{
    String data;
    int portDispo, etat = 0;
    portDispo = Serial.available();
    while (portDispo > 0)
    {
        data = Serial.readString();
    
    
       switch (etat)
       {
       case 1:
        if (data == "FinDeSeance&")
        {
            ihm();
        }
        break;
       }
    }   
}