/**
 * https://www.codechef.com/problems/CEQUAL
 */

import java.util.Scanner;
import java.util.Set;
import java.util.HashSet;

public class Duplicates {

    public static void sol (int[] arr, int n) {
        Set<Integer> set = new HashSet<>();
        // add to set
        for (int i = 0; i < n; i++) {
             set.add(arr[i]);
        }

        if (set.size() == n) {
            System.out.println("No");
        } else {
            System.out.println("Yes");
        }        
    }

    public static void main (String[] args) {

        Scanner sc  = new Scanner(System.in);
	    int test = sc.nextInt();

        while(test-- > 0) {
            int n = sc.nextInt();
            int[] arr = new int[n];
            
            for(int i = 0; i < n; i++) {
                arr[i] = sc.nextInt();
            }
              
            sol(arr, n);
        }
        sc.close();
    }
}
