
#include <CD74HC4067.h>

               // s0 s1 s2 s3
CD74HC4067 my_mux(22, 24, 26, 28);  // c,24,26reate a new CD74HC4067 object with its four control pins


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
//  pinMode(g_common_pin, OUTPUT); // set the initial mode of the common pin.
  // Pin Mux initialization
  for(int i=0; i<4; i++) {
    for(int j=0; j<4; j++){
      pinMode(PinMux[i][j], OUTPUT);
    }
  }
}

void loop() {
  // I injection (A)
  my_mux.channel(i);
  Serial.print("channel: ");
  Serial.println(i+1);
  
  // Measurement 1
  delay(1000);
  
  // Switch AB
  my_mux.channel(i+3);
  Serial.print("channel: ");
  Serial.println(i+4);
  
  // Measurement 2
  delay(1000);

  i++;
  if(i==13){i=0;}
}
