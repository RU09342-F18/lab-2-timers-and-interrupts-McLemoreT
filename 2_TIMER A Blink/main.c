/*
 * Credit to github user: andreic987456
 * Code inspiration and examples were used to aid in the development of this program.
 */
#include <msp430.h>


#define LED BIT0                   //Define "LED0" as bit 0.
#define PnB (P1IN & Btn)        //Define "INP" for checking if there is an input on pin 1.3.

typedef int bool;
#define true 1
#define false 0
//bool i = 0;
void TimerSetup (int rate);
int main(void)
{

    WDTCTL = WDTPW | WDTHOLD;   // stop watchdog timer
    P1DIR |= LED;               //Set Port 1.0 as an output
    P1OUT &= ~LED;              //Set the initial value of port 1.0 as "0"



    TimerSetup(10);
    __enable_interrupt();
    __bis_SR_register(LPM4_bits + GIE);
}
void TimerSetup(int rate){
    CCTL0 = CCIE;
    TA0CCTL0 = CCIE; // Enable interrupt in compare mode
    TA0CTL = TASSEL_2 + MC_1 + ID_2; // SMCLK/4, Up
    TA0CCR0 = 250000 / rate; // 250000 / 10 = 25000, (10^6 [Hz] / 4) / (25000) = 10Hz
}
//#pragma vector=PORT1_VECTOR
//__interrupt void Port_1(void)
#pragma vector=TIMER0_A0_VECTOR
__interrupt void Timer_A0 (void)
{


    P1OUT ^= BIT0;                            // P1.0 = toggle
    //P1IFG &= ~BIT3; // P1.3 IFG cleared

}
