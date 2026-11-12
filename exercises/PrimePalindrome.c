#include <stdio.h>

int isPrime(int n) {
    if (n < 2) return 0;
    for (int i = 2; i * i <= n; i++) {
        if (n % i == 0) return 0;
    }
    return 1;
}

int isPalindrome(int n) {
    int x = n, rev = 0;
    while (x > 0) {
        rev = rev * 10 + x % 10;
        x /= 10;
    }
    return n == rev;
}

int main(void) {
    int a, b;
    scanf("%d %d", &a, &b);

    for (int i = a; i <= b; i++) {
        if (isPrime(i) && isPalindrome(i)) {
            printf("%d\n", i);
        }
    }

    printf("\n");
    return 0;
}
