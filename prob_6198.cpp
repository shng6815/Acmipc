#include<iostream>

using namespace std;

#define SIZE 80000

typedef struct Stack
{
    int data[80000];
    int top;
}Stack;

void init(Stack* S){
    S->top = -1;
}

int isFull(Stack* S){
    return S->top == SIZE;
}

int isEmpty(Stack* S){
    return S->top == -1;
}

void push(Stack* S, int e){
    if (isFull(S))
        return;

    S->top++;
    S->data[S->top]=e;
}

void pop(Stack* S){
    if(isEmpty(S)){
        return;
    }
    S->top--;
}

int top(Stack* S){
    return S->data[S->top];
}

int main(){
    Stack s;
    init(&s);
    long long N, temp, sum=0;
    scanf("%lld",&N);
    for (int i = 0; i < N; i++)
    {
        scanf("%lld",&temp);
        while (!isEmpty(&s)&&top(&s)<=temp)
            pop(&s);
        sum += s.top+1;
        push(&s,temp);
    }
    printf("%lld\n",sum);

    return 0;
}