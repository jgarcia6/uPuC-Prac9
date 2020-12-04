#include <avr/io.h>
#include <avr/interrupt.h>

#define BUFFER_SIZE 64

typedef struct 
{
    char buffer[BUFFER_SIZE]; /* espacio reservado */
    volatile unsigned char in_idx; /* indice entrada (Head) */
    volatile unsigned char out_idx; /* indice entrada (tail) */
} ring_buffer_t;

// Prototypes
// Initialization
UART_Ini(uint8_t com, uint16_t baudrate, uint8_t size, uint8_t parity, uint8_t stop);

// Send
void UART_puts(uint8_t com, char *str);
void UART_putchar(uint8_t com, char data);

// Received
uint8_t UART_available(uint8_t com);
char UART_getchar(uint8_t com );
void UART_gets(uint8_t com, char *str);

// Escape sequences
UART_clrscr( uint8_t com );
UART_setColor(uint8_t com, uint8_t color);
UART_gotoxy(uint8_t com, uint8_t x, uint8_t y);

// Utils
void itoa(uint16_t number, char* str, uint8_t base);
uint16_t atoi(char *str);

// ISRs
//ISR( USARTx_RX_vect )
// ISR( USARTx_UDRE_vect )