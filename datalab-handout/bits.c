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
  3. Has unpredictable behavior when shifting if the shift amount
     is less than 0 or greater than 31.


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

For the problems that require you to implement floating-point operations,
the coding rules are less strict.  You are allowed to use looping and
conditional control.  You are allowed to use both ints and unsigneds.
You can use arbitrary integer and unsigned constants. You can use any arithmetic,
logical, or comparison operations on int or unsigned data.

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
  2. Each function has a maximum number of operations (integer, logical,
     or comparison) that you are allowed to use for your implementation
     of the function.  The max operator count is checked by dlc.
     Note that assignment ('=') is not counted; you may use as many of
     these as you want without penalty.
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
//1
/* 
 * bitXor - x^y using only ~ and & 
 *   Example: bitXor(4, 5) = 1
 *   Legal ops: ~ &
 *   Max ops: 14
 *   Rating: 1
 */
int bitXor(int x, int y) {
  int left = ~(x & y);
  int right = ~(~x & ~y);
  return left & right;
}
/* 
 * tmin - return minimum two's complement integer 
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 4
 *   Rating: 1
 */
int tmin(void) {
  return 1 << 31;
}
//2
/*
 * isTmax - returns 1 if x is the maximum, two's complement number,
 *     and 0 otherwise 
 *   Legal ops: ! ~ & ^ | +
 *   Max ops: 10
 *   Rating: 1
 */
int isTmax(int x) {
  int y = x + 1;
  int z = x ^ y;
  int k = z ^ ~0;
  return !k & !!~x;
}
/* 
 * allOddBits - return 1 if all odd-numbered bits in word set to 1
 *   where bits are numbered from 0 (least significant) to 31 (most significant)
 *   Examples allOddBits(0xFFFFFFFD) = 0, allOddBits(0xAAAAAAAA) = 1
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 12
 *   Rating: 2
 */
int allOddBits(int x) {
  int y8 = 0xaa;
  int y16 = (y8 << 8) + y8;
  int y32 = (y16 << 16) + y16;
  int z = (x & y32) ^ y32;
  return !z;
}
/* 
 * negate - return -x 
 *   Example: negate(1) = -1.
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 5
 *   Rating: 2
 */
int negate(int x) {
  return ~x + 1;
}
//3
/* 
 * isAsciiDigit - return 1 if 0x30 <= x <= 0x39 (ASCII codes for characters '0' to '9')
 *   Example: isAsciiDigit(0x35) = 1.
 *            isAsciiDigit(0x3a) = 0.
 *            isAsciiDigit(0x05) = 0.
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 15
 *   Rating: 3
 */
int isAsciiDigit(int x) {
  int a0 = x >> 4;
  /* 0x0000003 */
  int a1 = a0 ^ 0x3;
  int b0 = x & 0xf;
  /* 0b0xxx */
  int b1 = b0 >> 3;
  int c0 = b0 >> 1;
  /* 0b100x */
  int c1 = c0 ^ 0x4;
  return !a1 & (!b1 | !c1);
}
/* 
 * conditional - same as x ? y : z 
 *   Example: conditional(2,4,5) = 4
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 16
 *   Rating: 3
 */
int conditional(int x, int y, int z) {
  int a0 = !x;
  int b0 = !!x;
  int a1 = ~a0 + 1;
  int b1 = ~b0 + 1;
  return (b1 & y) | (a1 & z);
}
/* 
 * isLessOrEqual - if x <= y  then return 1, else return 0 
 *   Example: isLessOrEqual(4,5) = 1.
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 24
 *   Rating: 3
 */
int isLessOrEqual(int x, int y) {
  int a = ~y + 1;
  /* x - y */
  int b = x + a;
  int b2 = !b | ((b >> 31) & 1);
  int xf = (x >> 31) & 1;
  int yf = (y >> 31) & 1;
  /* x < 0 and y >= 0 */
  int c = ((xf ^ yf) & xf);
  /* x >= 0 and y < 0 */
  int d = ((xf ^ yf) & yf);
  int e = !d;
  return e & (c | b2);
}
//4
/* 
 * logicalNeg - implement the ! operator, using all of 
 *              the legal operators except !
 *   Examples: logicalNeg(3) = 0, logicalNeg(0) = 1
 *   Legal ops: ~ & ^ | + << >>
 *   Max ops: 12
 *   Rating: 4 
 */
int logicalNeg(int x) {
  int y = ~x + 1;
  /* z is 0 when x is 0 or 0b10...0 otherwise z is 0b1...10...0. */
  int z = x ^ y;
  int a = ~(x >> 31) & 1;
  int b = ~(z >> 31) & 1;
  return a & b;
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
  int mask31 = (1 << 31) + ~0;
  int xf = (x >> 31) & 1;
  /* Zero the sign bit */
  int y = x & mask31;
  int flag = ~(xf + ~0);
  int maskh16, maskh8, maskh4, maskh2, maskh1;
  int a16, a8, a4, a2, a1, a0;

  /* 0b1a...a -> 0b0b...b and b = ~a */
  /* 0b0a...a -> 0b0a...a */
  y ^= mask31 & flag;

  /* binary search */

  maskh16 = ((1 << 16) + ~0);
  maskh16 = maskh16 << 16;
  a16 = !!(y & maskh16) << 4;
  y = y >> a16;

  maskh8 = ((1 << 8) + ~0) << 8;
  a8 = !!(y & maskh8) << 3;
  y = y >> a8;

  maskh4 = ((1 << 4) + ~0) << 4;
  a4 = !!(y & maskh4) << 2;
  y = y >> a4;

  maskh2 = ((1 << 2) + ~0) << 2;
  a2 = !!(y & maskh2) << 1;
  y = y >> a2;

  maskh1 = 0x2;
  a1 = !!(y & maskh1);
  y = y >> a1;

  a0 = y;

  return 1 + a16 + a8 + a4 + a2 + a1 + a0;
}
//float
/* 
 * floatScale2 - Return bit-level equivalent of expression 2*f for
 *   floating point argument f.
 *   Both the argument and result are passed as unsigned int's, but
 *   they are to be interpreted as the bit-level representation of
 *   single-precision floating point values.
 *   When argument is NaN, return argument
 *   Legal ops: Any integer/unsigned operations incl. ||, &&. also if, while
 *   Max ops: 30
 *   Rating: 4
 */
unsigned floatScale2(unsigned uf) {
  unsigned s = uf >> 31;
  unsigned exp_mask = 0xff;
  unsigned exp = (uf >> 23) & exp_mask;
  unsigned frac_mask = 0x7fffff;
  unsigned frac = uf & frac_mask;
  if (exp == 0) {
    // Denormalized values
    frac += frac;
    if (frac > frac_mask) {
      frac &= frac_mask;
      exp = 1;
    }
    return (s << 31) | (exp << 23) | frac;
  } else if (exp == exp_mask) {
    // NaN or +/- infinity
    return uf;
  } else {
    // Normalized values
    ++exp;
    if (exp >= exp_mask) {
      return (s << 31) | (exp_mask << 23);
    }
    return (s << 31) | (exp << 23) | frac;
  }
}
/* 
 * floatFloat2Int - Return bit-level equivalent of expression (int) f
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
int floatFloat2Int(unsigned uf) {
  unsigned exp_mask = 0xff;
  unsigned frac_mask = 0x7fffff;
  unsigned s = uf >> 31;
  unsigned exp = (uf >> 23) & exp_mask;
  unsigned frac = uf & frac_mask;
  unsigned bound = 0x80000000;

  if (exp == 0) {
    // Denormalized values
    return 0;
  } else if (exp == exp_mask) {
    // Infinity or Nan
    return 0x80000000;
  } else {
    // Normalized values
    unsigned bias = 127;
    int E = exp - bias;
    if (E < -1) {
      return 0;
    } else if (E == - 1) {
      if (frac == 0) {
        return s ? -1 : 1;
      }
      return 0;
    } else {
      frac |= 0x800000;
      if (E >= 23) {
        if (E - 23 > 8) {
          return 0x80000000;
        }
        frac <<= E - 23;
        if (s) {
          if (frac > bound) {
            return 0x80000000;
          }
          return -frac;
        } else {
          if (frac >= bound) {
            return 0x80000000;
          }
          return frac;
        }
      } else {
        frac >>= 23 - E;
        return s ? -frac : frac;
      }
    }
  }
}
/* 
 * floatPower2 - Return bit-level equivalent of the expression 2.0^x
 *   (2.0 raised to the power x) for any 32-bit integer x.
 *
 *   The unsigned value that is returned should have the identical bit
 *   representation as the single-precision floating-point number 2.0^x.
 *   If the result is too small to be represented as a denorm, return
 *   0. If too large, return +INF.
 * 
 *   Legal ops: Any integer/unsigned operations incl. ||, &&. Also if, while 
 *   Max ops: 30 
 *   Rating: 4
 */
unsigned floatPower2(int x) {
  unsigned exp_mask = 0xff;
  unsigned f_zero = 0;
  unsigned f_inf = exp_mask << 23;
  int bias = 127;

  if (x < 1 - bias - 23) {
    // Result is too small
    return f_zero;
  }

  if (x > 254 - bias) {
    // Result is too large
    return f_inf;
  }

  if (x < 1 - bias) {
    // Denormalized values
    unsigned y = 1 - bias - x;
    return 1 << y;
  } else {
    // Normalized values
    unsigned exp = (bias + x) & exp_mask;
    return exp << 23;
  }
}
