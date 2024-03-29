#include "inputs/1.c"
#include "common.c"

/*
 * AOC 2022 Day 1: https://adventofcode.com/2022/day/1
 */

/*
 * The problem can be reduced to the following three steps:
 *     1. parse decimal number:
 *         For this we just need a single register "cur", which well update
 *         with cur = (cur * 10) + x
 *     2. sum adjacent numbers:
 *         Once we reach the first newline, we need to cumulate the decimal
 *         numbers, and reset our "cur" register.
 *         For this we create another register "sum",
 *         which will be updated at ever first newline with sum += cur, cur = 0
 *     3. find the top3 highest sums:
 *         We'll use three registers "m1,m2,m3" to store the largest sums,
 *         who will be updated once we hit two newlines in a row,
 *         which happens to be when we hit a newline and cur == 0.
 */

#define RUN__0a ,RUN_NEWLINE
#define RUN__0end ,RUN_END
#define RUN__0batch ,RUN_BATCH
#define CM_0run(P,m1,m2,m3,sum,cur,x,...) B_CHECK(RUN__##x,RUN_NEXT)(m1,m2,m3,sum,cur,x,__VA_ARGS__)

#define RUN_BATCH(m1,m2,m3,sum,cur,...) )NEXT ,0run,(m1,m2,m3,sum,cur)
#define RUN_END(m1,m2,m3,sum,cur,...) )END (B32_DECIMAL(m1) B32_DECIMAL(B32_ADD(m1,B32_ADD(m2,m3))))

/* parse decimal number with cur = (cur * 10) + x */
#define RUN_NEXT(m1,m2,m3,sum,cur,x,...) (,0run,m1,m2,m3,sum, \
		/* cur */ B32_ADD(B32_MUL_B4(cur,a),B32_1(ASCII_##x)), \
		__VA_ARGS__)

/* update sum, or updated maximums depending on the value of "cur" */
#define RUN_NEWLINE(m1,m2,m3,sum,cur,x,...) (,0run, \
		B_IFe(B32_IS_0(cur))( \
			/* m1,m2,m3 */ TOP3_OF_4(m1,m2,m3,sum), \
			/* sum */ B32_0 \
		) /* else */ ( \
			/* m1,m2,m3,sum */ m1,m2,m3,B32_ADD(sum,cur) \
		), \
		/* cur */ B32_0, \
		__VA_ARGS__)

/* find the top3 largest values of 4 values */
#define TOP3_OF_4(a,b,c,d) \
	B_IFe(B32_LT(a,d))(d,a,b)( \
		B_IFe(B32_LT(b,d))(a,d,b)( \
			B_IFe(B32_LT(c,d))(a,b,d)(a,b,c)))

/* dispatch our CM_0run using the BATCH construct defined in common.c */
#define RUN(x) BATCH(,0run,(B32_0,B32_0,B32_0,B32_0,B32_0),x)


#define EXAMPLE 31,30,30,30,0a,32,30,30,30,0a,33,30,30,30,0a,0a,34,30,30,30,0a,0a,35,30,30,30,0a,36,30,30,30,0a,0a,37,30,30,30,0a,38,30,30,30,0a,39,30,30,30,0a,0a,31,30,30,30,30,0a,0a,0a,0a


expected 24000 45000, got RUN(EXAMPLE)

final result: RUN(INPUT)

