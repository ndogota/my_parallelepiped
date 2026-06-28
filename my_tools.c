#include <unistd.h>
#include "my_tools.h"

void my_putchar(char c)
{
  write(1, &c, 1);
}

void my_putstr(const char *str)
{
	int i = 0;
	while (str[i] != '\0') {
		my_putchar(str[i]);
		i++;
	}
}
