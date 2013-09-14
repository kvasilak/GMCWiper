// GMC motorhome Wiper motor controller
// This code runs a RC servo to control the Hydralic wipers on a GMC motorhome
//these wipers are variable speed, normally controlled via a cable
// the servo replaces the cable to provide both variable speed and
// intermittent operation.
//
// There are 3 inputs to the system;
// On/Off switch
// intermmitent enable switch
// Wipers parked switch
// delay potometer
//
// Copyright 2013 Keith Vasilakes
/*
 This library is free software; you can redistribute it and/or
 modify it under the terms of the GNU Lesser General Public
 License as published by the Free Software Foundation; either
 version 2.1 of the License, or (at your option) any later version.

 This library is distributed in the hope that it will be useful,
 but WITHOUT ANY WARRANTY; without even the implied warranty of
 MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
 Lesser General Public License for more details.

 You should have received a copy of the GNU Lesser General Public
 License along with this library; if not, write to the Free Software
 Foundation, Inc., 51 Franklin St, Fifth Floor, Boston, MA  02110-1301  USA
 */

#include <Arduino.h> 
#include <Servo.h>	
#include <Debounced.h>
#include <GMCWipers.h>


GMCWipers theWipers;

//return true if it's been period ms since start
bool IsTimedOut(unsigned long period, unsigned long start)
{
  unsigned long current = millis();
  return((current - start) > period);
}

void setup()
{
  Serial.begin(9600);

  Serial.println("*******GMC wipermotor controller V1.0*********");
  
  theWipers.Init();
}


void loop()
{
  theWipers.Update();
}
