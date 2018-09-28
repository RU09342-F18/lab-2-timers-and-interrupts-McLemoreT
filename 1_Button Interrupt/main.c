#include <msp430.h> 

#define Btn BIT3                 //Define "Btn" as bit 3.
#define LED BIT0                   //Define "LED0" as bit 0.
#define PnB (P1IN & Btn)        //Define "INP" for checking if there is an input on pin 1.3.

typedef int bool;
#define true 1
#define false 0

int main(void)
{
    bool i = 0;
	WDTCTL = WDTPW | WDTHOLD;	// stop watchdog timer
    P1DIR |= LED;               //Set Port 1.0 as an output
    P1OUT &= ~LED;              //Set the initial value of port 1.0 as "0"

    P1DIR &= ~Btn;              //Set Port 1.3 as an input
    P1REN |= Btn;               //Turn on the pull-up resistor for port 1.3
    P1OUT |= Btn;               //Set the initial value of port 1.3 as "1"

    P1IE |=  BIT3;                            // P1.3 interrupt enabled
    P1IES |= BIT3;                            //falling edge
    P1REN |= BIT3;                            // Enable resistor on SW2 (P1.3)
    P1OUT |= BIT3;                             //Pull up resistor on P1.3
    P1IFG &= ~BIT3; // P1.3 Interrupt Flag cleared
	return 0;
}

#pragma vector=PORT1_VECTOR
__interrupt void Port_1(void)

{
    if(!PnB && !i){         //If the button is pushed and the boolean is false
                        P1OUT ^= LED;   //Flip the value of the LED
                        i = 1;          //Flip the Value of the Boolean
            }
            else if(PnB && i){          //If the button is pushed and the boolean is true
                       i = 0;           //Set the Boolean to be true
           }


}
