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
    printf("\nElement\t\tAddress\n");
    printf("-------------------------\n");
    for (int i = 0; i < n; i++)
    {
        printf("arr[%d] = %d\t%p\n", i, arr[i], (void*)&arr[i]);
    }
    return 0;
}