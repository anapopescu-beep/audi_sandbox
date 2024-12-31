#include "__cf_eCS_Algo_Simulation_2015b_opti.h"
#if 0
This file is not available for use in any application other than as a MATLAB
( R ) MEX file for use with the Simulink ( R ) product . If you do not have
the Simulink Coder licensed , this file contains encrypted block names , etc
. If you purchase the Simulink Coder , this file will contain full block
descriptions and improved variable names .
#endif
#include <math.h>
#include "eCS_Algo_Simulation_2015b_opti_acc.h"
#include "eCS_Algo_Simulation_2015b_opti_acc_private.h"
#include <stdio.h>
#include "slexec_vm_simstruct_bridge.h"
#include "slexec_vm_zc_functions.h"
#include "simstruc.h"
#include "fixedpoint.h"
#define CodeFormat S-Function
#define AccDefine1 Accelerator_S-Function
#include "simtarget/slAccSfcnBridge.h"
void eCS_Algo_Simulation_2015b_opti_acc_BINARYSEARCH_real_T ( uint32_T *
piLeft , uint32_T * piRght , real_T u , const real_T * pData , uint32_T iHi )
{ * piLeft = 0U ; * piRght = iHi ; if ( u <= pData [ 0 ] ) { * piRght = 0U ;
} else if ( u >= pData [ iHi ] ) { * piLeft = iHi ; } else { uint32_T i ;
while ( ( * piRght - * piLeft ) > 1U ) { i = ( * piLeft + * piRght ) >> 1 ;
if ( u < pData [ i ] ) { * piRght = i ; } else { * piLeft = i ; } } } } void
eCS_Algo_Simulation_2015b_opti_acc_LookUp_real_T_real_T ( real_T * pY , const
real_T * pYData , real_T u , const real_T * pUData , uint32_T iHi ) {
uint32_T iLeft ; uint32_T iRght ;
eCS_Algo_Simulation_2015b_opti_acc_BINARYSEARCH_real_T ( & ( iLeft ) , & (
iRght ) , u , pUData , iHi ) ; { real_T lambda ; if ( pUData [ iRght ] >
pUData [ iLeft ] ) { real_T num ; real_T den ; den = pUData [ iRght ] ; den
-= pUData [ iLeft ] ; num = u ; num -= pUData [ iLeft ] ; lambda = num / den
; } else { lambda = 0.0 ; } { real_T yLeftCast ; real_T yRghtCast ; yLeftCast
= pYData [ iLeft ] ; yRghtCast = pYData [ iRght ] ; yLeftCast += lambda * (
yRghtCast - yLeftCast ) ; ( * pY ) = yLeftCast ; } } } real_T look1_binlxpw (
real_T u0 , const real_T bp0 [ ] , const real_T table [ ] , uint32_T maxIndex
) { real_T frac ; uint32_T iRght ; uint32_T iLeft ; uint32_T bpIdx ; if ( u0
<= bp0 [ 0U ] ) { iLeft = 0U ; frac = ( u0 - bp0 [ 0U ] ) / ( bp0 [ 1U ] -
bp0 [ 0U ] ) ; } else if ( u0 < bp0 [ maxIndex ] ) { bpIdx = maxIndex >> 1U ;
iLeft = 0U ; iRght = maxIndex ; while ( iRght - iLeft > 1U ) { if ( u0 < bp0
[ bpIdx ] ) { iRght = bpIdx ; } else { iLeft = bpIdx ; } bpIdx = ( iRght +
iLeft ) >> 1U ; } frac = ( u0 - bp0 [ iLeft ] ) / ( bp0 [ iLeft + 1U ] - bp0
[ iLeft ] ) ; } else { iLeft = maxIndex - 1U ; frac = ( u0 - bp0 [ maxIndex -
1U ] ) / ( bp0 [ maxIndex ] - bp0 [ maxIndex - 1U ] ) ; } return ( table [
iLeft + 1U ] - table [ iLeft ] ) * frac + table [ iLeft ] ; } real_T
look1_binlcapw ( real_T u0 , const real_T bp0 [ ] , const real_T table [ ] ,
uint32_T maxIndex ) { real_T y ; real_T frac ; uint32_T iRght ; uint32_T
iLeft ; uint32_T bpIdx ; if ( u0 <= bp0 [ 0U ] ) { iLeft = 0U ; frac = 0.0 ;
} else if ( u0 < bp0 [ maxIndex ] ) { bpIdx = maxIndex >> 1U ; iLeft = 0U ;
iRght = maxIndex ; while ( iRght - iLeft > 1U ) { if ( u0 < bp0 [ bpIdx ] ) {
iRght = bpIdx ; } else { iLeft = bpIdx ; } bpIdx = ( iRght + iLeft ) >> 1U ;
} frac = ( u0 - bp0 [ iLeft ] ) / ( bp0 [ iLeft + 1U ] - bp0 [ iLeft ] ) ; }
else { iLeft = maxIndex ; frac = 0.0 ; } if ( iLeft == maxIndex ) { y = table
[ iLeft ] ; } else { y = ( table [ iLeft + 1U ] - table [ iLeft ] ) * frac +
table [ iLeft ] ; } return y ; } real_T look1_linlcapw ( real_T u0 , const
real_T bp0 [ ] , const real_T table [ ] , uint32_T maxIndex ) { real_T y ;
real_T frac ; uint32_T bpIdx ; if ( u0 <= bp0 [ 0U ] ) { bpIdx = 0U ; frac =
0.0 ; } else if ( u0 < bp0 [ maxIndex ] ) { for ( bpIdx = maxIndex >> 1U ; u0
< bp0 [ bpIdx ] ; bpIdx -- ) { } while ( u0 >= bp0 [ bpIdx + 1U ] ) { bpIdx
++ ; } frac = ( u0 - bp0 [ bpIdx ] ) / ( bp0 [ bpIdx + 1U ] - bp0 [ bpIdx ] )
; } else { bpIdx = maxIndex ; frac = 0.0 ; } if ( bpIdx == maxIndex ) { y =
table [ bpIdx ] ; } else { y = ( table [ bpIdx + 1U ] - table [ bpIdx ] ) *
frac + table [ bpIdx ] ; } return y ; } real_T look1_linlcpw ( real_T u0 ,
const real_T bp0 [ ] , const real_T table [ ] , uint32_T maxIndex ) { real_T
frac ; uint32_T bpIdx ; if ( u0 <= bp0 [ 0U ] ) { bpIdx = 0U ; frac = 0.0 ; }
else if ( u0 < bp0 [ maxIndex ] ) { for ( bpIdx = maxIndex >> 1U ; u0 < bp0 [
bpIdx ] ; bpIdx -- ) { } while ( u0 >= bp0 [ bpIdx + 1U ] ) { bpIdx ++ ; }
frac = ( u0 - bp0 [ bpIdx ] ) / ( bp0 [ bpIdx + 1U ] - bp0 [ bpIdx ] ) ; }
else { bpIdx = maxIndex - 1U ; frac = 1.0 ; } return ( table [ bpIdx + 1U ] -
table [ bpIdx ] ) * frac + table [ bpIdx ] ; } void pk4vnz4nca ( int8_T
pfqpzykylo , kneg2qbwoq * localB , o10tugwmnc * localP ) { localB ->
odrdy00z14 = localP -> P_0 ; localB -> o4ujby5tcp = pfqpzykylo ; } void
boiceho5kq ( SimStruct * const S ) { } real_T rt_urand_Upu32_Yd_f_pw_snf (
uint32_T * u ) { uint32_T lo ; uint32_T hi ; lo = * u % 127773U * 16807U ; hi
= * u / 127773U * 2836U ; if ( lo < hi ) { * u = 2147483647U - ( hi - lo ) ;
} else { * u = lo - hi ; } return ( real_T ) * u * 4.6566128752457969E-10 ; }
real_T rt_nrand_Upu32_Yd_f_pw_snf ( uint32_T * u ) { real_T y ; real_T sr ;
real_T si ; do { sr = 2.0 * rt_urand_Upu32_Yd_f_pw_snf ( u ) - 1.0 ; si = 2.0
* rt_urand_Upu32_Yd_f_pw_snf ( u ) - 1.0 ; si = sr * sr + si * si ; } while (
si > 1.0 ) ; y = muDoubleScalarSqrt ( - 2.0 * muDoubleScalarLog ( si ) / si )
* sr ; return y ; } static void mdlOutputs ( SimStruct * S , int_T tid ) {
int8_T s39_iter ; int32_T i ; uint32_T tmp ; uint8_T tmp_p ; real_T u0 ;
real_T u1 ; real_T u2 ; kwbgjqm1wd * _rtB ; eu5bvmyspd * _rtP ; o42trr3yi2 *
_rtX ; hklldc0mgt * _rtDW ; int32_T exitg1 ; int32_T exitg2 ; _rtDW = ( (
hklldc0mgt * ) ssGetRootDWork ( S ) ) ; _rtX = ( ( o42trr3yi2 * )
ssGetContStates ( S ) ) ; _rtP = ( ( eu5bvmyspd * ) ssGetDefaultParam ( S ) )
; _rtB = ( ( kwbgjqm1wd * ) _ssGetBlockIO ( S ) ) ; if ( ssIsSampleHit ( S ,
1 , tid ) ) { _rtB -> izkkkuksnx = _rtDW -> o2oosfolvi ; } if (
ssIsContinuousTask ( S , tid ) ) { _rtB -> pklb0xrrqm = 0.0 ; _rtB ->
pklb0xrrqm += _rtP -> P_302 [ 0 ] * _rtX -> pipnxjxhab [ 0 ] ; _rtB ->
pklb0xrrqm += _rtP -> P_302 [ 1 ] * _rtX -> pipnxjxhab [ 1 ] ; _rtB ->
kvrw2hryav = 0.0 ; _rtB -> kvrw2hryav += _rtP -> P_304 [ 0 ] * _rtX ->
h5ednakogf [ 0 ] ; _rtB -> kvrw2hryav += _rtP -> P_304 [ 1 ] * _rtX ->
h5ednakogf [ 1 ] ; _rtB -> olux1yeya2 = _rtP -> P_305 * _rtB -> kvrw2hryav ;
_rtB -> c1hniueff5 = 0.0 ; _rtB -> c1hniueff5 += _rtP -> P_307 [ 0 ] * _rtX
-> knglgyqvlm [ 0 ] ; _rtB -> c1hniueff5 += _rtP -> P_307 [ 1 ] * _rtX ->
knglgyqvlm [ 1 ] ; _rtB -> ohvwruzfes = _rtP -> P_308 * _rtB -> c1hniueff5 ;
_rtB -> fijvfjnodk = _rtB -> olux1yeya2 + _rtB -> ohvwruzfes ; _rtB ->
gdcd44d4iu = _rtB -> pklb0xrrqm + _rtB -> fijvfjnodk ; _rtB -> g1cmsdbq4b =
muDoubleScalarSin ( _rtP -> P_311 * ssGetTaskTime ( S , 0 ) + _rtP -> P_312 )
* _rtP -> P_309 + _rtP -> P_310 ; _rtB -> cgpdzq2lwx = _rtP -> P_313 * _rtB
-> g1cmsdbq4b ; _rtB -> hkovea0lav = _rtB -> cgpdzq2lwx * _rtB -> kvfb1yian3
; _rtB -> f1abyiwmdl = ssGetT ( S ) ; _rtB -> a5ljjffxve = ssGetTStart ( S )
; _rtB -> n24h5ecmuv = _rtB -> f1abyiwmdl - _rtB -> a5ljjffxve ; _rtB ->
pldn5vnlay = muDoubleScalarRem ( _rtB -> n24h5ecmuv , _rtB -> oqxijjrg4q ) ;
_rtB -> oalshruksr = look1_binlxpw ( _rtB -> pldn5vnlay , _rtP -> P_321 ,
_rtP -> P_320 , 1U ) ; _rtB -> oqmlemp1lk = _rtB -> oalshruksr ; _rtB ->
fbe0ypuo2v = _rtB -> oqmlemp1lk * _rtB -> pc4dwfdodj ; _rtB -> l23azyywtz = (
_rtB -> hkovea0lav + _rtB -> izkkkuksnx ) + _rtB -> fbe0ypuo2v ; _rtB ->
l041yxyiw1 = _rtP -> P_322 * _rtB -> l23azyywtz ; _rtB -> ljpsbmwf1l = _rtB
-> gdcd44d4iu + _rtB -> l041yxyiw1 ; u0 = _rtB -> ljpsbmwf1l ; u1 = _rtP ->
P_324 ; u2 = _rtP -> P_323 ; if ( u0 > u2 ) { _rtB -> bqlo2oxyl0 = u2 ; }
else if ( u0 < u1 ) { _rtB -> bqlo2oxyl0 = u1 ; } else { _rtB -> bqlo2oxyl0 =
u0 ; } u0 = _rtB -> bqlo2oxyl0 ; _rtB -> cvbw4krkyc = muDoubleScalarRound (
u0 / _rtP -> P_325 ) * _rtP -> P_325 ; if ( ssIsSpecialSampleHit ( S , 3 , 0
, tid ) ) { _rtB -> j2cav4m1bb = _rtB -> cvbw4krkyc ; } } if ( ssIsSampleHit
( S , 3 , tid ) ) { { if ( _rtDW -> lvedgoduja . AQHandles ) { sdiWriteSignal
( _rtDW -> lvedgoduja . AQHandles , ssGetTaskTime ( S , 3 ) , ( void * ) &
_rtB -> j2cav4m1bb ) ; } } } if ( ssIsSampleHit ( S , 1 , tid ) ) { _rtB ->
koiny3s1c4 = _rtDW -> a0xah1mbpy ; } if ( ssIsContinuousTask ( S , tid ) ) {
_rtB -> jfz5ckasuj = _rtP -> P_326 * _rtB -> pklb0xrrqm ; _rtB -> mct0ovi4ah
= _rtP -> P_327 * _rtB -> c1hniueff5 ; _rtB -> jxniunsdyn = _rtB ->
jfz5ckasuj + _rtB -> mct0ovi4ah ; _rtB -> ctzeqnysbf = _rtB -> kvrw2hryav +
_rtB -> jxniunsdyn ; _rtB -> maxsh21n2f = _rtP -> P_328 * _rtB -> g1cmsdbq4b
; _rtB -> gstryeh2sl = _rtB -> maxsh21n2f * _rtB -> kvfb1yian3 ; _rtB ->
hpdgbhrarc = ssGetT ( S ) ; _rtB -> furnnpbqoq = ssGetTStart ( S ) ; _rtB ->
kutj4pkxos = _rtB -> hpdgbhrarc - _rtB -> furnnpbqoq ; _rtB -> bfgw0p2hzs =
muDoubleScalarRem ( _rtB -> kutj4pkxos , _rtB -> he5ly1ypri ) ; _rtB ->
ex2qadjsca = look1_binlxpw ( _rtB -> bfgw0p2hzs , _rtP -> P_334 , _rtP ->
P_333 , 1U ) ; _rtB -> ag0ycqlctc = _rtB -> ex2qadjsca ; _rtB -> bw3w34q20q =
_rtB -> ag0ycqlctc * _rtB -> pc4dwfdodj ; _rtB -> nhxtntjwpc = ( _rtB ->
gstryeh2sl + _rtB -> koiny3s1c4 ) + _rtB -> bw3w34q20q ; _rtB -> n1zx2mflxk =
_rtP -> P_335 * _rtB -> nhxtntjwpc ; _rtB -> njkj3rors1 = _rtB -> ctzeqnysbf
+ _rtB -> n1zx2mflxk ; u0 = _rtB -> njkj3rors1 ; u1 = _rtP -> P_337 ; u2 =
_rtP -> P_336 ; if ( u0 > u2 ) { _rtB -> djyhrsxw3f = u2 ; } else if ( u0 <
u1 ) { _rtB -> djyhrsxw3f = u1 ; } else { _rtB -> djyhrsxw3f = u0 ; } u0 =
_rtB -> djyhrsxw3f ; _rtB -> oyfsiz2ymo = muDoubleScalarRound ( u0 / _rtP ->
P_338 ) * _rtP -> P_338 ; if ( ssIsSpecialSampleHit ( S , 3 , 0 , tid ) ) {
_rtB -> muyui1qnd5 = _rtB -> oyfsiz2ymo ; } } if ( ssIsSampleHit ( S , 3 ,
tid ) ) { { if ( _rtDW -> dxyq5hzwhk . AQHandles ) { sdiWriteSignal ( _rtDW
-> dxyq5hzwhk . AQHandles , ssGetTaskTime ( S , 3 ) , ( void * ) & _rtB ->
muyui1qnd5 ) ; } } } if ( ssIsSampleHit ( S , 1 , tid ) ) { _rtB ->
nvkqpnglwf = _rtDW -> adi32mgndf ; } if ( ssIsContinuousTask ( S , tid ) ) {
_rtB -> cylk35wsb2 = _rtP -> P_339 * _rtB -> pklb0xrrqm ; _rtB -> ajbiymdkkz
= _rtP -> P_340 * _rtB -> kvrw2hryav ; _rtB -> ndzsdsiil0 = _rtB ->
cylk35wsb2 + _rtB -> ajbiymdkkz ; _rtB -> bnbr4l53l4 = _rtB -> ndzsdsiil0 +
_rtB -> c1hniueff5 ; _rtB -> ejo0kslamy = _rtP -> P_341 * _rtB -> g1cmsdbq4b
; _rtB -> ctp2pw03mc = _rtB -> ejo0kslamy * _rtB -> kvfb1yian3 ; _rtB ->
cbwlisbv1n = ssGetT ( S ) ; _rtB -> pu2jhvqj4f = ssGetTStart ( S ) ; _rtB ->
pvaqsrdar0 = _rtB -> cbwlisbv1n - _rtB -> pu2jhvqj4f ; _rtB -> pw0bfrpppx =
muDoubleScalarRem ( _rtB -> pvaqsrdar0 , _rtB -> aftcl0hub1 ) ; _rtB ->
auibqejzlh = look1_binlxpw ( _rtB -> pw0bfrpppx , _rtP -> P_347 , _rtP ->
P_346 , 1U ) ; _rtB -> mixbfuc3mx = _rtB -> auibqejzlh ; _rtB -> enaystnhhn =
_rtB -> pc4dwfdodj * _rtB -> mixbfuc3mx ; _rtB -> p3jqapd5zc = ( _rtB ->
ctp2pw03mc + _rtB -> nvkqpnglwf ) + _rtB -> enaystnhhn ; _rtB -> e5dg5vw3fb =
_rtP -> P_348 * _rtB -> p3jqapd5zc ; _rtB -> nv1hgzhzpu = _rtB -> bnbr4l53l4
+ _rtB -> e5dg5vw3fb ; u0 = _rtB -> nv1hgzhzpu ; u1 = _rtP -> P_350 ; u2 =
_rtP -> P_349 ; if ( u0 > u2 ) { _rtB -> kisjx2qkzp = u2 ; } else if ( u0 <
u1 ) { _rtB -> kisjx2qkzp = u1 ; } else { _rtB -> kisjx2qkzp = u0 ; } u0 =
_rtB -> kisjx2qkzp ; _rtB -> pvdairikzu = muDoubleScalarRound ( u0 / _rtP ->
P_351 ) * _rtP -> P_351 ; if ( ssIsSpecialSampleHit ( S , 3 , 0 , tid ) ) {
_rtB -> amls4xkog5 = _rtB -> pvdairikzu ; } } if ( ssIsSampleHit ( S , 3 ,
tid ) ) { { if ( _rtDW -> fcuxuwxboa . AQHandles ) { sdiWriteSignal ( _rtDW
-> fcuxuwxboa . AQHandles , ssGetTaskTime ( S , 3 ) , ( void * ) & _rtB ->
amls4xkog5 ) ; } } if ( ! ( _rtDW -> hpimotibv3 != 0 ) ) { _rtDW ->
mqtrqg2aup [ 0 ] = _rtB -> j2cav4m1bb ; _rtDW -> mqtrqg2aup [ 1 ] = _rtB ->
muyui1qnd5 ; } } if ( ssIsSampleHit ( S , 4 , tid ) ) { _rtDW -> hpimotibv3 =
1 ; _rtB -> hrl3usfhrj [ 0 ] = _rtDW -> mqtrqg2aup [ 0 ] ; _rtB -> hrl3usfhrj
[ 1 ] = _rtDW -> mqtrqg2aup [ 1 ] ; _rtDW -> hpimotibv3 = 0 ; _rtB ->
efntnh4mf0 [ 0 ] = _rtP -> P_352 * _rtB -> hrl3usfhrj [ 0 ] ; _rtB ->
nxq2cqyxip [ 0 ] = _rtDW -> of1vslaqgx [ 0 ] ; _rtB -> eop2g1xite [ 0 ] =
_rtP -> P_357 * _rtB -> nxq2cqyxip [ 0 ] ; _rtB -> kr5ohferol [ 0 ] = _rtB ->
efntnh4mf0 [ 0 ] - _rtB -> eop2g1xite [ 0 ] ; _rtB -> givhdtmscd [ 0 ] = _rtP
-> P_358 * _rtB -> kr5ohferol [ 0 ] ; u0 = _rtB -> givhdtmscd [ 0 ] ; u1 =
_rtP -> P_360 ; u2 = _rtP -> P_359 ; if ( u0 > u2 ) { u0 = u2 ; } else { if (
u0 < u1 ) { u0 = u1 ; } } _rtB -> dlnrzb4sfw [ 0 ] = u0 ; _rtB -> efntnh4mf0
[ 1 ] = _rtP -> P_352 * _rtB -> hrl3usfhrj [ 1 ] ; _rtB -> nxq2cqyxip [ 1 ] =
_rtDW -> of1vslaqgx [ 1 ] ; _rtB -> eop2g1xite [ 1 ] = _rtP -> P_357 * _rtB
-> nxq2cqyxip [ 1 ] ; _rtB -> kr5ohferol [ 1 ] = _rtB -> efntnh4mf0 [ 1 ] -
_rtB -> eop2g1xite [ 1 ] ; _rtB -> givhdtmscd [ 1 ] = _rtP -> P_358 * _rtB ->
kr5ohferol [ 1 ] ; u0 = _rtB -> givhdtmscd [ 1 ] ; u1 = _rtP -> P_360 ; u2 =
_rtP -> P_359 ; if ( u0 > u2 ) { u0 = u2 ; } else { if ( u0 < u1 ) { u0 = u1
; } } _rtB -> dlnrzb4sfw [ 1 ] = u0 ; } if ( ssIsSampleHit ( S , 1 , tid ) )
{ if ( ssIsSpecialSampleHit ( S , 6 , 1 , tid ) ) { _rtB -> m2z3dblfze [ 0 ]
= _rtDW -> dmqgarxxse [ 0 ] ; _rtB -> m2z3dblfze [ 1 ] = _rtDW -> dmqgarxxse
[ 1 ] ; _rtB -> m2z3dblfze [ 2 ] = _rtDW -> dmqgarxxse [ 2 ] ; } _rtB ->
g05jfsgujp = _rtDW -> bjv5blal5s ; _rtB -> b5luvxxf1s = _rtP -> P_373 * _rtB
-> g05jfsgujp ; _rtB -> eypptav1zc = _rtP -> P_374 * _rtB -> b5luvxxf1s ; }
if ( ssIsContinuousTask ( S , tid ) ) { _rtB -> jdpste1wbb =
muDoubleScalarSin ( _rtP -> P_364 * ssGetTaskTime ( S , 0 ) + _rtP -> P_365 )
* _rtP -> P_362 + _rtP -> P_363 ; if ( _rtB -> d4v3ru0nxj != 0.0 ) { _rtB ->
cmawczf4bb = _rtB -> jdpste1wbb ; } else { _rtB -> cmawczf4bb = _rtB ->
atd2rker0m ; } _rtB -> g5ertxgp2c = ssGetT ( S ) ; } if ( ssIsSampleHit ( S ,
1 , tid ) ) { _rtB -> kdhetuqrbn = _rtB -> g5ertxgp2c ; switch ( ( int32_T )
_rtB -> nqwy3xmp15 ) { case 1 : _rtB -> baj2g1knsb = _rtB -> bbgpi5suhy ;
break ; case 2 : _rtB -> baj2g1knsb = _rtB -> bbgpi5suhy ; break ; case 3 :
_rtB -> baj2g1knsb = _rtB -> bbgpi5suhy ; break ; case 4 : _rtB -> baj2g1knsb
= _rtB -> bbgpi5suhy ; break ; case 5 : _rtB -> baj2g1knsb = _rtB ->
bbgpi5suhy ; break ; case 6 : _rtB -> baj2g1knsb = _rtB -> bbgpi5suhy ; break
; case 7 : _rtB -> baj2g1knsb = _rtB -> bbgpi5suhy ; break ; case 8 : _rtB ->
baj2g1knsb = _rtB -> bbgpi5suhy ; break ; case 9 : _rtB -> baj2g1knsb = _rtB
-> m2z3dblfze [ 2 ] ; break ; case 10 : _rtB -> baj2g1knsb = _rtB ->
bbgpi5suhy ; break ; case 11 : _rtB -> baj2g1knsb = _rtB -> bbgpi5suhy ;
break ; case 12 : _rtB -> baj2g1knsb = _rtB -> bbgpi5suhy ; break ; case 13 :
_rtB -> baj2g1knsb = _rtB -> bbgpi5suhy ; break ; case 14 : _rtB ->
baj2g1knsb = _rtB -> bbgpi5suhy ; break ; case 15 : _rtB -> baj2g1knsb = _rtB
-> bbgpi5suhy ; break ; case 16 : _rtB -> baj2g1knsb = _rtB -> bbgpi5suhy ;
break ; case 17 : _rtB -> baj2g1knsb = _rtB -> bbgpi5suhy ; break ; case 18 :
_rtB -> baj2g1knsb = _rtB -> bbgpi5suhy ; break ; case 19 : _rtB ->
jqbjggxvfg = muDoubleScalarCos ( _rtB -> eypptav1zc ) ; _rtB -> lb5wnsr3ge =
_rtP -> P_65 * _rtB -> jqbjggxvfg ; _rtB -> baj2g1knsb = _rtB -> lb5wnsr3ge ;
break ; case 20 : _rtB -> baj2g1knsb = _rtB -> bbgpi5suhy ; break ; case 21 :
_rtB -> baj2g1knsb = _rtB -> bbgpi5suhy ; break ; case 22 : _rtB ->
baj2g1knsb = _rtB -> bbgpi5suhy ; break ; case 23 : _rtB -> pkeot5zrxx =
look1_binlcapw ( _rtB -> kdhetuqrbn , _rtP -> P_64 , _rtP -> P_63 , 9U ) ;
_rtB -> baj2g1knsb = _rtB -> pkeot5zrxx ; break ; case 24 : _rtB ->
baj2g1knsb = _rtB -> bbgpi5suhy ; break ; case 25 : _rtB -> dcxkry4f2l =
look1_binlcapw ( _rtB -> kdhetuqrbn , _rtP -> P_62 , _rtP -> P_61 , 3U ) ;
_rtB -> baj2g1knsb = _rtB -> dcxkry4f2l ; break ; case 26 : _rtB ->
baj2g1knsb = _rtB -> bbgpi5suhy ; break ; case 27 : _rtB -> baj2g1knsb = _rtB
-> bbgpi5suhy ; break ; case 28 : _rtB -> baj2g1knsb = _rtB -> bbgpi5suhy ;
break ; default : _rtB -> baj2g1knsb = _rtB -> bbgpi5suhy ; break ; } _rtB ->
ezjcmmgpco = _rtP -> P_375 * _rtB -> baj2g1knsb ; _rtB -> opxy2vh0le = _rtP
-> P_376 * _rtB -> ezjcmmgpco ; } if ( ssIsContinuousTask ( S , tid ) ) {
_rtB -> aj12lh0tmp = _rtB -> cmawczf4bb + _rtB -> opxy2vh0le ; if (
ssIsSpecialSampleHit ( S , 3 , 0 , tid ) ) { _rtB -> od1j0xylc1 = _rtB ->
aj12lh0tmp ; } } if ( ssIsSampleHit ( S , 3 , tid ) ) { if ( _rtB ->
n2upmvferm > _rtP -> P_377 ) { _rtB -> jl0pynjlq4 = _rtB -> amls4xkog5 ; }
else { _rtB -> jl0pynjlq4 = _rtB -> od1j0xylc1 ; } if ( ! ( _rtDW ->
cr0s4ysym0 != 0 ) ) { _rtDW -> e2osolbci0 = _rtB -> jl0pynjlq4 ; } } if (
ssIsSampleHit ( S , 4 , tid ) ) { _rtDW -> cr0s4ysym0 = 1 ; _rtB ->
klgn2jpxgq = _rtDW -> e2osolbci0 ; _rtDW -> cr0s4ysym0 = 0 ; _rtB ->
mgzf3t4qnf = _rtP -> P_378 * _rtB -> klgn2jpxgq ; u0 = _rtB -> mgzf3t4qnf ;
u1 = _rtP -> P_380 ; u2 = _rtP -> P_379 ; if ( u0 > u2 ) { _rtB -> kaz1z4nb05
= u2 ; } else if ( u0 < u1 ) { _rtB -> kaz1z4nb05 = u1 ; } else { _rtB ->
kaz1z4nb05 = u0 ; } ssCallAccelRunBlock ( S , 104 , 0 , SS_CALL_MDL_OUTPUTS )
; _rtB -> p1qp3j1fxj = _rtDW -> hs4k4kefqd ; ssCallAccelRunBlock ( S , 93 , 1
, SS_CALL_MDL_OUTPUTS ) ; _rtB -> dsv5n42mig = _rtDW -> h4bttuatlh ;
ssCallAccelRunBlock ( S , 93 , 3 , SS_CALL_MDL_OUTPUTS ) ; _rtB -> cngorar52u
= _rtDW -> brjgq21c2d ; ssCallAccelRunBlock ( S , 93 , 5 ,
SS_CALL_MDL_OUTPUTS ) ; _rtB -> msrarsghj5 = muDoubleScalarAtan2 ( _rtB ->
dsv5n42mig , _rtB -> p1qp3j1fxj ) ; _rtB -> k1ufnfeorq = _rtB -> p1qp3j1fxj *
_rtB -> p1qp3j1fxj ; _rtB -> pvwk45fego = _rtB -> dsv5n42mig * _rtB ->
dsv5n42mig ; _rtB -> km1diz3tqy = _rtB -> k1ufnfeorq + _rtB -> pvwk45fego ;
_rtB -> aqn3juwm40 = muDoubleScalarSqrt ( _rtB -> km1diz3tqy ) ; u0 = _rtB ->
aqn3juwm40 ; u1 = _rtP -> P_210 ; u2 = _rtP -> P_209 ; if ( u0 > u2 ) { _rtB
-> nrgisxcrbk = u2 ; } else if ( u0 < u1 ) { _rtB -> nrgisxcrbk = u1 ; } else
{ _rtB -> nrgisxcrbk = u0 ; } _rtB -> a11vuydxav = muDoubleScalarCos ( _rtB
-> msrarsghj5 ) ; _rtB -> oz21rb1dqq = muDoubleScalarSin ( _rtB -> msrarsghj5
) ; _rtB -> ktxxur132q = look1_linlcapw ( _rtB -> nrgisxcrbk , _rtP -> P_232
, _rtP -> P_231 , 2U ) ; ssCallAccelRunBlock ( S , 93 , 8 ,
SS_CALL_MDL_OUTPUTS ) ; if ( _rtB -> nrgisxcrbk >= _rtP -> P_233 ) { _rtDW ->
c3a1r1jj13 = true ; } else { if ( _rtB -> nrgisxcrbk <= _rtP -> P_234 ) {
_rtDW -> c3a1r1jj13 = false ; } } if ( _rtDW -> c3a1r1jj13 ) { _rtB ->
fzm03nsyfv = _rtP -> P_235 ; } else { _rtB -> fzm03nsyfv = _rtP -> P_236 ; }
ssCallAccelRunBlock ( S , 93 , 10 , SS_CALL_MDL_OUTPUTS ) ; if ( _rtB ->
e30shzln4y ) { _rtB -> gsukd3gem1 = muDoubleScalarAtan2 ( _rtB -> dlnrzb4sfw
[ 1 ] , _rtB -> dlnrzb4sfw [ 0 ] ) ; _rtB -> mcminvbzxj = _rtB -> dlnrzb4sfw
[ 0 ] * _rtB -> dlnrzb4sfw [ 0 ] ; _rtB -> ibvksjgijz = _rtB -> dlnrzb4sfw [
1 ] * _rtB -> dlnrzb4sfw [ 1 ] ; _rtB -> gikkkshmpb = _rtB -> mcminvbzxj +
_rtB -> ibvksjgijz ; _rtB -> nwkvxj0sxn = muDoubleScalarSqrt ( _rtB ->
gikkkshmpb ) ; u0 = _rtB -> nwkvxj0sxn ; u1 = _rtP -> P_212 ; u2 = _rtP ->
P_211 ; if ( u0 > u2 ) { _rtB -> i33mseyxj4 = u2 ; } else if ( u0 < u1 ) {
_rtB -> i33mseyxj4 = u1 ; } else { _rtB -> i33mseyxj4 = u0 ; } _rtB ->
mpojok4zuy = look1_linlcpw ( _rtB -> i33mseyxj4 , _rtP -> P_218 , _rtP ->
P_217 , 4U ) ; _rtB -> ia4re5whvo = muDoubleScalarCos ( _rtB -> gsukd3gem1 )
; _rtB -> hacda3kuky = _rtB -> mpojok4zuy * _rtB -> ia4re5whvo ; _rtB ->
hgjzaz24zw = muDoubleScalarSin ( _rtB -> gsukd3gem1 ) ; _rtB -> owfte2zp54 =
_rtB -> mpojok4zuy * _rtB -> hgjzaz24zw ; u0 = _rtB -> hacda3kuky ; u1 = _rtP
-> P_214 ; u2 = _rtP -> P_213 ; if ( u0 > u2 ) { _rtB -> m05lu1yfli = u2 ; }
else if ( u0 < u1 ) { _rtB -> m05lu1yfli = u1 ; } else { _rtB -> m05lu1yfli =
u0 ; } u0 = _rtB -> owfte2zp54 ; u1 = _rtP -> P_216 ; u2 = _rtP -> P_215 ; if
( u0 > u2 ) { _rtB -> g5chtdr2rx = u2 ; } else if ( u0 < u1 ) { _rtB ->
g5chtdr2rx = u1 ; } else { _rtB -> g5chtdr2rx = u0 ; } _rtB -> jrjkzygyfy [ 0
] = _rtB -> m05lu1yfli ; _rtB -> jrjkzygyfy [ 1 ] = _rtB -> g5chtdr2rx ; }
else { _rtB -> jrjkzygyfy [ 0 ] = _rtB -> dlnrzb4sfw [ 0 ] ; _rtB ->
jrjkzygyfy [ 1 ] = _rtB -> dlnrzb4sfw [ 1 ] ; } _rtB -> cejv3te40n = _rtP ->
P_237 * _rtB -> ktxxur132q ; _rtB -> llpuuicddt = look1_linlcapw ( _rtB ->
nrgisxcrbk , _rtP -> P_239 , _rtP -> P_238 , 3U ) ; _rtB -> k2q4gsu3hm = _rtP
-> P_240 * _rtB -> llpuuicddt ; _rtB -> ljc4sdam4h = _rtB -> cejv3te40n +
_rtB -> k2q4gsu3hm ; _rtB -> jlljaenfgn = _rtP -> P_241 * _rtB -> ljc4sdam4h
; _rtB -> aq1cysec55 = muDoubleScalarSin ( _rtB -> jlljaenfgn ) ; _rtB ->
g5eky0mp43 = _rtP -> P_242 * _rtB -> aq1cysec55 ; _rtB -> hpld43bfs5 = _rtB
-> a11vuydxav * _rtB -> g5eky0mp43 ; _rtB -> fxcst3yxa2 = _rtB -> g5eky0mp43
* _rtB -> oz21rb1dqq ; _rtB -> lsmxv45udv = _rtDW -> jvy1xkxywy ; _rtB ->
fq2fhuuxoe [ 0 ] = _rtP -> P_245 * _rtB -> cngorar52u ; _rtB -> fq2fhuuxoe [
1 ] = _rtP -> P_245 * _rtB -> lsmxv45udv ; u0 = _rtB -> fq2fhuuxoe [ 0 ] ; u1
= _rtP -> P_247 ; u2 = _rtP -> P_246 ; if ( u0 > u2 ) { u0 = u2 ; } else { if
( u0 < u1 ) { u0 = u1 ; } } _rtB -> cuk0rirvdv [ 0 ] = u0 ; u0 = _rtB ->
fq2fhuuxoe [ 1 ] ; u1 = _rtP -> P_247 ; u2 = _rtP -> P_246 ; if ( u0 > u2 ) {
u0 = u2 ; } else { if ( u0 < u1 ) { u0 = u1 ; } } _rtB -> cuk0rirvdv [ 1 ] =
u0 ; _rtB -> eyp2codp2y [ 0 ] = ( _rtB -> jrjkzygyfy [ 0 ] - _rtB ->
hpld43bfs5 ) - _rtB -> cuk0rirvdv [ 0 ] ; _rtB -> eyp2codp2y [ 1 ] = ( _rtB
-> jrjkzygyfy [ 1 ] - _rtB -> fxcst3yxa2 ) - _rtB -> cuk0rirvdv [ 1 ] ; _rtB
-> bas4axaxbg = _rtB -> dlnrzb4sfw [ 0 ] * _rtB -> dlnrzb4sfw [ 0 ] ; _rtB ->
oognr4ydwd = _rtB -> dlnrzb4sfw [ 1 ] * _rtB -> dlnrzb4sfw [ 1 ] ; _rtB ->
kxydiremkp = _rtB -> bas4axaxbg + _rtB -> oognr4ydwd ; _rtB -> nk43r5asyx =
muDoubleScalarSqrt ( _rtB -> kxydiremkp ) ; _rtB -> ogt5hnd2dg = _rtDW ->
kqftxyuvoq ; if ( _rtB -> nk43r5asyx >= _rtP -> P_271 ) { _rtB -> hihfa4c4cr
= _rtB -> ogt5hnd2dg + _rtB -> fyozuiawkl ; u0 = _rtB -> hihfa4c4cr ; u1 =
_rtP -> P_249 ; u2 = _rtP -> P_248 ; if ( u0 > u2 ) { _rtB -> ipp2wd5upf = u2
; } else if ( u0 < u1 ) { _rtB -> ipp2wd5upf = u1 ; } else { _rtB ->
ipp2wd5upf = u0 ; } _rtB -> isvwzc1yat = _rtB -> ipp2wd5upf ; } else { _rtB
-> isvwzc1yat = _rtB -> h1cxuvw3g5 ; } _rtB -> g0rzpeetgc = ( _rtB ->
isvwzc1yat >= _rtB -> gmij1el113 ) ; _rtB -> bdtlceyugt = _rtDW -> hxp5z3k4kl
; _rtB -> djqb3klq2z = ( _rtB -> b0kdzju0vw == _rtB -> bdtlceyugt ) ; _rtB ->
j534aclxnx = ( _rtB -> g0rzpeetgc && _rtB -> djqb3klq2z ) ; _rtB ->
aj1sklpaii = _rtDW -> fceqnv3pgr ; if ( _rtB -> j534aclxnx ) { _rtB ->
ajnmumn0h3 = _rtP -> P_252 ; _rtB -> kgkdkqgwdl = _rtP -> P_253 ; srUpdateBC
( _rtDW -> odh1vulukc ) ; } else { _rtB -> dmdrdbpwh3 = ( _rtB -> isvwzc1yat
< _rtB -> miqitlu3dr ) ; _rtB -> ozxui3edtv = ( _rtB -> iknuq4luh4 == _rtB ->
bdtlceyugt ) ; _rtB -> f1vnfkfwab = ( _rtB -> dmdrdbpwh3 && _rtB ->
ozxui3edtv ) ; _rtB -> cnugxvdrzr = ( _rtB -> aj1sklpaii == _rtB ->
aamrtq0qcu ) ; _rtB -> ipgtvu2bxh = ( _rtB -> f1vnfkfwab && _rtB ->
cnugxvdrzr ) ; if ( _rtB -> ipgtvu2bxh ) { _rtB -> kgkdkqgwdl = _rtP -> P_256
; _rtB -> ajnmumn0h3 = _rtB -> aj1sklpaii ; srUpdateBC ( _rtDW -> pidrtwpmwk
) ; } else { if ( _rtB -> aj1sklpaii != 0.0 ) { _rtB -> fxddotau0t = _rtB ->
aj1sklpaii - _rtB -> neklowdj12 ; _rtB -> ajnmumn0h3 = _rtB -> fxddotau0t ; }
else { _rtB -> ajnmumn0h3 = _rtB -> dxpfldghjh ; } _rtB -> kgkdkqgwdl = _rtB
-> bdtlceyugt ; srUpdateBC ( _rtDW -> icflnjlwzu ) ; } srUpdateBC ( _rtDW ->
ence3bljtw ) ; } _rtB -> eej4ilo2ke = _rtB -> kgkdkqgwdl ; _rtB -> otqias0ib2
= ( ( _rtB -> fzm03nsyfv != 0.0 ) || ( _rtB -> eej4ilo2ke != 0.0 ) ) ; _rtB
-> nhcv0iqtkd = ( _rtB -> kaz1z4nb05 >= _rtB -> j5bqup4vc4 ) ; _rtB ->
j0jl4dcz4o = _rtDW -> ar15ee0cps ; _rtB -> khcwmz2nn1 = ( _rtB -> j0jl4dcz4o
&& _rtB -> nhcv0iqtkd ) ; _rtB -> hmrtnztp2k = ( _rtB -> khcwmz2nn1 || _rtB
-> otqias0ib2 ) ; _rtB -> hwotst4vji = _rtDW -> b5ng0txcrl ; if ( _rtB ->
hmrtnztp2k ) { _rtB -> j1ffurbqkf = _rtB -> miflwz331z ; } else { _rtB ->
j1ffurbqkf = _rtB -> hwotst4vji ; } _rtB -> ejayuqsvkb = _rtB -> j1ffurbqkf +
_rtB -> h4z4c51szo ; u0 = _rtB -> ejayuqsvkb ; u1 = _rtP -> P_282 ; u2 = _rtP
-> P_281 ; if ( u0 > u2 ) { _rtB -> puktn1stqd = u2 ; } else if ( u0 < u1 ) {
_rtB -> puktn1stqd = u1 ; } else { _rtB -> puktn1stqd = u0 ; }
ssCallAccelRunBlock ( S , 103 , 9 , SS_CALL_MDL_OUTPUTS ) ; _rtB ->
naeyk0bned = ( _rtB -> otqias0ib2 == _rtB -> o4t1nj0euj ) ; _rtB ->
d3kx1umf5d = _rtDW -> ghbdxiadlb ; _rtB -> hxfg5kldme = ( _rtB -> oqqxv3tqha
== _rtB -> d3kx1umf5d ) ; _rtB -> lltxoesoda = ( _rtB -> naeyk0bned && _rtB
-> hxfg5kldme ) ; _rtB -> mqu0padfx4 = _rtDW -> gkkdkyvd0d ; if ( _rtB ->
lltxoesoda ) { _rtB -> ctodit0li2 = ( _rtB -> hwotst4vji < _rtB -> bsw103v254
) ; if ( _rtB -> ctodit0li2 ) { _rtB -> hm1ksap3yt = _rtB -> g1pmkupdj0 ; }
else { _rtB -> hm1ksap3yt = _rtB -> iiwgtu23rp ; } _rtB -> chjhq0wzkk = _rtB
-> hm1ksap3yt ; } else { _rtB -> chjhq0wzkk = _rtB -> mqu0padfx4 ; }
ssCallAccelRunBlock ( S , 103 , 22 , SS_CALL_MDL_OUTPUTS ) ; _rtB ->
dja1tvnqzx = ( _rtB -> puktn1stqd < _rtB -> chjhq0wzkk ) ; if ( _rtB ->
dja1tvnqzx ) { _rtB -> a1thbc4edf = _rtB -> nohjwwgvtw ; } else { _rtB ->
a1thbc4edf = _rtB -> ebobnvfigw ; } _rtB -> m32zrjlim4 = ( _rtB -> a1thbc4edf
!= 0.0 ) ; _rtB -> c0exzvmegw = ( _rtB -> m32zrjlim4 || _rtB -> nozng0ink0 )
; _rtB -> d50nyhtpfe = _rtP -> P_295 * _rtB -> nrgisxcrbk ; _rtB ->
d1xdtficuc = _rtB -> c0exzvmegw ; } if ( ssIsContinuousTask ( S , tid ) ) {
u0 = ssGetTaskTime ( S , 0 ) ; if ( u0 < _rtP -> P_382 ) { _rtB -> frzcf1k54o
= _rtP -> P_383 ; } else { _rtB -> frzcf1k54o = _rtP -> P_384 ; } _rtB ->
btbk1ntaum = ssGetT ( S ) ; _rtB -> kwlfv1rjdf = _rtB -> btbk1ntaum - _rtB ->
bpwjoxgc2e ; _rtB -> j0qff3w4qp = _rtB -> frzcf1k54o * _rtB -> kwlfv1rjdf ;
_rtB -> eyz4fzaxno = _rtB -> j0qff3w4qp + _rtB -> g1iooey1bc ; if ( ! ( _rtDW
-> hfvby0lwvl != 0 ) ) { _rtDW -> d5w3nz0mn4 = _rtB -> eyz4fzaxno ; } } if (
ssIsSampleHit ( S , 4 , tid ) ) { _rtDW -> hfvby0lwvl = 1 ; _rtB ->
cm3eizn1jf = _rtDW -> d5w3nz0mn4 ; _rtDW -> hfvby0lwvl = 0 ; } if (
ssIsSampleHit ( S , 1 , tid ) && ( ! ( _rtDW -> pde3epnjnn != 0 ) ) ) { _rtDW
-> obh1h0fovt = _rtB -> grqq4ycftm ; } if ( ssIsSampleHit ( S , 4 , tid ) ) {
_rtDW -> pde3epnjnn = 1 ; _rtB -> orinnl1ixq = _rtDW -> obh1h0fovt ; _rtDW ->
pde3epnjnn = 0 ; for ( s39_iter = 0 ; s39_iter < _rtP -> P_514 ; s39_iter ++
) { _rtB -> g5sun202i1 = s39_iter ; if ( _rtB -> nyx2ncbgd0 ) { _rtB ->
amhrupay0y = _rtB -> nmwjw0vfbr ; } else { if ( _rtB -> cm3eizn1jf >= _rtP ->
P_1 ) { u0 = muDoubleScalarFloor ( _rtB -> orinnl1ixq ) ; if (
muDoubleScalarIsNaN ( u0 ) || muDoubleScalarIsInf ( u0 ) ) { u0 = 0.0 ; }
else { u0 = muDoubleScalarRem ( u0 , 256.0 ) ; } _rtB -> phokr55iiw = (
uint8_T ) ( u0 < 0.0 ? ( int32_T ) ( uint8_T ) - ( int8_T ) ( uint8_T ) - u0
: ( int32_T ) ( uint8_T ) u0 ) ; _rtB -> ievpjtq3z4 = ( uint8_T ) _rtB ->
g5sun202i1 ; _rtB -> nuk2m1cuor = ( uint8_T ) ( _rtB -> gxjj3w3gki << _rtB ->
ievpjtq3z4 ) ; _rtB -> nucttafbue = _rtB -> nuk2m1cuor ; _rtB -> js1i3n2gb3 =
_rtB -> nucttafbue & _rtB -> phokr55iiw ; if ( _rtB -> js1i3n2gb3 != 0 ) {
_rtB -> mos1rmbsps = _rtB -> iw04lpj300 ; } else { _rtB -> mos1rmbsps = _rtB
-> mgup1xmw4b ; } _rtB -> drhavenucx = _rtB -> mos1rmbsps ; } else { _rtB ->
drhavenucx = _rtB -> i0epboi5kz ; } _rtB -> amhrupay0y = _rtB -> drhavenucx ;
} if ( s39_iter == 0 ) { for ( i = 0 ; i < 6 ; i ++ ) { _rtB -> g1fxxrhgqq [
i ] = _rtB -> mwnsk1unci [ i ] ; } } _rtB -> g1fxxrhgqq [ _rtB -> g5sun202i1
] = _rtB -> amhrupay0y ; } for ( i = 0 ; i < 6 ; i ++ ) { _rtB -> gvyfwlxbbd
[ i ] = _rtDW -> mjjur2t4vf [ i ] ; } for ( s39_iter = 0 ; s39_iter < _rtP ->
P_515 ; s39_iter ++ ) { _rtB -> cr2cz5inn1 = s39_iter ; _rtB -> dzem4q2ily =
_rtB -> gvyfwlxbbd [ _rtB -> cr2cz5inn1 ] ; _rtB -> moacmv2r1f = _rtB ->
g1fxxrhgqq [ _rtB -> cr2cz5inn1 ] ; u0 = _rtB -> dzem4q2ily ; if ( u0 < 0.0 )
{ u0 = muDoubleScalarCeil ( u0 ) ; } else { u0 = muDoubleScalarFloor ( u0 ) ;
} if ( muDoubleScalarIsNaN ( u0 ) || muDoubleScalarIsInf ( u0 ) ) { u0 = 0.0
; } else { u0 = muDoubleScalarRem ( u0 , 4.294967296E+9 ) ; } switch ( u0 <
0.0 ? - ( int32_T ) ( uint32_T ) - u0 : ( int32_T ) ( uint32_T ) u0 ) { case
0 : if ( _rtB -> d1xdtficuc != 0.0 ) { _rtB -> ewlx33obgm = _rtB ->
havu0xznpa ; } else { _rtB -> ewlx33obgm = _rtB -> mvmfwyvulr ; } _rtDW ->
azbccupuvv = 4 ; break ; case 1 : if ( _rtB -> d1xdtficuc != 0.0 ) { _rtB ->
ewlx33obgm = _rtB -> ffrh2m4oj2 ; } else { if ( _rtB -> jmnp4e4vm0 != 0.0 ) {
_rtB -> hm1r0iyssh = _rtB -> akbbxkdxot ; } else { if ( _rtB -> moacmv2r1f !=
0.0 ) { _rtB -> mv2fiqwk20 = _rtB -> neez4beh0d ; } else { _rtB -> mv2fiqwk20
= _rtB -> akbbxkdxot ; } _rtB -> hm1r0iyssh = _rtB -> mv2fiqwk20 ; } _rtB ->
ewlx33obgm = _rtB -> hm1r0iyssh ; } _rtDW -> ast3ueudg3 = 4 ; break ; case 2
: if ( _rtB -> jmnp4e4vm0 != 0.0 ) { _rtB -> ewlx33obgm = _rtB -> jrzzbgsv2r
; } else { if ( _rtB -> moacmv2r1f != 0.0 ) { _rtB -> moocrq3dbd = _rtB ->
pcpf40zr0z ; } else { _rtB -> moocrq3dbd = _rtB -> jrzzbgsv2r ; } _rtB ->
ewlx33obgm = _rtB -> moocrq3dbd ; } _rtDW -> kpg2pjjtxi = 4 ; break ; default
: _rtB -> ewlx33obgm = _rtP -> P_18 ; _rtDW -> j3dukcsboa = 4 ; break ; } if
( s39_iter == 0 ) { for ( i = 0 ; i < 6 ; i ++ ) { _rtB -> ff31tjeuqy [ i ] =
_rtB -> o10otettee [ i ] ; } } _rtB -> ff31tjeuqy [ _rtB -> cr2cz5inn1 ] =
_rtB -> ewlx33obgm ; } for ( s39_iter = 0 ; s39_iter < _rtP -> P_516 ;
s39_iter ++ ) { _rtB -> et14lcujhr = s39_iter ; _rtB -> c31eoo1fet = _rtB ->
ff31tjeuqy [ _rtB -> et14lcujhr ] ; u0 = _rtB -> c31eoo1fet ; if ( u0 < 0.0 )
{ u0 = muDoubleScalarCeil ( u0 ) ; } else { u0 = muDoubleScalarFloor ( u0 ) ;
} if ( muDoubleScalarIsNaN ( u0 ) || muDoubleScalarIsInf ( u0 ) ) { u0 = 0.0
; } else { u0 = muDoubleScalarRem ( u0 , 4.294967296E+9 ) ; } switch ( u0 <
0.0 ? - ( int32_T ) ( uint32_T ) - u0 : ( int32_T ) ( uint32_T ) u0 ) { case
0 : _rtB -> ceiepuwuq5 = _rtP -> P_20 ; _rtDW -> ehuuf4bicf = 4 ; break ;
case 1 : _rtB -> ceiepuwuq5 = _rtP -> P_21 ; _rtDW -> khvrttihiq = 4 ; break
; case 2 : _rtB -> ceiepuwuq5 = _rtP -> P_22 ; _rtDW -> p3hesdbkxp = 4 ;
break ; default : _rtB -> ceiepuwuq5 = _rtP -> P_23 ; _rtDW -> ixjio2x5nd = 4
; break ; } if ( s39_iter == 0 ) { for ( i = 0 ; i < 6 ; i ++ ) { _rtB ->
l5y1e2gqqa [ i ] = _rtB -> j1poviybxl [ i ] ; } } _rtB -> l5y1e2gqqa [ _rtB
-> et14lcujhr ] = _rtB -> ceiepuwuq5 ; } for ( i = 0 ; i < 6 ; i ++ ) { _rtB
-> fhdlrlvnnr [ i ] = _rtDW -> clanm1vhae [ i ] ; } _rtB -> p3szxpknp4 =
_rtDW -> ddu1of3sto ; ssCallAccelRunBlock ( S , 86 , 1 , SS_CALL_MDL_OUTPUTS
) ; _rtB -> nayimscs34 = _rtDW -> fjqd5wsvmo ; _rtB -> drwj0dtug0 = _rtDW ->
katmfar1ds ; for ( i = 0 ; i < 6 ; i ++ ) { _rtB -> jxf5xcxcpr [ i ] = _rtDW
-> c2nrolbzv5 [ i ] ; _rtB -> ltvm3ohp1n [ i ] = _rtDW -> p2i3jocvl4 [ i ] ;
} _rtB -> lhp0izu5dh = _rtDW -> nkjl1zq3cc ; _rtB -> l5zyvytm2q = _rtDW ->
e1o1uerdtv ; s39_iter = 0 ; do { exitg2 = 0 ; u0 = _rtB -> lcef2awnpx ; if (
u0 < 0.0 ) { u0 = muDoubleScalarCeil ( u0 ) ; } else { u0 =
muDoubleScalarFloor ( u0 ) ; } if ( muDoubleScalarIsNaN ( u0 ) ||
muDoubleScalarIsInf ( u0 ) ) { u0 = 0.0 ; } else { u0 = muDoubleScalarRem (
u0 , 256.0 ) ; } if ( s39_iter < ( u0 < 0.0 ? ( int32_T ) ( int8_T ) - (
int8_T ) ( uint8_T ) - u0 : ( int32_T ) ( int8_T ) ( uint8_T ) u0 ) ) { _rtB
-> lkcusqcmzl = s39_iter ; _rtB -> bg4np5sa4i = _rtDW -> c4pfa4co1w ; if (
_rtB -> lkcusqcmzl != 0 ) { _rtB -> ch5ajtnebu = _rtB -> bg4np5sa4i ; } else
{ _rtB -> ch5ajtnebu = _rtB -> pajyam014w ; } _rtB -> czgwfjbdxz = _rtB ->
l5y1e2gqqa [ _rtB -> lkcusqcmzl ] ; if ( _rtB -> czgwfjbdxz != 0.0 ) { _rtB
-> alnwl1u0lg = _rtB -> ch5ajtnebu ; } else { _rtB -> d4pv3semc1 = ( uint8_T
) ( _rtB -> gm03qzow1w << _rtB -> lkcusqcmzl ) ; _rtB -> alnwl1u0lg = _rtB ->
d4pv3semc1 ; } _rtB -> ems3pw4wrx = _rtB -> ch5ajtnebu | _rtB -> alnwl1u0lg ;
_rtDW -> c4pfa4co1w = _rtB -> ems3pw4wrx ; srUpdateBC ( _rtDW -> ekiqgsav1p )
; s39_iter ++ ; } else { exitg2 = 1 ; } } while ( exitg2 == 0 ) ; if ( _rtB
-> ems3pw4wrx != 0 ) { _rtB -> o0xk4spltu = _rtB -> cgn3bd1q0k ; } else {
_rtB -> o0xk4spltu = _rtB -> lnbdqdazph ; } _rtB -> mls2ho5qt4 = _rtDW ->
jkp1gjxqwf ; _rtB -> hv0mhupbqs = _rtDW -> iqczfp0kxp ; _rtB -> j1hiycjpgb =
( _rtB -> l5lj3ozze0 <= _rtB -> o0xk4spltu ) ; for ( i = 0 ; i < 48 ; i ++ )
{ _rtB -> hnk2tibayv [ i ] = _rtP -> P_532 [ i ] ; } if ( _rtB -> j1hiycjpgb
) { _rtB -> ozagibp3qx = _rtP -> P_519 ; srUpdateBC ( _rtDW -> g22b1rlese ) ;
} else { _rtB -> h2zanmn1xm = ( _rtB -> o0xk4spltu != _rtB -> mls2ho5qt4 ) ;
_rtB -> ifdkkjsxmx = ( _rtB -> nrlr3pbf24 == _rtB -> hv0mhupbqs ) ; if ( _rtB
-> h2zanmn1xm || _rtB -> ifdkkjsxmx ) { _rtB -> c3avo5zl4w = _rtP -> P_523 ;
srUpdateBC ( _rtDW -> jkf0dz0cg5 ) ; } else if ( _rtB -> p3szxpknp4 ) { _rtB
-> c3avo5zl4w = ( uint8_T ) ( ( uint32_T ) _rtB -> drwj0dtug0 + _rtB ->
awanavkxi2 ) ; srUpdateBC ( _rtDW -> oqykfpcecb ) ; } else { _rtB ->
c3avo5zl4w = _rtB -> drwj0dtug0 ; srUpdateBC ( _rtDW -> atdpgg3ayq ) ; } _rtB
-> h2ptmt4cu2 = ( _rtB -> hq0kxxm04o <= _rtB -> c3avo5zl4w ) ; if ( _rtB ->
h2ptmt4cu2 ) { _rtB -> ozagibp3qx = _rtB -> i3vyjuy0sc ; } else { _rtB ->
a1zq5s5kiy = _rtB -> o0xk4spltu * _rtB -> bc3lbnnmx5 ; u0 = ( ( real_T ) _rtB
-> c3avo5zl4w + _rtB -> a1zq5s5kiy ) + _rtB -> doec5i5dn2 ; if ( u0 < 256.0 )
{ if ( u0 >= 0.0 ) { tmp_p = ( uint8_T ) u0 ; } else { tmp_p = 0U ; } } else
if ( u0 >= 256.0 ) { tmp_p = MAX_uint8_T ; } else { tmp_p = 0U ; } _rtB ->
dv0imzncmr = tmp_p ; _rtB -> pe5gvyd4o3 = _rtB -> hnk2tibayv [ _rtB ->
dv0imzncmr ] ; _rtB -> cj55zttl1r = ( _rtB -> pyvld00gfo <= _rtB ->
pe5gvyd4o3 ) ; if ( _rtB -> cj55zttl1r ) { _rtB -> ocv4f00ppe = _rtB ->
i3vyjuy0sc ; } else { _rtB -> ocv4f00ppe = _rtB -> pe5gvyd4o3 ; } _rtB ->
ozagibp3qx = _rtB -> ocv4f00ppe ; } srUpdateBC ( _rtDW -> o4nql2jow2 ) ; }
ssCallAccelRunBlock ( S , 62 , 7 , SS_CALL_MDL_OUTPUTS ) ; if ( _rtB ->
ozagibp3qx >= _rtP -> P_534 ) { _rtB -> kgdexlapo2 = _rtB -> iwql3g5xb5 ; }
else { _rtB -> kgdexlapo2 = _rtB -> c3avo5zl4w ; } u0 = muDoubleScalarFloor (
_rtB -> kgdexlapo2 ) ; if ( muDoubleScalarIsNaN ( u0 ) || muDoubleScalarIsInf
( u0 ) ) { u0 = 0.0 ; } else { u0 = muDoubleScalarRem ( u0 , 256.0 ) ; } _rtB
-> fmnkiyvcwg = ( uint8_T ) ( u0 < 0.0 ? ( int32_T ) ( uint8_T ) - ( int8_T )
( uint8_T ) - u0 : ( int32_T ) ( uint8_T ) u0 ) ; _rtB -> kxht3nbcof = ( _rtB
-> k0ylqmumbz <= _rtB -> ozagibp3qx ) ; ssCallAccelRunBlock ( S , 70 , 2 ,
SS_CALL_MDL_OUTPUTS ) ; if ( _rtB -> kxht3nbcof ) { s39_iter = 0 ; _rtB ->
efx3hutlus = _rtP -> P_99 ; srUpdateBC ( _rtDW -> ftlvvbsstm ) ; } else {
s39_iter = 1 ; memcpy ( & _rtB -> h3sennzuce [ 0 ] , & _rtP -> P_537 [ 0 ] ,
sizeof ( uint8_T ) << 6U ) ; _rtB -> l003tiujjo = _rtP -> P_538 ; _rtB ->
mzkljpvhda = ( uint8_T ) ( ( uint32_T ) _rtB -> ozagibp3qx * _rtB ->
l003tiujjo ) ; _rtB -> bke0icv4cb = _rtP -> P_539 ; _rtB -> md24ovkonb = (
uint8_T ) ( ( uint32_T ) _rtB -> mzkljpvhda + _rtB -> bke0icv4cb ) ; _rtB ->
h2mmyb2ec5 = _rtB -> h3sennzuce [ _rtB -> md24ovkonb ] ; _rtB -> h0fiwratd0 =
_rtB -> h2mmyb2ec5 & _rtP -> P_540 ; _rtB -> k3d2k3p3xp = ( _rtB ->
anwbf2qrap != _rtB -> h0fiwratd0 ) ; _rtB -> f4kr3h1n5u = ( _rtB ->
aoy0bc5vlk != _rtB -> h0fiwratd0 ) ; _rtB -> ifyhgmkhv3 = ( _rtB ->
k3d2k3p3xp && _rtB -> f4kr3h1n5u ) ; ssCallAccelRunBlock ( S , 69 , 12 ,
SS_CALL_MDL_OUTPUTS ) ; _rtB -> botwxxxann = _rtP -> P_541 ; _rtB ->
ekjyagxkdz = ( uint8_T ) ( ( uint32_T ) _rtB -> mzkljpvhda + _rtB ->
botwxxxann ) ; _rtB -> nnsribpao4 = ( _rtB -> j05gb1ytfx <= _rtB ->
ozagibp3qx ) ; _rtB -> nfnlavcp05 = _rtB -> h3sennzuce [ _rtB -> mzkljpvhda ]
; _rtB -> eyf4m41gv1 = _rtB -> nfnlavcp05 ; _rtB -> f5m4dvbz5q = ( uint16_T )
( _rtB -> eyf4m41gv1 << 8 ) ; _rtB -> fm14moiaiv = _rtB -> h3sennzuce [ _rtB
-> ekjyagxkdz ] ; _rtB -> lwlm15kt2z = _rtB -> fm14moiaiv ; _rtB ->
gfqxsecp2b = ( uint16_T ) ( ( uint32_T ) _rtB -> f5m4dvbz5q + _rtB ->
lwlm15kt2z ) ; if ( _rtB -> nnsribpao4 ) { _rtB -> o44btp1bfh = _rtB ->
k4bsolae0q ; } else { _rtB -> flt0jar51e = ( _rtB -> hv3l3zizuh == _rtB ->
gfqxsecp2b ) ; _rtB -> ahqzohpq2c = ( _rtB -> cz2scfzqth == _rtB ->
gfqxsecp2b ) ; _rtB -> bpze1ubspg = ( _rtB -> ahqzohpq2c || _rtB ->
flt0jar51e || _rtB -> ifyhgmkhv3 ) ; if ( _rtB -> bpze1ubspg ) { _rtB ->
oksczwpiji = _rtB -> k4bsolae0q ; } else { _rtB -> emjgdl5fdc = ( _rtB ->
ozagibp3qx != _rtB -> hv0mhupbqs ) ; if ( _rtB -> emjgdl5fdc ) { _rtB ->
dumpxmsxes = _rtB -> d1amjtvt0b ; } else { _rtB -> dumpxmsxes = _rtB ->
luaarzgy4o ; } _rtB -> oksczwpiji = _rtB -> dumpxmsxes ; } _rtB -> o44btp1bfh
= _rtB -> oksczwpiji ; } _rtB -> cco1iqhs0p = ( _rtB -> gbx3xsc1d2 == _rtB ->
o44btp1bfh ) ; _rtB -> epxqsmnki3 = _rtDW -> dduzbp03yu ; _rtB -> orodonfzre
= _rtDW -> p1mcxttdss ; _rtB -> fl0bs0j2mk = _rtDW -> ob3531id3b ; _rtB ->
hieuexynnh = _rtDW -> hjwoxvjp5r ; _rtB -> kilro5pwjt = _rtDW -> epvmybyobi ;
memcpy ( & _rtB -> g4eetkd1da [ 0 ] , & _rtP -> P_536 [ 0 ] , sizeof (
uint8_T ) << 6U ) ; if ( _rtB -> cco1iqhs0p ) { { UInt8 u8in ; Bool bit7 ;
Bool bit6 ; Bool bit5 ; Bool bit4 ; Bool bit3 ; Bool bit2 ; Bool bit1 ; Bool
bit0 ; u8in = SCALE_FP_FX ( UInt8 , _rtB -> h2mmyb2ec5 , 1 , 0 ) ; { bit7 = (
u8in & 0x80 ) >> 7 ; bit6 = ( u8in & 0x40 ) >> 6 ; bit5 = ( u8in & 0x20 ) >>
5 ; bit4 = ( u8in & 0x10 ) >> 4 ; bit3 = ( u8in & 0x08 ) >> 3 ; bit2 = ( u8in
& 0x04 ) >> 2 ; bit1 = ( u8in & 0x02 ) >> 1 ; bit0 = ( u8in & 0x01 ) ; } _rtB
-> agiue31rgp = SCALE_FX_FP ( bit7 , 1 , 0 ) ; _rtB -> ladl220j2f =
SCALE_FX_FP ( bit6 , 1 , 0 ) ; _rtB -> htjfiif0in = SCALE_FX_FP ( bit5 , 1 ,
0 ) ; _rtB -> prklzasnhe = SCALE_FX_FP ( bit4 , 1 , 0 ) ; _rtB -> iwnuczck2a
= SCALE_FX_FP ( bit3 , 1 , 0 ) ; _rtB -> ogtq0h4xc5 = SCALE_FX_FP ( bit2 , 1
, 0 ) ; _rtB -> oer42olrms = SCALE_FX_FP ( bit1 , 1 , 0 ) ; _rtB ->
fzuoroiqin = SCALE_FX_FP ( bit0 , 1 , 0 ) ; } _rtB -> jevv2fm2fd = _rtB ->
agiue31rgp ; _rtB -> mkkf5ndoy5 = _rtP -> P_104 * _rtB -> ogtq0h4xc5 ; _rtB
-> ogvtxlfyr3 = _rtP -> P_105 * _rtB -> oer42olrms ; u0 = muDoubleScalarFloor
( ( _rtB -> mkkf5ndoy5 + _rtB -> ogvtxlfyr3 ) + _rtB -> fzuoroiqin ) ; if (
muDoubleScalarIsNaN ( u0 ) || muDoubleScalarIsInf ( u0 ) ) { u0 = 0.0 ; }
else { u0 = muDoubleScalarRem ( u0 , 256.0 ) ; } _rtB -> pa20br3l13 = (
uint8_T ) ( u0 < 0.0 ? ( int32_T ) ( uint8_T ) - ( int8_T ) ( uint8_T ) - u0
: ( int32_T ) ( uint8_T ) u0 ) ; _rtB -> aa4ijn1jbi = _rtB -> pa20br3l13 ;
_rtB -> ndfizgz3vm = _rtP -> P_535 ; _rtB -> etko445svf = ( uint8_T ) ( (
uint32_T ) _rtB -> mzkljpvhda + _rtB -> ndfizgz3vm ) ; _rtB -> bfb2zcopef =
_rtB -> g4eetkd1da [ _rtB -> etko445svf ] ; _rtB -> kwyot2eh5v = _rtB ->
bfb2zcopef ; _rtB -> pusmjkv13h = _rtB -> gfqxsecp2b ; srUpdateBC ( _rtDW ->
eu4wugx31g ) ; } else { _rtB -> aa4ijn1jbi = _rtB -> epxqsmnki3 ; _rtB ->
kwyot2eh5v = _rtB -> orodonfzre ; _rtB -> pusmjkv13h = _rtB -> fl0bs0j2mk ;
_rtB -> jevv2fm2fd = _rtB -> hieuexynnh ; _rtB -> ladl220j2f = _rtB ->
kilro5pwjt ; srUpdateBC ( _rtDW -> migd3l322m ) ; } ssCallAccelRunBlock ( S ,
68 , 12 , SS_CALL_MDL_OUTPUTS ) ; ssCallAccelRunBlock ( S , 68 , 14 ,
SS_CALL_MDL_OUTPUTS ) ; _rtB -> efx3hutlus = _rtB -> o44btp1bfh ; _rtB ->
lnmmqjkn1y = _rtB -> pusmjkv13h ; srUpdateBC ( _rtDW -> ltwgr0hdzf ) ; }
_rtDW -> mr31tsmxrt = s39_iter ; ssCallAccelRunBlock ( S , 70 , 7 ,
SS_CALL_MDL_OUTPUTS ) ; _rtB -> imbvm4nubb = _rtB -> lnmmqjkn1y ; _rtB ->
crwju02pc4 = _rtB -> ltvm3ohp1n [ ( int32_T ) _rtB -> oermwpxuej ] ; _rtB ->
o0xkmddhz1 = ( _rtB -> pqdtxueztk == _rtB -> efx3hutlus ) ; _rtB ->
myuqgfg2pw = ( _rtB -> mu23lfp1gf == _rtB -> efx3hutlus ) ; _rtB ->
njlb0x2yx4 = _rtDW -> l50m1r2oee ; _rtB -> f5f2doxltb = _rtDW -> ifrf3qrqnt ;
_rtB -> euo1rf452s = _rtDW -> h4lwegxh2k ; u0 = muDoubleScalarFloor ( _rtB ->
aa4ijn1jbi ) ; if ( muDoubleScalarIsNaN ( u0 ) || muDoubleScalarIsInf ( u0 )
) { u0 = 0.0 ; } else { u0 = muDoubleScalarRem ( u0 , 256.0 ) ; } _rtB ->
cu3ywa2lpe = ( uint8_T ) ( u0 < 0.0 ? ( int32_T ) ( uint8_T ) - ( int8_T ) (
uint8_T ) - u0 : ( int32_T ) ( uint8_T ) u0 ) ; if ( _rtB -> o0xkmddhz1 ) {
_rtB -> nlzzwz5bw0 = _rtB -> kwyot2eh5v ; _rtB -> egg4rwd2zq = ldexp ( _rtB
-> nlzzwz5bw0 , dfqyg2doqf . p0yqwd1p4k ) ; ssCallAccelRunBlock ( S , 73 , 2
, SS_CALL_MDL_OUTPUTS ) ; _rtB -> lmm5czdetn = _rtB -> egg4rwd2zq / _rtB ->
ppjzempcom ; ssCallAccelRunBlock ( S , 73 , 5 , SS_CALL_MDL_OUTPUTS ) ;
switch ( _rtB -> cu3ywa2lpe ) { case 1 : u0 = muDoubleScalarFloor ( _rtB ->
kwyot2eh5v ) ; if ( muDoubleScalarIsNaN ( u0 ) || muDoubleScalarIsInf ( u0 )
) { u0 = 0.0 ; } else { u0 = muDoubleScalarRem ( u0 , 4.294967296E+9 ) ; }
_rtB -> iuj4f0idu5 = u0 < 0.0 ? - ( int32_T ) ( uint32_T ) - u0 : ( int32_T )
( uint32_T ) u0 ; _rtB -> cik24kt5fu = _rtB -> iuj4f0idu5 ; break ; case 2 :
u0 = muDoubleScalarFloor ( _rtB -> lmm5czdetn ) ; if ( muDoubleScalarIsNaN (
u0 ) || muDoubleScalarIsInf ( u0 ) ) { u0 = 0.0 ; } else { u0 =
muDoubleScalarRem ( u0 , 4.294967296E+9 ) ; } _rtB -> gxucwz1s5o = u0 < 0.0 ?
- ( int32_T ) ( uint32_T ) - u0 : ( int32_T ) ( uint32_T ) u0 ; _rtB ->
cik24kt5fu = _rtB -> gxucwz1s5o ; break ; default : _rtB -> cik24kt5fu = _rtB
-> ek0nqdriws ; break ; } _rtB -> fwfcg1jgmd = ( _rtB -> aitbhcdtya == _rtB
-> cu3ywa2lpe ) ; ssCallAccelRunBlock ( S , 76 , 2 , SS_CALL_MDL_OUTPUTS ) ;
_rtB -> awrbxk4kxk = ( _rtB -> jo5recaqez == _rtB -> cu3ywa2lpe ) ;
ssCallAccelRunBlock ( S , 76 , 5 , SS_CALL_MDL_OUTPUTS ) ; if ( _rtB ->
fwfcg1jgmd || _rtB -> awrbxk4kxk ) { _rtB -> k0r3hd4j3u = _rtB -> cu3ywa2lpe
; srUpdateBC ( _rtDW -> a5val3l0ul ) ; } else { _rtB -> k0r3hd4j3u = _rtP ->
P_542 ; srUpdateBC ( _rtDW -> gkqiolasrk ) ; } _rtB -> fylu5zm2np = _rtB ->
crwju02pc4 ; _rtB -> akr3kitw3r = ( real_T ) _rtB -> cik24kt5fu - _rtB ->
fylu5zm2np ; ssCallAccelRunBlock ( S , 77 , 2 , SS_CALL_MDL_OUTPUTS ) ; u0 =
_rtB -> akr3kitw3r / _rtB -> imbvm4nubb ; if ( u0 < 0.0 ) { u0 =
muDoubleScalarCeil ( u0 ) ; } else { u0 = muDoubleScalarFloor ( u0 ) ; } if (
muDoubleScalarIsNaN ( u0 ) || muDoubleScalarIsInf ( u0 ) ) { u0 = 0.0 ; }
else { u0 = muDoubleScalarRem ( u0 , 4.294967296E+9 ) ; } _rtB -> kiawnoo0wi
= u0 < 0.0 ? - ( int32_T ) ( uint32_T ) - u0 : ( int32_T ) ( uint32_T ) u0 ;
ssCallAccelRunBlock ( S , 77 , 4 , SS_CALL_MDL_OUTPUTS ) ; if ( _rtB ->
jevv2fm2fd != 0.0 ) { u0 = muDoubleScalarFloor ( _rtB -> fylu5zm2np ) ; if (
muDoubleScalarIsNaN ( u0 ) || muDoubleScalarIsInf ( u0 ) ) { u0 = 0.0 ; }
else { u0 = muDoubleScalarRem ( u0 , 4.294967296E+9 ) ; } _rtB -> a5plfgzpwo
= u0 < 0.0 ? - ( int32_T ) ( uint32_T ) - u0 : ( int32_T ) ( uint32_T ) u0 ;
_rtB -> a3pydpcoal = _rtB -> kiawnoo0wi ; } else { _rtB -> a5plfgzpwo = _rtB
-> cik24kt5fu ; _rtB -> a3pydpcoal = _rtB -> inas2ho4rn ; } _rtB ->
mvek0lp1us = _rtB -> a5plfgzpwo ; _rtB -> gq03v11vt2 = _rtB -> k0r3hd4j3u ;
srUpdateBC ( _rtDW -> fbwkms0mi0 ) ; } else if ( _rtB -> myuqgfg2pw ) { _rtB
-> a3pydpcoal = _rtB -> njlb0x2yx4 ; _rtB -> mvek0lp1us = _rtB -> f5f2doxltb
; _rtB -> gq03v11vt2 = _rtB -> euo1rf452s ; srUpdateBC ( _rtDW -> pbdjh3ja5h
) ; } else { _rtB -> a3pydpcoal = _rtP -> P_139 ; _rtB -> mvek0lp1us = _rtP
-> P_140 ; _rtB -> gq03v11vt2 = _rtP -> P_549 ; srUpdateBC ( _rtDW ->
dke4unogca ) ; } _rtB -> ksrltbexj4 = _rtB -> mvek0lp1us ;
ssCallAccelRunBlock ( S , 83 , 14 , SS_CALL_MDL_OUTPUTS ) ;
ssCallAccelRunBlock ( S , 83 , 15 , SS_CALL_MDL_OUTPUTS ) ; _rtB ->
ph10gctrs2 = _rtB -> gq03v11vt2 ; ssCallAccelRunBlock ( S , 83 , 18 ,
SS_CALL_MDL_OUTPUTS ) ; if ( _rtB -> ladl220j2f != 0.0 ) { _rtB -> c0s3xnm3nu
= _rtB -> jckkc4d340 ; } else { _rtB -> iwhnnp4hxh = ! _rtB -> o0xkmddhz1 ;
_rtB -> iss1iprrp5 = ( _rtB -> myuqgfg2pw && _rtB -> iwhnnp4hxh ) ; if ( _rtB
-> iss1iprrp5 ) { _rtB -> g5hxuyvbrt = _rtB -> nayimscs34 ; } else { _rtB ->
g5hxuyvbrt = _rtB -> fpz1qymzle ; } tmp = ( uint32_T ) _rtB -> ptljvylyhq +
_rtB -> g5hxuyvbrt ; if ( tmp > 65535U ) { tmp = 65535U ; } _rtB ->
n213hyia2f = ( uint16_T ) tmp ; _rtB -> c0s3xnm3nu = _rtB -> n213hyia2f ; }
_rtB -> gmp3jtolqx = ( _rtB -> imbvm4nubb <= _rtB -> c0s3xnm3nu ) ; u0 =
muDoubleScalarFloor ( _rtB -> c0s3xnm3nu ) ; if ( muDoubleScalarIsNaN ( u0 )
|| muDoubleScalarIsInf ( u0 ) ) { u0 = 0.0 ; } else { u0 = muDoubleScalarRem
( u0 , 65536.0 ) ; } _rtB -> mopl3z2tgx = ( uint16_T ) ( u0 < 0.0 ? ( int32_T
) ( uint16_T ) - ( int16_T ) ( uint16_T ) - u0 : ( int32_T ) ( uint16_T ) u0
) ; s39_iter = 0 ; do { exitg1 = 0 ; u0 = _rtB -> lcef2awnpx ; if ( u0 < 0.0
) { u0 = muDoubleScalarCeil ( u0 ) ; } else { u0 = muDoubleScalarFloor ( u0 )
; } if ( muDoubleScalarIsNaN ( u0 ) || muDoubleScalarIsInf ( u0 ) ) { u0 =
0.0 ; } else { u0 = muDoubleScalarRem ( u0 , 256.0 ) ; } if ( s39_iter < ( u0
< 0.0 ? ( int32_T ) ( int8_T ) - ( int8_T ) ( uint8_T ) - u0 : ( int32_T ) (
int8_T ) ( uint8_T ) u0 ) ) { _rtB -> eh0gayi5t2 = s39_iter ; for ( i = 0 ; i
< 6 ; i ++ ) { _rtDW -> boqm1yvkzq [ i ] = _rtB -> fhdlrlvnnr [ i ] ; }
ssWriteToDataStoreWithPath ( S , _rtDW -> o412tr1nxv ,
 "eCS_Algo_Simulation_2015b_opti/SAD/Subsystem/SAD/SAD/SAD_runMainFunction/SAD mainfunction/ComputeDutyCycle/Data Store Write"
, NULL ) ; _rtB -> ixp4wunhcf = _rtB -> l5y1e2gqqa [ _rtB -> eh0gayi5t2 ] ;
_rtB -> grujswzsmo = ( _rtB -> ixp4wunhcf == _rtB -> k23dxu2t4b ) ; _rtB ->
lvl22nafjo = _rtB -> jxf5xcxcpr [ _rtB -> eh0gayi5t2 ] ; _rtB -> hn0xrfjmf2 =
_rtB -> ltvm3ohp1n [ _rtB -> eh0gayi5t2 ] ; if ( _rtB -> grujswzsmo ) { _rtB
-> cntuug03ru = _rtP -> P_71 ; _rtB -> okwx5v5t1q = _rtP -> P_72 ; _rtB ->
fobv2j2e0p = _rtB -> eh0gayi5t2 ; _rtDW -> dm3lrfys1w = 4 ; } else {
ssReadFromDataStoreWithPath ( S , _rtDW -> o412tr1nxv ,
 "eCS_Algo_Simulation_2015b_opti/SAD/Subsystem/SAD/SAD/SAD_runMainFunction/SAD mainfunction/ComputeDutyCycle/UnlockRequest/scp_GetCurrent/Data Store Read"
, NULL ) ; for ( i = 0 ; i < 6 ; i ++ ) { _rtB -> dobsx4kzv4 [ i ] = _rtDW ->
boqm1yvkzq [ i ] ; } _rtB -> b1c4emnnpp = _rtB -> dobsx4kzv4 [ _rtB ->
eh0gayi5t2 ] ; u0 = _rtB -> ph10gctrs2 ; if ( u0 < 0.0 ) { u0 =
muDoubleScalarCeil ( u0 ) ; } else { u0 = muDoubleScalarFloor ( u0 ) ; } if (
muDoubleScalarIsNaN ( u0 ) || muDoubleScalarIsInf ( u0 ) ) { u0 = 0.0 ; }
else { u0 = muDoubleScalarRem ( u0 , 4.294967296E+9 ) ; } switch ( u0 < 0.0 ?
- ( int32_T ) ( uint32_T ) - u0 : ( int32_T ) ( uint32_T ) u0 ) { case 1 :
_rtB -> nzrkkjvksq = _rtB -> lhp0izu5dh - _rtB -> b1c4emnnpp ; _rtB ->
n5xiq3vehe = _rtP -> P_73 * _rtB -> nzrkkjvksq ; _rtB -> fe0vjdxzrd = _rtP ->
P_74 * _rtB -> nzrkkjvksq ; _rtB -> nw3a3wgxkg = ( _rtB -> nzrkkjvksq > _rtB
-> arhviy0l0a ) ; if ( _rtB -> nw3a3wgxkg ) { _rtB -> ag13qz2l0d = _rtB ->
nbg5eu0lv5 ; } else { _rtB -> ag13qz2l0d = _rtB -> lvl22nafjo ; } _rtB ->
ctyglt1byp = _rtB -> fe0vjdxzrd + _rtB -> ag13qz2l0d ; _rtB -> nbsfes5bhs =
_rtB -> n5xiq3vehe + _rtB -> ctyglt1byp ; ssCallAccelRunBlock ( S , 46 , 9 ,
SS_CALL_MDL_OUTPUTS ) ; ssCallAccelRunBlock ( S , 46 , 10 ,
SS_CALL_MDL_OUTPUTS ) ; u0 = _rtB -> nbsfes5bhs ; u1 = _rtP -> P_80 ; u2 =
_rtP -> P_79 ; if ( u0 > u2 ) { _rtB -> jeyjj5zzsa = u2 ; } else if ( u0 < u1
) { _rtB -> jeyjj5zzsa = u1 ; } else { _rtB -> jeyjj5zzsa = u0 ; } _rtB ->
caf5f1lfja = _rtB -> k3aj5v21pw * _rtB -> jeyjj5zzsa ; _rtB -> cntuug03ru =
_rtB -> caf5f1lfja / _rtB -> iykufpn0jg ; u0 = _rtB -> ctyglt1byp ; u1 = _rtP
-> P_82 ; u2 = _rtP -> P_81 ; if ( u0 > u2 ) { _rtB -> okwx5v5t1q = u2 ; }
else if ( u0 < u1 ) { _rtB -> okwx5v5t1q = u1 ; } else { _rtB -> okwx5v5t1q =
u0 ; } _rtB -> f2pmxkjptw = _rtP -> P_83 ; _rtDW -> lspbkd5who = 4 ; break ;
case 2 : if ( _rtB -> l5zyvytm2q != 0.0 ) { _rtB -> khjv5gm4wp = _rtB ->
hn0xrfjmf2 + _rtB -> l5zyvytm2q ; _rtB -> cntuug03ru = _rtB -> khjv5gm4wp ; }
else { _rtB -> cntuug03ru = _rtB -> lhp0izu5dh ; } _rtB -> f2pmxkjptw = _rtP
-> P_84 ; _rtDW -> m1vj0vtqqg = 4 ; break ; default : _rtB -> cntuug03ru =
_rtP -> P_85 ; _rtB -> f2pmxkjptw = _rtP -> P_86 ; _rtDW -> bm4f0symz4 = 4 ;
break ; } if ( _rtB -> f2pmxkjptw != 0.0 ) { pk4vnz4nca ( _rtB -> eh0gayi5t2
, & _rtB -> pk4vnz4ncay , ( o10tugwmnc * ) & _rtP -> pk4vnz4ncay ) ; } else {
pk4vnz4nca ( _rtB -> eh0gayi5t2 , & _rtB -> dzt5buqn0i , ( o10tugwmnc * ) &
_rtP -> dzt5buqn0i ) ; } _rtDW -> bqx1fj33ob = 4 ; } if ( s39_iter == 0 ) {
for ( i = 0 ; i < 6 ; i ++ ) { _rtB -> abalh4vw2r [ i ] = _rtB -> o2xkto035m
[ i ] ; _rtB -> m4tstczbwf [ i ] = _rtB -> pmvhbe5dy1 [ i ] ; _rtB ->
dzai3vfe0m [ i ] = _rtB -> kho1xs4xuc [ i ] ; } } _rtB -> abalh4vw2r [ _rtB
-> eh0gayi5t2 ] = _rtB -> okwx5v5t1q ; _rtB -> m4tstczbwf [ _rtB ->
eh0gayi5t2 ] = _rtB -> cntuug03ru ; _rtB -> dzai3vfe0m [ _rtB -> eh0gayi5t2 ]
= _rtB -> cntuug03ru ; srUpdateBC ( _rtDW -> ksy1mizjlr ) ; s39_iter ++ ; }
else { exitg1 = 1 ; } } while ( exitg1 == 0 ) ; _rtB -> nxlng2dxp2 = ( _rtB
-> bu4xye101e == _rtB -> efx3hutlus ) ; _rtB -> k5r2rlabpj = ( _rtB ->
k5ic2boaow == _rtB -> efx3hutlus ) ; _rtB -> agtolonpa0 = ( _rtB ->
nxlng2dxp2 || _rtB -> k5r2rlabpj ) ; if ( _rtB -> agtolonpa0 ) { _rtB ->
aghyyal3on = _rtB -> gmp3jtolqx ; } else { _rtB -> aghyyal3on = _rtB ->
li4gvkolhv ; } _rtB -> hj5kubfsqo = ( _rtB -> aghyyal3on || ( _rtB ->
lgy0jjj0i0 != 0.0 ) ) ; _rtB -> itw0wbw1u1 = _rtB -> hj5kubfsqo ; for ( i = 0
; i < 6 ; i ++ ) { _rtB -> kznyypxjcs [ i ] = _rtP -> P_389 * _rtB ->
m4tstczbwf [ i ] ; } { if ( _rtDW -> lkrzndmff3 . AQHandles ) {
sdiWriteSignal ( _rtDW -> lkrzndmff3 . AQHandles , ssGetTaskTime ( S , 4 ) ,
( void * ) & _rtB -> kznyypxjcs [ 0 ] ) ; } } if ( ssIsSpecialSampleHit ( S ,
5 , 4 , tid ) ) { _rtB -> ohj0mlvogt = _rtB -> d1xdtficuc ; } } if (
ssIsSampleHit ( S , 5 , tid ) ) { _rtB -> nudkrgh1vf = _rtDW -> pgnzkbaebr ;
if ( _rtB -> ohj0mlvogt != 0.0 ) { _rtB -> ds5nhpczjn = _rtB -> eeobulcy35 ;
} else { _rtB -> ds5nhpczjn = _rtB -> nudkrgh1vf ; } _rtB -> fgvn35rt5t =
_rtB -> ds5nhpczjn + _rtB -> nwkr1ixflo ; _rtB -> bqkot0jyum = look1_binlxpw
( _rtB -> fgvn35rt5t , _rtP -> P_167 , _rtP -> P_166 , 6U ) ; _rtB ->
bxbykbmumw = _rtB -> bqkot0jyum / _rtB -> i34ao5gnwv ; _rtB -> ojgknhescr =
_rtB -> cwhxnaeeqz + _rtB -> bxbykbmumw ; _rtB -> adqqzlo1x3 = _rtB ->
jr3yc0rmzv / _rtB -> ojgknhescr ; _rtB -> clqej3ibvk = _rtP -> P_206 * _rtB
-> bxbykbmumw ; } if ( ssIsSampleHit ( S , 4 , tid ) ) { _rtB -> ohktby5wme =
_rtDW -> lp1l3thhwo ; _rtB -> dhynpgeh5q = _rtP -> P_178 * _rtB -> ohktby5wme
; for ( i = 0 ; i < 6 ; i ++ ) { _rtB -> msonxiawi2 [ i ] = _rtB ->
cawesa2s3j [ i ] ; } _rtB -> msonxiawi2 [ ( int32_T ) _rtB -> pun25ssv2y ] =
_rtB -> dhynpgeh5q ; _rtB -> l1k2wyx5ju = _rtDW -> pqwrxa4opk ; _rtB ->
fexqyf5n2d = _rtP -> P_181 * _rtB -> l1k2wyx5ju ; u0 = _rtB -> fexqyf5n2d ;
u1 = _rtP -> P_183 ; u2 = _rtP -> P_182 ; if ( u0 > u2 ) { _rtB -> e2jke0yt3i
= u2 ; } else if ( u0 < u1 ) { _rtB -> e2jke0yt3i = u1 ; } else { _rtB ->
e2jke0yt3i = u0 ; } for ( i = 0 ; i < 6 ; i ++ ) { _rtB -> hhnw0yqplg [ i ] =
_rtB -> msonxiawi2 [ i ] ; } _rtB -> hhnw0yqplg [ ( int32_T ) _rtB ->
bn2s03wwos ] = _rtB -> e2jke0yt3i ; _rtB -> i4d3qdsjus = _rtDW -> daxp4bsf0f
; _rtB -> bg2gcigiz2 = _rtP -> P_186 * _rtB -> i4d3qdsjus ; u0 = _rtB ->
bg2gcigiz2 ; u1 = _rtP -> P_188 ; u2 = _rtP -> P_187 ; if ( u0 > u2 ) { _rtB
-> kwnovqfkki = u2 ; } else if ( u0 < u1 ) { _rtB -> kwnovqfkki = u1 ; } else
{ _rtB -> kwnovqfkki = u0 ; } for ( i = 0 ; i < 6 ; i ++ ) { _rtB ->
ef0mbk4yzi [ i ] = _rtB -> hhnw0yqplg [ i ] ; } _rtB -> ef0mbk4yzi [ (
int32_T ) _rtB -> guyrrwooxd ] = _rtB -> kwnovqfkki ; _rtB -> dqbagiyzjp =
_rtDW -> ck5sxwy2ru ; _rtB -> pj4dmd2zt2 = _rtP -> P_191 * _rtB -> dqbagiyzjp
; u0 = _rtB -> pj4dmd2zt2 ; u1 = _rtP -> P_193 ; u2 = _rtP -> P_192 ; if ( u0
> u2 ) { _rtB -> fqpn4rroj3 = u2 ; } else if ( u0 < u1 ) { _rtB -> fqpn4rroj3
= u1 ; } else { _rtB -> fqpn4rroj3 = u0 ; } for ( i = 0 ; i < 6 ; i ++ ) {
_rtB -> mnczwywben [ i ] = _rtB -> ef0mbk4yzi [ i ] ; } _rtB -> mnczwywben [
( int32_T ) _rtB -> flrxjgtgoj ] = _rtB -> fqpn4rroj3 ; _rtB -> i0wjevkgxt =
_rtDW -> g3ecn4ckon ; _rtB -> g1omkohyuw = _rtP -> P_196 * _rtB -> i0wjevkgxt
; u0 = _rtB -> g1omkohyuw ; u1 = _rtP -> P_198 ; u2 = _rtP -> P_197 ; if ( u0
> u2 ) { _rtB -> fnhk2b5abo = u2 ; } else if ( u0 < u1 ) { _rtB -> fnhk2b5abo
= u1 ; } else { _rtB -> fnhk2b5abo = u0 ; } for ( i = 0 ; i < 6 ; i ++ ) {
_rtB -> gpe3xkixi3 [ i ] = _rtB -> mnczwywben [ i ] ; } _rtB -> gpe3xkixi3 [
( int32_T ) _rtB -> ij22lsyyej ] = _rtB -> fnhk2b5abo ; _rtB -> hv0pwcmydw =
_rtDW -> oe212yvr13 ; _rtB -> n5afzxeevl = _rtP -> P_201 * _rtB -> hv0pwcmydw
; u0 = _rtB -> n5afzxeevl ; u1 = _rtP -> P_203 ; u2 = _rtP -> P_202 ; if ( u0
> u2 ) { _rtB -> omtwoohiof = u2 ; } else if ( u0 < u1 ) { _rtB -> omtwoohiof
= u1 ; } else { _rtB -> omtwoohiof = u0 ; } for ( i = 0 ; i < 6 ; i ++ ) {
_rtB -> pt4kxtn32n [ i ] = _rtB -> gpe3xkixi3 [ i ] ; } _rtB -> pt4kxtn32n [
( int32_T ) _rtB -> hw2t1cfbxp ] = _rtB -> omtwoohiof ; _rtB -> jdbxypgzo4 =
_rtB -> kznyypxjcs [ ( int32_T ) _rtB -> pun25ssv2y ] ; _rtB -> hykw5v2elp =
_rtB -> kznyypxjcs [ ( int32_T ) _rtB -> bn2s03wwos ] ; _rtB -> d0crgmjhmk =
_rtB -> kznyypxjcs [ ( int32_T ) _rtB -> guyrrwooxd ] ; _rtB -> etcomlt0am =
_rtB -> kznyypxjcs [ ( int32_T ) _rtB -> flrxjgtgoj ] ; _rtB -> fywe4qvkud =
_rtB -> kznyypxjcs [ ( int32_T ) _rtB -> ij22lsyyej ] ; _rtB -> bcm0wlon0r =
_rtB -> kznyypxjcs [ ( int32_T ) _rtB -> hw2t1cfbxp ] ; if (
ssIsSpecialSampleHit ( S , 5 , 4 , tid ) ) { _rtB -> br2nvy3pgj = _rtDW ->
aj2wjdkoig ; _rtB -> hzbtk1ux52 = _rtDW -> gm5ep22luc ; } _rtB -> n1kyvd1sma
= _rtB -> ohktby5wme * _rtB -> hzbtk1ux52 ; _rtB -> oaix03pkgj = _rtB ->
jdbxypgzo4 - _rtB -> n1kyvd1sma ; _rtB -> hl1lssukdz = _rtB -> oaix03pkgj *
_rtB -> br2nvy3pgj ; _rtB -> fvefuexz1y = _rtB -> l1k2wyx5ju * _rtB ->
hzbtk1ux52 ; _rtB -> bd2zqg2ilc = _rtB -> hykw5v2elp - _rtB -> fvefuexz1y ;
_rtB -> djxsupxwd5 = _rtB -> bd2zqg2ilc * _rtB -> br2nvy3pgj ; _rtB ->
dfwjdwiytu = _rtB -> i4d3qdsjus * _rtB -> hzbtk1ux52 ; _rtB -> grezjr1bo4 =
_rtB -> d0crgmjhmk - _rtB -> dfwjdwiytu ; _rtB -> crtn2ymfvo = _rtB ->
grezjr1bo4 * _rtB -> br2nvy3pgj ; _rtB -> nmzyospfed = _rtB -> dqbagiyzjp *
_rtB -> hzbtk1ux52 ; _rtB -> nenyig33cy = _rtB -> etcomlt0am - _rtB ->
nmzyospfed ; _rtB -> agtucdnby5 = _rtB -> nenyig33cy * _rtB -> br2nvy3pgj ;
_rtB -> byyh3reg4n = _rtB -> i0wjevkgxt * _rtB -> hzbtk1ux52 ; _rtB ->
eseldokymq = _rtB -> fywe4qvkud - _rtB -> byyh3reg4n ; _rtB -> c4wamgoft5 =
_rtB -> eseldokymq * _rtB -> br2nvy3pgj ; _rtB -> djsrvygabb = _rtB ->
hv0pwcmydw * _rtB -> hzbtk1ux52 ; _rtB -> nofdogvjae = _rtB -> bcm0wlon0r -
_rtB -> djsrvygabb ; _rtB -> lnzmvs2omy = _rtB -> nofdogvjae * _rtB ->
br2nvy3pgj ; { if ( _rtDW -> ox2hsn04wd . AQHandles ) { sdiWriteSignal (
_rtDW -> ox2hsn04wd . AQHandles , ssGetTaskTime ( S , 4 ) , ( void * ) & _rtB
-> pt4kxtn32n [ 0 ] ) ; } } } if ( ssIsSampleHit ( S , 1 , tid ) ) { if (
ssIsSpecialSampleHit ( S , 4 , 1 , tid ) ) { _rtB -> bunvhsvliq [ 0 ] = _rtDW
-> hrwqctpzib [ 0 ] ; _rtB -> bunvhsvliq [ 1 ] = _rtDW -> hrwqctpzib [ 1 ] ;
_rtB -> on05nrgtg5 [ 0 ] = _rtDW -> nctw2c0iw4 [ 0 ] ; _rtB -> on05nrgtg5 [ 1
] = _rtDW -> nctw2c0iw4 [ 1 ] ; _rtB -> be5iei4dsy [ 0 ] = _rtDW ->
cppuxlbmsi [ 0 ] ; _rtB -> be5iei4dsy [ 1 ] = _rtDW -> cppuxlbmsi [ 1 ] ;
_rtB -> gueomxio1u [ 0 ] = _rtDW -> kz22uwrjqw [ 0 ] ; _rtB -> gueomxio1u [ 1
] = _rtDW -> kz22uwrjqw [ 1 ] ; _rtB -> irwdszk43m [ 0 ] = _rtDW ->
bipp1kbm5a [ 0 ] ; _rtB -> irwdszk43m [ 1 ] = _rtDW -> bipp1kbm5a [ 1 ] ; }
switch ( ( int32_T ) _rtB -> nqwy3xmp15 ) { case 1 : _rtB -> klua5n5ghx =
look1_binlcapw ( _rtB -> kdhetuqrbn , _rtP -> P_60 , _rtP -> P_59 , 3U ) ;
_rtB -> hn5chskz40 = _rtB -> klua5n5ghx ; break ; case 2 : _rtB -> abuwfx3s0h
= look1_binlcapw ( _rtB -> kdhetuqrbn , _rtP -> P_58 , _rtP -> P_57 , 3U ) ;
_rtB -> hn5chskz40 = _rtB -> abuwfx3s0h ; break ; case 3 : _rtB -> l411susx3y
= look1_binlcapw ( _rtB -> kdhetuqrbn , _rtP -> P_56 , _rtP -> P_55 , 3U ) ;
_rtB -> hn5chskz40 = _rtB -> l411susx3y ; break ; case 4 : _rtB -> m2dyiro3kq
= look1_binlcapw ( _rtB -> kdhetuqrbn , _rtP -> P_54 , _rtP -> P_53 , 3U ) ;
_rtB -> hn5chskz40 = _rtB -> m2dyiro3kq ; break ; case 5 : _rtB -> mqaff1s4fk
= look1_binlcapw ( _rtB -> kdhetuqrbn , _rtP -> P_52 , _rtP -> P_51 , 3U ) ;
_rtB -> hn5chskz40 = _rtB -> mqaff1s4fk ; break ; case 6 : _rtB -> amdsu3wtxx
= look1_binlcapw ( _rtB -> kdhetuqrbn , _rtP -> P_50 , _rtP -> P_49 , 3U ) ;
_rtB -> hn5chskz40 = _rtB -> amdsu3wtxx ; break ; case 7 : _rtB -> g0tutjndio
= look1_binlcapw ( _rtB -> kdhetuqrbn , _rtP -> P_48 , _rtP -> P_47 , 3U ) ;
_rtB -> hn5chskz40 = _rtB -> g0tutjndio ; break ; case 8 : _rtB -> fqcihr1llb
= look1_binlcapw ( _rtB -> kdhetuqrbn , _rtP -> P_46 , _rtP -> P_45 , 3U ) ;
_rtB -> hn5chskz40 = _rtB -> fqcihr1llb ; break ; case 9 : _rtB -> hn5chskz40
= _rtB -> m2z3dblfze [ 0 ] ; break ; case 10 :
eCS_Algo_Simulation_2015b_opti_acc_LookUp_real_T_real_T ( & ( _rtB ->
cdphadlmmu ) , _rtP -> P_44 , _rtB -> kdhetuqrbn , _rtP -> P_43 , 2000U ) ;
_rtB -> hn5chskz40 = _rtB -> cdphadlmmu ; break ; case 11 :
eCS_Algo_Simulation_2015b_opti_acc_LookUp_real_T_real_T ( & ( _rtB ->
itkexqgd5l ) , _rtP -> P_42 , _rtB -> kdhetuqrbn , _rtP -> P_41 , 2000U ) ;
_rtB -> hn5chskz40 = _rtB -> itkexqgd5l ; break ; case 12 :
eCS_Algo_Simulation_2015b_opti_acc_LookUp_real_T_real_T ( & ( _rtB ->
elfnwgp23q ) , _rtP -> P_40 , _rtB -> kdhetuqrbn , _rtP -> P_39 , 2000U ) ;
_rtB -> hn5chskz40 = _rtB -> elfnwgp23q ; break ; case 13 :
eCS_Algo_Simulation_2015b_opti_acc_LookUp_real_T_real_T ( & ( _rtB ->
jlxywmhmvi ) , _rtP -> P_38 , _rtB -> kdhetuqrbn , _rtP -> P_37 , 2000U ) ;
_rtB -> hn5chskz40 = _rtB -> jlxywmhmvi ; break ; case 14 :
eCS_Algo_Simulation_2015b_opti_acc_LookUp_real_T_real_T ( & ( _rtB ->
ibxi13fxis ) , _rtP -> P_36 , _rtB -> kdhetuqrbn , _rtP -> P_35 , 2000U ) ;
_rtB -> hn5chskz40 = _rtB -> ibxi13fxis ; break ; case 15 : _rtB ->
kjhwermdpx = look1_binlcapw ( _rtB -> kdhetuqrbn , _rtP -> P_34 , _rtP ->
P_33 , 3U ) ; _rtB -> hn5chskz40 = _rtB -> kjhwermdpx ; break ; case 16 :
_rtB -> mquvrp1nad = look1_binlcapw ( _rtB -> kdhetuqrbn , _rtP -> P_32 ,
_rtP -> P_31 , 4U ) ; _rtB -> hn5chskz40 = _rtB -> mquvrp1nad ; break ; case
17 : _rtB -> hn5chskz40 = _rtB -> bunvhsvliq [ 0 ] ; break ; case 18 : _rtB
-> hn5chskz40 = _rtB -> on05nrgtg5 [ 0 ] ; break ; case 19 : _rtB ->
h31n5s1xvo = muDoubleScalarSin ( _rtB -> eypptav1zc ) ; _rtB -> hn5chskz40 =
_rtB -> h31n5s1xvo ; break ; case 20 : _rtB -> hn5chskz40 = _rtB ->
be5iei4dsy [ 0 ] ; break ; case 21 : _rtB -> hn5chskz40 = _rtB -> gueomxio1u
[ 0 ] ; break ; case 22 : _rtB -> hn5chskz40 = _rtB -> irwdszk43m [ 0 ] ;
break ; case 23 : _rtB -> etvjx4ulpa = look1_binlcapw ( _rtB -> kdhetuqrbn ,
_rtP -> P_30 , _rtP -> P_29 , 3U ) ; _rtB -> hn5chskz40 = _rtB -> etvjx4ulpa
; break ; case 24 : _rtB -> hn5chskz40 = _rtB -> m2z3dblfze [ 0 ] ; break ;
case 25 : _rtB -> aedrg5xog0 = _rtP -> P_26 * _rtB -> kdhetuqrbn ; u0 = _rtB
-> aedrg5xog0 ; u1 = _rtP -> P_28 ; u2 = _rtP -> P_27 ; if ( u0 > u2 ) { _rtB
-> cprwo25hcf = u2 ; } else if ( u0 < u1 ) { _rtB -> cprwo25hcf = u1 ; } else
{ _rtB -> cprwo25hcf = u0 ; } _rtB -> hn5chskz40 = _rtB -> cprwo25hcf ; break
; case 26 : _rtB -> hn5chskz40 = _rtB -> fchprg1k1b ; break ; case 27 : _rtB
-> hn5chskz40 = _rtB -> fchprg1k1b ; break ; case 28 : _rtB -> hn5chskz40 =
_rtB -> fchprg1k1b ; break ; default : _rtB -> hn5chskz40 = _rtB ->
fchprg1k1b ; break ; } switch ( ( int32_T ) _rtB -> nqwy3xmp15 ) { case 1 :
_rtB -> gpfg1nsx2e = _rtB -> fchprg1k1b ; break ; case 2 : _rtB -> gpfg1nsx2e
= _rtB -> fchprg1k1b ; break ; case 3 : _rtB -> gpfg1nsx2e = _rtB ->
fchprg1k1b ; break ; case 4 : _rtB -> gpfg1nsx2e = _rtB -> fchprg1k1b ; break
; case 5 : _rtB -> gpfg1nsx2e = _rtB -> fchprg1k1b ; break ; case 6 : _rtB ->
gpfg1nsx2e = _rtB -> fchprg1k1b ; break ; case 7 : _rtB -> gpfg1nsx2e = _rtB
-> fchprg1k1b ; break ; case 8 : _rtB -> gpfg1nsx2e = _rtB -> fchprg1k1b ;
break ; case 9 : _rtB -> gpfg1nsx2e = _rtB -> m2z3dblfze [ 1 ] ; break ; case
10 : _rtB -> gpfg1nsx2e = _rtB -> fchprg1k1b ; break ; case 11 : _rtB ->
gpfg1nsx2e = _rtB -> fchprg1k1b ; break ; case 12 : _rtB -> gpfg1nsx2e = _rtB
-> fchprg1k1b ; break ; case 13 : _rtB -> gpfg1nsx2e = _rtB -> fchprg1k1b ;
break ; case 14 : _rtB -> gpfg1nsx2e = _rtB -> fchprg1k1b ; break ; case 15 :
_rtB -> gpfg1nsx2e = _rtB -> fchprg1k1b ; break ; case 16 : _rtB ->
gpfg1nsx2e = _rtB -> fchprg1k1b ; break ; case 17 : _rtB -> gpfg1nsx2e = _rtB
-> bunvhsvliq [ 1 ] ; break ; case 18 : _rtB -> gpfg1nsx2e = _rtB ->
on05nrgtg5 [ 1 ] ; break ; case 19 : _rtB -> gpfg1nsx2e = _rtB -> fchprg1k1b
; break ; case 20 : _rtB -> gpfg1nsx2e = _rtB -> be5iei4dsy [ 1 ] ; break ;
case 21 : _rtB -> gpfg1nsx2e = _rtB -> gueomxio1u [ 1 ] ; break ; case 22 :
_rtB -> gpfg1nsx2e = _rtB -> irwdszk43m [ 1 ] ; break ; case 23 : _rtB ->
gpfg1nsx2e = _rtB -> m2z3dblfze [ 1 ] ; break ; case 24 : _rtB -> gpfg1nsx2e
= _rtB -> fchprg1k1b ; break ; case 25 : _rtB -> gpfg1nsx2e = _rtB ->
fchprg1k1b ; break ; case 26 : _rtB -> gpfg1nsx2e = _rtB -> fchprg1k1b ;
break ; case 27 : _rtB -> gpfg1nsx2e = _rtB -> fchprg1k1b ; break ; case 28 :
_rtB -> gpfg1nsx2e = _rtB -> fchprg1k1b ; break ; default : _rtB ->
gpfg1nsx2e = _rtB -> fchprg1k1b ; break ; } _rtB -> pejfvutxep [ 0 ] = _rtP
-> P_396 * _rtB -> hn5chskz40 ; _rtB -> pejfvutxep [ 1 ] = _rtP -> P_396 *
_rtB -> gpfg1nsx2e ; ssCallAccelRunBlock ( S , 113 , 155 ,
SS_CALL_MDL_OUTPUTS ) ; if ( ssIsSpecialSampleHit ( S , 4 , 1 , tid ) ) {
_rtB -> otrou3knvj = 0.0 ; } } if ( ssIsSampleHit ( S , 4 , tid ) ) { _rtB ->
cs4ybuyl5d = _rtB -> otrou3knvj ; _rtB -> o40m00z4xo = _rtP -> P_397 * _rtB
-> cs4ybuyl5d ; _rtB -> hinyxuv2uf [ 0 ] = _rtDW -> dqbmv0a4gm [ 0 ] ; _rtB
-> hinyxuv2uf [ 1 ] = _rtDW -> dqbmv0a4gm [ 1 ] ; _rtB -> buiapz53le =
muDoubleScalarHypot ( _rtB -> hinyxuv2uf [ 0 ] , _rtB -> hinyxuv2uf [ 1 ] ) ;
u0 = _rtB -> buiapz53le ; u1 = _rtP -> P_403 ; u2 = _rtP -> P_402 ; if ( u0 >
u2 ) { _rtB -> ju3k32zocs = u2 ; } else if ( u0 < u1 ) { _rtB -> ju3k32zocs =
u1 ; } else { _rtB -> ju3k32zocs = u0 ; } if ( _rtB -> ju3k32zocs >= _rtP ->
P_404 ) { _rtDW -> bv5gc20qwk = true ; } else { if ( _rtB -> ju3k32zocs <=
_rtP -> P_405 ) { _rtDW -> bv5gc20qwk = false ; } } if ( _rtDW -> bv5gc20qwk
) { _rtB -> bd5hv1yecd = _rtP -> P_406 ; } else { _rtB -> bd5hv1yecd = _rtP
-> P_407 ; } if ( _rtB -> o1st3cfhvz > _rtP -> P_409 ) { _rtB -> l5aggbsyt5 [
0 ] = _rtP -> P_296 * _rtB -> dlnrzb4sfw [ 0 ] ; _rtB -> l5aggbsyt5 [ 1 ] =
_rtP -> P_296 * _rtB -> dlnrzb4sfw [ 1 ] ; _rtB -> esbwb3abtv =
muDoubleScalarAtan2 ( _rtB -> l5aggbsyt5 [ 1 ] , _rtB -> l5aggbsyt5 [ 0 ] ) ;
_rtB -> efktvigxqo = muDoubleScalarHypot ( _rtB -> l5aggbsyt5 [ 0 ] , _rtB ->
l5aggbsyt5 [ 1 ] ) ; _rtB -> bhgdhge0wh = look1_binlxpw ( _rtB -> efktvigxqo
, _rtP -> P_298 , _rtP -> P_297 , 4U ) ; _rtB -> i0afh1ztlk = _rtB ->
bhgdhge0wh * muDoubleScalarSin ( _rtB -> esbwb3abtv ) ; _rtB -> nchjoxcibr =
_rtB -> bhgdhge0wh * muDoubleScalarCos ( _rtB -> esbwb3abtv ) ; _rtB ->
lf4qfqtilz [ 0 ] = _rtP -> P_299 * _rtB -> nchjoxcibr ; _rtB -> lf4qfqtilz [
1 ] = _rtP -> P_299 * _rtB -> i0afh1ztlk ; _rtB -> o2nhuetkcw [ 0 ] = _rtB ->
lf4qfqtilz [ 0 ] ; _rtB -> o2nhuetkcw [ 1 ] = _rtB -> lf4qfqtilz [ 1 ] ; }
else { _rtB -> o2nhuetkcw [ 0 ] = _rtB -> dlnrzb4sfw [ 0 ] ; _rtB ->
o2nhuetkcw [ 1 ] = _rtB -> dlnrzb4sfw [ 1 ] ; } u0 = _rtB -> o2nhuetkcw [ 0 ]
* _rtB -> o2nhuetkcw [ 0 ] + _rtB -> o2nhuetkcw [ 1 ] * _rtB -> o2nhuetkcw [
1 ] ; if ( u0 < 0.0 ) { u0 = - muDoubleScalarSqrt ( - u0 ) ; } else { u0 =
muDoubleScalarSqrt ( u0 ) ; } _rtB -> h1y41qssrb = u0 ; } if (
ssIsContinuousTask ( S , tid ) ) { _rtB -> amhc0ziya1 = ssGetT ( S ) ; if (
ssIsSpecialSampleHit ( S , 4 , 0 , tid ) ) { _rtB -> ejzgcob2qe = _rtB ->
amhc0ziya1 ; } } if ( ssIsSampleHit ( S , 4 , tid ) ) { ssCallAccelRunBlock (
S , 107 , 0 , SS_CALL_MDL_OUTPUTS ) ; _rtB -> ohwaabeuvd = ( ( _rtB ->
bd5hv1yecd != 0.0 ) || ( _rtB -> nora0pdveb != 0.0 ) ) ; _rtB -> eftejni13z =
_rtB -> ohwaabeuvd ; _rtB -> jjzmz53ut4 = _rtP -> P_414 * _rtB -> kaz1z4nb05
; ssCallAccelRunBlock ( S , 106 , 0 , SS_CALL_MDL_OUTPUTS ) ; _rtB ->
ffnec1tthf = _rtP -> P_415 * _rtB -> a2vj11zzjh ; _rtB -> n1yp244ju1 = _rtB
-> o40m00z4xo + _rtB -> ffnec1tthf ; } if ( ssIsSampleHit ( S , 1 , tid ) ) {
_rtB -> fbvucmsuyt = _rtDW -> kvqfd2snpc ; _rtB -> dnyocyec45 = _rtP -> P_418
* _rtB -> fbvucmsuyt ; if ( ssIsSpecialSampleHit ( S , 4 , 1 , tid ) ) { _rtB
-> d3mf5niw0b = _rtB -> dnyocyec45 ; } } if ( ssIsContinuousTask ( S , tid )
) { _rtB -> ibd50oa4ss = ssGetT ( S ) ; } if ( ssIsSampleHit ( S , 1 , tid )
) { _rtB -> fe24csbote = _rtB -> ibd50oa4ss ; if ( ssIsSpecialSampleHit ( S ,
4 , 1 , tid ) ) { _rtB -> bkrt2lmjz5 = _rtB -> fe24csbote ; } } if (
ssIsSampleHit ( S , 4 , tid ) ) { ssCallAccelRunBlock ( S , 111 , 0 ,
SS_CALL_MDL_OUTPUTS ) ; } if ( ssIsSampleHit ( S , 1 , tid ) ) { if (
ssIsSpecialSampleHit ( S , 4 , 1 , tid ) ) { _rtB -> odr1jfyedg = _rtDW ->
pdzhxmvm4m ; } ssCallAccelRunBlock ( S , 110 , 0 , SS_CALL_MDL_OUTPUTS ) ;
ssCallAccelRunBlock ( S , 112 , 0 , SS_CALL_MDL_OUTPUTS ) ; if (
ssIsSpecialSampleHit ( S , 4 , 1 , tid ) ) { _rtB -> gsbabzt4z4 = _rtB ->
orrinyuy1s ; } ssCallAccelRunBlock ( S , 109 , 0 , SS_CALL_MDL_OUTPUTS ) ; if
( ssIsSpecialSampleHit ( S , 4 , 1 , tid ) ) { _rtB -> pmgjxl3dd3 = _rtB ->
naowihtiai ; } } if ( ssIsSampleHit ( S , 4 , tid ) ) { _rtB -> j0rxsgsvmo [
0 ] = _rtB -> nogfk4dkzv ; _rtB -> j0rxsgsvmo [ 1 ] = _rtB -> gsbabzt4z4 ;
_rtB -> j0rxsgsvmo [ 2 ] = _rtB -> pmgjxl3dd3 ; ssCallAccelRunBlock ( S , 113
, 197 , SS_CALL_MDL_OUTPUTS ) ; } if ( ssIsSampleHit ( S , 1 , tid ) &&
ssIsSpecialSampleHit ( S , 2 , 1 , tid ) ) { _rtB -> ch53nkdxq0 [ 0 ] = _rtB
-> pejfvutxep [ 0 ] ; _rtB -> ch53nkdxq0 [ 1 ] = _rtB -> pejfvutxep [ 1 ] ; }
if ( ssIsSampleHit ( S , 2 , tid ) ) { ssCallAccelRunBlock ( S , 113 , 199 ,
SS_CALL_MDL_OUTPUTS ) ; } if ( ssIsSampleHit ( S , 1 , tid ) &&
ssIsSpecialSampleHit ( S , 4 , 1 , tid ) ) { _rtB -> cf1jgaigsz = _rtB ->
fe24csbote ; } if ( ssIsSampleHit ( S , 4 , tid ) ) { ssCallAccelRunBlock ( S
, 113 , 201 , SS_CALL_MDL_OUTPUTS ) ; if ( ssIsSampleHit ( S , 4 , tid ) ) {
_rtB -> lmhcsosjks = _rtB -> n1yp244ju1 ; } ssCallAccelRunBlock ( S , 113 ,
203 , SS_CALL_MDL_OUTPUTS ) ; _rtB -> jkjfgugn1q = _rtP -> P_423 * _rtB ->
ju3k32zocs ; if ( ssIsSampleHit ( S , 4 , tid ) ) { _rtB -> mude1gzxqd = _rtB
-> jkjfgugn1q ; } ssCallAccelRunBlock ( S , 113 , 206 , SS_CALL_MDL_OUTPUTS )
; if ( ssIsSampleHit ( S , 4 , tid ) ) { _rtB -> mjqpjnuelg = _rtB ->
d50nyhtpfe ; } ssCallAccelRunBlock ( S , 113 , 208 , SS_CALL_MDL_OUTPUTS ) ;
if ( ssIsSampleHit ( S , 4 , tid ) ) { _rtB -> pdfxubeked = _rtB ->
d1xdtficuc ; } ssCallAccelRunBlock ( S , 113 , 210 , SS_CALL_MDL_OUTPUTS ) ;
} if ( ssIsSampleHit ( S , 2 , tid ) ) { if ( ssIsSpecialSampleHit ( S , 4 ,
2 , tid ) ) { _rtB -> g2v0ga14q0 [ 0 ] = _rtDW -> pj4ojgmpcm [ 0 ] ; _rtB ->
g2v0ga14q0 [ 1 ] = _rtDW -> pj4ojgmpcm [ 1 ] ; } ssCallAccelRunBlock ( S ,
113 , 212 , SS_CALL_MDL_OUTPUTS ) ; if ( ssIsSpecialSampleHit ( S , 4 , 2 ,
tid ) ) { _rtB -> dfupyzb1hs [ 0 ] = _rtDW -> owgovwhchn [ 0 ] ; _rtB ->
dfupyzb1hs [ 1 ] = _rtDW -> owgovwhchn [ 1 ] ; } ssCallAccelRunBlock ( S ,
113 , 214 , SS_CALL_MDL_OUTPUTS ) ; if ( ssIsSpecialSampleHit ( S , 4 , 2 ,
tid ) ) { _rtB -> egm5bnflcg [ 0 ] = _rtDW -> aggzfxoows [ 0 ] ; _rtB ->
egm5bnflcg [ 1 ] = _rtDW -> aggzfxoows [ 1 ] ; _rtB -> egm5bnflcg [ 2 ] =
_rtDW -> aggzfxoows [ 2 ] ; } ssCallAccelRunBlock ( S , 113 , 216 ,
SS_CALL_MDL_OUTPUTS ) ; if ( ssIsSpecialSampleHit ( S , 4 , 2 , tid ) ) {
_rtB -> jafyodqdpm = _rtDW -> kg1nxff3qr ; } ssCallAccelRunBlock ( S , 113 ,
218 , SS_CALL_MDL_OUTPUTS ) ; } if ( ssIsSampleHit ( S , 1 , tid ) &&
ssIsSpecialSampleHit ( S , 4 , 1 , tid ) ) { _rtB -> kpex43dmre = _rtB ->
bim2cdm3mx ; _rtB -> id1dklg3fn = _rtB -> npnlw3lqib ; } if ( ssIsSampleHit (
S , 4 , tid ) ) { _rtB -> ffw0zeuw0i [ 0 ] = _rtB -> jrss0d5a5n ; _rtB ->
ffw0zeuw0i [ 1 ] = _rtB -> kpex43dmre ; _rtB -> ffw0zeuw0i [ 2 ] = _rtB ->
id1dklg3fn ; _rtB -> ffw0zeuw0i [ 3 ] = _rtB -> jprrtdhgvh ;
ssCallAccelRunBlock ( S , 113 , 222 , SS_CALL_MDL_OUTPUTS ) ; } if (
ssIsSampleHit ( S , 1 , tid ) && ssIsSpecialSampleHit ( S , 2 , 1 , tid ) ) {
_rtB -> cbkquiddso = _rtB -> dnyocyec45 ; } if ( ssIsSampleHit ( S , 2 , tid
) ) { ssCallAccelRunBlock ( S , 113 , 224 , SS_CALL_MDL_OUTPUTS ) ; if (
ssIsSpecialSampleHit ( S , 4 , 2 , tid ) ) { _rtB -> jd5mn12dmt = _rtDW ->
atxkeuoicm ; } } if ( ssIsSampleHit ( S , 1 , tid ) && ssIsSpecialSampleHit (
S , 2 , 1 , tid ) ) { _rtB -> ejyfdylvfw = _rtB -> orrinyuy1s ; _rtB ->
mc5laj1p1k = _rtB -> naowihtiai ; } if ( ssIsSampleHit ( S , 2 , tid ) ) {
_rtB -> pf2wh2pew2 [ 0 ] = _rtB -> jd5mn12dmt ; _rtB -> pf2wh2pew2 [ 1 ] =
_rtB -> ejyfdylvfw ; _rtB -> pf2wh2pew2 [ 2 ] = _rtB -> mc5laj1p1k ;
ssCallAccelRunBlock ( S , 113 , 229 , SS_CALL_MDL_OUTPUTS ) ; } if (
ssIsSampleHit ( S , 1 , tid ) && ssIsSpecialSampleHit ( S , 4 , 1 , tid ) ) {
_rtB -> aovdyc414s = _rtB -> pwzdxl0oaf ; } if ( ssIsSampleHit ( S , 4 , tid
) ) { _rtB -> jogdle00pk = _rtB -> frsiia5ymk ; _rtB -> nwlg2fsmpn = _rtB ->
jdi5voovy1 ; _rtB -> c1gvmpnlmc [ 0 ] = _rtB -> jogdle00pk ; _rtB ->
c1gvmpnlmc [ 1 ] = _rtB -> aovdyc414s ; _rtB -> c1gvmpnlmc [ 2 ] = _rtB ->
nwlg2fsmpn ; ssCallAccelRunBlock ( S , 113 , 234 , SS_CALL_MDL_OUTPUTS ) ; }
if ( ssIsSampleHit ( S , 1 , tid ) ) { ssCallAccelRunBlock ( S , 113 , 235 ,
SS_CALL_MDL_OUTPUTS ) ; } if ( ssIsContinuousTask ( S , tid ) &&
ssIsSpecialSampleHit ( S , 7 , 0 , tid ) ) { _rtB -> gwvbigvutp = _rtB ->
ibd50oa4ss ; } if ( ssIsSampleHit ( S , 7 , tid ) ) { ssCallAccelRunBlock ( S
, 113 , 237 , SS_CALL_MDL_OUTPUTS ) ; } if ( ssIsSampleHit ( S , 1 , tid ) )
{ ssCallAccelRunBlock ( S , 113 , 238 , SS_CALL_MDL_OUTPUTS ) ; } if (
ssIsSampleHit ( S , 4 , tid ) ) { for ( i = 0 ; i < 6 ; i ++ ) { _rtB ->
a42i3xr0ai [ i ] = _rtP -> P_429 * _rtB -> pt4kxtn32n [ i ] ; } } if (
ssIsSampleHit ( S , 3 , tid ) ) { ssCallAccelRunBlock ( S , 113 , 240 ,
SS_CALL_MDL_OUTPUTS ) ; } if ( ssIsContinuousTask ( S , tid ) ) { _rtB ->
hc4kjes0ty = muDoubleScalarSin ( _rtP -> P_432 * ssGetTaskTime ( S , 0 ) +
_rtP -> P_433 ) * _rtP -> P_430 + _rtP -> P_431 ; if ( _rtB -> d4v3ru0nxj !=
0.0 ) { _rtB -> jzdgmi2b4e = _rtB -> hc4kjes0ty ; } else { _rtB -> jzdgmi2b4e
= _rtB -> ecxiqz13p4 ; } } if ( ssIsSampleHit ( S , 1 , tid ) ) { _rtB ->
pp3ir4en3r = _rtB -> acscufcmry ; if ( _rtB -> pp3ir4en3r ) { _rtB ->
igx4z4kvxt = muDoubleScalarAtan2 ( _rtB -> pejfvutxep [ 1 ] , _rtB ->
pejfvutxep [ 0 ] ) ; _rtB -> igqkypuc2q = _rtB -> igx4z4kvxt + _rtB ->
knsgikviux ; _rtB -> k5qkxro3br = muDoubleScalarHypot ( _rtB -> pejfvutxep [
0 ] , _rtB -> pejfvutxep [ 1 ] ) ; _rtB -> l1apnubg1y = _rtB -> k5qkxro3br *
muDoubleScalarCos ( _rtB -> igqkypuc2q ) ; _rtB -> cbu4uc5jip = _rtB ->
k5qkxro3br * muDoubleScalarSin ( _rtB -> igqkypuc2q ) ; if (
ssIsMajorTimeStep ( S ) ) { srUpdateBC ( _rtDW -> o1he3akehe ) ; } } if (
_rtB -> m4vyrrkuvi != 0.0 ) { _rtB -> ifwqkh5mup [ 0 ] = _rtB -> l1apnubg1y ;
_rtB -> ifwqkh5mup [ 1 ] = _rtB -> cbu4uc5jip ; } else { _rtB -> ifwqkh5mup [
0 ] = _rtB -> pejfvutxep [ 0 ] ; _rtB -> ifwqkh5mup [ 1 ] = _rtB ->
pejfvutxep [ 1 ] ; } _rtB -> a4mh5mpxae [ 0 ] = _rtP -> P_437 * _rtB ->
ifwqkh5mup [ 0 ] ; _rtB -> a4mh5mpxae [ 1 ] = _rtP -> P_437 * _rtB ->
ifwqkh5mup [ 1 ] ; _rtB -> lznemqnlw0 = _rtDW -> m5rlxjrekj ; } if (
ssIsContinuousTask ( S , tid ) ) { _rtB -> a40q0srqaw = _rtB -> jzdgmi2b4e +
_rtB -> a4mh5mpxae [ 0 ] ; } if ( ssIsSampleHit ( S , 1 , tid ) ) { _rtB ->
o0wmtoymbz = _rtDW -> iphqaxfged ; } if ( ssIsContinuousTask ( S , tid ) ) {
_rtB -> b4n1d4srw3 = _rtB -> a40q0srqaw + _rtB -> lznemqnlw0 ; if ( _rtB ->
d4v3ru0nxj != 0.0 ) { _rtB -> ak0ued2moz = _rtB -> hc4kjes0ty ; } else { _rtB
-> ak0ued2moz = _rtB -> pc1143czyr ; } _rtB -> lgqfupnzhu = _rtB ->
a4mh5mpxae [ 1 ] + _rtB -> ak0ued2moz ; } if ( ssIsSampleHit ( S , 1 , tid )
) { _rtB -> ldltrjkkk2 = _rtDW -> lr5un131lv ; } if ( ssIsContinuousTask ( S
, tid ) ) { _rtB -> j1nemqtyj3 = _rtB -> lgqfupnzhu + _rtB -> o0wmtoymbz ;
_rtB -> mqhdxaknv2 = _rtB -> aj12lh0tmp + _rtB -> ldltrjkkk2 ; } if (
ssIsSampleHit ( S , 1 , tid ) ) { ssCallAccelRunBlock ( S , 113 , 261 ,
SS_CALL_MDL_OUTPUTS ) ; ssCallAccelRunBlock ( S , 113 , 262 ,
SS_CALL_MDL_OUTPUTS ) ; _rtB -> jg34pzjgic = ( uint8_T ) ( _rtB -> dnyocyec45
>= _rtB -> gkcrmj4rgc ) ; _rtB -> dj13yqkpcx = ( uint8_T ) ( _rtB ->
dnyocyec45 >= _rtB -> bbclbgdrl3 ) ; _rtB -> g3mzq41jrd = ( uint8_T ) ( (
uint32_T ) _rtB -> jg34pzjgic + _rtB -> dj13yqkpcx ) ; _rtB -> houke3cd4l =
_rtDW -> irodt0fwp2 ; } if ( ssIsSampleHit ( S , 4 , tid ) ) { u0 = _rtB ->
kr5ohferol [ 0 ] ; u1 = _rtP -> P_451 ; u2 = _rtP -> P_450 ; if ( u0 > u2 ) {
u0 = u2 ; } else { if ( u0 < u1 ) { u0 = u1 ; } } _rtB -> douo51unfo [ 0 ] =
u0 ; _rtB -> ezunhfht05 [ 0 ] = _rtP -> P_452 * _rtB -> douo51unfo [ 0 ] ;
_rtB -> ovxyoduk0d [ 0 ] = muDoubleScalarSign ( _rtB -> douo51unfo [ 0 ] ) ;
_rtB -> ju04wau0my [ 0 ] = _rtP -> P_453 * _rtB -> ovxyoduk0d [ 0 ] ; _rtB ->
nlfximr1uc [ 0 ] = _rtB -> ezunhfht05 [ 0 ] + _rtB -> ju04wau0my [ 0 ] ; u0 =
_rtB -> kr5ohferol [ 1 ] ; u1 = _rtP -> P_451 ; u2 = _rtP -> P_450 ; if ( u0
> u2 ) { u0 = u2 ; } else { if ( u0 < u1 ) { u0 = u1 ; } } _rtB -> douo51unfo
[ 1 ] = u0 ; _rtB -> ezunhfht05 [ 1 ] = _rtP -> P_452 * _rtB -> douo51unfo [
1 ] ; _rtB -> ovxyoduk0d [ 1 ] = muDoubleScalarSign ( _rtB -> douo51unfo [ 1
] ) ; _rtB -> ju04wau0my [ 1 ] = _rtP -> P_453 * _rtB -> ovxyoduk0d [ 1 ] ;
_rtB -> nlfximr1uc [ 1 ] = _rtB -> ezunhfht05 [ 1 ] + _rtB -> ju04wau0my [ 1
] ; ssCallAccelRunBlock ( S , 113 , 274 , SS_CALL_MDL_OUTPUTS ) ;
ssCallAccelRunBlock ( S , 113 , 275 , SS_CALL_MDL_OUTPUTS ) ; } if (
ssIsSampleHit ( S , 1 , tid ) ) { ssCallAccelRunBlock ( S , 113 , 278 ,
SS_CALL_MDL_OUTPUTS ) ; ssCallAccelRunBlock ( S , 113 , 279 ,
SS_CALL_MDL_OUTPUTS ) ; if ( ssIsSpecialSampleHit ( S , 4 , 1 , tid ) ) {
_rtB -> iblpx52a1x = _rtB -> kdhetuqrbn ; } } if ( ssIsSampleHit ( S , 4 ,
tid ) ) { eCS_Algo_Simulation_2015b_opti_acc_LookUp_real_T_real_T ( & ( _rtB
-> c5xqttlmhd ) , & _rtB -> i3r431unyt [ 0 ] , _rtB -> iblpx52a1x , & _rtB ->
lyaeykn1sb [ 0 ] , 67199U ) ;
eCS_Algo_Simulation_2015b_opti_acc_LookUp_real_T_real_T ( & ( _rtB ->
b0awtdni5x ) , & _rtB -> lizjw3s4ig [ 0 ] , _rtB -> iblpx52a1x , & _rtB ->
lyaeykn1sb [ 0 ] , 67199U ) ; _rtB -> enjoa0lvzo [ 0 ] = _rtP -> P_461 * _rtB
-> c5xqttlmhd ; _rtB -> enjoa0lvzo [ 1 ] = _rtP -> P_461 * _rtB -> b0awtdni5x
; } if ( ssIsSampleHit ( S , 1 , tid ) ) { ssCallAccelRunBlock ( S , 113 ,
287 , SS_CALL_MDL_OUTPUTS ) ; if ( ssIsSpecialSampleHit ( S , 4 , 1 , tid ) )
{ _rtB -> hydrttjjtk = _rtB -> kdhetuqrbn ; } } if ( ssIsSampleHit ( S , 4 ,
tid ) ) { eCS_Algo_Simulation_2015b_opti_acc_LookUp_real_T_real_T ( & ( _rtB
-> cxayhtwnbd ) , & _rtB -> mu1wdz4w0e [ 0 ] , _rtB -> hydrttjjtk , & _rtB ->
asrnehrv30 [ 0 ] , 81599U ) ;
eCS_Algo_Simulation_2015b_opti_acc_LookUp_real_T_real_T ( & ( _rtB ->
odr3i5unt0 ) , & _rtB -> mnbd2jvvr3 [ 0 ] , _rtB -> hydrttjjtk , & _rtB ->
asrnehrv30 [ 0 ] , 81599U ) ; _rtB -> em3jwdame2 [ 0 ] = _rtP -> P_465 * _rtB
-> cxayhtwnbd ; _rtB -> em3jwdame2 [ 1 ] = _rtP -> P_465 * _rtB -> odr3i5unt0
; } if ( ssIsSampleHit ( S , 1 , tid ) ) { ssCallAccelRunBlock ( S , 113 ,
295 , SS_CALL_MDL_OUTPUTS ) ; if ( ssIsSpecialSampleHit ( S , 4 , 1 , tid ) )
{ _rtB -> m3ecvgn4di = _rtB -> kdhetuqrbn ; } } if ( ssIsSampleHit ( S , 4 ,
tid ) ) { eCS_Algo_Simulation_2015b_opti_acc_LookUp_real_T_real_T ( & ( _rtB
-> pqehbhenyb ) , & _rtB -> eo5bi0xbg5 [ 0 ] , _rtB -> m3ecvgn4di , & _rtB ->
bbod3hg4un [ 0 ] , 55199U ) ;
eCS_Algo_Simulation_2015b_opti_acc_LookUp_real_T_real_T ( & ( _rtB ->
o0n2coomor ) , & _rtB -> l4nukjud55 [ 0 ] , _rtB -> m3ecvgn4di , & _rtB ->
bbod3hg4un [ 0 ] , 55199U ) ; _rtB -> i4h1usdtr2 [ 0 ] = _rtP -> P_469 * _rtB
-> pqehbhenyb ; _rtB -> i4h1usdtr2 [ 1 ] = _rtP -> P_469 * _rtB -> o0n2coomor
; } if ( ssIsSampleHit ( S , 1 , tid ) ) { ssCallAccelRunBlock ( S , 113 ,
303 , SS_CALL_MDL_OUTPUTS ) ; if ( ssIsSpecialSampleHit ( S , 4 , 1 , tid ) )
{ _rtB -> jyc4c21bxu = _rtB -> kdhetuqrbn ; } } if ( ssIsSampleHit ( S , 4 ,
tid ) ) { eCS_Algo_Simulation_2015b_opti_acc_LookUp_real_T_real_T ( & ( _rtB
-> lyiyb4r4ev ) , & _rtB -> o2yv5zyqyp [ 0 ] , _rtB -> jyc4c21bxu , & _rtB ->
cjyuww5nf3 [ 0 ] , 60000U ) ;
eCS_Algo_Simulation_2015b_opti_acc_LookUp_real_T_real_T ( & ( _rtB ->
a0ufqfitne ) , & _rtB -> hdxwzh5i0y [ 0 ] , _rtB -> jyc4c21bxu , & _rtB ->
cjyuww5nf3 [ 0 ] , 60000U ) ; _rtB -> kqsjdprz5q [ 0 ] = _rtP -> P_473 * _rtB
-> lyiyb4r4ev ; _rtB -> kqsjdprz5q [ 1 ] = _rtP -> P_473 * _rtB -> a0ufqfitne
; } if ( ssIsSampleHit ( S , 1 , tid ) ) { ssCallAccelRunBlock ( S , 113 ,
311 , SS_CALL_MDL_OUTPUTS ) ; if ( ssIsSpecialSampleHit ( S , 6 , 1 , tid ) )
{ _rtB -> f2nyfkn5ln = _rtB -> kdhetuqrbn ; } } if ( ssIsSampleHit ( S , 6 ,
tid ) ) { eCS_Algo_Simulation_2015b_opti_acc_LookUp_real_T_real_T ( & ( _rtB
-> n4kthym1id ) , & _rtB -> djwcb3zcpz [ 0 ] , _rtB -> f2nyfkn5ln , & _rtB ->
bgbajtikw5 [ 0 ] , 32931U ) ; _rtB -> bpvvwchlfa = _rtP -> P_478 * _rtB ->
n4kthym1id ; eCS_Algo_Simulation_2015b_opti_acc_LookUp_real_T_real_T ( & (
_rtB -> kieknrznqe ) , & _rtB -> ksxsyjgznc [ 0 ] , _rtB -> f2nyfkn5ln , &
_rtB -> bgbajtikw5 [ 0 ] , 32931U ) ;
eCS_Algo_Simulation_2015b_opti_acc_LookUp_real_T_real_T ( & ( _rtB ->
mxqdgvpnr2 ) , & _rtB -> bwhmbbh3gr [ 0 ] , _rtB -> f2nyfkn5ln , & _rtB ->
bgbajtikw5 [ 0 ] , 32931U ) ; _rtB -> dfrk5qnmnd [ 0 ] = _rtP -> P_479 * _rtB
-> kieknrznqe ; _rtB -> dfrk5qnmnd [ 1 ] = _rtP -> P_479 * _rtB -> mxqdgvpnr2
; _rtB -> dfrk5qnmnd [ 2 ] = _rtP -> P_479 * _rtB -> bpvvwchlfa ; } if (
ssIsSampleHit ( S , 1 , tid ) ) { ssCallAccelRunBlock ( S , 113 , 322 ,
SS_CALL_MDL_OUTPUTS ) ; if ( ssIsSpecialSampleHit ( S , 4 , 1 , tid ) ) {
_rtB -> lugebkfasu = _rtB -> kdhetuqrbn ; } } if ( ssIsSampleHit ( S , 4 ,
tid ) ) { eCS_Algo_Simulation_2015b_opti_acc_LookUp_real_T_real_T ( & ( _rtB
-> go5p2djakm ) , & _rtB -> l3czk1zqbu [ 0 ] , _rtB -> lugebkfasu , & _rtB ->
jyae45w2lu [ 0 ] , 52600U ) ;
eCS_Algo_Simulation_2015b_opti_acc_LookUp_real_T_real_T ( & ( _rtB ->
oujthq0ff4 ) , & _rtB -> jwi0v1gse2 [ 0 ] , _rtB -> lugebkfasu , & _rtB ->
jyae45w2lu [ 0 ] , 52600U ) ; } if ( ssIsSampleHit ( S , 1 , tid ) ) { if (
_rtB -> kdhetuqrbn > _rtP -> P_485 ) { _rtB -> a3xreohdxa = _rtB ->
lamfjtpsmx ; } else { _rtB -> a3xreohdxa = _rtB -> n0pfdm1iru ; } _rtB ->
nh1pvznjjn = _rtB -> n1yp244ju1 ; _rtB -> fwggdslqxu [ 0 ] = _rtB ->
n1yp244ju1 ; _rtB -> fwggdslqxu [ 1 ] = _rtB -> jkjfgugn1q ; } if (
ssIsContinuousTask ( S , tid ) && ssIsSpecialSampleHit ( S , 3 , 0 , tid ) )
{ _rtB -> oytmjsalxb [ 0 ] = _rtB -> a40q0srqaw ; _rtB -> oytmjsalxb [ 1 ] =
_rtB -> lgqfupnzhu ; } if ( ssIsSampleHit ( S , 4 , tid ) ) { for ( i = 0 ; i
< 6 ; i ++ ) { _rtB -> lianw0yon1 [ i ] = _rtB -> a42i3xr0ai [ i ] ; }
ssCallAccelRunBlock ( S , 113 , 337 , SS_CALL_MDL_OUTPUTS ) ; } if (
ssIsSampleHit ( S , 1 , tid ) ) { u0 = _rtB -> pejfvutxep [ 0 ] * _rtB ->
pejfvutxep [ 0 ] + _rtB -> pejfvutxep [ 1 ] * _rtB -> pejfvutxep [ 1 ] ; if (
u0 < 0.0 ) { u0 = - muDoubleScalarSqrt ( - u0 ) ; } else { u0 =
muDoubleScalarSqrt ( u0 ) ; } _rtB -> o4wxqnrg0x = u0 ; } if ( ssIsSampleHit
( S , 3 , tid ) ) { if ( _rtB -> jdmwmm3jx1 > _rtP -> P_489 ) { _rtB ->
hud3uiwzj4 [ 0 ] = _rtB -> j2cav4m1bb ; _rtB -> hud3uiwzj4 [ 1 ] = _rtB ->
muyui1qnd5 ; } else { _rtB -> hud3uiwzj4 [ 0 ] = _rtB -> oytmjsalxb [ 0 ] ;
_rtB -> hud3uiwzj4 [ 1 ] = _rtB -> oytmjsalxb [ 1 ] ; } } if ( ssIsSampleHit
( S , 4 , tid ) ) { { if ( _rtDW -> ol1svwa1nx . AQHandles ) { sdiWriteSignal
( _rtDW -> ol1svwa1nx . AQHandles , ssGetTaskTime ( S , 4 ) , ( void * ) &
_rtB -> c0exzvmegw ) ; } } { if ( _rtDW -> kkjyvuqxul . AQHandles ) {
sdiWriteSignal ( _rtDW -> kkjyvuqxul . AQHandles , ssGetTaskTime ( S , 4 ) ,
( void * ) & _rtB -> d50nyhtpfe ) ; } } ssCallAccelRunBlock ( S , 113 , 344 ,
SS_CALL_MDL_OUTPUTS ) ; _rtB -> mftzvqpyg0 [ 0 ] = _rtDW -> oyyxz52vk3 [ 0 ]
; _rtB -> bumznjqqup [ 0 ] = _rtP -> P_492 * _rtB -> mftzvqpyg0 [ 0 ] ; u0 =
_rtB -> bumznjqqup [ 0 ] ; u1 = _rtP -> P_494 ; u2 = _rtP -> P_493 ; if ( u0
> u2 ) { u0 = u2 ; } else { if ( u0 < u1 ) { u0 = u1 ; } } _rtB -> mvyfg53zmh
[ 0 ] = u0 ; _rtB -> mftzvqpyg0 [ 1 ] = _rtDW -> oyyxz52vk3 [ 1 ] ; _rtB ->
bumznjqqup [ 1 ] = _rtP -> P_492 * _rtB -> mftzvqpyg0 [ 1 ] ; u0 = _rtB ->
bumznjqqup [ 1 ] ; u1 = _rtP -> P_494 ; u2 = _rtP -> P_493 ; if ( u0 > u2 ) {
u0 = u2 ; } else { if ( u0 < u1 ) { u0 = u1 ; } } _rtB -> mvyfg53zmh [ 1 ] =
u0 ; ssCallAccelRunBlock ( S , 113 , 348 , SS_CALL_MDL_OUTPUTS ) ; _rtB ->
cj2xdfhfqg = look1_binlcapw ( _rtB -> ju3k32zocs , _rtP -> P_496 , _rtP ->
P_495 , 2U ) ; _rtB -> h5ltgh0ftu = _rtP -> P_497 * _rtB -> cj2xdfhfqg ; _rtB
-> a4xxyerprl = look1_binlcapw ( _rtB -> ju3k32zocs , _rtP -> P_499 , _rtP ->
P_498 , 3U ) ; _rtB -> e23wgn15ra = _rtP -> P_500 * _rtB -> a4xxyerprl ; _rtB
-> nsojqiqoia = _rtB -> h5ltgh0ftu + _rtB -> e23wgn15ra ; ssCallAccelRunBlock
( S , 113 , 354 , SS_CALL_MDL_OUTPUTS ) ; ssCallAccelRunBlock ( S , 113 , 355
, SS_CALL_MDL_OUTPUTS ) ; ssCallAccelRunBlock ( S , 113 , 356 ,
SS_CALL_MDL_OUTPUTS ) ; ssCallAccelRunBlock ( S , 113 , 357 ,
SS_CALL_MDL_OUTPUTS ) ; ssCallAccelRunBlock ( S , 113 , 358 ,
SS_CALL_MDL_OUTPUTS ) ; _rtB -> oslynuyngg = muDoubleScalarAtan2 ( _rtB ->
hinyxuv2uf [ 1 ] , _rtB -> hinyxuv2uf [ 0 ] ) ; _rtB -> bm103xxmap =
muDoubleScalarCos ( _rtB -> oslynuyngg ) ; _rtB -> gwe0bbo0ff = _rtP -> P_501
* _rtB -> nsojqiqoia ; _rtB -> m1oilxbih3 = muDoubleScalarSin ( _rtB ->
gwe0bbo0ff ) ; _rtB -> bb2ft1xklz = _rtP -> P_502 * _rtB -> m1oilxbih3 ; _rtB
-> fodpgea35e = _rtB -> bm103xxmap * _rtB -> bb2ft1xklz ; _rtB -> icubpckdzx
= muDoubleScalarSin ( _rtB -> oslynuyngg ) ; _rtB -> nh000tjly5 = _rtB ->
icubpckdzx * _rtB -> bb2ft1xklz ; _rtB -> d0zna1jhhp [ 0 ] = ( _rtB ->
o2nhuetkcw [ 0 ] - _rtB -> fodpgea35e ) - _rtB -> mvyfg53zmh [ 0 ] ; _rtB ->
d0zna1jhhp [ 1 ] = ( _rtB -> o2nhuetkcw [ 1 ] - _rtB -> nh000tjly5 ) - _rtB
-> mvyfg53zmh [ 1 ] ; _rtB -> hacjpotnfr = _rtB -> ju3k32zocs *
muDoubleScalarCos ( _rtB -> oslynuyngg ) ; _rtB -> pq0dpwyvoi = _rtB ->
ju3k32zocs * muDoubleScalarSin ( _rtB -> oslynuyngg ) ; _rtB -> h0jswbbxdd =
_rtP -> P_503 * _rtB -> pq0dpwyvoi ; _rtB -> iikxy4bdqc = _rtP -> P_504 *
_rtB -> hacjpotnfr ; _rtB -> pqn2t1ud4n = _rtP -> P_505 * _rtB -> hinyxuv2uf
[ 0 ] ; _rtB -> csjwnbqt5d = _rtP -> P_506 * _rtB -> hinyxuv2uf [ 1 ] ; } if
( ssIsSampleHit ( S , 1 , tid ) ) { _rtB -> jqru3rl5bu = _rtB -> g3mzq41jrd ;
} if ( ssIsContinuousTask ( S , tid ) ) { ssCallAccelRunBlock ( S , 113 , 375
, SS_CALL_MDL_OUTPUTS ) ; ssCallAccelRunBlock ( S , 113 , 376 ,
SS_CALL_MDL_OUTPUTS ) ; } if ( ssIsSampleHit ( S , 1 , tid ) ) {
ssCallAccelRunBlock ( S , 113 , 377 , SS_CALL_MDL_OUTPUTS ) ; } if (
ssIsContinuousTask ( S , tid ) ) { ssCallAccelRunBlock ( S , 113 , 378 ,
SS_CALL_MDL_OUTPUTS ) ; } if ( ssIsSampleHit ( S , 1 , tid ) ) {
ssCallAccelRunBlock ( S , 113 , 379 , SS_CALL_MDL_OUTPUTS ) ;
ssCallAccelRunBlock ( S , 113 , 380 , SS_CALL_MDL_OUTPUTS ) ;
ssCallAccelRunBlock ( S , 113 , 381 , SS_CALL_MDL_OUTPUTS ) ; }
UNUSED_PARAMETER ( tid ) ; } static void mdlOutputsTID8 ( SimStruct * S ,
int_T tid ) { int32_T i ; real_T tmp ; kwbgjqm1wd * _rtB ; eu5bvmyspd * _rtP
; _rtP = ( ( eu5bvmyspd * ) ssGetDefaultParam ( S ) ) ; _rtB = ( ( kwbgjqm1wd
* ) _ssGetBlockIO ( S ) ) ; _rtB -> dwmkoes0qp = _rtP -> P_314 ; _rtB ->
pc4dwfdodj = _rtP -> P_315 ; _rtB -> kvfb1yian3 = _rtB -> dwmkoes0qp - _rtB
-> pc4dwfdodj ; _rtB -> oqxijjrg4q = _rtP -> P_319 ; _rtB -> he5ly1ypri =
_rtP -> P_332 ; _rtB -> aftcl0hub1 = _rtP -> P_345 ; _rtB -> n2upmvferm =
_rtP -> P_361 ; _rtB -> d4v3ru0nxj = _rtP -> P_366 ; _rtB -> atd2rker0m =
_rtP -> P_367 ; _rtB -> nqwy3xmp15 = _rtP -> P_368 ; _rtB -> bbgpi5suhy =
_rtP -> P_369 ; _rtB -> mwkuovhsdr = _rtP -> P_381 ; _rtB -> d1pmh2y33t =
_rtP -> P_219 ; _rtB -> jjwxs35qob = _rtP -> P_220 ; _rtB -> e30shzln4y = (
_rtB -> jjwxs35qob == _rtB -> d1pmh2y33t ) ; _rtB -> fyozuiawkl = _rtP ->
P_269 ; _rtB -> h1cxuvw3g5 = _rtP -> P_270 ; _rtB -> gmij1el113 = _rtP ->
P_272 ; _rtB -> b0kdzju0vw = _rtP -> P_273 ; _rtB -> miqitlu3dr = _rtP ->
P_263 ; _rtB -> iknuq4luh4 = _rtP -> P_264 ; _rtB -> aamrtq0qcu = _rtP ->
P_265 ; _rtB -> neklowdj12 = _rtP -> P_259 ; _rtB -> dxpfldghjh = _rtP ->
P_260 ; _rtB -> j5bqup4vc4 = _rtP -> P_291 ; _rtB -> miflwz331z = _rtP ->
P_278 ; _rtB -> h4z4c51szo = _rtP -> P_280 ; _rtB -> g1pmkupdj0 = _rtP ->
P_283 ; _rtB -> bsw103v254 = _rtP -> P_284 ; _rtB -> iiwgtu23rp = _rtP ->
P_285 ; _rtB -> o4t1nj0euj = _rtP -> P_286 ; _rtB -> oqqxv3tqha = _rtP ->
P_287 ; _rtB -> nohjwwgvtw = _rtP -> P_289 ; _rtB -> ebobnvfigw = _rtP ->
P_290 ; _rtB -> psij5om3ue = _rtP -> P_292 ; _rtB -> molvxhv4ww = _rtP ->
P_293 ; _rtB -> nqe4ajy0yz = ( _rtB -> molvxhv4ww == _rtB -> mwkuovhsdr ) ;
_rtB -> dagyvjhlf4 = _rtP -> P_294 ; if ( _rtB -> nqe4ajy0yz ) { _rtB ->
gmbxneiope = _rtB -> psij5om3ue ; } else { _rtB -> gmbxneiope = _rtB ->
dagyvjhlf4 ; } _rtB -> nozng0ink0 = ( _rtB -> gmbxneiope != 0.0 ) ; _rtB ->
jmnp4e4vm0 = _rtP -> P_0 ; _rtB -> bpwjoxgc2e = _rtP -> P_385 ; _rtB ->
g1iooey1bc = _rtP -> P_386 ; _rtB -> grqq4ycftm = _rtP -> P_387 ; _rtB ->
nmwjw0vfbr = _rtP -> P_4 ; _rtB -> khbsthsord = _rtP -> P_5 ; _rtB ->
nyx2ncbgd0 = ( _rtB -> khbsthsord == _rtB -> jmnp4e4vm0 ) ; _rtB ->
iw04lpj300 = _rtP -> P_6 ; _rtB -> orslpttifz = _rtP -> P_7 ; tmp =
muDoubleScalarFloor ( _rtB -> orslpttifz ) ; if ( muDoubleScalarIsNaN ( tmp )
|| muDoubleScalarIsInf ( tmp ) ) { tmp = 0.0 ; } else { tmp =
muDoubleScalarRem ( tmp , 256.0 ) ; } _rtB -> gxjj3w3gki = ( uint8_T ) ( tmp
< 0.0 ? ( int32_T ) ( uint8_T ) - ( int8_T ) ( uint8_T ) - tmp : ( int32_T )
( uint8_T ) tmp ) ; _rtB -> mgup1xmw4b = _rtP -> P_8 ; _rtB -> i0epboi5kz =
_rtP -> P_9 ; _rtB -> havu0xznpa = _rtP -> P_10 ; _rtB -> mvmfwyvulr = _rtP
-> P_11 ; _rtB -> ffrh2m4oj2 = _rtP -> P_12 ; _rtB -> neez4beh0d = _rtP ->
P_13 ; _rtB -> akbbxkdxot = _rtP -> P_14 ; _rtB -> jrzzbgsv2r = _rtP -> P_15
; _rtB -> pcpf40zr0z = _rtP -> P_16 ; _rtB -> lcef2awnpx = _rtP -> P_157 ;
_rtB -> cgn3bd1q0k = _rtP -> P_153 ; _rtB -> ausxigqqyz = _rtP -> P_92 ; tmp
= muDoubleScalarFloor ( _rtB -> ausxigqqyz ) ; if ( muDoubleScalarIsNaN ( tmp
) || muDoubleScalarIsInf ( tmp ) ) { tmp = 0.0 ; } else { tmp =
muDoubleScalarRem ( tmp , 256.0 ) ; } _rtB -> pajyam014w = ( uint8_T ) ( tmp
< 0.0 ? ( int32_T ) ( uint8_T ) - ( int8_T ) ( uint8_T ) - tmp : ( int32_T )
( uint8_T ) tmp ) ; _rtB -> iunnexzbrj = _rtP -> P_93 ; tmp =
muDoubleScalarFloor ( _rtB -> iunnexzbrj ) ; if ( muDoubleScalarIsNaN ( tmp )
|| muDoubleScalarIsInf ( tmp ) ) { tmp = 0.0 ; } else { tmp =
muDoubleScalarRem ( tmp , 256.0 ) ; } _rtB -> gm03qzow1w = ( uint8_T ) ( tmp
< 0.0 ? ( int32_T ) ( uint8_T ) - ( int8_T ) ( uint8_T ) - tmp : ( int32_T )
( uint8_T ) tmp ) ; _rtB -> lnbdqdazph = _rtP -> P_154 ; _rtB -> l5lj3ozze0 =
_rtP -> P_531 ; _rtB -> nrlr3pbf24 = _rtP -> P_529 ; _rtB -> awanavkxi2 =
_rtP -> P_525 ; _rtB -> bc3lbnnmx5 = _rtP -> P_94 ; _rtB -> doec5i5dn2 = _rtP
-> P_95 ; _rtB -> hq0kxxm04o = _rtP -> P_520 ; _rtB -> i3vyjuy0sc = _rtP ->
P_521 ; _rtB -> pyvld00gfo = _rtP -> P_96 ; _rtB -> iwql3g5xb5 = _rtP -> P_97
; _rtB -> k0ylqmumbz = _rtP -> P_128 ; _rtB -> anwbf2qrap = _rtP -> P_120 ;
_rtB -> aoy0bc5vlk = _rtP -> P_121 ; _rtB -> k4bsolae0q = _rtP -> P_122 ;
_rtB -> j05gb1ytfx = _rtP -> P_123 ; _rtB -> cz2scfzqth = _rtP -> P_124 ;
_rtB -> hv3l3zizuh = _rtP -> P_125 ; _rtB -> d1amjtvt0b = _rtP -> P_126 ;
_rtB -> luaarzgy4o = _rtP -> P_127 ; _rtB -> gbx3xsc1d2 = _rtP -> P_110 ;
_rtB -> oermwpxuej = _rtP -> P_156 ; _rtB -> pqdtxueztk = _rtP -> P_142 ;
_rtB -> mu23lfp1gf = _rtP -> P_143 ; _rtB -> ppjzempcom = _rtP -> P_130 ;
_rtB -> pdxqcepvcc = _rtP -> P_131 ; tmp = muDoubleScalarFloor ( _rtB ->
pdxqcepvcc ) ; if ( muDoubleScalarIsNaN ( tmp ) || muDoubleScalarIsInf ( tmp
) ) { tmp = 0.0 ; } else { tmp = muDoubleScalarRem ( tmp , 4.294967296E+9 ) ;
} _rtB -> ek0nqdriws = tmp < 0.0 ? - ( int32_T ) ( uint32_T ) - tmp : (
int32_T ) ( uint32_T ) tmp ; _rtB -> aitbhcdtya = _rtP -> P_543 ; _rtB ->
jo5recaqez = _rtP -> P_544 ; _rtB -> inas2ho4rn = _rtP -> P_134 ; _rtB ->
ptljvylyhq = _rtP -> P_511 ; _rtB -> fpz1qymzle = _rtP -> P_512 ; _rtB ->
jckkc4d340 = _rtP -> P_141 ; _rtB -> k23dxu2t4b = _rtP -> P_87 ; for ( i = 0
; i < 6 ; i ++ ) { _rtB -> mwnsk1unci [ i ] = _rtP -> P_3 [ i ] ; _rtB ->
o10otettee [ i ] = _rtP -> P_19 [ i ] ; _rtB -> j1poviybxl [ i ] = _rtP ->
P_24 [ i ] ; _rtB -> o2xkto035m [ i ] = _rtP -> P_88 [ i ] ; _rtB ->
kho1xs4xuc [ i ] = _rtP -> P_89 [ i ] ; _rtB -> pmvhbe5dy1 [ i ] = _rtP ->
P_90 [ i ] ; } _rtB -> k3j43id5ux = _rtP -> P_70 ; _rtB -> nbg5eu0lv5 = _rtP
-> P_75 ; _rtB -> arhviy0l0a = _rtP -> P_76 ; _rtB -> iykufpn0jg = _rtP ->
P_77 ; _rtB -> k3aj5v21pw = _rtP -> P_78 ; _rtB -> prwxl24d3f = _rtP -> P_148
; _rtB -> jedmjkjw24 = _rtP -> P_149 ; _rtB -> pzoor1grdz = _rtP -> P_150 ;
_rtB -> bu4xye101e = _rtP -> P_151 ; _rtB -> k5ic2boaow = _rtP -> P_152 ;
_rtB -> li4gvkolhv = _rtP -> P_555 ; _rtB -> jmyssdkzyz = ( 0.0 > _rtB ->
prwxl24d3f ) ; _rtB -> kap4sfeplz = ( _rtB -> jedmjkjw24 == 0.0 ) ; if ( _rtB
-> kap4sfeplz ) { _rtB -> lgy0jjj0i0 = _rtB -> jmyssdkzyz ; } else { _rtB ->
lgy0jjj0i0 = _rtB -> pzoor1grdz ; } _rtB -> eeobulcy35 = _rtP -> P_162 ; _rtB
-> nwkr1ixflo = _rtP -> P_164 ; _rtB -> cwhxnaeeqz = _rtP -> P_165 ; _rtB ->
cvl4b0wzpy = _rtP -> P_168 ; _rtB -> pchhexkacz = muDoubleScalarFloor ( _rtB
-> cvl4b0wzpy ) ; _rtB -> namt5qyy4u = _rtP -> P_169 ; _rtB -> ax4rx1zb3a =
_rtP -> P_170 ; _rtB -> k43lrevqpi = _rtP -> P_171 ; _rtB -> may3fefpau =
_rtP -> P_172 ; _rtB -> dzei4er1ud = _rtP -> P_173 ; _rtB -> c1njiowvzp =
_rtP -> P_174 ; _rtB -> oqai3i42f1 = _rtP -> P_175 ; switch ( ( int32_T )
_rtB -> pchhexkacz ) { case 1 : _rtB -> i34ao5gnwv = _rtB -> namt5qyy4u ;
break ; case 2 : _rtB -> i34ao5gnwv = _rtB -> ax4rx1zb3a ; break ; case 3 :
_rtB -> i34ao5gnwv = _rtB -> k43lrevqpi ; break ; case 4 : _rtB -> i34ao5gnwv
= _rtB -> may3fefpau ; break ; case 5 : _rtB -> i34ao5gnwv = _rtB ->
dzei4er1ud ; break ; case 6 : _rtB -> i34ao5gnwv = _rtB -> c1njiowvzp ; break
; default : _rtB -> i34ao5gnwv = _rtB -> oqai3i42f1 ; break ; } for ( i = 0 ;
i < 6 ; i ++ ) { _rtB -> cawesa2s3j [ i ] = _rtP -> P_176 [ i ] ; } _rtB ->
pun25ssv2y = _rtP -> P_179 ; _rtB -> bn2s03wwos = _rtP -> P_184 ; _rtB ->
guyrrwooxd = _rtP -> P_189 ; _rtB -> flrxjgtgoj = _rtP -> P_194 ; _rtB ->
ij22lsyyej = _rtP -> P_199 ; _rtB -> hw2t1cfbxp = _rtP -> P_204 ; _rtB ->
jr3yc0rmzv = _rtP -> P_205 ; _rtB -> fchprg1k1b = _rtP -> P_395 ; _rtB ->
o1st3cfhvz = _rtP -> P_408 ; _rtB -> i2di5bmmog = _rtP -> P_410 ; _rtB ->
m3qfolcl5z = _rtP -> P_411 ; _rtB -> mawl1vnfur = _rtP -> P_412 ; _rtB ->
ovzsnmtfbg = _rtP -> P_413 ; _rtB -> mkpsf1kls3 = _rtP -> P_420 ; _rtB ->
ezbqkyfmwd = _rtP -> P_421 ; _rtB -> auqw2522d5 = _rtP -> P_422 ; _rtB ->
ecxiqz13p4 = _rtP -> P_434 ; _rtB -> m4vyrrkuvi = _rtP -> P_435 ; _rtB ->
kyaxdf20vn = _rtP -> P_436 ; _rtB -> acscufcmry = ( _rtB -> m4vyrrkuvi !=
_rtB -> kyaxdf20vn ) ; _rtB -> knsgikviux = _rtP -> P_300 * _rtB ->
m4vyrrkuvi ; _rtB -> pc1143czyr = _rtP -> P_441 ; _rtB -> gkcrmj4rgc = _rtP
-> P_448 ; _rtB -> bbclbgdrl3 = _rtP -> P_449 ; _rtB -> fkhfsmpn0b = _rtP ->
P_456 ; _rtB -> bnqm43c02m = _rtP -> P_457 ; memcpy ( & _rtB -> lyaeykn1sb [
0 ] , & _rtP -> P_458 [ 0 ] , 67200U * sizeof ( real_T ) ) ; memcpy ( & _rtB
-> i3r431unyt [ 0 ] , & _rtP -> P_459 [ 0 ] , 67200U * sizeof ( real_T ) ) ;
memcpy ( & _rtB -> lizjw3s4ig [ 0 ] , & _rtP -> P_460 [ 0 ] , 67200U * sizeof
( real_T ) ) ; memcpy ( & _rtB -> asrnehrv30 [ 0 ] , & _rtP -> P_462 [ 0 ] ,
81600U * sizeof ( real_T ) ) ; memcpy ( & _rtB -> mu1wdz4w0e [ 0 ] , & _rtP
-> P_463 [ 0 ] , 81600U * sizeof ( real_T ) ) ; memcpy ( & _rtB -> mnbd2jvvr3
[ 0 ] , & _rtP -> P_464 [ 0 ] , 81600U * sizeof ( real_T ) ) ; memcpy ( &
_rtB -> bbod3hg4un [ 0 ] , & _rtP -> P_466 [ 0 ] , 55200U * sizeof ( real_T )
) ; memcpy ( & _rtB -> eo5bi0xbg5 [ 0 ] , & _rtP -> P_467 [ 0 ] , 55200U *
sizeof ( real_T ) ) ; memcpy ( & _rtB -> l4nukjud55 [ 0 ] , & _rtP -> P_468 [
0 ] , 55200U * sizeof ( real_T ) ) ; memcpy ( & _rtB -> cjyuww5nf3 [ 0 ] , &
_rtP -> P_470 [ 0 ] , 60001U * sizeof ( real_T ) ) ; memcpy ( & _rtB ->
o2yv5zyqyp [ 0 ] , & _rtP -> P_471 [ 0 ] , 60001U * sizeof ( real_T ) ) ;
memcpy ( & _rtB -> hdxwzh5i0y [ 0 ] , & _rtP -> P_472 [ 0 ] , 60001U * sizeof
( real_T ) ) ; memcpy ( & _rtB -> bgbajtikw5 [ 0 ] , & _rtP -> P_474 [ 0 ] ,
32932U * sizeof ( real_T ) ) ; memcpy ( & _rtB -> ksxsyjgznc [ 0 ] , & _rtP
-> P_475 [ 0 ] , 32932U * sizeof ( real_T ) ) ; memcpy ( & _rtB -> djwcb3zcpz
[ 0 ] , & _rtP -> P_476 [ 0 ] , 32932U * sizeof ( real_T ) ) ; memcpy ( &
_rtB -> bwhmbbh3gr [ 0 ] , & _rtP -> P_477 [ 0 ] , 32932U * sizeof ( real_T )
) ; memcpy ( & _rtB -> jyae45w2lu [ 0 ] , & _rtP -> P_480 [ 0 ] , 52601U *
sizeof ( real_T ) ) ; memcpy ( & _rtB -> l3czk1zqbu [ 0 ] , & _rtP -> P_481 [
0 ] , 52601U * sizeof ( real_T ) ) ; memcpy ( & _rtB -> jwi0v1gse2 [ 0 ] , &
_rtP -> P_482 [ 0 ] , 52601U * sizeof ( real_T ) ) ; _rtB -> lamfjtpsmx =
_rtP -> P_483 ; _rtB -> n0pfdm1iru = _rtP -> P_484 ; _rtB -> patfv4hn2l =
look1_binlcapw ( 0.0 , _rtP -> P_487 , _rtP -> P_486 , 27U ) ; _rtB ->
bp3vs32e3a = _rtP -> P_66 ; _rtB -> dj4n1z5upi = _rtP -> P_67 ; _rtB ->
khtzuu4au4 = _rtP -> P_68 ; _rtB -> cwvtkk021o = _rtP -> P_69 ; _rtB ->
jdmwmm3jx1 = _rtP -> P_488 ; UNUSED_PARAMETER ( tid ) ; }
#define MDL_UPDATE
static void mdlUpdate ( SimStruct * S , int_T tid ) { int32_T i ; kwbgjqm1wd
* _rtB ; eu5bvmyspd * _rtP ; hklldc0mgt * _rtDW ; _rtDW = ( ( hklldc0mgt * )
ssGetRootDWork ( S ) ) ; _rtP = ( ( eu5bvmyspd * ) ssGetDefaultParam ( S ) )
; _rtB = ( ( kwbgjqm1wd * ) _ssGetBlockIO ( S ) ) ; if ( ssIsSampleHit ( S ,
1 , tid ) ) { _rtDW -> o2oosfolvi = rt_nrand_Upu32_Yd_f_pw_snf ( & _rtDW ->
hufiirxks4 ) * _rtP -> P_317 + _rtP -> P_316 ; _rtDW -> a0xah1mbpy =
rt_nrand_Upu32_Yd_f_pw_snf ( & _rtDW -> o4igofrew2 ) * _rtP -> P_330 + _rtP
-> P_329 ; _rtDW -> adi32mgndf = rt_nrand_Upu32_Yd_f_pw_snf ( & _rtDW ->
ejjxksjduu ) * _rtP -> P_343 + _rtP -> P_342 ; } if ( ssIsSampleHit ( S , 4 ,
tid ) ) { _rtDW -> of1vslaqgx [ 0 ] += _rtP -> P_353 * _rtB -> nlfximr1uc [ 0
] ; if ( _rtDW -> of1vslaqgx [ 0 ] >= _rtP -> P_355 ) { _rtDW -> of1vslaqgx [
0 ] = _rtP -> P_355 ; } else { if ( _rtDW -> of1vslaqgx [ 0 ] <= _rtP ->
P_356 ) { _rtDW -> of1vslaqgx [ 0 ] = _rtP -> P_356 ; } } _rtDW -> of1vslaqgx
[ 1 ] += _rtP -> P_353 * _rtB -> nlfximr1uc [ 1 ] ; if ( _rtDW -> of1vslaqgx
[ 1 ] >= _rtP -> P_355 ) { _rtDW -> of1vslaqgx [ 1 ] = _rtP -> P_355 ; } else
{ if ( _rtDW -> of1vslaqgx [ 1 ] <= _rtP -> P_356 ) { _rtDW -> of1vslaqgx [ 1
] = _rtP -> P_356 ; } } } if ( ssIsSampleHit ( S , 6 , tid ) ) { _rtDW ->
dmqgarxxse [ 0 ] = _rtB -> dfrk5qnmnd [ 0 ] ; _rtDW -> dmqgarxxse [ 1 ] =
_rtB -> dfrk5qnmnd [ 1 ] ; _rtDW -> dmqgarxxse [ 2 ] = _rtB -> dfrk5qnmnd [ 2
] ; } if ( ssIsSampleHit ( S , 1 , tid ) ) { _rtDW -> bjv5blal5s += _rtP ->
P_371 * _rtB -> a3xreohdxa ; } if ( ssIsSampleHit ( S , 4 , tid ) ) { _rtDW
-> hs4k4kefqd += _rtP -> P_221 * _rtB -> cngorar52u ; if ( _rtDW ->
hs4k4kefqd >= _rtP -> P_223 ) { _rtDW -> hs4k4kefqd = _rtP -> P_223 ; } else
{ if ( _rtDW -> hs4k4kefqd <= _rtP -> P_224 ) { _rtDW -> hs4k4kefqd = _rtP ->
P_224 ; } } _rtDW -> h4bttuatlh += _rtP -> P_225 * _rtB -> lsmxv45udv ; if (
_rtDW -> h4bttuatlh >= _rtP -> P_227 ) { _rtDW -> h4bttuatlh = _rtP -> P_227
; } else { if ( _rtDW -> h4bttuatlh <= _rtP -> P_228 ) { _rtDW -> h4bttuatlh
= _rtP -> P_228 ; } } _rtDW -> brjgq21c2d += _rtP -> P_229 * _rtB ->
eyp2codp2y [ 0 ] ; _rtDW -> jvy1xkxywy += _rtP -> P_243 * _rtB -> eyp2codp2y
[ 1 ] ; _rtDW -> kqftxyuvoq = _rtB -> isvwzc1yat ; _rtDW -> hxp5z3k4kl = _rtB
-> kgkdkqgwdl ; _rtDW -> fceqnv3pgr = _rtB -> ajnmumn0h3 ; _rtDW ->
ar15ee0cps = _rtB -> dja1tvnqzx ; _rtDW -> b5ng0txcrl = _rtB -> puktn1stqd ;
_rtDW -> ghbdxiadlb = _rtB -> otqias0ib2 ; _rtDW -> gkkdkyvd0d = _rtB ->
chjhq0wzkk ; _rtDW -> ddu1of3sto = _rtB -> itw0wbw1u1 ; _rtDW -> fjqd5wsvmo =
_rtB -> mopl3z2tgx ; _rtDW -> katmfar1ds = _rtB -> fmnkiyvcwg ; for ( i = 0 ;
i < 6 ; i ++ ) { _rtDW -> mjjur2t4vf [ i ] = _rtB -> ff31tjeuqy [ i ] ; _rtDW
-> clanm1vhae [ i ] = _rtB -> lianw0yon1 [ i ] ; _rtDW -> c2nrolbzv5 [ i ] =
_rtB -> abalh4vw2r [ i ] ; _rtDW -> p2i3jocvl4 [ i ] = _rtB -> dzai3vfe0m [ i
] ; } _rtDW -> nkjl1zq3cc = _rtB -> ksrltbexj4 ; _rtDW -> e1o1uerdtv = _rtB
-> a3pydpcoal ; _rtDW -> jkp1gjxqwf = _rtB -> o0xk4spltu ; _rtDW ->
iqczfp0kxp = _rtB -> ozagibp3qx ; if ( _rtDW -> mr31tsmxrt == 1 ) { _rtDW ->
dduzbp03yu = _rtB -> aa4ijn1jbi ; _rtDW -> p1mcxttdss = _rtB -> kwyot2eh5v ;
_rtDW -> ob3531id3b = _rtB -> pusmjkv13h ; _rtDW -> hjwoxvjp5r = _rtB ->
jevv2fm2fd ; _rtDW -> epvmybyobi = _rtB -> ladl220j2f ; } _rtDW -> l50m1r2oee
= _rtB -> a3pydpcoal ; _rtDW -> ifrf3qrqnt = _rtB -> mvek0lp1us ; _rtDW ->
h4lwegxh2k = _rtB -> gq03v11vt2 ; } if ( ssIsSampleHit ( S , 4 , tid ) ) {
_rtDW -> lp1l3thhwo = _rtB -> hl1lssukdz ; _rtDW -> pqwrxa4opk = _rtB ->
djxsupxwd5 ; _rtDW -> daxp4bsf0f = _rtB -> crtn2ymfvo ; _rtDW -> ck5sxwy2ru =
_rtB -> agtucdnby5 ; _rtDW -> g3ecn4ckon = _rtB -> c4wamgoft5 ; _rtDW ->
oe212yvr13 = _rtB -> lnzmvs2omy ; } if ( ssIsSampleHit ( S , 5 , tid ) ) {
_rtDW -> pgnzkbaebr = _rtB -> fgvn35rt5t ; _rtDW -> aj2wjdkoig = _rtB ->
adqqzlo1x3 ; _rtDW -> gm5ep22luc = _rtB -> clqej3ibvk ; } if ( ssIsSampleHit
( S , 4 , tid ) ) { _rtDW -> hrwqctpzib [ 0 ] = _rtB -> kqsjdprz5q [ 0 ] ;
_rtDW -> hrwqctpzib [ 1 ] = _rtB -> kqsjdprz5q [ 1 ] ; _rtDW -> nctw2c0iw4 [
0 ] = _rtB -> go5p2djakm ; _rtDW -> nctw2c0iw4 [ 1 ] = _rtB -> oujthq0ff4 ;
_rtDW -> cppuxlbmsi [ 0 ] = _rtB -> enjoa0lvzo [ 0 ] ; _rtDW -> cppuxlbmsi [
1 ] = _rtB -> enjoa0lvzo [ 1 ] ; _rtDW -> kz22uwrjqw [ 0 ] = _rtB ->
em3jwdame2 [ 0 ] ; _rtDW -> kz22uwrjqw [ 1 ] = _rtB -> em3jwdame2 [ 1 ] ;
_rtDW -> bipp1kbm5a [ 0 ] = _rtB -> i4h1usdtr2 [ 0 ] ; _rtDW -> bipp1kbm5a [
1 ] = _rtB -> i4h1usdtr2 [ 1 ] ; _rtDW -> dqbmv0a4gm [ 0 ] += _rtP -> P_398 *
_rtB -> mftzvqpyg0 [ 0 ] ; if ( _rtDW -> dqbmv0a4gm [ 0 ] >= _rtP -> P_400 )
{ _rtDW -> dqbmv0a4gm [ 0 ] = _rtP -> P_400 ; } else { if ( _rtDW ->
dqbmv0a4gm [ 0 ] <= _rtP -> P_401 ) { _rtDW -> dqbmv0a4gm [ 0 ] = _rtP ->
P_401 ; } } _rtDW -> dqbmv0a4gm [ 1 ] += _rtP -> P_398 * _rtB -> mftzvqpyg0 [
1 ] ; if ( _rtDW -> dqbmv0a4gm [ 1 ] >= _rtP -> P_400 ) { _rtDW -> dqbmv0a4gm
[ 1 ] = _rtP -> P_400 ; } else { if ( _rtDW -> dqbmv0a4gm [ 1 ] <= _rtP ->
P_401 ) { _rtDW -> dqbmv0a4gm [ 1 ] = _rtP -> P_401 ; } } } if (
ssIsSampleHit ( S , 1 , tid ) ) { _rtDW -> kvqfd2snpc += _rtP -> P_416 * _rtB
-> houke3cd4l ; } if ( ssIsSampleHit ( S , 4 , tid ) ) { _rtDW -> pdzhxmvm4m
= _rtB -> n1yp244ju1 ; _rtDW -> pj4ojgmpcm [ 0 ] = _rtB -> efntnh4mf0 [ 0 ] ;
_rtDW -> pj4ojgmpcm [ 1 ] = _rtB -> efntnh4mf0 [ 1 ] ; _rtDW -> owgovwhchn [
0 ] = _rtB -> givhdtmscd [ 0 ] ; _rtDW -> owgovwhchn [ 1 ] = _rtB ->
givhdtmscd [ 1 ] ; _rtDW -> aggzfxoows [ 0 ] = _rtB -> jkjfgugn1q ; _rtDW ->
aggzfxoows [ 1 ] = _rtB -> iikxy4bdqc ; _rtDW -> aggzfxoows [ 2 ] = _rtB ->
h0jswbbxdd ; _rtDW -> kg1nxff3qr = _rtB -> n1yp244ju1 ; _rtDW -> atxkeuoicm =
_rtB -> nogfk4dkzv ; _rtDW -> oyyxz52vk3 [ 0 ] += _rtP -> P_490 * _rtB ->
d0zna1jhhp [ 0 ] ; _rtDW -> oyyxz52vk3 [ 1 ] += _rtP -> P_490 * _rtB ->
d0zna1jhhp [ 1 ] ; } if ( ssIsSampleHit ( S , 1 , tid ) ) { _rtDW ->
m5rlxjrekj = rt_nrand_Upu32_Yd_f_pw_snf ( & _rtDW -> ekojnxr03c ) * _rtP ->
P_439 + _rtP -> P_438 ; _rtDW -> iphqaxfged = rt_nrand_Upu32_Yd_f_pw_snf ( &
_rtDW -> p5exexegrh ) * _rtP -> P_443 + _rtP -> P_442 ; _rtDW -> lr5un131lv =
rt_nrand_Upu32_Yd_f_pw_snf ( & _rtDW -> f3ib224wx2 ) * _rtP -> P_446 + _rtP
-> P_445 ; _rtDW -> irodt0fwp2 += _rtP -> P_454 * _rtB -> o4wxqnrg0x ; }
UNUSED_PARAMETER ( tid ) ; }
#define MDL_UPDATE
static void mdlUpdateTID8 ( SimStruct * S , int_T tid ) { UNUSED_PARAMETER (
tid ) ; }
#define MDL_DERIVATIVES
static void mdlDerivatives ( SimStruct * S ) { kwbgjqm1wd * _rtB ; eu5bvmyspd
* _rtP ; o42trr3yi2 * _rtX ; luxbtoomob * _rtXdot ; _rtXdot = ( ( luxbtoomob
* ) ssGetdX ( S ) ) ; _rtX = ( ( o42trr3yi2 * ) ssGetContStates ( S ) ) ;
_rtP = ( ( eu5bvmyspd * ) ssGetDefaultParam ( S ) ) ; _rtB = ( ( kwbgjqm1wd *
) _ssGetBlockIO ( S ) ) ; _rtXdot -> pipnxjxhab [ 0 ] = 0.0 ; _rtXdot ->
pipnxjxhab [ 0 ] += _rtP -> P_301 [ 0 ] * _rtX -> pipnxjxhab [ 0 ] ; _rtXdot
-> pipnxjxhab [ 1 ] = 0.0 ; _rtXdot -> pipnxjxhab [ 0 ] += _rtP -> P_301 [ 1
] * _rtX -> pipnxjxhab [ 1 ] ; _rtXdot -> pipnxjxhab [ 1 ] += _rtX ->
pipnxjxhab [ 0 ] ; _rtXdot -> pipnxjxhab [ 0 ] += _rtB -> b4n1d4srw3 ;
_rtXdot -> h5ednakogf [ 0 ] = 0.0 ; _rtXdot -> h5ednakogf [ 0 ] += _rtP ->
P_303 [ 0 ] * _rtX -> h5ednakogf [ 0 ] ; _rtXdot -> h5ednakogf [ 1 ] = 0.0 ;
_rtXdot -> h5ednakogf [ 0 ] += _rtP -> P_303 [ 1 ] * _rtX -> h5ednakogf [ 1 ]
; _rtXdot -> h5ednakogf [ 1 ] += _rtX -> h5ednakogf [ 0 ] ; _rtXdot ->
h5ednakogf [ 0 ] += _rtB -> j1nemqtyj3 ; _rtXdot -> knglgyqvlm [ 0 ] = 0.0 ;
_rtXdot -> knglgyqvlm [ 0 ] += _rtP -> P_306 [ 0 ] * _rtX -> knglgyqvlm [ 0 ]
; _rtXdot -> knglgyqvlm [ 1 ] = 0.0 ; _rtXdot -> knglgyqvlm [ 0 ] += _rtP ->
P_306 [ 1 ] * _rtX -> knglgyqvlm [ 1 ] ; _rtXdot -> knglgyqvlm [ 1 ] += _rtX
-> knglgyqvlm [ 0 ] ; _rtXdot -> knglgyqvlm [ 0 ] += _rtB -> mqhdxaknv2 ; }
static void mdlInitializeSizes ( SimStruct * S ) { ssSetChecksumVal ( S , 0 ,
3180754738U ) ; ssSetChecksumVal ( S , 1 , 4237689025U ) ; ssSetChecksumVal (
S , 2 , 3889061673U ) ; ssSetChecksumVal ( S , 3 , 1009658148U ) ; { mxArray
* slVerStructMat = NULL ; mxArray * slStrMat = mxCreateString ( "simulink" )
; char slVerChar [ 10 ] ; int status = mexCallMATLAB ( 1 , & slVerStructMat ,
1 , & slStrMat , "ver" ) ; if ( status == 0 ) { mxArray * slVerMat =
mxGetField ( slVerStructMat , 0 , "Version" ) ; if ( slVerMat == NULL ) {
status = 1 ; } else { status = mxGetString ( slVerMat , slVerChar , 10 ) ; }
} mxDestroyArray ( slStrMat ) ; mxDestroyArray ( slVerStructMat ) ; if ( (
status == 1 ) || ( strcmp ( slVerChar , "8.6" ) != 0 ) ) { return ; } }
ssSetOptions ( S , SS_OPTION_EXCEPTION_FREE_CODE ) ; if ( ssGetSizeofDWork (
S ) != sizeof ( hklldc0mgt ) ) { ssSetErrorStatus ( S ,
"Unexpected error: Internal DWork sizes do "
"not match for accelerator mex file." ) ; } if ( ssGetSizeofGlobalBlockIO ( S
) != sizeof ( kwbgjqm1wd ) ) { ssSetErrorStatus ( S ,
"Unexpected error: Internal BlockIO sizes do "
"not match for accelerator mex file." ) ; } { int ssSizeofParams ;
ssGetSizeofParams ( S , & ssSizeofParams ) ; if ( ssSizeofParams != sizeof (
eu5bvmyspd ) ) { static char msg [ 256 ] ; sprintf ( msg ,
"Unexpected error: Internal Parameters sizes do "
"not match for accelerator mex file." ) ; } } _ssSetDefaultParam ( S , (
real_T * ) & m2fl0tjmzk ) ; rt_InitInfAndNaN ( sizeof ( real_T ) ) ; ( (
eu5bvmyspd * ) ssGetDefaultParam ( S ) ) -> P_471 [ 60000 ] = rtNaN ; ( (
eu5bvmyspd * ) ssGetDefaultParam ( S ) ) -> P_472 [ 60000 ] = rtNaN ; }
static void mdlInitializeSampleTimes ( SimStruct * S ) { { SimStruct * childS
; SysOutputFcn * callSysFcns ; childS = ssGetSFunction ( S , 0 ) ;
callSysFcns = ssGetCallSystemOutputFcnList ( childS ) ; callSysFcns [ 3 + 0 ]
= ( SysOutputFcn ) ( NULL ) ; childS = ssGetSFunction ( S , 1 ) ; callSysFcns
= ssGetCallSystemOutputFcnList ( childS ) ; callSysFcns [ 3 + 0 ] = (
SysOutputFcn ) ( NULL ) ; childS = ssGetSFunction ( S , 2 ) ; callSysFcns =
ssGetCallSystemOutputFcnList ( childS ) ; callSysFcns [ 3 + 0 ] = (
SysOutputFcn ) ( NULL ) ; childS = ssGetSFunction ( S , 3 ) ; callSysFcns =
ssGetCallSystemOutputFcnList ( childS ) ; callSysFcns [ 3 + 0 ] = (
SysOutputFcn ) ( NULL ) ; childS = ssGetSFunction ( S , 4 ) ; callSysFcns =
ssGetCallSystemOutputFcnList ( childS ) ; callSysFcns [ 3 + 0 ] = (
SysOutputFcn ) ( NULL ) ; childS = ssGetSFunction ( S , 5 ) ; callSysFcns =
ssGetCallSystemOutputFcnList ( childS ) ; callSysFcns [ 3 + 0 ] = (
SysOutputFcn ) ( NULL ) ; } slAccRegPrmChangeFcn ( S , mdlOutputsTID8 ) ; }
static void mdlTerminate ( SimStruct * S ) { }
#include "simulink.c"
