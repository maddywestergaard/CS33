#include <stdio.h>
#include <gnu/stubs-32.h>

unsigned long srl (unsigned long x, int k) //logical
{
  unsigned xsra = (int) x>>k;
  int shift = 8*sizeof(int) - k;
  unsigned mask = (1 << shift) - 1;
  return xsra & mask;
}

long sra(long x, int k) //arithmetically
{
  int xsrl = (unsigned) x>>k;
  int w = 8*sizeof(int)-1;

  unsigned shift = 8*sizeof(int) - k;
  unsigned sign = !((!(1 << w)) & x);
  unsigned mask = ~(sign-1) << shift;
  return (mask | xsrl);
}

