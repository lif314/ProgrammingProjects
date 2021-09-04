# include <stdio.h>

// Bit Operation
/*
* & 按位与：相同为1
* | 按位或：有1为1
* ^ 按位异或：不同为1
* << 左移：乘
* >> 右移：除
*/


// getbits(x, p, n): Return n bits in x starting from the p-th bit
unsigned getbits(unsigned x, int p, int n)
{
    return (x >> (p + 1 -n)) & ~(~0 << n);
}

// bitcount(x): Count the number of x whose median value is 1
int bitcount(unsigned x)
{
    int b;
    for(b = 0; x != 0; x >>= 1)
    {
        if (x & 01)
            b++;
    }
    return b;
}