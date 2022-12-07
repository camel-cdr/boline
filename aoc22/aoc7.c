#include "inputs/7.c"
#include "common.c"

/*
 * AOC 2022 Day 7: https://adventofcode.com/2022/day/7
 */

#define EXAMPLE 24,20,63,64,20,2f,0a,24,20,6c,73,0a,64,69,72,20,61,0a,31,34,38,34,38,35,31,34,20,62,2e,74,78,74,0a,38,35,30,34,31,35,36,20,63,2e,64,61,74,0a,64,69,72,20,64,0a,24,20,63,64,20,61,0a,24,20,6c,73,0a,64,69,72,20,65,0a,32,39,31,31,36,20,66,0a,32,35,35,37,20,67,0a,36,32,35,39,36,20,68,2e,6c,73,74,0a,24,20,63,64,20,65,0a,24,20,6c,73,0a,35,38,34,20,69,0a,24,20,63,64,20,2e,2e,0a,24,20,63,64,20,2e,2e,0a,24,20,63,64,20,64,0a,24,20,6c,73,0a,34,30,36,30,31,37,34,20,6a,0a,38,30,33,33,30,32,30,20,64,2e,6c,6f,67,0a,35,36,32,36,31,35,32,20,64,2e,65,78,74,0a,37,32,31,34,32,39,36,20,6b,0a

/*
 * parses the input into the following format:
 * B32, B32     B32     (,)          ,     B32 ...
 * ^    ^ file  ^ file  ^ directory  ^ cd  ^ file
 * |
 * the first number is the total file system size
 */

#define FILE__30 ,FILE_NEXT
#define FILE__31 ,FILE_NEXT
#define FILE__32 ,FILE_NEXT
#define FILE__33 ,FILE_NEXT
#define FILE__34 ,FILE_NEXT
#define FILE__35 ,FILE_NEXT
#define FILE__36 ,FILE_NEXT
#define FILE__37 ,FILE_NEXT
#define FILE__38 ,FILE_NEXT
#define FILE__39 ,FILE_NEXT
#define CM_0file(P,t,n,x,...) B_CHECK(FILE__##x,FILE_END)(,t,n,x,P##__VA_ARGS__)
#define FILE_END(P,t,n,x,...) (,0skipln,B32_ADD(t,n),P##__VA_ARGS__)n
#define FILE_NEXT(P,t,n,x,...) (,0file,t,B32_ADD(B32_MUL(n,B32(a)),B32(ASCII_##x)),P##__VA_ARGS__)

#define CM_0skipln(P,t,x,...) (,B_IFe(B_CHECK0(EQ_0a##x))(0parse)(0skipln),t,P##__VA_ARGS__)

#define CM_0skipln0(P,t,x,...) (,B_CATe(0skipln,B_CHECK0(EQ_0a##x)),t,P##__VA_ARGS__)
#define CM_0skipln1(P,t,x,...) (,B_IFe(B_CHECK0(EQ_24##x))(0skipln0)(0parse),t,x,P##__VA_ARGS__)

#define PARSE__0end ,PARSE_END
#define PARSE__24 ,PARSE_SKIPLN
#define PARSE__64 ,PARSE_DIR
#define CM_0parse(P,t,x,...) B_CHECK(PARSE__##x,PARSE_FILE)(,t,x,P##__VA_ARGS__)

#define PARSE_END(P,t,...) )t,
#define PARSE_FILE(P,t,...) (,0file,t,B32_0,P##__VA_ARGS__)
#define PARSE_SKIPLN(P,t,a,b,c,d,...) (,0skipln0,t,P##__VA_ARGS__),
#define PARSE_DIR(P,t,a,b,c,d,...) (,0skipln,t,P##__VA_ARGS__)(,)

#define PARSE(...) CM(,0parse,B32_0,__VA_ARGS__,0end,)

#if 0
PARSE(EXAMPLE)
#endif



/* sum directory sizes by poping an pushing them from a stack,
 * whenever a directory marker, or a cd seperator is reached */
#define MIN B32(2,6,2,5,a,0,0) // 70000000 - 30000000
#define MAX B32(1,8,6,a,0) // 100000

#define RUN_PROBE(...) ,RUN_NEXT,
#define CM_0run(P,t,m,n,c,s,x,...) B_CHECK(RUN_PROBE x,RUN_CD)(,t,m,n,c,s,x,P##__VA_ARGS__)
#define RUN_CD(P,t,m,n,c,s,x,...) (,0run,t,\
	B_IFe(B32_LE(B32_SUB(t,c),MIN))(B32_MIN(c,m))(m), \
	B_IFe(B32_LE(c,MAX))(B32_ADD(n,c))(n),\
	B32_0,c s,P##__VA_ARGS__)

#define RUN__ ,RUN_DIR,
#define RUN__0end ,RUN_END,
#define RUN_NEXT_PROBE(x,...) RUN__##x
#define SPLAT(...) (__VA_ARGS__),
#define RUN_NEXT(P,t,m,n,c,s,x,...) B_APPLY(B_CHECK(RUN_NEXT_PROBE x,RUN_FILE),(,t,m,n,c,s,SPLAT x,P##__VA_ARGS__))

#define SEQ_AT_1(x) B_FX(B_TUPLE_AT_0,SPLAT x)

#define RUN_FILE(P,t,m,n,c,s,x,xs,...) (,0run,t,m,n,B32_ADD(c,x),s,xs,P##__VA_ARGS__)
#define RUN_DIR(P,t,m,n,c,s,x,xs,...) (,0run,t,m,n,B32_ADD(c,SEQ_AT_1(s)),B_EAT s,xs,P##__VA_ARGS__)
#define RUN_END(P,t,m,n,c,s,x,xs,...) )B32_DECIMAL(n) B32_DECIMAL(m)


#define RUN2(a,...) CM(,0run,a,B32(7,f,f,f,f,f,f,f),B32_0,B32_0,,__VA_ARGS__,(0end,))
#define RUN1(...) RUN2(__VA_ARGS__)
#define RUN(...) RUN1(PARSE(__VA_ARGS__))



expected 95437 24933642, got RUN(EXAMPLE)

final result: RUN(INPUT)


