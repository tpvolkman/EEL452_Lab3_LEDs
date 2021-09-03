/**
 * Main program.
 */

#include "main.h"

bool isPinSet( uint32_t pin )
{
    if (( GPIOB->IDR & ( 0x01 << pin )) == ( 0x01 << pin ))
    {
        return TRUE;
    }
    else
    {
        return FALSE;
    }
}

void pinSet( uint32_t pin )
{
    GPIOB->ODR |= ( 1 << pin );
}

void pinReset( uint32_t pin )
{
    GPIOB->ODR &= ~( 1 << pin );
}

int main(void) 
{
    uint32_t    delay;
    
  	// Enable the GPIOB peripheral in 'RCC_AHBENR'.
  	RCC->AHB2ENR   |= RCC_AHB2ENR_GPIOBEN;
  
  	// Initialize the GPIOB pins.
  
  	// B3 is connected to an LED on the 'Nucleo' board.
  	//    It should be set to push-pull low-speed output.
    GPIOB->MODER &= 0xFFFFFF3F;
    GPIOB->MODER |= 0x00000040;
    GPIOB->OTYPER &= 0xFFFFFFF7;
    GPIOB->PUPDR &= 0xFFFFFF3F;
    GPIOB->OSPEEDR &= 0xFFFFFF3F;
   
  	while (1) 
	{
        delay = 300000;
        
        while ( delay-- );
        
        if ( isPinSet( LED_ONBOARD_PIN ) == TRUE )
        {
            pinReset( LED_ONBOARD_PIN );
        }
        else
        {
            pinSet( LED_ONBOARD_PIN );
        }
  	}
}