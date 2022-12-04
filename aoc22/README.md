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


| day         | complexity  | loc  | runtime |  added features | postprocessing |
| ----------- | ----------- | ---- | ------- | --------------- | -------------- |
| [1](aoc1.c) | 2/10        |   28 | 2.0 sec |  `B<n>_MUL_B4`  |           none |
| [2](aoc2.c) | 1/10        |   31 | 2.8 sec |                 |           none |
| [3](aoc3.c) | 9/10        |   64 | 8.9 sec |  `B<n>_FROM_Bn` |           none |

