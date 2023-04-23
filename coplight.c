#include "pindef.h"
#include "pico/stdlib.h"
#include "pico/cyw43_arch.h"


void setup() {

    //initiate
    stdio_init_all();
    if (cyw43_arch_init()) {
        printf("Wi-Fi init failed");
    }
    
    //set direction for the two LEDs
    gpio_init(BLUE_LED_PIN);
    gpio_set_dir(BLUE_LED_PIN, GPIO_OUT);
    gpio_init(RED_LED_PIN);
    gpio_set_dir(RED_LED_PIN, GPIO_OUT);

    //set direction for the two buttons
    gpio_init(ON_OFF_BTN_PIN);
    gpio_set_dir(ON_OFF_BTN_PIN, GPIO_IN);
    gpio_init(TOGGLE_BTN_PIN);
    gpio_set_dir(TOGGLE_BTN_PIN, GPIO_IN);    

}

void on_code(uint *current) {

    gpio_put(*current, 1);
    sleep_ms(150);

    if(*current == BLUE_LED_PIN) {
        gpio_put(*current, 0);
        *current = RED_LED_PIN;
    }
    else {
        gpio_put(*current, 0);
        *current = BLUE_LED_PIN;
    }
}

void off_code() {
    gpio_put(BLUE_LED_PIN, 0);
    gpio_put(RED_LED_PIN, 0);
}


int main() {

    setup();
    enum state{ON, OFF};

    enum state on_off;
    on_off = OFF;

    uint flag_on_off = 0;
    uint current = BLUE_LED_PIN;

    while (true) {

        //check if on off button is pressed
        //use a while loop so that nothing happens as long as button pressed
        while(gpio_get(ON_OFF_BTN_PIN) == 1) {
            //set on off flag
            flag_on_off = 1;
            sleep_ms(50);
        }

        while(gpio_get(TOGGLE_BTN_PIN) == 1) {
            //set the siren pattern 
            gpio_put(RED_LED_PIN, 0);
            gpio_put(BLUE_LED_PIN, 1);
            sleep_ms(40);
            gpio_put(BLUE_LED_PIN, 0);
            gpio_put(RED_LED_PIN, 1);
            sleep_ms(40);
        }

        //run the lights
        if(on_off == ON) {
            on_code(&current);
            if(flag_on_off == 1) {
                on_off = OFF;
                flag_on_off = 0;
            }
        }
        else {
            off_code();
            if(flag_on_off == 1) {
                on_off = ON;
                flag_on_off = 0;
            }
        }

    }
}
