//---------------------------------
#include <EEPROM.h>
#include <RCSwitch.h>
//---------------------------------
const int value_length = 100;
int Sensorvalues1[value_length];
int Sensorvalues2[value_length];
int Sensorvalues3[value_length];
int Sensorvalues4[value_length];
//---------------------------------
int ButonGiris        = 9;
int Transistor_Buzzer = 5;
int Role_Siren        = 4;
int Role_Lamba        = 3;
int SensorBasladi;
//---------------------------------
int Transistor_Lamba1 = 10;
int Transistor_Lamba2 = 11;
int Transistor_Lamba3 = 12;
int Transistor_Lamba4 = 13;
//---------------------------------
const int BUFSIZE = 25;
char Button1GetData[BUFSIZE];
char Button2GetData[BUFSIZE];
char Button3GetData[BUFSIZE];
char Button4GetData[BUFSIZE];
int TanimlamaButonSira;
char buf[BUFSIZE];
//---------------------------------
int KorumaModuDurum;
int LambaDurumu;
int TanimaModu;
int RFGelenData;
int RFDelay;
int LambaSira;
int LambaZamanlayici;
int GuvenlikHatasi;
int GuvenlikHatasiSure;
int PanikAcikmi;
int PanikSure;
int OncekiLedSira;
int StandartLedDurum;
int FlasorLambaZamanlayici;
int FlasorLambaDurum;
//---------------------------------
RCSwitch mySwitch = RCSwitch();
//------------------------------------------------------------------------------------------------------
//------------------------------------------------------------------------------------------------------
void setup(){
  //---------------------------------
  mySwitch.enableReceive(0);
  //---------------------------------
  pinMode(Role_Siren,OUTPUT); pinMode(Role_Lamba,OUTPUT); pinMode(Transistor_Lamba1, OUTPUT); pinMode(Transistor_Lamba2, OUTPUT); pinMode(Transistor_Lamba3, OUTPUT); pinMode(Transistor_Lamba4, OUTPUT); pinMode(ButonGiris,INPUT); pinMode(Transistor_Buzzer, OUTPUT);
  //---------------------------------
  KorumaModuDurum = EEPROM.read(0);
  LambaDurumu     = EEPROM.read(1);
  //---------------------------------
  if (KorumaModuDurum == 1){digitalWrite(Role_Siren, HIGH);delay(250);digitalWrite(Role_Siren, LOW);}
  if (LambaDurumu == 1){digitalWrite(Role_Lamba, HIGH);}
  //---------------------------------
  LambaSira = 10;
  LambaZamanlayici = 0;
  //---------------------------------
  eeprom_read_string(10, Button1GetData, BUFSIZE);
  eeprom_read_string(40, Button2GetData, BUFSIZE);
  eeprom_read_string(70, Button3GetData, BUFSIZE);
  eeprom_read_string(100, Button4GetData, BUFSIZE);
}
//------------------------------------------------------------------------------------------------------
//------------------------------------------------------------------------------------------------------
void loop(){
  //---------------------------------
  SystemBasitZamanlayici();
  //---------------------------------
  if (KorumaModuDurum == 1){
    //---------------------------------
    if (SensorBasladi == 0){
        SensorKontrolEt();
    }else{
         SensorBasladi = SensorBasladi - 1;
    }
    if(LambaZamanlayici == 50){LambaCalistir();LambaZamanlayici = 0;}else{LambaZamanlayici = LambaZamanlayici +1;}
    //---------------------------------
    if(GuvenlikHatasi == 1){
        if (GuvenlikHatasiSure == 0){
          GuvenlikHatasi = 0;
          if (LambaDurumu == 1){digitalWrite(Role_Lamba, HIGH);}else{digitalWrite(Role_Lamba, LOW);}
          FlasorLambaZamanlayici = 0;
          FlasorLambaDurum = 0;
          digitalWrite(Role_Siren, LOW);
        }else{
          if(FlasorLambaZamanlayici == 100){FlasorLambaCalistir();FlasorLambaZamanlayici = 0;}else{FlasorLambaZamanlayici = FlasorLambaZamanlayici +1;}
          GuvenlikHatasiSure = GuvenlikHatasiSure -1;
        }
    }
    //---------------------------------
    if (mySwitch.available()){RFKontrolEtKoruma();mySwitch.resetAvailable();}
    //---------------------------------
  }else{
  //---------------------------------
    if (TanimaModu == 0){
        //---------------------------------
        if (mySwitch.available()){RFKontrolEtStandart();mySwitch.resetAvailable();}
        if(LambaZamanlayici == 50){StandartLambaCalistir();LambaZamanlayici = 0;}else{LambaZamanlayici = LambaZamanlayici +1;}
        if (digitalRead(ButonGiris) == HIGH){TanimaModu = 1;digitalWrite(Transistor_Buzzer, HIGH);delay(250);digitalWrite(Transistor_Buzzer, LOW);delay(250);digitalWrite(Transistor_Buzzer, HIGH);delay(250);digitalWrite(Transistor_Buzzer, LOW);TanimlamaButonSira= 0;}
        //---------------------------------
      }else{
        //---------------------------------
        if (mySwitch.available()){RFTanimaKontrolEt();} mySwitch.resetAvailable();
        if(LambaZamanlayici == 100){PasifLambaCalistir();LambaZamanlayici = 0;}else{LambaZamanlayici = LambaZamanlayici +1;
        //---------------------------------
      }
    }
  }
  //---------------------------------
  delay(10);
}
//------------------------------------------------------------------------------------------------------
//------------------------------------------------------------------------------------------------------
























