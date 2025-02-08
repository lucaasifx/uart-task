#include "interrupt.h"
#include "button.h"
#include "pico/bootrom.h"
#include "pico/stdlib.h"
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
    }
}