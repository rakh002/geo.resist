bool bin[16][4]={
  {0,0,0,0},
  {1,0,0,0},
  {0,1,0,0},
  {1,1,0,0},
  {0,0,1,0},
  {1,0,1,0},
  {0,1,1,0},
  {1,1,1,0},
  {0,0,0,1},
  {1,0,0,1},
  {0,1,0,1},
  {1,1,0,1},
  {0,0,1,1},
  {1,0,1,1},
  {0,1,1,1},
  {1,1,1,1}
  };
  
byte PinMux[4][4]={
  {22,24,26,28},
  {23,25,27,29},
  {30,32,34,36},
  {31,33,35,37}
  };

byte i=0;
  
void MUX(byte mux, byte channel){
  for(int i=0; i<4; i++){
    digitalWrite(PinMux[mux][i],bin[channel][i]);
    Serial.print(PinMux[mux][i]);
    Serial.print("=>");
    Serial.print(bin[channel][i]);
    Serial.print(", ");
    }
    Serial.println();
  }

void setup() {
  // Serial port initialization.
  Serial.begin(9600);
  // Pin Mux initialization
  for(int i=0; i<4; i++) {
    for(int j=0; j<4; j++){
      pinMode(PinMux[i][j], OUTPUT);
    }
  }
}

void loop() {
  // I injection (A)
  MUX(0,i);
  // I read (B)
  MUX(3,i+3);
  // V- (M)
  MUX(1,i+1);
  // V+ (N)
  MUX(2,i+2);

  // Measurement 1
  delay(1000);
  
  // Switch AB
  // I injection (A)
  MUX(0,i+3);
  // I read (B)
  MUX(3,i);

  // Measurement 2
  delay(1000);

  i++;
  if(i==13){i=0;}
}
