const int pins[] = { 3, 5, 6, 9, 10, 11 };

const int PINS_COUNT = 6;

const unsigned long INTERVAL = 1000000;

unsigned long* PINS_INTERVALS = new unsigned long[PINS_COUNT];
unsigned long* PINS_LAST_ACTIVATE = new unsigned long[PINS_COUNT];
int* STATES = new int[PINS_COUNT]; 

void setup() {
  for (int i = 0; i < PINS_COUNT; i++)
  {
    PINS_LAST_ACTIVATE[i] = 0;
    STATES[i] = LOW;
    pinMode(pins[i], OUTPUT);
  }
  PINS_INTERVALS[0] = INTERVAL * 0.1;
  PINS_INTERVALS[1] = INTERVAL * 0.2;  
  PINS_INTERVALS[2] = INTERVAL * 0.16;  
  PINS_INTERVALS[3] = INTERVAL * 0.04;  
  PINS_INTERVALS[4] = INTERVAL * 0.8;    
  PINS_INTERVALS[5] = INTERVAL * 0.32;  
}

void loop() {
  unsigned long currentMicrosTime = micros();

  for (int i = 0; i < PINS_COUNT; i++)
  {
    if(currentMicrosTime - PINS_LAST_ACTIVATE[i] >= PINS_INTERVALS[i])
    {
      PINS_LAST_ACTIVATE[i] = currentMicrosTime;
      if (STATES[i] == LOW)
      {
        STATES[i] =  HIGH;
      }
      else 
      {
        STATES[i] = LOW;
      }
      digitalWrite(pins[i], STATES[i]);
    }
  }
}
