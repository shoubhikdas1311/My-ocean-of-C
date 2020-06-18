#include<stdio.h>
#include<stdlib.h>
int power(int num, int count)
{
    int result =1;
    for (int i = 0; i < count; i++)
    {
        result *= num;
    }
    return result;
}
int limitChecker(int num,int base, int * iter)
{
    int result = 0;
    *iter = 0;
    for (int i = 0; num > result; i++)
    {
        result = power(base, i);
        *iter = i;
    }
    return result;
}
int SD_i2a(char * str, int num, int base)
{
    int result = 0, lim = 0, iter = 0, j = 0;
    lim = limitChecker(num, base, &iter);
//    printf("%d\n%d\n", lim, iter);
    for (int i = iter; i >= 0; i--)
    {
        result = (num / power(base, i));
        if (result > 9)
        {
            result = (result - 9 -1) + 'A';
        }
        else
        {
            result = result + '0';
        }
        str[j++] = result;        
        printf("%c", result);
        num = num%power(base, i);
    }
    str[j] = '\0';
    printf("\n");
    return j;
}
int main(int argc, char const *argv[])
{
    int num = atoi(argv[1]), base = atoi(argv[2]), length = 0;
    char str[20];
    length = bin_calc(str, num, base);
    printf("%s", str);
    return 0;
}
