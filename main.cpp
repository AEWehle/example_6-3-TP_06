/*
se esta usando i2c
los pines son

#define I2C1_SDA PB_9
#define I2C1_SCL PB_8

la clase 
I2C i2cPcf8574( I2C1_SDA, I2C1_SCL ); 


la funcion void displayInit( displayConnection_t connection )
if( display.connection == DISPLAY_CONNECTION_I2C_PCF8574_IO_EXPANDER) {
        pcf8574.address = PCF8574_I2C_BUS_8BIT_WRITE_ADDRESS;
        pcf8574.data = 0b00000000;
        i2cPcf8574.frequency(100000);
        displayPinWrite( DISPLAY_PIN_A_PCF8574,  ON );
    } 

case DISPLAY_CONNECTION_I2C_PCF8574_IO_EXPANDER:
    displayCodeWrite( DISPLAY_RS_INSTRUCTION, 
                        DISPLAY_IR_FUNCTION_SET | 
                        DISPLAY_IR_FUNCTION_SET_4BITS );
    delay( 1 );  

    initial8BitCommunicationIsCompleted = true;  

    displayCodeWrite( DISPLAY_RS_INSTRUCTION, 
                        DISPLAY_IR_FUNCTION_SET | 
                        DISPLAY_IR_FUNCTION_SET_4BITS | 
                        DISPLAY_IR_FUNCTION_SET_2LINES |
                        DISPLAY_IR_FUNCTION_SET_5x8DOTS );
    delay( 1 ); 

la funcion displayPinWrite( uint8_t pinName, int value )
en la funcion static void displayDataBusWrite( uint8_t dataBus )
        if ( initial8BitCommunicationIsCompleted == true) {
                displayPinWrite( DISPLAY_PIN_EN, ON );         
                delay( 1 );
                displayPinWrite( DISPLAY_PIN_EN, OFF );              
                delay( 1 );        
                displayPinWrite( DISPLAY_PIN_D7, dataBus & 0b00001000 );
                displayPinWrite( DISPLAY_PIN_D6, dataBus & 0b00000100 );  
                displayPinWrite( DISPLAY_PIN_D5, dataBus & 0b00000010 );      
                displayPinWrite( DISPLAY_PIN_D4, dataBus & 0b00000001 );                
            }

no se usa lock y unlock
*/

//=====[Libraries]=============================================================

#include "smart_home_system.h"

//=====[Main function, the program entry point after power on or reset]========

int main()
{
    smartHomeSystemInit();
    while (true) {
        smartHomeSystemUpdate();
    }
}