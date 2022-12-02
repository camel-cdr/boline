#include "inputs/2.c"
#include "common.c"

/*
 * AOC 2022 Day 2: https://adventofcode.com/2022/day/2
 */


/*
 * We could've done this using arithmetic, but that would require 6 lines
 * to detect A,B,C,X,Y,Z, so we might as well hard code every combination
 * in 9 lines and be way more efficient.
 */

#define TBL1_4158 4 /* RR */
#define TBL1_4258 1 /* PR */
#define TBL1_4358 7 /* SR */
#define TBL1_4159 8 /* RP */
#define TBL1_4259 5 /* PP */
#define TBL1_4359 2 /* SP */
#define TBL1_415a 3 /* RS */
#define TBL1_425a 9 /* PS */
#define TBL1_435a 6 /* SS */

#define TBL2_4158 3 /* RS Loose */
#define TBL2_4258 1 /* PR Loose */
#define TBL2_4358 2 /* SP Loose */
#define TBL2_4159 4 /* RR Draw */
#define TBL2_4259 5 /* PP Draw */
#define TBL2_4359 6 /* SS Draw */
#define TBL2_415a 8 /* RP Win */
#define TBL2_425a 9 /* PS Win */
#define TBL2_435a 7 /* SR Win */


#define RUN__0end ,RUN_END
#define CM_0run(P,s1,s2,x,...) B_CHECK(RUN__##x,RUN_NEXT)(,s1,s2,x,P##__VA_ARGS__)

/* just sum up all scores */
#define RUN_NEXT(P,s1,s2,a,_0,b,_1,...) (,0run, \
		B32_ADD(s1,B32_1(TBL1_##a##b)), \
		B32_ADD(s2,B32_1(TBL2_##a##b)), \
		P##__VA_ARGS__)
#define RUN_END(P,s1,s2,...) ) B32_FMT(s1) B32_FMT(s2)

#define RUN(...) CM(,0run,B32_0,B32_0,__VA_ARGS__,0end,)



#define EXAMPLE 41,20,59,0a,42,20,58,0a,43,20,5a,0a
expected 0xf, got RUN(EXAMPLE)

final result: RUN(INPUT)

