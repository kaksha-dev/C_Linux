/*
https://www.hackerrank.com/contests/crescent-practice-3rd-years/challenges/islands-1
*/
#include <stdio.h>
#include <assert.h>


void find_island(int i, int j, int rows, int cols, int arr[rows][cols], int visited[rows][cols])
{
    if(i >= rows) return;
    if(j >= cols) return;
    if(j < 0) return;
    if(i < 0) return;
    if(!arr[i][j]) return;
    if(visited[i][j]) return;

    // Element is 1 and has not been computed before
    visited[i][j] = 1;
    find_island(i-1, j-1, rows, cols, arr, visited);
    find_island(i-1, j, rows, cols, arr, visited);
    find_island(i-1, j+1, rows, cols, arr, visited);
    find_island(i, j-1, rows, cols, arr, visited);
    find_island(i, j+1, rows, cols, arr, visited);
    find_island(i+1, j-1, rows, cols, arr, visited);
    find_island(i+1, j, rows, cols, arr, visited);
    find_island(i+1, j+1, rows, cols, arr, visited);
}


int count_islands(int rows, int cols, int arr[rows][cols], int visited[rows][cols])
{
    int num_islands = 0;

    for(int i = 0; i < rows; i++)
    {
       for(int j=0; j < cols; j++)
       {
          if(!arr[i][j]) continue;
          if(visited[i][j]) continue;
          // Element is 1 and has not been computed before
          // You have found an element which is not part of islands computed already
          num_islands++;
          find_island(i, j, rows, cols, arr, visited);
       }
    }

    return num_islands;
}

int main()
{
   //Test Case -1
   int arr_1[1][1] = {0};
   int visited_1[1][1] = {0};
   assert(count_islands(1, 1, arr_1, visited_1)== 0);


   //Test Case -2
   int arr_2[1][1] = {1};
   int visited_2[1][1] = {0};
   assert(count_islands(1, 1, arr_2, visited_2)== 1);

   //Test Case -3
   int arr_3[3][2] = {
      {1, 0},
      {0, 1},
      {1, 0},
   };

   int visited_3[3][2] = {
      {0, 0},
      {0, 0},
      {0, 0},
   };
   assert(count_islands(3, 2, arr_3, visited_3)== 1);

   //Test Case -4
   int arr_4[3][2] = {
      {1, 1},
      {0, 0},
      {1, 1},
   };

   int visited_4[3][2] = {
      {0, 0},
      {0, 0},
      {0, 0},
   };
   assert(count_islands(3, 2, arr_4, visited_4)== 2);


   //Test Case -5
   int arr_5[5][5] = {
       {1, 1, 0, 0, 0},
       {0, 1, 0, 0, 1},
       {1, 0, 0, 1, 1},
       {0, 0, 0, 0, 0},
       {1, 0, 1, 0, 1},
   };
   int visited_5[5][5] = {
       {0, 0, 0, 0, 0},
       {0, 0, 0, 0, 0},
       {0, 0, 0, 0, 0},
       {0, 0, 0, 0, 0},
       {0, 0, 0, 0, 0},
   };
   assert(count_islands(5, 5, arr_5, visited_5)== 5);

   //Test Case -6
   int arr_6[3][3] = {
       {1, 0, 1},
       {0, 1, 0},
       {1, 0, 1},
   };
   int visited_6[3][3] = {
       {0, 0, 0},
       {0, 0, 0},
       {0, 0, 0},
   };
   assert(count_islands(3, 3, arr_6, visited_6)== 1);

   return 0;
}
