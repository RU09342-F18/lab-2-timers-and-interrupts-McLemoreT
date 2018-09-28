# Button Interrupt
Last lab you were introduced to the idea of "Polling" where in you would constantly check the status of the P1IN register to see if something has changed. While your code may have worked, it ends up spending a ton of time just checking something that has not changed. What we can do instead is use another two registers available to us from the GPIO peripheral, P1IE and P1IES, to allow our processor to just chill out and wait until something happens to act upon it. Without spending too much space on this README with explanations, what makes these interrupts tick is the following code:

```c
#pragma vector=PORT1_VECTOR
__interrupt void Port_1(void)
{
}
```

While you still need to initialize the Ports to be interrupt enabled and clear the flags, this "Pragma Vector" tells the compiler that when a particular interrupt occurs, run this code. 

## A word of caution...
While you might be willing to just jump straight in and begin using example code you may find, I would seriously take a few minutes and find a few good videos or tutorials to help understand exactly what is happening in the processor. I implore you to do this since you will inevitably have issues in the future which are solved by not understanding how the processor processes interrupts. A prime example is when I once tried implementing UART and I did not realize that you had to clear a flag or else my code would get stuck in an infinite loop. Hours of my life are now gone thanks to me at the time not understanding how interrupts worked with the peripherals I was utilizing. A few resources I have used in the past include:
* https://youtu.be/GR8S2XT47eI?t=1334
* http://processors.wiki.ti.com/index.php/MSP430_LaunchPad_Interrupt_vs_Polling
* http://www.simplyembedded.org/tutorials/msp430-interrupts/

## Task
Your goal for this part of the lab is to replicate your button code from Lab 2, where the LED should change states only when the button is pressed. This can be extended to include behaviors such as only have the LED on when the button is depressed, or have the LED blink one color when pressed and another when it is let go. Another behavior extends from the second lab which is speed control based on the button presses. For example, have the rate of the LED cycle between a "low", "Medium", and "High" rate of speed.

## Extra Work 
### Binary Counter/Shift Register
Either use a function generator, another processor, or a button to control your microcontroller as an 8-bit binary counter using 8 LEDs to indicate the current status of the counter.

### Multiple Buttons
Come up with a behavior of your own that incorporates needing to use two buttons or more and these two buttons must be implemented using interrupts.

### (Recommended) Energy Trace
Using the built in EnergyTrace(R) software in CCS and the corresponding supporting hardware on the MSP430 development platforms, analyze the power consumption between the button based blink code you wrote last week versus this week. What can you do to decrease the amount of power used within the microcontroller in this code? Take a look at the MSP430FR5994 and the built in SuperCap and see how long your previous code and the new code lasts. For a quick intro to EnergyTrace(R), take a look at this video: https://youtu.be/HqeDthLrcsg
