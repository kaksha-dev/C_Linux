/**
 * https://www.codechef.com/problems/ALTARAY
 */

import java.util.Scanner;

public class LengthSubarray
{   
    public static void sol (long[] arr, int n) {
        long[] result = new long[n];
        // 1st value
        result[n - 1] = 1;

        // check for subarray
        for (int i = (n - 2); i >= 0; i--) {
            
             if ((arr[i] * arr[i + 1]) <= 0) {
                result[i] = result[i + 1] + 1;
            } else {
                result[i] = 1;
            }
        }
        
        for(int i = 0; i < n; i++) {
            System.out.print(result[i] + " ");
        }
        System.out.println();
    }

	public static void main(String[] args) {

	    Scanner sc  = new Scanner(System.in);
	    int test = sc.nextInt();

        while(test-- > 0) {
            int n = sc.nextInt();
            long[] arr = new long[n];
            
            for(int i = 0; i < n; i++) {
                arr[i] = sc.nextLong();
            }
            
            sol(arr, n);   
        }
        
        sc.close();
	}
}


