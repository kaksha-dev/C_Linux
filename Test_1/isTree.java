/**
 * https://www.spoj.com/problems/PT07Y/
 */

import java.util.ArrayList;
import java.util.Scanner;

class isTree {

    private static ArrayList<ArrayList<Integer>> adj;
    private static boolean[] visited;
    
    public static boolean dfs (int node, int parent) {
        visited[node] = true;

        for (int nextNode : adj.get(node)) {

            if (visited[nextNode] == false){

                if (dfs(nextNode, node)) {
                    return true;
                } 
            }
            else if (nextNode != parent){
                return true;
            }
        }
        return false;
    }

    public static void main(String[] args) {

        Scanner sc = new Scanner(System.in);
        
        int n = sc.nextInt();
        int m = sc.nextInt();

        adj = new ArrayList<>();

        for(int i = 0 ; i < n + 1 ; i++) {
            adj.add(new ArrayList<Integer>());
        }

        // adjacency list
        for(int i = 0 ; i < m ; i++){
            int u = sc.nextInt();
            int v = sc.nextInt();

            adj.get(u).add(v);
            adj.get(v).add(u);
        }

        visited = new boolean[n + 1]; 

        boolean result = false;  
        for (int i = 1 ; i <= n ; i++) {
            if (visited[i] == false) {
                
                // if each node visisted and check parent
                // i - start node, -1 - parent of start
                if (dfs(i, -1)) {
                    result = true;
                    break;
                }
            }
        }

        if (result) {
            System.out.println("NO");
        }
        else {
            System.out.println("YES");
        }
    }
}
