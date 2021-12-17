/**
 * https://www.spoj.com/problems/PT07Z/
 */


import java.util.ArrayList;
import java.util.Arrays;
import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.io.IOException;

class LongestPath {

    private static ArrayList<ArrayList<Integer>> adj;
    private static boolean[] visited;
    private static int maxLevel;
    private static int maxNode;

    public static void dfs (int source, int level) {

        if (level > maxLevel) {
            maxLevel = level;
            maxNode = source;
        }

        visited[source] = true;

        for (int nextNode : adj.get(source)) {
            if (visited[nextNode] == false) {
                dfs(nextNode, level + 1);
            }
        }
    }

    public static void main(String[] args) throws IOException  {

        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        int n = Integer.parseInt(br.readLine());

        adj = new ArrayList<>();

        for(int i = 0 ; i < n + 1 ; i++) {
            adj.add(new ArrayList<Integer>());
        }

        // adjacency list
        for(int i = 0 ; i < (n - 1) ; i++){
            String num[]=br.readLine().split(" ");
            int u=Integer.parseInt(num[0]);
            int v=Integer.parseInt(num[1]);

            adj.get(u).add(v);
            adj.get(v).add(u);
        }
        
        visited = new boolean[n + 1];

        maxLevel = 0; // level
        maxNode = 1; // node

        dfs(1, 0);
        
        maxLevel = 0;

        Arrays.fill(visited, false);
        dfs(maxNode, 0);

        System.out.println(maxLevel);
    }
}
