#include "SPI_INTERFACE.h"

void SPI_MasterInit()
{
	DDRB |= 0xB0;
	SPCR = 0x53;
	SPSR = 0x00;
}

void SPI_SlaveInit()
{
	DDRB &= ~(1<<6);
	SPCR = 0x43;
	SPSR = 0x00;
}

void MSPI_voidSendData(uint8_t Data)
{
	SPDR = Data;
	while(!(SPSR&(1<<SPIF)));
}

uint8_t MSPI_voidRecieveData()
{
	while(!(SPSR&(1<<SPIF)));
	return SPDR;
}