#include <stdio.h>
int main()
{
    int n;

    printf("Enter number of elements: ");
    scanf("%d", &n);

    int arr[n];
    printf("Enter %d elements:\n", n);
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &arr[i]);
    }
    int smallest = arr[0];
    int largest = arr[0];

    for (int i = 1; i < n; i++)
    {
        if (arr[i] < smallest) smallest = arr[i];
        if (arr[i] > largest) largest = arr[i];
    }
    printf("Smallest element = %d\n", smallest);
    printf("Largest element = %d\n", largest);

    return 0;
}