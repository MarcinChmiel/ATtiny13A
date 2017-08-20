//Example shows how to use EEPROM to remember value after power off.

#include <avr/io.h>
#include <avr/eeprom.h>									//EEPROM library
#define F_CPU 1000000UL
#include <util/delay.h>
#define BUTTON (1<<PB3)
#define LED (1<<PB4)

uint8_t EEMEM led_state_eeprom;								//variable in EEPROM

int main()
{
	uint8_t led_state = eeprom_read_byte(&led_state_eeprom);			//Read value of led_state_eeprom variable
	DDRB |= LED;									//PB4 output
	uint8_t last_button_state = 0;
	while(1)
	{
		uint8_t button_state = PINB & BUTTON					//Check button's state
		if(button_state != last_button_state)
		{
			_delay_ms(20);							//Deboucing
			if(button_state == BUTTON)					//It's pressed
			{
				led_state ^= 1;						//Change LSB of led_state variable
				eeprom_update_byte(&led_state_eeprom, led_state);	//Update led_stan_eeprom
			}

		}
		last_button_state = button_state;
	switch(led_state & 1)								//Depends on LSB value
	{
		case 0:	PORTB &= ~LED;							//Turn off LED
			break;
		case 1: PORTB |= LED;							//Turn on LED
			break;
	}
	}
}
