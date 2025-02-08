#include <stdio.h>
#include "pico/stdlib.h"
#include "hardware/pio.h"
#include "hardware/clocks.h"
#include "hardware/uart.h"


// ************************* LIBS ******************************

#include "matrix.h"
#include "lib/button.h"
#include "lib/led.h"
#include "lib/interrupt.h"
#include "menu.h"
#include "lib/ws2812.pio.h"

// *********************** MACROS *******************************

#define UART_ID uart0
#define UART_TX 0
#define UART_RX 1
#define BAUD_RATE 115200


int main() {
    // habilita o uso da comunicação UART
    stdio_init_all();

    // Configuração da UART
    uart_init(UART_ID, BAUD_RATE);
    gpio_set_function(UART_TX, GPIO_FUNC_UART);
    gpio_set_function(UART_RX, GPIO_FUNC_UART);


    // Inicialização do botões e configuração de eventos de interrupção
    init_button_with_interrupt(BUTTON_A, GPIO_IRQ_EDGE_FALL, true);
    init_button_with_interrupt(BUTTON_B, GPIO_IRQ_EDGE_FALL, true);
    init_button_with_interrupt(JOYSTICK_BUTTON, GPIO_IRQ_EDGE_FALL, true);

    // Configuração da matriz de LEDS
    PIO pio = pio0;
    int sm = 0;
    uint offset = pio_add_program(pio, &ws2812_program);
    ws2812_program_init(pio, sm, offset, WS2812_PIN, 800000, IS_RGBW);

    char input;
    // rotina principal
    while(true) {

        // so vai entrar nessa rotina se a USB estiver conectada
        if(stdio_usb_connected()) {
            main_menu();
            scanf("%c", &input);
            switch (input) {
                case '0':
                    /* code */
                    break;
                case '1':
                    /* code */
                    break;
                case '2':
                    /* code */
                    break;
                case '3':
                    /* code */
                    break;
                case '4':
                    /* code */
                    break;
                case '5':
                    /* code */
                    break;   
                case '6':
                    /* code */
                    break;  
                case '7':
                    /* code */
                    break; 
                case '8':
                    /* code */
                    break; 
                case '9':
                    /* code */
                    break;   
                // limpa o terminal              
                case 'c':
                    break;
                // ESCAPE para finalizar o programa
                case 27:
                    break;
                default:
                    break;
            }
        }
        // para evitar que o loop seja executado muito rapidamente
        sleep_ms(100);
    }
}