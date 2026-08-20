#include <stdio.h>
int main()
{
    unsigned long baseAddress;
    int elementSize, index;
    unsigned long targetAddress;

    printf("Enter Base Address (e.g., 1000): ");
    scanf("%lu", &baseAddress);

    printf("Enter Size of Element in bytes (e.g., 2 or 4): ");
    scanf("%d", &elementSize);

    printf("Enter Index of Element (e.g., 3): ");
    scanf("%d", &index);

    targetAddress = baseAddress + (index * elementSize);

    printf("\nCalculated Address for index %d: %lu\n", index, targetAddress);

    return 0;
}