#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <stdbool.h>
#include <limits.h>

int minDistance(int* distance, bool* checkVertex, int length) {
   int min = INT_MAX, min_index;
   for (int i = 0; i < length; i++) {
     if (!checkVertex[i] && distance[i] <= min) {
       min = distance[i];
       min_index = i;
     }
   }
   return min_index;
}

void dijkstra(int graph[9][9], int pos, int length) {
     int* distance = malloc(sizeof(int) * length);
     bool* checkVertex = malloc(sizeof(bool) * length);
     for (int i = 0; i < length; i++) {
       distance[i] = INT_MAX;
       checkVertex[i] = false;
     }
     distance[pos] = 0;
     for (int i = 0; i < length-1; i++) {
       int min = minDistance(distance, checkVertex, length);
       checkVertex[min] = true;
       for (int j = 0; j < 9; j++)
         if (!checkVertex[j] && graph[min][j] && distance[min] != INT_MAX && distance[min]+graph[min][j] < distance[j]) {
           distance[j] = distance[min] + graph[min][j];
         }
     }
     for(int i = 0; i < length; i++) {
       printf("Vertex: %i - Distance: %i\n", i, distance[i]);
     }
}

int main(int argc, char* argv[]) {
  int graph[9][9] = {{0, 4, 0, 0, 0, 0, 0, 8, 0},
                      {4, 0, 8, 0, 0, 0, 0, 11, 0},
                      {0, 8, 0, 7, 0, 4, 0, 0, 2},
                      {0, 0, 7, 0, 9, 14, 0, 0, 0},
                      {0, 0, 0, 9, 0, 10, 0, 0, 0},
                      {0, 0, 4, 14, 10, 0, 2, 0, 0},
                      {0, 0, 0, 0, 0, 2, 0, 1, 6},
                      {8, 11, 0, 0, 0, 0, 1, 0, 7},
                      {0, 0, 2, 0, 0, 0, 6, 7, 0}
                     };
  dijkstra(graph, 0, 9);
  return 0;
}
