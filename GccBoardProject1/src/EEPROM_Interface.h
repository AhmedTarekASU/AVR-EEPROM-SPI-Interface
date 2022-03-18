#ifndef EEPROM_INTERFACE_H_
#define EEPROM_INTERFACE_H_

void EEPROM_voidSendData(uint16_t copy_u16Address, uint8_t copy_u8Data);
void EEPROM_voidSend16Byte(uint16_t copy_u16Address, uint8_t *copy_u8Data);
uint8_t EEPROM_u8ReadData(uint16_t copy_u16Address);


#endif /* EEPROM_INTERFACE_H_ */