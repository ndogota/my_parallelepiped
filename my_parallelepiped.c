#include <unistd.h>
#include <stdio.h>
#include "my_tools.c"

void depth_line(int x, int y, int z);
void horizontal_line(int index_num, int x, int y, int z);
int my_parallelepiped(int x, int y, int z);

int my_parallelepiped(int x, int y, int z)
{
    horizontal_line(1, x, y, z);
    printf("\n");
    if (y > 1) {
      horizontal_line(2, x, y, z);
      printf("\n");
      horizontal_line(3, x, y, z);
    }
}

void horizontal_line(int index_num, int x, int y, int z)
{
  for (int i = 1; i <= x; i++) {
    if (i == 1) {
      for (int j = 1; x > 1 && index_num == 1 && j < x; j++) {
        my_putchar(' ');
      }
      my_putchar('*');
    }
    if(i > 1 && i < x) {
      my_putchar('-');
    }
    if(i == x && x != 0 && x != 1) {
      my_putchar('*');
    }
  }
}

void depth_line(int x, int y, int z)
{
  for (int i = x; i < (y + z); i++)
  {
    printf(" ");
  }
  printf("|");
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
