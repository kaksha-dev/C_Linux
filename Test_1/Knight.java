/**
 * https://www.spoj.com/problems/NAKANJ/
 */

import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.io.IOException;
import java.util.Queue;
import java.util.LinkedList;

class Knight {
    
    static boolean[][] chessBoard;
    static boolean[][] visited;

    static class Position {
        // a to h
        int first;
        // 1 to 8
        int second;

        Position (String input) {
            this.first = input.charAt(0) - 97;
            this.second = Integer.parseInt("" + input.charAt(1)) - 1;
        }

        Position (int first, int second) {
            this.first = first;
            this.second = second;
        }

        boolean equals (Position pos) {
            return this.first == pos.first && this.second == pos.second;
        }
    }

    // valid indices of chessboard
    public static boolean isValid (int x, int y) {
        return (x < 0 || y < 0 || x >= 8 || y >= 8) ? false : true;
    }

    public static int bfs (Position start, Position destination) {
        // possible positions
        int[] x = { -1, -2, -2, -1, 1, 2, 2, 1 };
        int[] y = { -2, -1, 1, 2, -2, -1, 1, 2 };

        Queue<Position> queue = new LinkedList<Position>();
        int result = 0;

        queue.add(start);
        visited[start.first][start.second] = true;

        while (!queue.isEmpty()) {
            int size = queue.size();
            
            for (int i = 0; i < size; i++) {
                Position pos = queue.poll();

                if (pos.equals(destination)) {
                    return result;
                }
                    
                // valid positions
                for (int j = 0; j < 8; j++) {
                    int newX = pos.first + x[j];
                    int newY = pos.second +y[j];

                    if (isValid(newX, newY) && !visited[newX][newY]) {
                        // store next position
                        queue.offer(new Position(newX, newY));
                        visited[newX][newY] = true;
                    }
                }       
            }

            result++;
        }

        return -1;
    }

    public static void main (String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        int test = Integer.parseInt(br.readLine());

        while (test-- > 0) {
            chessBoard = new boolean[8][8];
            visited = new boolean[8][8];

            String[] str = br.readLine().split(" ");
            Position start = new Position(str[0]);
            Position destination = new Position(str[1]);

            int result = bfs(start, destination);
            System.out.println(result);
        }
    }
}