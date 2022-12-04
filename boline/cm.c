#define CM_SCAN(...) __VA_ARGS__
#define CM_EAT(...)
#define CM_LPAREN (

#define CM0(...)  CM_SCAN(CM_EAT CM_LPAREN CM0__0(__VA_ARGS__))
#define CM1(...)  CM_SCAN(CM_EAT CM_LPAREN CM1__0(__VA_ARGS__))
#define CM2(...)  CM_SCAN(CM_EAT CM_LPAREN CM2__0(__VA_ARGS__))
#define CM3(...)  CM_SCAN(CM_EAT CM_LPAREN CM3__0(__VA_ARGS__))
#define CM4(...)  CM_SCAN(CM_EAT CM_LPAREN CM4__0(__VA_ARGS__))
#define CM5(...)  CM_SCAN(CM_EAT CM_LPAREN CM5__0(__VA_ARGS__))
#define CM6(...)  CM_SCAN(CM_EAT CM_LPAREN CM6__0(__VA_ARGS__))
#define CM7(...)  CM_SCAN(CM_EAT CM_LPAREN CM7__0(__VA_ARGS__))
#define CM8(...)  CM_SCAN(CM_EAT CM_LPAREN CM8__0(__VA_ARGS__))
#define CM9(...)  CM_SCAN(CM_EAT CM_LPAREN CM9__0(__VA_ARGS__))
#define CMa(...)  CM_SCAN(CM_EAT CM_LPAREN CMa__0(__VA_ARGS__))
#define CMb(...)  CM_SCAN(CM_EAT CM_LPAREN CMb__0(__VA_ARGS__))
#define CMc(...)  CM_SCAN(CM_EAT CM_LPAREN CMc__0(__VA_ARGS__))
#define CMd(...)  CM_SCAN(CM_EAT CM_LPAREN CMd__0(__VA_ARGS__))
#define CMe(...)  CM_SCAN(CM_EAT CM_LPAREN CMe__0(__VA_ARGS__))
#define CMf(...)  CM_SCAN(CM_EAT CM_LPAREN CMf__0(__VA_ARGS__))

#define CM_PROBE ),1,(
#define CM_IF(x) CM_IF_(x,0,)
#define CM_IF_(b,a,...) CM_IF_##a
#define CM_IF_1(a,b) a
#define CM_IF_0(a,b) b

#define CM \
	CM_IF(CM7__0(CM_,,PROBE))( \
	      CM_IF(CM3__0(CM_,,PROBE))( \
	            CM_IF(CM1__0(CM_,,PROBE))( \
	                  CM_IF(CM0__0(CM_,,PROBE))(CM0,CM1), \
	                  CM_IF(CM2__0(CM_,,PROBE))(CM2,CM3)), \
	            CM_IF(CM5__0(CM_,,PROBE))( \
	                  CM_IF(CM4__0(CM_,,PROBE))(CM4,CM5), \
	                  CM_IF(CM6__0(CM_,,PROBE))(CM6,CM7))), \
	      CM_IF(CMb__0(CM_,,PROBE))( \
	            CM_IF(CM9__0(CM_,,PROBE))( \
	                  CM_IF(CM8__0(CM_,,PROBE))(CM8,CM9), \
	                  CM_IF(CMa__0(CM_,,PROBE))(CMa,CMb)), \
	            CM_IF(CMd__0(CM_,,PROBE))( \
	                  CM_IF(CMc__0(CM_,,PROBE))(CMc,CMd), \
	                  CM_IF(CMe__0(CM_,,PROBE))(CMe,CMf)))) \

#define CM0__0(P,f,...) CM0_P1(CM0_P1(CM0_P1(CM0_P1(CM0_P1(CM_##f(,P##__VA_ARGS__))))))
#define CM0__1(P,f,...) CM0_P2(CM0_P2(CM0_P2(CM0_P2(CM0_P2(CM_##f(,P##__VA_ARGS__))))))
#define CM0__2(P,f,...) CM0_P3(CM0_P3(CM0_P3(CM0_P3(CM0_P3(CM_##f(,P##__VA_ARGS__))))))
#define CM0__3(P,f,...) CM0_P4(CM0_P4(CM0_P4(CM0_P4(CM0_P4(CM_##f(,P##__VA_ARGS__))))))
#define CM0__4(P,f,...) CM0_P5(CM0_P5(CM0_P5(CM0_P5(CM0_P5(CM_##f(,P##__VA_ARGS__))))))
#define CM0__5(P,f,...) CM0_P6(CM0_P6(CM0_P6(CM0_P6(CM0_P6(CM_##f(,P##__VA_ARGS__))))))
#define CM0__6(P,f,...) CM0_P7(CM0_P7(CM0_P7(CM0_P7(CM0_P7(CM_##f(,P##__VA_ARGS__))))))
#define CM0__7(P,f,...) CM0_P8(CM0_P8(CM0_P8(CM0_P8(CM0_P8(CM_##f(,P##__VA_ARGS__))))))
#define CM0__8(P,f,...) CM0_P9(CM0_P9(CM0_P9(CM0_P9(CM0_P9(CM_##f(,P##__VA_ARGS__))))))
#define CM0__9(P,f,...) CM0_Pa(CM0_Pa(CM0_Pa(CM0_Pa(CM0_Pa(CM_##f(,P##__VA_ARGS__))))))
#define CM0__a(P,f,...) CM0_Pb(CM0_Pb(CM0_Pb(CM0_Pb(CM0_Pb(CM_##f(,P##__VA_ARGS__))))))
#define CM0__b(P,f,...) CM0_Pc(CM0_Pc(CM0_Pc(CM0_Pc(CM0_Pc(CM_##f(,P##__VA_ARGS__))))))
#define CM0__c(P,f,...) CM0_Pd(CM0_Pd(CM0_Pd(CM0_Pd(CM0_Pd(CM_##f(,P##__VA_ARGS__))))))
#define CM0__d(P,f,...) CM0_Pe(CM0_Pe(CM0_Pe(CM0_Pe(CM0_Pe(CM_##f(,P##__VA_ARGS__))))))
#define CM0__e(P,f,...) CM0_Pf(CM0_Pf(CM0_Pf(CM0_Pf(CM0_Pf(CM_##f(,P##__VA_ARGS__))))))
#define CM0__f(P,f,...) CM_##f(,P##__VA_ARGS__)
#define CM0_P1(x) CM0__1 x
#define CM0_P2(x) CM0__2 x
#define CM0_P3(x) CM0__3 x
#define CM0_P4(x) CM0__4 x
#define CM0_P5(x) CM0__5 x
#define CM0_P6(x) CM0__6 x
#define CM0_P7(x) CM0__7 x
#define CM0_P8(x) CM0__8 x
#define CM0_P9(x) CM0__9 x
#define CM0_Pa(x) CM0__a x
#define CM0_Pb(x) CM0__b x
#define CM0_Pc(x) CM0__c x
#define CM0_Pd(x) CM0__d x
#define CM0_Pe(x) CM0__e x
#define CM0_Pf(x) CM0__f x

#define CM1__0(P,f,...) CM1_P1(CM1_P1(CM1_P1(CM1_P1(CM1_P1(CM_##f(,P##__VA_ARGS__))))))
#define CM1__1(P,f,...) CM1_P2(CM1_P2(CM1_P2(CM1_P2(CM1_P2(CM_##f(,P##__VA_ARGS__))))))
#define CM1__2(P,f,...) CM1_P3(CM1_P3(CM1_P3(CM1_P3(CM1_P3(CM_##f(,P##__VA_ARGS__))))))
#define CM1__3(P,f,...) CM1_P4(CM1_P4(CM1_P4(CM1_P4(CM1_P4(CM_##f(,P##__VA_ARGS__))))))
#define CM1__4(P,f,...) CM1_P5(CM1_P5(CM1_P5(CM1_P5(CM1_P5(CM_##f(,P##__VA_ARGS__))))))
#define CM1__5(P,f,...) CM1_P6(CM1_P6(CM1_P6(CM1_P6(CM1_P6(CM_##f(,P##__VA_ARGS__))))))
#define CM1__6(P,f,...) CM1_P7(CM1_P7(CM1_P7(CM1_P7(CM1_P7(CM_##f(,P##__VA_ARGS__))))))
#define CM1__7(P,f,...) CM1_P8(CM1_P8(CM1_P8(CM1_P8(CM1_P8(CM_##f(,P##__VA_ARGS__))))))
#define CM1__8(P,f,...) CM1_P9(CM1_P9(CM1_P9(CM1_P9(CM1_P9(CM_##f(,P##__VA_ARGS__))))))
#define CM1__9(P,f,...) CM1_Pa(CM1_Pa(CM1_Pa(CM1_Pa(CM1_Pa(CM_##f(,P##__VA_ARGS__))))))
#define CM1__a(P,f,...) CM1_Pb(CM1_Pb(CM1_Pb(CM1_Pb(CM1_Pb(CM_##f(,P##__VA_ARGS__))))))
#define CM1__b(P,f,...) CM1_Pc(CM1_Pc(CM1_Pc(CM1_Pc(CM1_Pc(CM_##f(,P##__VA_ARGS__))))))
#define CM1__c(P,f,...) CM1_Pd(CM1_Pd(CM1_Pd(CM1_Pd(CM1_Pd(CM_##f(,P##__VA_ARGS__))))))
#define CM1__d(P,f,...) CM1_Pe(CM1_Pe(CM1_Pe(CM1_Pe(CM1_Pe(CM_##f(,P##__VA_ARGS__))))))
#define CM1__e(P,f,...) CM1_Pf(CM1_Pf(CM1_Pf(CM1_Pf(CM1_Pf(CM_##f(,P##__VA_ARGS__))))))
#define CM1__f(P,f,...) CM_##f(,P##__VA_ARGS__)
#define CM1_P1(x) CM1__1 x
#define CM1_P2(x) CM1__2 x
#define CM1_P3(x) CM1__3 x
#define CM1_P4(x) CM1__4 x
#define CM1_P5(x) CM1__5 x
#define CM1_P6(x) CM1__6 x
#define CM1_P7(x) CM1__7 x
#define CM1_P8(x) CM1__8 x
#define CM1_P9(x) CM1__9 x
#define CM1_Pa(x) CM1__a x
#define CM1_Pb(x) CM1__b x
#define CM1_Pc(x) CM1__c x
#define CM1_Pd(x) CM1__d x
#define CM1_Pe(x) CM1__e x
#define CM1_Pf(x) CM1__f x

#define CM2__0(P,f,...) CM2_P1(CM2_P1(CM2_P1(CM2_P1(CM2_P1(CM_##f(,P##__VA_ARGS__))))))
#define CM2__1(P,f,...) CM2_P2(CM2_P2(CM2_P2(CM2_P2(CM2_P2(CM_##f(,P##__VA_ARGS__))))))
#define CM2__2(P,f,...) CM2_P3(CM2_P3(CM2_P3(CM2_P3(CM2_P3(CM_##f(,P##__VA_ARGS__))))))
#define CM2__3(P,f,...) CM2_P4(CM2_P4(CM2_P4(CM2_P4(CM2_P4(CM_##f(,P##__VA_ARGS__))))))
#define CM2__4(P,f,...) CM2_P5(CM2_P5(CM2_P5(CM2_P5(CM2_P5(CM_##f(,P##__VA_ARGS__))))))
#define CM2__5(P,f,...) CM2_P6(CM2_P6(CM2_P6(CM2_P6(CM2_P6(CM_##f(,P##__VA_ARGS__))))))
#define CM2__6(P,f,...) CM2_P7(CM2_P7(CM2_P7(CM2_P7(CM2_P7(CM_##f(,P##__VA_ARGS__))))))
#define CM2__7(P,f,...) CM2_P8(CM2_P8(CM2_P8(CM2_P8(CM2_P8(CM_##f(,P##__VA_ARGS__))))))
#define CM2__8(P,f,...) CM2_P9(CM2_P9(CM2_P9(CM2_P9(CM2_P9(CM_##f(,P##__VA_ARGS__))))))
#define CM2__9(P,f,...) CM2_Pa(CM2_Pa(CM2_Pa(CM2_Pa(CM2_Pa(CM_##f(,P##__VA_ARGS__))))))
#define CM2__a(P,f,...) CM2_Pb(CM2_Pb(CM2_Pb(CM2_Pb(CM2_Pb(CM_##f(,P##__VA_ARGS__))))))
#define CM2__b(P,f,...) CM2_Pc(CM2_Pc(CM2_Pc(CM2_Pc(CM2_Pc(CM_##f(,P##__VA_ARGS__))))))
#define CM2__c(P,f,...) CM2_Pd(CM2_Pd(CM2_Pd(CM2_Pd(CM2_Pd(CM_##f(,P##__VA_ARGS__))))))
#define CM2__d(P,f,...) CM2_Pe(CM2_Pe(CM2_Pe(CM2_Pe(CM2_Pe(CM_##f(,P##__VA_ARGS__))))))
#define CM2__e(P,f,...) CM2_Pf(CM2_Pf(CM2_Pf(CM2_Pf(CM2_Pf(CM_##f(,P##__VA_ARGS__))))))
#define CM2__f(P,f,...) CM_##f(,P##__VA_ARGS__)
#define CM2_P1(x) CM2__1 x
#define CM2_P2(x) CM2__2 x
#define CM2_P3(x) CM2__3 x
#define CM2_P4(x) CM2__4 x
#define CM2_P5(x) CM2__5 x
#define CM2_P6(x) CM2__6 x
#define CM2_P7(x) CM2__7 x
#define CM2_P8(x) CM2__8 x
#define CM2_P9(x) CM2__9 x
#define CM2_Pa(x) CM2__a x
#define CM2_Pb(x) CM2__b x
#define CM2_Pc(x) CM2__c x
#define CM2_Pd(x) CM2__d x
#define CM2_Pe(x) CM2__e x
#define CM2_Pf(x) CM2__f x
#define CM2_Pf(x) CM2__f x

#define CM3__0(P,f,...) CM3_P1(CM3_P1(CM3_P1(CM3_P1(CM3_P1(CM_##f(,P##__VA_ARGS__))))))
#define CM3__1(P,f,...) CM3_P2(CM3_P2(CM3_P2(CM3_P2(CM3_P2(CM_##f(,P##__VA_ARGS__))))))
#define CM3__2(P,f,...) CM3_P3(CM3_P3(CM3_P3(CM3_P3(CM3_P3(CM_##f(,P##__VA_ARGS__))))))
#define CM3__3(P,f,...) CM3_P4(CM3_P4(CM3_P4(CM3_P4(CM3_P4(CM_##f(,P##__VA_ARGS__))))))
#define CM3__4(P,f,...) CM3_P5(CM3_P5(CM3_P5(CM3_P5(CM3_P5(CM_##f(,P##__VA_ARGS__))))))
#define CM3__5(P,f,...) CM3_P6(CM3_P6(CM3_P6(CM3_P6(CM3_P6(CM_##f(,P##__VA_ARGS__))))))
#define CM3__6(P,f,...) CM3_P7(CM3_P7(CM3_P7(CM3_P7(CM3_P7(CM_##f(,P##__VA_ARGS__))))))
#define CM3__7(P,f,...) CM3_P8(CM3_P8(CM3_P8(CM3_P8(CM3_P8(CM_##f(,P##__VA_ARGS__))))))
#define CM3__8(P,f,...) CM3_P9(CM3_P9(CM3_P9(CM3_P9(CM3_P9(CM_##f(,P##__VA_ARGS__))))))
#define CM3__9(P,f,...) CM3_Pa(CM3_Pa(CM3_Pa(CM3_Pa(CM3_Pa(CM_##f(,P##__VA_ARGS__))))))
#define CM3__a(P,f,...) CM3_Pb(CM3_Pb(CM3_Pb(CM3_Pb(CM3_Pb(CM_##f(,P##__VA_ARGS__))))))
#define CM3__b(P,f,...) CM3_Pc(CM3_Pc(CM3_Pc(CM3_Pc(CM3_Pc(CM_##f(,P##__VA_ARGS__))))))
#define CM3__c(P,f,...) CM3_Pd(CM3_Pd(CM3_Pd(CM3_Pd(CM3_Pd(CM_##f(,P##__VA_ARGS__))))))
#define CM3__d(P,f,...) CM3_Pe(CM3_Pe(CM3_Pe(CM3_Pe(CM3_Pe(CM_##f(,P##__VA_ARGS__))))))
#define CM3__e(P,f,...) CM3_Pf(CM3_Pf(CM3_Pf(CM3_Pf(CM3_Pf(CM_##f(,P##__VA_ARGS__))))))
#define CM3__f(P,f,...) CM_##f(,P##__VA_ARGS__)
#define CM3_P1(x) CM3__1 x
#define CM3_P2(x) CM3__2 x
#define CM3_P3(x) CM3__3 x
#define CM3_P4(x) CM3__4 x
#define CM3_P5(x) CM3__5 x
#define CM3_P6(x) CM3__6 x
#define CM3_P7(x) CM3__7 x
#define CM3_P8(x) CM3__8 x
#define CM3_P9(x) CM3__9 x
#define CM3_Pa(x) CM3__a x
#define CM3_Pb(x) CM3__b x
#define CM3_Pc(x) CM3__c x
#define CM3_Pd(x) CM3__d x
#define CM3_Pe(x) CM3__e x
#define CM3_Pf(x) CM3__f x

#define CM4__0(P,f,...) CM4_P1(CM4_P1(CM4_P1(CM4_P1(CM4_P1(CM_##f(,P##__VA_ARGS__))))))
#define CM4__1(P,f,...) CM4_P2(CM4_P2(CM4_P2(CM4_P2(CM4_P2(CM_##f(,P##__VA_ARGS__))))))
#define CM4__2(P,f,...) CM4_P3(CM4_P3(CM4_P3(CM4_P3(CM4_P3(CM_##f(,P##__VA_ARGS__))))))
#define CM4__3(P,f,...) CM4_P4(CM4_P4(CM4_P4(CM4_P4(CM4_P4(CM_##f(,P##__VA_ARGS__))))))
#define CM4__4(P,f,...) CM4_P5(CM4_P5(CM4_P5(CM4_P5(CM4_P5(CM_##f(,P##__VA_ARGS__))))))
#define CM4__5(P,f,...) CM4_P6(CM4_P6(CM4_P6(CM4_P6(CM4_P6(CM_##f(,P##__VA_ARGS__))))))
#define CM4__6(P,f,...) CM4_P7(CM4_P7(CM4_P7(CM4_P7(CM4_P7(CM_##f(,P##__VA_ARGS__))))))
#define CM4__7(P,f,...) CM4_P8(CM4_P8(CM4_P8(CM4_P8(CM4_P8(CM_##f(,P##__VA_ARGS__))))))
#define CM4__8(P,f,...) CM4_P9(CM4_P9(CM4_P9(CM4_P9(CM4_P9(CM_##f(,P##__VA_ARGS__))))))
#define CM4__9(P,f,...) CM4_Pa(CM4_Pa(CM4_Pa(CM4_Pa(CM4_Pa(CM_##f(,P##__VA_ARGS__))))))
#define CM4__a(P,f,...) CM4_Pb(CM4_Pb(CM4_Pb(CM4_Pb(CM4_Pb(CM_##f(,P##__VA_ARGS__))))))
#define CM4__b(P,f,...) CM4_Pc(CM4_Pc(CM4_Pc(CM4_Pc(CM4_Pc(CM_##f(,P##__VA_ARGS__))))))
#define CM4__c(P,f,...) CM4_Pd(CM4_Pd(CM4_Pd(CM4_Pd(CM4_Pd(CM_##f(,P##__VA_ARGS__))))))
#define CM4__d(P,f,...) CM4_Pe(CM4_Pe(CM4_Pe(CM4_Pe(CM4_Pe(CM_##f(,P##__VA_ARGS__))))))
#define CM4__e(P,f,...) CM4_Pf(CM4_Pf(CM4_Pf(CM4_Pf(CM4_Pf(CM_##f(,P##__VA_ARGS__))))))
#define CM4__f(P,f,...) CM_##f(,P##__VA_ARGS__)
#define CM4_P1(x) CM4__1 x
#define CM4_P2(x) CM4__2 x
#define CM4_P3(x) CM4__3 x
#define CM4_P4(x) CM4__4 x
#define CM4_P5(x) CM4__5 x
#define CM4_P6(x) CM4__6 x
#define CM4_P7(x) CM4__7 x
#define CM4_P8(x) CM4__8 x
#define CM4_P9(x) CM4__9 x
#define CM4_Pa(x) CM4__a x
#define CM4_Pb(x) CM4__b x
#define CM4_Pc(x) CM4__c x
#define CM4_Pd(x) CM4__d x
#define CM4_Pe(x) CM4__e x
#define CM4_Pf(x) CM4__f x

#define CM5__0(P,f,...) CM5_P1(CM5_P1(CM5_P1(CM5_P1(CM5_P1(CM_##f(,P##__VA_ARGS__))))))
#define CM5__1(P,f,...) CM5_P2(CM5_P2(CM5_P2(CM5_P2(CM5_P2(CM_##f(,P##__VA_ARGS__))))))
#define CM5__2(P,f,...) CM5_P3(CM5_P3(CM5_P3(CM5_P3(CM5_P3(CM_##f(,P##__VA_ARGS__))))))
#define CM5__3(P,f,...) CM5_P4(CM5_P4(CM5_P4(CM5_P4(CM5_P4(CM_##f(,P##__VA_ARGS__))))))
#define CM5__4(P,f,...) CM5_P5(CM5_P5(CM5_P5(CM5_P5(CM5_P5(CM_##f(,P##__VA_ARGS__))))))
#define CM5__5(P,f,...) CM5_P6(CM5_P6(CM5_P6(CM5_P6(CM5_P6(CM_##f(,P##__VA_ARGS__))))))
#define CM5__6(P,f,...) CM5_P7(CM5_P7(CM5_P7(CM5_P7(CM5_P7(CM_##f(,P##__VA_ARGS__))))))
#define CM5__7(P,f,...) CM5_P8(CM5_P8(CM5_P8(CM5_P8(CM5_P8(CM_##f(,P##__VA_ARGS__))))))
#define CM5__8(P,f,...) CM5_P9(CM5_P9(CM5_P9(CM5_P9(CM5_P9(CM_##f(,P##__VA_ARGS__))))))
#define CM5__9(P,f,...) CM5_Pa(CM5_Pa(CM5_Pa(CM5_Pa(CM5_Pa(CM_##f(,P##__VA_ARGS__))))))
#define CM5__a(P,f,...) CM5_Pb(CM5_Pb(CM5_Pb(CM5_Pb(CM5_Pb(CM_##f(,P##__VA_ARGS__))))))
#define CM5__b(P,f,...) CM5_Pc(CM5_Pc(CM5_Pc(CM5_Pc(CM5_Pc(CM_##f(,P##__VA_ARGS__))))))
#define CM5__c(P,f,...) CM5_Pd(CM5_Pd(CM5_Pd(CM5_Pd(CM5_Pd(CM_##f(,P##__VA_ARGS__))))))
#define CM5__d(P,f,...) CM5_Pe(CM5_Pe(CM5_Pe(CM5_Pe(CM5_Pe(CM_##f(,P##__VA_ARGS__))))))
#define CM5__e(P,f,...) CM5_Pf(CM5_Pf(CM5_Pf(CM5_Pf(CM5_Pf(CM_##f(,P##__VA_ARGS__))))))
#define CM5__f(P,f,...) CM_##f(,P##__VA_ARGS__)
#define CM5_P1(x) CM5__1 x
#define CM5_P2(x) CM5__2 x
#define CM5_P3(x) CM5__3 x
#define CM5_P4(x) CM5__4 x
#define CM5_P5(x) CM5__5 x
#define CM5_P6(x) CM5__6 x
#define CM5_P7(x) CM5__7 x
#define CM5_P8(x) CM5__8 x
#define CM5_P9(x) CM5__9 x
#define CM5_Pa(x) CM5__a x
#define CM5_Pb(x) CM5__b x
#define CM5_Pc(x) CM5__c x
#define CM5_Pd(x) CM5__d x
#define CM5_Pe(x) CM5__e x
#define CM5_Pf(x) CM5__f x

#define CM6__0(P,f,...) CM6_P1(CM6_P1(CM6_P1(CM6_P1(CM6_P1(CM_##f(,P##__VA_ARGS__))))))
#define CM6__1(P,f,...) CM6_P2(CM6_P2(CM6_P2(CM6_P2(CM6_P2(CM_##f(,P##__VA_ARGS__))))))
#define CM6__2(P,f,...) CM6_P3(CM6_P3(CM6_P3(CM6_P3(CM6_P3(CM_##f(,P##__VA_ARGS__))))))
#define CM6__3(P,f,...) CM6_P4(CM6_P4(CM6_P4(CM6_P4(CM6_P4(CM_##f(,P##__VA_ARGS__))))))
#define CM6__4(P,f,...) CM6_P5(CM6_P5(CM6_P5(CM6_P5(CM6_P5(CM_##f(,P##__VA_ARGS__))))))
#define CM6__5(P,f,...) CM6_P6(CM6_P6(CM6_P6(CM6_P6(CM6_P6(CM_##f(,P##__VA_ARGS__))))))
#define CM6__6(P,f,...) CM6_P7(CM6_P7(CM6_P7(CM6_P7(CM6_P7(CM_##f(,P##__VA_ARGS__))))))
#define CM6__7(P,f,...) CM6_P8(CM6_P8(CM6_P8(CM6_P8(CM6_P8(CM_##f(,P##__VA_ARGS__))))))
#define CM6__8(P,f,...) CM6_P9(CM6_P9(CM6_P9(CM6_P9(CM6_P9(CM_##f(,P##__VA_ARGS__))))))
#define CM6__9(P,f,...) CM6_Pa(CM6_Pa(CM6_Pa(CM6_Pa(CM6_Pa(CM_##f(,P##__VA_ARGS__))))))
#define CM6__a(P,f,...) CM6_Pb(CM6_Pb(CM6_Pb(CM6_Pb(CM6_Pb(CM_##f(,P##__VA_ARGS__))))))
#define CM6__b(P,f,...) CM6_Pc(CM6_Pc(CM6_Pc(CM6_Pc(CM6_Pc(CM_##f(,P##__VA_ARGS__))))))
#define CM6__c(P,f,...) CM6_Pd(CM6_Pd(CM6_Pd(CM6_Pd(CM6_Pd(CM_##f(,P##__VA_ARGS__))))))
#define CM6__d(P,f,...) CM6_Pe(CM6_Pe(CM6_Pe(CM6_Pe(CM6_Pe(CM_##f(,P##__VA_ARGS__))))))
#define CM6__e(P,f,...) CM6_Pf(CM6_Pf(CM6_Pf(CM6_Pf(CM6_Pf(CM_##f(,P##__VA_ARGS__))))))
#define CM6__f(P,f,...) CM_##f(,P##__VA_ARGS__)
#define CM6_P1(x) CM6__1 x
#define CM6_P2(x) CM6__2 x
#define CM6_P3(x) CM6__3 x
#define CM6_P4(x) CM6__4 x
#define CM6_P5(x) CM6__5 x
#define CM6_P6(x) CM6__6 x
#define CM6_P7(x) CM6__7 x
#define CM6_P8(x) CM6__8 x
#define CM6_P9(x) CM6__9 x
#define CM6_Pa(x) CM6__a x
#define CM6_Pb(x) CM6__b x
#define CM6_Pc(x) CM6__c x
#define CM6_Pd(x) CM6__d x
#define CM6_Pe(x) CM6__e x
#define CM6_Pf(x) CM6__f x

#define CM7__0(P,f,...) CM7_P1(CM7_P1(CM7_P1(CM7_P1(CM7_P1(CM_##f(,P##__VA_ARGS__))))))
#define CM7__1(P,f,...) CM7_P2(CM7_P2(CM7_P2(CM7_P2(CM7_P2(CM_##f(,P##__VA_ARGS__))))))
#define CM7__2(P,f,...) CM7_P3(CM7_P3(CM7_P3(CM7_P3(CM7_P3(CM_##f(,P##__VA_ARGS__))))))
#define CM7__3(P,f,...) CM7_P4(CM7_P4(CM7_P4(CM7_P4(CM7_P4(CM_##f(,P##__VA_ARGS__))))))
#define CM7__4(P,f,...) CM7_P5(CM7_P5(CM7_P5(CM7_P5(CM7_P5(CM_##f(,P##__VA_ARGS__))))))
#define CM7__5(P,f,...) CM7_P6(CM7_P6(CM7_P6(CM7_P6(CM7_P6(CM_##f(,P##__VA_ARGS__))))))
#define CM7__6(P,f,...) CM7_P7(CM7_P7(CM7_P7(CM7_P7(CM7_P7(CM_##f(,P##__VA_ARGS__))))))
#define CM7__7(P,f,...) CM7_P8(CM7_P8(CM7_P8(CM7_P8(CM7_P8(CM_##f(,P##__VA_ARGS__))))))
#define CM7__8(P,f,...) CM7_P9(CM7_P9(CM7_P9(CM7_P9(CM7_P9(CM_##f(,P##__VA_ARGS__))))))
#define CM7__9(P,f,...) CM7_Pa(CM7_Pa(CM7_Pa(CM7_Pa(CM7_Pa(CM_##f(,P##__VA_ARGS__))))))
#define CM7__a(P,f,...) CM7_Pb(CM7_Pb(CM7_Pb(CM7_Pb(CM7_Pb(CM_##f(,P##__VA_ARGS__))))))
#define CM7__b(P,f,...) CM7_Pc(CM7_Pc(CM7_Pc(CM7_Pc(CM7_Pc(CM_##f(,P##__VA_ARGS__))))))
#define CM7__c(P,f,...) CM7_Pd(CM7_Pd(CM7_Pd(CM7_Pd(CM7_Pd(CM_##f(,P##__VA_ARGS__))))))
#define CM7__d(P,f,...) CM7_Pe(CM7_Pe(CM7_Pe(CM7_Pe(CM7_Pe(CM_##f(,P##__VA_ARGS__))))))
#define CM7__e(P,f,...) CM7_Pf(CM7_Pf(CM7_Pf(CM7_Pf(CM7_Pf(CM_##f(,P##__VA_ARGS__))))))
#define CM7__f(P,f,...) CM_##f(,P##__VA_ARGS__)
#define CM7_P1(x) CM7__1 x
#define CM7_P2(x) CM7__2 x
#define CM7_P3(x) CM7__3 x
#define CM7_P4(x) CM7__4 x
#define CM7_P5(x) CM7__5 x
#define CM7_P6(x) CM7__6 x
#define CM7_P7(x) CM7__7 x
#define CM7_P8(x) CM7__8 x
#define CM7_P9(x) CM7__9 x
#define CM7_Pa(x) CM7__a x
#define CM7_Pb(x) CM7__b x
#define CM7_Pc(x) CM7__c x
#define CM7_Pd(x) CM7__d x
#define CM7_Pe(x) CM7__e x
#define CM7_Pf(x) CM7__f x

#define CM8__0(P,f,...) CM8_P1(CM8_P1(CM8_P1(CM8_P1(CM8_P1(CM_##f(,P##__VA_ARGS__))))))
#define CM8__1(P,f,...) CM8_P2(CM8_P2(CM8_P2(CM8_P2(CM8_P2(CM_##f(,P##__VA_ARGS__))))))
#define CM8__2(P,f,...) CM8_P3(CM8_P3(CM8_P3(CM8_P3(CM8_P3(CM_##f(,P##__VA_ARGS__))))))
#define CM8__3(P,f,...) CM8_P4(CM8_P4(CM8_P4(CM8_P4(CM8_P4(CM_##f(,P##__VA_ARGS__))))))
#define CM8__4(P,f,...) CM8_P5(CM8_P5(CM8_P5(CM8_P5(CM8_P5(CM_##f(,P##__VA_ARGS__))))))
#define CM8__5(P,f,...) CM8_P6(CM8_P6(CM8_P6(CM8_P6(CM8_P6(CM_##f(,P##__VA_ARGS__))))))
#define CM8__6(P,f,...) CM8_P7(CM8_P7(CM8_P7(CM8_P7(CM8_P7(CM_##f(,P##__VA_ARGS__))))))
#define CM8__7(P,f,...) CM8_P8(CM8_P8(CM8_P8(CM8_P8(CM8_P8(CM_##f(,P##__VA_ARGS__))))))
#define CM8__8(P,f,...) CM8_P9(CM8_P9(CM8_P9(CM8_P9(CM8_P9(CM_##f(,P##__VA_ARGS__))))))
#define CM8__9(P,f,...) CM8_Pa(CM8_Pa(CM8_Pa(CM8_Pa(CM8_Pa(CM_##f(,P##__VA_ARGS__))))))
#define CM8__a(P,f,...) CM8_Pb(CM8_Pb(CM8_Pb(CM8_Pb(CM8_Pb(CM_##f(,P##__VA_ARGS__))))))
#define CM8__b(P,f,...) CM8_Pc(CM8_Pc(CM8_Pc(CM8_Pc(CM8_Pc(CM_##f(,P##__VA_ARGS__))))))
#define CM8__c(P,f,...) CM8_Pd(CM8_Pd(CM8_Pd(CM8_Pd(CM8_Pd(CM_##f(,P##__VA_ARGS__))))))
#define CM8__d(P,f,...) CM8_Pe(CM8_Pe(CM8_Pe(CM8_Pe(CM8_Pe(CM_##f(,P##__VA_ARGS__))))))
#define CM8__e(P,f,...) CM8_Pf(CM8_Pf(CM8_Pf(CM8_Pf(CM8_Pf(CM_##f(,P##__VA_ARGS__))))))
#define CM8__f(P,f,...) CM_##f(,P##__VA_ARGS__)
#define CM8_P1(x) CM8__1 x
#define CM8_P2(x) CM8__2 x
#define CM8_P3(x) CM8__3 x
#define CM8_P4(x) CM8__4 x
#define CM8_P5(x) CM8__5 x
#define CM8_P6(x) CM8__6 x
#define CM8_P7(x) CM8__7 x
#define CM8_P8(x) CM8__8 x
#define CM8_P9(x) CM8__9 x
#define CM8_Pa(x) CM8__a x
#define CM8_Pb(x) CM8__b x
#define CM8_Pc(x) CM8__c x
#define CM8_Pd(x) CM8__d x
#define CM8_Pe(x) CM8__e x
#define CM8_Pf(x) CM8__f x

#define CM9__0(P,f,...) CM9_P1(CM9_P1(CM9_P1(CM9_P1(CM9_P1(CM_##f(,P##__VA_ARGS__))))))
#define CM9__1(P,f,...) CM9_P2(CM9_P2(CM9_P2(CM9_P2(CM9_P2(CM_##f(,P##__VA_ARGS__))))))
#define CM9__2(P,f,...) CM9_P3(CM9_P3(CM9_P3(CM9_P3(CM9_P3(CM_##f(,P##__VA_ARGS__))))))
#define CM9__3(P,f,...) CM9_P4(CM9_P4(CM9_P4(CM9_P4(CM9_P4(CM_##f(,P##__VA_ARGS__))))))
#define CM9__4(P,f,...) CM9_P5(CM9_P5(CM9_P5(CM9_P5(CM9_P5(CM_##f(,P##__VA_ARGS__))))))
#define CM9__5(P,f,...) CM9_P6(CM9_P6(CM9_P6(CM9_P6(CM9_P6(CM_##f(,P##__VA_ARGS__))))))
#define CM9__6(P,f,...) CM9_P7(CM9_P7(CM9_P7(CM9_P7(CM9_P7(CM_##f(,P##__VA_ARGS__))))))
#define CM9__7(P,f,...) CM9_P8(CM9_P8(CM9_P8(CM9_P8(CM9_P8(CM_##f(,P##__VA_ARGS__))))))
#define CM9__8(P,f,...) CM9_P9(CM9_P9(CM9_P9(CM9_P9(CM9_P9(CM_##f(,P##__VA_ARGS__))))))
#define CM9__9(P,f,...) CM9_Pa(CM9_Pa(CM9_Pa(CM9_Pa(CM9_Pa(CM_##f(,P##__VA_ARGS__))))))
#define CM9__a(P,f,...) CM9_Pb(CM9_Pb(CM9_Pb(CM9_Pb(CM9_Pb(CM_##f(,P##__VA_ARGS__))))))
#define CM9__b(P,f,...) CM9_Pc(CM9_Pc(CM9_Pc(CM9_Pc(CM9_Pc(CM_##f(,P##__VA_ARGS__))))))
#define CM9__c(P,f,...) CM9_Pd(CM9_Pd(CM9_Pd(CM9_Pd(CM9_Pd(CM_##f(,P##__VA_ARGS__))))))
#define CM9__d(P,f,...) CM9_Pe(CM9_Pe(CM9_Pe(CM9_Pe(CM9_Pe(CM_##f(,P##__VA_ARGS__))))))
#define CM9__e(P,f,...) CM9_Pf(CM9_Pf(CM9_Pf(CM9_Pf(CM9_Pf(CM_##f(,P##__VA_ARGS__))))))
#define CM9__f(P,f,...) CM_##f(,P##__VA_ARGS__)
#define CM9_P1(x) CM9__1 x
#define CM9_P2(x) CM9__2 x
#define CM9_P3(x) CM9__3 x
#define CM9_P4(x) CM9__4 x
#define CM9_P5(x) CM9__5 x
#define CM9_P6(x) CM9__6 x
#define CM9_P7(x) CM9__7 x
#define CM9_P8(x) CM9__8 x
#define CM9_P9(x) CM9__9 x
#define CM9_Pa(x) CM9__a x
#define CM9_Pb(x) CM9__b x
#define CM9_Pc(x) CM9__c x
#define CM9_Pd(x) CM9__d x
#define CM9_Pe(x) CM9__e x
#define CM9_Pf(x) CM9__f x

#define CMa__0(P,f,...) CMa_P1(CMa_P1(CMa_P1(CMa_P1(CMa_P1(CM_##f(,P##__VA_ARGS__))))))
#define CMa__1(P,f,...) CMa_P2(CMa_P2(CMa_P2(CMa_P2(CMa_P2(CM_##f(,P##__VA_ARGS__))))))
#define CMa__2(P,f,...) CMa_P3(CMa_P3(CMa_P3(CMa_P3(CMa_P3(CM_##f(,P##__VA_ARGS__))))))
#define CMa__3(P,f,...) CMa_P4(CMa_P4(CMa_P4(CMa_P4(CMa_P4(CM_##f(,P##__VA_ARGS__))))))
#define CMa__4(P,f,...) CMa_P5(CMa_P5(CMa_P5(CMa_P5(CMa_P5(CM_##f(,P##__VA_ARGS__))))))
#define CMa__5(P,f,...) CMa_P6(CMa_P6(CMa_P6(CMa_P6(CMa_P6(CM_##f(,P##__VA_ARGS__))))))
#define CMa__6(P,f,...) CMa_P7(CMa_P7(CMa_P7(CMa_P7(CMa_P7(CM_##f(,P##__VA_ARGS__))))))
#define CMa__7(P,f,...) CMa_P8(CMa_P8(CMa_P8(CMa_P8(CMa_P8(CM_##f(,P##__VA_ARGS__))))))
#define CMa__8(P,f,...) CMa_P9(CMa_P9(CMa_P9(CMa_P9(CMa_P9(CM_##f(,P##__VA_ARGS__))))))
#define CMa__9(P,f,...) CMa_Pa(CMa_Pa(CMa_Pa(CMa_Pa(CMa_Pa(CM_##f(,P##__VA_ARGS__))))))
#define CMa__a(P,f,...) CMa_Pb(CMa_Pb(CMa_Pb(CMa_Pb(CMa_Pb(CM_##f(,P##__VA_ARGS__))))))
#define CMa__b(P,f,...) CMa_Pc(CMa_Pc(CMa_Pc(CMa_Pc(CMa_Pc(CM_##f(,P##__VA_ARGS__))))))
#define CMa__c(P,f,...) CMa_Pd(CMa_Pd(CMa_Pd(CMa_Pd(CMa_Pd(CM_##f(,P##__VA_ARGS__))))))
#define CMa__d(P,f,...) CMa_Pe(CMa_Pe(CMa_Pe(CMa_Pe(CMa_Pe(CM_##f(,P##__VA_ARGS__))))))
#define CMa__e(P,f,...) CMa_Pf(CMa_Pf(CMa_Pf(CMa_Pf(CMa_Pf(CM_##f(,P##__VA_ARGS__))))))
#define CMa__f(P,f,...) CM_##f(,P##__VA_ARGS__)
#define CMa_P1(x) CMa__1 x
#define CMa_P2(x) CMa__2 x
#define CMa_P3(x) CMa__3 x
#define CMa_P4(x) CMa__4 x
#define CMa_P5(x) CMa__5 x
#define CMa_P6(x) CMa__6 x
#define CMa_P7(x) CMa__7 x
#define CMa_P8(x) CMa__8 x
#define CMa_P9(x) CMa__9 x
#define CMa_Pa(x) CMa__a x
#define CMa_Pb(x) CMa__b x
#define CMa_Pc(x) CMa__c x
#define CMa_Pd(x) CMa__d x
#define CMa_Pe(x) CMa__e x
#define CMa_Pf(x) CMa__f x

#define CMb__0(P,f,...) CMb_P1(CMb_P1(CMb_P1(CMb_P1(CMb_P1(CM_##f(,P##__VA_ARGS__))))))
#define CMb__1(P,f,...) CMb_P2(CMb_P2(CMb_P2(CMb_P2(CMb_P2(CM_##f(,P##__VA_ARGS__))))))
#define CMb__2(P,f,...) CMb_P3(CMb_P3(CMb_P3(CMb_P3(CMb_P3(CM_##f(,P##__VA_ARGS__))))))
#define CMb__3(P,f,...) CMb_P4(CMb_P4(CMb_P4(CMb_P4(CMb_P4(CM_##f(,P##__VA_ARGS__))))))
#define CMb__4(P,f,...) CMb_P5(CMb_P5(CMb_P5(CMb_P5(CMb_P5(CM_##f(,P##__VA_ARGS__))))))
#define CMb__5(P,f,...) CMb_P6(CMb_P6(CMb_P6(CMb_P6(CMb_P6(CM_##f(,P##__VA_ARGS__))))))
#define CMb__6(P,f,...) CMb_P7(CMb_P7(CMb_P7(CMb_P7(CMb_P7(CM_##f(,P##__VA_ARGS__))))))
#define CMb__7(P,f,...) CMb_P8(CMb_P8(CMb_P8(CMb_P8(CMb_P8(CM_##f(,P##__VA_ARGS__))))))
#define CMb__8(P,f,...) CMb_P9(CMb_P9(CMb_P9(CMb_P9(CMb_P9(CM_##f(,P##__VA_ARGS__))))))
#define CMb__9(P,f,...) CMb_Pa(CMb_Pa(CMb_Pa(CMb_Pa(CMb_Pa(CM_##f(,P##__VA_ARGS__))))))
#define CMb__a(P,f,...) CMb_Pb(CMb_Pb(CMb_Pb(CMb_Pb(CMb_Pb(CM_##f(,P##__VA_ARGS__))))))
#define CMb__b(P,f,...) CMb_Pc(CMb_Pc(CMb_Pc(CMb_Pc(CMb_Pc(CM_##f(,P##__VA_ARGS__))))))
#define CMb__c(P,f,...) CMb_Pd(CMb_Pd(CMb_Pd(CMb_Pd(CMb_Pd(CM_##f(,P##__VA_ARGS__))))))
#define CMb__d(P,f,...) CMb_Pe(CMb_Pe(CMb_Pe(CMb_Pe(CMb_Pe(CM_##f(,P##__VA_ARGS__))))))
#define CMb__e(P,f,...) CMb_Pf(CMb_Pf(CMb_Pf(CMb_Pf(CMb_Pf(CM_##f(,P##__VA_ARGS__))))))
#define CMb__f(P,f,...) CM_##f(,P##__VA_ARGS__)
#define CMb_P1(x) CMb__1 x
#define CMb_P2(x) CMb__2 x
#define CMb_P3(x) CMb__3 x
#define CMb_P4(x) CMb__4 x
#define CMb_P5(x) CMb__5 x
#define CMb_P6(x) CMb__6 x
#define CMb_P7(x) CMb__7 x
#define CMb_P8(x) CMb__8 x
#define CMb_P9(x) CMb__9 x
#define CMb_Pa(x) CMb__a x
#define CMb_Pb(x) CMb__b x
#define CMb_Pc(x) CMb__c x
#define CMb_Pd(x) CMb__d x
#define CMb_Pe(x) CMb__e x
#define CMb_Pf(x) CMb__f x

#define CMc__0(P,f,...) CMc_P1(CMc_P1(CMc_P1(CMc_P1(CMc_P1(CM_##f(,P##__VA_ARGS__))))))
#define CMc__1(P,f,...) CMc_P2(CMc_P2(CMc_P2(CMc_P2(CMc_P2(CM_##f(,P##__VA_ARGS__))))))
#define CMc__2(P,f,...) CMc_P3(CMc_P3(CMc_P3(CMc_P3(CMc_P3(CM_##f(,P##__VA_ARGS__))))))
#define CMc__3(P,f,...) CMc_P4(CMc_P4(CMc_P4(CMc_P4(CMc_P4(CM_##f(,P##__VA_ARGS__))))))
#define CMc__4(P,f,...) CMc_P5(CMc_P5(CMc_P5(CMc_P5(CMc_P5(CM_##f(,P##__VA_ARGS__))))))
#define CMc__5(P,f,...) CMc_P6(CMc_P6(CMc_P6(CMc_P6(CMc_P6(CM_##f(,P##__VA_ARGS__))))))
#define CMc__6(P,f,...) CMc_P7(CMc_P7(CMc_P7(CMc_P7(CMc_P7(CM_##f(,P##__VA_ARGS__))))))
#define CMc__7(P,f,...) CMc_P8(CMc_P8(CMc_P8(CMc_P8(CMc_P8(CM_##f(,P##__VA_ARGS__))))))
#define CMc__8(P,f,...) CMc_P9(CMc_P9(CMc_P9(CMc_P9(CMc_P9(CM_##f(,P##__VA_ARGS__))))))
#define CMc__9(P,f,...) CMc_Pa(CMc_Pa(CMc_Pa(CMc_Pa(CMc_Pa(CM_##f(,P##__VA_ARGS__))))))
#define CMc__a(P,f,...) CMc_Pb(CMc_Pb(CMc_Pb(CMc_Pb(CMc_Pb(CM_##f(,P##__VA_ARGS__))))))
#define CMc__b(P,f,...) CMc_Pc(CMc_Pc(CMc_Pc(CMc_Pc(CMc_Pc(CM_##f(,P##__VA_ARGS__))))))
#define CMc__c(P,f,...) CMc_Pd(CMc_Pd(CMc_Pd(CMc_Pd(CMc_Pd(CM_##f(,P##__VA_ARGS__))))))
#define CMc__d(P,f,...) CMc_Pe(CMc_Pe(CMc_Pe(CMc_Pe(CMc_Pe(CM_##f(,P##__VA_ARGS__))))))
#define CMc__e(P,f,...) CMc_Pf(CMc_Pf(CMc_Pf(CMc_Pf(CMc_Pf(CM_##f(,P##__VA_ARGS__))))))
#define CMc__f(P,f,...) CM_##f(,P##__VA_ARGS__)
#define CMc_P1(x) CMc__1 x
#define CMc_P2(x) CMc__2 x
#define CMc_P3(x) CMc__3 x
#define CMc_P4(x) CMc__4 x
#define CMc_P5(x) CMc__5 x
#define CMc_P6(x) CMc__6 x
#define CMc_P7(x) CMc__7 x
#define CMc_P8(x) CMc__8 x
#define CMc_P9(x) CMc__9 x
#define CMc_Pa(x) CMc__a x
#define CMc_Pb(x) CMc__b x
#define CMc_Pc(x) CMc__c x
#define CMc_Pd(x) CMc__d x
#define CMc_Pe(x) CMc__e x
#define CMc_Pf(x) CMc__f x

#define CMd__0(P,f,...) CMd_P1(CMd_P1(CMd_P1(CMd_P1(CMd_P1(CM_##f(,P##__VA_ARGS__))))))
#define CMd__1(P,f,...) CMd_P2(CMd_P2(CMd_P2(CMd_P2(CMd_P2(CM_##f(,P##__VA_ARGS__))))))
#define CMd__2(P,f,...) CMd_P3(CMd_P3(CMd_P3(CMd_P3(CMd_P3(CM_##f(,P##__VA_ARGS__))))))
#define CMd__3(P,f,...) CMd_P4(CMd_P4(CMd_P4(CMd_P4(CMd_P4(CM_##f(,P##__VA_ARGS__))))))
#define CMd__4(P,f,...) CMd_P5(CMd_P5(CMd_P5(CMd_P5(CMd_P5(CM_##f(,P##__VA_ARGS__))))))
#define CMd__5(P,f,...) CMd_P6(CMd_P6(CMd_P6(CMd_P6(CMd_P6(CM_##f(,P##__VA_ARGS__))))))
#define CMd__6(P,f,...) CMd_P7(CMd_P7(CMd_P7(CMd_P7(CMd_P7(CM_##f(,P##__VA_ARGS__))))))
#define CMd__7(P,f,...) CMd_P8(CMd_P8(CMd_P8(CMd_P8(CMd_P8(CM_##f(,P##__VA_ARGS__))))))
#define CMd__8(P,f,...) CMd_P9(CMd_P9(CMd_P9(CMd_P9(CMd_P9(CM_##f(,P##__VA_ARGS__))))))
#define CMd__9(P,f,...) CMd_Pa(CMd_Pa(CMd_Pa(CMd_Pa(CMd_Pa(CM_##f(,P##__VA_ARGS__))))))
#define CMd__a(P,f,...) CMd_Pb(CMd_Pb(CMd_Pb(CMd_Pb(CMd_Pb(CM_##f(,P##__VA_ARGS__))))))
#define CMd__b(P,f,...) CMd_Pc(CMd_Pc(CMd_Pc(CMd_Pc(CMd_Pc(CM_##f(,P##__VA_ARGS__))))))
#define CMd__c(P,f,...) CMd_Pd(CMd_Pd(CMd_Pd(CMd_Pd(CMd_Pd(CM_##f(,P##__VA_ARGS__))))))
#define CMd__d(P,f,...) CMd_Pe(CMd_Pe(CMd_Pe(CMd_Pe(CMd_Pe(CM_##f(,P##__VA_ARGS__))))))
#define CMd__e(P,f,...) CMd_Pf(CMd_Pf(CMd_Pf(CMd_Pf(CMd_Pf(CM_##f(,P##__VA_ARGS__))))))
#define CMd__f(P,f,...) CM_##f(,P##__VA_ARGS__)
#define CMd_P1(x) CMd__1 x
#define CMd_P2(x) CMd__2 x
#define CMd_P3(x) CMd__3 x
#define CMd_P4(x) CMd__4 x
#define CMd_P5(x) CMd__5 x
#define CMd_P6(x) CMd__6 x
#define CMd_P7(x) CMd__7 x
#define CMd_P8(x) CMd__8 x
#define CMd_P9(x) CMd__9 x
#define CMd_Pa(x) CMd__a x
#define CMd_Pb(x) CMd__b x
#define CMd_Pc(x) CMd__c x
#define CMd_Pd(x) CMd__d x
#define CMd_Pe(x) CMd__e x
#define CMd_Pf(x) CMd__f x

#define CMe__0(P,f,...) CMe_P1(CMe_P1(CMe_P1(CMe_P1(CMe_P1(CM_##f(,P##__VA_ARGS__))))))
#define CMe__1(P,f,...) CMe_P2(CMe_P2(CMe_P2(CMe_P2(CMe_P2(CM_##f(,P##__VA_ARGS__))))))
#define CMe__2(P,f,...) CMe_P3(CMe_P3(CMe_P3(CMe_P3(CMe_P3(CM_##f(,P##__VA_ARGS__))))))
#define CMe__3(P,f,...) CMe_P4(CMe_P4(CMe_P4(CMe_P4(CMe_P4(CM_##f(,P##__VA_ARGS__))))))
#define CMe__4(P,f,...) CMe_P5(CMe_P5(CMe_P5(CMe_P5(CMe_P5(CM_##f(,P##__VA_ARGS__))))))
#define CMe__5(P,f,...) CMe_P6(CMe_P6(CMe_P6(CMe_P6(CMe_P6(CM_##f(,P##__VA_ARGS__))))))
#define CMe__6(P,f,...) CMe_P7(CMe_P7(CMe_P7(CMe_P7(CMe_P7(CM_##f(,P##__VA_ARGS__))))))
#define CMe__7(P,f,...) CMe_P8(CMe_P8(CMe_P8(CMe_P8(CMe_P8(CM_##f(,P##__VA_ARGS__))))))
#define CMe__8(P,f,...) CMe_P9(CMe_P9(CMe_P9(CMe_P9(CMe_P9(CM_##f(,P##__VA_ARGS__))))))
#define CMe__9(P,f,...) CMe_Pa(CMe_Pa(CMe_Pa(CMe_Pa(CMe_Pa(CM_##f(,P##__VA_ARGS__))))))
#define CMe__a(P,f,...) CMe_Pb(CMe_Pb(CMe_Pb(CMe_Pb(CMe_Pb(CM_##f(,P##__VA_ARGS__))))))
#define CMe__b(P,f,...) CMe_Pc(CMe_Pc(CMe_Pc(CMe_Pc(CMe_Pc(CM_##f(,P##__VA_ARGS__))))))
#define CMe__c(P,f,...) CMe_Pd(CMe_Pd(CMe_Pd(CMe_Pd(CMe_Pd(CM_##f(,P##__VA_ARGS__))))))
#define CMe__d(P,f,...) CMe_Pe(CMe_Pe(CMe_Pe(CMe_Pe(CMe_Pe(CM_##f(,P##__VA_ARGS__))))))
#define CMe__e(P,f,...) CMe_Pf(CMe_Pf(CMe_Pf(CMe_Pf(CMe_Pf(CM_##f(,P##__VA_ARGS__))))))
#define CMe__f(P,f,...) CM_##f(,P##__VA_ARGS__)
#define CMe_P1(x) CMe__1 x
#define CMe_P2(x) CMe__2 x
#define CMe_P3(x) CMe__3 x
#define CMe_P4(x) CMe__4 x
#define CMe_P5(x) CMe__5 x
#define CMe_P6(x) CMe__6 x
#define CMe_P7(x) CMe__7 x
#define CMe_P8(x) CMe__8 x
#define CMe_P9(x) CMe__9 x
#define CMe_Pa(x) CMe__a x
#define CMe_Pb(x) CMe__b x
#define CMe_Pc(x) CMe__c x
#define CMe_Pd(x) CMe__d x
#define CMe_Pe(x) CMe__e x
#define CMe_Pf(x) CMe__f x

#define CMf__0(P,f,...) CMf_P1(CMf_P1(CMf_P1(CMf_P1(CMf_P1(CM_##f(,P##__VA_ARGS__))))))
#define CMf__1(P,f,...) CMf_P2(CMf_P2(CMf_P2(CMf_P2(CMf_P2(CM_##f(,P##__VA_ARGS__))))))
#define CMf__2(P,f,...) CMf_P3(CMf_P3(CMf_P3(CMf_P3(CMf_P3(CM_##f(,P##__VA_ARGS__))))))
#define CMf__3(P,f,...) CMf_P4(CMf_P4(CMf_P4(CMf_P4(CMf_P4(CM_##f(,P##__VA_ARGS__))))))
#define CMf__4(P,f,...) CMf_P5(CMf_P5(CMf_P5(CMf_P5(CMf_P5(CM_##f(,P##__VA_ARGS__))))))
#define CMf__5(P,f,...) CMf_P6(CMf_P6(CMf_P6(CMf_P6(CMf_P6(CM_##f(,P##__VA_ARGS__))))))
#define CMf__6(P,f,...) CMf_P7(CMf_P7(CMf_P7(CMf_P7(CMf_P7(CM_##f(,P##__VA_ARGS__))))))
#define CMf__7(P,f,...) CMf_P8(CMf_P8(CMf_P8(CMf_P8(CMf_P8(CM_##f(,P##__VA_ARGS__))))))
#define CMf__8(P,f,...) CMf_P9(CMf_P9(CMf_P9(CMf_P9(CMf_P9(CM_##f(,P##__VA_ARGS__))))))
#define CMf__9(P,f,...) CMf_Pa(CMf_Pa(CMf_Pa(CMf_Pa(CMf_Pa(CM_##f(,P##__VA_ARGS__))))))
#define CMf__a(P,f,...) CMf_Pb(CMf_Pb(CMf_Pb(CMf_Pb(CMf_Pb(CM_##f(,P##__VA_ARGS__))))))
#define CMf__b(P,f,...) CMf_Pc(CMf_Pc(CMf_Pc(CMf_Pc(CMf_Pc(CM_##f(,P##__VA_ARGS__))))))
#define CMf__c(P,f,...) CMf_Pd(CMf_Pd(CMf_Pd(CMf_Pd(CMf_Pd(CM_##f(,P##__VA_ARGS__))))))
#define CMf__d(P,f,...) CMf_Pe(CMf_Pe(CMf_Pe(CMf_Pe(CMf_Pe(CM_##f(,P##__VA_ARGS__))))))
#define CMf__e(P,f,...) CMf_Pf(CMf_Pf(CMf_Pf(CMf_Pf(CMf_Pf(CM_##f(,P##__VA_ARGS__))))))
#define CMf__f(P,f,...) CM_##f(,P##__VA_ARGS__)
#define CMf_P1(x) CMf__1 x
#define CMf_P2(x) CMf__2 x
#define CMf_P3(x) CMf__3 x
#define CMf_P4(x) CMf__4 x
#define CMf_P5(x) CMf__5 x
#define CMf_P6(x) CMf__6 x
#define CMf_P7(x) CMf__7 x
#define CMf_P8(x) CMf__8 x
#define CMf_P9(x) CMf__9 x
#define CMf_Pa(x) CMf__a x
#define CMf_Pb(x) CMf__b x
#define CMf_Pc(x) CMf__c x
#define CMf_Pd(x) CMf__d x
#define CMf_Pe(x) CMf__e x
#define CMf_Pf(x) CMf__f x

