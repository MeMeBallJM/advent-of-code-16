#include <ctype.h>
#include <inttypes.h>
#include <stdbool.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
  FILE *file = fopen("input.txt", "r");

  size_t length = 0;
  size_t string_cap = 0;
  int32_t max = 0;
  int32_t current_sum = 0;
  for (char *string = malloc(sizeof(char) * string_cap); length != -1;
       length = getline(&string, &string_cap, file)) {
    if (!strcmp(string, "\n")) {
      max = current_sum > max ? current_sum : max;
      current_sum = 0;
      continue;
    }

    current_sum += atoi(string);
  }

  printf("%i\n", max);
}
