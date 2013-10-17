GMCWiper
========
an arduino mini pro based controller for the classic GMC motorhome windshield wipers. 
the GMC has a really cool hydraulic, variable speed wiper motor. 
What it doesn't have is intermittentness. 
and when you run the wipers real slow, they shudder and shake and do strange things.
The speed is also controlled by a 35 year old cable and is hard to adjust.
this controller uses a hobby servo to both set the speed and implement intermmittent wipers.
It also causes 2 sweeps of the wipers if the user presses the mist button with the wipers off or in intermmittent mode.

The hardware consists of the following;
1. The stated hoby servo that is connected to the wiper motor valve via a control rod. 
    The servo is used to adjust the wiper speed for both speed and intermittent settings.
2. There is a parked switch that senses when the wipers have returned to the down position. 
    The parked switch allows the controller to know when to start the delay timer. 
      The parked switch is not used in speed mode.
    With out the park switch  it's impossible to know when to start the next sweep as sweep time is dependant on 
    engine speed, windshield wetness etc.
3. An on/off/on switch used to select speed vs wiper mode or off. 
    This allows 1 switch to select 3 different modes using 2 input lines.
4. A linear pot that replaces the speed adjustment lever of the origonal system.
    No requirement to be a linear pot except for apearance.
5. A push button used for the mist button. Pressing this button causes the wipers to make 2 sweeps.
    This button can be triggered off the winshield washer button with a relay etc if desired
6. An arduino microcontroller to ead all the inputs and control the servo. This project uses the 5v 16mhz Pro mini,
    But there is no reason other implementations cannot be used.
