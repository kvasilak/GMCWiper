//CWipers.h

#ifndef THE_WIPERS_H
#define THE_WIPERS_H

#include <inttypes.h>
#include <Servo.h>
#include "Debounced.h"

class GMCWipers
{
public:
GMCWipers();

void Init();
void Update();

private:

bool IsTimedOut(unsigned long period, unsigned long start);
void WiperSpeed(int val);
void WipersIntermitent(int val);

#ifdef MISTENABLED
void WipersMisting();
#endif
void WipersDo();

enum IStates_e {iSTATE_PARK, iSTATE_PARK_WAIT, iSTATE_DELAY, iSTATE_UNPARK, iSTATE_UNPARK_WAIT};

enum MStates_e {mSTATE_SET, mSTATE_UNPARK, mSTATE_COUNT, mSTATE_WAIT, mSTATE_PARK};

Servo myservo;  // create servo object to control a servo

int val;    // variable to read the value from the analog pin
int oldval;
unsigned long StartTime;

//i/o
int potpin;  // analog pin used to connect the potentiometer
int parkPin;
int SpeedmodePin;
int DelaymodePin;
int servoPin;

#ifdef MISTENABLED
int mistPin;
#endif

//Servo positions
int DEADBAND;	//any pot value below this is considered off
int SPEED_OFF;
int UNPARK; //move just far enough to start the wipers
int SPEED_MEDIUM; //not too fast
int SPEED_HIGH; //as fast as you wanna go

#ifdef MISTENABLED
int MISTSWEEPS; //three sweeps when you squirt the windshield washer
bool misting;
#endif

//debounced pins
Debounced WiperSpeedMode;
Debounced WiperDelayMode;

#ifdef MISTENABLED
Debounced WipersMist;
#endif
Debounced WipersParked;
};

#endif
