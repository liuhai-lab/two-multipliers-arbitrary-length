#include<stdio.h>
#include<string.h>
#include<malloc.h>
#define and &&           //�����߼� ��
#define or ||            //�����߼� ��
#define not !
#define Int(X) (X - '0')
int *multiBigInteger(const char *, const char *);
int checkNum(const char *);
int main(void)
{
    char num1[100] = {'\0'}, num2[100] = {'\0'};
    printf("����������������:\n> ");
    while(scanf("%s%s", num1, num2) != EOF)
    {
        int *result = NULL;
        int i, change = 0;      //�������������

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
        //������result��result[0]������result�ĳ��ȣ� ���±�Ҫ��1��ʼ
        printf("������˵Ľ����:\t");
        for(i = 1; i <= result[0]; i++)
        {
            if(result[i] != 0)   //ȥ��0,��һλΪ0�����
                change = 1;
            if(not change)
            {
                if(i > 1)        //�Ͻ���Ƿ�Ϊ0,
                    {                //������ڶ�λ����0,���ж�Ϊ0
                        printf("0");
                        break;
                    }
                continue;
            }
            printf("%d", result[i]);
        }
        printf("\n");
        printf("\n����������������:\n> ");
    }
    return 0;
}    //���������Ƿ������֣����Ǿͷ���0,���Ǿͷ���1
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
}                //���ؽ��result
int *multiBigInteger(const char *num1, const char *num2)
{
    int *result = NULL;                //�������ս��
    int num1Len = strlen(num1);        //��һ�����ĳ���
    int num2Len = strlen(num2);        //�ڶ������ĳ���
    int resultLen;                     //�������󳤶�
    int i, j;                          //ѭ��������
    resultLen = num1Len + num2Len;     //����������Ϊ��һ�������Ⱥ͵ڶ���������֮��
    result = (int *)malloc((resultLen+1)*sizeof(int));
    memset(result, 0, (resultLen+1)*sizeof(int));

    result[0] = resultLen; //result�ĵ�һλ����������result�ĳ��ȵġ�
    // ��һ�������Եڶ�����,������������Ȳ���λ���㷨�������㷨�ǰ������� ��˳�����ˣ�Ȼ��ÿλ�Ľ�����浽result��ÿһλ�У�ѭ��һ�� reult�ʹ���һλ��ʼ���
    for(j = 0; j < num2Len; j++)
    {
        for(i = 0; i < num1Len; i++)
        {
        	//result��һλ����������result���ȵģ����ڶ�λ�Ǳ��������Ľ�λ��û�н�λ����result[1]Ϊ0������ÿλ���֮���Ǵӵ���λ����result[2]����ʼ
            result[i+j+2] += Int(num1[i]) * Int(num2[j]);
        }
    }         //���ѭ�����������λ�ģ�����Ҫ��result�����һλһֱ������λ��
    for(i = resultLen; i > 1; i--)
    {
        result[i-1] += result[i]/10;
        result[i] = result[i]%10;
    }
    printf("num1Len:%d\nnum2Len:%d\n", num1Len, num2Len);
    return result;
}

