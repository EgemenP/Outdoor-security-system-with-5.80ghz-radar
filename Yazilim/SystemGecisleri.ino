//---------------------------------
void SystemKorumaBaslat(){
  SystemTumLEDKapat();
  LambaZamanlayici = 0;
  EEPROM.write(0, 1);
  SensorBasladi = 250;
  KorumaModuDurum = 1;
  digitalWrite(Role_Siren, HIGH);delay(250);digitalWrite(Role_Siren, LOW);
}
//---------------------------------
void SystemSessizKorumaBaslat(){
  SystemTumLEDKapat();
  LambaZamanlayici = 0;
  EEPROM.write(0, 1);
  SensorBasladi = 250;
  KorumaModuDurum = 1;
  digitalWrite(Transistor_Buzzer, HIGH);delay(350);digitalWrite(Transistor_Buzzer, LOW);delay(200);digitalWrite(Transistor_Buzzer, HIGH);delay(350);digitalWrite(Transistor_Buzzer, LOW);
}
//---------------------------------
void SystemSessizKorumaBaslat2(){
  digitalWrite(Transistor_Buzzer, HIGH);delay(350);digitalWrite(Transistor_Buzzer, LOW);delay(200);digitalWrite(Transistor_Buzzer, HIGH);delay(350);digitalWrite(Transistor_Buzzer, LOW);delay(200);digitalWrite(Transistor_Buzzer, HIGH);delay(350);digitalWrite(Transistor_Buzzer, LOW);
}
//---------------------------------
void SystemKorumaDurdur(){
  SystemTumLEDKapat();
  SystemAlarmDurdur();
  EEPROM.write(0, 0);
  KorumaModuDurum = 0;
}
//---------------------------------
void SystemAlarmBaslat(){
  GuvenlikHatasi = 1;
  digitalWrite(Role_Siren, HIGH);
}
//---------------------------------
void SystemAlarmDurdur(){
  GuvenlikHatasi = 0;
  
  int Degisken = 0;
  while(Degisken < 100){
    frequency_estimation1(500);
    Degisken++;
  }
          if (LambaDurumu == 1){digitalWrite(Role_Lamba, HIGH);}else{digitalWrite(Role_Lamba, LOW);}
          FlasorLambaZamanlayici = 0;
          FlasorLambaDurum = 0;
  
  if (PanikAcikmi == 0){digitalWrite(Role_Siren, LOW);}
  digitalWrite(Transistor_Buzzer, HIGH);delay(1000);digitalWrite(Transistor_Buzzer, LOW);
}
//---------------------------------
void SystemLambaAc(){
  LambaDurumu = 1;
  EEPROM.write(1, 1);
  digitalWrite(Role_Lamba, HIGH);
}
//---------------------------------
void SystemLambaKapat(){
  LambaDurumu = 0;
  EEPROM.write(1, 0);
  digitalWrite(Role_Lamba, LOW);
}
//---------------------------------
void SystemTumLEDKapat(){
  LambaSira = 10;
  StandartLedDurum = 0;
  digitalWrite(Transistor_Lamba1, LOW);digitalWrite(Transistor_Lamba2, LOW);digitalWrite(Transistor_Lamba3, LOW);digitalWrite(Transistor_Lamba4, LOW);delay(100);
}
//---------------------------------
void SystemPanik(){
  PanikAcikmi = 1;
  PanikSure = 50;
  digitalWrite(Role_Siren, HIGH);
}
//---------------------------------


