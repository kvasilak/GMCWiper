/*
  Debouncer.c- Debounced Digital inputs
  Copyright (c) 2013 Keith Vasilakes.  All right reserved.
 
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

#include "Debounced.h"

//return true if it's been period ms since start
static bool IsTimedOut(unsigned long period, unsigned long start)
{
  unsigned long current = millis();
  return((current - start) > period);
}

Debounced::Debounced() :
PinLevel(0),
PinNumber(-1),
DebounceStart(0),
State(CHECKING)
{
}

//connect and read the initial values
void Debounced::attach(int pin, bool pullup)
{
    if(pullup)
    {
        pinMode(pin, INPUT_PULLUP);
    }
    else
    {
        pinMode(pin, INPUT);
    }

	PinNumber = pin;
	PinLevel = digitalRead(pin);
}

//update the current pin level
//call in the loop before using any IO
void Debounced::Update()
{
	int newlevel;
	
	if(PinNumber <0)
	{
		return; //assign me a pin Dude!
	}

	switch(State)
	{
	case CHECKING:
		newlevel = digitalRead(PinNumber);

		if(newlevel != PinLevel)
		{
			DebounceStart = millis();
			State = BOUNCING;
		}
		break;

	case BOUNCING:
		if(IsTimedOut(10, DebounceStart) )
		{
			//check again
			newlevel = digitalRead(PinNumber);

			//still different, update it
			if(newlevel != PinLevel)
			{
				PinLevel = newlevel;

				State = CHECKING;
			}
		}
	}
}