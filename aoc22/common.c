#include "../boline/boline.c"
#include "../boline/cm.c"

/*
 * Some common utilities used in multiple aoc solutions
 */


/*
 * Helper for iterating through a large comma separated input faster.
 *
 * This construct can be used to run a nested CM on a batch of inputs at a time,
 * to reduce the overhead of copying every following input in each iteration.
 *
 * minimal usage:
 *     #define RUN__0end ,RUN_END
 *     #define RUN__0batch ,RUN_BATCH
 *     #define CM_0run(P,data,x,...) B_CHECK(RUN__##x,RUN_NEXT)(,data,x,P##__VA_ARGS__)
 *
 *     #define RUN_BATCH(P,data,...) )NEXT ,0run,(data x)
 *     #define RUN_END(P,data,...) )END (data)
 *     #define RUN_NEXT(P,data,x,...) (,0run,data x,P##__VA_ARGS__)
 *
 *     #define RUN(...) BATCH(,0run,(),__VA_ARGS__)
 *
 *     RUN(1,2,3) -> (1 2 3)
 */

#define CM_0batch(_,fx,xx,a,b,c,d,e,f,g,h,i,j,k,l,m,n,o,p,q,r,s,t,u,v,w,x,y,z, \
	                 A,B,C,D,E,F,G,H,I,J,K,L,M,N,O,P,Q,R,S,T,U,V,W,X,Y,Z,...) \
	B_CATe(BATCH__,CM(,fx,B_OPEN xx, \
		a,b,c,d,e,f,g,h,i,j,k,l,m,n,o,p,q,r,s,t,u,v,w,x,y,z, \
		A,B,C,D,E,F,G,H,I,J,K,L,M,N,O,P,Q,R,S,T,U,V,W,X,Y,Z,0batch,)),_##__VA_ARGS__)
/*
 * The user needs to ensure that the nested execution ends in either
 *     NEXT ,fx,(arguments)
 * , to handle the next batch, when the 0batch input was reached, or
 *     END (out)
 * , to signal the end of input, when the 0end input was reached.
 */
#define BATCH__NEXT BATCH_NEXT(
#define BATCH__END BATCH_END(

#define BATCH_NEXT(P,fx,xx,...) (,0batch,fx,xx,P##__VA_ARGS__)
#define BATCH_END(xx,...) )xx

/* The arguments need to be properly padded to avoid having
 * too few arguments for CM_0batch  */
#define BATCH_PADDING52 ,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,
#define BATCH_PADDING BATCH_PADDING52 BATCH_PADDING52
#define BATCH(P,fx,xx,...) CM(,0batch,fx,xx,P##__VA_ARGS__,0end,BATCH_PADDING)


/*
 * Lookup table to convert hex ASCII characters to tokens:
 */
#define ASCII_21 !
#define ASCII_25 %
#define ASCII_26 &
#define ASCII_28 (
#define ASCII_29 )
#define ASCII_2a *
#define ASCII_2b +
#define ASCII_2c ,
#define ASCII_2d -
#define ASCII_2e .
#define ASCII_2f /
#define ASCII_30 0
#define ASCII_31 1
#define ASCII_32 2
#define ASCII_33 3
#define ASCII_34 4
#define ASCII_35 5
#define ASCII_36 6
#define ASCII_37 7
#define ASCII_38 8
#define ASCII_39 9
#define ASCII_3a :
#define ASCII_3b ;
#define ASCII_3c <
#define ASCII_3d =
#define ASCII_3e >
#define ASCII_3f ?
#define ASCII_40 @
#define ASCII_41 A
#define ASCII_42 B
#define ASCII_43 C
#define ASCII_44 D
#define ASCII_45 E
#define ASCII_46 F
#define ASCII_47 G
#define ASCII_48 H
#define ASCII_49 I
#define ASCII_4a J
#define ASCII_4b K
#define ASCII_4c L
#define ASCII_4d M
#define ASCII_4e N
#define ASCII_4f O
#define ASCII_50 P
#define ASCII_51 Q
#define ASCII_52 R
#define ASCII_53 S
#define ASCII_54 T
#define ASCII_55 U
#define ASCII_56 V
#define ASCII_57 W
#define ASCII_58 X
#define ASCII_59 Y
#define ASCII_5a Z
#define ASCII_5b [
#define ASCII_5d ]
#define ASCII_5e ^
#define ASCII_5f _
#define ASCII_61 a
#define ASCII_62 b
#define ASCII_63 c
#define ASCII_64 d
#define ASCII_65 e
#define ASCII_66 f
#define ASCII_67 g
#define ASCII_68 h
#define ASCII_69 i
#define ASCII_6a j
#define ASCII_6b k
#define ASCII_6c l
#define ASCII_6d m
#define ASCII_6e n
#define ASCII_6f o
#define ASCII_70 p
#define ASCII_71 q
#define ASCII_72 r
#define ASCII_73 s
#define ASCII_74 t
#define ASCII_75 u
#define ASCII_76 v
#define ASCII_77 w
#define ASCII_78 x
#define ASCII_79 y
#define ASCII_7a z
#define ASCII_7b {
#define ASCII_7c |
#define ASCII_7d }
#define ASCII_7e ~

