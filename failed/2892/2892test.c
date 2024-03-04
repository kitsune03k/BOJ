#include <stdio.h>

int main(void) {
    int min = 128, max = 0;
    for(int i = 0; i < 26; i++) {
        for(int j = 0; j < 10; j++) {
            char c1 = i + 'a', c2 = j + '0';
            int xor = c1 ^ c2;

            //printf("'%c'(%x) ^ '%c'(%x) = %x\n", c1, c1, c2, c2, xor, xor);

            if(xor < min)
                min = xor;
            if(xor > max)
                max = xor;
        }
    }
    printf("1. a-z | min 0x%x(%d), max 0x%x(%d)\n", min, min, max, max);

    // 결과1 : min = 64(0x40), max = 95(0x5f)


    int min1 = 128, max1 = 0;
    for(int i = 0; i < 10; i++) {
        char c = i + '0';
        char dot = '.';

        int xor1 = c ^ dot;

        //printf("'%c'(%x) ^ '%c'(%x) = %x\n", c, c, dot, dot, xor1, xor1);

        if(xor1 < min1) {
            min1 = xor1;
        }
        if(xor1 > max1) {
            max1 = xor1;
        }
    }
    printf("2. '.' | min1 0x%x(%d), max1 0x%x(%d)\n", min1, min1, max1, max1);
    // 결과 2 : min1 0x10(22), max1 0x19(31)


    int min2 = 128, max2 = 0;
    for(int i = 0; i < 10; i++) {
        char c = i + '0';
        char space = ' ';

        int xor2 = c ^ space;

        //printf("'%c'(%x) ^ '%c'(%x) = %x\n", c, c, space, space, xor2, xor2);

        if(xor2 < min2) {
            min2 = xor2;
        }
        if(xor2 > max2) {
            max2 = xor2;
        }

    }
    printf("3. ' ' |min2 0x%x(%d), max2 0x%x(%d)\n", min2, min2, max2, max2);


    // 결과 3 : min2 0x16(16), max2 0x1e(25)
}