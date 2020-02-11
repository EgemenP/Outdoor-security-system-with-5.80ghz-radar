//------------------------------------------------------------------------------------------------------
//------------------------------------------------------------------------------------------------------
void RFKontrolEtKoruma(){
  //------------------------------------------------------------------------------------------------------
  if (String(dec2binWzerofill(mySwitch.getReceivedValue(), 24)) == String(Button1GetData))
  {
    SystemKorumaDurdur();
    return;
  }
  //------------------------------------------------------------------------------------------------------
  if (String(dec2binWzerofill(mySwitch.getReceivedValue(), 24)) == String(Button2GetData))
  {
    SystemPanik();
    return;  
  }
  //------------------------------------------------------------------------------------------------------
  if (String(dec2binWzerofill(mySwitch.getReceivedValue(), 24)) == String(Button3GetData))
  {
    if (GuvenlikHatasi == 0){
        if (LambaDurumu == 0){
          SystemLambaAc();
        }else{
          SystemLambaKapat();
        }
        delay(500);
    }
    return;  
  }
  //------------------------------------------------------------------------------------------------------
  if (String(dec2binWzerofill(mySwitch.getReceivedValue(), 24)) == String(Button4GetData))
  {
    if (GuvenlikHatasi == 0){SystemSessizKorumaBaslat2();}
    return;
  }
  //------------------------------------------------------------------------------------------------------
}
//------------------------------------------------------------------------------------------------------
//------------------------------------------------------------------------------------------------------
void RFKontrolEtStandart(){
  //------------------------------------------------------------------------------------------------------
  if (String(dec2binWzerofill(mySwitch.getReceivedValue(), 24)) == String(Button1GetData))
  {
    SystemKorumaBaslat();
    delay(500);
    return;
  }
  //------------------------------------------------------------------------------------------------------
  if (String(dec2binWzerofill(mySwitch.getReceivedValue(), 24)) == String(Button2GetData))
  {
    SystemPanik();
    return;
  }
  //------------------------------------------------------------------------------------------------------
  if (String(dec2binWzerofill(mySwitch.getReceivedValue(), 24)) == String(Button3GetData))
  {
    if (LambaDurumu == 0){
      SystemLambaAc();
    }else{
      SystemLambaKapat();
    }
    delay(500);
    return;  
  }
  //------------------------------------------------------------------------------------------------------
  if (String(dec2binWzerofill(mySwitch.getReceivedValue(), 24)) == String(Button4GetData))
  {
    if (GuvenlikHatasi == 0){SystemSessizKorumaBaslat();}
    return;
  }
  //------------------------------------------------------------------------------------------------------
}
//------------------------------------------------------------------------------------------------------
//------------------------------------------------------------------------------------------------------
void RFTanimaKontrolEt(){
  //---------------------------------
  if (TanimlamaButonSira == 0){  
    strcpy(buf, dec2binWzerofill(mySwitch.getReceivedValue(),24));
    eeprom_write_string(10, buf);
    digitalWrite(Transistor_Buzzer, HIGH);delay(250);digitalWrite(Transistor_Buzzer, LOW);
    TanimlamaButonSira = 1;
    return;
  }
  //---------------------------------
  if (TanimlamaButonSira == 1){
    strcpy(buf, dec2binWzerofill(mySwitch.getReceivedValue(),24));
    eeprom_write_string(40, buf);
    digitalWrite(Transistor_Buzzer, HIGH);delay(250);digitalWrite(Transistor_Buzzer, LOW);
    TanimlamaButonSira = 2;
    return;
  }
  //---------------------------------
  if (TanimlamaButonSira == 2){
    strcpy(buf, dec2binWzerofill(mySwitch.getReceivedValue(),24));
    eeprom_write_string(70, buf);
    digitalWrite(Transistor_Buzzer, HIGH);delay(250);digitalWrite(Transistor_Buzzer, LOW);
    TanimlamaButonSira = 3;
    return;
  }
  //---------------------------------
  if (TanimlamaButonSira == 3){
    strcpy(buf, dec2binWzerofill(mySwitch.getReceivedValue(),24));
    eeprom_write_string(100, buf);
    TanimaModu = 0;
    delay(100);
    eeprom_read_string(10, Button1GetData, BUFSIZE);
    eeprom_read_string(40, Button2GetData, BUFSIZE);
    eeprom_read_string(70, Button3GetData, BUFSIZE);
    eeprom_read_string(100, Button4GetData, BUFSIZE);
    digitalWrite(Transistor_Buzzer, HIGH);delay(250);digitalWrite(Transistor_Buzzer, LOW);delay(250);digitalWrite(Transistor_Buzzer, HIGH);delay(250);digitalWrite(Transistor_Buzzer, LOW);
    return;
  }
  //---------------------------------
}
//------------------------------------------------------------------------------------------------------
//------------------------------------------------------------------------------------------------------




