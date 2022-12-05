
#include "inputs/4.c"
#include "common.c"

/*
 * AOC 2022 Day 4: https://adventofcode.com/2022/day/4
 */

/*
 * Instead of parsing the decimal digits properly, we can just interpret them as
 * hexadecimal, because we don't care about the exact values, only the ranges.
 * So we'll read a 13 as 0x13.
 *
 * The parsing can be simplified by filling and rotating four registers (m1..m4),
 * untill we try to rotate to an already filled up register.
 * This works especially well, because the Bn number format stors numbers in
 * reverse (LSB on the left and MSB on the right.)
 *
 *          -> (0),,,
 * 12-3,2-4 -> (1,0),,,
 *  2-3,2-4 -> (2,1,0),,,
 *   -3,2-4 -> (0),,,(2,1,0)
 *    3,2-4 -> (3,0),,,(2,1,0)
 *     ,2-4 -> (0),,(2,1,0),(3,0)
 *      2-4 -> (2,0),,(2,1,0),(3,0)
 *       -4 -> (0),(2,1,0),(3,0),(2,0)
 *        4 -> (4,0),(2,1,0),(3,0),(2,0)
 *          -> update sums
 */

/* dispatch digits to RUN_DIGIT */
#define RUN__30  ,RUN_DIGIT
#define RUN__31  ,RUN_DIGIT
#define RUN__32  ,RUN_DIGIT
#define RUN__33  ,RUN_DIGIT
#define RUN__34  ,RUN_DIGIT
#define RUN__35  ,RUN_DIGIT
#define RUN__36  ,RUN_DIGIT
#define RUN__37  ,RUN_DIGIT
#define RUN__38  ,RUN_DIGIT
#define RUN__39  ,RUN_DIGIT

#define RUN__0end ,RUN_END
#define RUN__0batch ,RUN_BATCH
#define CM_0run(P,m1,m2,m3,m4,s1,s2,x,...) B_CHECK(RUN__##x,RUN_DEFAULT)(m1,m2,m3,m4,s1,s2,x,__VA_ARGS__)

#define RUN_BATCH(m1,m2,m3,m4,s1,s2,...) )NEXT ,0run,(m1,m2,m3,m4,s1,s2)
#define RUN_END(m1,m2,m3,m4,s1,s2,...) )END (B16_DECIMAL(s1) B16_DECIMAL(s2))

/* prepend digits */
#define RUN_DIGIT(m1,m2,m3,m4,s1,s2,x,...) (,0run,(ASCII_##x,B_OPEN m1),m2,m3,m4,s1,s2,__VA_ARGS__)

/* rotate m1 to m4, unless the are allready filled, in that case update sum */
#define RUN_PROBE(...) ,RUN_UPDATE
#define RUN_DEFAULT(m1,m2,...) B_CHECK(RUN_PROBE m2,RUN_ROTATE)(m1,m2,__VA_ARGS__)

#define RUN_ROTATE(m1,m2,m3,m4,s1,s2,x,...) (,0run,(0),m3,m4,m1,s1,s2,__VA_ARGS__)

#define RUN_UPDATE(m4,m1,m2,m3,s1,s2,x,...) \
	(,0run,(0),,,, \
		RUN_UPDATE_SUMS(s1,s2,B16_FROM_Bn(m1),B16_FROM_Bn(m2),B16_FROM_Bn(m3),B16_FROM_Bn(m4)), \
	__VA_ARGS__)
#define RUN_UPDATE_SUMS(s1,s2,m1,m2,m3,m4) \
	B_IFe(CONTAINS(m1,m2,m3,m4))(B16_INC(s1))(s1), \
	B_IFe(OVERLAPS(m1,m2,m3,m4))(B16_INC(s2))(s2) \

#define CONTAINS(m1,m2,m3,m4) B1_ORqe(,B1_ANDqe(,B16_LE(m1,m3),B16_GE(m2,m4)),B1_ANDqe(,B16_LE(m3,m1),B16_GE(m4,m2)))
#define OVERLAPS(m1,m2,m3,m4) B1_NOTe(B1_ORqe(,B16_LT(m2,m3),B16_GT(m1,m4)))


#define RUN(x) BATCH(,0run,((0),,,,B16_0,B16_0),x)


#define EXAMPLE 32,2d,34,2c,36,2d,38,0a,32,2d,33,2c,34,2d,35,0a,35,2d,37,2c,37,2d,39,0a,32,2d,38,2c,33,2d,37,0a,36,2d,36,2c,34,2d,36,0a,32,2d,36,2c,34,2d,38,0a


expected 2 4, got RUN(EXAMPLE)

final result: RUN(INPUT)

