#include <ctype.h>
#include <inttypes.h>
#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void insert_max(int32_t *list, size_t len, int32_t x) {
  for (size_t i = 0; i < len; i++) {
    if (x > list[i]) {
      int32_t preivous = list[i];
      list[i] = x;
      insert_max(list, len, preivous);
      break;
    }
  }
}

int main() {
  FILE *file = fopen("input.txt", "r");

  size_t length = 0;
  size_t string_cap = 0;
#define TOP 3
  int32_t maxs[TOP] = {0};
  int32_t current_sum = 0;
  for (char *string = malloc(sizeof(char) * string_cap); length != -1;
       length = getline(&string, &string_cap, file)) {
    if (!strcmp(string, "\n")) {
      insert_max(maxs, TOP, current_sum);
      current_sum = 0;
      continue;
    }
    current_sum += atoi(string);
  }
  printf("%i %i %i\n", maxs[0], maxs[1], maxs[2]);
}
