void LambaCalistir(){
              //---------------------------------
              digitalWrite(OncekiLedSira, LOW);
              digitalWrite(LambaSira, HIGH);
              //---------------------------------
              if (LambaSira == 13){
                  LambaSira = 10;
                  OncekiLedSira = 13;
              }else{
                  OncekiLedSira = LambaSira;
                  LambaSira = LambaSira + 1;
              }
              //---------------------------------
}
//------------------------------------------------------------------------------------------------------
//------------------------------------------------------------------------------------------------------
void PasifLambaCalistir(){
    digitalWrite(Transistor_Lamba1, HIGH);digitalWrite(Transistor_Lamba2, HIGH);digitalWrite(Transistor_Lamba3, HIGH);digitalWrite(Transistor_Lamba4, HIGH);delay(300);
    digitalWrite(Transistor_Lamba1, LOW);digitalWrite(Transistor_Lamba2, LOW);digitalWrite(Transistor_Lamba3, LOW);digitalWrite(Transistor_Lamba4, LOW);delay(150);
    digitalWrite(Transistor_Lamba1, HIGH);digitalWrite(Transistor_Lamba2, HIGH);digitalWrite(Transistor_Lamba3, HIGH);digitalWrite(Transistor_Lamba4, HIGH);delay(300);
    digitalWrite(Transistor_Lamba1, LOW);digitalWrite(Transistor_Lamba2, LOW);digitalWrite(Transistor_Lamba3, LOW);digitalWrite(Transistor_Lamba4, LOW);
}
//------------------------------------------------------------------------------------------------------
//------------------------------------------------------------------------------------------------------
void StandartLambaCalistir(){
    if (StandartLedDurum == 0){
        digitalWrite(Transistor_Lamba1, HIGH);digitalWrite(Transistor_Lamba2, HIGH);
        digitalWrite(Transistor_Lamba3, LOW);digitalWrite(Transistor_Lamba4, LOW);
        StandartLedDurum = 1;
    }else{
        digitalWrite(Transistor_Lamba1, LOW);digitalWrite(Transistor_Lamba2, LOW);
        digitalWrite(Transistor_Lamba3, HIGH);digitalWrite(Transistor_Lamba4, HIGH);
        StandartLedDurum = 0;
    }
}
//------------------------------------------------------------------------------------------------------
//------------------------------------------------------------------------------------------------------
void FlasorLambaCalistir(){
    if (FlasorLambaDurum == 0){
        digitalWrite(Role_Lamba, HIGH);
        FlasorLambaDurum = 1;
    }else{
        digitalWrite(Role_Lamba, LOW);
        FlasorLambaDurum = 0;
    }
}
//------------------------------------------------------------------------------------------------------
//------------------------------------------------------------------------------------------------------
