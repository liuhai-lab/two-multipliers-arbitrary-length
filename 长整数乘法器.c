#include<stdio.h>
#include<string.h>
#include<malloc.h>
#define and &&           //定义逻辑 且
#define or ||            //定义逻辑 非
#define not !
#define Int(X) (X - '0')
int *multiBigInteger(const char *, const char *);
int checkNum(const char *);
int main(void)
{
    char num1[100] = {'\0'}, num2[100] = {'\0'};
    printf("请输入两个长整数:\n> ");
    while(scanf("%s%s", num1, num2) != EOF)
    {
        int *result = NULL;
        int i, change = 0;      //检验输入的数据

        if(strlen(num1) > 100 or strlen(num2) > 100)
        {
            printf("per number must less than 100 digits\n");
            return 1;
        }
        if(checkNum(num1) or checkNum(num2))
        {
            printf("ERROR: input must be an Integer\n");
            return 1;
        }
        printf("num1:\t%s\nnum2:\t%s\n", num1, num2);
        result = multiBigInteger(num1, num2);
        //输出结果result，result[0]保存着result的长度， 故下标要从1开始
        printf("两数相乘的结果是:\t");
        for(i = 1; i <= result[0]; i++)
        {
            if(result[i] != 0)   //去掉0,第一位为0则不输出
                change = 1;
            if(not change)
            {
                if(i > 1)        //断结果是否为0,
                    {                //若结果第二位还是0,就判断为0
                        printf("0");
                        break;
                    }
                continue;
            }
            printf("%d", result[i]);
        }
        printf("\n");
        printf("\n请输入两个长整数:\n> ");
    }
    return 0;
}    //检测输入的是否是数字，若是就返回0,不是就返回1
int checkNum(const char *num)
{
    int i;
    for(i = 0; (size_t)i < strlen(num); i++)
    {
        if(num[i] < '0' or num[i] > '9')
        {
            return 1;
        }
    }
    return 0;
}                //返回结果result
int *multiBigInteger(const char *num1, const char *num2)
{
    int *result = NULL;                //保存最终结果
    int num1Len = strlen(num1);        //第一个数的长度
    int num2Len = strlen(num2);        //第二个数的长度
    int resultLen;                     //结果的最大长度
    int i, j;                          //循环计数器
    resultLen = num1Len + num2Len;     //结果长度最大为第一个数长度和第二个数长度之和
    result = (int *)malloc((resultLen+1)*sizeof(int));
    memset(result, 0, (resultLen+1)*sizeof(int));

    result[0] = resultLen; //result的第一位是用来保存result的长度的。
    // 第一个数乘以第二个数,由于这里采用先不进位的算法，所以算法是按从左到右 按顺序来乘，然后将每位的结果保存到result的每一位中，循环一次 reult就从下一位开始求和
    for(j = 0; j < num2Len; j++)
    {
        for(i = 0; i < num1Len; i++)
        {
        	//result第一位是用来保存result长度的，而第二位是保存结果最后的进位的没有进位，则result[1]为0，所以每位相乘之和是从第三位（即result[2]）开始
            result[i+j+2] += Int(num1[i]) * Int(num2[j]);
        }
    }         //这个循环用来处理进位的，所以要从result的最后一位一直处理到首位。
    for(i = resultLen; i > 1; i--)
    {
        result[i-1] += result[i]/10;
        result[i] = result[i]%10;
    }
    printf("num1Len:%d\nnum2Len:%d\n", num1Len, num2Len);
    return result;
}

