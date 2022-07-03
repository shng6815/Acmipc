#include <stdio.h>

#define SIZE 10001

int map[101][101] = {0};
int now[2] = {0};
int cnt = 0;
typedef struct
{
    int data_y[SIZE];
    int data_x[SIZE];
    int front, rear;
} Queue;

void init(Queue *q)
{
    q->front = 0;
    q->rear = 1;
    q->data_x[1] = 0;
    q->data_y[1] = 0;
    map[0][0] = 1;
}

int isFull(Queue *q)
{
    return q->rear == q->front - 1;
}

int isEmpty(Queue *q)
{
    return q->rear == q->front;
}

void delQueue(Queue *q)
{
    q->front++;
    map[q->data_y[q->front]][q->data_x[q->front]] = 0;
}

void insert(Queue *q, int y, int x)
{
    q->rear++;
    cnt++;
    now[1] = q->data_x[q->rear] = x;
    now[0] = q->data_y[q->rear] = y;

    if (map[y][x] != 2)
    {
        delQueue(q);
    }
    map[y][x] = 1;
}

int main()
{
    Queue q;
    init(&q);
    int T, apple, dir, move, dirmove = 0, j = 0;
    int x = 0, y = 0;
    char d;
    scanf("%d %d", &T, &apple);
    for (int i = 0; i < apple; i++)
    {
        int y, x;
        scanf("%d %d", &y, &x);

        map[y-1][x-1] = 2;
    }
    scanf("%d", &dir);
    for (int i = 0; i < dir; i++)
    {
        x = y = 0;
        scanf("%d %c", &move, &d);
        switch (dirmove % 4)
        {
        case 0: // right
            x = 1;
            break;
        case 1: // down
            y = 1;
            break;
        case 2: // left
            x = -1;
            break;
        case 3: // up
            y = -1;
            break;
        }
        for (; j < move; j++)
        {
            if (((now[0] + y < 0 || now[0] + y > T-1) || (now[1] + x < 0 || now[1] + x > T-1)) || (map[now[0] + y][now[1] + x] == 1))
            {
                printf("%d", cnt+1);
                return 0;
            }
            insert(&q, now[0] + y, now[1] + x);
        }
        if (d == 'D')
            dirmove++;
        else
            dirmove+=3;
    }

    x=y=0;
    switch (dirmove % 4)
    {
    case 0: // right
        x = 1;
        break;
    case 1: // down
        y = 1;
        break;
    case 2: // left
        x = -1;
        break;
    case 3: // up
        y = -1;
        break;
    }

    while (1)
    {
        if (((now[0] + y < 0 || now[0] + y > T-1) || (now[1] + x < 0 || now[1] + x > T-1)) || (map[now[0] + y][now[1] + x] == 1))
        {
            printf("%d", cnt+1);
            return 0;
        }
        insert(&q, now[0] + y, now[1] + x);
    }
}