#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MaxSize 10

typedef struct
{
    char data[MaxSize];
    int top;
}SqStack;

void InitStack(SqStack &S)
{
    S.top = -1;
}

bool StackEmpty(SqStack S)
{
    return S.top == -1;
}

bool StackFull(SqStack S)
{
    return S.top == MaxSize - 1;
}

bool Push(SqStack &S, char x)
{
    if (StackFull(S)) return false;
    S.data[++S.top] = x;
    return true;
}

bool Pop(SqStack &S, char &x)
{
    if (StackEmpty(S)) return false;
    x = S.data[S.top--];
    return true;
}

bool GetTop(SqStack S, char &x)
{
    if (S.top == -1) return false;
    x = S.data[S.top];
    return true;
}

//检测括号是否匹配
bool bracketCheck(char str[], int length)
{
    SqStack S;
    InitStack(S);
    for (int i = 0; i < length; i++)
    {
        if (str[i] == '(' || str[i] == '[' || str[i] == '{') //左括号
        {
            Push(S, str[i]);
        }
        else //右括号
        {
            if (StackEmpty(S)) return false;
            char topElem;
            Pop(S, topElem);
            if (str[i] == ')' && topElem != '(') return false; //检测括号类型是否匹配
            if (str[i] == ']' && topElem != '[') return false;
            if (str[i] == '}' && topElem != '{') return false;
        }
    }
    return StackEmpty(S);//检索完所有括号后，栈空说明匹配成功
}

int main()
{
    char str[MaxSize] = "{}[()]}";
    int length = strlen(str);
    bool result = bracketCheck(str, length);
}