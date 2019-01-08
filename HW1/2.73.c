#include <stdio.h>
#include <limits.h>

int saturating_add(int x, int y)
{
  int maxShift = (8*sizeof(int)) - 1;
  int sum = x+y;

  int signX = !(!(x >> maxShift));
  int signY = !(!(y >> maxShift));
  int signSum = !(!(sum >> maxShift));
    
  int negOver = ((signX == 1)& (signY == 1) & (signSum == 0));
  int posOver = ((signX == 0) & (signY == 0) & (signSum == 1));
    
  return ( (((~posOver+1))&INT_MAX) + (((~negOver+1))&INT_MIN) + ((~(!(negOver|posOver)) + 1)&sum) );
}
