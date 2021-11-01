/**
 * https://www.codechef.com/problems/SUBINC
 */

import java.util.Scanner;

public class Subarray
{   
    public static long sol (long[] arr, int n) {
        long[] count = new long[n];
        // 1st value
        count[0] = 1;
        long ans = 1;

        for (int i = 1; i < n; i++) {
            if (arr[i] >= arr[i - 1]) {
                count[i] = count[i - 1] + 1;
            } 
            else {
                count[i] = 1;
            }
            ans = ans + count[i];
        }
        return ans;
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
            
            long result  = sol(arr, n);
            System.out.println(result);	   
        }
        
        sc.close();
	}
}


