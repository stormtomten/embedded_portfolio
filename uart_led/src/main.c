#include "pico/stdlib.h"
#include <stdio.h>
#include <string.h>

int main() {
  stdio_init_all();
  stdin_uart_init();

  const uint LED_PIN = 16;

  gpio_init(LED_PIN);
  gpio_set_dir(LED_PIN, GPIO_OUT);

  int led_state = 1;
  char input[5];

  while (!stdio_usb_connected) {
    sleep_ms(1000);
  }

  while (true) {
    gpio_put(LED_PIN, led_state);
    if (scanf("%4s", input) == 1) {
      input[strcspn(input, "\n")] = '\0';

      if (strcmp(input, "on") == 0) {
        led_state = 1;
        printf("Led on\n");
      } else if (strcmp(input, "off") == 0) {
        led_state = 0;
        printf("Led off\n");

      } else {
        printf("Unknown command\n");
      }
    } else {
      fprintf(stderr,
              "Error: Failed to read input. Please enter 'on' or 'off'.\n");
    }
  }
}
