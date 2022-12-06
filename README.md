
<p align="center"> <img width="50%" src="https://user-images.githubusercontent.com/69110542/205676165-b97bf94e-88be-404e-8b0a-1e0d72b5405f.svg"/></p>

> A low level preprocessor meta programming library.

---

## Samples

### conditionals

<table>
<tr><td><b>code.c</b></td><td><b>output</b></td></tr>
<tr><td>

```c
#include "boline/boline.c"
B_IF(1)(true)(false)
B_UNLESS(1)(true)
B_WHEN(1)(true)

#define TRUE 1
B_IFe(FALSE)(false)(true)
B_UNLESSe(FALSE)(false)
B_WHENe(FALSE)(flase)
```

</td><td>

```c
​
true

true

false
false
​
```

</td></tr></table>


### checks

<table>
<tr><td><b>code.c</b></td><td><b>output</b></td></tr>
<tr><td>

```c
#include "boline/boline.c"
#define MYWORD word
#define EQ_word_word ,1
B_CHECK0(B_CATe(EQ_word_,MYWORD))

#define BRANCH__word1 ,BRANCH_1
#define BRANCH__word2 ,BRANCH_2
B_CHECK(B_CATe(BRANCH__,MYWORD),BRANCH_DEFAULT)
```

</td><td>

```c
​
​
​
1



BRANCH_DEFAULT
```

</td></tr></table>

### boolean logic

<table>
<tr><td><b>code.c</b></td><td><b>output</b></td></tr>
<tr><td>

```c
#include "boline/boline.c"
B1_ANDe(1, B1_OR(1, 0))
B1_ANDe(1, B1_OR(0, 0))
B1_XORe(B1_NOTe(B1_ANDe(1, 0)), B1_OR(1, 1))
```

</td><td>

```c
​
1
0
0
```

</td></tr></table>

### Integer types

<table>
<tr><td><b>code.c</b></td><td><b>output</b></td></tr>
<tr><td>

```c
#include "boline/boline.c"
B8_HEX(B8(1,f))
B16_HEX(B16(1,2,3))
B32_HEX(B32(1,2,3,4,5,6))
B64_HEX(B64(1,2,3,4,5,6,7,8,9,a,b,c,d,e,f))

B8_HEX(B8_FROM_Bn(B32(1,2,3,4,5,6)))
B32_HEX(B32_FROM_Bn(B8(1,2)))

B16_HEX(B16_2(1,2))
B16_HEX(B16_0)

B16(1,2) // internal representation
```

</td><td>

```c
​
0x1f
0x0123
0x00123456
0x0123456789abcdef

0x56
0x00000012

0x0012
0x0000

(2,1,0,0)
```

</td></tr></table>

### basic math

<table>
<tr><td><b>code.c</b></td><td><b>output</b></td></tr>
<tr><td>

```c
#include "boline/boline.c"
B32_HEX(B32_ADD(B32(1,2,3), B32(1,a)))
B32_HEX(B32_MUL(B32(1,2,3), B32(1,a)))
B32_HEX(B32_UDIV(B32(1,2,3), B32(1,a)))
B32_HEX(B32_UREM(B32(1,2,3), B32(1,a)))

B32_HEX(B32_INC(B32(1,2,0)))
B32_HEX(B32_DEC(B32(1,2,0)))
B32_HEX(B32_NOT(B32(1,f,0)))
B32_HEX(B32_NEG(B32(1)))
B32_HEX(B32_ABS(B32_DEC(B32_0)))

B8_HEX(B8_AND(B8(3,7),B8(9,4)))
B8_HEX(B8_OR(B8(3,7),B8(9,4)))
B8_HEX(B8_XOR(B8(3,7),B8(9,4)))
```

</td><td>

```c
​
0x0000013d
0x00001d8e
0x0000000b
0x00000005

0x00000121
0x0000011f
0xfffffe0f
0xffffffff
0x00000001

0x14
0xb7
0xa3
```

</td></tr></table>

### Comparisons

<table>
<tr><td><b>code.c</b></td><td><b>output</b></td></tr>
<tr><td>

```c
#include "boline/boline.c"
B32_LT(B32(a,3), B32(1,2))
B32_GT(B32(a,3), B32(1,2))
B32_EQ(B32(a,3),B32(a,3))
B32_NE(B32(a,3),B32(a,3))
B32_IS_0(B32(a,3))
B32_IS_NEG(B32_DEC(B32_0))
```

</td><td>

```c
​
0
1
1
0
0
```

</td></tr></table>


### Memory


<table>
<tr><td><b>code.c</b></td><td><b>output</b></td></tr>
<tr><td>

```c
#include "/home/camel/git/boline/boline/boline.c"

M8_AT(M8_PUT(M8_PUT(,B8(4,2),Y),B8(1,2),X),B8(4,2))
M8_PUT(,B8(1,e),X)
M8_PUT(M8_PUT(M8_PUT(,B8(1,e),X),B8(1,f),Y),B8(2,0),Z)
```

</td><td>

```c
​
​
Y
(,(,,,,,,,,,,,,,,X,),,,,,,,,,,,,,,)
(,(,,,,,,,,,,,,,,X,Y),(Z,,,,,,,,,,,,,,,),,,,,,,,,,,,,)
```

</td></tr></table>


### Continuation Machine (Recursion)


<table>
<tr><td><b>code.c</b></td><td><b>output</b></td></tr>
<tr><td>

```c
#include "boline/boline.c"
#include "boline/cm.c"

#define SUM_PROPE(...) ,SUM_NEXT
#define CM_0sum(P,total,x,...) B_CHECK(SUM_PROPE x,SUM_END)(,total,x,P##__VA_ARGS__)
#define SUM_END(P,total,...) ) B16_HEX(total)
#define SUM_NEXT(P,total,x,...) (,0sum,B16_ADD(total,x),P##__VA_ARGS__)

#define SUM(...) CM(,0sum,B16_0,__VA_ARGS__,0end)

SUM(B16(1),B16(a),B16(1,2),B16(a,f),B16(1,1,1,1))
```

</td><td>

```c
​
​
​
​
​
​
​
​
​
​
0x11dd
```

</td></tr></table>


### Advent Of Code 2022 (Samples)

Check out the [Advent Of Code 2022](https://adventofcode.com/2022) solutions in [aoc22/](aoc22/).

## Licensing

This project is licensed under [LICENSE](LICENSE).

