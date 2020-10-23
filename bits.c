/* 
 * CS:APP Data Lab 
 * 
 * <Please put your name and userid here>
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
/* Copyright (C) 1991-2018 Free Software Foundation, Inc.
   This file is part of the GNU C Library.

   The GNU C Library is free software; you can redistribute it and/or
   modify it under the terms of the GNU Lesser General Public
   License as published by the Free Software Foundation; either
   version 2.1 of the License, or (at your option) any later version.

   The GNU C Library is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
   Lesser General Public License for more details.

   You should have received a copy of the GNU Lesser General Public
   License along with the GNU C Library; if not, see
   <http://www.gnu.org/licenses/>.  */
/* This header is separate from features.h so that the compiler can
   include it implicitly at the start of every compilation.  It must
   not itself include <features.h> or any other header that includes
   <features.h> because the implicit include comes before any feature
   test macros that may be defined in a source file before it first
   explicitly includes a system header.  GCC knows the name of this
   header in order to preinclude it.  */
/* glibc's intent is to support the IEC 559 math functionality, real
   and complex.  If the GCC (4.9 and later) predefined macros
   specifying compiler intent are available, use them to determine
   whether the overall intent is to support these features; otherwise,
   presume an older compiler has intent to support these features and
   define these macros by default.  */
/* wchar_t uses Unicode 10.0.0.  Version 10.0 of the Unicode Standard is
   synchronized with ISO/IEC 10646:2017, fifth edition, plus
   the following additions from Amendment 1 to the fifth edition:
   - 56 emoji characters
   - 285 hentaigana
   - 3 additional Zanabazar Square characters */
/* We do not support C11 <threads.h>.  */
/* 
 * evenBits - return word with all even-numbered bits set to 1
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 8
 *   Rating: 1
 */
int evenBits(void) {
  /**
   * 利用0x55逐次扩展
  */
  int res = 0x55;
  res += res << 8;
  res += res << 16;
  return res;
}
/* 
 * isEqual - return 1 if x == y, and 0 otherwise 
 *   Examples: isEqual(5,5) = 1, isEqual(4,5) = 0
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 5
 *   Rating: 2
 */
int isEqual(int x, int y) {
  /**
   * 异或取非
  */
  int res = !(x ^ y);
  return res;
}
/* 
 * byteSwap - swaps the nth byte and the mth byte
 *  Examples: byteSwap(0x12345678, 1, 3) = 0x56341278
 *            byteSwap(0xDEADBEEF, 0, 2) = 0xDEEFBEAD
 *  You may assume that 0 <= n <= 3, 0 <= m <= 3
 *  Legal ops: ! ~ & ^ | + << >>
 *  Max ops: 25
 *  Rating: 2
 */
int byteSwap(int x, int n, int m) {
  /**
   * first we need sn, sm 
   * which are the numbers we use to get the correspond bytes
   * then we get maskn, maskm
   * which are the mask to get cn, cm
   * cn, cm are the bytes in the nth and mth position
   * then we use mask to let nth and mth to be zero
   * then we use "or" operation to place cn, cm to the right positon
  */
  // int sn = n << 3;
  // int sm = m << 3;
  // int maskn = 0xff << sn;
  // int maskm = 0xff << sm;
  // int shift = sn + ~sm + 1;
  // int cn = (x >> sn) & 0xff;
  // int cm = (x >> sm) & 0xff;

  // x &= ~(maskn | maskm);
  // x |= (cn << sm | cm << sn);
  int sn = n << 3;
  int sm = m << 3;
  int mask = ((x >> sn) ^ (x >> sm)) & 0xff;
  x = x ^ (mask << sn | mask << sm);
  return x;
}
/* 
 * rotateRight - Rotate x to the right by n
 *   Can assume that 0 <= n <= 31
 *   Examples: rotateRight(0x87654321,4) = 0x76543218
 *   Legal ops: ~ & ^ | + << >> !
 *   Max ops: 25
 *   Rating: 3 
 */
int rotateRight(int x, int n) {
  /**
   * first we get the mask
   * whose lower n bits are set to 1
   * then we get the value which will lost in the Rshift process
   * then we use or operation to get final result
  */
  // int mask = (1 << n) + ~0;
  // int val = x & mask;
  // int shift = 33 + ~n;

  // x = x >> n;
  // x &= ~(mask << shift);
  // x |= val << shift;
  // return x;
  int tmp = x, mask, shift;
  x >>= n;
  shift = 33 + ~n;
  mask = ((tmp << shift) ^ x) >> shift; 
  x = x ^ (mask << shift);
  return x;
}
/* 
 * logicalNeg - implement the ! operator, using all of 
 *              the legal operators except !
 *   Examples: logicalNeg(3) = 0, logicalNeg(0) = 1
 *   Legal ops: ~ & ^ | + << >>
 *   Max ops: 12
 *   Rating: 4 
 */
int logicalNeg(int x) {
  /**
   * first we need unsigned to Rshift
   * then if a number is not zero the it has exactly one opposite number
   * so the highest bit or must be 1
   * then trans 1 to 0 and 0 to 1
   * OK!!!(don't mind my chinglish)
  */
  int nx = ~x + 1;
  int res = (x | nx) >> 31;
  return (res + 1);
}
/* 
 * TMax - return maximum two's complement integer 
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 4
 *   Rating: 1
 */
int tmax(void) {
  /**
   * nothing much to say about this
  */
  int res = ~(1 << 31);
  return res;
}
/* 
 * sign - return 1 if positive, 0 if zero, and -1 if negative
 *  Examples: sign(130) = 1
 *            sign(-23) = -1
 *  Legal ops: ! ~ & ^ | + << >>
 *  Max ops: 10
 *  Rating: 2
 */
int sign(int x) {
  /**
   * if negtive
   * flag will be 0xffffffff which is -1
   * if positive 
   * fisrt flag = 0
   * iszero will be 1 if not 0, 0 if 0
   * the return flag | iszero
   * OK!!!
  */
  int flag = x >> 31;
  int iszero = !!(x);
  return flag | iszero;
}
/* 
 * isGreater - if x > y  then return 1, else return 0 
 *   Example: isGreater(4,5) = 0, isGreater(5,4) = 1
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 24
 *   Rating: 3
 */
int isGreater(int x, int y) {
  /**
   * test if y - x < 0?
   * there are 3 conditions:
   *  same sign
   *  y is positve and x is negtive
   *  y is negtive and x is positve
   * just figure out the relation between 3 conditions
   * then it is solved
  */

  /* version 1.0 ops 11 */
  // int sub = y + ~x + 1;
  // int pos = (~x) | y;
  // int neg = y & (~x);
  // return (((sub & pos) | neg) >> 31) & 1;

  /* version 1.1 ops 10 */
  // int sub = y + ~x + 1;
  // int sign = x ^ y;
  // return (((~sign & sub) | (sign & y)) >> 31) & 1;

  /* version 1.2 ops 4 */
  /**
   * first we expand x, y to 64 bits
   * then compute res = x - 1 - y
   * if res >= 0, then return 1
   * else return 0 
  */
  long long a = x;
  long long b = y;
  int z = (a + ~b) >> 63;
  return z + 1;
  /* version 1.3 7 ops */
  // return ((x + ~(((x ^ y) >> 31) | y)) >> 31) + 1;
}
/* 
 * subOK - Determine if can compute x-y without overflow
 *   Example: subOK(0x80000000,0x80000000) = 1,
 *            subOK(0x80000000,0x70000000) = 0, 
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 20
 *   Rating: 3
 */
int subOK(int x, int y) {
  /**
   * fist we should get 3 signs
   * sub sign
   * x sign
   * y sign
   * only if x_s diff with y_s and x_s diff with sub_s
   * the sub will be wrong
   * so let it be logical expression
   * OK
  */
  int sub = x + ~y + 1;
  return !(((x ^ y) & (x ^ sub)) >> 31);

  /* version 1.1 ops 4 */
  // long long a = x;
  // long long b = y;
  // long long z = ~a + b;
  // int z2;
  // z2 = z;
  // return !(z2 ^ z);
}
/*
 * satAdd - adds two numbers but when positive overflow occurs, returns
 *          maximum possible value, and when negative overflow occurs,
 *          it returns minimum positive value.
 *   Examples: satAdd(0x40000000,0x40000000) = 0x7fffffff
 *             satAdd(0x80000000,0xffffffff) = 0x80000000
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 30
 *   Rating: 4
 */
int satAdd(int x, int y) {
  /**
   * fist we get the max, min to be used later
   * then we get add result
   * there is 2 overflow conditions:
   *  1: pos pos neg
   *  2: neg neg pos
   * when overflow occurs we should
   *  1: set res to zero
   *  2: set res to max/min
   * for example:
   * we use res & ~p_o to make sure 
   * when pos overflow occurs, res will be zero
   * then we use res |= p_o & max
   * p_o & max will be max only if p_o equals 0xffffffff
   * that's when pos overflow occurs
  */
  /* version 1.0 */
  // int min = 1 << 31;
  // int max = ~min;
  // int add = x + y;
  // int p_o = (~x & ~y & add) >> 31;
  // int n_o = (x & y & ~add) >> 31;
  // int res = add & ~(p_o | n_o);
  // res |= p_o & max;
  // res |= n_o & min;
  // return res;
  /* verison 1.1 */
  /**
   * first we get add = x + y
   * overFlow = 11...111 if overflow occurs
   * 0x7fff ffff = 0111 ... 1111
   * 0x8000 0000 = 1000 ... 0000
   * if pos overflow , sign(add) = 1, add >> 31 + 1000 ... 0000 = 0x7fff ffff
   * if neg overflow , sign(add) = 0, add >> 31 + 1000 ... 0000 = 0x8000 0000
   * then it is solved
  */
  int add = x + y;
	int overFlow = ((x ^ add) & (y ^ add)) >> 31;
	return (add >> (overFlow & 31)) + (overFlow << 31);
}
/* howManyBits - return the minimum number of bits required to represent x in
 *             two's complement
 *  Examples: howManyBits(12) = 5
 *            howManyBits(298) = 10
 *            howManyBits(-5) = 4
 *            howManyBits(0)  = 1
 *            howManyBits(-1) = 1
 *            howManyBits(0x80000000) = 32
 *  Legal ops: ! ~ & ^ | + << >>
 *  Max ops: 90
 *  Rating: 4
 */
int howManyBits(int x) {
  /**
   * first we should we one important thins:
   *  if negative , we choose ~x
   *  this is because we want to find the first 1 in x's two's complement
   * so see this case:
   *  num   pos   ans
   *    1     1     2
   *    0     0     1
   * and this case:
   *  num: xy
   *  we should figure out where first 1 is
   *  1. ans = (x >> 1);   
   *  2. ans += (x >> ans);  //ans is the offset
   * we can see, if there is only one bit, ans = num + 1
   * so we expand to 32 bits
   * 1. check if first 1 is in first 16 bits
   * 2. repeat until there is only 1 bit
   * 3. use the fomula above ans = num + 1
   * 4. finish
  */

  /* version 1.0 ops 30 */
  int sign = x >> 31;
  int res = 0;
  // x = (x & ~sign) | (sign & ~x);
  x = x ^ sign;
  res = !!(x >> 16) << 4;
  res += !!(x >> (8 + res)) << 3;
  res += !!(x >> (4 + res)) << 2;
  res += !!(x >> (2 + res)) << 1;
  res += (x >> (1 + res));
  res += (x >> res);
  res += 1;
  return res;

  /* version 1.1 ops 21 */
  // int global_4 = ~0x5B;   //1111 1111 1111 1010 0100
  // int ans;
  // long long y = x;        // need 1 more op only using int
  // y = y ^ (y << 2);                               // y = 1 ^ 1 << 2 = 1 ^ 100 = 101
  // ans = (!(y >> 17)) << 4;                        // ans = 16 
  // ans ^= 25;                                      // ans = 16 ^ 25 = 10000 ^ 11001 = 01001 = 9
  // ans ^= (!(y >> ans)) << 3;                      // ans = 9 ^ 8 = 0001
  // ans ^= 4;                                       // ans = 4 ^ 1 = 100 ^ 001 = 101 = 5
  // ans ^= (!(y >> ans)) << 2;                      // ans = 5 ^ 4 = 101 ^ 100 = 001
  // ans += (global_4 >> ((y >> ans) & 30)) & 3;     // ans = 1 + (1...0100 >> ((101 >> 1) & 30)) & 3 = 
  // return ans;
}
/*
 * ilog2 - return floor(log base 2 of x), where x > 0
 *   Example: ilog2(16) = 4
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 90
 *   Rating: 4
 */
int ilog2(int x) {
  /**
   * to solve this problem
   * see this case first:
   *  xy
   * in this case, there is only two bits
   * how do we compute ilog2(xy) ?
   * ilog2(y) = 0 (only 1 bit)
   * ilog2(xy) = x = xy >> 1
   * so here comes the idea
   * 1. judge if x > 2 ^ 16                     xxxxxxxx xxxxxxxx
   *    if true then res += 16, else res += 0
   * 2. judge if x > 2 ^ (8 + res)                       xxxxxxxx
   *    by doing this, we divide the problem to 8bits
   * 3. ...
   * 4. at last, we divide the problem to 2bits
   * 5. use the conclusion above, res += (x >> (1 + res))
   * notice:
   * !!(x) = 0 if x = 0, 1 if x != 0 
   * in each step, res can be seen as a offset
  */
  int res = 0;
  res = !!(x >> 16) << 4;
  res += !!(x >> (8 + res)) << 3;
  res += !!(x >> (4 + res)) << 2;
  res += !!(x >> (2 + res)) << 1;
  res += (x >> (1 + res));
  return res;
}
/* 
 * float_half - Return bit-level equivalent of expression 0.5*f for
 *   floating point argument f.
 *   Both the argument and result are passed as unsigned int's, but
 *   they are to be interpreted as the bit-level representation of
 *   single-precision floating point values.
 *   When argument is NaN, return argument
 *   Legal ops: Any integer/unsigned operations incl. ||, &&. also if, while
 *   Max ops: 30
 *   Rating: 4
 */
unsigned float_half(unsigned uf) {
  /**
   * 1. check whether uf is NaN / INF
   * 2. check whether uf is non-formal
   * 3. if !ep then just let sigificant divided by 2
   * 4. if exponent = 1, then 
   *    1. let sigificant divided by 2 considering there is a implicit 1
   *    2. exponent = 0
   * 5. others : exponent -= 1
  */
  unsigned ep, tmp;
  ep = uf & 0x7f800000;
  if (ep == 0x7f800000) return uf;
  tmp = (((uf & 0x00ffffff)) >> 1) + ((uf & 3) == 3);
  if (ep <= 0x00800000) return tmp | (uf & 0x80000000);
  return uf - 0x00800000;
}
/* 
 * float_f2i - Return bit-level equivalent of expression (int) f
 *   for floating point argument f.
 *   Argument is passed as unsigned int, but
 *   it is to be interpreted as the bit-level representation of a
 *   single-precision floating point value.
 *   Anything out of range (including NaN and infinity) should return
 *   0x80000000u.
 *   Legal ops: Any integer/unsigned operations incl. ||, &&. also if, while
 *   Max ops: 30
 *   Rating: 4
 */
int float_f2i(unsigned uf) {
  /**
   * 1. get exponent
   * 2. if exponent > 150 then it will overflow
   *    that's because 1.xxxx * 2 ^ (ep - 127), ep - 127 <= 
   * 3. if exponent < 127 then it will be zero
   * 4. then it will be easy:
   * 5. let lowest bit of exponent be 1
   * 6. let the bit and the significant Rshift by 150 - ep
   * 7. if negtative, res = -res
   * 1 8 23
   * 1.xxxxx
   * 23 - (ep - 127)
   * 150 - ep
   * ep - 127 <= 23
   * ep <= 150
  */
  int ep;
  int res;
  ep = (uf & 0x7f800000) >> 23;
  if (ep > 150) return 0x80000000u;
  if (ep < 127) return 0;
  res = ((uf & 0x007fffff) | 0x00800000) >> (150 - ep);
  if (uf & 0x80000000) res = -res;
  return res;
}
/* 
 * float_twice - Return bit-level equivalent of expression 2*f for
 *   floating point argument f.
 *   Both the argument and result are passed as unsigned int's, but
 *   they are to be interpreted as the bit-level representation of
 *   single-precision floating point values.
 *   When argument is NaN, return argument
 *   Legal ops: Any integer/unsigned operations incl. ||, &&. also if, while
 *   Max ops: 30
 *   Rating: 4
 */
unsigned float_twice(unsigned uf) {
  /**
   * first we get exponent
   * then check if uf is NaN or INF
   * then check if exponent if 0, if not
   * let exponent increase by 1
   * if 0, let significant Lshift by 1 and reserve it's sign bit
  */
  int ep = uf & 0x7f800000;
  if (ep == 0x7f800000) return uf;
  if (ep) return uf + 0x00800000; 
  return (uf << 1) | (uf & 0x80000000);
}
