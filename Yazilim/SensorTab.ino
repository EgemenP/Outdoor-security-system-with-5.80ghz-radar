void SensorKontrolEt(){
  

    if (frequency_estimation1(analogRead(A3)) > 10){
      GuvenlikHatasiSure = 500;
      if (GuvenlikHatasi == 0){GuvenlikHatasi = 1;digitalWrite(Role_Siren, HIGH); return;}
    }
    

    if (frequency_estimation2(analogRead(A2)) > 10){
      GuvenlikHatasiSure = 500;
      if (GuvenlikHatasi == 0){GuvenlikHatasi = 1;digitalWrite(Role_Siren, HIGH); return;}
    }
    

    if (frequency_estimation3(analogRead(A1)) > 10){
      GuvenlikHatasiSure = 500;
      if (GuvenlikHatasi == 0){GuvenlikHatasi = 1;digitalWrite(Role_Siren, HIGH); return;}
    }
}

