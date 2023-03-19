/*
Time complexity in DSA with Algo : O(V+E)[V=Vertex , E = Edge]
Time complexity in AI : O(b^d)[b=Branch Factor, d=Depth]
*/

/*
It is a Unimformed Search Technique
    - FIFO(Using Queue)
    - complete 
    - Optimal
    - Shallowest Node
*/
#include <stdio.h>
#include <stdlib.h>
int i;
int a[7][7] = {
    {0, 1, 1, 1, 0, 0, 0},
    {1, 0, 1, 0, 0, 0, 0},
    {1, 1, 0, 1, 1, 0, 0},
    {1, 0, 1, 0, 1, 0, 0},
    {0, 0, 1, 1, 0, 1, 1},
    {0, 0, 0, 0, 1, 0, 0},
    {0, 0, 0, 0, 1, 0, 0}};
typedef struct queue
{
    int *arr, f, r, size;
} Queue;

int isEmpty(Queue *q)
{
    if (q->f == q->r)
    {
        return 1;
    }
    return 0;
}

int isFull(Queue *q)
{
    if (q->r == q->size - 1)
    {
        return 1;
    }
    return 0;
}

void enQueue(Queue *q, int v)
{
    if (isFull(q))
    {
        printf("Queue is full\n");
    }
    else
    {
        q->r++;
        q->arr[q->r] = v;
    }
}

int deQueue(Queue *q)
{
    int v = -1;
    if (isEmpty(q))
    {
        printf("Queue is empty !");
    }
    else
    {
        q->f++;
        v = q->arr[q->f];
    }
    return v;
}

void showQueue(Queue *q)
{

    if (isEmpty(q))
    {
        printf("Queue is Empty\n");
    }
    else
    {
        for (i = q->f + 1; i <= q->r; i++)
        {
            printf("|%d|", q->arr[i]);
        }
    }
    printf("\n");
}

void BFS(int s)
{
    // Define Queuue Structure
    Queue *q;
    q = (Queue *)malloc(sizeof(Queue));
    q->f = q->r = -1;
    q->size = 7;
    q->arr = (int *)calloc(q->size, sizeof(int));

    int *v = (int *)calloc(q->size, sizeof(int));
    printf("%d ", s);
    v[s] = 1;
    enQueue(q, s);

    while (!isEmpty(q))
    {
        int node = deQueue(q);
        for (i = 0; i < 7; i++)
        {
            if (a[node][i] == 1 && v[i] == 0)
            {
                printf("%d ", i);
                v[i] = 1;
                enQueue(q, i);
            }
        }
    }
}
int main()
{
    int i;

    for (i = 0; i < 7; i++)
    {
        printf("Source Node : %d\n", i);
        printf("BFS Traversal is :>");
        BFS(i);
        printf("\n");
    }

    return 0;
}