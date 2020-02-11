//------------------------------------------------------------------------------------------------------
//------------------------------------------------------------------------------------------------------
void SystemBasitZamanlayici(){
  //---------------------------------
  if (PanikAcikmi == 1){
    if (PanikSure == 0){
      if (GuvenlikHatasi == 0){digitalWrite(Role_Siren, LOW);}
      PanikAcikmi = 0;
    }else{
      PanikSure = PanikSure -1;
    }
  }
  //---------------------------------
}
//------------------------------------------------------------------------------------------------------
//------------------------------------------------------------------------------------------------------
static char * dec2binWzerofill(unsigned long Dec, unsigned int bitLength){
  static char bin[64]; 
  unsigned int i=0;
  //---------------------------------
  while (Dec > 0) {
    bin[32+i++] = (Dec & 1 > 0) ? '1' : '0';
    Dec = Dec >> 1;
  }
  //---------------------------------
  for (unsigned int j = 0; j< bitLength; j++) {
    if (j >= bitLength - i) {
      bin[j] = bin[ 31 + i - (j - (bitLength - i)) ];
    }else {
      bin[j] = '0';
    }
  }
  bin[bitLength] = '\0';
  //---------------------------------
  return bin;
}
//------------------------------------------------------------------------------------------------------
//------------------------------------------------------------------------------------------------------
int frequency_estimation1(int sensorValue) {
  int cycles = 0;
  for (int i=0; i<value_length-1; i++) {
    if(signal_floor(Sensorvalues1[i]) != signal_floor(Sensorvalues1[i+1]))
      cycles++;
    Sensorvalues1[i] = Sensorvalues1[i+1];
  }
  Sensorvalues1[value_length-1] = sensorValue;
  return cycles;
}
//------------------------------------------------------------------------------------------------------
//------------------------------------------------------------------------------------------------------
int frequency_estimation2(int sensorValue) {
  int cycles = 0;
  for (int i=0; i<value_length-1; i++) {
    if(signal_floor(Sensorvalues2[i]) != signal_floor(Sensorvalues2[i+1]))
      cycles++;
    Sensorvalues2[i] = Sensorvalues2[i+1];
  }
  Sensorvalues2[value_length-1] = sensorValue;
  return cycles;
}
//------------------------------------------------------------------------------------------------------
//------------------------------------------------------------------------------------------------------
int frequency_estimation3(int sensorValue) {
  int cycles = 0;
  for (int i=0; i<value_length-1; i++) {
    if(signal_floor(Sensorvalues3[i]) != signal_floor(Sensorvalues3[i+1]))
      cycles++;
    Sensorvalues3[i] = Sensorvalues3[i+1];
  }
  Sensorvalues3[value_length-1] = sensorValue;
  return cycles;
}
//------------------------------------------------------------------------------------------------------
//------------------------------------------------------------------------------------------------------
int frequency_estimation4(int sensorValue) {
  int cycles = 0;
  for (int i=0; i<value_length-1; i++) {
    if(signal_floor(Sensorvalues4[i]) != signal_floor(Sensorvalues4[i+1]))
      cycles++;
    Sensorvalues4[i] = Sensorvalues4[i+1];
  }
  Sensorvalues4[value_length-1] = sensorValue;
  return cycles;
}
//------------------------------------------------------------------------------------------------------
//------------------------------------------------------------------------------------------------------
boolean signal_floor(int sensorValue) {
  return sensorValue > 600;
}
//------------------------------------------------------------------------------------------------------
//------------------------------------------------------------------------------------------------------

