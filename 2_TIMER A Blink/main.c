
#include <msp430.h>

#define LED_0 BIT0
#define LED_1 BIT6
#define LED_OUT P1OUT
#define LED_DIR P1DIR

void initializeTimer(int capture);

unsigned int timerCount = 0;
void main(void)
{
    WDTCTL = WDTPW + WDTHOLD; // Stop watchdog timer
    LED_DIR |= (LED_0 + LED_1); // Set P1.0 and P1.6 to output direction
    LED_OUT &= ~(LED_0 + LED_1); // Set the LEDs off

    initializeTimer(20); // Initialize timer at 10Hz or 0.1s

    __enable_interrupt();

    __bis_SR_register(LPM0 + GIE); // LPM0 with interrupts enabled
}

void initializeTimer(int hertz) // Seconds = 1/Hertz, 10Hz = 0.1s
{
    CCTL0 = CCIE;
    TACTL = TASSEL_2 + MC_1 + ID_3; // SMCLK/8, UPMODE
    // CLK/HERTZ = CAPTURE
    // CLK = 1MHZ/8 = 125kHz
    int capture = (125000)/hertz;
    TACCR0 = capture; // (1000000/8)/(12500) = 10 Hz = 0.1 seconds
}

// Timer A0 interrupt service routine
#pragma vector=TIMER0_A0_VECTOR
__interrupt void Timer0_A0 (void)
{
    if(timerCount >= 100) // 0.1 seconds 100 times, called every 10s
    {
        P1OUT ^= (LED_0 + LED_1); // Switch on the LEDs
        timerCount = 0; // Reset the counter variable
    }
    else timerCount++; // Increment the counter variable until 10s
}
