#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAXLEN 255//串长最大为255

typedef struct //定长顺序存储（静态数组）
{
    char ch[MAXLEN];
    int length;
}SString;

typedef struct //堆分配存储（动态数组）
{
    char *ch; //ch指向串的基地址
    int length;
}HString;

typedef struct StringNode //链式存储
{
    char ch[4]; //每个结点存多个字符 4Byte
    struct StringNode *next; //4Byte
}StringNode, *String;

void InitSString(SString &S)
{
    S.length = 0;
}

void InitHString(HString &S)
{
    S.ch = (char *)malloc(MAXLEN * sizeof(char));
    S.length = 0;
}

//求子串
bool SubString(SString &Sub, SString S, int pos, int len)
{
    if (pos + len - 1 > S.length) return false;//子串范围越界
    for (int i = pos; i < pos + len; i++)
    {
        Sub.ch[i - pos + 1] = S.ch[i];
    }
    Sub.length = len;
    return true;
}

//比较:S>T,return(>0); S=T,return(=0); S<T,return(<0); 
int StrCompare(SString S, SString T)
{
    for (int i = 1; i <= S.length && i <= T.length; i++)
    {
        if (S.ch[i] != T.ch[i]) 
        {
            return S.ch[i] - T.ch[i];
        }
    }
    return S.length - T.length;
}

//求串长
int StrLength(SString S)
{
    return S.length;
}

//定位子串(模式匹配):返回主串S中第一次出现T的位置，没有则为0
int Index(SString S, SString T)
{
    int i = 1, n = StrLength(S), m = StrLength(T);
    SString sub;
    for (int i = 1; i <= n - m + 1; i++)
    {
        SubString(sub, S, i, m);
        if (StrCompare(sub, T) == 0) return i;
    }
    return 0;
}

//朴素模式匹配算法(BF)-O(nm)
int Index_BF(SString S, SString T)
{
    int k = 1;//当前子串的位置
    int i = k, j = 1;
    while (i <= S.length && j <= T.length && k <= S.length - T.length + 1)
    {
        if (S.ch[i] == T.ch[j]) 
        {
            ++i; ++j;
        }
        else 
        {
            ++k;//检查下一个子串
            i = k; j = 1;
        }
    }
    if (j > T.length) return k; //匹配到子串
    else return 0;
}

int main()
{
    SString S, T;
    InitSString(S);
    InitSString(T);
    strcpy(S.ch + 1, "Hello World!");
    strcpy(T.ch + 1, "Worlo");
    S.length = 12;
    T.length = 5;
    // int result = Index(S, T);
    int result = Index_BF(S, T);
}
