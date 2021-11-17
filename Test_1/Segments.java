/**
 * https://www.codechef.com/problems/BEARSEG
 */

import java.util.Scanner;
import java.util.TreeMap;

public class Segments {

    public static void sol (int[] arr, int n, int p) {
        long[] prefixSum = new long[n + 1];

        // prefix sum
        for (int i = 1; i <= n; i++) {
            prefixSum[i] = (arr[i - 1] + prefixSum[i - 1]) % p;
        }

        TreeMap<Long, Integer> map = new TreeMap<>();
        map.put(0L, 1);
        
        // maximum sum, current sum, count
        long count = 0;
        long max = 0;
        long sum = 0;

        for(int i = 1; i <=n ; i++) {
            long x = prefixSum[i] % p;
            Long y = map.higherKey(x);

            if(y == null) {
                y = map.firstKey();
            }
            
            sum = (x - y + p) % p;
            
            // max sum and count in each segment
            if(sum > max) {
                max = sum;
                count = 0;
            } 
            if(sum == max) {
                count = count + map.get(y);
            }
            
            // increase frequency
            if(map.containsKey(x)) {
                map.put(x, map.get(x) + 1);
            } else {
                map.put(x,1);
            }
        }

        System.out.println(max+" "+count);
    }

    public static void main (String[] args) {

        Scanner sc  = new Scanner(System.in);
	    int test = sc.nextInt();

        while(test-- > 0) {
            int n = sc.nextInt();
            int p = sc.nextInt();

            int[] arr = new int[n];
            
            for(int i = 0; i < n; i++) {
                arr[i] = sc.nextInt();
            }
                
            sol(arr, n, p);
        }
        
        sc.close();
    }
}
