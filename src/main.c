#include <stdio.h>
#include <stdlib.h>
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

    // Inicializa os LEDS
    init_led(LED_GREEN);
    init_led(LED_BLUE);
    // Inicialização do botões e configuração de eventos de interrupção
    init_button_with_interrupt(BUTTON_A, GPIO_IRQ_EDGE_FALL, true);
    init_button_with_interrupt(BUTTON_B, GPIO_IRQ_EDGE_FALL, true);
    init_button_with_interrupt(JOYSTICK_BUTTON, GPIO_IRQ_EDGE_FALL, true);

    // Configuração da matriz de LEDS
    PIO pio = pio0;
    int sm = 0;
    uint offset = pio_add_program(pio, &ws2812_program);
    ws2812_program_init(pio, sm, offset, WS2812_PIN, 800000, IS_RGBW);


    // Aguarda pressionar Enter para exibir o menu pela primeira vez
    getchar();
    char input;
    // rotina principal
    while(true) {

        // so vai entrar nessa rotina se a USB estiver conectada
        if(stdio_usb_connected()) {
            main_menu();
            puts("");
            while(true) {
                printf("Escolha uma opcao: ");
                scanf("%c", &input);
                if((input>= '0' && input <= '9')
                                || input == 'c'
                                || input == 27)
                    break;
                printf("Caractere inválido!\n");
            }
            switch (input) {
                case '0':
                    actual_number = 0;
                    set_one_led(numbers[actual_number], led_r, led_g, led_b);
                    printf("Exibindo o numero %d na matriz\n", actual_number);
                    break;
                case '1':
                    actual_number = 1;
                    set_one_led(numbers[actual_number], led_r, led_g, led_b);
                    printf("Exibindo o numero %d na matriz\n", actual_number);
                    break;
                case '2':
                    actual_number = 2;
                    set_one_led(numbers[actual_number], led_r, led_g, led_b);
                    printf("Exibindo o numero %d na matriz\n", actual_number);
                    break;
                case '3':
                    actual_number = 3;
                    set_one_led(numbers[actual_number], led_r, led_g, led_b);
                    printf("Exibindo o numero %d na matriz\n", actual_number);
                    break;
                case '4':
                    actual_number = 4;
                    set_one_led(numbers[actual_number], led_r, led_g, led_b);
                    printf("Exibindo o numero %d na matriz\n", actual_number);
                    break;
                case '5':
                    actual_number = 5;
                    set_one_led(numbers[actual_number], led_r, led_g, led_b);
                    printf("Exibindo o numero %d na matriz\n", actual_number);
                    break;   
                case '6':
                    actual_number = 6;
                    set_one_led(numbers[actual_number], led_r, led_g, led_b);
                    printf("Exibindo o numero %d na matriz\n", actual_number);
                    break;  
                case '7':
                    actual_number = 7;
                    set_one_led(numbers[actual_number], led_r, led_g, led_b);
                    printf("Exibindo o numero %d na matriz\n", actual_number);
                    break; 
                case '8':
                    actual_number = 8;
                    set_one_led(numbers[actual_number], led_r, led_g, led_b);
                    printf("Exibindo o numero %d na matriz\n", actual_number);
                    break; 
                case '9':
                    actual_number = 9;
                    set_one_led(numbers[actual_number], led_r, led_g, led_b);
                    printf("Exibindo o numero %d na matriz\n", actual_number);
                    break;   
                // limpa o terminal              
                case 'c':
                    system("cls");
                    break;
                // ESCAPE para finalizar o programa
                case 27:
                    break;
                default:
                    break;
            }
            puts("");
        }
        // para evitar que o loop seja executado muito rapidamente
        sleep_ms(100);
    }
}