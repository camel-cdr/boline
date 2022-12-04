#include "inputs/3.c"
#include "common.c"

/*
 * AOC 2022 Day 3: https://adventofcode.com/2022/day/3
 */

/*
 * I'll spare you the comments, this is a huge mess, and I'm not proud of it.
 * But it works!
 */


#define SEQ_OPEN(...) __VA_ARGS__,
#define SEQ_EXTRACT(...) (__VA_ARGS__),

#define EQ_0end_0end ,1

#define CM_0contains(P,x,y,ys) B_CAT3e(CONTAINS,B_CHECK0(x##y),B_CHECK0(EQ_0end_##y))(,x,y,P##ys)
#define CONTAINS00(P,x,y,ys) (,0contains,x,SEQ_OPEN P##ys)
#define CONTAINS10(P,x,y,ys) )y
#define CONTAINS01(P,x,y,ys) )0
#define SEQ_CONTIANS(ys,x) CM(,0contains,EQ_##x,SEQ_OPEN ys(0end))

SEQ_CONTIANS((76)(4a)(72)(77)(70)(57)(74)(77),74) == 74
SEQ_CONTIANS((76)(4a)(72)(77)(70)(57)(74)(77),nope) == 0



#define INTERSECT_0end_0end ,INTERSECT_END
#define CM_0intersect(P,xs,y,ys,rs) B_CHECK(INTERSECT_0end_##y,INTERSECT_NEXT)(,SEQ_CONTIANS(xs,y),P##xs,y,P##ys,P##rs)

#define INTERSECT_END(P,c,xs,y,ys,rs) )P##rs
#define INTERSECT_NEXT(P,c,xs,y,ys,rs) \
	(,0intersect,xs,SEQ_OPEN ys,B_WHENe(B_BOOL(c))((c))rs)


#define INTERSECT(xs,ys) CM(,0intersect,xs,SEQ_OPEN ys(0end),)

INTERSECT((76)(4a)(72)(77)(4c)(57)(74)(77)(4a)(67)(57)(72),
     (68)(63)(73)(46)(4d)(4d)(66)(46)(46)(68)(46)(4c)) == (4c)

INTERSECT((76)(4a)(72)(77)(4c)(57)(74)(77)(4a)(67)(57)(72),
     (68)(63)(57)(46)(4d)(4d)(66)(46)(46)(68)(46)(4c)) == (4c)(57)




#define SCORE_EXTRACT(x) B8_##x,
#define SCORE_SEQ(x) SCORE_SEQ_1(SCORE_EXTRACT x)
#define SCORE_SEQ_1(...) SCORE_SEQ_2(__VA_ARGS__)
#define SCORE_SEQ_2(x,...) SCORE_B8(x)
#define SCORE_B8(x) B_IFe(B8_LT(x,B8(6,1)))(B8_SUB(x,B8(2,6)))(B8_SUB(x,B8(6,0)))

#define CM_0score(P,xs,ys,len) \
	B_IFe(B8_IS_0(len)) \
	((,0intersect,xs,SEQ_OPEN ys(0end),)) \
	((,0score,xs SEQ_EXTRACT ys,B8_DEC(B8_DEC(len))))

#define SCORE(xs,len) SCORE_SEQ(CM(,0score,,xs,len))

SCORE((76)(4a)(72)(77)(70)(57)(74)(77)(4a)(67)(57)(72)(68)(63)(73)(46)(4d)(4d)(66)(46)(46)(68)(46)(70), B8(1,8)) == B8(1,0)

SCORE ((6a)(71)(48)(52)(4e)(71)(52)(6a)(71)(7a)(6a)(47)(44)(4c)(47)(4c)(72)(73)(46)(4d)(66)(46)(5a)(53)(72)(4c)(72)(46)(5a)(73)(53)(4c),B8(1,e)) == B8(2,6)




#define RUN__0a ,RUN_NEWLINE
#define RUN__0end ,RUN_END
#define RUN__0batch ,RUN_BATCH
#define CM_0run(P,xs,len,sum1,cnt,ys,sum2,x,...) B_CHECK(RUN__##x,RUN_NEXT)(,xs,len,sum1,cnt,ys,sum2,x,P##__VA_ARGS__)

#define RUN_BATCH(P,xs,len,sum1,cnt,ys,sum2,...) )NEXT ,0run,(xs,len,sum1,cnt,ys,sum2)
#define RUN_END(P,xs,len,sum1,cnt,ys,sum2,...) )END (B16_DECIMAL(sum1) \
	B16_DECIMAL(B16_ADD(sum2,B16_FROM_Bn(SCORE_SEQ(ys(26))))))

#define RUN_NEXT(P,xs,len,sum1,cnt,ys,sum2,x,...) (,0run,xs(x),B8_INC(len),sum1,cnt,ys,sum2,P##__VA_ARGS__)

#define RUN_NEWLINE(P,xs,len,sum1,cnt,ys,sum2,x,...) RUN_NEWLINE_1(,SCORE(xs,len),sum1,PART2(cnt,ys,xs,sum2),P##__VA_ARGS__)
#define RUN_NEWLINE_1(P,score,sum1,part2,...) (,0run,,B8_0,B16_ADD(B16_FROM_Bn(score),sum1),part2,P##__VA_ARGS__)


#define PART2(cnt,ys,xs,sum) \
	B_IFe(B8_IS_0(cnt))( \
		B8(2),xs,B16_ADD(sum,B16_FROM_Bn(SCORE_SEQ(ys(26)))) \
	) /* else */ ( \
		B8_DEC(cnt),INTERSECT(ys,xs),sum \
	)

/* dispatch our CM_0run using the BATCH construct defined in common.c */
#define RUN(x) BATCH(,0run,(,B8_0,B16_0,B8_0,,B16_0),x)



#define EXAMPLE 76,4a,72,77,70,57,74,77,4a,67,57,72,68,63,73,46,4d,4d,66,46,46,68,46,70,0a,6a,71,48,52,4e,71,52,6a,71,7a,6a,47,44,4c,47,4c,72,73,46,4d,66,46,5a,53,72,4c,72,46,5a,73,53,4c,0a,50,6d,6d,64,7a,71,50,72,56,76,50,77,77,54,57,42,77,67,0a,77,4d,71,76,4c,4d,5a,48,68,48,4d,76,77,4c,48,6a,62,76,63,6a,6e,6e,53,42,6e,76,54,51,46,6e,0a,74,74,67,4a,74,52,47,4a,51,63,74,54,5a,74,5a,54,0a,43,72,5a,73,4a,73,50,50,5a,73,47,7a,77,77,73,4c,77,4c,6d,70,77,4d,44,77,0a

expected 157 70, got RUN(EXAMPLE)

final result: RUN(INPUT)


