/* 
 * CS:APP Data Lab 
 * 
 * Madison Westergaard
 UID: 004903420
 * 
 * bits.c - Source file with your solutions to the Lab.
 *          This is the file you will hand in to your instructor.
 *
 * WARNING: Do not include the <stdio.h> header; it confuses the dlc
 * compiler. You can still use printf for debugging without including
 * <stdio.h>, although you might get a compiler warning. In general,
 * it's not good practice to ignore compiler warnings, but in this
 * case it's OK.  
 */

#if 0
/*
 * Instructions to Students:
 *
 * STEP 1: Read the following instructions carefully.
 */

You will provide your solution to the Data Lab by
editing the collection of functions in this source file.

INTEGER CODING RULES:
 
  Replace the "return" statement in each function with one
  or more lines of C code that implements the function. Your code 
  must conform to the following style:
 
  int Funct(arg1, arg2, ...) {
      /* brief description of how your implementation works */
      int var1 = Expr1;
      ...
      int varM = ExprM;

      varJ = ExprJ;
      ...
      varN = ExprN;
      return ExprR;
  }

  Each "Expr" is an expression using ONLY the following:
  1. Integer constants 0 through 255 (0xFF), inclusive. You are
      not allowed to use big constants such as 0xffffffff.
  2. Function arguments and local variables (no global variables).
  3. Unary integer operations ! ~
  4. Binary integer operations & ^ | + << >>
    
  Some of the problems restrict the set of allowed operators even further.
  Each "Expr" may consist of multiple operators. You are not restricted to
  one operator per line.

  You are expressly forbidden to:
  1. Use any control constructs such as if, do, while, for, switch, etc.
  2. Define or use any macros.
  3. Define any additional functions in this file.
  4. Call any functions.
  5. Use any other operations, such as &&, ||, -, or ?:
  6. Use any form of casting.
  7. Use any data type other than int.  This implies that you
     cannot use arrays, structs, or unions.

 
  You may assume that your machine:
  1. Uses 2s complement, 32-bit representations of integers.
  2. Performs right shifts arithmetically.
  3. Has unpredictable behavior when shifting an integer by more
     than the word size.

EXAMPLES OF ACCEPTABLE CODING STYLE:
  /*
   * pow2plus1 - returns 2^x + 1, where 0 <= x <= 31
   */
  int pow2plus1(int x) {
     /* exploit ability of shifts to compute powers of 2 */
     return (1 << x) + 1;
  }

  /*
   * pow2plus4 - returns 2^x + 4, where 0 <= x <= 31
   */
  int pow2plus4(int x) {
     /* exploit ability of shifts to compute powers of 2 */
     int result = (1 << x);
     result += 4;
     return result;
  }

FLOATING POINT CODING RULES

For the problems that require you to implent floating-point operations,
the coding rules are less strict.  You are allowed to use looping and
conditional control.  You are allowed to use both ints and unsigneds.
You can use arbitrary integer and unsigned constants.

You are expressly forbidden to:
  1. Define or use any macros.
  2. Define any additional functions in this file.
  3. Call any functions.
  4. Use any form of casting.
  5. Use any data type other than int or unsigned.  This means that you
     cannot use arrays, structs, or unions.
  6. Use any floating point data types, operations, or constants.


NOTES:
  1. Use the dlc (data lab checker) compiler (described in the handout) to 
     check the legality of your solutions.
  2. Each function has a maximum number of operators (! ~ & ^ | + << >>)
     that you are allowed to use for your implementation of the function. 
     The max operator count is checked by dlc. Note that '=' is not 
     counted; you may use as many of these as you want without penalty.
  3. Use the btest test harness to check your functions for correctness.
  4. Use the BDD checker to formally verify your functions
  5. The maximum number of ops for each function is given in the
     header comment for each function. If there are any inconsistencies 
     between the maximum ops in the writeup and in this file, consider
     this file the authoritative source.
 */
/*
 * STEP 2: Modify the following functions according the coding rules.
 * 
 *   IMPORTANT. TO AVOID GRADING SURPRISES:
 *   1. Use the dlc compiler to check that your solutions conform
 *      to the coding rules.
 *   2. Use the BDD checker to formally verify that your solutions produce 
 *      the correct answers.
 */


#endif
/* 
 * bang - Compute !x without using !
 *   Examples: bang(3) = 0, bang(0) = 1
 *   Legal ops: ~ & ^ | + << >>
 *   Max ops: 12
 *   Rating: 4 
 */

int bang(int x) {
/*   
   find the negative of x, then take the XOR of the negative with the x. The first bit will be 0 if x is zero (since negating it doesnt do anything) and will be 1 for all other numbers. Right shifting by 31 isolates the first bit and will have a value of 0 if x is zero and -1 if not. Adding one to that will return the value we need. 
*/
   int neg = ~x + 1;
   int isZero = (x ^ neg) >> 31;
   return (1+isZero)&(~(x>>31)) ;
}

/*
 * bitCount - returns count of number of 1's in word
 *   Examples: bitCount(5) = 2, bitCount(7) = 3
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 40
 *   Rating: 4
 */
int bitCount(int x) 
{
  /*
    make mask that has 0001 repeated through 8 bytes. AND that with x, then shift x right one and then AND it again, then right shift one more and AND it, then one last time. this will give 0001 for each occurance of 1, in 4 different numbers. adding them together gets the sum of each byte in x in the corresponding byte of the sum variable. to find the actual sum, we have to add each byte together. 

*/
  int mask = (17<<24)+(17<<16)+(17<<8)+17;

  int x1 = x&mask;
  int x2 = (x>>1)&mask;
  int x3 = (x>>2)&mask;
  int x4 = (x>>3)&mask;
  int sum = x1 + x2 + x3 + x4;
  
  return ((sum>>28)&15) + ((sum>>24)&15) + ((sum>>20)&15) + ((sum>>16)&15) + ((sum>>12)&15) + ((sum>>8)&15) + ((sum>>4)&15) + (sum&15);
}

/* 
 * bitOr - x|y using only ~ and & 
 *   Example: bitOr(6, 5) = 7
 *   Legal ops: ~ &
 *   Max ops: 8
 *   Rating: 1
 */
int bitOr(int x, int y) {
/*
  or can be calculated by Not-ing x, then not-ing y, then and-ing them, then not-ing that.
 */

  return ~((~x)&(~y));
}
/*
 * bitRepeat - repeat x's low-order n bits until word is full.
 *   Can assume that 1 <= n <= 32.
 *   Examples: bitRepeat(1, 1) = -1
 *             bitRepeat(7, 4) = 0x77777777
 *             bitRepeat(0x13f, 8) = 0x3f3f3f3f
 *             bitRepeat(0xfffe02, 9) = 0x10080402
 *             bitRepeat(-559038737, 31) = -559038737
 *             bitRepeat(-559038737, 32) = -559038737
 *   Legal ops: int and unsigned ! ~ & ^ | + - * / % << >>
 *             (This is more general than the usual integer coding rules.)
 *   Max ops: 40

 *   Rating: 4
 */

int bitRepeat(int x, int n) {
  /*
    the mask has a 1 in all the spots of x that is going to be repeated, and a zero in all others. and-ing that with x gets the pattern that will be repeated. then shifting that by the number of bits being repeated then adding it to the mask gets the pattern repeated twice. This process is repeated until n has been multiplied by 32. But to check that it is not overflowing, an overflow value is compared against the new answer. the overflow will return -1 if it is not overflow and 0 if it is. if 31 subtracted by the shift is negative, then it has overflowed, and will return 0.

*/
  int zero = (!(n^32)-1);
  int mask = ((1 << n) -1);
  int xmask = mask & x;
  int ans = (xmask << n) + xmask;
  
  int shift1 = n<<1;
  int shift2 = n<<2;
  int shift3 = n<<3;
  int shift4 = n<<4;

  int overflow = ~(((31-(shift1))>>31));
  ans = (overflow&(ans << (shift1))) + ans;

  overflow = ~(((31-(shift2))>>31));
  ans = (overflow & (ans << (shift2))) + ans;

  overflow = ~(((31-(shift3))>>31));
  ans = (overflow & (ans << (shift3))) + ans; 

  overflow = ~(((31-(shift4))>>31));
  ans = (overflow & (ans << (shift4))) + ans;

  return (ans + ((~zero)&x));
}

/* 
 * fitsBits - return 1 if x can be represented as an 
 *  n-bit, two's complement integer.
 *   1 <= n <= 32
 *   Examples: fitsBits(5,3) = 0, fitsBits(-4,3) = 1
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 15
 *   Rating: 2
 */

int fitsBits(int x, int n) {
  /*
  the shift2 is left shifted by 32-n, then right shifted by the same amount to erase the bits left of n. then XOR-ing that with x will return 0 if they are equal, then not-ing it will return 1. if they are not equal, that means that x cannot fit in n amount of bits, and the return statement will return 0.

*/
  int shift2 = (x << (32+(~n+1)))>>(32+(~n+1));
   return !(shift2^x);
}

/* 
 * getByte - Extract byte n from word x
 *   Bytes numbered from 0 (LSB) to 3 (MSB)
 *   Examples: getByte(0x12345678,1) = 0x56
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 6
 *   Rating: 2
 */
int getByte(int x, int n) {
/*
   n<<3 multiplies n by 8, which converts bytes to bits. then right shifting x by that amount gets the byte that you want to the far right. Then and-ing with 255 isolates that byte. 
*/
  return ( (x>> (n<<3))& 255);
}
/* 
 * isLessOrEqual - if x <= y  then return 1, else return 0 
 *   Example: isLessOrEqual(4,5) = 1.
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 24
 *   Rating: 3
 */
int isLessOrEqual(int x, int y) {
/*
  the negative of x is determined, then added to y to get (y-x). if this value is negative, then x is greater than y. The sign bit of the difference is isolated and returned.
*/
  int negX = (~x + 1);
  int diff = negX + y;
  int sign = !( diff>>31);

  int xSign = (((1<<31)&x)>>31)&1;
  int ySign = (((1<<31)&y)>>31)&1;
  int opp = xSign^ySign;

  return ((opp & (xSign)) | ((!opp) &sign));
}

/* 
 * isPositive - return 1 if x > 0, return 0 otherwise 
 *   Example: isPositive(-1) = 0.
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 8
 *   Rating: 3
 */

int isPositive(int x) {
  /*
     the sign of x is determined by shifting right 31 bits to get -1 if the value is negative and 0 if its positive. that value is then sumed with 1 to get 1 if it is positive and 0 if its negative. Then x is checked to see if it is zero, and if it is, will return 1.
   */
  int signX = ((x>>31)+1);
  return ((signX) & ( ~(~(!(x^0)) + 1)));
}

/* 
 * logicalShift - shift x to the right by n, using a logical shift
 *   Can assume that 0 <= n <= 31
 *   Examples: logicalShift(0x87654321,4) = 0x08765432
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 20
 *   Rating: 3 
 */
int logicalShift(int x, int n) {
  /*
this shift uses the arithmetic right shift, then creates a mask that keeps the original value of x, and makes the part that was shifted zero using the and operator.
*/

  int xsra = x>>n;
  int mask = (1 << (32+(~n+1))) + (~1+1);
  return (xsra & mask) + ( (~(!(n^0))+1)&x  );

}
/* 
 * tmin - return minimum two's complement integer 
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 4
 *   Rating: 1
 */
int tmin(void) {
/*
  takes -1, which is 0x11111111, then left shift it by 31 to get the min value.
*/

  int min = ~0;
  return (min<<31);
  
}
