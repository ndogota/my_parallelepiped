# my_parallelepiped

An ASCII isometric box generator. Give it a width, height and depth and it draws
a wireframe parallelepiped in the terminal using `*`, `-`, `|` and `/`.

## Build

```
make
```

This produces a single binary named `parallelepiped`. The only dependency is the
C standard library. Run `make clean` to remove the binary and object files.

## Usage

Two modes.

CLI mode draws one box and exits:

```
./parallelepiped X Y Z
```

X, Y and Z are positive integers for width, height and depth. For example:

```
./parallelepiped 8 4 3
./parallelepiped 5 3 2
```

Interactive mode starts when you run it with no arguments. It prompts for each
dimension, draws the box, then repeats. Press Enter on an empty line or type `q`
to quit (it also exits cleanly on end of input):

```
./parallelepiped
```

Use `-h` or `--help` to print the usage line.

## Example

```
$ ./parallelepiped 8 4 3
  *------*
 /      /|
*------* |
|      | *
|      |/
*------*
```

## How it works

The box is drawn with a simple isometric projection: the front face is a plain
rectangle, and depth is faked by offsetting a second rectangle up and to the
right, then joining the two with diagonal `/` edges. Each row is built one
character at a time, padding with spaces so the slanted edges line up.
