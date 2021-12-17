/**
 * https://codeforces.com/problemset/problem/447/A
 */

import java.util.Scanner;

public class Hash {

    public static int sol (int[] arr, int n, int p) {
        // hash values
        boolean[] hash = new boolean[p];

        for (int i = 0; i < n; i++) {
            int hashVal = (arr[i] % p);

            if(hash[hashVal]) {
                // duplicate case
                return (i + 1);
            } else {
                hash[hashVal] = true;
            }
        }

        return -1;
    }

    public static void main (String[] args) {

        Scanner sc  = new Scanner(System.in);
        
        int p = sc.nextInt();
        int n = sc.nextInt();
        int[] arr = new int[n];
            
        for(int i = 0; i < n; i++) {
            arr[i] = sc.nextInt();
        }
                
        int result = sol(arr, n, p);
        System.out.println(result);

        sc.close();
    }
}
