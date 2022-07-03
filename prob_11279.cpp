#include <iostream>

#define HEAP_SIZE 100001
using namespace std;

int heap[HEAP_SIZE];
int heap_count = 0;
void swap(int *a, int *b)
{
    int tmp = *a;
    *a = *b;
    *b = tmp;
}

void init()
{
    heap_count = 0;
}

int size()
{
    return heap_count;
}

void push(int data)
{
    heap[++heap_count] = data;

    int child = heap_count;
    int parent = child / 2;
    while (child > 1 && heap[parent] < heap[child])
    {
        swap(&heap[parent], &heap[child]);
        child = parent;
        parent = child / 2;
    }
}

int pop()
{
    if (!size())
    {
        return 0;
    }
    int result = heap[1];

    swap(&heap[1], &heap[heap_count]);
    heap_count--;

    int parent = 1;
    int child = parent * 2;
    if (child + 1 <= heap_count)
    {
        child = (heap[child] > heap[child + 1]) ? child : child + 1;
    }

    while (child <= heap_count && heap[parent] < heap[child])
    {
        swap(&heap[parent], &heap[child]);

        parent = child;
        child = child * 2;
        if (child + 1 <= heap_count)
        {
            child = (heap[child] > heap[child + 1]) ? child : child + 1;
        }
    }

    return result;
}

int main()
{

    int T, temp;
    cin >> T;
    for (int i = 0; i < T; i++)
    {
        cin >> temp;
        if (temp)
            push(temp);
        else
            cout << pop() << endl;
    }

    return 0;
}