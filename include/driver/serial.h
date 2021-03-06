#ifndef DRIVER_SERIAL_H_
# define DRIVER_SERIAL_H_

# include <common.h>

# define PORT_COM1 0x3F8
# define PORT_COM2 0x2F8
# define PORT_COM3 0x3E8
# define PORT_COM4 0x2E8

# define PORT_OFFSET_DATA_REG(port)						(port + 0)
# define PORT_OFFSET_INT_ENABLE_REG(port)				(port + 1)
# define PORT_OFFSET_BRATE_DIVISOR_LOW(port)			(port + 0)
# define PORT_OFFSET_BRATE_DIVISOR_HIGH(port)			(port + 1)
# define PORT_OFFSET_INT_CONTROL_REG(port)				(port + 2)
# define PORT_OFFSET_LINE_CONTROL_REG(port)				(port + 3)
# define PORT_OFFSET_MODEM_CONTROL_REG(port)			(port + 4)
# define PORT_OFFSET_LINE_STATUS_REG(port)				(port + 5)
# define PORT_OFFSET_MODEM_STATUS_REG(port)				(port + 6)
# define PORT_OFFSET_SCRATCH_REGISTER(port)				(port + 7)

# define SERIAL_BIT_DLAB_OFF							0b00000000
# define SERIAL_BIT_DLAB_ON								0b10000000

# define SERIAL_BIT_DATA_5								0b00000000
# define SERIAL_BIT_DATA_6								0b00000001
# define SERIAL_BIT_DATA_7								0b00000010
# define SERIAL_BIT_DATA_8								0b00000011
# define SERIAL_BIT_DATA_ASCII							SERIAL_BIT_DATA_7

# define SERIAL_BIT_STOP_ONE							0b00000000
# define SERIAL_BIT_STOP_MULTIPLE						0b00000100

# define SERIAL_BIT_PARITY_NONE							0b00000000
# define SERIAL_BIT_PARITY_ODD							0b00001000
# define SERIAL_BIT_PARITY_EVEN							0b00011000
# define SERIAL_BIT_PARITY_MARK							0b00101000
# define SERIAL_BIT_PARITY_SPACE						0b00111000

# define SERIAL_BIT_INT_NONE							0b00000000
# define SERIAL_BIT_INT_DATA_AVAILABLE					0b00000001
# define SERIAL_BIT_INT_TRANSMITTER_EMPTY				0b00000010
# define SERIAL_BIT_INT_ERROR							0b00000100
# define SERIAL_BIT_INT_STATUS_CHANGE					0b00001000
# define SERIAL_BIT_INT_UNUSED							0b11110000

# define SERIAL_BIT_STATUS_DATA_READY					0b00000001
# define SERIAL_BIT_STATUS_DATA_OVERRUN_ERROR			0b00000010
# define SERIAL_BIT_STATUS_DATA_PARITY_ERROR			0b00000100
# define SERIAL_BIT_STATUS_DATA_FRAMING_ERROR			0b00001000
# define SERIAL_BIT_STATUS_DATA_BREAK_INDICATOR			0b00010000
# define SERIAL_BIT_STATUS_DATA_TR_HOLD_REG_EMPTY		0b00100000
# define SERIAL_BIT_STATUS_DATA_TR_EMPTY				0b01000000
# define SERIAL_BIT_STATUS_DATA_IMPENDING_ERROR			0b10000000

# define SERIAL_DR		SERIAL_BIT_STATUS_DATA_READY
# define SERIAL_OE		SERIAL_BIT_STATUS_DATA_OVERRUN_ERROR
# define SERIAL_PE		SERIAL_BIT_STATUS_DATA_PARITY_ERROR
# define SERIAL_FE		SERIAL_BIT_STATUS_DATA_FRAMING_ERROR
# define SERIAL_BI		SERIAL_BIT_STATUS_DATA_BREAK_INDICATOR
# define SERIAL_THRE	SERIAL_BIT_STATUS_DATA_TR_HOLD_REG_EMPTY
# define SERIAL_TEMT	SERIAL_BIT_STATUS_DATA_TR_EMPTY
# define SERIAL_IE		SERIAL_BIT_STATUS_DATA_IMPENDING_ERROR

# define DIVISOR_BAUD_RATE_115200_LOW					0x01
# define DIVISOR_BAUD_RATE_115200_HIGH					0x00
# define DIVISOR_BAUD_RATE_57600_LOW					0x02
# define DIVISOR_BAUD_RATE_57600_HIGH					0x00
# define DIVISOR_BAUD_RATE_38400_LOW					0x03
# define DIVISOR_BAUD_RATE_38400_HIGH					0x00

void	serial_initialize(uint16 port);
bool	serial_available(uint16 port);
uint8	serial_read(uint16 port);
bool	serial_is_transmit_empty(uint16 port);
void	serial_write(uint16 port, int8 chr);
void	serial_write_str(uint16 port, int8 *str);

#endif /* DRIVER_SERIAL_H_ */
