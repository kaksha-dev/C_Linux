/**
 * https://www.hackerrank.com/challenges/icecream-parlor/problem
 */

import java.util.Scanner;
import java.util.Map;
import java.util.HashMap;

public class Icecream {

    public static int[] sol (int[] arr, int n, int k) {
        int result[] = new int[2];
        Map <Integer, Integer> map = new HashMap<>();

        for (int i = 0; i < n; i++) {
            // check if pair exists
            if (map.containsKey(k - arr[i])) {
                result[0] = map.get(k - arr[i]) + 1;
                result[1] = (i + 1);
                break;
            }

            map.put(arr[i], i);
        }
        return result;
    }

    public static void main (String[] args) {

        Scanner sc  = new Scanner(System.in);
	    int test = sc.nextInt();
        
        while(test-- > 0) {
            int k = sc.nextInt();
            int n = sc.nextInt();
            int[] arr = new int[n];
            
            for(int i = 0; i < n; i++) {
                arr[i] = sc.nextInt();
            }

            int[] result = sol (arr, n, k);
        }
        sc.close();
    }
}
