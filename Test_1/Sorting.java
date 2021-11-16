/**
 * https://www.codechef.com/problems/KJCP01
 */

import java.util.Scanner;
import java.util.Map;
import java.util.HashMap;
import java.util.List;
import java.util.ArrayList;
import java.util.Collections;
import java.util.Comparator;

public class Sorting {
    // node
    private class Node {
        int value;
        int index;
        int frequency;

        public Node (int value, int index, int frequency) {
            this.value = value;
            this.index = index;
            this.frequency = frequency;
        }
    }

    // custom compare for node
    class NodeComparator implements Comparator<Node> {
        @Override
        public int compare(Node a, Node b) {

            if (a.frequency == b.frequency) {
                // based on index
                return (a.index < b.index) ? -1 : 1;
            } else {
                // larger frequency
                return (a.frequency > b.frequency) ? -1 : 1;
            }
        }
    }

    public void sol (int[] arr, int n) {
        Map <Integer, Integer> frequency = new HashMap<>();
        Map <Integer, Integer> index = new HashMap<>();

        for (int i = 0; i < n; i++) {
            // index
            if (!index.containsKey(arr[i])) {
                index.put(arr[i], i);
            }
                    
            // frequency
            if (frequency.containsKey(arr[i])) {
                frequency.put(arr[i], frequency.get(arr[i]) + 1);
            } else {
                frequency.put(arr[i], 1);
            }
        }

        // arraylist of nodes
        List <Node> list = new ArrayList<>();
        for (Map.Entry<Integer, Integer> entry : frequency.entrySet()) {
            list.add(new Node(entry.getKey(), index.get(entry.getKey()), entry.getValue()));
        }

        // sort
        Collections.sort(list, new NodeComparator());

        // display
        for (Node node : list) {
            for (int i = 0; i < node.frequency; i++) {
                System.out.println(node.value);
            }
        }
    }

    public static void main (String[] args) {

        Scanner sc  = new Scanner(System.in);

        int n = sc.nextInt();
        int m = sc.nextInt();
        int[] arr = new int[n];
            
        for(int i = 0; i < n; i++) {
            arr[i] = sc.nextInt();
        }

        Sorting obj = new Sorting();
        obj.sol(arr,n);       

        sc.close();
    }
}

       