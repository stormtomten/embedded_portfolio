#include "pico/stdlib.h"
#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <strings.h>

#define GPIO_START 11 // Set your start gpio port
#define GPIO_COUNT 10 // Set your number of ports
#define GPIO_MASK(GPIO_START, GPIO_COUNT)                                      \
  ((((1 << (GPIO_COUNT)) - 1) << (GPIO_START))) // Generates a bitmask
#define MAX_LENGHT 10

int read_command(char *buffer, const uint32_t *mask) {
  char *delim = strchr(buffer, ' ');
  char *arg = NULL;

  if (delim != NULL) {
    *delim = '\0';
    arg = delim + 1;
  }

  if (strcmp(buffer, "ON") == 0) {
    if (arg != NULL && isdigit(arg[0])) {
      int pin = atoi(arg) % GPIO_COUNT;
      gpio_put((pin + GPIO_START), 1);
    } else {
      return 1;
    }
  } else if (strcmp(buffer, "OFF") == 0) {
    if (arg != NULL && isdigit(arg[0])) {
      int pin = atoi(arg) % GPIO_COUNT;
      gpio_put((pin + GPIO_START), 0);
    } else {
      return 1;
    }
  } else if (strcmp(buffer, "TOGGLE") == 0) {
    if (arg != NULL && isdigit(arg[0])) {
      int pin = atoi(arg) % GPIO_COUNT;
      gpio_xor_mask(1 << (pin + GPIO_START));
    } else {
      return 1;
    }
  } else if (strcmp(buffer, "ALL") == 0) {
    if (arg != NULL && strcmp(arg, "ON") == 0) {
      gpio_set_mask(*mask);
    } else if (arg != NULL && strcmp(arg, "OFF") == 0) {
      gpio_clr_mask(*mask);
    } else {
      return 1;
    }
  }

  return 0;
}
int echo_read_line(char *buffer, int max_length) {
  int index = 0, read = 1;
  char ch;

  while (read) {
    ch = getchar();
    if (ch == '\r' || ch == '\n') {
      buffer[index] = '\0';
      printf("\n");
      read = 0;
    } else if (ch == '\b' && index > 0) {
      printf("\b \b");
      index--;
    } else if (index < max_length - 1) {
      buffer[index++] = ch;
      putchar(ch);
    } else {
      printf("\n");
      return 1;
    }
  }
  return 0;
}

int main() {
  stdio_init_all();
  stdio_uart_init();
  const int start = GPIO_START;
  const uint32_t mask = GPIO_MASK(GPIO_START, GPIO_COUNT);
  gpio_init_mask(mask);
  gpio_set_dir_out_masked(mask);

  int wait = 1;
  printf("Awaiting terminal...\n");

  while (wait) {
    for (int i = 0; i < 10; i++) {
      gpio_xor_mask(1 << (i + start));
      if (getchar_timeout_us(150000) != PICO_ERROR_TIMEOUT) {
        printf("Terminal connected!\n");
        wait = 0;
        break;
      }
    }
  }

  gpio_clr_mask(mask);
  printf("\033[2J\033[H");
  printf("%*s\n", 20, "Halloj!!!!");
  printf("%*s\n", 21, "************");

  char input[MAX_LENGHT];

  while (1) {
    if (!echo_read_line(input, MAX_LENGHT)) {
      printf("Got command %s\n", input);
      if (!read_command(input, &mask)) {
      } else {
        printf("Invalid Command\n");
      }

    } else {
      printf("Too long input!\n");
    }
  }
  return 0;
}
