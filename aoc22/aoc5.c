#include "inputs/5.c"
#include "common.c"

/*
 * AOC 2022 Day 5: https://adventofcode.com/2022/day/5
 */


/*
 * I've decided to ignore the example this time around, because assuming there
 * are nine containers drastically simplifies the code.
 *
 * The idea of how to parse this is the following:
 *     1. Fill 9 initial containers, by extracting the values until the
 *        second character of a line is "1".
 *     2. Rearrange containers by parsing the move commands, here we need to
 *        distinguish between the number of containers to move being one or two
 *        digits wide.
 */



/* parse the inital containers */
#define MAYBE_20_20 ,1
#define MAYBE(x) B_IFe(B_CHECK0(MAYBE_20_##x))()((ASCII_##x))

/* end if the second character after a newlien is "1"  */
#define INIT__31 ,INIT_END
#define CM_0init(P,a,b,c,d,e,f,g,h,i,_a,A,...) \
	B_CHECK(INIT__##A,INIT_NEXT)(,MAYBE,a,b,c,d,e,f,g,h,i,_a,A,P##__VA_ARGS__)

/* extract containers from line */
#define INIT_NEXT(P,M,a,b,c,d,e,f,g,h,i, \
		_a,A,_b,_c, \
		_d,B,_e,_f, \
		_g,C,_h,_i, \
		_j,D,_k,_l, \
		_m,E,_n,_o, \
		_p,F,_q,_r, \
		_s,G,_t,_u, \
		_v,H,_w,_x, \
		_y,I,_z,_0,...) \
		(,0init,a M(A),b M(B),c M(C),d M(D),e M(E),f M(F),g M(G),h M(H),i M(I),P##__VA_ARGS__)
/* consume the leftover lines, until the move commands start */
#define INIT_END_CONSUME(P,aa,ab,ac,ad,ae,af,ag,ah,ai,aj,ak,al,am,an,ao,ap,aq,ar, \
                           as,at,au,av,aw,ax,ay,az,a0,a1,a2,a3,a4,a5,a6,a7,a8,a9,...) P##__VA_ARGS__
#define INIT_END(P,M,a,b,c,d,e,f,g,h,i,...) ) (a,b,c,d,e,f,g,h,i),INIT_END_CONSUME(,P##__VA_ARGS__)

#define INIT(...) CM(,0init,,,,,,,,,,__VA_ARGS__,)



/* helpers to implement the move functions */
#define EAT(x)
#define SEQ_SPLAT(x) (x),
#define SEQ_AT_1(x) B_FX(B_TUPLE_AT_0,SEQ_SPLAT x)

#define SPLAT(x) x,
#define SEQ_AT_1_OPEN(x) B_FX(B_TUPLE_AT_0,SPLAT x)

#define REMOVE_1(a,b,c,d,e,f,g,h,i) SEQ_AT_1(a),EAT a,b,c,d,e,f,g,h,i
#define REMOVE_2(a,b,c,d,e,f,g,h,i) SEQ_AT_1(b),a,EAT b,c,d,e,f,g,h,i
#define REMOVE_3(a,b,c,d,e,f,g,h,i) SEQ_AT_1(c),a,b,EAT c,d,e,f,g,h,i
#define REMOVE_4(a,b,c,d,e,f,g,h,i) SEQ_AT_1(d),a,b,c,EAT d,e,f,g,h,i
#define REMOVE_5(a,b,c,d,e,f,g,h,i) SEQ_AT_1(e),a,b,c,d,EAT e,f,g,h,i
#define REMOVE_6(a,b,c,d,e,f,g,h,i) SEQ_AT_1(f),a,b,c,d,e,EAT f,g,h,i
#define REMOVE_7(a,b,c,d,e,f,g,h,i) SEQ_AT_1(g),a,b,c,d,e,f,EAT g,h,i
#define REMOVE_8(a,b,c,d,e,f,g,h,i) SEQ_AT_1(h),a,b,c,d,e,f,g,EAT h,i
#define REMOVE_9(a,b,c,d,e,f,g,h,i) SEQ_AT_1(i),a,b,c,d,e,f,g,h,EAT i

#define APPEND_1(X,a,b,c,d,e,f,g,h,i) X a,b,c,d,e,f,g,h,i
#define APPEND_2(X,a,b,c,d,e,f,g,h,i) a,X b,c,d,e,f,g,h,i
#define APPEND_3(X,a,b,c,d,e,f,g,h,i) a,b,X c,d,e,f,g,h,i
#define APPEND_4(X,a,b,c,d,e,f,g,h,i) a,b,c,X d,e,f,g,h,i
#define APPEND_5(X,a,b,c,d,e,f,g,h,i) a,b,c,d,X e,f,g,h,i
#define APPEND_6(X,a,b,c,d,e,f,g,h,i) a,b,c,d,e,X f,g,h,i
#define APPEND_7(X,a,b,c,d,e,f,g,h,i) a,b,c,d,e,f,X g,h,i
#define APPEND_8(X,a,b,c,d,e,f,g,h,i) a,b,c,d,e,f,g,X h,i
#define APPEND_9(X,a,b,c,d,e,f,g,h,i) a,b,c,d,e,f,g,h,X i




/* moves each container one at a time (part 1) */
#define CM_0move1(P,S,n,x,y) B_CATe(MOVE1__,B8_IS_0(n))(,S,n,x,y)
#define MOVE1__0(P,S,n,x,y) (,0move1,(B_FX(y,x S)),B8_DEC(n),x,y)
#define MOVE1__1(P,S,...) )S

#define MOVE1(S,n,x,y) CM(,0move1,S,n,B_CATe(REMOVE_,ASCII_##x),B_CATe(APPEND_,ASCII_##y))



/* moves containers simultaneously (part 2) */

#define MOVE2_REMOVE(X,a,b,c,d,e,f,g,h,i) X,(a,b,c,d,e,f,g,h,i)
#define MOVE2_APPEND(y,...) APPEND_##y(__VA_ARGS__)

#define CM_0move2(P,i,S,n,x,y) B_CATe(MOVE2__,B8_IS_0(n))(,i,S,n,x,y)
#define MOVE2__0(P,i,S,n,x,y) \
	(,0move2, \
	 i B_FX(MOVE2_REMOVE,x S), \
	 B8_DEC(n),x,y)
#define MOVE2__1(P,i,S,n,x,y) )(MOVE2_APPEND(y,i,B_OPEN S))

#define MOVE2(S,n,x,y) CM(,0move2,,S,n,B_CATe(REMOVE_,ASCII_##x),ASCII_##y)




/* call INIT and issue the apropriate move commands */
#define RUN__0end ,RUN_END
#define CM_0run(P,mv,S,a,b,c,d,e,f,g,h,i,j,k,l,m,n,o,p,q,r,s,t,...) \
	B_CHECK(RUN__##a,RUN_NEXT)(,mv,S,f,g,m,n,r,s,t,P##__VA_ARGS__)

#define RUN_END(P,mv,S,...) ) S

#define RUN_NEXT__20 ,RUN_1DIGIT
#define RUN_NEXT(P,mv,S,f,g,...) B_CHECK(RUN_NEXT__##g,RUN_2DIGIT)(,mv,S,f,g,P##__VA_ARGS__)
#define RUN_1DIGIT(P,mv,S,f,g,m,n,r,s,t,...) (,0run,mv,mv(S,B8(ASCII_##f),m,r),t,P##__VA_ARGS__)
#define RUN_2DIGIT(P,mv,S,f,g,m,n,r,s,t,...) (,0run,mv,mv(S,B8_ADD(B8_MUL(B8(a),B8(ASCII_##f)),B8(ASCII_##g)),n,s),P##__VA_ARGS__)

/* extract top most containers and concatinate them */
#define TOP(x) TOP_1 x
#define TOP_1(a,b,c,d,e,f,g,h,i) TOP_2(SEQ_AT_1_OPEN,a,b,c,d,e,f,g,h,i)
#define TOP_2(F,a,b,c,d,e,f,g,h,i) B_STRe(F(a)F(b)F(c)F(d)F(e)F(f)F(g)F(h)F(i))

#define RUN(mv,...) TOP(CM(,0run,mv,INIT(__VA_ARGS__)0end,,,,,,,,,,,,,,,,,,,,,,,,))



final result: RUN(MOVE1,INPUT) RUN(MOVE2,INPUT)



