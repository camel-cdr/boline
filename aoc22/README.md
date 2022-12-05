# [Advent Of Code 2022](https://adventofcode.com/2022)

This is my attempt at improving the boline library, by solving the [aoc 2022](https://adventofcode.com/2022) challenges.
The goal is to learn what features are missing and to implement these features.
Moreover, this can function as sample code, and it's in general also a personal challenge.


## The Basic Structure

Because we sadly can't parse raw files using the preprocessor, we'll be using a [script](inputs/convert.sh) to convert each days input into a comma separated list of hexadecimal bytes:

<table>
<tr><td><b>inputs/N.txt</b></td><td><b>inputs/N.c</b></td></tr>
<tr><td>

```c
Hello World
```

</td><td>

```c
#define INPUT 48,65,6c,6c,6f,20,57,6f,72,6c,64,0a
```

</td></tr></table>

The output should require as few postprocessing as possible/practical.
So an expected output of `0.6` could be output as `3/5` and still count as a valid solution.



## Development Log


* complexity:
  My personal rating of how complex the implementation was.

* loc:
  The liens of code may not correlate with my perceived complexity, as creating lookup tables is very easy, but adds a lot of lines.

* runtime:
  Runtime on my PC with `tcc -P -E`. The runtime only partially reflect the performance of boline, since the inputs we are working with are raw bytes, which you wouldn't use in usual boline applications.


| file             | complexity | loc | runtime | added features | postprocessing | godbolt                                      |
| ----             | ---------- | --- | ------- | -------------- | -------------- | -------                                      |
| [aoc1.c](aoc1.c) | 2/10       | 28  | 2.1 sec | `B<n>_MUL_B4`  | none           | [WK4zdW5vK](https://godbolt.org/z/WK4zdW5vK) |
| [aoc2.c](aoc2.c) | 1/10       | 31  | 2.8 sec |                | none           | [cKef7jPWs](https://godbolt.org/z/cKef7jPWs) |
| [aoc3.c](aoc3.c) | 9/10       | 64  | 9.2 sec | `B<n>_FROM_Bn` | none           | [ezozv1jTT](https://godbolt.org/z/ezozv1jTT) |
| [aoc4.c](aoc4.c) | 3/10       | 35  | 1.0 sec |                | none           | [8TP8zeeb1](https://godbolt.org/z/8TP8zeeb1) |
| [aoc5.c](aoc5.c) | 4/10       | 71  | 2.1 sec |                | none           | [M1bedjhEv](https://godbolt.org/z/M1bedjhEv) |

