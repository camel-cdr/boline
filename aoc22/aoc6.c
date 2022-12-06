#include "inputs/6.c"
#include "common.c"

/*
 * AOC 2022 Day 6: https://adventofcode.com/2022/day/6
 */


#define CM_0distinct(P,n,m,a,...) B_IFe(B8_IS_0(n))(DISTINCT_END1)(DISTINCT_NEXT)(,n,m,B8_##a,P##__VA_ARGS__)
#define DISTINCT_END0(...) )0
#define DISTINCT_END1(...) )1
#define DISTINCT_PROBE(...) ,DISTINCT_END0
#define DISTINCT_NEXT(P,n,m,a,...) B_CHECK(B_APPLY(DISTINCT_PROBE,M8_AT(m,a)),DISTINCT_NEXT1)(,n,m,a,P##__VA_ARGS__)
#define DISTINCT_NEXT1(P,n,m,a,...) (,0distinct,B8_DEC(n),M8_PUT(m,a,()),P##__VA_ARGS__)


#define DISTINCT(P,n,...) CM(,0distinct,n,,P##__VA_ARGS__)

DISTINCT(,B8(3),77,78,79,77,78) == 1
DISTINCT(,B8(4),77,78,79,77,78) == 0



/* we assume that there always is a marker */
#define EQ(a,b) B_CHECK0(EQ_##a##b)
#define RUN__000000 ,RUN_END
#define CM_0run(P,n,cnt,A,B,C,D,E,F,G,H,I,J,K,L,M,N,O,Q,...) \
	B_IFe(DISTINCT(,n,A,B,C,D,E,F,G,H,I,J,K,L,M,N,O,Q))(RUN_END)(RUN_NEXT) \
		(,n,cnt,B,C,D,E,F,G,H,I,J,K,L,M,N,O,Q,P##__VA_ARGS__)
#define RUN_END(P,n,cnt,...) ) B16_DECIMAL(cnt)
#define RUN_NEXT(P,n,cnt,...) (,0run,n,B16_INC(cnt),P##__VA_ARGS__)

#define RUN(n,...) CM(,0run,B8(n),B16(n),__VA_ARGS__,,,,,)



#define EXAMPLE1 6d,6a,71,6a,70,71,6d,67,62,6c,6a,73,70,68,64,7a,74,6e,76,6a,66,71,77,72,63,67,73,6d,6c,62,0a
#define EXAMPLE2 62,76,77,62,6a,70,6c,62,67,76,62,68,73,72,6c,70,67,64,6d,6a,71,77,66,74,76,6e,63,7a,0a
#define EXAMPLE3 6d,6a,71,6a,70,71,6d,67,62,6c,6a,73,70,68,64,7a,74,6e,76,6a,66,71,77,72,63,67,73,6d,6c,62,0a

expected 7, got RUN(4, EXAMPLE1)
expected 5, got RUN(4, EXAMPLE2)
expected 19, got RUN(e, EXAMPLE3)

final result: RUN(4, INPUT) RUN(e, INPUT)

