#include <avr/io.h>
#include <util/delay.h>
#include "EEPROM_Interface.h"
#include "SPI_INTERFACE.h"

void EEPROM_voidSendData(uint16_t copy_u16Address, uint8_t copy_u8Data)
{
	PORTB |= (1<<4);
	PORTB &= ~(1<<4);
	MSPI_voidSendData(0x06);
	PORTB |= (1<<4);
	_delay_ms(5);
	PORTB &= ~(1<<4);
	MSPI_voidSendData(0x02);
	MSPI_voidSendData(copy_u16Address);
	MSPI_voidSendData(copy_u8Data);
	PORTB |= (1<<4);
	_delay_ms(5);
}

void EEPROM_voidSend16Byte(uint16_t copy_u16Address, uint8_t *copy_u8Data)
{
	PORTB |= (1<<4);
	PORTB &= ~(1<<4);
	MSPI_voidSendData(0x06);
	PORTB |= (1<<4);
	_delay_ms(5);
	PORTB &= ~(1<<4);
	MSPI_voidSendData(0x02);
	MSPI_voidSendData(copy_u16Address);
	for(uint8_t i=0; i<=9; i++)
		MSPI_voidSendData(copy_u8Data[i]);
	PORTB |= (1<<4);
	_delay_ms(5);
}

uint8_t EEPROM_u8ReadData(uint16_t copy_u16Address)
{
	uint8_t Local_u8Dummy = 0xFF;
	uint8_t Local_u8Data;
	PORTB |= (1<<4);
	PORTB &= ~(1<<4);
	MSPI_voidSendData(0x03);
	MSPI_voidSendData(copy_u16Address);
	MSPI_voidSendData(Local_u8Dummy);
	Local_u8Data = MSPI_voidRecieveData();
	PORTB |= (1<<4);
	return Local_u8Data;
}