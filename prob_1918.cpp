#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define SIZE 101

typedef struct
{
    char data[SIZE];
    int top;
} StackType;

void init(StackType *S)
{
    S->top = -1;
}

int isEmpty(StackType *S)
{
    return S->top == -1;
}

int isFull(StackType *S)
{
    return S->top == SIZE - 1;
}

void push(StackType *S, char c)
{
    if (isFull(S))
        printf("Overflow!!\n");
    else
    {
        S->top++;
        S->data[S->top] = c;
    }
}

char pop(StackType *S)
{
    if (isEmpty(S))
    {
        printf("Empty!!\n");
        return -1;
    }

    char c = S->data[S->top];
    S->top--;
    return c;
}

char peek(StackType *S)
{
    if (isEmpty(S))
    {
        printf("Empty!!\n");
        return -1;
    }
    return S->data[S->top];
}

int prec(char op)
{
    switch(op)
    {
        case '(': case ')':
            return 0;
        case '+': case '-':
            return 1;
        case '*': case '/':
            return 2;
    }
}

void convert(char infix[], char postfix[])
{
    StackType S;
    init(&S);
    
    char c, t;
    int n = strlen(infix);
    
    for(int i = 0; i < n; i++)
    {
        c = infix[i];
        
        switch(c)
        {
            case '+': case '-': case '*': case '/':
                while(!isEmpty(&S) && prec(c) <= prec(peek(&S))){
                    printf("%c",pop(&S));
                }
                push(&S, c);    
                break;
                
            case '(':
                push(&S, c);
                break;
                
            case ')':
                t = pop(&S);
                while(t != '(')
                {
                    printf("%c", t);
                    t = pop(&S);
                }
                break;
                
            default:
                printf("%c",c);
                break;
        }
    }
    while(!isEmpty(&S)){
        printf("%c",pop(&S));
    }
    printf("\n");
}


int main()
{
    char infix[SIZE], postfix[SIZE];
    scanf("%s", infix);//중위표기식 입력

    convert(infix, postfix);//후위표기식으로 변환

    return 0;
}