// realization of instrumentation in C
// header part

#ifndef __COV_H
#define __COV_H

extern unsigned char coveragedata[];
#define ICOV(x) coveragedata[x>>3]|=1<<(x&7)
#define BCOV(x) (ICOV(x),1)

#endif

