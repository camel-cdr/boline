
#if B_ASSERT_ENABLE

#define TRUE 1
#define FALSE 0

#define B_ASSERT(expr,target) B_ASSERT_1(#expr, expr, target, __LINE__)
#define B_ASSERT_1(expr,result,target,line) B_ASSERT_2(expr, #result, #target, line)
#define B_ASSERT_2(expr,result,target,line) \
	if (strcmp(#result, #target)) \
		puts("ERROR in '" expr "' on "#line":\n" \
	             "\ttarget: " target "\n" \
	             "\tgot   : " result "\n");
int puts(const char *s);
int strcmp(const char *s1, const char *s2);
int main(void) {

#else
#define B_ASSERT(a,b)
#endif


// Basic Primitives

#define B_SCAN(...) __VA_ARGS__
#define B_FX(f,...) f(__VA_ARGS__)
#define B_APPLY(f,...) f __VA_ARGS__


#define B_EAT(...)

#define B_LPAREN (
#define B_RPAREN )
#define B_EMPTY()

#define B_OPENe(...) B_OPEN(__VA_ARGS__)
#define B_OPEN(...) __VA_ARGS__
#define B_OPENq(P,...) P##__VA_ARGS__
B_ASSERT(B_OPEN(0) B_OPENq(,0),0 0)

#define B_STRe(...) B_STR(__VA_ARGS__)
#define B_STR(...) #__VA_ARGS__
B_ASSERT(B_STR(TRUE) B_STRe(TRUE), "TRUE" "1")

#define B_CATe(...) B_CAT(__VA_ARGS__)
#define B_CAT(a,...) a##__VA_ARGS__
B_ASSERT(B_CAT(TRUE,FALSE) B_CATe(TRUE,FALSE),TRUEFALSE 10)

#define B_CAT2e(...) B_CAT2(__VA_ARGS__)
#define B_CAT3e(...) B_CAT3(__VA_ARGS__)
#define B_CAT4e(...) B_CAT4(__VA_ARGS__)
#define B_CAT5e(...) B_CAT5(__VA_ARGS__)
#define B_CAT6e(...) B_CAT6(__VA_ARGS__)
#define B_CAT7e(...) B_CAT7(__VA_ARGS__)
#define B_CAT8e(...) B_CAT8(__VA_ARGS__)
#define B_CAT2(a,b) a##b
#define B_CAT3(a,b,c) a##b##c
#define B_CAT4(a,b,c,d) a##b##c##d
#define B_CAT5(a,b,c,d,e) a##b##c##d##e
#define B_CAT6(a,b,c,d,e,f) a##b##c##d##e##f
#define B_CAT7(a,b,c,d,e,f,g) a##b##c##d##e##f##g
#define B_CAT8(a,b,c,d,e,f,g,h) a##b##c##d##e##f##g##h

#define B_TUPLE_AT_0(a,...) a
#define B_TUPLE_AT_1(b,a,...) a
#define B_TUPLE_AT_2(c,b,a,...) a
#define B_TUPLE_AT_3(d,c,b,a,...) a
#define B_TUPLE_AT_4(e,d,c,b,a,...) a
#define B_TUPLE_AT_8(i,h,g,f,e,d,c,b,a,...) a
#define B_TUPLE_AT_f(q,p,o,n,m,l,k,j,i,h,g,f,e,d,c,b,a,...) a

#define B_TUPLE_UNTIL_0(a,...) a
#define B_TUPLE_UNTIL_1(a,b,...) a,b
#define B_TUPLE_UNTIL_2(a,b,c,...) a,b,c
#define B_TUPLE_UNTIL_3(a,b,c,d,...) a,b,c,d
#define B_TUPLE_UNTIL_7(a,b,c,d,e,f,g,h,...) a,b,c,d,e,f,g,h
#define B_TUPLE_UNTIL_15(a,b,c,d,e,f,g,h,i,j,k,l,m,n,o,p,...) a,b,c,d,e,f,g,h,i,j,k,l,m,n,o,p

#define B_TUPLE_AFTER_0(a,...) __VA_ARGS__
#define B_TUPLE_AFTER_1(b,a,...) __VA_ARGS__
#define B_TUPLE_AFTER_2(c,b,a,...) __VA_ARGS__
#define B_TUPLE_AFTER_3(d,c,b,a,...) __VA_ARGS__


/// Conditionals

#define B_WHENe(x) B_WHEN(x)
#define B_WHEN(x) B_WHEN_##x
#define B_WHEN_1(...) __VA_ARGS__
#define B_WHEN_0(...)
B_ASSERT(B_WHENe(TRUE)(A) B_WHENe(FALSE)(A), A)

#define B_UNLESSe(x) B_UNLESS(x)
#define B_UNLESS(x) B_UNLESS_##x
#define B_UNLESS_1(...)
#define B_UNLESS_0(...) __VA_ARGS__
B_ASSERT(B_UNLESSe(TRUE)(A) B_UNLESSe(FALSE)(A), A)

#define B_IFe(x) B_IF(x)
#define B_IF(x) B_IF_##x
#define B_IF_1(...) __VA_ARGS__ B_UNLESS_1
#define B_IF_0(...) B_UNLESS_0
B_ASSERT((B_IFe(TRUE)(1,2)(0) B_IFe(FALSE)(1)(0)),(1,2 0))

/// Probing for macro existance

#define B_CHECK(...) B_TUPLE_AT_1(__VA_ARGS__,)
#define B_CHECK0(...) B_TUPLE_AT_1(__VA_ARGS__,0,)
#define B_CHECK1(...) B_TUPLE_AT_1(__VA_ARGS__,1,)

#define B_EQe(x,y) B_EQ(x,y)
#define B_EQ(x,y) B_CHECK0(x##y)
#define B_EQ_0_0 ,1
#define B_EQ_1_1 ,1
B_ASSERT(B_EQ(B_EQ_0_,0) B_EQ(B_EQ_0_,1) B_EQe(B_EQ_1_,TRUE) B_EQe(B_EQ_1_,FALSE), 1 0 1 0)

#define B_BOOLe(...) B_BOOL(__VA_ARGS__)
#define B_BOOL(x) B_CHECK1(B_BOOL_0_##x)
#define B_BOOL_0_0 ,0
B_ASSERT(B_BOOL(0) B_BOOLe(FALSE) B_BOOL(1) B_BOOLe(TRUE) B_BOOLe(a b), 0 0 1 1 1)

// Arithmetics

/// Boolean arithmetics

#define B1_NOT_0 1
#define B1_NOT_1 0
#define B1_NOT(x) B1_NOT_##x
#define B1_NOTe(x) B1_NOT(x)

#define B1_AND_00 0
#define B1_AND_01 0
#define B1_AND_10 0
#define B1_AND_11 1
#define B1_AND(x,y) B1_AND_##x##y
#define B1_ANDe(x,y) B1_AND(x,y)

#define B1_OR_00 0
#define B1_OR_01 1
#define B1_OR_10 1
#define B1_OR_11 1
#define B1_OR(x,y) B1_OR_##x##y
#define B1_ORe(x,y) B1_OR(x,y)

#define B1_XOR_00 0
#define B1_XOR_01 1
#define B1_XOR_10 1
#define B1_XOR_11 0
#define B1_XOR(x,y) B1_XOR_##x##y
#define B1_XORe(x,y) B1_XOR(x,y)

B_ASSERT(B1_XORe(B1_NOTe(B1_ANDe(TRUE, FALSE)), B1_OR(1, 1)),0)


//// short circuiting

#define B1_ANDq_0(x) 0
#define B1_ANDq_1(x) x
#define B1_ANDq(P,x,y) B1_ANDq_##x(P##y)
#define B1_ANDqe(P,x,y) B1_ANDq(,x,P##y)

#define B1_ORq_0(x) x
#define B1_ORq_1(x) 1
#define B1_ORq(P,x,y) B1_ORq_##x(P##y)
#define B1_ORqe(P,x,y) B1_ORq(,x,P##y)

B_ASSERT(B1_ANDqe(,0,B_RPAREN) B1_ORqe(,1,B_RPAREN),0 1)



/// B4 tables

//// Lookup helper

#define B4_AT_0(a,...) a
#define B4_AT_1(a,b,...) b
#define B4_AT_2(a,b,c,...) c
#define B4_AT_3(a,b,c,d,...) d
#define B4_AT_4(a,b,c,d,e,...) e
#define B4_AT_5(a,b,c,d,e,f,...) f
#define B4_AT_6(a,b,c,d,e,f,g,...) g
#define B4_AT_7(a,b,c,d,e,f,g,h,...) h
#define B4_AT_8(a,b,c,d,e,f,g,h,i,...) i
#define B4_AT_9(a,b,c,d,e,f,g,h,i,j,...) j
#define B4_AT_a(a,b,c,d,e,f,g,h,i,j,k,...) k
#define B4_AT_b(a,b,c,d,e,f,g,h,i,j,k,l,...) l
#define B4_AT_c(a,b,c,d,e,f,g,h,i,j,k,l,m,...) m
#define B4_AT_d(a,b,c,d,e,f,g,h,i,j,k,l,m,n,...) n
#define B4_AT_e(a,b,c,d,e,f,g,h,i,j,k,l,m,n,o,...) o
#define B4_AT_f(a,b,c,d,e,f,g,h,i,j,k,l,m,n,o,p) p

//// Addition

#define B4_ADD(C,x,y) B4_ADD_##x##C(B4_AT_##y)
#define B4_ADDC(C,x,y) B4_ADDC_##x##C(B4_AT_##y)

#define B4_ADDe(...) B4_ADD(__VA_ARGS__)
#define B4_ADDCe(...) B4_ADDC(__VA_ARGS__)

#define B4_ADD_0(F) F(0,1,2,3,4,5,6,7,8,9,a,b,c,d,e,f)
#define B4_ADD_1(F) F(1,2,3,4,5,6,7,8,9,a,b,c,d,e,f,0)
#define B4_ADD_2(F) F(2,3,4,5,6,7,8,9,a,b,c,d,e,f,0,1)
#define B4_ADD_3(F) F(3,4,5,6,7,8,9,a,b,c,d,e,f,0,1,2)
#define B4_ADD_4(F) F(4,5,6,7,8,9,a,b,c,d,e,f,0,1,2,3)
#define B4_ADD_5(F) F(5,6,7,8,9,a,b,c,d,e,f,0,1,2,3,4)
#define B4_ADD_6(F) F(6,7,8,9,a,b,c,d,e,f,0,1,2,3,4,5)
#define B4_ADD_7(F) F(7,8,9,a,b,c,d,e,f,0,1,2,3,4,5,6)
#define B4_ADD_8(F) F(8,9,a,b,c,d,e,f,0,1,2,3,4,5,6,7)
#define B4_ADD_9(F) F(9,a,b,c,d,e,f,0,1,2,3,4,5,6,7,8)
#define B4_ADD_a(F) F(a,b,c,d,e,f,0,1,2,3,4,5,6,7,8,9)
#define B4_ADD_b(F) F(b,c,d,e,f,0,1,2,3,4,5,6,7,8,9,a)
#define B4_ADD_c(F) F(c,d,e,f,0,1,2,3,4,5,6,7,8,9,a,b)
#define B4_ADD_d(F) F(d,e,f,0,1,2,3,4,5,6,7,8,9,a,b,c)
#define B4_ADD_e(F) F(e,f,0,1,2,3,4,5,6,7,8,9,a,b,c,d)
#define B4_ADD_f(F) F(f,0,1,2,3,4,5,6,7,8,9,a,b,c,d,e)
#define B4_ADDC_0(F)
#define B4_ADDC_1(F) F(,,,,,,,,,,,,,,,1)
#define B4_ADDC_2(F) F(,,,,,,,,,,,,,,1,1)
#define B4_ADDC_3(F) F(,,,,,,,,,,,,,1,1,1)
#define B4_ADDC_4(F) F(,,,,,,,,,,,,1,1,1,1)
#define B4_ADDC_5(F) F(,,,,,,,,,,,1,1,1,1,1)
#define B4_ADDC_6(F) F(,,,,,,,,,,1,1,1,1,1,1)
#define B4_ADDC_7(F) F(,,,,,,,,,1,1,1,1,1,1,1)
#define B4_ADDC_8(F) F(,,,,,,,,1,1,1,1,1,1,1,1)
#define B4_ADDC_9(F) F(,,,,,,,1,1,1,1,1,1,1,1,1)
#define B4_ADDC_a(F) F(,,,,,,1,1,1,1,1,1,1,1,1,1)
#define B4_ADDC_b(F) F(,,,,,1,1,1,1,1,1,1,1,1,1,1)
#define B4_ADDC_c(F) F(,,,,1,1,1,1,1,1,1,1,1,1,1,1)
#define B4_ADDC_d(F) F(,,,1,1,1,1,1,1,1,1,1,1,1,1,1)
#define B4_ADDC_e(F) F(,,1,1,1,1,1,1,1,1,1,1,1,1,1,1)
#define B4_ADDC_f(F) F(,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1)

#define B4_ADD_01(F) F(1,2,3,4,5,6,7,8,9,a,b,c,d,e,f,0)
#define B4_ADD_11(F) F(2,3,4,5,6,7,8,9,a,b,c,d,e,f,0,1)
#define B4_ADD_21(F) F(3,4,5,6,7,8,9,a,b,c,d,e,f,0,1,2)
#define B4_ADD_31(F) F(4,5,6,7,8,9,a,b,c,d,e,f,0,1,2,3)
#define B4_ADD_41(F) F(5,6,7,8,9,a,b,c,d,e,f,0,1,2,3,4)
#define B4_ADD_51(F) F(6,7,8,9,a,b,c,d,e,f,0,1,2,3,4,5)
#define B4_ADD_61(F) F(7,8,9,a,b,c,d,e,f,0,1,2,3,4,5,6)
#define B4_ADD_71(F) F(8,9,a,b,c,d,e,f,0,1,2,3,4,5,6,7)
#define B4_ADD_81(F) F(9,a,b,c,d,e,f,0,1,2,3,4,5,6,7,8)
#define B4_ADD_91(F) F(a,b,c,d,e,f,0,1,2,3,4,5,6,7,8,9)
#define B4_ADD_a1(F) F(b,c,d,e,f,0,1,2,3,4,5,6,7,8,9,a)
#define B4_ADD_b1(F) F(c,d,e,f,0,1,2,3,4,5,6,7,8,9,a,b)
#define B4_ADD_c1(F) F(d,e,f,0,1,2,3,4,5,6,7,8,9,a,b,c)
#define B4_ADD_d1(F) F(e,f,0,1,2,3,4,5,6,7,8,9,a,b,c,d)
#define B4_ADD_e1(F) F(f,0,1,2,3,4,5,6,7,8,9,a,b,c,d,e)
#define B4_ADD_f1(F) F(0,1,2,3,4,5,6,7,8,9,a,b,c,d,e,f)
#define B4_ADDC_01(F) F(,,,,,,,,,,,,,,,1)
#define B4_ADDC_11(F) F(,,,,,,,,,,,,,,1,1)
#define B4_ADDC_21(F) F(,,,,,,,,,,,,,1,1,1)
#define B4_ADDC_31(F) F(,,,,,,,,,,,,1,1,1,1)
#define B4_ADDC_41(F) F(,,,,,,,,,,,1,1,1,1,1)
#define B4_ADDC_51(F) F(,,,,,,,,,,1,1,1,1,1,1)
#define B4_ADDC_61(F) F(,,,,,,,,,1,1,1,1,1,1,1)
#define B4_ADDC_71(F) F(,,,,,,,,1,1,1,1,1,1,1,1)
#define B4_ADDC_81(F) F(,,,,,,,1,1,1,1,1,1,1,1,1)
#define B4_ADDC_91(F) F(,,,,,,1,1,1,1,1,1,1,1,1,1)
#define B4_ADDC_a1(F) F(,,,,,1,1,1,1,1,1,1,1,1,1,1)
#define B4_ADDC_b1(F) F(,,,,1,1,1,1,1,1,1,1,1,1,1,1)
#define B4_ADDC_c1(F) F(,,,1,1,1,1,1,1,1,1,1,1,1,1,1)
#define B4_ADDC_d1(F) F(,,1,1,1,1,1,1,1,1,1,1,1,1,1,1)
#define B4_ADDC_e1(F) F(,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1)
#define B4_ADDC_f1(F) 1

B_ASSERT(B4_ADD(,a,a) B4_ADDC(,a,a),4 1)
B_ASSERT(B4_ADD(1,2,c) B4_ADDC(1,2,c),f )

//// Multiplication

#define B4_MUL(x,y) B4_MUL_##x(B4_AT_##y)
#define B4_MULC(x,y) B4_MULC_##x(B4_AT_##y)

#define B4_MULe(...) B4_MUL(__VA_ARGS__)
#define B4_MULCe(...) B4_MULC(__VA_ARGS__)

#define B4_MUL_0(F) 0
#define B4_MUL_1(F) F(0,1,2,3,4,5,6,7,8,9,a,b,c,d,e,f)
#define B4_MUL_2(F) F(0,2,4,6,8,a,c,e,0,2,4,6,8,a,c,e)
#define B4_MUL_3(F) F(0,3,6,9,c,f,2,5,8,b,e,1,4,7,a,d)
#define B4_MUL_4(F) F(0,4,8,c,0,4,8,c,0,4,8,c,0,4,8,c)
#define B4_MUL_5(F) F(0,5,a,f,4,9,e,3,8,d,2,7,c,1,6,b)
#define B4_MUL_6(F) F(0,6,c,2,8,e,4,a,0,6,c,2,8,e,4,a)
#define B4_MUL_7(F) F(0,7,e,5,c,3,a,1,8,f,6,d,4,b,2,9)
#define B4_MUL_8(F) F(0,8,0,8,0,8,0,8,0,8,0,8,0,8,0,8)
#define B4_MUL_9(F) F(0,9,2,b,4,d,6,f,8,1,a,3,c,5,e,7)
#define B4_MUL_a(F) F(0,a,4,e,8,2,c,6,0,a,4,e,8,2,c,6)
#define B4_MUL_b(F) F(0,b,6,1,c,7,2,d,8,3,e,9,4,f,a,5)
#define B4_MUL_c(F) F(0,c,8,4,0,c,8,4,0,c,8,4,0,c,8,4)
#define B4_MUL_d(F) F(0,d,a,7,4,1,e,b,8,5,2,f,c,9,6,3)
#define B4_MUL_e(F) F(0,e,c,a,8,6,4,2,0,e,c,a,8,6,4,2)
#define B4_MUL_f(F) F(0,f,e,d,c,b,a,9,8,7,6,5,4,3,2,1)

#define B4_MULC_0(F) 0
#define B4_MULC_1(F) 0
#define B4_MULC_2(F) F(0,0,0,0,0,0,0,0,1,1,1,1,1,1,1,1)
#define B4_MULC_3(F) F(0,0,0,0,0,0,1,1,1,1,1,2,2,2,2,2)
#define B4_MULC_4(F) F(0,0,0,0,1,1,1,1,2,2,2,2,3,3,3,3)
#define B4_MULC_5(F) F(0,0,0,0,1,1,1,2,2,2,3,3,3,4,4,4)
#define B4_MULC_6(F) F(0,0,0,1,1,1,2,2,3,3,3,4,4,4,5,5)
#define B4_MULC_7(F) F(0,0,0,1,1,2,2,3,3,3,4,4,5,5,6,6)
#define B4_MULC_8(F) F(0,0,1,1,2,2,3,3,4,4,5,5,6,6,7,7)
#define B4_MULC_9(F) F(0,0,1,1,2,2,3,3,4,5,5,6,6,7,7,8)
#define B4_MULC_a(F) F(0,0,1,1,2,3,3,4,5,5,6,6,7,8,8,9)
#define B4_MULC_b(F) F(0,0,1,2,2,3,4,4,5,6,6,7,8,8,9,a)
#define B4_MULC_c(F) F(0,0,1,2,3,3,4,5,6,6,7,8,9,9,a,b)
#define B4_MULC_d(F) F(0,0,1,2,3,4,4,5,6,7,8,8,9,a,b,c)
#define B4_MULC_e(F) F(0,0,1,2,3,4,5,6,7,7,8,9,a,b,c,d)
#define B4_MULC_f(F) F(0,0,1,2,3,4,5,6,7,8,9,a,b,c,d,e)

B_ASSERT(B4_MUL(2,2) B4_MULC(2,2),4 0)
B_ASSERT(B4_MUL(f,e) B4_MULC(c,e),2 a)

//// INC/DEC if C

#define B4_INC(C,x) B4_ADD_0##C(B4_AT_##x)
#define B4_INCC(C,x) B4_ADDC_0##C(B4_AT_##x)

#define B4_INCe(...) B4_INC(__VA_ARGS__)
#define B4_INCCe(...) B4_INCC(__VA_ARGS__)


#define B4_DEC(C,x) B4_DEC_##C(x)
#define B4_DECC(C,x) B4_DECC_##C(x)

#define B4_DECe(...) B4_DEC(__VA_ARGS__)
#define B4_DECCe(...) B4_DECC(__VA_ARGS__)

#define B4_DEC_(x) x
#define B4_DECC_(x)
#define B4_DEC_1(x) B4_AT_##x(f,0,1,2,3,4,5,6,7,8,9,a,b,c,d,e)
#define B4_DECC_1(x) B4_AT_##x(1,,,,,,,,,,,,,,,)

B_ASSERT(B4_INC(1,2) B4_INCe(1,B4_INC(1,1)),3 3)
B_ASSERT(B4_DEC(1,3) B4_DECe(1,B4_DEC(1,3)),2 1)

//// NOT

#define B4_NOT(x) B4_AT_##x(f,e,d,c,b,a,9,8,7,6,5,4,3,2,1,0)
#define B4_NOTe(x) B4_NOT(x)

B_ASSERT(B4_NOT(0) B4_NOT(4),f b)


//// cnverting to and from binary

#define B4_TO_B1_0 0,0,0,0
#define B4_TO_B1_1 1,0,0,0
#define B4_TO_B1_2 0,1,0,0
#define B4_TO_B1_3 1,1,0,0
#define B4_TO_B1_4 0,0,1,0
#define B4_TO_B1_5 1,0,1,0
#define B4_TO_B1_6 0,1,1,0
#define B4_TO_B1_7 1,1,1,0
#define B4_TO_B1_8 0,0,0,1
#define B4_TO_B1_9 1,0,0,1
#define B4_TO_B1_a 0,1,0,1
#define B4_TO_B1_b 1,1,0,1
#define B4_TO_B1_c 0,0,1,1
#define B4_TO_B1_d 1,0,1,1
#define B4_TO_B1_e 0,1,1,1
#define B4_TO_B1_f 1,1,1,1

#define B4_FROM_B1_0000 0
#define B4_FROM_B1_0001 1
#define B4_FROM_B1_0010 2
#define B4_FROM_B1_0011 3
#define B4_FROM_B1_0100 4
#define B4_FROM_B1_0101 5
#define B4_FROM_B1_0110 6
#define B4_FROM_B1_0111 7
#define B4_FROM_B1_1000 8
#define B4_FROM_B1_1001 9
#define B4_FROM_B1_1010 a
#define B4_FROM_B1_1011 b
#define B4_FROM_B1_1100 c
#define B4_FROM_B1_1101 d
#define B4_FROM_B1_1110 e
#define B4_FROM_B1_1111 f

//// Bitwise binary operations

#define B4_AND(x,y) B4_AND_##x(B4_AT_##y)
#define B4_OR(x,y)  B4_OR_##x (B4_AT_##y)
#define B4_XOR(x,y) B4_XOR_##x(B4_AT_##y)

#define B4_ANDe(...) B4_AND(__VA_ARGS__)
#define B4_ORe(...)  B4_OR(__VA_ARGS__)
#define B4_XORe(...) B4_XOR(__VA_ARGS__)

#define B4_AND_0(F) F(0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0)
#define B4_AND_1(F) F(0,1,0,1,0,1,0,1,0,1,0,1,0,1,0,1)
#define B4_AND_2(F) F(0,0,2,2,0,0,2,2,0,0,2,2,0,0,2,2)
#define B4_AND_3(F) F(0,1,2,3,0,1,2,3,0,1,2,3,0,1,2,3)
#define B4_AND_4(F) F(0,0,0,0,4,4,4,4,0,0,0,0,4,4,4,4)
#define B4_AND_5(F) F(0,1,0,1,4,5,4,5,0,1,0,1,4,5,4,5)
#define B4_AND_6(F) F(0,0,2,2,4,4,6,6,0,0,2,2,4,4,6,6)
#define B4_AND_7(F) F(0,1,2,3,4,5,6,7,0,1,2,3,4,5,6,7)
#define B4_AND_8(F) F(0,0,0,0,0,0,0,0,8,8,8,8,8,8,8,8)
#define B4_AND_9(F) F(0,1,0,1,0,1,0,1,8,9,8,9,8,9,8,9)
#define B4_AND_a(F) F(0,0,2,2,0,0,2,2,8,8,a,a,8,8,a,a)
#define B4_AND_b(F) F(0,1,2,3,0,1,2,3,8,9,a,b,8,9,a,b)
#define B4_AND_c(F) F(0,0,0,0,4,4,4,4,8,8,8,8,c,c,c,c)
#define B4_AND_d(F) F(0,1,0,1,4,5,4,5,8,9,8,9,c,d,c,d)
#define B4_AND_e(F) F(0,0,2,2,4,4,6,6,8,8,a,a,c,c,e,e)
#define B4_AND_f(F) F(0,1,2,3,4,5,6,7,8,9,a,b,c,d,e,f)

#define B4_OR_0(F) F(0,1,2,3,4,5,6,7,8,9,a,b,c,d,e,f)
#define B4_OR_1(F) F(1,1,3,3,5,5,7,7,9,9,b,b,d,d,f,f)
#define B4_OR_2(F) F(2,3,2,3,6,7,6,7,a,b,a,b,e,f,e,f)
#define B4_OR_3(F) F(3,3,3,3,7,7,7,7,b,b,b,b,f,f,f,f)
#define B4_OR_4(F) F(4,5,6,7,4,5,6,7,c,d,e,f,c,d,e,f)
#define B4_OR_5(F) F(5,5,7,7,5,5,7,7,d,d,f,f,d,d,f,f)
#define B4_OR_6(F) F(6,7,6,7,6,7,6,7,e,f,e,f,e,f,e,f)
#define B4_OR_7(F) F(7,7,7,7,7,7,7,7,f,f,f,f,f,f,f,f)
#define B4_OR_8(F) F(8,9,a,b,c,d,e,f,8,9,a,b,c,d,e,f)
#define B4_OR_9(F) F(9,9,b,b,d,d,f,f,9,9,b,b,d,d,f,f)
#define B4_OR_a(F) F(a,b,a,b,e,f,e,f,a,b,a,b,e,f,e,f)
#define B4_OR_b(F) F(b,b,b,b,f,f,f,f,b,b,b,b,f,f,f,f)
#define B4_OR_c(F) F(c,d,e,f,c,d,e,f,c,d,e,f,c,d,e,f)
#define B4_OR_d(F) F(d,d,f,f,d,d,f,f,d,d,f,f,d,d,f,f)
#define B4_OR_e(F) F(e,f,e,f,e,f,e,f,e,f,e,f,e,f,e,f)
#define B4_OR_f(F) F(f,f,f,f,f,f,f,f,f,f,f,f,f,f,f,f)

#define B4_XOR_0(F) F(0,1,2,3,4,5,6,7,8,9,a,b,c,d,e,f)
#define B4_XOR_1(F) F(1,0,3,2,5,4,7,6,9,8,b,a,d,c,f,e)
#define B4_XOR_2(F) F(2,3,0,1,6,7,4,5,a,b,8,9,e,f,c,d)
#define B4_XOR_3(F) F(3,2,1,0,7,6,5,4,b,a,9,8,f,e,d,c)
#define B4_XOR_4(F) F(4,5,6,7,0,1,2,3,c,d,e,f,8,9,a,b)
#define B4_XOR_5(F) F(5,4,7,6,1,0,3,2,d,c,f,e,9,8,b,a)
#define B4_XOR_6(F) F(6,7,4,5,2,3,0,1,e,f,c,d,a,b,8,9)
#define B4_XOR_7(F) F(7,6,5,4,3,2,1,0,f,e,d,c,b,a,9,8)
#define B4_XOR_8(F) F(8,9,a,b,c,d,e,f,0,1,2,3,4,5,6,7)
#define B4_XOR_9(F) F(9,8,b,a,d,c,f,e,1,0,3,2,5,4,7,6)
#define B4_XOR_a(F) F(a,b,8,9,e,f,c,d,2,3,0,1,6,7,4,5)
#define B4_XOR_b(F) F(b,a,9,8,f,e,d,c,3,2,1,0,7,6,5,4)
#define B4_XOR_c(F) F(c,d,e,f,8,9,a,b,4,5,6,7,0,1,2,3)
#define B4_XOR_d(F) F(d,c,f,e,9,8,b,a,5,4,7,6,1,0,3,2)
#define B4_XOR_e(F) F(e,f,c,d,a,b,8,9,6,7,4,5,2,3,0,1)
#define B4_XOR_f(F) F(f,e,d,c,b,a,9,8,7,6,5,4,3,2,1,0)

B_ASSERT(B4_AND(e,6) B4_OR(e,6) B4_XOR(e,6),6 e 8)


/// Constructors / Formatting

#define B8(...)  B_CATe(B8_,B_TUPLE_AT_2(__VA_ARGS__,2,1,))(__VA_ARGS__)
#define B16(...) B_CATe(B16_,B_TUPLE_AT_4(__VA_ARGS__,4,3,2,1,))(__VA_ARGS__)
#define B32(...) B_CATe(B32_,B_TUPLE_AT_8(__VA_ARGS__,8,7,6,5,4,3,2,1,))(__VA_ARGS__)
#define B64(...) B_CATe(B64_,B_TUPLE_AT_f(__VA_ARGS__,16,15,14,13,12,11,10,9,8,7,6,5,4,3,2,1,))(__VA_ARGS__)

#define B8_2(b,a) (a,b)
#define B8_1(a) (a,0)
#define B8_0 (0,0)

#define B16_4(d,c,b,a) (a,b,c,d)
#define B16_3(c,b,a) (a,b,c,0)
#define B16_2(b,a) (a,b,0,0)
#define B16_1(a) (a,0,0,0)
#define B16_0 (0,0,0,0)


#define B32_8(h,g,f,e,d,c,b,a) (a,b,c,d,e,f,g,h)
#define B32_7(g,f,e,d,c,b,a) (a,b,c,d,e,f,g,0)
#define B32_6(f,e,d,c,b,a) (a,b,c,d,e,f,0,0)
#define B32_5(e,d,c,b,a) (a,b,c,d,e,0,0,0)
#define B32_4(d,c,b,a) (a,b,c,d,0,0,0,0)
#define B32_3(c,b,a) (a,b,c,0,0,0,0,0)
#define B32_2(b,a) (a,b,0,0,0,0,0,0)
#define B32_1(a) (a,0,0,0,0,0,0,0)
#define B32_0 (0,0,0,0,0,0,0,0)

#define B64_16(p,o,n,m,l,k,j,i,h,g,f,e,d,c,b,a) (a,b,c,d,e,f,g,h,i,j,k,l,m,n,o,p)
#define B64_15(o,n,m,l,k,j,i,h,g,f,e,d,c,b,a) (a,b,c,d,e,f,g,h,i,j,k,l,m,n,o,0)
#define B64_14(n,m,l,k,j,i,h,g,f,e,d,c,b,a) (a,b,c,d,e,f,g,h,i,j,k,l,m,n,0,0)
#define B64_13(m,l,k,j,i,h,g,f,e,d,c,b,a) (a,b,c,d,e,f,g,h,i,j,k,l,m,0,0,0)
#define B64_12(l,k,j,i,h,g,f,e,d,c,b,a) (a,b,c,d,e,f,g,h,i,j,k,l,0,0,0,0)
#define B64_11(k,j,i,h,g,f,e,d,c,b,a) (a,b,c,d,e,f,g,h,i,j,k,0,0,0,0,0)
#define B64_10(j,i,h,g,f,e,d,c,b,a) (a,b,c,d,e,f,g,h,i,j,0,0,0,0,0,0)
#define B64_9(i,h,g,f,e,d,c,b,a) (a,b,c,d,e,f,g,h,i,0,0,0,0,0,0,0)
#define B64_8(h,g,f,e,d,c,b,a) (a,b,c,d,e,f,g,h,0,0,0,0,0,0,0,0)
#define B64_7(g,f,e,d,c,b,a) (a,b,c,d,e,f,g,0,0,0,0,0,0,0,0,0)
#define B64_6(f,e,d,c,b,a) (a,b,c,d,e,f,0,0,0,0,0,0,0,0,0,0)
#define B64_5(e,d,c,b,a) (a,b,c,d,e,0,0,0,0,0,0,0,0,0,0,0)
#define B64_4(d,c,b,a) (a,b,c,d,0,0,0,0,0,0,0,0,0,0,0,0)
#define B64_3(c,b,a) (a,b,c,0,0,0,0,0,0,0,0,0,0,0,0,0)
#define B64_2(b,a) (a,b,0,0,0,0,0,0,0,0,0,0,0,0,0,0)
#define B64_1(a) (a,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0)
#define B64_0 (0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0)

#define B8_HEX(x) B_CATe(0x,B8_MERGE x)
#define B16_HEX(x) B_CATe(0x,B16_MERGE x)
#define B32_HEX(x) B_CATe(0x,B32_MERGE x)
#define B64_HEX(x) B_CATe(0x,B64_MERGE x)


#define B8_MERGE(a,b) b##a
#define B16_MERGE(a,b,c,d) d##c##b##a
#define B32_MERGE(a,b,c,d,e,f,g,h) h##g##f##e##d##c##b##a
#define B64_MERGE(a,b,c,d,e,f,g,h,i,j,k,l,m,n,o,p) p##o##n##m##l##k##j##i##h##g##f##e##d##c##b##a



#define B8_FROM_Bn_(b) (B_TUPLE_UNTIL_1(b,0,))
#define B16_FROM_Bn_(b) (B_TUPLE_UNTIL_3(b,0,0,0,))
#define B32_FROM_Bn_(b) (B_TUPLE_UNTIL_7(b,0,0,0,0,0,0,0,))
#define B64_FROM_Bn_(b) (B_TUPLE_UNTIL_15(b,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,))

#define B8_FROM_Bn(b) B8_FROM_Bn_(B_OPENe b)
#define B16_FROM_Bn(b) B16_FROM_Bn_(B_OPENe b)
#define B32_FROM_Bn(b) B32_FROM_Bn_(B_OPENe b)
#define B64_FROM_Bn(b) B64_FROM_Bn_(B_OPENe b)

B_ASSERT(B8_HEX(B8_FROM_Bn(B16(1,2,3))), B8_HEX(B8(2,3)))
B_ASSERT(B16_HEX(B16_FROM_Bn(B16(1,2,3))), B16_HEX(B16(1,2,3)))
B_ASSERT(B32_HEX(B32_FROM_Bn(B16(1,2,3))), B32_HEX(B32(1,2,3)))
B_ASSERT(B64_HEX(B64_FROM_Bn(B16(1,2,3))), B64_HEX(B64(1,2,3)))


/// IS_0/IS_NEG

#define B8_IS_0_00 ,1
#define B16_IS_0_0000 ,1
#define B32_IS_0_00000000 ,1
#define B64_IS_0_0000000000000000 ,1

#define B8_IS_0r(a,b) B_CHECK0(B8_IS_0_##a##b)
#define B16_IS_0r(a,b,c,d) B_CHECK0(B16_IS_0_##a##b##c##d)
#define B32_IS_0r(a,b,c,d,e,f,g,h) B_CHECK0(B32_IS_0_##a##b##c##d##e##f##g##h)
#define B64_IS_0r(a,b,c,d,e,f,g,h,i,j,k,l,m,n,o,p) \
	B_CHECK0(B64_IS_0_##a##b##c##d##e##f##g##h##i##j##k##l##m##n##o##p)
#define B8_IS_0(x) B8_IS_0r x
#define B16_IS_0(x) B16_IS_0r x
#define B32_IS_0(x) B32_IS_0r x
#define B64_IS_0(x) B64_IS_0r x

B_ASSERT(B8_IS_0(B8(0,0)) B8_IS_0(B8(1,0)), 1 0)
B_ASSERT(B16_IS_0(B16(0,0)) B16_IS_0(B16(1,0)), 1 0)
B_ASSERT(B32_IS_0(B32(0,0)) B32_IS_0(B32(1,0)), 1 0)
B_ASSERT(B64_IS_0(B64(0,0,0)) B64_IS_0(B64(1,0,0)), 1 0)


#define B8_IS_NEGr(b,a) B4_AT_##a(0,0,0,0,0,0,0,0,1,1,1,1,1,1,1,1)
#define B16_IS_NEGr(d,c,b,a) B4_AT_##a(0,0,0,0,0,0,0,0,1,1,1,1,1,1,1,1)
#define B32_IS_NEGr(h,g,f,e,d,c,b,a) B4_AT_##a(0,0,0,0,0,0,0,0,1,1,1,1,1,1,1,1)
#define B64_IS_NEGr(p,o,n,m,l,k,j,i,h,g,f,e,d,c,b,a) B4_AT_##a(0,0,0,0,0,0,0,0,1,1,1,1,1,1,1,1)
#define B8_IS_NEG(x) B8_IS_NEGr x
#define B16_IS_NEG(x) B16_IS_NEGr x
#define B32_IS_NEG(x) B32_IS_NEGr x
#define B64_IS_NEG(x) B64_IS_NEGr x

B_ASSERT(B8_IS_NEG(B8(f,f)) B8_IS_NEG(B8(3,3)), 1 0)
B_ASSERT(B16_IS_NEG(B16(f,f,f,f)) B16_IS_NEG(B16(3,3,3,3)), 1 0)
B_ASSERT(B32_IS_NEG(B32(f,f,f,f,f,f,f,f)) B32_IS_NEG(B32(3,3,3,3,3,3,3,3)), 1 0)
B_ASSERT(B64_IS_NEG(B64(f,f,f,f,f,f,f,f,f,f,f,f,f,f,f,f)) B64_IS_NEG(B64(3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3)), 1 0)


/// Addition

#define B128_ADD_17(C,x,y) B4_ADD(C,x,y),B64_ADD_16(B4_ADDC(C,x,y),
#define B64_ADD_16(C,x,y) B4_ADD(C,x,y),B64_ADD_15(B4_ADDC(C,x,y),
#define B64_ADD_15(C,x,y) B4_ADD(C,x,y),B64_ADD_14(B4_ADDC(C,x,y),
#define B64_ADD_14(C,x,y) B4_ADD(C,x,y),B64_ADD_13(B4_ADDC(C,x,y),
#define B64_ADD_13(C,x,y) B4_ADD(C,x,y),B64_ADD_12(B4_ADDC(C,x,y),
#define B64_ADD_12(C,x,y) B4_ADD(C,x,y),B64_ADD_11(B4_ADDC(C,x,y),
#define B64_ADD_11(C,x,y) B4_ADD(C,x,y),B64_ADD_10(B4_ADDC(C,x,y),
#define B64_ADD_10(C,x,y) B4_ADD(C,x,y),B64_ADD_9(B4_ADDC(C,x,y),
#define B64_ADD_9(C,x,y) B4_ADD(C,x,y),B32_ADD_8(B4_ADDC(C,x,y),
#define B32_ADD_8(C,x,y) B4_ADD(C,x,y),B32_ADD_7(B4_ADDC(C,x,y),
#define B32_ADD_7(C,x,y) B4_ADD(C,x,y),B32_ADD_6(B4_ADDC(C,x,y),
#define B32_ADD_6(C,x,y) B4_ADD(C,x,y),B32_ADD_5(B4_ADDC(C,x,y),
#define B32_ADD_5(C,x,y) B4_ADD(C,x,y),B16_ADD_4(B4_ADDC(C,x,y),
#define B16_ADD_4(C,x,y) B4_ADD(C,x,y),B16_ADD_3(B4_ADDC(C,x,y),
#define B16_ADD_3(C,x,y) B4_ADD(C,x,y),B8_ADD_2(B4_ADDC(C,x,y),
#define B8_ADD_2(C,x,y) B4_ADD(C,x,y),B8_ADD_1(B4_ADDC(C,x,y),
#define B8_ADD_1(C,x,y) B4_ADD(C,x,y)



#define B8_ADDr(car,a,b,A,B) B8_ADD_2(car,a,A)b,B)
#define B12_ADDr(car,a,b,c,A,B,C) B16_ADD_3(car,a,A)b,B)c,C)
#define B16_ADDr(car,a,b,c,d,A,B,C,D) B16_ADD_4(car,a,A)b,B)c,C)d,D)
#define B20_ADDr(car,a,b,c,d,e,A,B,C,D,E) B32_ADD_5(car,a,A)b,B)c,C)d,D)e,E)
#define B24_ADDr(car,a,b,c,d,e,f,A,B,C,D,E,F) B32_ADD_6(car,a,A)b,B)c,C)d,D)e,E)f,F)
#define B28_ADDr(car,a,b,c,d,e,f,g,A,B,C,D,E,F,G) B32_ADD_7(car,a,A)b,B)c,C)d,D)e,E)f,F)g,G)
#define B32_ADDr(car,a,b,c,d,e,f,g,h,A,B,C,D,E,F,G,H) \
	B32_ADD_8(car,a,A)b,B)c,C)d,D)e,E)f,F)g,G)h,H)
#define B36_ADDr(car,a,b,c,d,e,f,g,h,i,A,B,C,D,E,F,G,H,I) \
	B64_ADD_9(car,a,A)b,B)c,C)d,D)e,E)f,F)g,G)h,H)i,I)
#define B40_ADDr(car,a,b,c,d,e,f,g,h,i,j,A,B,C,D,E,F,G,H,I,J) \
	B64_ADD_10(car,a,A)b,B)c,C)d,D)e,E)f,F)g,G)h,H)i,I)j,J)
#define B44_ADDr(car,a,b,c,d,e,f,g,h,i,j,k,A,B,C,D,E,F,G,H,I,J,K) \
	B64_ADD_11(car,a,A)b,B)c,C)d,D)e,E)f,F)g,G)h,H)i,I)j,J)k,K)
#define B48_ADDr(car,a,b,c,d,e,f,g,h,i,j,k,l,A,B,C,D,E,F,G,H,I,J,K,L) \
	B64_ADD_12(car,a,A)b,B)c,C)d,D)e,E)f,F)g,G)h,H)i,I)j,J)k,K)l,L)
#define B52_ADDr(car,a,b,c,d,e,f,g,h,i,j,k,l,m,A,B,C,D,E,F,G,H,I,J,K,L,M) \
	B64_ADD_13(car,a,A)b,B)c,C)d,D)e,E)f,F)g,G)h,H)i,I)j,J)k,K)l,L)m,M)
#define B56_ADDr(car,a,b,c,d,e,f,g,h,i,j,k,l,m,n,A,B,C,D,E,F,G,H,I,J,K,L,M,N) \
	B64_ADD_14(car,a,A)b,B)c,C)d,D)e,E)f,F)g,G)h,H)i,I)j,J)k,K)l,L)m,M)n,N)
#define B60_ADDr(car,a,b,c,d,e,f,g,h,i,j,k,l,m,n,o,A,B,C,D,E,F,G,H,I,J,K,L,M,N,O) \
	B64_ADD_15(car,a,A)b,B)c,C)d,D)e,E)f,F)g,G)h,H)i,I)j,J)k,K)l,L)m,M)n,N)o,O)
#define B64_ADDr(car,a,b,c,d,e,f,g,h,i,j,k,l,m,n,o,p,A,B,C,D,E,F,G,H,I,J,K,L,M,N,O,P) \
	B64_ADD_16(car,a,A)b,B)c,C)d,D)e,E)f,F)g,G)h,H)i,I)j,J)k,K)l,L)m,M)n,N)o,O)p,P)

#define B8_ADD(x,y) (B_FX(B8_ADDr,,B_SCAN x,B_SCAN y))
#define B16_ADD(x,y) (B_FX(B16_ADDr,,B_SCAN x,B_SCAN y))
#define B32_ADD(x,y) (B_FX(B32_ADDr,,B_SCAN x,B_SCAN y))
#define B64_ADD(x,y) (B_FX(B64_ADDr,,B_SCAN x,B_SCAN y))

#define B8_ADDC(x,y) (B_FX(B8_ADDr,1,B_SCAN x,B_SCAN y))
#define B16_ADDC(x,y) (B_FX(B16_ADDr,1,B_SCAN x,B_SCAN y))
#define B32_ADDC(x,y) (B_FX(B32_ADDr,1,B_SCAN x,B_SCAN y))
#define B64_ADDC(x,y) (B_FX(B64_ADDr,1,B_SCAN x,B_SCAN y))

B_ASSERT(B8_HEX(B8_ADD(B8(2,1),B8(1,1))) B8_HEX(B8_ADD(B8(e,2),B8(3,2))),0x32 0x14)
B_ASSERT(B16_HEX(B16_ADD(B16(e,7,5,6),B16(5,c,7,2))),0x43c8)
B_ASSERT(B32_HEX(B32_ADD(B32(3,0,5,e,c,3,7,9),B32(2,2,3,3,f,8,5,d))),0x5292bbd6)
B_ASSERT(B64_HEX(B64_ADD(B64(6,8,0,e,c,5,e,2,5,a,0,4,e,0,9,1),
                 B64(8,0,8,1,7,c,5,f,4,8,8,3,e,7,b,d))), 0xe8904241a288c84e)


/// INC/DEC

#define B128_INC_17(C,x) B4_INC(C,x),B64_INC_16(B4_INCC(C,x),
#define B64_INC_16(C,x) B4_INC(C,x),B64_INC_15(B4_INCC(C,x),
#define B64_INC_15(C,x) B4_INC(C,x),B64_INC_14(B4_INCC(C,x),
#define B64_INC_14(C,x) B4_INC(C,x),B64_INC_13(B4_INCC(C,x),
#define B64_INC_13(C,x) B4_INC(C,x),B64_INC_12(B4_INCC(C,x),
#define B64_INC_12(C,x) B4_INC(C,x),B64_INC_11(B4_INCC(C,x),
#define B64_INC_11(C,x) B4_INC(C,x),B64_INC_10(B4_INCC(C,x),
#define B64_INC_10(C,x) B4_INC(C,x),B64_INC_9(B4_INCC(C,x),
#define B64_INC_9(C,x) B4_INC(C,x),B32_INC_8(B4_INCC(C,x),
#define B32_INC_8(C,x) B4_INC(C,x),B32_INC_7(B4_INCC(C,x),
#define B32_INC_7(C,x) B4_INC(C,x),B32_INC_6(B4_INCC(C,x),
#define B32_INC_6(C,x) B4_INC(C,x),B32_INC_5(B4_INCC(C,x),
#define B32_INC_5(C,x) B4_INC(C,x),B16_INC_4(B4_INCC(C,x),
#define B16_INC_4(C,x) B4_INC(C,x),B16_INC_3(B4_INCC(C,x),
#define B16_INC_3(C,x) B4_INC(C,x),B8_INC_2(B4_INCC(C,x),
#define B8_INC_2(C,x) B4_INC(C,x),B8_INC_1(B4_INCC(C,x),
#define B8_INC_1(C,x) B4_INC(C,x)


#define B8_INC(x) (B_FX(B8_INCr,B_SCAN x))
#define B8_INCr(a,b) B8_INC_2(1,a)b)

#define B16_INC(x) (B_FX(B16_INCr,B_SCAN x))
#define B16_INCr(a,b,c,d) B16_INC_4(1,a)b)c)d)

#define B32_INC(x) (B_FX(B32_INCr,B_SCAN x))
#define B32_INCr(a,b,c,d,e,f,g,h) B32_INC_8(1,a)b)c)d)e)f)g)h)

#define B64_INC(x) (B_FX(B64_INCr,B_SCAN x))
#define B64_INCr(a,b,c,d,e,f,g,h,i,j,k,l,m,n,o,p) B64_INC_16(1,a)b)c)d)e)f)g)h)i)j)k)l)m)n)o)p)



#define B128_DEC_17(C,x) B4_DEC(C,x),B64_DEC_16(B4_DECC(C,x),
#define B64_DEC_16(C,x) B4_DEC(C,x),B64_DEC_15(B4_DECC(C,x),
#define B64_DEC_15(C,x) B4_DEC(C,x),B64_DEC_14(B4_DECC(C,x),
#define B64_DEC_14(C,x) B4_DEC(C,x),B64_DEC_13(B4_DECC(C,x),
#define B64_DEC_13(C,x) B4_DEC(C,x),B64_DEC_12(B4_DECC(C,x),
#define B64_DEC_12(C,x) B4_DEC(C,x),B64_DEC_11(B4_DECC(C,x),
#define B64_DEC_11(C,x) B4_DEC(C,x),B64_DEC_10(B4_DECC(C,x),
#define B64_DEC_10(C,x) B4_DEC(C,x),B64_DEC_9(B4_DECC(C,x),
#define B64_DEC_9(C,x) B4_DEC(C,x),B32_DEC_8(B4_DECC(C,x),
#define B32_DEC_8(C,x) B4_DEC(C,x),B32_DEC_7(B4_DECC(C,x),
#define B32_DEC_7(C,x) B4_DEC(C,x),B32_DEC_6(B4_DECC(C,x),
#define B32_DEC_6(C,x) B4_DEC(C,x),B32_DEC_5(B4_DECC(C,x),
#define B32_DEC_5(C,x) B4_DEC(C,x),B16_DEC_4(B4_DECC(C,x),
#define B16_DEC_4(C,x) B4_DEC(C,x),B16_DEC_3(B4_DECC(C,x),
#define B16_DEC_3(C,x) B4_DEC(C,x),B8_DEC_2(B4_DECC(C,x),
#define B8_DEC_2(C,x) B4_DEC(C,x),B8_DEC_1(B4_DECC(C,x),
#define B8_DEC_1(C,x) B4_DEC(C,x)


#define B8_DEC(x) (B_FX(B8_DECr,B_SCAN x))
#define B8_DECr(a,b) B8_DEC_2(1,a)b)

#define B16_DEC(x) (B_FX(B16_DECr,B_SCAN x))
#define B16_DECr(a,b,c,d) B16_DEC_4(1,a)b)c)d)

#define B32_DEC(x) (B_FX(B32_DECr,B_SCAN x))
#define B32_DECr(a,b,c,d,e,f,g,h) B32_DEC_8(1,a)b)c)d)e)f)g)h)

#define B64_DEC(x) (B_FX(B64_DECr,B_SCAN x))
#define B64_DECr(a,b,c,d,e,f,g,h,i,j,k,l,m,n,o,p) B64_DEC_16(1,a)b)c)d)e)f)g)h)i)j)k)l)m)n)o)p)


B_ASSERT(B8_HEX(B8_INC(B8(2,f))),0x30)
B_ASSERT(B16_HEX(B16_INC(B16(1,2,f,f))),0x1300)
B_ASSERT(B32_HEX(B32_INC(B32(1,f,2,a,f,1,f,f))),0x1f2af200)
B_ASSERT(B64_HEX(B64_INC(B64(1,f,4,5,2,2,a,f,f,1,a,f,f,f,f,f))),0x1f4522aff1b00000)

B_ASSERT(B8_HEX(B8_DEC(B8(3,0))),0x2f)
B_ASSERT(B16_HEX(B16_DEC(B16(1,3,0,0))),0x12ff)
B_ASSERT(B32_HEX(B32_DEC(B32(1,f,2,a,f,2,0,0))),0x1f2af1ff)
B_ASSERT(B64_HEX(B64_DEC(B64(1,f,4,5,2,2,a,f,f,1,b,0,0,0,0,0))),0x1f4522aff1afffff)


/// NOT/NEG/ABS/SUB

#define B8_NOTr(a,b) B4_NOT(a),B4_NOT(b)
#define B16_NOTr(a,b,c,d) B4_NOT(a),B4_NOT(b),B4_NOT(c),B4_NOT(d)
#define B32_NOTr(a,b,c,d,e,f,g,h) \
	B4_NOT(a),B4_NOT(b),B4_NOT(c),B4_NOT(d),B4_NOT(e),B4_NOT(f),B4_NOT(g),B4_NOT(h)
#define B64_NOTr(a,b,c,d,e,f,g,h,i,j,k,l,m,n,o,p) \
	B4_NOT(a),B4_NOT(b),B4_NOT(c),B4_NOT(d),B4_NOT(e),B4_NOT(f),B4_NOT(g),B4_NOT(h), \
	B4_NOT(i),B4_NOT(j),B4_NOT(k),B4_NOT(l),B4_NOT(m),B4_NOT(n),B4_NOT(o),B4_NOT(p)

#define B8_NOT(x) (B_FX(B8_NOTr,B_SCAN x))
#define B16_NOT(x) (B_FX(B16_NOTr,B_SCAN x))
#define B32_NOT(x) (B_FX(B32_NOTr,B_SCAN x))
#define B64_NOT(x) (B_FX(B64_NOTr,B_SCAN x))

#define B8_NEG(x) (B_FX(B8_INCr,B8_NOTr x))
#define B16_NEG(x) (B_FX(B16_INCr,B16_NOTr x))
#define B32_NEG(x) (B_FX(B32_INCr,B32_NOTr x))
#define B64_NEG(x) (B_FX(B64_INCr,B64_NOTr x))


#define B8_ABS(x) B_CATe(B8_ABS,B8_IS_NEGr x)(x)
#define B8_ABS0(x) x
#define B8_ABS1 B8_NEG

#define B16_ABS(x) B_CATe(B16_ABS,B16_IS_NEGr x)(x)
#define B16_ABS0(x) x
#define B16_ABS1 B16_NEG

#define B32_ABS(x) B_CATe(B32_ABS,B32_IS_NEGr x)(x)
#define B32_ABS0(x) x
#define B32_ABS1 B32_NEG

#define B64_ABS(x) B_CATe(B64_ABS,B64_IS_NEGr x)(x)
#define B64_ABS0(x) x
#define B64_ABS1 B64_NEG


#define B8_SUB(x,y) (B_FX(B8_ADDr,1,B_SCAN x,B8_NOTr y))
#define B16_SUB(x,y) (B_FX(B16_ADDr,1,B_SCAN x,B16_NOTr y))
#define B32_SUB(x,y) (B_FX(B32_ADDr,1,B_SCAN x,B32_NOTr y))
#define B64_SUB(x,y) (B_FX(B64_ADDr,1,B_SCAN x,B64_NOTr y))

B_ASSERT(B8_HEX(B8_ABS(B8(1,9))) B8_HEX(B8_ABS(B8(9,1))),0x19 0x6f)
B_ASSERT(B16_HEX(B16_ABS(B16(9,2,3,1))),0x6dcf)
B_ASSERT(B32_HEX(B32_ABS(B32(a,2,b,c,5,4,3,1))),0x5d43abcf)
B_ASSERT(B64_HEX(B64_ABS(B64(f,a,2,b,3,c,f,c,e,f,3,4,3,1,a,f))),0x05d4c30310cbce51)

B_ASSERT(B8_HEX(B8_SUB(B8(1,9),B8(2,3))),0xf6)
B_ASSERT(B16_HEX(B16_SUB(B16(e,7,5,6),B16(5,c,7,2))),0x8ae4)
B_ASSERT(B32_HEX(B32_SUB(B32(3,0,5,e,c,3,7,9),B32(2,2,3,3,f,8,5,d))),0x0e2acb1c)
B_ASSERT(B64_HEX(B64_SUB(B64(6,8,0,e,c,5,e,2,5,a,0,4,e,0,9,1),
                         B64(8,0,8,1,7,c,5,f,4,8,8,3,e,7,b,d))), 0xe78d49831180f8d4)


/// mul


#define B8_ADDr_(...) B8_ADDr(,__VA_ARGS__)
#define B12_ADDr_(...) B12_ADDr(,__VA_ARGS__)
#define B16_ADDr_(...) B16_ADDr(,__VA_ARGS__)
#define B20_ADDr_(...) B20_ADDr(,__VA_ARGS__)
#define B24_ADDr_(...) B24_ADDr(,__VA_ARGS__)
#define B28_ADDr_(...) B28_ADDr(,__VA_ARGS__)
#define B32_ADDr_(...) B32_ADDr(,__VA_ARGS__)

#define B36_ADDr_(...) B36_ADDr(,__VA_ARGS__)
#define B40_ADDr_(...) B40_ADDr(,__VA_ARGS__)
#define B44_ADDr_(...) B44_ADDr(,__VA_ARGS__)
#define B48_ADDr_(...) B48_ADDr(,__VA_ARGS__)
#define B52_ADDr_(...) B52_ADDr(,__VA_ARGS__)
#define B56_ADDr_(...) B56_ADDr(,__VA_ARGS__)
#define B60_ADDr_(...) B60_ADDr(,__VA_ARGS__)
#define B64_ADDr_(...) B64_ADDr(,__VA_ARGS__)

#define B8_MUL(x,y) (B8_MUL__1(B_SCAN x,B_SCAN y))
#define B8_MUL__1(...) B8_MUL_(__VA_ARGS__)
#define B8_MUL_(x0,x1,y0,y1) \
	B4_MUL_##x0(B4_AT_##y0),B8_ADD_1(,B4_MULC_##x0(B4_AT_##y0), \
	B8_ADD_1(,B4_MUL_##x1(B4_AT_##y0),B4_MUL_##x0(B4_AT_##y1)))

B_ASSERT(B8_HEX(B8_MUL(B8(3,2),B8(f,2))),0x44)

#define B16_MUL(x,y) (B16_MUL__1(B4_MUL_,B4_MULC_,B4_AT_,B_SCAN x,B_SCAN y))
#define B16_MUL__1(...) B16_MUL_(__VA_ARGS__)
#define B16_MUL_(M,C,A,x0,x1,x2,x3,y0,y1,y2,y3) \
	M##x0(A##y0), \
	  B12_ADDr_(C##x0(A##y0), \
	   B8_ADDr_(C##x1(A##y0),C##x2(A##y0),C##x0(A##y1), \
	B8_ADD_1(,C##x1(A##y1),C##x0(A##y2))), \
	  B12_ADDr_(M##x1(A##y0),M##x2(A##y0),M##x3(A##y0),M##x0(A##y1), \
	   B8_ADDr_(M##x1(A##y1),M##x2(A##y1),M##x0(A##y2), \
	B8_ADD_1(,M##x1(A##y2),M##x0(A##y3)))))

B_ASSERT(B16_HEX(B16_MUL(B16(3,2,4,6),B16(f,3,2,e))),0x7a94)

#define B32_MUL(x,y) (B32_MUL__1(B4_MUL_,B4_MULC_,B4_AT_,B_SCAN x,B_SCAN y))
#define B32_MUL__1(...) B32_MUL_(__VA_ARGS__)
#define B32_MUL_(M,C,A,x0,x1,x2,x3,x4,x5,x6,x7,y0,y1,y2,y3,y4,y5,y6,y7) \
	M##x0(A##y0), \
	  B28_ADDr_(C##x0(A##y0), \
	  B24_ADDr_(C##x1(A##y0),C##x2(A##y0),C##x3(A##y0),C##x4(A##y0),C##x5(A##y0),C##x6(A##y0),C##x0(A##y1), \
	  B20_ADDr_(C##x1(A##y1),C##x2(A##y1),C##x3(A##y1),C##x4(A##y1),C##x5(A##y1),C##x0(A##y2), \
	  B16_ADDr_(C##x1(A##y2),C##x2(A##y2),C##x3(A##y2),C##x4(A##y2),C##x0(A##y3), \
	  B12_ADDr_(C##x1(A##y3),C##x2(A##y3),C##x3(A##y3),C##x0(A##y4), \
	   B8_ADDr_(C##x1(A##y4),C##x2(A##y4),C##x0(A##y5), \
	B8_ADD_1(,C##x1(A##y5),C##x0(A##y6))))))), \
	  B28_ADDr_(M##x1(A##y0),M##x2(A##y0),M##x3(A##y0),M##x4(A##y0),M##x5(A##y0),M##x6(A##y0),M##x7(A##y0),M##x0(A##y1), \
	  B24_ADDr_(M##x1(A##y1),M##x2(A##y1),M##x3(A##y1),M##x4(A##y1),M##x5(A##y1),M##x6(A##y1),M##x0(A##y2), \
	  B20_ADDr_(M##x1(A##y2),M##x2(A##y2),M##x3(A##y2),M##x4(A##y2),M##x5(A##y2),M##x0(A##y3), \
	  B16_ADDr_(M##x1(A##y3),M##x2(A##y3),M##x3(A##y3),M##x4(A##y3),M##x0(A##y4), \
	  B12_ADDr_(M##x1(A##y4),M##x2(A##y4),M##x3(A##y4),M##x0(A##y5), \
	   B8_ADDr_(M##x1(A##y5),M##x2(A##y5),M##x0(A##y6), \
	B8_ADD_1(,M##x1(A##y6),M##x0(A##y7)))))))))

B_ASSERT(B32_HEX(B32_MUL(B32(0,1,3,2,3,2,4,6),B32(f,f,1,2,3,2,f,e))),0x408b8d74)

#define B64_MUL(x,y) (B64_MUL__1(B4_MUL_,B4_MULC_,B4_AT_,B_SCAN x,B_SCAN y))
#define B64_MUL__1(...) B64_MUL_(__VA_ARGS__)
#define B64_MUL_(M,C,A,x0,x1,x2,x3,x4,x5,x6,x7,x8,x9,xa,xb,xc,xd,xe,xf,y0,y1,y2,y3,y4,y5,y6,y7,y8,y9,ya,yb,yc,yd,ye,yf) \
	M##x0(A##y0),B60_ADDr_(C##x0(A##y0), \
	B56_ADDr_(C##x1(A##y0),C##x2(A##y0),C##x3(A##y0),C##x4(A##y0),C##x5(A##y0),C##x6(A##y0),C##x7(A##y0),C##x8(A##y0), \
	          C##x9(A##y0),C##xa(A##y0),C##xb(A##y0),C##xc(A##y0),C##xd(A##y0),C##xe(A##y0),C##x0(A##y1), \
	B52_ADDr_(C##x1(A##y1),C##x2(A##y1),C##x3(A##y1),C##x4(A##y1),C##x5(A##y1),C##x6(A##y1),C##x7(A##y1), \
	          C##x8(A##y1),C##x9(A##y1),C##xa(A##y1),C##xb(A##y1),C##xc(A##y1),C##xd(A##y1),C##x0(A##y2), \
	B48_ADDr_(C##x1(A##y2),C##x2(A##y2),C##x3(A##y2),C##x4(A##y2),C##x5(A##y2),C##x6(A##y2),C##x7(A##y2), \
	          C##x8(A##y2),C##x9(A##y2),C##xa(A##y2),C##xb(A##y2),C##xc(A##y2),C##x0(A##y3), \
	B44_ADDr_(C##x1(A##y3),C##x2(A##y3),C##x3(A##y3),C##x4(A##y3),C##x5(A##y3),C##x6(A##y3), \
	          C##x7(A##y3),C##x8(A##y3),C##x9(A##y3),C##xa(A##y3),C##xb(A##y3),C##x0(A##y4), \
	B40_ADDr_(C##x1(A##y4),C##x2(A##y4),C##x3(A##y4),C##x4(A##y4),C##x5(A##y4),C##x6(A##y4), \
	          C##x7(A##y4),C##x8(A##y4),C##x9(A##y4),C##xa(A##y4),C##x0(A##y5), \
	B36_ADDr_(C##x1(A##y5),C##x2(A##y5),C##x3(A##y5),C##x4(A##y5),C##x5(A##y5), \
	          C##x6(A##y5),C##x7(A##y5),C##x8(A##y5),C##x9(A##y5),C##x0(A##y6), \
	B32_ADDr_(C##x1(A##y6),C##x2(A##y6),C##x3(A##y6),C##x4(A##y6),C##x5(A##y6), \
	          C##x6(A##y6),C##x7(A##y6),C##x8(A##y6),C##x0(A##y7), \
	B28_ADDr_(C##x1(A##y7),C##x2(A##y7),C##x3(A##y7),C##x4(A##y7),C##x5(A##y7),C##x6(A##y7),C##x7(A##y7),C##x0(A##y8), \
	B24_ADDr_(C##x1(A##y8),C##x2(A##y8),C##x3(A##y8),C##x4(A##y8),C##x5(A##y8),C##x6(A##y8),C##x0(A##y9), \
	B20_ADDr_(C##x1(A##y9),C##x2(A##y9),C##x3(A##y9),C##x4(A##y9),C##x5(A##y9),C##x0(A##ya), \
	B16_ADDr_(C##x1(A##ya),C##x2(A##ya),C##x3(A##ya),C##x4(A##ya),C##x0(A##yb), \
	B12_ADDr_(C##x1(A##yb),C##x2(A##yb),C##x3(A##yb),C##x0(A##yc), \
	 B8_ADDr_(C##x1(A##yc),C##x2(A##yc),C##x0(A##yd), \
	B8_ADD_1(,C##x1(A##yd),C##x0(A##ye))))))))))))))), \
	B60_ADDr_(M##x1(A##y0),M##x2(A##y0),M##x3(A##y0),M##x4(A##y0),M##x5(A##y0),M##x6(A##y0),M##x7(A##y0),M##x8(A##y0), \
	          M##x9(A##y0),M##xa(A##y0),M##xb(A##y0),M##xc(A##y0),M##xd(A##y0),M##xe(A##y0),M##xf(A##y0),M##x0(A##y1), \
	B56_ADDr_(M##x1(A##y1),M##x2(A##y1),M##x3(A##y1),M##x4(A##y1),M##x5(A##y1),M##x6(A##y1),M##x7(A##y1),M##x8(A##y1), \
	          M##x9(A##y1),M##xa(A##y1),M##xb(A##y1),M##xc(A##y1),M##xd(A##y1),M##xe(A##y1),M##x0(A##y2), \
	B52_ADDr_(M##x1(A##y2),M##x2(A##y2),M##x3(A##y2),M##x4(A##y2),M##x5(A##y2),M##x6(A##y2),M##x7(A##y2), \
	          M##x8(A##y2),M##x9(A##y2),M##xa(A##y2),M##xb(A##y2),M##xc(A##y2),M##xd(A##y2),M##x0(A##y3), \
	B48_ADDr_(M##x1(A##y3),M##x2(A##y3),M##x3(A##y3),M##x4(A##y3),M##x5(A##y3),M##x6(A##y3),M##x7(A##y3), \
	          M##x8(A##y3),M##x9(A##y3),M##xa(A##y3),M##xb(A##y3),M##xc(A##y3),M##x0(A##y4), \
	B44_ADDr_(M##x1(A##y4),M##x2(A##y4),M##x3(A##y4),M##x4(A##y4),M##x5(A##y4),M##x6(A##y4), \
	          M##x7(A##y4),M##x8(A##y4),M##x9(A##y4),M##xa(A##y4),M##xb(A##y4),M##x0(A##y5), \
	B40_ADDr_(M##x1(A##y5),M##x2(A##y5),M##x3(A##y5),M##x4(A##y5),M##x5(A##y5),M##x6(A##y5), \
	          M##x7(A##y5),M##x8(A##y5),M##x9(A##y5),M##xa(A##y5),M##x0(A##y6), \
	B36_ADDr_(M##x1(A##y6),M##x2(A##y6),M##x3(A##y6),M##x4(A##y6),M##x5(A##y6), \
	          M##x6(A##y6),M##x7(A##y6),M##x8(A##y6),M##x9(A##y6),M##x0(A##y7), \
	B32_ADDr_(M##x1(A##y7),M##x2(A##y7),M##x3(A##y7),M##x4(A##y7),M##x5(A##y7), \
	          M##x6(A##y7),M##x7(A##y7),M##x8(A##y7),M##x0(A##y8), \
	B28_ADDr_(M##x1(A##y8),M##x2(A##y8),M##x3(A##y8),M##x4(A##y8),M##x5(A##y8),M##x6(A##y8),M##x7(A##y8),M##x0(A##y9), \
	B24_ADDr_(M##x1(A##y9),M##x2(A##y9),M##x3(A##y9),M##x4(A##y9),M##x5(A##y9),M##x6(A##y9),M##x0(A##ya), \
	B20_ADDr_(M##x1(A##ya),M##x2(A##ya),M##x3(A##ya),M##x4(A##ya),M##x5(A##ya),M##x0(A##yb), \
	B16_ADDr_(M##x1(A##yb),M##x2(A##yb),M##x3(A##yb),M##x4(A##yb),M##x0(A##yc), \
	B12_ADDr_(M##x1(A##yc),M##x2(A##yc),M##x3(A##yc),M##x0(A##yd), \
	 B8_ADDr_(M##x1(A##yd),M##x2(A##yd),M##x0(A##ye), \
	B8_ADD_1(,M##x1(A##ye),M##x0(A##yf)))))))))))))))))

B_ASSERT(B64_HEX(B64_MUL(B64(a,f,3,3,2,9,4,6,0,1,3,2,3,2,4,6),B64(9,9,1,2,7,1,1,e,f,f,1,2,3,2,f,e))),0x1fee7f80408b8d74)
B_ASSERT(B64_HEX(B64_MUL(B64(d,e,a,d,b,e,e,f),B64(d,e,a,d,b,e,e,f))),0xc1b1cd12216da321)



#define B8_MUL_B4(x,y) (B8_MUL_B4__1(B_SCAN x,B4_AT_##y))
#define B8_MUL_B4__1(...) B8_MUL_B4_(__VA_ARGS__)
#define B8_MUL_B4_(x0,x1,y) \
	B4_MUL_##x0(y),B4_ADDe(,B4_MULC_##x0(y),B4_MUL_##x1(y))

B_ASSERT(B8_HEX(B8_MUL_B4(B8(3,2),9)),0xc2)

#define B16_MUL_B4(x,y) (B16_MUL_B4__1(B4_MUL_,B4_MULC_,B_SCAN x,B4_AT_##y))
#define B16_MUL_B4__1(...) B16_MUL_B4_(__VA_ARGS__)
#define B16_MUL_B4_(M,C,x0,x1,x2,x3,y) \
	M##x0(y),B12_ADDr_(C##x0(y),C##x1(y),C##x2(y),M##x1(y),M##x2(y),M##x3(y))

B_ASSERT(B16_HEX(B16_MUL_B4(B16(3,2,4,6),4)),0xc918)

#define B32_MUL_B4(x,y) (B32_MUL_B4__1(B4_MUL_,B4_MULC_,B_SCAN x,B4_AT_##y))
#define B32_MUL_B4__1(...) B32_MUL_B4_(__VA_ARGS__)
#define B32_MUL_B4_(M,C,x0,x1,x2,x3,x4,x5,x6,x7,y) \
	M##x0(y), \
	B28_ADDr_(C##x0(y),C##x1(y),C##x2(y),C##x3(y),C##x4(y),C##x5(y),C##x6(y), \
	          M##x1(y),M##x2(y),M##x3(y),M##x4(y),M##x5(y),M##x6(y),M##x7(y))

B_ASSERT(B32_HEX(B32_MUL_B4(B32(0,1,3,2,3,2,4,6),e)),0x10bebfd4)

#define B64_MUL_B4(x,y) (B64_MUL_B4__1(B4_MUL_,B4_MULC_,B_SCAN x,B4_AT_##y))
#define B64_MUL_B4__1(...) B64_MUL_B4_(__VA_ARGS__)
#define B64_MUL_B4_(M,C,x0,x1,x2,x3,x4,x5,x6,x7,x8,x9,xa,xb,xc,xd,xe,xf,y) \
	M##x0(y), \
	B60_ADDr_(C##x0(y),C##x1(y),C##x2(y),C##x3(y),C##x4(y),C##x5(y),C##x6(y),C##x7(y),C##x8(y),C##x9(y),C##xa(y),C##xb(y),C##xc(y),C##xd(y),C##xe(y), \
	          M##x1(y),M##x2(y),M##x3(y),M##x4(y),M##x5(y),M##x6(y),M##x7(y),M##x8(y),M##x9(y),M##xa(y),M##xb(y),M##xc(y),M##xd(y),M##xe(y),M##xf(y))

B_ASSERT(B64_HEX(B64_MUL_B4(B64(a,f,3,3,2,9,4,6,0,1,3,2,3,2,4,6),a)),0xd7ff9cbc0bf5f6bc)


/// binop

#define B8_BIN_OP(F,x0,x1,y0,y1) F(x0,y0),F(x1,y1)
#define B16_BIN_OP(F,x0,x1,x2,x3,y0,y1,y2,y3) F(x0,y0),F(x1,y1),F(x2,y2),F(x3,y3)
#define B32_BIN_OP(F,x0,x1,x2,x3,x4,x5,x6,x7,y0,y1,y2,y3,y4,y5,y6,y7) \
	F(x0,y0),F(x1,y1),F(x2,y2),F(x3,y3),F(x4,y4),F(x5,y5),F(x6,y6),F(x7,y7)
#define B64_BIN_OP(F,x0,x1,x2,x3,x4,x5,x6,x7,x8,x9,xa,xb,xc,xd,xe,xf,y0,y1,y2,y3,y4,y5,y6,y7,y8,y9,ya,yb,yc,yd,ye,yf) \
	F(x0,y0),F(x1,y1),F(x2,y2),F(x3,y3),F(x4,y4),F(x5,y5),F(x6,y6),F(x7,y7), \
	F(x8,y8),F(x9,y9),F(xa,ya),F(xb,yb),F(xc,yc),F(xd,yd),F(xe,ye),F(xf,yf)

#define B8_AND(x,y) (B_FX(B8_BIN_OP,B4_ANDe,B_SCAN x,B_SCAN y))
#define B8_OR(x,y) (B_FX(B8_BIN_OP,B4_ORe,B_SCAN x,B_SCAN y))
#define B8_XOR(x,y) (B_FX(B8_BIN_OP,B4_XORe,B_SCAN x,B_SCAN y))

#define B16_AND(x,y) (B_FX(B16_BIN_OP,B4_ANDe,B_SCAN x,B_SCAN y))
#define B16_OR(x,y) (B_FX(B16_BIN_OP,B4_ORe,B_SCAN x,B_SCAN y))
#define B16_XOR(x,y) (B_FX(B16_BIN_OP,B4_XORe,B_SCAN x,B_SCAN y))

#define B32_AND(x,y) (B_FX(B32_BIN_OP,B4_ANDe,B_SCAN x,B_SCAN y))
#define B32_OR(x,y) (B_FX(B32_BIN_OP,B4_ORe,B_SCAN x,B_SCAN y))
#define B32_XOR(x,y) (B_FX(B32_BIN_OP,B4_XORe,B_SCAN x,B_SCAN y))

#define B64_AND(x,y) (B_FX(B64_BIN_OP,B4_ANDe,B_SCAN x,B_SCAN y))
#define B64_OR(x,y) (B_FX(B64_BIN_OP,B4_ORe,B_SCAN x,B_SCAN y))
#define B64_XOR(x,y) (B_FX(B64_BIN_OP,B4_XORe,B_SCAN x,B_SCAN y))

B_ASSERT(B8_HEX(B8_AND(B8(3,7),B8(9,4))),0x14)
B_ASSERT(B8_HEX(B8_OR(B8(3,7),B8(9,4))),0xb7)
B_ASSERT(B8_HEX(B8_XOR(B8(3,7),B8(9,4))),0xa3)

/// EQ/NE/LT/GT/LE/GE

#define B8_EQ(x,y) B8_IS_0(B8_SUB(x,y))
#define B16_EQ(x,y) B16_IS_0(B16_SUB(x,y))
#define B32_EQ(x,y) B32_IS_0(B32_SUB(x,y))
#define B64_EQ(x,y) B64_IS_0(B64_SUB(x,y))

#define B8_NE(x,y) B1_NOTe(B8_IS_0(B8_SUB(x,y)))
#define B16_NE(x,y) B1_NOTe(B16_IS_0(B16_SUB(x,y)))
#define B32_NE(x,y) B1_NOTe(B32_IS_0(B32_SUB(x,y)))
#define B64_NE(x,y) B1_NOTe(B64_IS_0(B64_SUB(x,y)))

#define B8_GT(x,y) B8_IS_NEG(B8_SUB(y,x))
#define B16_GT(x,y) B16_IS_NEG(B16_SUB(y,x))
#define B32_GT(x,y) B32_IS_NEG(B32_SUB(y,x))
#define B64_GT(x,y) B64_IS_NEG(B64_SUB(y,x))

#define B8_LT(x,y) B8_IS_NEG(B8_SUB(x,y))
#define B16_LT(x,y) B16_IS_NEG(B16_SUB(x,y))
#define B32_LT(x,y) B32_IS_NEG(B32_SUB(x,y))
#define B64_LT(x,y) B64_IS_NEG(B64_SUB(x,y))

#define B8_GE_(x) B1_ORe(B8_IS_NEGr x,B8_IS_0r x)
#define B16_GE_(x) B1_ORe(B16_IS_NEGr x,B16_IS_0r x)
#define B32_GE_(x) B1_ORe(B32_IS_NEGr x,B32_IS_0r x)
#define B64_GE_(x) B1_ORe(B64_IS_NEGr x,B64_IS_0r x)

#define B8_GE(x,y) B8_GE_(B8_SUB(y,x))
#define B16_GE(x,y) B16_GE_(B16_SUB(y,x))
#define B32_GE(x,y) B32_GE_(B32_SUB(y,x))
#define B64_GE(x,y) B64_GE_(B64_SUB(y,x))


#define B8_LE_(x) B1_ORe(B8_IS_NEGr x,B8_IS_0r x)
#define B16_LE_(x) B1_ORe(B16_IS_NEGr x,B16_IS_0r x)
#define B32_LE_(x) B1_ORe(B32_IS_NEGr x,B32_IS_0r x)
#define B64_LE_(x) B1_ORe(B64_IS_NEGr x,B64_IS_0r x)

#define B8_LE(x,y) B8_LE_(B8_SUB(x,y))
#define B16_LE(x,y) B16_LE_(B16_SUB(x,y))
#define B32_LE(x,y) B32_LE_(B32_SUB(x,y))
#define B64_LE(x,y) B64_LE_(B64_SUB(x,y))


B_ASSERT(B8_EQ(B8(3,3),B8(3,4))B8_EQ(B8(3,3),B8(3,3)),01)
B_ASSERT(B8_NE(B8(3,3),B8(3,4))B8_NE(B8(3,3),B8(3,3)),10)
B_ASSERT(B8_LT(B8(3,3),B8(3,4))B8_LE(B8(3,3),B8(3,0)),10)
B_ASSERT(B8_GT(B8(3,3),B8(3,4))B8_GT(B8(3,3),B8(3,0)),01)
B_ASSERT(B8_LE(B8(3,3),B8(3,3))B8_LE(B8(3,3),B8(3,0)),10)
B_ASSERT(B8_GE(B8(3,3),B8(3,3))B8_GE(B8(3,0),B8(3,3)),10)

#define B8_MAX(a,b) B_IFe(B8_GT(a,b))(a)(b)
#define B16_MAX(a,b) B_IFe(B16_GT(a,b))(a)(b)
#define B32_MAX(a,b) B_IFe(B32_GT(a,b))(a)(b)
#define B64_MAX(a,b) B_IFe(B64_GT(a,b))(a)(b)

#define B8_MIN(a,b) B_IFe(B8_LT(a,b))(a)(b)
#define B16_MIN(a,b) B_IFe(B16_LT(a,b))(a)(b)
#define B32_MIN(a,b) B_IFe(B32_LT(a,b))(a)(b)
#define B64_MIN(a,b) B_IFe(B64_LT(a,b))(a)(b)


/// to/from binary

#define B8_TO_B1r(a,b) B4_TO_B1_##a,B4_TO_B1_##b

#define B16_TO_B1r(a,b,c,d) B4_TO_B1_##a,B4_TO_B1_##b,B4_TO_B1_##c,B4_TO_B1_##d

#define B32_TO_B1r(a,b,c,d,e,f,g,h) \
	B4_TO_B1_##a,B4_TO_B1_##b,B4_TO_B1_##c,B4_TO_B1_##d, \
	B4_TO_B1_##e,B4_TO_B1_##f,B4_TO_B1_##g,B4_TO_B1_##h

#define B64_TO_B1r(a,b,c,d,e,f,g,h,...) \
	B32_TO_B1r(a,b,c,d,e,f,g,h),B32_TO_B1r(__VA_ARGS__)


#define B8_FROM_B1r(a,b,c,d,e,f,g,h) \
	B4_FROM_B1_##d##c##b##a,B4_FROM_B1_##h##g##f##e \

#define B16_FROM_B1r(a,b,c,d,e,f,g,h,i,j,k,l,m,n,o,p) \
	B4_FROM_B1_##d##c##b##a,B4_FROM_B1_##h##g##f##e, \
	B4_FROM_B1_##l##k##j##i,B4_FROM_B1_##p##o##n##m

#define B32_FROM_B1r(a,b,c,d,e,f,g,h,i,j,k,l,m,n,o,p,q,r,s,t,u,v,w,x,y,z,A,B,C,D,E,F) \
	B4_FROM_B1_##d##c##b##a,B4_FROM_B1_##h##g##f##e,B4_FROM_B1_##l##k##j##i, \
	B4_FROM_B1_##p##o##n##m,B4_FROM_B1_##t##s##r##q,B4_FROM_B1_##x##w##v##u, \
	B4_FROM_B1_##B##A##z##y,B4_FROM_B1_##F##E##D##C

#define B64_FROM_B1r(a,b,c,d,e,f,g,h,i,j,k,l,m,n,o,p,q,r,s,t,u,v,w,x,y,z,A,B,C,D,E,F,...) \
	B32_FROM_B1r(a,b,c,d,e,f,g,h,i,j,k,l,m,n,o,p,q,r,s,t,u,v,w,x,y,z,A,B,C,D,E,F), \
	B32_FROM_B1r(__VA_ARGS__)

/// bsearch

#define B_BSEARCH_00(F,...) __VA_ARGS__
#define B_BSEARCH_01(F,...) F##1(__VA_ARGS__)
#define B_BSEARCH_02(F,...) F##2(__VA_ARGS__)
#define B_BSEARCH_03(F,...) B__FX(F##2,F##1(__VA_ARGS__))
#define B_BSEARCH_04(F,...) F##4(__VA_ARGS__)
#define B_BSEARCH_05(F,...) B__FX(F##4,F##1(__VA_ARGS__))
#define B_BSEARCH_06(F,...) B__FX(F##4,F##2(__VA_ARGS__))
#define B_BSEARCH_07(F,...) B__FX(F##4,B__FX(F##2,F##1(__VA_ARGS__)))
#define B_BSEARCH_08(F,...) F##8(__VA_ARGS__)
#define B_BSEARCH_09(F,...) B__FX(F##8,F##1(__VA_ARGS__))
#define B_BSEARCH_0a(F,...) B__FX(F##8,F##2(__VA_ARGS__))
#define B_BSEARCH_0b(F,...) B__FX(F##8,B__FX(F##2(,##1(__VA_ARGS__)))
#define B_BSEARCH_0c(F,...) B__FX(F##8,F##4(__VA_ARGS__))
#define B_BSEARCH_0d(F,...) B__FX(F##8,B__FX(F##4,F##1(__VA_ARGS__)))
#define B_BSEARCH_0e(F,...) B__FX(F##8,B__FX(F##4,F##2(__VA_ARGS__)))
#define B_BSEARCH_0f(F,...) B__FX(F##8,B__FX(F##4,B__FX(F##2,F##1(__VA_ARGS__))))
#define B_BSEARCH_10(F,...) F##16(__VA_ARGS__)
#define B_BSEARCH_11(F,...) B__FX(F##16,F##1(__VA_ARGS__))
#define B_BSEARCH_12(F,...) B__FX(F##16,F##2(__VA_ARGS__))
#define B_BSEARCH_13(F,...) B__FX(F##16,B__FX(F##2,F##1(__VA_ARGS__)))
#define B_BSEARCH_14(F,...) B__FX(F##16,F##4(__VA_ARGS__))
#define B_BSEARCH_15(F,...) B__FX(F##16,B__FX(F##4,F##1(__VA_ARGS__)))
#define B_BSEARCH_16(F,...) B__FX(F##16,B__FX(F##4,F##2(__VA_ARGS__)))
#define B_BSEARCH_17(F,...) B__FX(F##16,B__FX(F##4,B__FX(F##2,F##1(__VA_ARGS__))))
#define B_BSEARCH_18(F,...) B__FX(F##16,F##8(__VA_ARGS__))
#define B_BSEARCH_19(F,...) B__FX(F##16,B__FX(F##8,F##1(__VA_ARGS__)))
#define B_BSEARCH_1a(F,...) B__FX(F##16,B__FX(F##8,F##2(__VA_ARGS__)))
#define B_BSEARCH_1b(F,...) B__FX(F##16,B__FX(F##8,B__FX(F##2(,##1(__VA_ARGS__))))
#define B_BSEARCH_1c(F,...) B__FX(F##16,B__FX(F##8,F##4(__VA_ARGS__)))
#define B_BSEARCH_1d(F,...) B__FX(F##16,B__FX(F##8,B__FX(F##4,F##1(__VA_ARGS__))))
#define B_BSEARCH_1e(F,...) B__FX(F##16,B__FX(F##8,B__FX(F##4,F##2(__VA_ARGS__))))
#define B_BSEARCH_1f(F,...) B__FX(F##16,B__FX(F##8,B__FX(F##4,B__FX(F##2,F##1(__VA_ARGS__)))))
#define B_BSEARCH_20(F,...) F##32(__VA_ARGS__)
#define B_BSEARCH_21(F,...) B__FX(F##32,F##1(__VA_ARGS__))
#define B_BSEARCH_22(F,...) B__FX(F##32,F##2(__VA_ARGS__))
#define B_BSEARCH_23(F,...) B__FX(F##32,B__FX(F##2,F##1(__VA_ARGS__)))
#define B_BSEARCH_24(F,...) B__FX(F##32,F##4(__VA_ARGS__))
#define B_BSEARCH_25(F,...) B__FX(F##32,B__FX(F##4,F##1(__VA_ARGS__)))
#define B_BSEARCH_26(F,...) B__FX(F##32,B__FX(F##4,F##2(__VA_ARGS__)))
#define B_BSEARCH_27(F,...) B__FX(F##32,B__FX(F##4,B__FX(F##2,F##1(__VA_ARGS__))))
#define B_BSEARCH_28(F,...) B__FX(F##32,F##8(__VA_ARGS__))
#define B_BSEARCH_29(F,...) B__FX(F##32,B__FX(F##8,F##1(__VA_ARGS__)))
#define B_BSEARCH_2a(F,...) B__FX(F##32,B__FX(F##8,F##2(__VA_ARGS__)))
#define B_BSEARCH_2b(F,...) B__FX(F##32,B__FX(F##8,B__FX(F##2(,##1(__VA_ARGS__))))
#define B_BSEARCH_2c(F,...) B__FX(F##32,B__FX(F##8,F##4(__VA_ARGS__)))
#define B_BSEARCH_2d(F,...) B__FX(F##32,B__FX(F##8,B__FX(F##4,F##1(__VA_ARGS__))))
#define B_BSEARCH_2e(F,...) B__FX(F##32,B__FX(F##8,B__FX(F##4,F##2(__VA_ARGS__))))
#define B_BSEARCH_2f(F,...) B__FX(F##32,B__FX(F##8,B__FX(F##4,B__FX(F##2,F##1(__VA_ARGS__)))))
#define B_BSEARCH_30(F,...) B__FX(F##32,F##16(__VA_ARGS__))
#define B_BSEARCH_31(F,...) B__FX(F##32,B__FX(F##16,F##1(__VA_ARGS__)))
#define B_BSEARCH_32(F,...) B__FX(F##32,B__FX(F##16,F##2(__VA_ARGS__)))
#define B_BSEARCH_33(F,...) B__FX(F##32,B__FX(F##16,B__FX(F##2,F##1(__VA_ARGS__))))
#define B_BSEARCH_34(F,...) B__FX(F##32,B__FX(F##16,F##4(__VA_ARGS__)))
#define B_BSEARCH_35(F,...) B__FX(F##32,B__FX(F##16,B__FX(F##4,F##1(__VA_ARGS__))))
#define B_BSEARCH_36(F,...) B__FX(F##32,B__FX(F##16,B__FX(F##4,F##2(__VA_ARGS__))))
#define B_BSEARCH_37(F,...) B__FX(F##32,B__FX(F##16,B__FX(F##4,B__FX(F##2,F##1(__VA_ARGS__)))))
#define B_BSEARCH_38(F,...) B__FX(F##32,B__FX(F##16,F##8(__VA_ARGS__)))
#define B_BSEARCH_39(F,...) B__FX(F##32,B__FX(F##16,B__FX(F##8,F##1(__VA_ARGS__))))
#define B_BSEARCH_3a(F,...) B__FX(F##32,B__FX(F##16,B__FX(F##8,F##2(__VA_ARGS__))))
#define B_BSEARCH_3b(F,...) B__FX(F##32,B__FX(F##16,B__FX(F##8,B__FX(F##2(,##1(__VA_ARGS__)))))
#define B_BSEARCH_3c(F,...) B__FX(F##32,B__FX(F##16,B__FX(F##8,F##4(__VA_ARGS__))))
#define B_BSEARCH_3d(F,...) B__FX(F##32,B__FX(F##16,B__FX(F##8,B__FX(F##4,F##1(__VA_ARGS__)))))
#define B_BSEARCH_3e(F,...) B__FX(F##32,B__FX(F##16,B__FX(F##8,B__FX(F##4,F##2(__VA_ARGS__)))))
#define B_BSEARCH_3f(F,...) B__FX(F##32,B__FX(F##16,B__FX(F##8,B__FX(F##4,B__FX(F##2,F##1(__VA_ARGS__))))))

#define B_BSEARCH_FX(f,...) f(__VA_ARGS__)

#define B_BSEARCH8(F,x,n) B_BSEARCH_FX(B_BSEARCH8_,F,x,B_SCAN n)
#define B_BSEARCH8_(F,x,n0,n1) B_BSEARCH_##n1##n0(F,B8_TO_B1r x)
#define B_BSEARCH16(F,x,n) B_BSEARCH_FX(B_BSEARCH16_,F,x,B_TUPLE_UNTIL_1 n)
#define B_BSEARCH16_(F,x,n0,n1) B_BSEARCH_##n1##n0(F,B16_TO_B1r x)
#define B_BSEARCH32(F,x,n) B_BSEARCH_FX(B_BSEARCH32_,F,x,B_TUPLE_UNTIL_1 n)
#define B_BSEARCH32_(F,x,n0,n1) B_BSEARCH_##n1##n0(F,B32_TO_B1r x)
#define B_BSEARCH64(F,x,n) B_BSEARCH_FX(B_BSEARCH64_,F,x,B_TUPLE_UNTIL_1 n)
#define B_BSEARCH64_(F,x,n0,n1) B_BSEARCH_##n1##n0(F,B64_TO_B1r x)

/// DIV


#define B8_IS_EVENr(b,a) B4_AT_##a(0,0,0,0,0,0,0,0,1,1,1,1,1,1,1,1)
#define B16_IS_EVENr(d,c,b,a) B4_AT_##a(0,0,0,0,0,0,0,0,1,1,1,1,1,1,1,1)
#define B32_IS_EVENr(h,g,f,e,d,c,b,a) B4_AT_##a(0,0,0,0,0,0,0,0,1,1,1,1,1,1,1,1)
#define B64_IS_EVENr(p,o,n,m,l,k,j,i,h,g,f,e,d,c,b,a) B4_AT_##a(0,0,0,0,0,0,0,0,1,1,1,1,1,1,1,1)

#define B8_SLL1V_(V,a,b,c,d,e,f,g,h) V,a,b,c,d,e,f,g
#define B16_SLL1V_(V,a,b,c,d,e,f,g,h,i,j,k,l,m,n,o,p) V,a,b,c,d,e,f,g,h,i,j,k,l,m,n,o
#define B32_SLL1V_(V,a,b,c,d,e,f,g,h,i,j,k,l,m,n,o,p,q,r,s,t,u,v,w,x,y,z,A,B,C,D,E,F) \
        V,a,b,c,d,e,f,g,h,i,j,k,l,m,n,o,p,q,r,s,t,u,v,w,x,y,z,A,B,C,D,E
#define B64_SLL1V_(val,a,b,c,d,e,f,g,h,i,j,k,l,m,n,o,p,q,r,s,t,u,v,w,x,y,z,A,B,C,D,E,F,G,H, \
                   I,J,K,L,M,N,O,P,Q,R,S,T,U,V,W,X,Y,Z,a0,b0,c0,d0,e0,f0,g0,h0,i0,j0,k0,l0) \
	val,a,b,c,d,e,f,g,h,i,j,k,l,m,n,o,p,q,r,s,t,u,v,w,x,y,z,A,B,C,D,E,F,G, \
	H,I,J,K,L,M,N,O,P,Q,R,S,T,U,V,W,X,Y,Z,a0,b0,c0,d0,e0,f0,g0,h0,i0,j0,k0

#define B8_SLL1V(V,x) (B_FX(B8_FROM_B1r,B_FX(B8_SLL1V_,V,B8_TO_B1r x)))
#define B16_SLL1V(V,x) (B_FX(B16_FROM_B1r,B_FX(B16_SLL1V_,V,B16_TO_B1r x)))
#define B32_SLL1V(V,x) (B_FX(B32_FROM_B1r,B_FX(B32_SLL1V_,V,B32_TO_B1r x)))
#define B64_SLL1V(V,x) (B_FX(B64_FROM_B1r,B_FX(B64_SLL1V_,V,B64_TO_B1r x)))


#define B8__DIV_ONCE(...) B8__DIV_ONCE_(__VA_ARGS__)
#define B8__DIV_ONCE_(N,D,Q,R) B8_SLL1V(0,N),B8__DIV_ONCE_1(D,Q,B8_SLL1V(B8_IS_EVENr N,R))
#define B8__DIV_ONCE_1(D,Q,R) D,B8__DIV_ONCE_2(Q,R,B8_SUB(R,D))
#define B8__DIV_ONCE_2(Q,R,RD) B_IFe(B8_IS_NEG(RD))(B8_SLL1V(0,Q),R)(B8_SLL1V(1,Q),RD)

#define B16__DIV_ONCE(...) B16__DIV_ONCE_(__VA_ARGS__)
#define B16__DIV_ONCE_(N,D,Q,R) B16_SLL1V(0,N),B16__DIV_ONCE_1(D,Q,B16_SLL1V(B16_IS_EVENr N,R))
#define B16__DIV_ONCE_1(D,Q,R) D,B16__DIV_ONCE_2(Q,R,B16_SUB(R,D))
#define B16__DIV_ONCE_2(Q,R,RD) B_IFe(B16_IS_NEG(RD))(B16_SLL1V(0,Q),R)(B16_SLL1V(1,Q),RD)

#define B32__DIV_ONCE(...) B32__DIV_ONCE_(__VA_ARGS__)
#define B32__DIV_ONCE_(N,D,Q,R) B32_SLL1V(0,N),B32__DIV_ONCE_1(D,Q,B32_SLL1V(B32_IS_EVENr N,R))
#define B32__DIV_ONCE_1(D,Q,R) D,B32__DIV_ONCE_2(Q,R,B32_SUB(R,D))
#define B32__DIV_ONCE_2(Q,R,RD) B_IFe(B32_IS_NEG(RD))(B32_SLL1V(0,Q),R)(B32_SLL1V(1,Q),RD)

#define B64__DIV_ONCE(...) B64__DIV_ONCE_(__VA_ARGS__)
#define B64__DIV_ONCE_(N,D,Q,R) B64_SLL1V(0,N),B64__DIV_ONCE_1(D,Q,B64_SLL1V(B64_IS_EVENr N,R))
#define B64__DIV_ONCE_1(D,Q,R) D,B64__DIV_ONCE_2(Q,R,B64_SUB(R,D))
#define B64__DIV_ONCE_2(Q,R,RD) B_IFe(B64_IS_NEG(RD))(B64_SLL1V(0,Q),R)(B64_SLL1V(1,Q),RD)

#define B8__DIV_FX(F,...) F(F(F(F(F(F(F(F(__VA_ARGS__))))))))
#define B16__DIV_FX(F,...) F(F(F(F(F(F(F(F(F(F(F(F(F(F(F(F(__VA_ARGS__))))))))))))))))
#define B32__DIV_FX(F,...) F(F(F(F(F(F(F(F(F(F(F(F(F(F(F(F(F(F(F(F(F(F(F(F(F(F(\
                              F(F(F(F(F(F(__VA_ARGS__))))))))))))))))))))))))))))))))
#define B64__DIV_FX(F,...) F(F(F(F(F(F(F(F(F(F(F(F(F(F(F(F(F(F(F(F(F(F(F(F(F(F(F(F( \
	F(F(F(F(F(F(F(F(F(F(F(F(F(F(F(F(F(F(F(F(F(F(F(F(F(F(F(F(F(F(F(F(F(F(F(F( \
	__VA_ARGS__))))))))))))))))))))))))))))))))))))))))))))))))))))))))))))))))


#define B__UDIV_REM_1(...) B__UDIV_REM_2(__VA_ARGS__)
#define B__UDIV_REM_2(N,D,Q,R) Q,R

#define B8_UDIV_REM(x,y) B__UDIV_REM_1(B8__DIV_FX(B8__DIV_ONCE,x,y,B8_0,B8_0))
#define B16_UDIV_REM(x,y) B__UDIV_REM_1(B16__DIV_FX(B16__DIV_ONCE,x,y,B16_0,B16_0))
#define B32_UDIV_REM(x,y) B__UDIV_REM_1(B32__DIV_FX(B32__DIV_ONCE,x,y,B32_0,B32_0))
#define B64_UDIV_REM(x,y) B__UDIV_REM_1(B64__DIV_FX(B64__DIV_ONCE,x,y,B64_0,B64_0))

#define B8_UDIV(x,y) B_FX(B_TUPLE_AT_0,B8_UDIV_REM(x,y))
#define B16_UDIV(x,y) B_FX(B_TUPLE_AT_0,B16_UDIV_REM(x,y))
#define B32_UDIV(x,y) B_FX(B_TUPLE_AT_0,B32_UDIV_REM(x,y))
#define B64_UDIV(x,y) B_FX(B_TUPLE_AT_0,B64_UDIV_REM(x,y))

#define B8_UREM(x,y) B_FX(B_TUPLE_AT_1,B8_UDIV_REM(x,y),)
#define B16_UREM(x,y) B_FX(B_TUPLE_AT_1,B16_UDIV_REM(x,y),)
#define B32_UREM(x,y) B_FX(B_TUPLE_AT_1,B32_UDIV_REM(x,y),)
#define B64_UREM(x,y) B_FX(B_TUPLE_AT_1,B64_UDIV_REM(x,y),)


B_ASSERT(B16_HEX(B16_UDIV(B16(3,3,3,3),B16(1,3,2))),0x002a)
B_ASSERT(B16_HEX(B16_UREM(B16(3,3,3,3),B16(1,3,2))),0x00ff)

B_ASSERT(B16_HEX(B16_UDIV(B16(e,2,d,d),B16(e,6,6))),0x000f)
B_ASSERT(B16_HEX(B16_UREM(B16(e,2,d,d),B16(e,6,6))),0x0ae3)



#define B__IDIV_NEG_1(n,r) B##n##_NEG(r)
#define B__IDIV_NEG_0(n,x) x

#define B__IDIV_REM(n,x,y) B__IDIV_REM_1(n,B##n##_IS_NEGr x,B##n##_IS_NEGr y,x,y)
#define B__IDIV_REM_1(n,xneg,yneg,x,y) \
	B__IDIV_REM_2(n,B1_XOR(xneg,yneg),xneg,\
			B##n##__DIV_FX(B##n##__DIV_ONCE, \
					B_CATe(B##n##_ABS,xneg)(x), \
					B_CATe(B##n##_ABS,yneg)(y),B##n##_0,B##n##_0))
#define B__IDIV_REM_2(...) B__IDIV_REM_3(__VA_ARGS__)
#define B__IDIV_REM_3(n,Qneg,Rneg,N,D,Q,R) B__IDIV_NEG_##Qneg(n,Q),B__IDIV_NEG_##Rneg(n,R)

#define B8_IDIV(x,y) B_FX(B_TUPLE_AT_0,B__IDIV_REM(8,x,y))
#define B8_IREM(x,y) B_FX(B_TUPLE_AT_1,B__IDIV_REM(8,x,y),)
#define B16_IDIV(x,y) B_FX(B_TUPLE_AT_0,B__IDIV_REM(16,x,y))
#define B16_IREM(x,y) B_FX(B_TUPLE_AT_1,B__IDIV_REM(16,x,y),)
#define B32_IDIV(x,y) B_FX(B_TUPLE_AT_0,B__IDIV_REM(32,x,y))
#define B32_IREM(x,y) B_FX(B_TUPLE_AT_1,B__IDIV_REM(32,x,y),)
#define B64_IDIV(x,y) B_FX(B_TUPLE_AT_0,B__IDIV_REM(64,x,y))
#define B64_IREM(x,y) B_FX(B_TUPLE_AT_1,B__IDIV_REM(64,x,y),)

B_ASSERT(B16_HEX(B16_IDIV(        B16(7),         B16(2))), 0x0003)
B_ASSERT(B16_HEX(B16_IDIV(B16_NEG(B16(7)),        B16(2))), 0xfffd)
B_ASSERT(B16_HEX(B16_IDIV(        B16(7), B16_NEG(B16(2)))),0xfffd)
B_ASSERT(B16_HEX(B16_IDIV(B16_NEG(B16(7)),B16_NEG(B16(2)))),0x0003)



//python3 -c "print(hex(10000))"


#define B8_DECIMAL__2(a,b,c) a##b##c
#define B8_DECIMAL__1(a,b,c) B_FX(B8_DECIMAL__2,B_TUPLE_AT_0 a,B_TUPLE_AT_0 b,B_TUPLE_AT_0 c)
#define B8_DECIMAL(x) B8_DECIMAL__1(B8_UDIV(x,(4,6)),B8_UREM(B8_UDIV(x,(a,0)),(a,0)),B8_UREM(x,(a,0)))

#define B16_DECIMAL__2(a,b,c,d,e) a##b##c##d##e
#define B16_DECIMAL__1(F,a,b,c,d,e) B_FX(B16_DECIMAL__2,F a,F b,F c,F d,F e)
#define B16_DECIMAL(x) B16_DECIMAL__1(B_TUPLE_AT_0, \
		B16_UDIV(x,(0,1,7,2)), \
		B16_UREM(B16_UDIV(x,(8,e,3,0)),(a,0,0,0)), \
		B16_UREM(B16_UDIV(x,(4,6,0,0)),(a,0,0,0)), \
		B16_UREM(B16_UDIV(x,(a,0,0,0)),(a,0,0,0)), \
		B16_UREM(x,(a,0,0,0)))


#define B32_DECIMAL__2(a,b,c,d,e,f,g,h,i,j) a##b##c##d##e##f##g##h##i##j
#define B32_DECIMAL__1(F,a,b,c,d,e,f,g,h,i,j) B_FX(B32_DECIMAL__2,F a,F b,F c,F d,F e,F f,F g,F h,F i,F j)
#define B32_DECIMAL(x) B32_DECIMAL__1(B_TUPLE_AT_0, \
		B32_UREM(B32_UDIV(x,(0,0,a,c,a,9,b,3)),B32_1(a)), \
		B32_UREM(B32_UDIV(x,(0,0,1,e,5,f,5,0)),B32_1(a)), \
		B32_UREM(B32_UDIV(x,(0,8,6,9,8,9,0,0)),B32_1(a)), \
		B32_UREM(B32_UDIV(x,(0,4,2,4,f,0,0,0)),B32_1(a)), \
		B32_UREM(B32_UDIV(x,(0,a,6,8,1,0,0,0)),B32_1(a)), \
		B32_UREM(B32_UDIV(x,(0,1,7,2,0,0,0,0)),B32_1(a)), \
		B32_UREM(B32_UDIV(x,(8,e,3,0,0,0,0,0)),B32_1(a)), \
		B32_UREM(B32_UDIV(x,(4,6,0,0,0,0,0,0)),B32_1(a)), \
		B32_UREM(B32_UDIV(x,(a,0,0,0,0,0,0,0)),B32_1(a)), \
		B32_UREM(x,B32_1(a)))

B_ASSERT(B8_DECIMAL(B8(7,b)), 123)
B_ASSERT(B16_DECIMAL(B16(3,0,4,4)), 12356)
B_ASSERT(B32_DECIMAL(B32(4,9,a,6,a,0,5,5)), 1235656789)



// memory



#define MEM__AT_f_P(...) ,MEM__AT_f
#define MEM__AT_e_P(...) ,MEM__AT_e
#define MEM__AT_d_P(...) ,MEM__AT_d
#define MEM__AT_c_P(...) ,MEM__AT_c
#define MEM__AT_b_P(...) ,MEM__AT_b
#define MEM__AT_a_P(...) ,MEM__AT_a
#define MEM__AT_9_P(...) ,MEM__AT_9
#define MEM__AT_8_P(...) ,MEM__AT_8
#define MEM__AT_7_P(...) ,MEM__AT_7
#define MEM__AT_6_P(...) ,MEM__AT_6
#define MEM__AT_5_P(...) ,MEM__AT_5
#define MEM__AT_4_P(...) ,MEM__AT_4
#define MEM__AT_3_P(...) ,MEM__AT_3
#define MEM__AT_2_P(...) ,MEM__AT_2
#define MEM__AT_1_P(...) ,MEM__AT_1

#define MEM__AT_g(M,x,...) B_CHECK(MEM__AT_f_P M,MEM__AT_0)(B4_AT_##x M,__VA_ARGS__)
#define MEM__AT_f(M,x,...) B_CHECK(MEM__AT_e_P M,MEM__AT_0)(B4_AT_##x M,__VA_ARGS__)
#define MEM__AT_e(M,x,...) B_CHECK(MEM__AT_d_P M,MEM__AT_0)(B4_AT_##x M,__VA_ARGS__)
#define MEM__AT_d(M,x,...) B_CHECK(MEM__AT_c_P M,MEM__AT_0)(B4_AT_##x M,__VA_ARGS__)
#define MEM__AT_c(M,x,...) B_CHECK(MEM__AT_b_P M,MEM__AT_0)(B4_AT_##x M,__VA_ARGS__)
#define MEM__AT_b(M,x,...) B_CHECK(MEM__AT_a_P M,MEM__AT_0)(B4_AT_##x M,__VA_ARGS__)
#define MEM__AT_a(M,x,...) B_CHECK(MEM__AT_9_P M,MEM__AT_0)(B4_AT_##x M,__VA_ARGS__)
#define MEM__AT_9(M,x,...) B_CHECK(MEM__AT_8_P M,MEM__AT_0)(B4_AT_##x M,__VA_ARGS__)
#define MEM__AT_8(M,x,...) B_CHECK(MEM__AT_7_P M,MEM__AT_0)(B4_AT_##x M,__VA_ARGS__)
#define MEM__AT_7(M,x,...) B_CHECK(MEM__AT_6_P M,MEM__AT_0)(B4_AT_##x M,__VA_ARGS__)
#define MEM__AT_6(M,x,...) B_CHECK(MEM__AT_5_P M,MEM__AT_0)(B4_AT_##x M,__VA_ARGS__)
#define MEM__AT_5(M,x,...) B_CHECK(MEM__AT_4_P M,MEM__AT_0)(B4_AT_##x M,__VA_ARGS__)
#define MEM__AT_4(M,x,...) B_CHECK(MEM__AT_3_P M,MEM__AT_0)(B4_AT_##x M,__VA_ARGS__)
#define MEM__AT_3(M,x,...) B_CHECK(MEM__AT_2_P M,MEM__AT_0)(B4_AT_##x M,__VA_ARGS__)
#define MEM__AT_2(M,x)     B_CHECK(MEM__AT_1_P M,MEM__AT_0)(B4_AT_##x M)
#define MEM__AT_1(M) M
#define MEM__AT_0(...)

#define M8_AT(x,M) B_FX(M8__AT,M,B_OPEN x)
#define M8__AT(M,a,b) MEM__AT_2(B4_AT_##b M,a)

#define M16_AT(x,M) B_FX(M16__AT,M,B_OPEN x)
#define M16__AT(M,a,b,c,d) MEM__AT_4(B4_AT_##d M,c,b,a)

#define M32_AT(x,M) B_FX(M32__AT,M,B_OPEN x)
#define M32__AT(M,a,b,c,d,e,f,g,h) MEM__AT_8(B4_AT_##h M,g,f,e,d,c,b,a)

#define M64_AT(x,M) B_FX(M64__AT,M,B_OPEN x)
#define M64__AT(M,a,b,c,d,e,f,g,h,i,j,k,l,m,n,o,p) MEM__AT_g(B4_AT_##p M,o,n,m,l,k,j,i,h,g,f,e,d,c,b,a)

B_ASSERT(M8_AT(B8(2,c),(,,(,,,,,,,,,,,,X,,,),,,,,,,,,,,,,)), X)
B_ASSERT(M16_AT(B16(2,c,1,0),(,,(,,,,,,,,,,,,(,(X,,,,,,,,,,,,,,,),,,,,,,,,,,,,,),,,),,,,,,,,,,,,,)), X)




#define MEM__FX_0(F,a,b,c,d,e,f,g,h,i,j,k,l,m,n,o,p,...) (F MEM__EMPTY()()(a,__VA_ARGS__),b,c,d,e,f,g,h,i,j,k,l,m,n,o,p)
#define MEM__FX_1(F,a,b,c,d,e,f,g,h,i,j,k,l,m,n,o,p,...) (a,F MEM__EMPTY()()(b,__VA_ARGS__),c,d,e,f,g,h,i,j,k,l,m,n,o,p)
#define MEM__FX_2(F,a,b,c,d,e,f,g,h,i,j,k,l,m,n,o,p,...) (a,b,F MEM__EMPTY()()(c,__VA_ARGS__),d,e,f,g,h,i,j,k,l,m,n,o,p)
#define MEM__FX_3(F,a,b,c,d,e,f,g,h,i,j,k,l,m,n,o,p,...) (a,b,c,F MEM__EMPTY()()(d,__VA_ARGS__),e,f,g,h,i,j,k,l,m,n,o,p)
#define MEM__FX_4(F,a,b,c,d,e,f,g,h,i,j,k,l,m,n,o,p,...) (a,b,c,d,F MEM__EMPTY()()(e,__VA_ARGS__),f,g,h,i,j,k,l,m,n,o,p)
#define MEM__FX_5(F,a,b,c,d,e,f,g,h,i,j,k,l,m,n,o,p,...) (a,b,c,d,e,F MEM__EMPTY()()(f,__VA_ARGS__),g,h,i,j,k,l,m,n,o,p)
#define MEM__FX_6(F,a,b,c,d,e,f,g,h,i,j,k,l,m,n,o,p,...) (a,b,c,d,e,f,F MEM__EMPTY()()(g,__VA_ARGS__),h,i,j,k,l,m,n,o,p)
#define MEM__FX_7(F,a,b,c,d,e,f,g,h,i,j,k,l,m,n,o,p,...) (a,b,c,d,e,f,g,F MEM__EMPTY()()(h,__VA_ARGS__),i,j,k,l,m,n,o,p)
#define MEM__FX_8(F,a,b,c,d,e,f,g,h,i,j,k,l,m,n,o,p,...) (a,b,c,d,e,f,g,h,F MEM__EMPTY()()(i,__VA_ARGS__),j,k,l,m,n,o,p)
#define MEM__FX_9(F,a,b,c,d,e,f,g,h,i,j,k,l,m,n,o,p,...) (a,b,c,d,e,f,g,h,i,F MEM__EMPTY()()(j,__VA_ARGS__),k,l,m,n,o,p)
#define MEM__FX_a(F,a,b,c,d,e,f,g,h,i,j,k,l,m,n,o,p,...) (a,b,c,d,e,f,g,h,i,j,F MEM__EMPTY()()(j,__VA_ARGS__),l,m,n,o,p)
#define MEM__FX_b(F,a,b,c,d,e,f,g,h,i,j,k,l,m,n,o,p,...) (a,b,c,d,e,f,g,h,i,j,k,F MEM__EMPTY()()(j,__VA_ARGS__),m,n,o,p)
#define MEM__FX_c(F,a,b,c,d,e,f,g,h,i,j,k,l,m,n,o,p,...) (a,b,c,d,e,f,g,h,i,j,k,l,F MEM__EMPTY()()(j,__VA_ARGS__),n,o,p)
#define MEM__FX_d(F,a,b,c,d,e,f,g,h,i,j,k,l,m,n,o,p,...) (a,b,c,d,e,f,g,h,i,j,k,l,m,F MEM__EMPTY()()(j,__VA_ARGS__),o,p)
#define MEM__FX_e(F,a,b,c,d,e,f,g,h,i,j,k,l,m,n,o,p,...) (a,b,c,d,e,f,g,h,i,j,k,l,m,n,F MEM__EMPTY()()(j,__VA_ARGS__),p)
#define MEM__FX_f(F,a,b,c,d,e,f,g,h,i,j,k,l,m,n,o,p,...) (a,b,c,d,e,f,g,h,i,j,k,l,m,n,o,F MEM__EMPTY()()(j,__VA_ARGS__))


#define MEM__PUT_FX(f,...) f(__VA_ARGS__)
#define MEM__PUT_N_PROBE(...) ,MEM__PUT_N_
#define MEM__PUT_N(F,m,...) B_CHECK(MEM__PUT_N_PROBE m,MEM__PUT_EMPTY)(F,m,__VA_ARGS__)
#define MEM__PUT_EMPTY(F,m,...) MEM__PUT_N_(F,(,,,,,,,,,,,,,,,),__VA_ARGS__)
#define MEM__PUT_N_(F,m,x,...) MEM__PUT_FX(MEM__FX_##x,F,B_SCAN m,__VA_ARGS__)

#define MEM__EVALf(...) MEM__EVAL8(MEM__EVAL8(__VA_ARGS__))
#define MEM__EVAL8(...) MEM__EVAL4(MEM__EVAL4(__VA_ARGS__))
#define MEM__EVAL4(...) MEM__EVAL1(MEM__EVAL1(MEM__EVAL1(__VA_ARGS__)))
#define MEM__EVAL2(...) MEM__EVAL1(__VA_ARGS__)
#define MEM__EVAL1(...) __VA_ARGS__
#define MEM__EMPTY()

#define MEM__PUT_f_ID() MEM__PUT_f
#define MEM__PUT_e_ID() MEM__PUT_e
#define MEM__PUT_d_ID() MEM__PUT_d
#define MEM__PUT_c_ID() MEM__PUT_c
#define MEM__PUT_b_ID() MEM__PUT_b
#define MEM__PUT_a_ID() MEM__PUT_a
#define MEM__PUT_9_ID() MEM__PUT_9
#define MEM__PUT_8_ID() MEM__PUT_8
#define MEM__PUT_7_ID() MEM__PUT_7
#define MEM__PUT_6_ID() MEM__PUT_6
#define MEM__PUT_5_ID() MEM__PUT_5
#define MEM__PUT_4_ID() MEM__PUT_4
#define MEM__PUT_3_ID() MEM__PUT_3
#define MEM__PUT_2_ID() MEM__PUT_2
#define MEM__PUT_1_ID() MEM__PUT_1
#define MEM__PUT_0_ID() MEM__PUT_0

#define MEM__PUT_f(m,x,...) MEM__PUT_N(MEM__PUT_e_ID,m,x,__VA_ARGS__)
#define MEM__PUT_e(m,x,...) MEM__PUT_N(MEM__PUT_d_ID,m,x,__VA_ARGS__)
#define MEM__PUT_d(m,x,...) MEM__PUT_N(MEM__PUT_c_ID,m,x,__VA_ARGS__)
#define MEM__PUT_c(m,x,...) MEM__PUT_N(MEM__PUT_b_ID,m,x,__VA_ARGS__)
#define MEM__PUT_b(m,x,...) MEM__PUT_N(MEM__PUT_a_ID,m,x,__VA_ARGS__)
#define MEM__PUT_a(m,x,...) MEM__PUT_N(MEM__PUT_9_ID,m,x,__VA_ARGS__)
#define MEM__PUT_9(m,x,...) MEM__PUT_N(MEM__PUT_8_ID,m,x,__VA_ARGS__)
#define MEM__PUT_8(m,x,...) MEM__PUT_N(MEM__PUT_7_ID,m,x,__VA_ARGS__)
#define MEM__PUT_7(m,x,...) MEM__PUT_N(MEM__PUT_6_ID,m,x,__VA_ARGS__)
#define MEM__PUT_6(m,x,...) MEM__PUT_N(MEM__PUT_5_ID,m,x,__VA_ARGS__)
#define MEM__PUT_5(m,x,...) MEM__PUT_N(MEM__PUT_4_ID,m,x,__VA_ARGS__)
#define MEM__PUT_4(m,x,...) MEM__PUT_N(MEM__PUT_3_ID,m,x,__VA_ARGS__)
#define MEM__PUT_3(m,x,...) MEM__PUT_N(MEM__PUT_2_ID,m,x,__VA_ARGS__)
#define MEM__PUT_2(m,x,...) MEM__PUT_N(MEM__PUT_1_ID,m,x,__VA_ARGS__)
#define MEM__PUT_1(m,x,...) MEM__PUT_N(MEM__PUT_0_ID,m,x,__VA_ARGS__)
#define MEM__PUT_0(m,x)  x


#define M8_PUT(x,v,M) MEM__EVAL2(B_FX(M8__PUT,M,v,B_OPEN x))
#define M8__PUT(M,v,a,b) MEM__PUT_N(MEM__PUT_1_ID,M,b,a,v)

#define M16_PUT(x,v,M) MEM__EVAL4(B_FX(M16__PUT,M,v,B_OPEN x))
#define M16__PUT(M,v,a,b,c,d) MEM__PUT_N(MEM__PUT_3_ID,M,d,c,b,a,v)

#define M32_PUT(x,v,M) MEM__EVAL8(B_FX(M32__PUT,M,v,B_OPEN x))
#define M32__PUT(M,v,a,b,c,d,e,f,g,h) MEM__PUT_N(MEM__PUT_7_ID,M,h,g,f,e,d,c,b,a,v)

#define M64_PUT(x,v,M) MEM__EVALf(B_FX(M64__PUT,M,v,B_OPEN x))
#define M64__PUT(M,v,a,b,c,d,e,f,g,h,i,j,k,l,m,n,o,p) \
		MEM__PUT_N(MEM__PUT_f_ID,M,p,o,n,m,l,k,j,i,h,g,f,e,d,c,b,a,v)


B_ASSERT(M8_AT(B8(1,3),M8_PUT(B8(1,4),Y,M8_PUT(B8(1,3),X,))), X)
B_ASSERT(M16_AT(B16(3,1,2,f),M16_PUT(B16(3,1,2,f),X,)), X)
B_ASSERT(M16_AT(B16(3,1,f),M16_PUT(B16(3,1,f),X,)), X)
B_ASSERT(M32_AT(B32(3,1,2,f,1),M32_PUT(B32(3,1,2,f,1),X,)), X)
B_ASSERT(M64_AT(B64(1,2,3,3,1,2,f),M64_PUT(B64(1,2,3,3,1,2,f),X,)), X)


#if B_ASSERT_ENABLE
}
#endif
