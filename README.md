GMCWiper
========
A windshield wiper upgrade for the classic GMC motorhome. <br>
The GMC has a really cool hydraulic, variable speed wiper motor. <br>
What it doesn't have is intermittentness. <br>
and when you run the wipers real slow, they shudder and shake and do strange things.<br>
The speed is controlled by a 35 year old cable and is hard to adjust.<br>
<br>
This controller uses a hobby servo to both set the speed and implement intermittent wipers.<br>
It also causes 2 sweeps of the wipers if the user presses the mist button with the wipers off or in intermmittent mode.<br>
<br>
The hardware consists of the following;<br>
1. The stated hobby servo that is connected to the wiper motor valve via a control rod. <br>
    The servo is used to adjust the wiper speed for both speed and intermittent settings.<br>
2. There is a parked switch that senses when the wipers have returned to the down position. <br>
    The parked switch allows the controller to know when to start the delay timer. <br>
      The parked switch is not used in speed mode.<br>
    With out the park switch  it's impossible to know when to start the next sweep as sweep time is dependant on <br>
    engine speed, windshield wetness etc.<br>
3. An on/off/on switch used to select speed vs wiper mode or off. <br>
    This allows 1 switch to select 3 different modes using 2 input lines.<br>
4. A linear pot that replaces the speed adjustment lever of the original system.<br>
    No requirement to be a linear pot except for appearance.<br>
5. A push button used for the mist button. Pressing this button causes the wipers to make 2 sweeps.<br>
    This button can be triggered off the windshield washer button with a relay etc if desired<br>
6. An arduino microcontroller to read all the inputs and control the servo. This project uses the 5v 16mhz Pro mini,<br>
    But there is no reason other implementations cannot be used.<br>
7. A power supply with enough power to run the Arduino and the servo motor.<br>
    I used a $2 ebay adjustable power supply with a 35 volt input rating. I set it to 6 volts to run the servo and use the internal mini pro regulator for the processor  
<br>
