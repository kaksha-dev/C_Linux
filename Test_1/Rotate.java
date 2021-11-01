/**
 *  https://www.hackerrank.com/challenges/array-left-rotation/problem
 */

import java.util.Scanner;
import java.util.Map;
import java.util.HashMap;

public class Rotate {

    public static int[] sol (int[] arr, int n, int d) {
        int[] result = new int[n];

        for (int i = 0; i < n; i++) {
            // new location
            result[(i + n - d)%n] = arr[i];
        }

        return result;
    }
    
    public static void main (String[] args) {

        Scanner sc  = new Scanner(System.in);
	    int test = sc.nextInt();

        while(test-- > 0) {
            int n = sc.nextInt();
            int d = sc.nextInt();
            int[] arr = new int[n];
            
            for(int i = 0; i < n; i++) {
                arr[i] = sc.nextInt();
            }

            int result[] = sol(arr, n, d);
        }
        sc.close();
    }
}
