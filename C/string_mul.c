// Multiply strings of integers

#include <stdio.h>
#include <string.h>

char *multiply(char *num1, char *num2)
{
    static char ans[401];
    int n1 = strlen(num1), n2 = strlen(num2);
    int temp[400] = {0};

    for (int i = 0; i < n1; i++)
        for (int j = 0; j < n2; j++)
            temp[i + j] += (num1[i] - '0') * (num2[j] - '0');

    for (int i = n1 + n2 - 2; i > 0; i--)
    {
        temp[i - 1] += temp[i] / 10;
        temp[i] %= 10;
    }

    if (temp[0] / 10 != 0)
    {
        // Carry
        for (int i = n1 + n2 - 2; i > 0; i--)
            ans[i + 1] = temp[i] + '0';
        ans[1] = temp[0] % 10 + '0';
        ans[0] = temp[0] / 10 + '0';
        ans[n1 + n2] = '\0';
    }
    else
    {
        // No Carry
        for (int i = n1 + n2 - 2; i >= 0; i--)
            ans[i] = temp[i] + '0';
        ans[n1 + n2 - 1] = '\0';
    }
    return ans;
}

int main()
{
    char num1[201], num2[201];
    scanf("%s", num1);
    scanf("%s", num2);
    char *product = multiply(num1, num2);
    printf("\n%s", product);
}
