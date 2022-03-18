#include <asf.h>
#include <avr/io.h>
#define F_CPU 1000000ul
#include <util/delay.h>
#include "EEPROM_Interface.h"
#include "SPI_INTERFACE.h"

int main (void)
{
	uint8_t Local_u8represent;
	DDRC = 0xFF;
	SPI_MasterInit();
	_delay_ms(5);
	Local_u8represent = EEPROM_u8ReadData(0x00);
	if(Local_u8represent==0xFF)
	{
		uint8_t arr[10] = {0x3F, 0x06, 0x5B, 0x4F, 0x66, 0x6D, 0x7D, 0x07, 0x6F};
		EEPROM_voidSend16Byte(0x00, arr);
	}

	while(1)
	{
		for(uint8_t i=0; i<10; i++)
		{
			Local_u8represent = EEPROM_u8ReadData(0x00+i);
			PORTC = Local_u8represent;
			_delay_ms(1000);
		}
	}
	return 0;
}