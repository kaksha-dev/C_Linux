/**
 * https://codeforces.com/problemset/problem/1520/D
 */

import java.util.Scanner;
import java.util.Map;
import java.util.HashMap;

public class Difference {

    public static long sol (int[] arr, int n) {
        Map <Integer, Integer> map = new HashMap<>();
        long result = 0;

        for (int i = 0; i < n; i++) {
            int x = arr[i] - i;

            // check if pair exists
            if (map.containsKey(x)) {
                result = result + map.get(x);
                map.put(x, map.get(x) + 1);
            } else {
                map.put(x, 1);
            }
        }
        
        return result;
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
                
            long result = sol(arr, n);
            System.out.println(result);
        }
        
        sc.close();
    }
}
