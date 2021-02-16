#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>

void reverse(char *str)
{
  size_t i;
  char temp;
  size_t size;
  assert(str);
  size = strlen(str);
  for(i = 0; i < (size / 2); ++i)
    {
      temp = str[i];
      str[i] = str[size - 1 - i];
      str[size - 1 - i] = temp;
    }
}

int main(void) {
  char str0[] = "";
  char str1[] = "123";
  char str2[] = "abcd";
  char str3[] = "Captain's log, Stardate 42523.7";
  char str4[] = "Hello, my name is Inigo Montoya.";
  char str5[] = "You can be my wingman anyday!";
  char str6[] = "Executor Selendis! Unleash the full power of your forces! There may be no tomorrow!";
  char * array[] = {str0, str1, str2, str3, str4, str5, str6};
  for (int i = 0; i < 7; i++) {
    reverse(array[i]);
    printf("%s\n", array[i]);
    //printf("jfkdjfkldsj]n");
  }
  return EXIT_SUCCESS;
}
