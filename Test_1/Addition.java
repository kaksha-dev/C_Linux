/**
 * https://codeforces.com/problemset/problem/1584/A
 */

import java.util.Scanner;

public class Addition {

    public static void sol (int u, int v) {
       
        long x = - u * u;
        long y = v * v;

        System.out.println(x+" "+y);
    }

    public static void main (String[] args) {

        Scanner sc  = new Scanner(System.in);
	    int test = sc.nextInt();

        while(test-- > 0) {
            int u = sc.nextInt();
            int v = sc.nextInt();
  
            sol(u,v);
        }
        
        sc.close();
    }
}
