/*******************************************************************************
6 * File	: DIO_config.h, defines configurations for DIO preipheral
 * Date		: 15th Mar 2019
 * Version	: 1.3
 * Author	: Mohammad Mohsen
 *******************************************************************************/

/*******************************************************************************
 * Description :
 * -------------
 * DIO_config.h, defines configurations for DIO preipheral
 *******************************************************************************/

#include "std_types.h"
#include "bit_man.h"
#include "DIO_interface.h"
#include "DIO_config.h"
#include "DIO_private.h"

/**
 * Initializes the direction and initial values for DIO pins as configured in
 * DIO config.h
 * @param void
 * @return void
 */
void DIO_vidInitialize(void)
{
	/* --------------- Initializing Port Directions ----------------- */
	/* --------- DDRA -------------- */
	DDRA->ByteAccess = CAT8BIT(DIO_u8PIN_07_DIR, DIO_u8PIN_06_DIR, DIO_u8PIN_05_DIR,
			DIO_u8PIN_04_DIR, DIO_u8PIN_03_DIR, DIO_u8PIN_02_DIR,
			DIO_u8PIN_01_DIR, DIO_u8PIN_00_DIR);

	/* --------- DDRB -------------- */
	DDRB->ByteAccess = CAT8BIT(DIO_u8PIN_15_DIR, DIO_u8PIN_14_DIR, DIO_u8PIN_13_DIR,
			DIO_u8PIN_12_DIR, DIO_u8PIN_11_DIR, DIO_u8PIN_10_DIR,
			DIO_u8PIN_09_DIR, DIO_u8PIN_08_DIR);

	/* --------- DDRC -------------- */
	DDRC->ByteAccess = CAT8BIT(DIO_u8PIN_23_DIR, DIO_u8PIN_22_DIR, DIO_u8PIN_21_DIR,
			DIO_u8PIN_20_DIR, DIO_u8PIN_19_DIR, DIO_u8PIN_18_DIR,
			DIO_u8PIN_17_DIR, DIO_u8PIN_16_DIR);

	/* --------- DDRD -------------- */
	DDRD->ByteAccess = CAT8BIT(DIO_u8PIN_31_DIR, DIO_u8PIN_30_DIR, DIO_u8PIN_29_DIR,
			DIO_u8PIN_28_DIR, DIO_u8PIN_27_DIR, DIO_u8PIN_26_DIR,
			DIO_u8PIN_25_DIR, DIO_u8PIN_24_DIR);

	/* -------------------- Initializing Port values ------------------------ */
	/* --------- PORTA -------------- */
	PORTA->ByteAccess = CAT8BIT(DIO_u8PIN_07_INIT_VALUE, DIO_u8PIN_06_INIT_VALUE,
			DIO_u8PIN_05_INIT_VALUE, DIO_u8PIN_04_INIT_VALUE,
			DIO_u8PIN_03_INIT_VALUE, DIO_u8PIN_02_INIT_VALUE,
			DIO_u8PIN_01_INIT_VALUE, DIO_u8PIN_00_INIT_VALUE);

	/* --------- PORTB -------------- */
	PORTB->ByteAccess = CAT8BIT(DIO_u8PIN_15_INIT_VALUE, DIO_u8PIN_14_INIT_VALUE,
			DIO_u8PIN_13_INIT_VALUE, DIO_u8PIN_12_INIT_VALUE,
			DIO_u8PIN_11_INIT_VALUE, DIO_u8PIN_10_INIT_VALUE,
			DIO_u8PIN_09_INIT_VALUE, DIO_u8PIN_08_INIT_VALUE);

	/* --------- PORTC -------------- */
	PORTC->ByteAccess = CAT8BIT(DIO_u8PIN_23_INIT_VALUE, DIO_u8PIN_22_INIT_VALUE,
			DIO_u8PIN_21_INIT_VALUE, DIO_u8PIN_20_INIT_VALUE,
			DIO_u8PIN_19_INIT_VALUE, DIO_u8PIN_18_INIT_VALUE,
			DIO_u8PIN_17_INIT_VALUE, DIO_u8PIN_16_INIT_VALUE);

	/* --------- PORTD -------------- */
	PORTD->ByteAccess = CAT8BIT(DIO_u8PIN_31_INIT_VALUE, DIO_u8PIN_30_INIT_VALUE,
			DIO_u8PIN_29_INIT_VALUE, DIO_u8PIN_28_INIT_VALUE,
			DIO_u8PIN_27_INIT_VALUE, DIO_u8PIN_26_INIT_VALUE,
			DIO_u8PIN_25_INIT_VALUE, DIO_u8PIN_24_INIT_VALUE);

}

/**
 * Sets a given pin's output value
 * @param (uint8_t) Copy_u8PinId	: The pin id to set DIO_u8PIN_[00-32]
 * @param (uint8_t)	Copy_u8PinValue : The pin value DIO_u8VALUE_[LOW, HIGH]
 * @return (uint8_t):	error code indicating if the function execution was
 *  					successful or not DIO_u8ERR_CODE_[SUCCESS, INVALID_ARG]
 * */
uint8_t DIO_u8SetPinValue(uint8_t Copy_u8PinId, uint8_t Copy_u8PinValue)
{
	uint8_t err_code = DIO_u8ERR_CODE_SUCCESS;

	/*	calculate port number	*/
	uint8_t u8PortNumber = Copy_u8PinId / DIO_u8PINS_PER_PORT;

	/*	validate pin number		*/
	if ((Copy_u8PinId >= DIO_u8MAX_PINS)
			|| ((Copy_u8PinValue != DIO_u8VALUE_HIGH)
					&& (Copy_u8PinValue != DIO_u8VALUE_LOW))
		)
	{
		err_code = DIO_u8ERR_CODE_INVALID_ARG;
	}
	else
	{
		/*	calculate pin number	*/
		Copy_u8PinId %= DIO_u8PINS_PER_PORT;

		/*	check port	*/
		switch (u8PortNumber)
		{
		case DIO_u8PORT_A:
			if (Copy_u8PinValue == DIO_u8VALUE_HIGH)
			{
				SET_BIT(PORTA->ByteAccess, Copy_u8PinId);
			}
			else
			{
				CLR_BIT(PORTA->ByteAccess, Copy_u8PinId);
			} /*	end if	*/
			break;

		case DIO_u8PORT_B:
			if (Copy_u8PinValue == DIO_u8VALUE_HIGH)
			{
				SET_BIT(PORTB->ByteAccess, Copy_u8PinId);
			}
			else
			{
				CLR_BIT(PORTB->ByteAccess, Copy_u8PinId);
			} /*	end if	*/
			break;

		case DIO_u8PORT_C:
			if (Copy_u8PinValue == DIO_u8VALUE_HIGH)
			{
				SET_BIT(PORTC->ByteAccess, Copy_u8PinId);
			}
			else
			{
				CLR_BIT(PORTC->ByteAccess, Copy_u8PinId);
			} /*	end if	*/
			break;

		case DIO_u8PORT_D:
			if (Copy_u8PinValue == DIO_u8VALUE_HIGH)
			{
				SET_BIT(PORTD->ByteAccess, Copy_u8PinId);
			}
			else
			{
				CLR_BIT(PORTD->ByteAccess, Copy_u8PinId);
			} /*	end if	*/
			break;

		default:
			err_code = DIO_u8ERR_CODE_INVALID_ARG;
			break;
		} /*	end switch u8PortNumber		*/

	} /*	end if		*/
	return err_code;
}

/**
 * Sets a given pin's direction
 * @param (uint8_t) Copy_u8PinId	: The pin id to set DIO_u8PIN_[00-32]
 * @param (uint8_t)	Copy_u8PinDirection : The pin value DIO_u8DIR_[INPUT, OUTPUT]
 * @return (uint8_t):	error code indicating if the function execution was
 *  					successful or not DIO_u8ERR_CODE_[SUCCESS, INVALID_ARG]
 * */
uint8_t DIO_u8SetPinDirection(uint8_t Copy_u8PinId, uint8_t Copy_u8PinDirection)
{
	uint8_t err_code = DIO_u8ERR_CODE_SUCCESS;

	/*	calculate port number	*/
	uint8_t u8PortNumber = Copy_u8PinId / DIO_u8PINS_PER_PORT;

	/*	validate pin number		*/
	if ((Copy_u8PinId >= DIO_u8MAX_PINS)
			|| ((Copy_u8PinDirection != DIO_u8DIR_OUTPUT)
					&& (Copy_u8PinDirection != DIO_u8DIR_INPUT))
		)
	{
		err_code = DIO_u8ERR_CODE_INVALID_ARG;
	}
	else
	{
		/*	calculate pin number	*/
		Copy_u8PinId %= DIO_u8PINS_PER_PORT;

		/*	check port	*/
		switch (u8PortNumber)
		{
		case DIO_u8PORT_A:
			if (Copy_u8PinDirection == DIO_u8DIR_OUTPUT)
			{
				SET_BIT(DDRA->ByteAccess, Copy_u8PinId);
			}
			else
			{
				CLR_BIT(DDRA->ByteAccess, Copy_u8PinId);
			} /*	end if	*/
			break;

		case DIO_u8PORT_B:
			if (Copy_u8PinDirection == DIO_u8DIR_OUTPUT)
			{
				SET_BIT(DDRB->ByteAccess, Copy_u8PinId);
			}
			else
			{
				CLR_BIT(DDRB->ByteAccess, Copy_u8PinId);
			} /*	end if	*/
			break;

		case DIO_u8PORT_C:
			if (Copy_u8PinDirection == DIO_u8DIR_OUTPUT)
			{
				SET_BIT(DDRC->ByteAccess, Copy_u8PinId);
			}
			else
			{
				CLR_BIT(DDRC->ByteAccess, Copy_u8PinId);
			} /*	end if	*/
			break;

		case DIO_u8PORT_D:
			if (Copy_u8PinDirection == DIO_u8DIR_OUTPUT)
			{
				SET_BIT(DDRD->ByteAccess, Copy_u8PinId);
			}
			else
			{
				CLR_BIT(DDRD->ByteAccess, Copy_u8PinId);
			} /*	end if	*/
			break;

		default:
			err_code = DIO_u8ERR_CODE_INVALID_ARG;
			break;
		} /*	end switch u8PortNumber		*/

	} /*	end if		*/
	return err_code;
}

/**
 * Gets a given pin's input value
 * @param (uint8_t) Copy_u8PinId	: The pin id to set DIO_u8PIN_[00-32]
 * @param (uint8_t *)	Copy_Pu8pResult : A pointer to result container
 * @return (uint8_t):	error code indicating if the function execution was
 *  					successful or not DIO_u8ERR_CODE_[SUCCESS, INVALID_ARG]
 * */
uint8_t DIO_u8GetPinValue(uint8_t Copy_u8PinId, uint8_t * Copy_pu8_Result)
{
	uint8_t err_code = DIO_u8ERR_CODE_SUCCESS;

	/*	calculate port number	*/
	uint8_t u8PortNumber = Copy_u8PinId / DIO_u8PINS_PER_PORT;

	/*	validate pin number		*/
	if ((Copy_u8PinId > DIO_u8MAX_PINS) || (Copy_pu8_Result == NULL))
	{
		err_code = DIO_u8ERR_CODE_INVALID_ARG;
	}
	else
	{
		/*	calculate pin number	*/
		Copy_u8PinId %= DIO_u8PINS_PER_PORT;

		/*	check port	*/
		switch (u8PortNumber)
		{
		case DIO_u8PORT_A:
			(*Copy_pu8_Result) = GET_BIT(PINA->ByteAccess, Copy_u8PinId);
			break;

		case DIO_u8PORT_B:
			(*Copy_pu8_Result) = GET_BIT(PINB->ByteAccess, Copy_u8PinId);
			break;

		case DIO_u8PORT_C:
			(*Copy_pu8_Result) = GET_BIT(PINC->ByteAccess, Copy_u8PinId);
			break;

		case DIO_u8PORT_D:
			(*Copy_pu8_Result) = GET_BIT(PIND->ByteAccess, Copy_u8PinId);
			break;

		default:
			err_code = DIO_u8ERR_CODE_INVALID_ARG;
			break;
		} /*	end switch u8PortNumber		*/

	} /*	end if		*/
	return err_code;
}
//
///**
// * Sets a given port's output value
// * @param (uint8_t) Copy_u8PortId	: The port id to set DIO_u8PORT_[A, B, C, D]
// * @param (uint8_t)	Copy_u8PinValue : The pin value DIO_u8VALUE_[LOW, HIGH]
// * @return (uint8_t):	error code indicating if the function execution was
// *  					successful or not DIO_u8ERR_CODE_[SUCCESS, INVALID_ARG]
// * */
//uint8_t DIO_u8SetPortValue(uint8_t Copy_u8PortId, uint8_t Copy_u8PortValue)
//{
//	uint8_t err_code = DIO_u8ERR_CODE_SUCCESS;
//
//	if (Copy_u8PortId > DIO_u8PORT_D)
//	{
//		err_code = DIO_u8ERR_CODE_INVALID_ARG;
//	}
//	else
//	{
//		switch (Copy_u8PortId)
//		{
//		case DIO_u8PORT_A:
//			if(Copy_u8PortValue == DIO_u8VALUE_HIGH)
//			{
//				SET_REG(PORTA->ByteAccess);
//			}
//			else
//			{
//				CLR_REG(PORTA->ByteAccess);
//			}	/*	end if	*/
//			break;
//
//		case DIO_u8PORT_B:
//			if(Copy_u8PortValue == DIO_u8VALUE_HIGH)
//			{
//				SET_REG(PORTB->ByteAccess);
//			}
//			else
//			{
//				CLR_REG(PORTB->ByteAccess);
//			}	/*	end if	*/
//			break;
//
//		case DIO_u8PORT_C:
//			if(Copy_u8PortValue == DIO_u8VALUE_HIGH)
//			{
//				SET_REG(PORTC->ByteAccess);
//			}
//			else
//			{
//				CLR_REG(PORTC->ByteAccess);
//			}	/*	end if	*/
//			break;
//
//		case DIO_u8PORT_D:
//			if(Copy_u8PortValue == DIO_u8VALUE_HIGH)
//			{
//				SET_REG(PORTD->ByteAccess);
//			}
//			else
//			{
//				CLR_REG(PORTD->ByteAccess);
//			}	/*	end if	*/
//			break;
//		default:
//			err_code = DIO_u8ERR_CODE_INVALID_ARG;
//			break;
//		}/*	end switch port		*/
//	} /*	end if	*/
//
//	return err_code;
//}
//
//
///**
// * Sets a given port's output value ( puts value on the port )
// * @param (uint8_t) Copy_u8PortId	: The port id to set DIO_u8PORT_[A, B, C, D]
// * @param (uint8_t)	Copy_u8PortValue: The port value (0 - 255)
// * @return (uint8_t):	error code indicating if the function execution was
// *  					successful or not DIO_u8ERR_CODE_[SUCCESS, INVALID_ARG]
// * */
//uint8_t DIO_u8AssignPortValue(uint8_t Copy_u8PortId, uint8_t Copy_u8PortValue)
//{
//	uint8_t error_code = DIO_u8ERR_CODE_SUCCESS;
//
//	if(Copy_u8PortId > DIO_u8PORT_D)
//	{
//		error_code = DIO_u8ERR_CODE_INVALID_ARG;
//	}
//	else
//	{
//
//		switch (Copy_u8PortId)
//		{
//			case DIO_u8PORT_A:
//				ASN_REG(PORTA->ByteAccess, Copy_u8PortValue);
//				break;
//
//			case DIO_u8PORT_B:
//				ASN_REG(PORTB->ByteAccess, Copy_u8PortValue);
//				break;
//
//			case DIO_u8PORT_C:
//				ASN_REG(PORTC->ByteAccess, Copy_u8PortValue);
//				break;
//
//			case DIO_u8PORT_D:
//				ASN_REG(PORTD->ByteAccess, Copy_u8PortValue);
//				break;
//
//			default:
//				error_code = DIO_u8ERR_CODE_INVALID_ARG;
//				break;
//		} /*	end switch port	*/
//
//	}	/*	end if 	*/
//
//	return error_code;
//}
//
///**
// * Sets a given port's direction
// * @param (uint8_t) Copy_u8PortId	: The port id to set DIO_u8PORT_[A, B, C, D]
// * @param (uint8_t)	Copy_u8PinDirection : The pin value DIO_u8DIR_[INPUT, OUTPUT]
// * @return (uint8_t):	error code indicating if the function execution was
// *  					successful or not DIO_u8ERR_CODE_[SUCCESS, INVALID_ARG]
// * */
//uint8_t DIO_u8SetPortDirection(uint8_t Copy_u8PortId,
//		uint8_t Copy_u8PortDirection)
//{
//	uint8_t err_code = DIO_u8ERR_CODE_SUCCESS;
//
//	if ((Copy_u8PortId > DIO_u8PORT_D)
//			|| ((Copy_u8PortDirection != DIO_u8DIR_INPUT)
//				&& (Copy_u8PortDirection != DIO_u8DIR_OUTPUT))
//		)
//	{
//		err_code = DIO_u8ERR_CODE_INVALID_ARG;
//	}
//	else
//	{
//		switch (Copy_u8PortId)
//		{
//		case DIO_u8PORT_A:
//			if (Copy_u8PortDirection == DIO_u8DIR_OUTPUT)
//			{
//				SET_REG(DDRA->ByteAccess);
//			}
//			else
//			{
//				CLR_REG(DDRA->ByteAccess);
//			} /*	end if	*/
//			break;
//
//		case DIO_u8PORT_B:
//			if (Copy_u8PortDirection == DIO_u8DIR_OUTPUT)
//			{
//				SET_REG(DDRB->ByteAccess);
//			}
//			else
//			{
//				CLR_REG(DDRB->ByteAccess);
//			} /*	end if	*/
//			break;
//
//		case DIO_u8PORT_C:
//			if (Copy_u8PortDirection == DIO_u8DIR_OUTPUT)
//			{
//				SET_REG(DDRC->ByteAccess);
//			}
//			else
//			{
//				CLR_REG(DDRC->ByteAccess);
//			} /*	end if	*/
//			break;
//
//		case DIO_u8PORT_D:
//			if (Copy_u8PortDirection == DIO_u8DIR_OUTPUT)
//			{
//				SET_REG(DDRD->ByteAccess);
//			}
//			else
//			{
//				CLR_REG(DDRD->ByteAccess);
//			} /*	end if	*/
//			break;
//		default:
//			err_code = DIO_u8ERR_CODE_INVALID_ARG;
//			break;
//		}/*	end switch port		*/
//	} /*	end if	*/
//
//	return err_code;
//}
//
///**
// * Gets a given port's input value
// * @param (uint8_t) Copy_u8PortId	: The port id to set DIO_u8PORT_[A, B, C, D]
// * @param (uint8_t)	Copy_Pu8pResult : A pointer to result container
// * @return (uint8_t):	error code indicating if the function execution was
// *  					successful or not DIO_u8ERR_CODE_[SUCCESS, INVALID_ARG]
// * */
//uint8_t DIO_u8GetPortValue(uint8_t Copy_u8PortId, uint8_t * Copy_Pu8pResult)
//{
//	uint8_t err_code = DIO_u8ERR_CODE_SUCCESS;
//
//	if ((Copy_u8PortId > DIO_u8PORT_D) || (Copy_Pu8pResult == NULL))
//	{
//		err_code = DIO_u8ERR_CODE_INVALID_ARG;
//	}
//	else
//	{
//		/*	check port		*/
//		switch (Copy_u8PortId)
//		{
//		case DIO_u8PORT_A:
//			*Copy_Pu8pResult = GET_REG(PINA->ByteAccess);
//			break;
//
//		case DIO_u8PORT_B:
//			*Copy_Pu8pResult = GET_REG(PINB->ByteAccess);
//			break;
//
//		case DIO_u8PORT_C:
//			*Copy_Pu8pResult = GET_REG(PINC->ByteAccess);
//			break;
//
//		case DIO_u8PORT_D:
//			*Copy_Pu8pResult = GET_REG(PIND->ByteAccess);
//			break;
//		default:
//
//			err_code = DIO_u8ERR_CODE_INVALID_ARG;
//			break;
//		} /*	end switch port		*/
//	} /*	end if	*/
//
//	return err_code;
//}
