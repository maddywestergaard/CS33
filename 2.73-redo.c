#include <stdio.h>
#include <limits.h>

_Bool __builtin_add_overflow_p (int x, int y, int *res);

int saturating_add(int x, int y)
{
  int maxShift = (8*sizeof(int)) - 1;
  int sum = x+y;
    
  int signX = !(!(x >> maxShift));
    
  return ( ((~(( __builtin_add_overflow_p (x,y, (__typeof__ ((x) + (y))) 0) & (signX==0)))+1)&INT_MAX) + ((~(( __builtin_add_overflow_p (x,y, (__typeof__ ((x) + (y))) 0) & (signX==1)))+1)&INT_MIN) + (((__builtin_add_overflow_p (x,y, (__typeof__ ((x) + (y))) 0)))&sum) );
}
