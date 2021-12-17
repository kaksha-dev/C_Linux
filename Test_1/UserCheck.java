/**
 * https://codeforces.com/problemset/problem/4/C
 */

import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.util.Map;
import java.util.HashMap;
import java.io.IOException;

public class UserCheck {

    public static void sol (String[] arr, int n) {
        Map <String, Integer> map = new HashMap<>();
        String str = "";

        for (int i = 0; i < n; i++) {
            str = arr[i];

            //  check if registered
            if (map.containsKey(str)) {
                System.out.println(str + map.get(arr[i]));
                // new name
                map.put(str, map.get(str) + 1 );
            } else {
                map.put(str, 1);
                System.out.println("OK");
            }
        }   
    }

    public static void main (String[] args) throws IOException{
        
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        int n = Integer.parseInt(br.readLine());

        String[] arr = new String[n];

        for (int i = 0; i < n; i++) {
            arr[i] = br.readLine();
        }
    
        sol(arr, n);
    }
}
