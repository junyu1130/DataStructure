#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAXLEN 255

typedef struct
{
    char ch[MAXLEN];
    int length;
}SString;

void InitSString(SString &S)
{
    S.length = 0;
}

//求模式串的next数组
void get_next(SString T, int next[])
{
    int i = 1, j = 0;
    next[1] = 0;
    while (i < T.length)
    {
        if (j == 0 || T.ch[i] == T.ch[j])
        {
            next[++i] = ++j; //匹配串的最长相等前后缀长度+1
        }
        else 
        {
            j = next[j]; //寻找匹配串的最长相等前后缀长度
        }
    }
}

//求模式串的next函数修正值
void get_nextval(SString T, int nextval[])
{
    int i = 1, j = 0;
    nextval[1] = 0;
    while (i < T.length)
    {
        if (j == 0 || T.ch[i] == T.ch[j])
        {
            ++i; ++j;
            if (T.ch[i] != T.ch[j]) 
            {
                nextval[i] = j; //匹配串的最长相等前后缀长度+1
            }
            else
            {
                nextval[i] = nextval[j];
            }
        }
        else 
        {
            j = nextval[j]; //寻找匹配串的最长相等前后缀长度
        }
    }
}

//KMP匹配（主串不回溯）
int Index_KMP(SString S, SString T)
{
    int i = 1, j = 1;
    int nextval[T.length + 1];
    get_nextval(T, nextval); //求模式串的next函数修正值
    while (i <= S.length && j <= T.length)
    {
        if (j == 0 || S.ch[i] == T.ch[j])
        {
            ++i; ++j; //继续比较后继字符
        }
        else
        {
            j = nextval[j]; //模式串向右移动
        }
    }
    if (j > T.length) return i - T.length;
    else return 0;
}

int main()
{
    SString S, T;
    InitSString(S);
    InitSString(T);
    strcpy(S.ch + 1, "Hello World!");
    strcpy(T.ch + 1, "World");
    S.length = 12;
    T.length = 5;
    int result = Index_KMP(S, T);
}