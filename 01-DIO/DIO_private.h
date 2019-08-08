/*******************************************************************************
 * File		: DIO_config.h, defines configurations for DIO preipheral
 * Date		: 6th Feb 2019
 * Version	: 1.2
 * Author	: Mohammad Mohsen
*******************************************************************************/

/*******************************************************************************
 * Description :
 * -------------
 * DIO_config.h, defines configurations for DIO preipheral
*******************************************************************************/

#ifndef _DIO_PRIVATE_H_
#define _DIO_PRIVATE_H_

/* -------------------------- Registers Addresses --------------------------- */

#define DIO_PORTA_ADDRESS   0x3B
#define DIO_DDRA_ADDRESS    0x3A
#define DIO_PINA_ADDRESS    0x39

#define DIO_PORTB_ADDRESS   0x38
#define DIO_DDRB_ADDRESS    0x37
#define DIO_PINB_ADDRESS    0x36

#define DIO_PORTC_ADDRESS   0x35
#define DIO_DDRC_ADDRESS    0x34
#define DIO_PINC_ADDRESS    0x33

#define DIO_PORTD_ADDRESS   0x32
#define DIO_DDRD_ADDRESS    0x31
#define DIO_PIND_ADDRESS    0x30

/* ------------ PORTA ------------- */
#define PORTA	((Register_8bit_t *)(DIO_PORTA_ADDRESS))
#define DDRA    ((Register_8bit_t *)(DIO_DDRA_ADDRESS))
#define PINA    ((Register_8bit_t *)(DIO_PINA_ADDRESS))

/* ------------ PORTB ------------- */
#define PORTB	((Register_8bit_t *)(DIO_PORTB_ADDRESS))
#define DDRB    ((Register_8bit_t *)(DIO_DDRB_ADDRESS))
#define PINB    ((Register_8bit_t *)(DIO_PINB_ADDRESS))

/* ------------ PORTC ------------- */
#define PORTC	((Register_8bit_t *)(DIO_PORTC_ADDRESS))
#define DDRC    ((Register_8bit_t *)(DIO_DDRC_ADDRESS))
#define PINC    ((Register_8bit_t *)(DIO_PINC_ADDRESS))

/* ------------ PORTD ------------- */
#define PORTD	((Register_8bit_t *)(DIO_PORTD_ADDRESS))
#define DDRD    ((Register_8bit_t *)(DIO_DDRD_ADDRESS))
#define PIND    ((Register_8bit_t *)(DIO_PIND_ADDRESS))



#endif // _DIO_PRIVATE_H_
