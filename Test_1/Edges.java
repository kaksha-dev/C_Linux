/**
 * https://codeforces.com/problemset/problem/862/B
 */

import java.util.ArrayList;
import java.util.Scanner;

public class Edges {

    private static ArrayList<ArrayList<Integer>> adj;
    private static boolean[] visited;
    // count of vertices of each color
    private static long[] count;

    public static void dfs (int node, int color) {

        if (visited[node] == false) {
            visited[node] = true;

            count[color]++;

            for (int nextNode : adj.get(node)) {
                // next color
                dfs(nextNode, ((color + 1) % 2));
            }
        }
	}

	public static void main (String[] args) {
	    
        Scanner sc = new Scanner(System.in);
		
        int n = sc.nextInt();
        adj = new ArrayList<>();
		
		for(int i = 0; i <= n ; i++) {
		    adj.add(new ArrayList<>());
		}
		
		for(int i = 1; i < n; i++) {
		    int u = sc.nextInt();
		    int v = sc.nextInt();
		    
		    adj.get(u).add(v);
		    adj.get(v).add(u);
		}
		
        visited = new boolean[n + 1];

        // 2 colors - 0  for black, 1 for white
        count = new long[2];
        count[0] = 0;
        count[1] = 0;

        // 1 - start node, 0 color of start
        dfs(1, 0);
		
		System.out.println((count[0] * count[1]) - (n  - 1));	
	}
}