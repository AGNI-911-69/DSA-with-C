#include <stdio.h>
#define MAX 100
void inputPolynomial(int poly[], int degree)
{
    for (int i = degree; i >= 0; i--)
    {
        printf("Enter coefficient of x^%d: ", i);
        scanf("%d", &poly[i]);
    }
}
void displayPolynomial(int poly[], int degree)
{
    int first = 1;
    for (int i = degree; i >= 0; i--)
    {
        if (poly[i] == 0) continue;
        if (!first && poly[i] > 0) printf(" + ");

        
        if (poly[i] < 0) printf(" - ");

        int coefficient = poly[i] < 0 ? -poly[i] : poly[i];

        if (i == 0 || coefficient != 1)
            printf("%d", coefficient);

        if (i >= 1) printf("x");
        if (i >= 2) printf("^%d", i);

        first = 0;
    }
    if (first) printf("0");
    printf("\n");
}
int main()
{
    int poly1[MAX] = {0}, poly2[MAX] = {0};
    int sum[MAX] = {0}, product[2 * MAX] = {0};
    int degree1, degree2;

    printf("Enter degree of first polynomial: ");
    scanf("%d", &degree1);

    printf("Enter coefficients for first polynomial:\n");
    inputPolynomial(poly1, degree1);

    printf("Enter degree of second polynomial: ");
    scanf("%d", &degree2);

    printf("Enter coefficients for second polynomial:\n");
    inputPolynomial(poly2, degree2);

    int maxDegree = degree1 > degree2 ? degree1 : degree2;

    for (int i = 0; i <= maxDegree; i++)
        sum[i] = poly1[i] + poly2[i];

    for (int i = 0; i <= degree1; i++)
        for (int j = 0; j <= degree2; j++)
            product[i + j] += poly1[i] * poly2[j];

    printf("\nFirst Polynomial: ");
    displayPolynomial(poly1, degree1);

    printf("Second Polynomial: ");
    displayPolynomial(poly2, degree2);

    printf("Addition: ");
    displayPolynomial(sum, maxDegree);

    printf("Multiplication: ");
    displayPolynomial(product, degree1 + degree2);

    return 0;
}