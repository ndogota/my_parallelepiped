#include <unistd.h>
#include <stdio.h>
#include "my_tools.c"

int my_parallelepiped(int x, int y, int z);
void horizontal_line(int x, int y, int number);
void vertical_lines(int x, int y, int z);
void depth_line(int x, int y, int z, int i);
void make_spaces(int i);


int my_parallelepiped(int x, int y, int z)
{
  if (z > 1) {
    make_spaces(z - 1);
    horizontal_line(x, y, 1);
    my_putchar('\n');
    if (z > 2) {
      for (int i = z; i > 2; i--) {
        make_spaces(i - 2);
        depth_line(x, y, z, i);
        my_putchar('\n');
      }
    }
  }
  if (x > 0) {
    horizontal_line(x, y, 2);
    if (y == z && x > 1) {
      make_spaces(z - 2);
      my_putchar('a');
    }
    else if (z > y && y > 1) {
      make_spaces(y - 2);
      my_putchar('/');
    }
    else if (z < y && z > 1) {
      make_spaces(z - 2);
      my_putchar('|');
    }
  }
  if (y > 1 && x > 1) {
    my_putchar('\n');
    vertical_lines(x, y, z);
  }
}

void horizontal_line(int x, int y, int number)
{
  if (x != 0) {
    my_putchar('b');
  }
  for (int i = 0; i < (x - 2); i++) {
    if (x > 2) {
      my_putchar('-');
    }
    else if (x > 0 && x <= 2) {
      my_putchar('c');
    }
  }
  if (x > 1) {
    my_putchar('d');
  }
}

void depth_line(int x, int y, int z, int i)
{
  my_putchar('/');
  make_spaces(x - 2);
  if (x > 1) {
    my_putchar('/');
  }
  if (i + y - 2 > z) {
    make_spaces(z - i);
    my_putchar('|');
  }
  else if (i + y - 2 == z) {
    make_spaces(z - i);
    my_putchar('e');
  }
  else if (i + y - 2 < z && y > 1) {
    make_spaces(y - 2);
    my_putchar('/');
  }
}

void vertical_lines(int x, int y, int z)
{
  for (int i = 0, j = z - 3; i < y - 2; i++) {
    my_putchar('|');
    make_spaces(x - 2);
    if (x > 1) {
      my_putchar('|');
      if (y < z) {
        make_spaces(j--);
        my_putchar('/');
      }
    }
    if (y > z && i < y - z - 1) {
      make_spaces(z - 2);
      my_putchar('|');
    }
    else if (i == y - z - 1) {
      make_spaces(z - 2);
      my_putchar('z');
    }
    else if (y > z && i > y - z - 1) {
      make_spaces(j--);
      my_putchar('/');
    }
    else if (y == z) {
      make_spaces(j--);
      my_putchar('/');
    }
    my_putchar('\n');
  }
}

void make_spaces(int i)
{
  for (int j = 0; j < i; j++) {
    my_putchar(' ');
  }
}

int main(int argc, char **argv)
{
  int x_input;
  int y_input;
  int z_input;

  for (int i = 0, x_input = 0, y_input = 0, z_input = 0; i != 1;) {
    printf("\ninsert the x_input :\n");
    scanf("%d", &x_input);
    printf("insert the y_input :\n");
    scanf("%d", &y_input);
    printf("insert the z_input :\n");
    scanf("%d", &z_input);
    printf("\033[H\033[2J");
    printf("x_input :%d\n", x_input);
    printf("y_input :%d\n", y_input);
    printf("z_input :%d\n\n", z_input);
    my_parallelepiped(x_input, y_input, z_input);
    printf("\n");
  }
}
