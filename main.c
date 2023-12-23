#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LIMIT           2147483647  // 2^31 - 1
#define DEFAULT_LIMIT       50          // Default limit when an invalid or blank limit is provided                      
#define PRINT_NON_MATCHING  1           // Print numbers that don't match any rule?
#define ANSWER_BUFFER_SIZE  8           // How many bytes to allocate for the answer buffer. Increase if needed.

int main(int argc, char *argv[]) {

  int limit = DEFAULT_LIMIT;

  if(argc < 2) {
    printf("Warning: No limit provided. Assuming limit to be %i. Use %s [limit] to set a limit.\n\n", limit, argv[0]);
  } else {
    int user_provided_limit = atoi(argv[1]);

    if(user_provided_limit <= 0 || user_provided_limit >= MAX_LIMIT) {
      printf("Warning: Invalid limit provided (either too large or negative). Assuming limit to be %i.", limit);
    } else {
      limit = user_provided_limit;
    }
  }

  printf("Starting FizzBuzz up to %i!\n\n", limit);

  for(int i = 1; i <= limit; i++) {    
    char answer[ANSWER_BUFFER_SIZE] = {0};

    if(i % 3 == 0) strcat(answer, "Fizz");
    if(i % 5 == 0) strcat(answer, "Buzz");

    if(strlen(answer) == 0) {
      if(PRINT_NON_MATCHING == 1) printf("%i\n", i);
    } else {
      printf("%i -> %s\n", i, answer);
    }
  }

  return 0;
}
