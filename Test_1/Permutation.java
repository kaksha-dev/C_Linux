/**
 * https://codeforces.com/problemset/problem/1490/D
 */

import java.util.Scanner;

public class Permutation {

    public static void findDepth(int left, int right, int[]arr, int[]result, int current) {
        if (right < left) {
            return;
        }

        if (left == right) {
            result[left] = current;
        }

        // largest element in segment
        int largest = left;
        for (int i = left + 1; i <= right; i++) {
            if (arr[largest] < arr[i])
                 largest = i;
        }

        result[largest] = current;

        // left subtree
        findDepth(left, largest - 1, arr, result, current + 1);
        // right subtree
        findDepth(largest + 1, right, arr, result, current + 1);

    }

    public static void sol (int[] arr, int n) {
        int[] result = new int[n];

        // depth of root is 0
        findDepth(0, n - 1, arr, result,0);
       
        for(int i = 0; i < n; i++) {
            System.out.print(result[i]+" ");
        }
        System.out.println();

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
