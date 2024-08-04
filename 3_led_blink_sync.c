#include <avr/io.h>
#include <util/delay.h>

int main(void) {
    DDRD |= (1 << PD0) | (1 << PD1);

    while (1) {
        PORTD |= (1 << PD0) | (1 << PD1);
        _delay_ms(1000);

        PORTD &= ~((1 << PD0) | (1 << PD1));
        _delay_ms(1000);
    }

    return 0;
}
