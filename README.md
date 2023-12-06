# Diorama uC Light Control

A controller for the diorama that I plan to work on in what little free time I have. The lighting code here will be loaded onto a micorcontroller and will control the LED lighting that will illuminate the model(s) in the diorama. Currently using the following hardware restrictions:

1. LED
    1. The LEDs are in a strip, and are non-programmable.
    2. The LEDs are bundled in sections containing three, three-color LEDs.
    3. The LEDs share a +5 Volt Vin, have built-in resistors, and are controlled by connecting them to ground.
2. microcontroller
    1. The uC decided on is an ESP8266, as that is what I have lying around, and is also capable of providing a +5V feed for the LEDs
    2. I may change the power to the LEDs from the uC to a voltage converter powered by a 9V battery. Actually, I am going to changethe design to do just that.
    3. There are going to be multiple sets of LEDs around the diorama. This will necessitate having a few different sets of control pins for each area (models, stars, moon, etc).
    4. May need to change the driver to a (de)mux chip or something similar (a shift register would work well in this case).
3. Power Converter
    1. Buck-style DC-DC power converter powered by a COTS 9V battery
    2. Output tunable to +5v, and can handle the current necessary to drive the LEDs and the uC