#include <stdio.h>
#include <stdbool.h>

#define MAX_N 1000

typedef struct {
    int numCities;
    bool routes[MAX_N + 1][MAX_N + 1];
} Graph;

void initializeGraph(Graph *graph, int numCities) {
    graph->numCities = numCities;
    for (int i = 1; i <= numCities; i++) {
        for (int j = 1; j <= numCities; j++) {
            graph->routes[i][j] = false;
        }
    }
}

void addRoute(Graph *graph, int cityA, int cityB) {
    graph->routes[cityA][cityB] = true;
    graph->routes[cityB][cityA] = true;
}

int findShortestPath(Graph graph, int start, int end, int avoid) {
    int distance[MAX_N];
    bool visited[MAX_N];

    for (int i = 1; i <= graph.numCities; i++) {
        distance[i] = -1;
        visited[i] = false;
    }

    distance[start] = 0;

    for (int count = 0; count < graph.numCities; count++) {
        int minDistance = -1;
        int minIndex = -1;

        for (int i = 1; i <= graph.numCities; i++) {
            if (!visited[i] && (minDistance == -1 || distance[i] < minDistance)) {
                minDistance = distance[i];
                minIndex = i;
            }
        }

        visited[minIndex] = true;

        for (int i = 1; i <= graph.numCities; i++) {
            if (!visited[i] && graph.routes[minIndex][i] && (i != avoid || minIndex != start)) {
                if (distance[i] == -1 || distance[minIndex] + 1 < distance[i]) {
                    distance[i] = distance[minIndex] + 1;
                }
            }
        }
    }

    return distance[end];
}

int main() {
    int N, M;
    while (scanf("%d %d", &N, &M) != EOF) {
        Graph graph;
        initializeGraph(&graph, N);

        for (int i = 0; i < M; i++) {
            int A, B;
            scanf("%d %d", &A, &B);
            addRoute(&graph, A, B);
        }

        int C, R, E;
        scanf("%d %d %d", &C, &R, &E);

        int result = findShortestPath(graph, C, R, E);
        printf("%d\n", result);
    }

    return 0;
}
