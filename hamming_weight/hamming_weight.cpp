// hamming_weight.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "hamming_weight.h"

int _tmain(int argc, _TCHAR* argv[])
{
  // http://en.wikipedia.org/wiki/Hamming_weight
  // count the number of ones in a binary number ("pop count")

  int x = 5;
  int res1 = NumberOfSetBits(x);
  int res2 = NumberOfSetBitsProDebug(x);

  return 0;
}

int NumberOfSetBits(int i)
{
  i = i - ((i >> 1) & 0x55555555);
  i = (i & 0x33333333) + ((i >> 2) & 0x33333333);
  return (((i + (i >> 4)) & 0x0F0F0F0F) * 0x01010101) >> 24;
}

int NumberOfSetBitsProDebug(int input)
{
  int a = (input >> 1);
  int b = (a & 0x55555555); // binary: 1010101010101010101010101010101
  int c = input - b;

  int d = (c & 0x33333333); // binary: 110011001100110011001100110011
  int e = ((c >> 2) & 0x33333333); 

  int f = d + e;
  
  int g = f >> 4;
  int h = f + g;

  int i = (h & 0x0F0F0F0F); // binary: 1111000011110000111100001111
  int l = (i * 0x01010101); // binary: 1000000010000000100000001

  int res = l >> 24;
  return res;
}
