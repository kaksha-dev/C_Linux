
/**
 * https://www.hackerrank.com/contests/crescent-practice-3rd-years/challenges/islands-1
 */

import java.util.Scanner;

public class Island {

    public static void findIsland (int i, int j, int row, int col, int[][]arr, int[][] visited) {
        if (i >= row) {
            return;
        }
           
        if (j >= col) {
            return;
        }
            
        if (j < 0) {
            return;
        }
           
        if (i < 0) {
            return;
        }
            
        if (arr[i][j] == 0) {
            return;
        }
            
        if (visited[i][j] == 1) {
            return;
        }
            
        visited[i][j] = 1;
        
        // all directions
        findIsland(i-1, j-1, row, col, arr, visited);
        findIsland(i-1, j, row, col, arr, visited);
        findIsland(i-1, j+1, row, col, arr, visited);
        findIsland(i, j-1, row, col, arr, visited);
        findIsland(i, j+1, row, col, arr, visited);
        findIsland(i+1, j-1, row, col, arr, visited);
        findIsland(i+1, j, row, col, arr, visited);
        findIsland(i+1, j+1, row, col, arr, visited);
    }

    public static int sol(int[][] arr, int row, int col) {
        int[][] visited = new int[row][col];
        int ans = 0;
        
        for(int i = 0; i < row; i++) {
            for (int j = 0; j < col; j++) {
                // water
                if (arr[i][j] == 0) {
                    continue;
                }
                // checked
                if (visited[i][j] == 1) {
                    continue;
                }
                ans++;
                findIsland(i, j, row, col, arr, visited);
            }
        }

        return ans;
    }

    public static void main(String[] args) {

        Scanner sc  = new Scanner(System.in);
        int row = sc.nextInt();
        int col = sc.nextInt();
        int[][] arr = new int[row][col];
        
        for (int i = 0; i < row; i++) {
            for (int j = 0; j < col; j++) {
                arr[i][j] = sc.nextInt();        
            }
        }
        
        int ans = sol(arr, row, col);     
        System.out.println(ans);

        sc.close();
    }
}