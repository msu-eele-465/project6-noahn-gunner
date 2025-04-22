#include <msp430fr2355.h>
#include <stdint.h>
#include "lcd.h"
#include "intrinsics.h"

int main(void)
{
    // Stop watchdog timer
    WDTCTL = WDTPW | WDTHOLD;

    define_ports();

    // Disable low-power mode / GPIO high-impedance
    PM5CTL0 &= ~LOCKLPM5;

    while (true) {

        start_up();

        while (true) {
            display_mode_string(0);
            display_window_size(3);
            display_ambient_temperature('2', '3', '4');
            display_plant_temperature('1', '5', '3');
            display_time_in_state(96);
            display_mode_string(1);
            display_window_size(4);
            display_time_in_state(124);
            display_mode_string(2);
            display_ambient_temperature('4', '3', '2');
            display_plant_temperature('1', '0', '9');
            display_mode_string(3);
            display_time_in_state(5);
            display_mode_string(4);
        }
    }
}

