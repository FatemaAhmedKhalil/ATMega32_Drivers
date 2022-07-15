#ifndef BITOPERATIONS_H_INCLUDED
#define BITOPERATIONS_H_INCLUDED

#define SET_BIT(x,BIT)    x|=(1<<BIT)
#define CLR_BIT(x,BIT)    x&=(~(1<<BIT))
#define TOGGLE_BIT(x,BIT) x^=(1<<BIT)
#define GET_BIT(x,BIT)    (x>>BIT)&1

#endif
