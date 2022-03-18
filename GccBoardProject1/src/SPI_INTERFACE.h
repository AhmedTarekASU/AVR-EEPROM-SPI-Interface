#ifndef SPI_INTERFACE_H_
#define SPI_INTERFACE_H_
#include <avr/io.h>

void SPI_MasterInit();
void SPI_SlaveInit();
void MSPI_voidSendData(uint8_t Data);
uint8_t MSPI_voidRecieveData();


#endif /* SPI_INTERFACE_H_ */