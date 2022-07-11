#define CM_SCAN(...) __VA_ARGS__
#define CM_EAT(...)
#define CM_LPAREN (

#define CM0(...)  CM_SCAN(CM_EAT CM_LPAREN CM0__00(__VA_ARGS__))
#define CM1(...)  CM_SCAN(CM_EAT CM_LPAREN CM1__00(__VA_ARGS__))
#define CM2(...)  CM_SCAN(CM_EAT CM_LPAREN CM2__00(__VA_ARGS__))
#define CM3(...)  CM_SCAN(CM_EAT CM_LPAREN CM3__00(__VA_ARGS__))
#define CM4(...)  CM_SCAN(CM_EAT CM_LPAREN CM4__00(__VA_ARGS__))
#define CM5(...)  CM_SCAN(CM_EAT CM_LPAREN CM5__00(__VA_ARGS__))
#define CM6(...)  CM_SCAN(CM_EAT CM_LPAREN CM6__00(__VA_ARGS__))
#define CM7(...)  CM_SCAN(CM_EAT CM_LPAREN CM7__00(__VA_ARGS__))
#define CM8(...)  CM_SCAN(CM_EAT CM_LPAREN CM8__00(__VA_ARGS__))
#define CM9(...)  CM_SCAN(CM_EAT CM_LPAREN CM9__00(__VA_ARGS__))
#define CMa(...)  CM_SCAN(CM_EAT CM_LPAREN CMa__00(__VA_ARGS__))
#define CMb(...)  CM_SCAN(CM_EAT CM_LPAREN CMb__00(__VA_ARGS__))
#define CMc(...)  CM_SCAN(CM_EAT CM_LPAREN CMc__00(__VA_ARGS__))
#define CMd(...)  CM_SCAN(CM_EAT CM_LPAREN CMd__00(__VA_ARGS__))
#define CMe(...)  CM_SCAN(CM_EAT CM_LPAREN CMe__00(__VA_ARGS__))
#define CMf(...)  CM_SCAN(CM_EAT CM_LPAREN CMf__00(__VA_ARGS__))

#define CM_PROBE ),1,(
#define CM_IF(x) CM_IF_(x,0,)
#define CM_IF_(b,a,...) CM_IF_##a
#define CM_IF_1(a,b) a
#define CM_IF_0(a,b) b

#define CM \
	CM_IF(CM7__00(CM_,,PROBE))( \
	      CM_IF(CM3__00(CM_,,PROBE))( \
	            CM_IF(CM1__00(CM_,,PROBE))( \
	                  CM_IF(CM0__00(CM_,,PROBE))(CM0,CM1), \
	                  CM_IF(CM2__00(CM_,,PROBE))(CM2,CM3)), \
	            CM_IF(CM5__00(CM_,,PROBE))( \
	                  CM_IF(CM4__00(CM_,,PROBE))(CM4,CM5), \
	                  CM_IF(CM6__00(CM_,,PROBE))(CM6,CM7))), \
	      CM_IF(CMb__00(CM_,,PROBE))( \
	            CM_IF(CM9__00(CM_,,PROBE))( \
	                  CM_IF(CM8__00(CM_,,PROBE))(CM8,CM9), \
	                  CM_IF(CMa__00(CM_,,PROBE))(CMa,CMb)), \
	            CM_IF(CMd__00(CM_,,PROBE))( \
	                  CM_IF(CMc__00(CM_,,PROBE))(CMc,CMd), \
	                  CM_IF(CMe__00(CM_,,PROBE))(CMe,CMf)))) \

#define CM0__00(P,f,...) CM0_P01(CM0_P01(CM_##f(,P##__VA_ARGS__)))
#define CM0__01(P,f,...) CM0_P02(CM0_P02(CM_##f(,P##__VA_ARGS__)))
#define CM0__02(P,f,...) CM0_P03(CM0_P03(CM_##f(,P##__VA_ARGS__)))
#define CM0__03(P,f,...) CM0_P04(CM0_P04(CM_##f(,P##__VA_ARGS__)))
#define CM0__04(P,f,...) CM0_P05(CM0_P05(CM_##f(,P##__VA_ARGS__)))
#define CM0__05(P,f,...) CM0_P06(CM0_P06(CM_##f(,P##__VA_ARGS__)))
#define CM0__06(P,f,...) CM0_P07(CM0_P07(CM_##f(,P##__VA_ARGS__)))
#define CM0__07(P,f,...) CM0_P08(CM0_P08(CM_##f(,P##__VA_ARGS__)))
#define CM0__08(P,f,...) CM0_P09(CM0_P09(CM_##f(,P##__VA_ARGS__)))
#define CM0__09(P,f,...) CM0_P0a(CM0_P0a(CM_##f(,P##__VA_ARGS__)))
#define CM0__0a(P,f,...) CM0_P0b(CM0_P0b(CM_##f(,P##__VA_ARGS__)))
#define CM0__0b(P,f,...) CM0_P0c(CM0_P0c(CM_##f(,P##__VA_ARGS__)))
#define CM0__0c(P,f,...) CM0_P0d(CM0_P0d(CM_##f(,P##__VA_ARGS__)))
#define CM0__0d(P,f,...) CM0_P0e(CM0_P0e(CM_##f(,P##__VA_ARGS__)))
#define CM0__0e(P,f,...) CM0_P0f(CM0_P0f(CM_##f(,P##__VA_ARGS__)))
#define CM0__0f(P,f,...) CM0_P10(CM0_P10(CM_##f(,P##__VA_ARGS__)))
#define CM0__10(P,f,...) CM0_P11(CM0_P11(CM_##f(,P##__VA_ARGS__)))
#define CM0__11(P,f,...) CM0_P12(CM0_P12(CM_##f(,P##__VA_ARGS__)))
#define CM0__12(P,f,...) CM0_P13(CM0_P13(CM_##f(,P##__VA_ARGS__)))
#define CM0__13(P,f,...) CM0_P14(CM0_P14(CM_##f(,P##__VA_ARGS__)))
#define CM0__14(P,f,...) CM0_P15(CM0_P15(CM_##f(,P##__VA_ARGS__)))
#define CM0__15(P,f,...) CM0_P16(CM0_P16(CM_##f(,P##__VA_ARGS__)))
#define CM0__16(P,f,...) CM0_P17(CM0_P17(CM_##f(,P##__VA_ARGS__)))
#define CM0__17(P,f,...) CM0_P18(CM0_P18(CM_##f(,P##__VA_ARGS__)))
#define CM0__18(P,f,...) CM0_P19(CM0_P19(CM_##f(,P##__VA_ARGS__)))
#define CM0__19(P,f,...) CM0_P1a(CM0_P1a(CM_##f(,P##__VA_ARGS__)))
#define CM0__1a(P,f,...) CM0_P1b(CM0_P1b(CM_##f(,P##__VA_ARGS__)))
#define CM0__1b(P,f,...) CM0_P1c(CM0_P1c(CM_##f(,P##__VA_ARGS__)))
#define CM0__1c(P,f,...) CM0_P1d(CM0_P1d(CM_##f(,P##__VA_ARGS__)))
#define CM0__1d(P,f,...) CM0_P1e(CM0_P1e(CM_##f(,P##__VA_ARGS__)))
#define CM0__1e(P,f,...) CM0_P1f(CM0_P1f(CM_##f(,P##__VA_ARGS__)))
#define CM0__1f(P,f,...) CM_##f(,P##__VA_ARGS__)

#define CM0_P01(x) CM0__01 x
#define CM0_P02(x) CM0__02 x
#define CM0_P03(x) CM0__03 x
#define CM0_P04(x) CM0__04 x
#define CM0_P05(x) CM0__05 x
#define CM0_P06(x) CM0__06 x
#define CM0_P07(x) CM0__07 x
#define CM0_P08(x) CM0__08 x
#define CM0_P09(x) CM0__09 x
#define CM0_P0a(x) CM0__0a x
#define CM0_P0b(x) CM0__0b x
#define CM0_P0c(x) CM0__0c x
#define CM0_P0d(x) CM0__0d x
#define CM0_P0e(x) CM0__0e x
#define CM0_P0f(x) CM0__0f x
#define CM0_P10(x) CM0__10 x
#define CM0_P11(x) CM0__11 x
#define CM0_P12(x) CM0__12 x
#define CM0_P13(x) CM0__13 x
#define CM0_P14(x) CM0__14 x
#define CM0_P15(x) CM0__15 x
#define CM0_P16(x) CM0__16 x
#define CM0_P17(x) CM0__17 x
#define CM0_P18(x) CM0__18 x
#define CM0_P19(x) CM0__19 x
#define CM0_P1a(x) CM0__1a x
#define CM0_P1b(x) CM0__1b x
#define CM0_P1c(x) CM0__1c x
#define CM0_P1d(x) CM0__1d x
#define CM0_P1e(x) CM0__1e x
#define CM0_P1f(x) CM0__1f x

#define CM1__00(P,f,...) CM1_P01(CM1_P01(CM_##f(,P##__VA_ARGS__)))
#define CM1__01(P,f,...) CM1_P02(CM1_P02(CM_##f(,P##__VA_ARGS__)))
#define CM1__02(P,f,...) CM1_P03(CM1_P03(CM_##f(,P##__VA_ARGS__)))
#define CM1__03(P,f,...) CM1_P04(CM1_P04(CM_##f(,P##__VA_ARGS__)))
#define CM1__04(P,f,...) CM1_P05(CM1_P05(CM_##f(,P##__VA_ARGS__)))
#define CM1__05(P,f,...) CM1_P06(CM1_P06(CM_##f(,P##__VA_ARGS__)))
#define CM1__06(P,f,...) CM1_P07(CM1_P07(CM_##f(,P##__VA_ARGS__)))
#define CM1__07(P,f,...) CM1_P08(CM1_P08(CM_##f(,P##__VA_ARGS__)))
#define CM1__08(P,f,...) CM1_P09(CM1_P09(CM_##f(,P##__VA_ARGS__)))
#define CM1__09(P,f,...) CM1_P0a(CM1_P0a(CM_##f(,P##__VA_ARGS__)))
#define CM1__0a(P,f,...) CM1_P0b(CM1_P0b(CM_##f(,P##__VA_ARGS__)))
#define CM1__0b(P,f,...) CM1_P0c(CM1_P0c(CM_##f(,P##__VA_ARGS__)))
#define CM1__0c(P,f,...) CM1_P0d(CM1_P0d(CM_##f(,P##__VA_ARGS__)))
#define CM1__0d(P,f,...) CM1_P0e(CM1_P0e(CM_##f(,P##__VA_ARGS__)))
#define CM1__0e(P,f,...) CM1_P0f(CM1_P0f(CM_##f(,P##__VA_ARGS__)))
#define CM1__0f(P,f,...) CM1_P10(CM1_P10(CM_##f(,P##__VA_ARGS__)))
#define CM1__10(P,f,...) CM1_P11(CM1_P11(CM_##f(,P##__VA_ARGS__)))
#define CM1__11(P,f,...) CM1_P12(CM1_P12(CM_##f(,P##__VA_ARGS__)))
#define CM1__12(P,f,...) CM1_P13(CM1_P13(CM_##f(,P##__VA_ARGS__)))
#define CM1__13(P,f,...) CM1_P14(CM1_P14(CM_##f(,P##__VA_ARGS__)))
#define CM1__14(P,f,...) CM1_P15(CM1_P15(CM_##f(,P##__VA_ARGS__)))
#define CM1__15(P,f,...) CM1_P16(CM1_P16(CM_##f(,P##__VA_ARGS__)))
#define CM1__16(P,f,...) CM1_P17(CM1_P17(CM_##f(,P##__VA_ARGS__)))
#define CM1__17(P,f,...) CM1_P18(CM1_P18(CM_##f(,P##__VA_ARGS__)))
#define CM1__18(P,f,...) CM1_P19(CM1_P19(CM_##f(,P##__VA_ARGS__)))
#define CM1__19(P,f,...) CM1_P1a(CM1_P1a(CM_##f(,P##__VA_ARGS__)))
#define CM1__1a(P,f,...) CM1_P1b(CM1_P1b(CM_##f(,P##__VA_ARGS__)))
#define CM1__1b(P,f,...) CM1_P1c(CM1_P1c(CM_##f(,P##__VA_ARGS__)))
#define CM1__1c(P,f,...) CM1_P1d(CM1_P1d(CM_##f(,P##__VA_ARGS__)))
#define CM1__1d(P,f,...) CM1_P1e(CM1_P1e(CM_##f(,P##__VA_ARGS__)))
#define CM1__1e(P,f,...) CM1_P1f(CM1_P1f(CM_##f(,P##__VA_ARGS__)))
#define CM1__1f(P,f,...) CM_##f(,P##__VA_ARGS__)

#define CM1_P01(x) CM1__01 x
#define CM1_P02(x) CM1__02 x
#define CM1_P03(x) CM1__03 x
#define CM1_P04(x) CM1__04 x
#define CM1_P05(x) CM1__05 x
#define CM1_P06(x) CM1__06 x
#define CM1_P07(x) CM1__07 x
#define CM1_P08(x) CM1__08 x
#define CM1_P09(x) CM1__09 x
#define CM1_P0a(x) CM1__0a x
#define CM1_P0b(x) CM1__0b x
#define CM1_P0c(x) CM1__0c x
#define CM1_P0d(x) CM1__0d x
#define CM1_P0e(x) CM1__0e x
#define CM1_P0f(x) CM1__0f x
#define CM1_P10(x) CM1__10 x
#define CM1_P11(x) CM1__11 x
#define CM1_P12(x) CM1__12 x
#define CM1_P13(x) CM1__13 x
#define CM1_P14(x) CM1__14 x
#define CM1_P15(x) CM1__15 x
#define CM1_P16(x) CM1__16 x
#define CM1_P17(x) CM1__17 x
#define CM1_P18(x) CM1__18 x
#define CM1_P19(x) CM1__19 x
#define CM1_P1a(x) CM1__1a x
#define CM1_P1b(x) CM1__1b x
#define CM1_P1c(x) CM1__1c x
#define CM1_P1d(x) CM1__1d x
#define CM1_P1e(x) CM1__1e x
#define CM1_P1f(x) CM1__1f x

#define CM2__00(P,f,...) CM2_P01(CM2_P01(CM_##f(,P##__VA_ARGS__)))
#define CM2__01(P,f,...) CM2_P02(CM2_P02(CM_##f(,P##__VA_ARGS__)))
#define CM2__02(P,f,...) CM2_P03(CM2_P03(CM_##f(,P##__VA_ARGS__)))
#define CM2__03(P,f,...) CM2_P04(CM2_P04(CM_##f(,P##__VA_ARGS__)))
#define CM2__04(P,f,...) CM2_P05(CM2_P05(CM_##f(,P##__VA_ARGS__)))
#define CM2__05(P,f,...) CM2_P06(CM2_P06(CM_##f(,P##__VA_ARGS__)))
#define CM2__06(P,f,...) CM2_P07(CM2_P07(CM_##f(,P##__VA_ARGS__)))
#define CM2__07(P,f,...) CM2_P08(CM2_P08(CM_##f(,P##__VA_ARGS__)))
#define CM2__08(P,f,...) CM2_P09(CM2_P09(CM_##f(,P##__VA_ARGS__)))
#define CM2__09(P,f,...) CM2_P0a(CM2_P0a(CM_##f(,P##__VA_ARGS__)))
#define CM2__0a(P,f,...) CM2_P0b(CM2_P0b(CM_##f(,P##__VA_ARGS__)))
#define CM2__0b(P,f,...) CM2_P0c(CM2_P0c(CM_##f(,P##__VA_ARGS__)))
#define CM2__0c(P,f,...) CM2_P0d(CM2_P0d(CM_##f(,P##__VA_ARGS__)))
#define CM2__0d(P,f,...) CM2_P0e(CM2_P0e(CM_##f(,P##__VA_ARGS__)))
#define CM2__0e(P,f,...) CM2_P0f(CM2_P0f(CM_##f(,P##__VA_ARGS__)))
#define CM2__0f(P,f,...) CM2_P10(CM2_P10(CM_##f(,P##__VA_ARGS__)))
#define CM2__10(P,f,...) CM2_P11(CM2_P11(CM_##f(,P##__VA_ARGS__)))
#define CM2__11(P,f,...) CM2_P12(CM2_P12(CM_##f(,P##__VA_ARGS__)))
#define CM2__12(P,f,...) CM2_P13(CM2_P13(CM_##f(,P##__VA_ARGS__)))
#define CM2__13(P,f,...) CM2_P14(CM2_P14(CM_##f(,P##__VA_ARGS__)))
#define CM2__14(P,f,...) CM2_P15(CM2_P15(CM_##f(,P##__VA_ARGS__)))
#define CM2__15(P,f,...) CM2_P16(CM2_P16(CM_##f(,P##__VA_ARGS__)))
#define CM2__16(P,f,...) CM2_P17(CM2_P17(CM_##f(,P##__VA_ARGS__)))
#define CM2__17(P,f,...) CM2_P18(CM2_P18(CM_##f(,P##__VA_ARGS__)))
#define CM2__18(P,f,...) CM2_P19(CM2_P19(CM_##f(,P##__VA_ARGS__)))
#define CM2__19(P,f,...) CM2_P1a(CM2_P1a(CM_##f(,P##__VA_ARGS__)))
#define CM2__1a(P,f,...) CM2_P1b(CM2_P1b(CM_##f(,P##__VA_ARGS__)))
#define CM2__1b(P,f,...) CM2_P1c(CM2_P1c(CM_##f(,P##__VA_ARGS__)))
#define CM2__1c(P,f,...) CM2_P1d(CM2_P1d(CM_##f(,P##__VA_ARGS__)))
#define CM2__1d(P,f,...) CM2_P1e(CM2_P1e(CM_##f(,P##__VA_ARGS__)))
#define CM2__1e(P,f,...) CM2_P1f(CM2_P1f(CM_##f(,P##__VA_ARGS__)))
#define CM2__1f(P,f,...) CM_##f(,P##__VA_ARGS__)

#define CM2_P01(x) CM2__01 x
#define CM2_P02(x) CM2__02 x
#define CM2_P03(x) CM2__03 x
#define CM2_P04(x) CM2__04 x
#define CM2_P05(x) CM2__05 x
#define CM2_P06(x) CM2__06 x
#define CM2_P07(x) CM2__07 x
#define CM2_P08(x) CM2__08 x
#define CM2_P09(x) CM2__09 x
#define CM2_P0a(x) CM2__0a x
#define CM2_P0b(x) CM2__0b x
#define CM2_P0c(x) CM2__0c x
#define CM2_P0d(x) CM2__0d x
#define CM2_P0e(x) CM2__0e x
#define CM2_P0f(x) CM2__0f x
#define CM2_P10(x) CM2__10 x
#define CM2_P11(x) CM2__11 x
#define CM2_P12(x) CM2__12 x
#define CM2_P13(x) CM2__13 x
#define CM2_P14(x) CM2__14 x
#define CM2_P15(x) CM2__15 x
#define CM2_P16(x) CM2__16 x
#define CM2_P17(x) CM2__17 x
#define CM2_P18(x) CM2__18 x
#define CM2_P19(x) CM2__19 x
#define CM2_P1a(x) CM2__1a x
#define CM2_P1b(x) CM2__1b x
#define CM2_P1c(x) CM2__1c x
#define CM2_P1d(x) CM2__1d x
#define CM2_P1e(x) CM2__1e x
#define CM2_P1f(x) CM2__1f x

#define CM3__00(P,f,...) CM3_P01(CM3_P01(CM_##f(,P##__VA_ARGS__)))
#define CM3__01(P,f,...) CM3_P02(CM3_P02(CM_##f(,P##__VA_ARGS__)))
#define CM3__02(P,f,...) CM3_P03(CM3_P03(CM_##f(,P##__VA_ARGS__)))
#define CM3__03(P,f,...) CM3_P04(CM3_P04(CM_##f(,P##__VA_ARGS__)))
#define CM3__04(P,f,...) CM3_P05(CM3_P05(CM_##f(,P##__VA_ARGS__)))
#define CM3__05(P,f,...) CM3_P06(CM3_P06(CM_##f(,P##__VA_ARGS__)))
#define CM3__06(P,f,...) CM3_P07(CM3_P07(CM_##f(,P##__VA_ARGS__)))
#define CM3__07(P,f,...) CM3_P08(CM3_P08(CM_##f(,P##__VA_ARGS__)))
#define CM3__08(P,f,...) CM3_P09(CM3_P09(CM_##f(,P##__VA_ARGS__)))
#define CM3__09(P,f,...) CM3_P0a(CM3_P0a(CM_##f(,P##__VA_ARGS__)))
#define CM3__0a(P,f,...) CM3_P0b(CM3_P0b(CM_##f(,P##__VA_ARGS__)))
#define CM3__0b(P,f,...) CM3_P0c(CM3_P0c(CM_##f(,P##__VA_ARGS__)))
#define CM3__0c(P,f,...) CM3_P0d(CM3_P0d(CM_##f(,P##__VA_ARGS__)))
#define CM3__0d(P,f,...) CM3_P0e(CM3_P0e(CM_##f(,P##__VA_ARGS__)))
#define CM3__0e(P,f,...) CM3_P0f(CM3_P0f(CM_##f(,P##__VA_ARGS__)))
#define CM3__0f(P,f,...) CM3_P10(CM3_P10(CM_##f(,P##__VA_ARGS__)))
#define CM3__10(P,f,...) CM3_P11(CM3_P11(CM_##f(,P##__VA_ARGS__)))
#define CM3__11(P,f,...) CM3_P12(CM3_P12(CM_##f(,P##__VA_ARGS__)))
#define CM3__12(P,f,...) CM3_P13(CM3_P13(CM_##f(,P##__VA_ARGS__)))
#define CM3__13(P,f,...) CM3_P14(CM3_P14(CM_##f(,P##__VA_ARGS__)))
#define CM3__14(P,f,...) CM3_P15(CM3_P15(CM_##f(,P##__VA_ARGS__)))
#define CM3__15(P,f,...) CM3_P16(CM3_P16(CM_##f(,P##__VA_ARGS__)))
#define CM3__16(P,f,...) CM3_P17(CM3_P17(CM_##f(,P##__VA_ARGS__)))
#define CM3__17(P,f,...) CM3_P18(CM3_P18(CM_##f(,P##__VA_ARGS__)))
#define CM3__18(P,f,...) CM3_P19(CM3_P19(CM_##f(,P##__VA_ARGS__)))
#define CM3__19(P,f,...) CM3_P1a(CM3_P1a(CM_##f(,P##__VA_ARGS__)))
#define CM3__1a(P,f,...) CM3_P1b(CM3_P1b(CM_##f(,P##__VA_ARGS__)))
#define CM3__1b(P,f,...) CM3_P1c(CM3_P1c(CM_##f(,P##__VA_ARGS__)))
#define CM3__1c(P,f,...) CM3_P1d(CM3_P1d(CM_##f(,P##__VA_ARGS__)))
#define CM3__1d(P,f,...) CM3_P1e(CM3_P1e(CM_##f(,P##__VA_ARGS__)))
#define CM3__1e(P,f,...) CM3_P1f(CM3_P1f(CM_##f(,P##__VA_ARGS__)))
#define CM3__1f(P,f,...) CM_##f(,P##__VA_ARGS__)

#define CM3_P01(x) CM3__01 x
#define CM3_P02(x) CM3__02 x
#define CM3_P03(x) CM3__03 x
#define CM3_P04(x) CM3__04 x
#define CM3_P05(x) CM3__05 x
#define CM3_P06(x) CM3__06 x
#define CM3_P07(x) CM3__07 x
#define CM3_P08(x) CM3__08 x
#define CM3_P09(x) CM3__09 x
#define CM3_P0a(x) CM3__0a x
#define CM3_P0b(x) CM3__0b x
#define CM3_P0c(x) CM3__0c x
#define CM3_P0d(x) CM3__0d x
#define CM3_P0e(x) CM3__0e x
#define CM3_P0f(x) CM3__0f x
#define CM3_P10(x) CM3__10 x
#define CM3_P11(x) CM3__11 x
#define CM3_P12(x) CM3__12 x
#define CM3_P13(x) CM3__13 x
#define CM3_P14(x) CM3__14 x
#define CM3_P15(x) CM3__15 x
#define CM3_P16(x) CM3__16 x
#define CM3_P17(x) CM3__17 x
#define CM3_P18(x) CM3__18 x
#define CM3_P19(x) CM3__19 x
#define CM3_P1a(x) CM3__1a x
#define CM3_P1b(x) CM3__1b x
#define CM3_P1c(x) CM3__1c x
#define CM3_P1d(x) CM3__1d x
#define CM3_P1e(x) CM3__1e x
#define CM3_P1f(x) CM3__1f x

#define CM4__00(P,f,...) CM4_P01(CM4_P01(CM_##f(,P##__VA_ARGS__)))
#define CM4__01(P,f,...) CM4_P02(CM4_P02(CM_##f(,P##__VA_ARGS__)))
#define CM4__02(P,f,...) CM4_P03(CM4_P03(CM_##f(,P##__VA_ARGS__)))
#define CM4__03(P,f,...) CM4_P04(CM4_P04(CM_##f(,P##__VA_ARGS__)))
#define CM4__04(P,f,...) CM4_P05(CM4_P05(CM_##f(,P##__VA_ARGS__)))
#define CM4__05(P,f,...) CM4_P06(CM4_P06(CM_##f(,P##__VA_ARGS__)))
#define CM4__06(P,f,...) CM4_P07(CM4_P07(CM_##f(,P##__VA_ARGS__)))
#define CM4__07(P,f,...) CM4_P08(CM4_P08(CM_##f(,P##__VA_ARGS__)))
#define CM4__08(P,f,...) CM4_P09(CM4_P09(CM_##f(,P##__VA_ARGS__)))
#define CM4__09(P,f,...) CM4_P0a(CM4_P0a(CM_##f(,P##__VA_ARGS__)))
#define CM4__0a(P,f,...) CM4_P0b(CM4_P0b(CM_##f(,P##__VA_ARGS__)))
#define CM4__0b(P,f,...) CM4_P0c(CM4_P0c(CM_##f(,P##__VA_ARGS__)))
#define CM4__0c(P,f,...) CM4_P0d(CM4_P0d(CM_##f(,P##__VA_ARGS__)))
#define CM4__0d(P,f,...) CM4_P0e(CM4_P0e(CM_##f(,P##__VA_ARGS__)))
#define CM4__0e(P,f,...) CM4_P0f(CM4_P0f(CM_##f(,P##__VA_ARGS__)))
#define CM4__0f(P,f,...) CM4_P10(CM4_P10(CM_##f(,P##__VA_ARGS__)))
#define CM4__10(P,f,...) CM4_P11(CM4_P11(CM_##f(,P##__VA_ARGS__)))
#define CM4__11(P,f,...) CM4_P12(CM4_P12(CM_##f(,P##__VA_ARGS__)))
#define CM4__12(P,f,...) CM4_P13(CM4_P13(CM_##f(,P##__VA_ARGS__)))
#define CM4__13(P,f,...) CM4_P14(CM4_P14(CM_##f(,P##__VA_ARGS__)))
#define CM4__14(P,f,...) CM4_P15(CM4_P15(CM_##f(,P##__VA_ARGS__)))
#define CM4__15(P,f,...) CM4_P16(CM4_P16(CM_##f(,P##__VA_ARGS__)))
#define CM4__16(P,f,...) CM4_P17(CM4_P17(CM_##f(,P##__VA_ARGS__)))
#define CM4__17(P,f,...) CM4_P18(CM4_P18(CM_##f(,P##__VA_ARGS__)))
#define CM4__18(P,f,...) CM4_P19(CM4_P19(CM_##f(,P##__VA_ARGS__)))
#define CM4__19(P,f,...) CM4_P1a(CM4_P1a(CM_##f(,P##__VA_ARGS__)))
#define CM4__1a(P,f,...) CM4_P1b(CM4_P1b(CM_##f(,P##__VA_ARGS__)))
#define CM4__1b(P,f,...) CM4_P1c(CM4_P1c(CM_##f(,P##__VA_ARGS__)))
#define CM4__1c(P,f,...) CM4_P1d(CM4_P1d(CM_##f(,P##__VA_ARGS__)))
#define CM4__1d(P,f,...) CM4_P1e(CM4_P1e(CM_##f(,P##__VA_ARGS__)))
#define CM4__1e(P,f,...) CM4_P1f(CM4_P1f(CM_##f(,P##__VA_ARGS__)))
#define CM4__1f(P,f,...) CM_##f(,P##__VA_ARGS__)

#define CM4_P01(x) CM4__01 x
#define CM4_P02(x) CM4__02 x
#define CM4_P03(x) CM4__03 x
#define CM4_P04(x) CM4__04 x
#define CM4_P05(x) CM4__05 x
#define CM4_P06(x) CM4__06 x
#define CM4_P07(x) CM4__07 x
#define CM4_P08(x) CM4__08 x
#define CM4_P09(x) CM4__09 x
#define CM4_P0a(x) CM4__0a x
#define CM4_P0b(x) CM4__0b x
#define CM4_P0c(x) CM4__0c x
#define CM4_P0d(x) CM4__0d x
#define CM4_P0e(x) CM4__0e x
#define CM4_P0f(x) CM4__0f x
#define CM4_P10(x) CM4__10 x
#define CM4_P11(x) CM4__11 x
#define CM4_P12(x) CM4__12 x
#define CM4_P13(x) CM4__13 x
#define CM4_P14(x) CM4__14 x
#define CM4_P15(x) CM4__15 x
#define CM4_P16(x) CM4__16 x
#define CM4_P17(x) CM4__17 x
#define CM4_P18(x) CM4__18 x
#define CM4_P19(x) CM4__19 x
#define CM4_P1a(x) CM4__1a x
#define CM4_P1b(x) CM4__1b x
#define CM4_P1c(x) CM4__1c x
#define CM4_P1d(x) CM4__1d x
#define CM4_P1e(x) CM4__1e x
#define CM4_P1f(x) CM4__1f x

#define CM5__00(P,f,...) CM5_P01(CM5_P01(CM_##f(,P##__VA_ARGS__)))
#define CM5__01(P,f,...) CM5_P02(CM5_P02(CM_##f(,P##__VA_ARGS__)))
#define CM5__02(P,f,...) CM5_P03(CM5_P03(CM_##f(,P##__VA_ARGS__)))
#define CM5__03(P,f,...) CM5_P04(CM5_P04(CM_##f(,P##__VA_ARGS__)))
#define CM5__04(P,f,...) CM5_P05(CM5_P05(CM_##f(,P##__VA_ARGS__)))
#define CM5__05(P,f,...) CM5_P06(CM5_P06(CM_##f(,P##__VA_ARGS__)))
#define CM5__06(P,f,...) CM5_P07(CM5_P07(CM_##f(,P##__VA_ARGS__)))
#define CM5__07(P,f,...) CM5_P08(CM5_P08(CM_##f(,P##__VA_ARGS__)))
#define CM5__08(P,f,...) CM5_P09(CM5_P09(CM_##f(,P##__VA_ARGS__)))
#define CM5__09(P,f,...) CM5_P0a(CM5_P0a(CM_##f(,P##__VA_ARGS__)))
#define CM5__0a(P,f,...) CM5_P0b(CM5_P0b(CM_##f(,P##__VA_ARGS__)))
#define CM5__0b(P,f,...) CM5_P0c(CM5_P0c(CM_##f(,P##__VA_ARGS__)))
#define CM5__0c(P,f,...) CM5_P0d(CM5_P0d(CM_##f(,P##__VA_ARGS__)))
#define CM5__0d(P,f,...) CM5_P0e(CM5_P0e(CM_##f(,P##__VA_ARGS__)))
#define CM5__0e(P,f,...) CM5_P0f(CM5_P0f(CM_##f(,P##__VA_ARGS__)))
#define CM5__0f(P,f,...) CM5_P10(CM5_P10(CM_##f(,P##__VA_ARGS__)))
#define CM5__10(P,f,...) CM5_P11(CM5_P11(CM_##f(,P##__VA_ARGS__)))
#define CM5__11(P,f,...) CM5_P12(CM5_P12(CM_##f(,P##__VA_ARGS__)))
#define CM5__12(P,f,...) CM5_P13(CM5_P13(CM_##f(,P##__VA_ARGS__)))
#define CM5__13(P,f,...) CM5_P14(CM5_P14(CM_##f(,P##__VA_ARGS__)))
#define CM5__14(P,f,...) CM5_P15(CM5_P15(CM_##f(,P##__VA_ARGS__)))
#define CM5__15(P,f,...) CM5_P16(CM5_P16(CM_##f(,P##__VA_ARGS__)))
#define CM5__16(P,f,...) CM5_P17(CM5_P17(CM_##f(,P##__VA_ARGS__)))
#define CM5__17(P,f,...) CM5_P18(CM5_P18(CM_##f(,P##__VA_ARGS__)))
#define CM5__18(P,f,...) CM5_P19(CM5_P19(CM_##f(,P##__VA_ARGS__)))
#define CM5__19(P,f,...) CM5_P1a(CM5_P1a(CM_##f(,P##__VA_ARGS__)))
#define CM5__1a(P,f,...) CM5_P1b(CM5_P1b(CM_##f(,P##__VA_ARGS__)))
#define CM5__1b(P,f,...) CM5_P1c(CM5_P1c(CM_##f(,P##__VA_ARGS__)))
#define CM5__1c(P,f,...) CM5_P1d(CM5_P1d(CM_##f(,P##__VA_ARGS__)))
#define CM5__1d(P,f,...) CM5_P1e(CM5_P1e(CM_##f(,P##__VA_ARGS__)))
#define CM5__1e(P,f,...) CM5_P1f(CM5_P1f(CM_##f(,P##__VA_ARGS__)))
#define CM5__1f(P,f,...) CM_##f(,P##__VA_ARGS__)

#define CM5_P01(x) CM5__01 x
#define CM5_P02(x) CM5__02 x
#define CM5_P03(x) CM5__03 x
#define CM5_P04(x) CM5__04 x
#define CM5_P05(x) CM5__05 x
#define CM5_P06(x) CM5__06 x
#define CM5_P07(x) CM5__07 x
#define CM5_P08(x) CM5__08 x
#define CM5_P09(x) CM5__09 x
#define CM5_P0a(x) CM5__0a x
#define CM5_P0b(x) CM5__0b x
#define CM5_P0c(x) CM5__0c x
#define CM5_P0d(x) CM5__0d x
#define CM5_P0e(x) CM5__0e x
#define CM5_P0f(x) CM5__0f x
#define CM5_P10(x) CM5__10 x
#define CM5_P11(x) CM5__11 x
#define CM5_P12(x) CM5__12 x
#define CM5_P13(x) CM5__13 x
#define CM5_P14(x) CM5__14 x
#define CM5_P15(x) CM5__15 x
#define CM5_P16(x) CM5__16 x
#define CM5_P17(x) CM5__17 x
#define CM5_P18(x) CM5__18 x
#define CM5_P19(x) CM5__19 x
#define CM5_P1a(x) CM5__1a x
#define CM5_P1b(x) CM5__1b x
#define CM5_P1c(x) CM5__1c x
#define CM5_P1d(x) CM5__1d x
#define CM5_P1e(x) CM5__1e x
#define CM5_P1f(x) CM5__1f x

#define CM6__00(P,f,...) CM6_P01(CM6_P01(CM_##f(,P##__VA_ARGS__)))
#define CM6__01(P,f,...) CM6_P02(CM6_P02(CM_##f(,P##__VA_ARGS__)))
#define CM6__02(P,f,...) CM6_P03(CM6_P03(CM_##f(,P##__VA_ARGS__)))
#define CM6__03(P,f,...) CM6_P04(CM6_P04(CM_##f(,P##__VA_ARGS__)))
#define CM6__04(P,f,...) CM6_P05(CM6_P05(CM_##f(,P##__VA_ARGS__)))
#define CM6__05(P,f,...) CM6_P06(CM6_P06(CM_##f(,P##__VA_ARGS__)))
#define CM6__06(P,f,...) CM6_P07(CM6_P07(CM_##f(,P##__VA_ARGS__)))
#define CM6__07(P,f,...) CM6_P08(CM6_P08(CM_##f(,P##__VA_ARGS__)))
#define CM6__08(P,f,...) CM6_P09(CM6_P09(CM_##f(,P##__VA_ARGS__)))
#define CM6__09(P,f,...) CM6_P0a(CM6_P0a(CM_##f(,P##__VA_ARGS__)))
#define CM6__0a(P,f,...) CM6_P0b(CM6_P0b(CM_##f(,P##__VA_ARGS__)))
#define CM6__0b(P,f,...) CM6_P0c(CM6_P0c(CM_##f(,P##__VA_ARGS__)))
#define CM6__0c(P,f,...) CM6_P0d(CM6_P0d(CM_##f(,P##__VA_ARGS__)))
#define CM6__0d(P,f,...) CM6_P0e(CM6_P0e(CM_##f(,P##__VA_ARGS__)))
#define CM6__0e(P,f,...) CM6_P0f(CM6_P0f(CM_##f(,P##__VA_ARGS__)))
#define CM6__0f(P,f,...) CM6_P10(CM6_P10(CM_##f(,P##__VA_ARGS__)))
#define CM6__10(P,f,...) CM6_P11(CM6_P11(CM_##f(,P##__VA_ARGS__)))
#define CM6__11(P,f,...) CM6_P12(CM6_P12(CM_##f(,P##__VA_ARGS__)))
#define CM6__12(P,f,...) CM6_P13(CM6_P13(CM_##f(,P##__VA_ARGS__)))
#define CM6__13(P,f,...) CM6_P14(CM6_P14(CM_##f(,P##__VA_ARGS__)))
#define CM6__14(P,f,...) CM6_P15(CM6_P15(CM_##f(,P##__VA_ARGS__)))
#define CM6__15(P,f,...) CM6_P16(CM6_P16(CM_##f(,P##__VA_ARGS__)))
#define CM6__16(P,f,...) CM6_P17(CM6_P17(CM_##f(,P##__VA_ARGS__)))
#define CM6__17(P,f,...) CM6_P18(CM6_P18(CM_##f(,P##__VA_ARGS__)))
#define CM6__18(P,f,...) CM6_P19(CM6_P19(CM_##f(,P##__VA_ARGS__)))
#define CM6__19(P,f,...) CM6_P1a(CM6_P1a(CM_##f(,P##__VA_ARGS__)))
#define CM6__1a(P,f,...) CM6_P1b(CM6_P1b(CM_##f(,P##__VA_ARGS__)))
#define CM6__1b(P,f,...) CM6_P1c(CM6_P1c(CM_##f(,P##__VA_ARGS__)))
#define CM6__1c(P,f,...) CM6_P1d(CM6_P1d(CM_##f(,P##__VA_ARGS__)))
#define CM6__1d(P,f,...) CM6_P1e(CM6_P1e(CM_##f(,P##__VA_ARGS__)))
#define CM6__1e(P,f,...) CM6_P1f(CM6_P1f(CM_##f(,P##__VA_ARGS__)))
#define CM6__1f(P,f,...) CM_##f(,P##__VA_ARGS__)

#define CM6_P01(x) CM6__01 x
#define CM6_P02(x) CM6__02 x
#define CM6_P03(x) CM6__03 x
#define CM6_P04(x) CM6__04 x
#define CM6_P05(x) CM6__05 x
#define CM6_P06(x) CM6__06 x
#define CM6_P07(x) CM6__07 x
#define CM6_P08(x) CM6__08 x
#define CM6_P09(x) CM6__09 x
#define CM6_P0a(x) CM6__0a x
#define CM6_P0b(x) CM6__0b x
#define CM6_P0c(x) CM6__0c x
#define CM6_P0d(x) CM6__0d x
#define CM6_P0e(x) CM6__0e x
#define CM6_P0f(x) CM6__0f x
#define CM6_P10(x) CM6__10 x
#define CM6_P11(x) CM6__11 x
#define CM6_P12(x) CM6__12 x
#define CM6_P13(x) CM6__13 x
#define CM6_P14(x) CM6__14 x
#define CM6_P15(x) CM6__15 x
#define CM6_P16(x) CM6__16 x
#define CM6_P17(x) CM6__17 x
#define CM6_P18(x) CM6__18 x
#define CM6_P19(x) CM6__19 x
#define CM6_P1a(x) CM6__1a x
#define CM6_P1b(x) CM6__1b x
#define CM6_P1c(x) CM6__1c x
#define CM6_P1d(x) CM6__1d x
#define CM6_P1e(x) CM6__1e x
#define CM6_P1f(x) CM6__1f x

#define CM7__00(P,f,...) CM7_P01(CM7_P01(CM_##f(,P##__VA_ARGS__)))
#define CM7__01(P,f,...) CM7_P02(CM7_P02(CM_##f(,P##__VA_ARGS__)))
#define CM7__02(P,f,...) CM7_P03(CM7_P03(CM_##f(,P##__VA_ARGS__)))
#define CM7__03(P,f,...) CM7_P04(CM7_P04(CM_##f(,P##__VA_ARGS__)))
#define CM7__04(P,f,...) CM7_P05(CM7_P05(CM_##f(,P##__VA_ARGS__)))
#define CM7__05(P,f,...) CM7_P06(CM7_P06(CM_##f(,P##__VA_ARGS__)))
#define CM7__06(P,f,...) CM7_P07(CM7_P07(CM_##f(,P##__VA_ARGS__)))
#define CM7__07(P,f,...) CM7_P08(CM7_P08(CM_##f(,P##__VA_ARGS__)))
#define CM7__08(P,f,...) CM7_P09(CM7_P09(CM_##f(,P##__VA_ARGS__)))
#define CM7__09(P,f,...) CM7_P0a(CM7_P0a(CM_##f(,P##__VA_ARGS__)))
#define CM7__0a(P,f,...) CM7_P0b(CM7_P0b(CM_##f(,P##__VA_ARGS__)))
#define CM7__0b(P,f,...) CM7_P0c(CM7_P0c(CM_##f(,P##__VA_ARGS__)))
#define CM7__0c(P,f,...) CM7_P0d(CM7_P0d(CM_##f(,P##__VA_ARGS__)))
#define CM7__0d(P,f,...) CM7_P0e(CM7_P0e(CM_##f(,P##__VA_ARGS__)))
#define CM7__0e(P,f,...) CM7_P0f(CM7_P0f(CM_##f(,P##__VA_ARGS__)))
#define CM7__0f(P,f,...) CM7_P10(CM7_P10(CM_##f(,P##__VA_ARGS__)))
#define CM7__10(P,f,...) CM7_P11(CM7_P11(CM_##f(,P##__VA_ARGS__)))
#define CM7__11(P,f,...) CM7_P12(CM7_P12(CM_##f(,P##__VA_ARGS__)))
#define CM7__12(P,f,...) CM7_P13(CM7_P13(CM_##f(,P##__VA_ARGS__)))
#define CM7__13(P,f,...) CM7_P14(CM7_P14(CM_##f(,P##__VA_ARGS__)))
#define CM7__14(P,f,...) CM7_P15(CM7_P15(CM_##f(,P##__VA_ARGS__)))
#define CM7__15(P,f,...) CM7_P16(CM7_P16(CM_##f(,P##__VA_ARGS__)))
#define CM7__16(P,f,...) CM7_P17(CM7_P17(CM_##f(,P##__VA_ARGS__)))
#define CM7__17(P,f,...) CM7_P18(CM7_P18(CM_##f(,P##__VA_ARGS__)))
#define CM7__18(P,f,...) CM7_P19(CM7_P19(CM_##f(,P##__VA_ARGS__)))
#define CM7__19(P,f,...) CM7_P1a(CM7_P1a(CM_##f(,P##__VA_ARGS__)))
#define CM7__1a(P,f,...) CM7_P1b(CM7_P1b(CM_##f(,P##__VA_ARGS__)))
#define CM7__1b(P,f,...) CM7_P1c(CM7_P1c(CM_##f(,P##__VA_ARGS__)))
#define CM7__1c(P,f,...) CM7_P1d(CM7_P1d(CM_##f(,P##__VA_ARGS__)))
#define CM7__1d(P,f,...) CM7_P1e(CM7_P1e(CM_##f(,P##__VA_ARGS__)))
#define CM7__1e(P,f,...) CM7_P1f(CM7_P1f(CM_##f(,P##__VA_ARGS__)))
#define CM7__1f(P,f,...) CM_##f(,P##__VA_ARGS__)

#define CM7_P01(x) CM7__01 x
#define CM7_P02(x) CM7__02 x
#define CM7_P03(x) CM7__03 x
#define CM7_P04(x) CM7__04 x
#define CM7_P05(x) CM7__05 x
#define CM7_P06(x) CM7__06 x
#define CM7_P07(x) CM7__07 x
#define CM7_P08(x) CM7__08 x
#define CM7_P09(x) CM7__09 x
#define CM7_P0a(x) CM7__0a x
#define CM7_P0b(x) CM7__0b x
#define CM7_P0c(x) CM7__0c x
#define CM7_P0d(x) CM7__0d x
#define CM7_P0e(x) CM7__0e x
#define CM7_P0f(x) CM7__0f x
#define CM7_P10(x) CM7__10 x
#define CM7_P11(x) CM7__11 x
#define CM7_P12(x) CM7__12 x
#define CM7_P13(x) CM7__13 x
#define CM7_P14(x) CM7__14 x
#define CM7_P15(x) CM7__15 x
#define CM7_P16(x) CM7__16 x
#define CM7_P17(x) CM7__17 x
#define CM7_P18(x) CM7__18 x
#define CM7_P19(x) CM7__19 x
#define CM7_P1a(x) CM7__1a x
#define CM7_P1b(x) CM7__1b x
#define CM7_P1c(x) CM7__1c x
#define CM7_P1d(x) CM7__1d x
#define CM7_P1e(x) CM7__1e x
#define CM7_P1f(x) CM7__1f x

#define CM8__00(P,f,...) CM8_P01(CM8_P01(CM_##f(,P##__VA_ARGS__)))
#define CM8__01(P,f,...) CM8_P02(CM8_P02(CM_##f(,P##__VA_ARGS__)))
#define CM8__02(P,f,...) CM8_P03(CM8_P03(CM_##f(,P##__VA_ARGS__)))
#define CM8__03(P,f,...) CM8_P04(CM8_P04(CM_##f(,P##__VA_ARGS__)))
#define CM8__04(P,f,...) CM8_P05(CM8_P05(CM_##f(,P##__VA_ARGS__)))
#define CM8__05(P,f,...) CM8_P06(CM8_P06(CM_##f(,P##__VA_ARGS__)))
#define CM8__06(P,f,...) CM8_P07(CM8_P07(CM_##f(,P##__VA_ARGS__)))
#define CM8__07(P,f,...) CM8_P08(CM8_P08(CM_##f(,P##__VA_ARGS__)))
#define CM8__08(P,f,...) CM8_P09(CM8_P09(CM_##f(,P##__VA_ARGS__)))
#define CM8__09(P,f,...) CM8_P0a(CM8_P0a(CM_##f(,P##__VA_ARGS__)))
#define CM8__0a(P,f,...) CM8_P0b(CM8_P0b(CM_##f(,P##__VA_ARGS__)))
#define CM8__0b(P,f,...) CM8_P0c(CM8_P0c(CM_##f(,P##__VA_ARGS__)))
#define CM8__0c(P,f,...) CM8_P0d(CM8_P0d(CM_##f(,P##__VA_ARGS__)))
#define CM8__0d(P,f,...) CM8_P0e(CM8_P0e(CM_##f(,P##__VA_ARGS__)))
#define CM8__0e(P,f,...) CM8_P0f(CM8_P0f(CM_##f(,P##__VA_ARGS__)))
#define CM8__0f(P,f,...) CM8_P10(CM8_P10(CM_##f(,P##__VA_ARGS__)))
#define CM8__10(P,f,...) CM8_P11(CM8_P11(CM_##f(,P##__VA_ARGS__)))
#define CM8__11(P,f,...) CM8_P12(CM8_P12(CM_##f(,P##__VA_ARGS__)))
#define CM8__12(P,f,...) CM8_P13(CM8_P13(CM_##f(,P##__VA_ARGS__)))
#define CM8__13(P,f,...) CM8_P14(CM8_P14(CM_##f(,P##__VA_ARGS__)))
#define CM8__14(P,f,...) CM8_P15(CM8_P15(CM_##f(,P##__VA_ARGS__)))
#define CM8__15(P,f,...) CM8_P16(CM8_P16(CM_##f(,P##__VA_ARGS__)))
#define CM8__16(P,f,...) CM8_P17(CM8_P17(CM_##f(,P##__VA_ARGS__)))
#define CM8__17(P,f,...) CM8_P18(CM8_P18(CM_##f(,P##__VA_ARGS__)))
#define CM8__18(P,f,...) CM8_P19(CM8_P19(CM_##f(,P##__VA_ARGS__)))
#define CM8__19(P,f,...) CM8_P1a(CM8_P1a(CM_##f(,P##__VA_ARGS__)))
#define CM8__1a(P,f,...) CM8_P1b(CM8_P1b(CM_##f(,P##__VA_ARGS__)))
#define CM8__1b(P,f,...) CM8_P1c(CM8_P1c(CM_##f(,P##__VA_ARGS__)))
#define CM8__1c(P,f,...) CM8_P1d(CM8_P1d(CM_##f(,P##__VA_ARGS__)))
#define CM8__1d(P,f,...) CM8_P1e(CM8_P1e(CM_##f(,P##__VA_ARGS__)))
#define CM8__1e(P,f,...) CM8_P1f(CM8_P1f(CM_##f(,P##__VA_ARGS__)))
#define CM8__1f(P,f,...) CM_##f(,P##__VA_ARGS__)

#define CM8_P01(x) CM8__01 x
#define CM8_P02(x) CM8__02 x
#define CM8_P03(x) CM8__03 x
#define CM8_P04(x) CM8__04 x
#define CM8_P05(x) CM8__05 x
#define CM8_P06(x) CM8__06 x
#define CM8_P07(x) CM8__07 x
#define CM8_P08(x) CM8__08 x
#define CM8_P09(x) CM8__09 x
#define CM8_P0a(x) CM8__0a x
#define CM8_P0b(x) CM8__0b x
#define CM8_P0c(x) CM8__0c x
#define CM8_P0d(x) CM8__0d x
#define CM8_P0e(x) CM8__0e x
#define CM8_P0f(x) CM8__0f x
#define CM8_P10(x) CM8__10 x
#define CM8_P11(x) CM8__11 x
#define CM8_P12(x) CM8__12 x
#define CM8_P13(x) CM8__13 x
#define CM8_P14(x) CM8__14 x
#define CM8_P15(x) CM8__15 x
#define CM8_P16(x) CM8__16 x
#define CM8_P17(x) CM8__17 x
#define CM8_P18(x) CM8__18 x
#define CM8_P19(x) CM8__19 x
#define CM8_P1a(x) CM8__1a x
#define CM8_P1b(x) CM8__1b x
#define CM8_P1c(x) CM8__1c x
#define CM8_P1d(x) CM8__1d x
#define CM8_P1e(x) CM8__1e x
#define CM8_P1f(x) CM8__1f x

#define CM9__00(P,f,...) CM9_P01(CM9_P01(CM_##f(,P##__VA_ARGS__)))
#define CM9__01(P,f,...) CM9_P02(CM9_P02(CM_##f(,P##__VA_ARGS__)))
#define CM9__02(P,f,...) CM9_P03(CM9_P03(CM_##f(,P##__VA_ARGS__)))
#define CM9__03(P,f,...) CM9_P04(CM9_P04(CM_##f(,P##__VA_ARGS__)))
#define CM9__04(P,f,...) CM9_P05(CM9_P05(CM_##f(,P##__VA_ARGS__)))
#define CM9__05(P,f,...) CM9_P06(CM9_P06(CM_##f(,P##__VA_ARGS__)))
#define CM9__06(P,f,...) CM9_P07(CM9_P07(CM_##f(,P##__VA_ARGS__)))
#define CM9__07(P,f,...) CM9_P08(CM9_P08(CM_##f(,P##__VA_ARGS__)))
#define CM9__08(P,f,...) CM9_P09(CM9_P09(CM_##f(,P##__VA_ARGS__)))
#define CM9__09(P,f,...) CM9_P0a(CM9_P0a(CM_##f(,P##__VA_ARGS__)))
#define CM9__0a(P,f,...) CM9_P0b(CM9_P0b(CM_##f(,P##__VA_ARGS__)))
#define CM9__0b(P,f,...) CM9_P0c(CM9_P0c(CM_##f(,P##__VA_ARGS__)))
#define CM9__0c(P,f,...) CM9_P0d(CM9_P0d(CM_##f(,P##__VA_ARGS__)))
#define CM9__0d(P,f,...) CM9_P0e(CM9_P0e(CM_##f(,P##__VA_ARGS__)))
#define CM9__0e(P,f,...) CM9_P0f(CM9_P0f(CM_##f(,P##__VA_ARGS__)))
#define CM9__0f(P,f,...) CM9_P10(CM9_P10(CM_##f(,P##__VA_ARGS__)))
#define CM9__10(P,f,...) CM9_P11(CM9_P11(CM_##f(,P##__VA_ARGS__)))
#define CM9__11(P,f,...) CM9_P12(CM9_P12(CM_##f(,P##__VA_ARGS__)))
#define CM9__12(P,f,...) CM9_P13(CM9_P13(CM_##f(,P##__VA_ARGS__)))
#define CM9__13(P,f,...) CM9_P14(CM9_P14(CM_##f(,P##__VA_ARGS__)))
#define CM9__14(P,f,...) CM9_P15(CM9_P15(CM_##f(,P##__VA_ARGS__)))
#define CM9__15(P,f,...) CM9_P16(CM9_P16(CM_##f(,P##__VA_ARGS__)))
#define CM9__16(P,f,...) CM9_P17(CM9_P17(CM_##f(,P##__VA_ARGS__)))
#define CM9__17(P,f,...) CM9_P18(CM9_P18(CM_##f(,P##__VA_ARGS__)))
#define CM9__18(P,f,...) CM9_P19(CM9_P19(CM_##f(,P##__VA_ARGS__)))
#define CM9__19(P,f,...) CM9_P1a(CM9_P1a(CM_##f(,P##__VA_ARGS__)))
#define CM9__1a(P,f,...) CM9_P1b(CM9_P1b(CM_##f(,P##__VA_ARGS__)))
#define CM9__1b(P,f,...) CM9_P1c(CM9_P1c(CM_##f(,P##__VA_ARGS__)))
#define CM9__1c(P,f,...) CM9_P1d(CM9_P1d(CM_##f(,P##__VA_ARGS__)))
#define CM9__1d(P,f,...) CM9_P1e(CM9_P1e(CM_##f(,P##__VA_ARGS__)))
#define CM9__1e(P,f,...) CM9_P1f(CM9_P1f(CM_##f(,P##__VA_ARGS__)))
#define CM9__1f(P,f,...) CM_##f(,P##__VA_ARGS__)

#define CM9_P01(x) CM9__01 x
#define CM9_P02(x) CM9__02 x
#define CM9_P03(x) CM9__03 x
#define CM9_P04(x) CM9__04 x
#define CM9_P05(x) CM9__05 x
#define CM9_P06(x) CM9__06 x
#define CM9_P07(x) CM9__07 x
#define CM9_P08(x) CM9__08 x
#define CM9_P09(x) CM9__09 x
#define CM9_P0a(x) CM9__0a x
#define CM9_P0b(x) CM9__0b x
#define CM9_P0c(x) CM9__0c x
#define CM9_P0d(x) CM9__0d x
#define CM9_P0e(x) CM9__0e x
#define CM9_P0f(x) CM9__0f x
#define CM9_P10(x) CM9__10 x
#define CM9_P11(x) CM9__11 x
#define CM9_P12(x) CM9__12 x
#define CM9_P13(x) CM9__13 x
#define CM9_P14(x) CM9__14 x
#define CM9_P15(x) CM9__15 x
#define CM9_P16(x) CM9__16 x
#define CM9_P17(x) CM9__17 x
#define CM9_P18(x) CM9__18 x
#define CM9_P19(x) CM9__19 x
#define CM9_P1a(x) CM9__1a x
#define CM9_P1b(x) CM9__1b x
#define CM9_P1c(x) CM9__1c x
#define CM9_P1d(x) CM9__1d x
#define CM9_P1e(x) CM9__1e x
#define CM9_P1f(x) CM9__1f x

#define CMa__00(P,f,...) CMa_P01(CMa_P01(CM_##f(,P##__VA_ARGS__)))
#define CMa__01(P,f,...) CMa_P02(CMa_P02(CM_##f(,P##__VA_ARGS__)))
#define CMa__02(P,f,...) CMa_P03(CMa_P03(CM_##f(,P##__VA_ARGS__)))
#define CMa__03(P,f,...) CMa_P04(CMa_P04(CM_##f(,P##__VA_ARGS__)))
#define CMa__04(P,f,...) CMa_P05(CMa_P05(CM_##f(,P##__VA_ARGS__)))
#define CMa__05(P,f,...) CMa_P06(CMa_P06(CM_##f(,P##__VA_ARGS__)))
#define CMa__06(P,f,...) CMa_P07(CMa_P07(CM_##f(,P##__VA_ARGS__)))
#define CMa__07(P,f,...) CMa_P08(CMa_P08(CM_##f(,P##__VA_ARGS__)))
#define CMa__08(P,f,...) CMa_P09(CMa_P09(CM_##f(,P##__VA_ARGS__)))
#define CMa__09(P,f,...) CMa_P0a(CMa_P0a(CM_##f(,P##__VA_ARGS__)))
#define CMa__0a(P,f,...) CMa_P0b(CMa_P0b(CM_##f(,P##__VA_ARGS__)))
#define CMa__0b(P,f,...) CMa_P0c(CMa_P0c(CM_##f(,P##__VA_ARGS__)))
#define CMa__0c(P,f,...) CMa_P0d(CMa_P0d(CM_##f(,P##__VA_ARGS__)))
#define CMa__0d(P,f,...) CMa_P0e(CMa_P0e(CM_##f(,P##__VA_ARGS__)))
#define CMa__0e(P,f,...) CMa_P0f(CMa_P0f(CM_##f(,P##__VA_ARGS__)))
#define CMa__0f(P,f,...) CMa_P10(CMa_P10(CM_##f(,P##__VA_ARGS__)))
#define CMa__10(P,f,...) CMa_P11(CMa_P11(CM_##f(,P##__VA_ARGS__)))
#define CMa__11(P,f,...) CMa_P12(CMa_P12(CM_##f(,P##__VA_ARGS__)))
#define CMa__12(P,f,...) CMa_P13(CMa_P13(CM_##f(,P##__VA_ARGS__)))
#define CMa__13(P,f,...) CMa_P14(CMa_P14(CM_##f(,P##__VA_ARGS__)))
#define CMa__14(P,f,...) CMa_P15(CMa_P15(CM_##f(,P##__VA_ARGS__)))
#define CMa__15(P,f,...) CMa_P16(CMa_P16(CM_##f(,P##__VA_ARGS__)))
#define CMa__16(P,f,...) CMa_P17(CMa_P17(CM_##f(,P##__VA_ARGS__)))
#define CMa__17(P,f,...) CMa_P18(CMa_P18(CM_##f(,P##__VA_ARGS__)))
#define CMa__18(P,f,...) CMa_P19(CMa_P19(CM_##f(,P##__VA_ARGS__)))
#define CMa__19(P,f,...) CMa_P1a(CMa_P1a(CM_##f(,P##__VA_ARGS__)))
#define CMa__1a(P,f,...) CMa_P1b(CMa_P1b(CM_##f(,P##__VA_ARGS__)))
#define CMa__1b(P,f,...) CMa_P1c(CMa_P1c(CM_##f(,P##__VA_ARGS__)))
#define CMa__1c(P,f,...) CMa_P1d(CMa_P1d(CM_##f(,P##__VA_ARGS__)))
#define CMa__1d(P,f,...) CMa_P1e(CMa_P1e(CM_##f(,P##__VA_ARGS__)))
#define CMa__1e(P,f,...) CMa_P1f(CMa_P1f(CM_##f(,P##__VA_ARGS__)))
#define CMa__1f(P,f,...) CM_##f(,P##__VA_ARGS__)

#define CMa_P01(x) CMa__01 x
#define CMa_P02(x) CMa__02 x
#define CMa_P03(x) CMa__03 x
#define CMa_P04(x) CMa__04 x
#define CMa_P05(x) CMa__05 x
#define CMa_P06(x) CMa__06 x
#define CMa_P07(x) CMa__07 x
#define CMa_P08(x) CMa__08 x
#define CMa_P09(x) CMa__09 x
#define CMa_P0a(x) CMa__0a x
#define CMa_P0b(x) CMa__0b x
#define CMa_P0c(x) CMa__0c x
#define CMa_P0d(x) CMa__0d x
#define CMa_P0e(x) CMa__0e x
#define CMa_P0f(x) CMa__0f x
#define CMa_P10(x) CMa__10 x
#define CMa_P11(x) CMa__11 x
#define CMa_P12(x) CMa__12 x
#define CMa_P13(x) CMa__13 x
#define CMa_P14(x) CMa__14 x
#define CMa_P15(x) CMa__15 x
#define CMa_P16(x) CMa__16 x
#define CMa_P17(x) CMa__17 x
#define CMa_P18(x) CMa__18 x
#define CMa_P19(x) CMa__19 x
#define CMa_P1a(x) CMa__1a x
#define CMa_P1b(x) CMa__1b x
#define CMa_P1c(x) CMa__1c x
#define CMa_P1d(x) CMa__1d x
#define CMa_P1e(x) CMa__1e x
#define CMa_P1f(x) CMa__1f x

#define CMb__00(P,f,...) CMb_P01(CMb_P01(CM_##f(,P##__VA_ARGS__)))
#define CMb__01(P,f,...) CMb_P02(CMb_P02(CM_##f(,P##__VA_ARGS__)))
#define CMb__02(P,f,...) CMb_P03(CMb_P03(CM_##f(,P##__VA_ARGS__)))
#define CMb__03(P,f,...) CMb_P04(CMb_P04(CM_##f(,P##__VA_ARGS__)))
#define CMb__04(P,f,...) CMb_P05(CMb_P05(CM_##f(,P##__VA_ARGS__)))
#define CMb__05(P,f,...) CMb_P06(CMb_P06(CM_##f(,P##__VA_ARGS__)))
#define CMb__06(P,f,...) CMb_P07(CMb_P07(CM_##f(,P##__VA_ARGS__)))
#define CMb__07(P,f,...) CMb_P08(CMb_P08(CM_##f(,P##__VA_ARGS__)))
#define CMb__08(P,f,...) CMb_P09(CMb_P09(CM_##f(,P##__VA_ARGS__)))
#define CMb__09(P,f,...) CMb_P0a(CMb_P0a(CM_##f(,P##__VA_ARGS__)))
#define CMb__0a(P,f,...) CMb_P0b(CMb_P0b(CM_##f(,P##__VA_ARGS__)))
#define CMb__0b(P,f,...) CMb_P0c(CMb_P0c(CM_##f(,P##__VA_ARGS__)))
#define CMb__0c(P,f,...) CMb_P0d(CMb_P0d(CM_##f(,P##__VA_ARGS__)))
#define CMb__0d(P,f,...) CMb_P0e(CMb_P0e(CM_##f(,P##__VA_ARGS__)))
#define CMb__0e(P,f,...) CMb_P0f(CMb_P0f(CM_##f(,P##__VA_ARGS__)))
#define CMb__0f(P,f,...) CMb_P10(CMb_P10(CM_##f(,P##__VA_ARGS__)))
#define CMb__10(P,f,...) CMb_P11(CMb_P11(CM_##f(,P##__VA_ARGS__)))
#define CMb__11(P,f,...) CMb_P12(CMb_P12(CM_##f(,P##__VA_ARGS__)))
#define CMb__12(P,f,...) CMb_P13(CMb_P13(CM_##f(,P##__VA_ARGS__)))
#define CMb__13(P,f,...) CMb_P14(CMb_P14(CM_##f(,P##__VA_ARGS__)))
#define CMb__14(P,f,...) CMb_P15(CMb_P15(CM_##f(,P##__VA_ARGS__)))
#define CMb__15(P,f,...) CMb_P16(CMb_P16(CM_##f(,P##__VA_ARGS__)))
#define CMb__16(P,f,...) CMb_P17(CMb_P17(CM_##f(,P##__VA_ARGS__)))
#define CMb__17(P,f,...) CMb_P18(CMb_P18(CM_##f(,P##__VA_ARGS__)))
#define CMb__18(P,f,...) CMb_P19(CMb_P19(CM_##f(,P##__VA_ARGS__)))
#define CMb__19(P,f,...) CMb_P1a(CMb_P1a(CM_##f(,P##__VA_ARGS__)))
#define CMb__1a(P,f,...) CMb_P1b(CMb_P1b(CM_##f(,P##__VA_ARGS__)))
#define CMb__1b(P,f,...) CMb_P1c(CMb_P1c(CM_##f(,P##__VA_ARGS__)))
#define CMb__1c(P,f,...) CMb_P1d(CMb_P1d(CM_##f(,P##__VA_ARGS__)))
#define CMb__1d(P,f,...) CMb_P1e(CMb_P1e(CM_##f(,P##__VA_ARGS__)))
#define CMb__1e(P,f,...) CMb_P1f(CMb_P1f(CM_##f(,P##__VA_ARGS__)))
#define CMb__1f(P,f,...) CM_##f(,P##__VA_ARGS__)

#define CMb_P01(x) CMb__01 x
#define CMb_P02(x) CMb__02 x
#define CMb_P03(x) CMb__03 x
#define CMb_P04(x) CMb__04 x
#define CMb_P05(x) CMb__05 x
#define CMb_P06(x) CMb__06 x
#define CMb_P07(x) CMb__07 x
#define CMb_P08(x) CMb__08 x
#define CMb_P09(x) CMb__09 x
#define CMb_P0a(x) CMb__0a x
#define CMb_P0b(x) CMb__0b x
#define CMb_P0c(x) CMb__0c x
#define CMb_P0d(x) CMb__0d x
#define CMb_P0e(x) CMb__0e x
#define CMb_P0f(x) CMb__0f x
#define CMb_P10(x) CMb__10 x
#define CMb_P11(x) CMb__11 x
#define CMb_P12(x) CMb__12 x
#define CMb_P13(x) CMb__13 x
#define CMb_P14(x) CMb__14 x
#define CMb_P15(x) CMb__15 x
#define CMb_P16(x) CMb__16 x
#define CMb_P17(x) CMb__17 x
#define CMb_P18(x) CMb__18 x
#define CMb_P19(x) CMb__19 x
#define CMb_P1a(x) CMb__1a x
#define CMb_P1b(x) CMb__1b x
#define CMb_P1c(x) CMb__1c x
#define CMb_P1d(x) CMb__1d x
#define CMb_P1e(x) CMb__1e x
#define CMb_P1f(x) CMb__1f x

#define CMc__00(P,f,...) CMc_P01(CMc_P01(CM_##f(,P##__VA_ARGS__)))
#define CMc__01(P,f,...) CMc_P02(CMc_P02(CM_##f(,P##__VA_ARGS__)))
#define CMc__02(P,f,...) CMc_P03(CMc_P03(CM_##f(,P##__VA_ARGS__)))
#define CMc__03(P,f,...) CMc_P04(CMc_P04(CM_##f(,P##__VA_ARGS__)))
#define CMc__04(P,f,...) CMc_P05(CMc_P05(CM_##f(,P##__VA_ARGS__)))
#define CMc__05(P,f,...) CMc_P06(CMc_P06(CM_##f(,P##__VA_ARGS__)))
#define CMc__06(P,f,...) CMc_P07(CMc_P07(CM_##f(,P##__VA_ARGS__)))
#define CMc__07(P,f,...) CMc_P08(CMc_P08(CM_##f(,P##__VA_ARGS__)))
#define CMc__08(P,f,...) CMc_P09(CMc_P09(CM_##f(,P##__VA_ARGS__)))
#define CMc__09(P,f,...) CMc_P0a(CMc_P0a(CM_##f(,P##__VA_ARGS__)))
#define CMc__0a(P,f,...) CMc_P0b(CMc_P0b(CM_##f(,P##__VA_ARGS__)))
#define CMc__0b(P,f,...) CMc_P0c(CMc_P0c(CM_##f(,P##__VA_ARGS__)))
#define CMc__0c(P,f,...) CMc_P0d(CMc_P0d(CM_##f(,P##__VA_ARGS__)))
#define CMc__0d(P,f,...) CMc_P0e(CMc_P0e(CM_##f(,P##__VA_ARGS__)))
#define CMc__0e(P,f,...) CMc_P0f(CMc_P0f(CM_##f(,P##__VA_ARGS__)))
#define CMc__0f(P,f,...) CMc_P10(CMc_P10(CM_##f(,P##__VA_ARGS__)))
#define CMc__10(P,f,...) CMc_P11(CMc_P11(CM_##f(,P##__VA_ARGS__)))
#define CMc__11(P,f,...) CMc_P12(CMc_P12(CM_##f(,P##__VA_ARGS__)))
#define CMc__12(P,f,...) CMc_P13(CMc_P13(CM_##f(,P##__VA_ARGS__)))
#define CMc__13(P,f,...) CMc_P14(CMc_P14(CM_##f(,P##__VA_ARGS__)))
#define CMc__14(P,f,...) CMc_P15(CMc_P15(CM_##f(,P##__VA_ARGS__)))
#define CMc__15(P,f,...) CMc_P16(CMc_P16(CM_##f(,P##__VA_ARGS__)))
#define CMc__16(P,f,...) CMc_P17(CMc_P17(CM_##f(,P##__VA_ARGS__)))
#define CMc__17(P,f,...) CMc_P18(CMc_P18(CM_##f(,P##__VA_ARGS__)))
#define CMc__18(P,f,...) CMc_P19(CMc_P19(CM_##f(,P##__VA_ARGS__)))
#define CMc__19(P,f,...) CMc_P1a(CMc_P1a(CM_##f(,P##__VA_ARGS__)))
#define CMc__1a(P,f,...) CMc_P1b(CMc_P1b(CM_##f(,P##__VA_ARGS__)))
#define CMc__1b(P,f,...) CMc_P1c(CMc_P1c(CM_##f(,P##__VA_ARGS__)))
#define CMc__1c(P,f,...) CMc_P1d(CMc_P1d(CM_##f(,P##__VA_ARGS__)))
#define CMc__1d(P,f,...) CMc_P1e(CMc_P1e(CM_##f(,P##__VA_ARGS__)))
#define CMc__1e(P,f,...) CMc_P1f(CMc_P1f(CM_##f(,P##__VA_ARGS__)))
#define CMc__1f(P,f,...) CM_##f(,P##__VA_ARGS__)

#define CMc_P01(x) CMc__01 x
#define CMc_P02(x) CMc__02 x
#define CMc_P03(x) CMc__03 x
#define CMc_P04(x) CMc__04 x
#define CMc_P05(x) CMc__05 x
#define CMc_P06(x) CMc__06 x
#define CMc_P07(x) CMc__07 x
#define CMc_P08(x) CMc__08 x
#define CMc_P09(x) CMc__09 x
#define CMc_P0a(x) CMc__0a x
#define CMc_P0b(x) CMc__0b x
#define CMc_P0c(x) CMc__0c x
#define CMc_P0d(x) CMc__0d x
#define CMc_P0e(x) CMc__0e x
#define CMc_P0f(x) CMc__0f x
#define CMc_P10(x) CMc__10 x
#define CMc_P11(x) CMc__11 x
#define CMc_P12(x) CMc__12 x
#define CMc_P13(x) CMc__13 x
#define CMc_P14(x) CMc__14 x
#define CMc_P15(x) CMc__15 x
#define CMc_P16(x) CMc__16 x
#define CMc_P17(x) CMc__17 x
#define CMc_P18(x) CMc__18 x
#define CMc_P19(x) CMc__19 x
#define CMc_P1a(x) CMc__1a x
#define CMc_P1b(x) CMc__1b x
#define CMc_P1c(x) CMc__1c x
#define CMc_P1d(x) CMc__1d x
#define CMc_P1e(x) CMc__1e x
#define CMc_P1f(x) CMc__1f x

#define CMd__00(P,f,...) CMd_P01(CMd_P01(CM_##f(,P##__VA_ARGS__)))
#define CMd__01(P,f,...) CMd_P02(CMd_P02(CM_##f(,P##__VA_ARGS__)))
#define CMd__02(P,f,...) CMd_P03(CMd_P03(CM_##f(,P##__VA_ARGS__)))
#define CMd__03(P,f,...) CMd_P04(CMd_P04(CM_##f(,P##__VA_ARGS__)))
#define CMd__04(P,f,...) CMd_P05(CMd_P05(CM_##f(,P##__VA_ARGS__)))
#define CMd__05(P,f,...) CMd_P06(CMd_P06(CM_##f(,P##__VA_ARGS__)))
#define CMd__06(P,f,...) CMd_P07(CMd_P07(CM_##f(,P##__VA_ARGS__)))
#define CMd__07(P,f,...) CMd_P08(CMd_P08(CM_##f(,P##__VA_ARGS__)))
#define CMd__08(P,f,...) CMd_P09(CMd_P09(CM_##f(,P##__VA_ARGS__)))
#define CMd__09(P,f,...) CMd_P0a(CMd_P0a(CM_##f(,P##__VA_ARGS__)))
#define CMd__0a(P,f,...) CMd_P0b(CMd_P0b(CM_##f(,P##__VA_ARGS__)))
#define CMd__0b(P,f,...) CMd_P0c(CMd_P0c(CM_##f(,P##__VA_ARGS__)))
#define CMd__0c(P,f,...) CMd_P0d(CMd_P0d(CM_##f(,P##__VA_ARGS__)))
#define CMd__0d(P,f,...) CMd_P0e(CMd_P0e(CM_##f(,P##__VA_ARGS__)))
#define CMd__0e(P,f,...) CMd_P0f(CMd_P0f(CM_##f(,P##__VA_ARGS__)))
#define CMd__0f(P,f,...) CMd_P10(CMd_P10(CM_##f(,P##__VA_ARGS__)))
#define CMd__10(P,f,...) CMd_P11(CMd_P11(CM_##f(,P##__VA_ARGS__)))
#define CMd__11(P,f,...) CMd_P12(CMd_P12(CM_##f(,P##__VA_ARGS__)))
#define CMd__12(P,f,...) CMd_P13(CMd_P13(CM_##f(,P##__VA_ARGS__)))
#define CMd__13(P,f,...) CMd_P14(CMd_P14(CM_##f(,P##__VA_ARGS__)))
#define CMd__14(P,f,...) CMd_P15(CMd_P15(CM_##f(,P##__VA_ARGS__)))
#define CMd__15(P,f,...) CMd_P16(CMd_P16(CM_##f(,P##__VA_ARGS__)))
#define CMd__16(P,f,...) CMd_P17(CMd_P17(CM_##f(,P##__VA_ARGS__)))
#define CMd__17(P,f,...) CMd_P18(CMd_P18(CM_##f(,P##__VA_ARGS__)))
#define CMd__18(P,f,...) CMd_P19(CMd_P19(CM_##f(,P##__VA_ARGS__)))
#define CMd__19(P,f,...) CMd_P1a(CMd_P1a(CM_##f(,P##__VA_ARGS__)))
#define CMd__1a(P,f,...) CMd_P1b(CMd_P1b(CM_##f(,P##__VA_ARGS__)))
#define CMd__1b(P,f,...) CMd_P1c(CMd_P1c(CM_##f(,P##__VA_ARGS__)))
#define CMd__1c(P,f,...) CMd_P1d(CMd_P1d(CM_##f(,P##__VA_ARGS__)))
#define CMd__1d(P,f,...) CMd_P1e(CMd_P1e(CM_##f(,P##__VA_ARGS__)))
#define CMd__1e(P,f,...) CMd_P1f(CMd_P1f(CM_##f(,P##__VA_ARGS__)))
#define CMd__1f(P,f,...) CM_##f(,P##__VA_ARGS__)

#define CMd_P01(x) CMd__01 x
#define CMd_P02(x) CMd__02 x
#define CMd_P03(x) CMd__03 x
#define CMd_P04(x) CMd__04 x
#define CMd_P05(x) CMd__05 x
#define CMd_P06(x) CMd__06 x
#define CMd_P07(x) CMd__07 x
#define CMd_P08(x) CMd__08 x
#define CMd_P09(x) CMd__09 x
#define CMd_P0a(x) CMd__0a x
#define CMd_P0b(x) CMd__0b x
#define CMd_P0c(x) CMd__0c x
#define CMd_P0d(x) CMd__0d x
#define CMd_P0e(x) CMd__0e x
#define CMd_P0f(x) CMd__0f x
#define CMd_P10(x) CMd__10 x
#define CMd_P11(x) CMd__11 x
#define CMd_P12(x) CMd__12 x
#define CMd_P13(x) CMd__13 x
#define CMd_P14(x) CMd__14 x
#define CMd_P15(x) CMd__15 x
#define CMd_P16(x) CMd__16 x
#define CMd_P17(x) CMd__17 x
#define CMd_P18(x) CMd__18 x
#define CMd_P19(x) CMd__19 x
#define CMd_P1a(x) CMd__1a x
#define CMd_P1b(x) CMd__1b x
#define CMd_P1c(x) CMd__1c x
#define CMd_P1d(x) CMd__1d x
#define CMd_P1e(x) CMd__1e x
#define CMd_P1f(x) CMd__1f x

#define CMe__00(P,f,...) CMe_P01(CMe_P01(CM_##f(,P##__VA_ARGS__)))
#define CMe__01(P,f,...) CMe_P02(CMe_P02(CM_##f(,P##__VA_ARGS__)))
#define CMe__02(P,f,...) CMe_P03(CMe_P03(CM_##f(,P##__VA_ARGS__)))
#define CMe__03(P,f,...) CMe_P04(CMe_P04(CM_##f(,P##__VA_ARGS__)))
#define CMe__04(P,f,...) CMe_P05(CMe_P05(CM_##f(,P##__VA_ARGS__)))
#define CMe__05(P,f,...) CMe_P06(CMe_P06(CM_##f(,P##__VA_ARGS__)))
#define CMe__06(P,f,...) CMe_P07(CMe_P07(CM_##f(,P##__VA_ARGS__)))
#define CMe__07(P,f,...) CMe_P08(CMe_P08(CM_##f(,P##__VA_ARGS__)))
#define CMe__08(P,f,...) CMe_P09(CMe_P09(CM_##f(,P##__VA_ARGS__)))
#define CMe__09(P,f,...) CMe_P0a(CMe_P0a(CM_##f(,P##__VA_ARGS__)))
#define CMe__0a(P,f,...) CMe_P0b(CMe_P0b(CM_##f(,P##__VA_ARGS__)))
#define CMe__0b(P,f,...) CMe_P0c(CMe_P0c(CM_##f(,P##__VA_ARGS__)))
#define CMe__0c(P,f,...) CMe_P0d(CMe_P0d(CM_##f(,P##__VA_ARGS__)))
#define CMe__0d(P,f,...) CMe_P0e(CMe_P0e(CM_##f(,P##__VA_ARGS__)))
#define CMe__0e(P,f,...) CMe_P0f(CMe_P0f(CM_##f(,P##__VA_ARGS__)))
#define CMe__0f(P,f,...) CMe_P10(CMe_P10(CM_##f(,P##__VA_ARGS__)))
#define CMe__10(P,f,...) CMe_P11(CMe_P11(CM_##f(,P##__VA_ARGS__)))
#define CMe__11(P,f,...) CMe_P12(CMe_P12(CM_##f(,P##__VA_ARGS__)))
#define CMe__12(P,f,...) CMe_P13(CMe_P13(CM_##f(,P##__VA_ARGS__)))
#define CMe__13(P,f,...) CMe_P14(CMe_P14(CM_##f(,P##__VA_ARGS__)))
#define CMe__14(P,f,...) CMe_P15(CMe_P15(CM_##f(,P##__VA_ARGS__)))
#define CMe__15(P,f,...) CMe_P16(CMe_P16(CM_##f(,P##__VA_ARGS__)))
#define CMe__16(P,f,...) CMe_P17(CMe_P17(CM_##f(,P##__VA_ARGS__)))
#define CMe__17(P,f,...) CMe_P18(CMe_P18(CM_##f(,P##__VA_ARGS__)))
#define CMe__18(P,f,...) CMe_P19(CMe_P19(CM_##f(,P##__VA_ARGS__)))
#define CMe__19(P,f,...) CMe_P1a(CMe_P1a(CM_##f(,P##__VA_ARGS__)))
#define CMe__1a(P,f,...) CMe_P1b(CMe_P1b(CM_##f(,P##__VA_ARGS__)))
#define CMe__1b(P,f,...) CMe_P1c(CMe_P1c(CM_##f(,P##__VA_ARGS__)))
#define CMe__1c(P,f,...) CMe_P1d(CMe_P1d(CM_##f(,P##__VA_ARGS__)))
#define CMe__1d(P,f,...) CMe_P1e(CMe_P1e(CM_##f(,P##__VA_ARGS__)))
#define CMe__1e(P,f,...) CMe_P1f(CMe_P1f(CM_##f(,P##__VA_ARGS__)))
#define CMe__1f(P,f,...) CM_##f(,P##__VA_ARGS__)

#define CMe_P01(x) CMe__01 x
#define CMe_P02(x) CMe__02 x
#define CMe_P03(x) CMe__03 x
#define CMe_P04(x) CMe__04 x
#define CMe_P05(x) CMe__05 x
#define CMe_P06(x) CMe__06 x
#define CMe_P07(x) CMe__07 x
#define CMe_P08(x) CMe__08 x
#define CMe_P09(x) CMe__09 x
#define CMe_P0a(x) CMe__0a x
#define CMe_P0b(x) CMe__0b x
#define CMe_P0c(x) CMe__0c x
#define CMe_P0d(x) CMe__0d x
#define CMe_P0e(x) CMe__0e x
#define CMe_P0f(x) CMe__0f x
#define CMe_P10(x) CMe__10 x
#define CMe_P11(x) CMe__11 x
#define CMe_P12(x) CMe__12 x
#define CMe_P13(x) CMe__13 x
#define CMe_P14(x) CMe__14 x
#define CMe_P15(x) CMe__15 x
#define CMe_P16(x) CMe__16 x
#define CMe_P17(x) CMe__17 x
#define CMe_P18(x) CMe__18 x
#define CMe_P19(x) CMe__19 x
#define CMe_P1a(x) CMe__1a x
#define CMe_P1b(x) CMe__1b x
#define CMe_P1c(x) CMe__1c x
#define CMe_P1d(x) CMe__1d x
#define CMe_P1e(x) CMe__1e x
#define CMe_P1f(x) CMe__1f x

#define CMf__00(P,f,...) CMf_P01(CMf_P01(CM_##f(,P##__VA_ARGS__)))
#define CMf__01(P,f,...) CMf_P02(CMf_P02(CM_##f(,P##__VA_ARGS__)))
#define CMf__02(P,f,...) CMf_P03(CMf_P03(CM_##f(,P##__VA_ARGS__)))
#define CMf__03(P,f,...) CMf_P04(CMf_P04(CM_##f(,P##__VA_ARGS__)))
#define CMf__04(P,f,...) CMf_P05(CMf_P05(CM_##f(,P##__VA_ARGS__)))
#define CMf__05(P,f,...) CMf_P06(CMf_P06(CM_##f(,P##__VA_ARGS__)))
#define CMf__06(P,f,...) CMf_P07(CMf_P07(CM_##f(,P##__VA_ARGS__)))
#define CMf__07(P,f,...) CMf_P08(CMf_P08(CM_##f(,P##__VA_ARGS__)))
#define CMf__08(P,f,...) CMf_P09(CMf_P09(CM_##f(,P##__VA_ARGS__)))
#define CMf__09(P,f,...) CMf_P0a(CMf_P0a(CM_##f(,P##__VA_ARGS__)))
#define CMf__0a(P,f,...) CMf_P0b(CMf_P0b(CM_##f(,P##__VA_ARGS__)))
#define CMf__0b(P,f,...) CMf_P0c(CMf_P0c(CM_##f(,P##__VA_ARGS__)))
#define CMf__0c(P,f,...) CMf_P0d(CMf_P0d(CM_##f(,P##__VA_ARGS__)))
#define CMf__0d(P,f,...) CMf_P0e(CMf_P0e(CM_##f(,P##__VA_ARGS__)))
#define CMf__0e(P,f,...) CMf_P0f(CMf_P0f(CM_##f(,P##__VA_ARGS__)))
#define CMf__0f(P,f,...) CMf_P10(CMf_P10(CM_##f(,P##__VA_ARGS__)))
#define CMf__10(P,f,...) CMf_P11(CMf_P11(CM_##f(,P##__VA_ARGS__)))
#define CMf__11(P,f,...) CMf_P12(CMf_P12(CM_##f(,P##__VA_ARGS__)))
#define CMf__12(P,f,...) CMf_P13(CMf_P13(CM_##f(,P##__VA_ARGS__)))
#define CMf__13(P,f,...) CMf_P14(CMf_P14(CM_##f(,P##__VA_ARGS__)))
#define CMf__14(P,f,...) CMf_P15(CMf_P15(CM_##f(,P##__VA_ARGS__)))
#define CMf__15(P,f,...) CMf_P16(CMf_P16(CM_##f(,P##__VA_ARGS__)))
#define CMf__16(P,f,...) CMf_P17(CMf_P17(CM_##f(,P##__VA_ARGS__)))
#define CMf__17(P,f,...) CMf_P18(CMf_P18(CM_##f(,P##__VA_ARGS__)))
#define CMf__18(P,f,...) CMf_P19(CMf_P19(CM_##f(,P##__VA_ARGS__)))
#define CMf__19(P,f,...) CMf_P1a(CMf_P1a(CM_##f(,P##__VA_ARGS__)))
#define CMf__1a(P,f,...) CMf_P1b(CMf_P1b(CM_##f(,P##__VA_ARGS__)))
#define CMf__1b(P,f,...) CMf_P1c(CMf_P1c(CM_##f(,P##__VA_ARGS__)))
#define CMf__1c(P,f,...) CMf_P1d(CMf_P1d(CM_##f(,P##__VA_ARGS__)))
#define CMf__1d(P,f,...) CMf_P1e(CMf_P1e(CM_##f(,P##__VA_ARGS__)))
#define CMf__1e(P,f,...) CMf_P1f(CMf_P1f(CM_##f(,P##__VA_ARGS__)))
#define CMf__1f(P,f,...) CM_##f(,P##__VA_ARGS__)

#define CMf_P01(x) CMf__01 x
#define CMf_P02(x) CMf__02 x
#define CMf_P03(x) CMf__03 x
#define CMf_P04(x) CMf__04 x
#define CMf_P05(x) CMf__05 x
#define CMf_P06(x) CMf__06 x
#define CMf_P07(x) CMf__07 x
#define CMf_P08(x) CMf__08 x
#define CMf_P09(x) CMf__09 x
#define CMf_P0a(x) CMf__0a x
#define CMf_P0b(x) CMf__0b x
#define CMf_P0c(x) CMf__0c x
#define CMf_P0d(x) CMf__0d x
#define CMf_P0e(x) CMf__0e x
#define CMf_P0f(x) CMf__0f x
#define CMf_P10(x) CMf__10 x
#define CMf_P11(x) CMf__11 x
#define CMf_P12(x) CMf__12 x
#define CMf_P13(x) CMf__13 x
#define CMf_P14(x) CMf__14 x
#define CMf_P15(x) CMf__15 x
#define CMf_P16(x) CMf__16 x
#define CMf_P17(x) CMf__17 x
#define CMf_P18(x) CMf__18 x
#define CMf_P19(x) CMf__19 x
#define CMf_P1a(x) CMf__1a x
#define CMf_P1b(x) CMf__1b x
#define CMf_P1c(x) CMf__1c x
#define CMf_P1d(x) CMf__1d x
#define CMf_P1e(x) CMf__1e x
#define CMf_P1f(x) CMf__1f x

