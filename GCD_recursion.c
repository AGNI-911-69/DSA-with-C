#include <stdio.h>
int gcd(int a, int b)
{
    if (b == 0)
        return a;

    return gcd(b, a % b);
}
int main()
{
    int a, b;

    printf("Enter two positive numbers: ");
    scanf("%d %d", &a, &b);

    if (a < 0)
        a = -a;
    if (b < 0)
        b = -b;

    printf("GCD = %d\n", gcd(a, b));

    return 0;
}