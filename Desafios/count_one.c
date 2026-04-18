#include <stdio.h>
#include <stdlib.h>

int countDigitOne(int n) {
    long long m = 1;
    int count = 0;

    while (m <= n) {
        long long high = n / (m * 10);
        long long cur  = (n / m) % 10;
        long long low  = n % m;

        if (cur == 0) {
            count += high * m;
        } 
        else if (cur == 1) {
            count += high * m + low + 1;
        } 
        else {
            count += (high + 1) * m;
        }

        m *= 10;
    }

    return count;
}
int main() {
    int n1 = 13;
    int n2 = 0;
    int n3 = 11;
    int n4 = 99;
    int n5 = 100;

    printf("n = %d -> %d\n", n1, countDigitOne(n1)); // 6
    printf("n = %d -> %d\n", n2, countDigitOne(n2)); // 0
    printf("n = %d -> %d\n", n3, countDigitOne(n3)); // 4
    printf("n = %d -> %d\n", n4, countDigitOne(n4)); // 20
    printf("n = %d -> %d\n", n5, countDigitOne(n5)); // 21

    return 0;
}