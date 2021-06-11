#include <stdio.h>
#include <stdlib.h>
#include <string.h>

unsigned long long power(int x) {
        unsigned long long a = 1;
        for (int i = 0; i < x; i++)
                a *= 3;
        return a;
}

int main() {
        char s[12];
        unsigned long long d = 0;
        scanf("%s", s);
        int l = strlen(s);
        for (int i = l - 1; i >= 0; i-- ) {
                d += (int)(s[i] - '0') * power(l - i - 1);
        }
        printf("%llu\n", d);
        return 0;
}
