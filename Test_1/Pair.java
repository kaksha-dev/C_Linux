/**
 * https://www.codechef.com/problems/BUTYPAIR
 */

import java.util.Scanner;
import java.util.Map;
import java.util.HashMap;
import java.util.Iterator;

public class Pair {

    public static int sol (int[] arr, int n) {
        Map <Integer, Integer> map = new HashMap<>();
        int result = 0;

        for (int i = 0; i < n; i++) {
            // check if pair exists
            if (map.containsKey(arr[i])) {
                map.put(arr[i], map.get(arr[i]) + 1);
            } else {
                map.put(arr[i], 1);
            }
        }
        
        for (Integer freq : map.values()) {
            result = result + freq * (n - freq);
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
                
            int result = sol(arr, n);
            System.out.println(result);
        }
        
        sc.close();
    }
}
