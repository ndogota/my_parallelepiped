#include <unistd.h>
#include <stdio.h>
#include "my_tools.c"

int my_parallelepiped(int x, int y, int z);
void horizontal_line(int x, int y, int number);
void vertical_line(int x, int z, int lines_num);
void outside_space(int z);
void inside_space(int z);
void depth_line(int x, int y, int position);

int my_parallelepiped(int x, int y, int z)
{
  int lines_count = (y + z) - 1;

  if (z > 1) {
    outside_space(z);
  }
  horizontal_line(x, y, 1);
  my_putchar('\n');
  if (z > 1) {
    for (int i = 2, j = (z - 1); i < z; i++, j--) {
      outside_space(j);
      depth_line(x, y, 1);
      inside_space(i);
      if(z > 2 && i < y) {
        my_putchar('|');
      }
      if(i == y) {
        my_putchar('*');
      }
      my_putchar('\n');
    }
  }
  if (y > 0 && z > 1) {
    horizontal_line(x, y, 2);
    if(x == y) {
      inside_space(z);
      my_putchar('*');
    }
    else if (z < y){
      my_putchar('|');
    }
    my_putchar('\n');
  }
  for (int i = 1; i < (y - 1) && x > 2; i++) {
    vertical_line(x, z, i);
    my_putchar('\n');
  }
  if (y > 1 && z > 0) {
    horizontal_line(x, y, 3);
  }
}

void horizontal_line(int x, int y, int number)
{
  if (x != 0) {
    my_putchar('*');
  }
  for (int i = 0; i < (x - 2); i++) {
    if (x > 2) {
      my_putchar('-');
    }
    else if (x > 0 && x <= 2) {
      my_putchar('*');
    }
  }
  if (x > 1) {
    my_putchar('*');
  }
}

void vertical_line(int x, int z, int lines_num)
{
  my_putchar('|');
  for (int i = 2; i < x; i++) {
    my_putchar(' ');
  }
  my_putchar('|');
  if (z > 2, lines_num < ) {
    my_putchar('|');
  }
}

void depth_line(int x, int y, int position)
{
  if (position == 1) {
    my_putchar('/');
    for (int i = 2; i < x; i++) {
      my_putchar(' ');
    }
    if (x > 2) {
      my_putchar('/');
    }
  }
  else if (position == 2) {
    for (int i = 0; i < (y - 2); i++) {
      my_putchar(' ');
    }
    my_putchar('/');
  }
}

void inside_space(int z) {
  for(int i = 0; i < (z - 2); i++) {
    my_putchar(' ');
  }
}

void outside_space(int z) {
  for (int i = 0; i < (z - 1); i ++) {
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
