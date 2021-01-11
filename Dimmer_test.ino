
int triac_pin = 3;  // Digital output to TRIAC
int dimm_time = 8000;  // 8000 = 20% output power
bool zero_cross = 0;
void setup(void) {
  Serial.begin(9600);
  Serial.println("Power on...");
  pinMode(triac_pin, OUTPUT);
  digitalWrite(triac_pin, HIGH);
  delay(2000);
  digitalWrite(triac_pin, LOW);
  Serial.println("Power off...");
  delay(2000);
  Serial.println("Start dimming...");
  attachInterrupt(0, zero_cross_detect, CHANGE);
}

void loop() {

  int i;
  for (i = 39.06255; i <= 10000; i += 39.06255)
  {
    Serial.println(i);
    if (zero_cross) {
    if (true) {
      delayMicroseconds(i);
      digitalWrite(triac_pin, HIGH);
      delayMicroseconds(200);
      digitalWrite(triac_pin, LOW);
      //Serial.print("BEGINNING OF THE LOOP");
      
    }
    zero_cross = 0;
    
  }

  delayMicroseconds(10200000000);
    
  }
  return 0;

  delay(10000);
 
  
/*
  if (dimm_time > 8800) {
    dimm_time = 9500;
  }
  if (dimm_time < 1000) {
    dimm_time = 1000;
  }

 */

  if (Serial.available() > 1) {
    int getval = 10000 - (Serial.parseInt() * 100);
    if (getval >= 0 && getval <= 10000) {
      dimm_time = getval;
      Serial.print("Dimm to ");
      Serial.print(100 - (getval / 100));
      Serial.println(" %");
    } else {
      Serial.println("Wrong value!");
    }
    //Serial.print("END OF LOOP -> repeat");
  }
  
}

void zero_cross_detect() {  // If zero crossing is detected
  zero_cross = 1;
}
