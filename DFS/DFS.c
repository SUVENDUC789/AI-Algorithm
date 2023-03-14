/*
Time complexity in DSA with Algo : O(V+E)[V=Vertex , E = Edge]
Time complexity in AI : O(b^d)[b=Branch Factor, d=Depth]
*/

/*
It is a Unimformed Search Technique
    - LIFO(Using Stack)
    - Incomplete 
    - Not Optimal
    - Depest Node
*/

#include <stdio.h>
#include <stdlib.h>

int a[7][7] = {
    {0, 1, 1, 1, 0, 0, 0},
    {1, 0, 1, 0, 0, 0, 0},
    {1, 1, 0, 1, 1, 0, 0},
    {1, 0, 1, 0, 1, 0, 0},
    {0, 0, 1, 1, 0, 1, 1},
    {0, 0, 0, 0, 1, 0, 0},
    {0, 0, 0, 0, 1, 0, 0}};

// int v[7] = {0, 0, 0, 0, 0, 0, 0};

void DFS(int *v, int i)
{
    int j;
    printf("%d ", i);
    v[i] = 1;
    for (j = 0; j < 7; j++)
    {
        if (a[i][j] == 1 && v[j] == 0)
        {
            DFS(v, j);
        }
    }
}

int main()
{
    int i;
    for (i = 0; i < 7; i++)
    {
        int *v = (int *)calloc(7, sizeof(int));
        printf("Source Node : %d\n", i);
        DFS(v, i);
        printf("\n");
    }
    return 0;
}