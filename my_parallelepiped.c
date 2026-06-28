#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>
#include <limits.h>
#include "my_tools.h"

int my_parallelepiped(int x, int y, int z);
void horizontal_line(int x);
void vertical_lines(int x, int y, int z);
void depth_line(int x, int y, int z, int i);
void make_spaces(int i);


int my_parallelepiped(int x, int y, int z)
{
  if (x > 0 && y > 0 && z > 0) {
    if (z > 1) {
      make_spaces(z - 1);
      horizontal_line(x);
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
      horizontal_line(x);
      if (y == z && x > 1 && z > 1) {
        make_spaces(z - 2);
        my_putchar('*');
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
    if (y > 1 && x > 0) {
      my_putchar('\n');
      vertical_lines(x, y, z);
      horizontal_line(x);
    }
    return (0);
  }
  else
    return (-1);
}

void horizontal_line(int x)
{
  if (x != 0)
    my_putchar('*');
  for (int i = 0; i < (x - 2); i++) {
    if (x > 2)
      my_putchar('-');
    else if (x > 0 && x <= 2)
      my_putchar('*');
  }
  if (x > 1)
    my_putchar('*');
}

void depth_line(int x, int y, int z, int i)
{
  my_putchar('/');
  make_spaces(x - 2);
  if (x > 1)
    my_putchar('/');
  if (i + y - 2 > z) {
    make_spaces(z - i);
    my_putchar('|');
  }
  else if (i + y - 2 == z) {
    make_spaces(z - i);
    my_putchar('*');
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
    if (x > 0) {
      if (x > 1)
        my_putchar('|');
      if (y < z) {
        make_spaces((j--) - (z - y));
        my_putchar('/');
      }
    }
    if (y > z && i < y - z - 1 && x > 1 && z > 1) {
      make_spaces(z - 2);
      my_putchar('|');
    }
    else if (i == y - z - 1) {
      make_spaces(z - 2);
      my_putchar('*');
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

enum { READ_OK, READ_QUIT, READ_BAD };

static void usage(FILE *stream, const char *prog)
{
  fprintf(stream, "Usage: %s [X Y Z]\n", prog);
  fprintf(stream, "  Draw an ASCII isometric box of width X, height Y, depth Z.\n");
  fprintf(stream, "  X, Y and Z must be positive integers.\n");
  fprintf(stream, "  With no arguments, run in interactive mode (one line per dimension,\n");
  fprintf(stream, "  empty line or 'q' to quit).\n");
}

static int parse_positive(const char *s, int *out)
{
  char *end;
  long v;

  errno = 0;
  v = strtol(s, &end, 10);
  while (*end == ' ' || *end == '\t' || *end == '\n')
    end++;
  if (end == s || *end != '\0' || errno != 0 || v <= 0 || v > INT_MAX)
    return -1;
  *out = (int)v;
  return 0;
}

static int read_dim(const char *name, int *out)
{
  char line[64];

  printf("%s: ", name);
  fflush(stdout);
  if (fgets(line, sizeof(line), stdin) == NULL)
    return READ_QUIT;
  if (line[0] == '\n' || line[0] == 'q')
    return READ_QUIT;
  if (parse_positive(line, out) != 0)
    return READ_BAD;
  return READ_OK;
}

static int interactive(void)
{
  int x = 0, y = 0, z = 0;

  for (;;) {
    int rx = read_dim("width  (x)", &x);
    if (rx == READ_QUIT)
      break;
    int ry = (rx == READ_OK) ? read_dim("height (y)", &y) : READ_BAD;
    if (ry == READ_QUIT)
      break;
    int rz = (ry == READ_OK) ? read_dim("depth  (z)", &z) : READ_BAD;
    if (rz == READ_QUIT)
      break;
    if (rx == READ_BAD || ry == READ_BAD || rz == READ_BAD) {
      fprintf(stderr, "Please enter a positive integer for each dimension.\n");
      continue;
    }
    my_parallelepiped(x, y, z);
    my_putchar('\n');
  }
  return 0;
}

int main(int argc, char **argv)
{
  int x, y, z;

  if (argc == 2 && (strcmp(argv[1], "-h") == 0 || strcmp(argv[1], "--help") == 0)) {
    usage(stdout, argv[0]);
    return 0;
  }
  if (argc == 4) {
    if (parse_positive(argv[1], &x) != 0 ||
        parse_positive(argv[2], &y) != 0 ||
        parse_positive(argv[3], &z) != 0) {
      usage(stderr, argv[0]);
      return 1;
    }
    my_parallelepiped(x, y, z);
    my_putchar('\n');
    return 0;
  }
  if (argc != 1) {
    usage(stderr, argv[0]);
    return 1;
  }
  return interactive();
}
