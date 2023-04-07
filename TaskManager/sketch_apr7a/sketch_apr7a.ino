#include <TaskManagerIO.h>;

const int pins[] = { 3, 5, 6, 9, 10, 11 };

const int PINS_COUNT = 6;

const unsigned long INTERVAL = 1000000;

unsigned long* PINS_INTERVALS = new unsigned long[PINS_COUNT];
int* STATES = new int[PINS_COUNT]; 

void setup() {
  for (int i = 0; i < PINS_COUNT; i++)
  {
    STATES[i] = LOW;
    pinMode(pins[i], OUTPUT);
  }
  PINS_INTERVALS[0] = INTERVAL * 0.1;
  PINS_INTERVALS[1] = INTERVAL * 0.2;  
  PINS_INTERVALS[2] = INTERVAL * 0.16;  
  PINS_INTERVALS[3] = INTERVAL * 0.04;  
  PINS_INTERVALS[4] = INTERVAL * 0.8;    
  PINS_INTERVALS[5] = INTERVAL * 0.32; 

  taskid_t task0 = taskManager.scheduleFixedRate(PINS_INTERVALS[0], [] {
		if (STATES[0] == LOW)
      {
        STATES[0] =  HIGH;
      }
      else 
      {
        STATES[0] = LOW;
      }
      digitalWrite(pins[0], STATES[0]);
	}, TIME_MICROS);

  taskid_t task1 = taskManager.scheduleFixedRate(PINS_INTERVALS[1], [] {
		if (STATES[1] == LOW)
      {
        STATES[1] =  HIGH;
      }
      else 
      {
        STATES[1] = LOW;
      }
      digitalWrite(pins[1], STATES[1]);
	}, TIME_MICROS);
  
  taskid_t task2 = taskManager.scheduleFixedRate(PINS_INTERVALS[2], [] {
    if (STATES[2] == LOW)
      {
        STATES[2] =  HIGH;
      }
      else 
      {
        STATES[2] = LOW;
      }
      digitalWrite(pins[2], STATES[2]);
  }, TIME_MICROS);

  taskid_t task3 = taskManager.scheduleFixedRate(PINS_INTERVALS[3], [] {
    if (STATES[3] == LOW)
      {
        STATES[3] =  HIGH;
      }
      else 
      {
        STATES[3] = LOW;
      }
      digitalWrite(pins[3], STATES[3]);
  }, TIME_MICROS);

  taskid_t task4 = taskManager.scheduleFixedRate(PINS_INTERVALS[4], [] {
    if (STATES[4] == LOW)
      {
        STATES[4] =  HIGH;
      }
      else 
      {
        STATES[4] = LOW;
      }
      digitalWrite(pins[4], STATES[4]);
  }, TIME_MICROS);

  taskid_t task5 = taskManager.scheduleFixedRate(PINS_INTERVALS[5], [] {
    if (STATES[5] == LOW)
      {
        STATES[5] =  HIGH;
      }
      else 
      {
        STATES[5] = LOW;
      }
      digitalWrite(pins[5], STATES[5]);
  }, TIME_MICROS);
}

void loop() {
  taskManager.runLoop();
}
