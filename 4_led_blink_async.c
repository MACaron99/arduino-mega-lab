#include <avr/io.h>
#include <util/delay.h>

#define LED1_PIN PD0
#define LED2_PIN PD1

int main(void) {
    DDRD |= (1 << LED1_PIN) | (1 << LED2_PIN);

    const uint16_t period_led1 = 3000;
    const uint16_t period_led2 = 2000;

    uint16_t time_led1 = 0; // Время для первого светодиода
    uint16_t time_led2 = 0; // Время для второго светодиода

    while (1) {
        _delay_ms(10);
        
        time_led1 += 10;
        time_led2 += 10;

        if (time_led1 >= period_led1) {
            time_led1 = 0;
        }
        if (time_led1 < (period_led1 / 2)) {
            PORTD |= (1 << LED1_PIN);
        } else {
            PORTD &= ~(1 << LED1_PIN);
        }

        if (time_led2 >= period_led2) {
            time_led2 = 0;
        }
        if (time_led2 < (period_led2 / 2)) {
            PORTD |= (1 << LED2_PIN);
        } else {
            PORTD &= ~(1 << LED2_PIN);
        }
    }

    return 0;
}
