/*******************************************************************************
 * File		: DIO_interface.h, provides APIs for DIO preipheral
 * Date		: 6th Feb 2019
 * Version	: 1.2
 * Author	: Mohammad Mohsen
*******************************************************************************/

/*******************************************************************************
 * Description :
 * -------------
 * This component provides APIs for DIO preipheral
*******************************************************************************/

#ifndef _DIO_INTERFACE_H_
#define _DIO_INTERFACE_H_

/* --------------------------- DIO Constants -------------------------------- */


#define DIO_u8MAX_PINS			32u
#define DIO_u8PINS_PER_PORT		8u

/* ------------------- PIN Numbers ----------------- */
#define DIO_u8PIN_00    0u
#define DIO_u8PIN_01    1u
#define DIO_u8PIN_02    2u
#define DIO_u8PIN_03    3u
#define DIO_u8PIN_04    4u
#define DIO_u8PIN_05    5u
#define DIO_u8PIN_06    6u
#define DIO_u8PIN_07    7u
#define DIO_u8PIN_08    8u
#define DIO_u8PIN_09    9u

#define DIO_u8PIN_10    10u
#define DIO_u8PIN_11    11u
#define DIO_u8PIN_12    12u
#define DIO_u8PIN_13    13u
#define DIO_u8PIN_14    14u
#define DIO_u8PIN_15    15u
#define DIO_u8PIN_16    16u
#define DIO_u8PIN_17    17u
#define DIO_u8PIN_18    18u
#define DIO_u8PIN_19    19u

#define DIO_u8PIN_20    20u
#define DIO_u8PIN_21    21u
#define DIO_u8PIN_22    22u
#define DIO_u8PIN_23    23u
#define DIO_u8PIN_24    24u
#define DIO_u8PIN_25    25u
#define DIO_u8PIN_26    26u
#define DIO_u8PIN_27    27u
#define DIO_u8PIN_28    28u
#define DIO_u8PIN_29    29u

#define DIO_u8PIN_30    30u
#define DIO_u8PIN_31    31u

/* ---------------- DIO Ports ------------------------- */
#define DIO_u8PORT_A    0u
#define DIO_u8PORT_B    1u
#define DIO_u8PORT_C    2u
#define DIO_u8PORT_D    3u


/* ---------------- PIN Values ---------------------- */
#define DIO_u8VALUE_LOW     	0
#define DIO_u8VALUE_HIGH    	1

/* ---------------- PIN Directions ------------------ */
#define DIO_u8DIR_INPUT     	0
#define DIO_u8DIR_OUTPUT    	1

/* ----------------------- DIO Error Codes ---------------------------- */
#define DIO_u8ERR_CODE_SUCCESS				0u
#define DIO_u8ERR_CODE_INVALID_ARG			1u
#define DIO_u8ERR_CODE_INVALID_PIN			2u
#define DIO_u8ERR_CODE_INVALID_PORT			3u
#define DIO_u8ERR_CODE_INVALID_DIR			4u
#define DIO_u8ERR_CODE_INVALID_VAL			5u
#define DIO_u8ERR_CODE_NULL_PTR			    6u

/**
 * Initializes the direction and initial values for DIO pins as configured in
 * DIO config.h
 * @param void
 * @return void
 */
void DIO_vidInitialize(void);


/**
 * Sets a given pin output value
 * @param (uint8_t) Copy_u8PinId	: The pin id to set DIO_u8PIN_[00-32]
 * @param (uint8_t)	Copy_u8PinValue : The pin value DIO_u8VALUE_[LOW, HIGH]
 * @return (uint8_t):	error code indicating if the function execution was
 *  					successful or not DIO_u8ERR_CODE_[SUCCESS, INVALID_ARG]
 * */
uint8_t DIO_u8SetPinValue(uint8_t Copy_u8PinId, uint8_t Copy_u8PinValue);

/**
 * Sets a given pin's direction
 * @param (uint8_t) Copy_u8PinId	: The pin id to set DIO_u8PIN_[00-32]
 * @param (uint8_t)	Copy_u8PinDirection : The pin value DIO_u8DIR_[INPUT, OUTPUT]
 * @return (uint8_t):	error code indicating if the function execution was
 *  					successful or not DIO_u8ERR_CODE_[SUCCESS, INVALID_ARG]
 * */
uint8_t DIO_u8SetPinDirection(uint8_t Copy_u8PinId, uint8_t Copy_u8PinDirection);

/**
 * Sets a given pin's direction
 * @param (uint8_t) Copy_u8PinId	: The pin id to set DIO_u8PIN_[00-32]
 * @param (uint8_t *)	Copy_Pu8pResult : A pointer to result container
 * @return (uint8_t):	error code indicating if the function execution was
 *  					successful or not DIO_u8ERR_CODE_[SUCCESS, INVALID_ARG]
 * */
uint8_t DIO_u8GetPinValue(uint8_t Copy_u8PinId, uint8_t * Copy_Pu8pResult);

///**
// * Sets a given port's output value ( all zeros or all ones )
// * @param (uint8_t) Copy_u8PortId	: The port id to set DIO_u8PORT_[A, B, C, D]
// * @param (uint8_t)	Copy_u8PortValue: The port value DIO_u8VALUE_[LOW, HIGH]
// * @return (uint8_t):	error code indicating if the function execution was
// *  					successful or not DIO_u8ERR_CODE_[SUCCESS, INVALID_ARG]
// * */
//uint8_t DIO_u8SetPortValue(uint8_t Copy_u8PortId, uint8_t Copy_u8PortValue);
//
///**
// * Sets a given port's output value ( puts value on the port )
// * @param (uint8_t) Copy_u8PortId	: The port id to set DIO_u8PORT_[A, B, C, D]
// * @param (uint8_t)	Copy_u8PortValue: The port value (0 - 255)
// * @return (uint8_t):	error code indicating if the function execution was
// *  					successful or not DIO_u8ERR_CODE_[SUCCESS, INVALID_ARG]
// * */
//uint8_t DIO_u8AssignPortValue(uint8_t Copy_u8PortId, uint8_t Copy_u8PortValue);
//
///**
// * Sets a given port's direction
// * @param (uint8_t) Copy_u8PortId	: The port id to set DIO_u8PORT_[A, B, C, D]
// * @param (uint8_t)	Copy_u8PortDirection : The port value DIO_u8DIR_[INPUT, OUTPUT]
// * @return (uint8_t):	error code indicating if the function execution was
// *  					successful or not DIO_u8ERR_CODE_[SUCCESS, INVALID_ARG]
// * */
//uint8_t DIO_u8SetPortDirection(uint8_t Copy_u8PortId, uint8_t Copy_u8PortDirection);
//
///**
// * Gets a given port's input value
// * @param (uint8_t) Copy_u8PortId	: The port id to set DIO_u8PORT_[A, B, C, D]
// * @param (uint8_t)	Copy_Pu8pResult : A pointer to result container
// * @return (uint8_t):	error code indicating if the function execution was
// *  					successful or not DIO_u8ERR_CODE_[SUCCESS, INVALID_ARG]
// * */
//uint8_t DIO_u8GetPortValue(uint8_t Copy_u8PortId, uint8_t * Copy_Pu8pResult);

#endif  //_DIO_INTERFACE_H_
