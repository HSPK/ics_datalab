#include <stdio.h>
#define test(a) { \
    int res = a; \
    printf("%s = 0x%0x, %d\n", #a, res, res); \
}

int fun1(int x) {
    x ^= x >> 16;
    x ^= x >> 8;
    x ^= x >> 4;
    x ^= x >> 2;
    x ^= x >> 1;
    return x;
}

int fun2(int x) {
    x ^= x >> 1;
    x ^= x >> 2;
    x ^= x >> 4;
    x ^= x >> 8;
    x ^= x >> 16;
    return x;
}

int main(int argc, char const *argv[])
{
    test(fun1(0x87654321));
    test(fun1(0x80000000));
    test(fun1(0xc0000000));
    test(fun1(0x40000000));
    test(fun2(0x87654321));
    test(fun2(0x80000000));
    test(fun2(0xc0000000));
    test(fun2(0x40000000));
    return 0;
}
