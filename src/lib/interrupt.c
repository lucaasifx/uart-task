#include "interrupt.h"
#include "button.h"
#include "led.h"
#include "pico/bootrom.h"
#include "pico/stdlib.h"
#include "ssd1306.h"
#include <stdio.h>

// Função que lida com eventos de interrupção
void gpio_irq_handler(uint gpio, uint32_t events) {
    // eventos de acionamento de botões
    if(gpio == BUTTON_A || gpio == BUTTON_B || gpio == JOYSTICK_BUTTON) {
        // tratamento de debouncing dos botões
        if(!debouncing(300))
            return;
        // Habilita a entrada do modo BOOTSELL ao pressionar JOYSTICK_BUTTON
        if(gpio == JOYSTICK_BUTTON)
            reset_usb_boot(0,0);

        // Deve alternar o estado do LED verde
        if(gpio == BUTTON_A) {
            if(gpio_get(LED_GREEN))
                puts("\nLED verde desligado.");
            else
                puts("\nLED verde ligado.");
            // ALTERNA O ESTADO DO LED verde
            gpio_put(LED_GREEN, !gpio_get(LED_GREEN));
        }
        if(gpio == BUTTON_B) {
            if(gpio_get(LED_BLUE))
                puts("\nLED azul desligado.");
            else
                puts("\nLED azul ligado.");
            // ALTERNA O ESTADO DO LED azul
            gpio_put(LED_BLUE, !gpio_get(LED_BLUE));
        }

    }
}