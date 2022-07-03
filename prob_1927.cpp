#include <iostream>

#define HEAP_SIZE 100001
using namespace std;

int overHeap[HEAP_SIZE];
int underHeap[HEAP_SIZE];
int oheapCount = 0;
int uheapCount = 0;
void swap(int *a, int *b)
{
    int tmp = *a;
    *a = *b;
    *b = tmp;
}

void init()
{
    uheapCount = oheapCount = 0;
}

int usize()
{
    return uheapCount;
}

int osize(){
    return oheapCount;
}

void push(int data)
{
    if (data > 0)
    {
        overHeap[++oheapCount] = data;

        int child = oheapCount;
        int parent = child / 2;
        while (child > 1 && overHeap[parent] > overHeap[child])
        {
            swap(&overHeap[parent], &overHeap[child]);
            child = parent;
            parent = child / 2;
        }
    }
    else
    {
        underHeap[++uheapCount] = data * -1;

        int child = uheapCount;
        int parent = child / 2;
        while (child > 1 && underHeap[parent] > underHeap[child])
        {
            swap(&underHeap[parent], &underHeap[child]);
            child = parent;
            parent = child / 2;
        }
    }
}

int pop()
{
    int result;
    if (!(usize()+osize()))
    {
        return 0;
    }
    else if(usize() && osize() == 0){
        result = underHeap[1]*-1;

        swap(&underHeap[1], &underHeap[uheapCount]);
        uheapCount--;

        int parent = 1;
        int child = parent * 2;
        if (child + 1 <= uheapCount)
        {
            child = (underHeap[child] < underHeap[child + 1]) ? child : child + 1;
        }

        while (child <= uheapCount && underHeap[parent] > underHeap[child])
        {
            swap(&underHeap[parent], &underHeap[child]);

            parent = child;
            child = child * 2;
            if (child + 1 <= uheapCount)
            {
                child = (underHeap[child] < underHeap[child + 1]) ? child : child + 1;
            }
        }
        return result;
    }
    else if(osize() && usize() == 0){
        result = overHeap[1];

        swap(&overHeap[1], &overHeap[oheapCount]);
        oheapCount--;

        int parent = 1;
        int child = parent * 2;
        if (child + 1 <= oheapCount)
        {
            child = (overHeap[child] < overHeap[child + 1]) ? child : child + 1;
        }

        while (child <= oheapCount && overHeap[parent] > overHeap[child])
        {
            swap(&overHeap[parent], &overHeap[child]);

            parent = child;
            child = child * 2;
            if (child + 1 <= oheapCount)
            {
                child = (overHeap[child] < overHeap[child + 1]) ? child : child + 1;
            }
        }
        return result;
    }

    if (overHeap[1] >= underHeap[1])
    {
        result = underHeap[1]*-1;

        swap(&underHeap[1], &underHeap[uheapCount]);
        uheapCount--;

        int parent = 1;
        int child = parent * 2;
        if (child + 1 <= uheapCount)
        {
            child = (underHeap[child] < underHeap[child + 1]) ? child : child + 1;
        }

        while (child <= uheapCount && underHeap[parent] > underHeap[child])
        {
            swap(&underHeap[parent], &underHeap[child]);

            parent = child;
            child = child * 2;
            if (child + 1 <= uheapCount)
            {
                child = (underHeap[child] < underHeap[child + 1]) ? child : child + 1;
            }
        }
    }
    else
    {
        result = overHeap[1];

        swap(&overHeap[1], &overHeap[oheapCount]);
        oheapCount--;

        int parent = 1;
        int child = parent * 2;
        if (child + 1 <= oheapCount)
        {
            child = (overHeap[child] < overHeap[child + 1]) ? child : child + 1;
        }

        while (child <= oheapCount && overHeap[parent] > overHeap[child])
        {
            swap(&overHeap[parent], &overHeap[child]);

            parent = child;
            child = child * 2;
            if (child + 1 <= oheapCount)
            {
                child = (overHeap[child] < overHeap[child + 1]) ? child : child + 1;
            }
        }
    }

    return result;
}

int main()
{

    int T, temp;
    scanf("%d", &T);
    for (int i = 0; i < T; i++)
    {
        scanf("%d", &temp);
        if (temp)
            push(temp);
        else
            printf("%d\n", pop());
    }

    return 0;
}