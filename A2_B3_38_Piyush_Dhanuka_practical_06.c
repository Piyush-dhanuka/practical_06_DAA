#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#define V 6
#define E (V * (V - 1))

typedef struct
{
    int src;
    int dest;
    float weight;
} Edge;

float distance(float lat1, float lon1, float lat2, float lon2)
{
    return sqrt(pow(lat1 - lat2, 2) + pow(lon1 - lon2, 2));
}

void bellmanFord(Edge edges[], int src)
{
    float dist[V];
    for (int i = 0; i < V; i++)
        dist[i] = INFINITY;
    dist[src] = 0;

    for (int i = 1; i < V; i++)
    {
        for (int j = 0; j < E; j++)
        {
            int u = edges[j].src;
            int v = edges[j].dest;
            float w = edges[j].weight;
            if (dist[u] + w < dist[v])
                dist[v] = dist[u] + w;
        }
    }

    printf("\nShortest distances from Zero Mile (Node %d):\n", src);
    for (int i = 0; i < V; i++)
        printf("To Location %d: %.6f\n", i, dist[i]);
}

int main()
{
    float lat[V] = {21.1458, 21.1281, 21.1298, 21.1483, 21.1459, 21.1540};
    float lon[V] = {79.0806, 79.0725, 79.0428, 79.0792, 79.0941, 79.0414};

    Edge edges[E];
    int k = 0;

    for (int i = 0; i < V; i++)
    {
        for (int j = 0; j < V; j++)
        {
            if (i != j)
            {
                float d = distance(lat[i], lon[i], lat[j], lon[j]);
                edges[k].src = i;
                edges[k].dest = j;
                edges[k].weight = d;
                k++;
            }
        }
    }

    bellmanFord(edges, 0);
    return 0;
}
