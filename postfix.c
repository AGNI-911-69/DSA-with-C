#include <stdio.h>
int main() { 
    char exp[] = "267*+";
    int stack[20], top = -1;
    int i, a, b, result;

    for (i = 0; exp[i] != '\0'; i++) {
        if (exp[i] >= '0' && exp[i] <= '9') {
            stack[++top] = exp[i] - '0';
        } else {
            b = stack[top--];
            a = stack[top--];

            if (exp[i] == '+')
                result = a + b;
            else if (exp[i] == '-')
                result = a - b;
            else if (exp[i] == '*')
                result = a * b;
            else
                result = a / b;  
            stack[++top] = result;
        }
    }
    printf("Result = %d\n", stack[top]);
    return 0;
}