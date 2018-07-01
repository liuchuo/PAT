package p1021to1030;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.Arrays;
import java.util.LinkedList;
import java.util.PriorityQueue;
import java.util.Scanner;

/**
 * 1021 Deepest Root (25)（25 分）
 */
public class Deepest_Root {
    static BufferedReader reader=new BufferedReader(new InputStreamReader(System.in));
    static Scanner scanner=new Scanner(System.in);

    static class Node implements Comparable<Node> {
        int id;
        int value;

        Node(int id, int value) {
            this.id = id;
            this.value = value;
        }

        @Override
        public int compareTo(Node o) {
            int compare = o.value - value;
            if (compare == 0) {
                return id - o.id;
            }
            return compare;
        }
    }

    static class Graph {
        int vertex;
        LinkedList<Integer>[] table;
        boolean[] checkTable;
        PriorityQueue<Node> deepTable;

        Graph() throws IOException {
            this.vertex=Integer.valueOf(reader.readLine());
            table = new LinkedList[vertex + 1];
            checkTable = new boolean[vertex + 1];
            deepTable = new PriorityQueue<>();
            for (int i = 0; i < vertex - 1; i++) {
                int from=scanner.nextInt();
                int to=scanner.nextInt();
                if (table[from] == null) {
                    table[from] = new LinkedList<>();
                }
                if (table[to] == null) {
                    table[to] = new LinkedList<>();
                }
                table[from].add(to);
                table[to].add(from);
            }
        }

        /**
         * @return 图区域数量
         */
        int travel() {
            int compoments = 1;
            for (int i = 1; i <= vertex; i++) {
                compoments = travel(i);
                if (compoments > 1) {
                    break;
                }
                //clear checkTable
                Arrays.fill(checkTable,false);
            }
            return compoments;
        }

        private int travel(int start) {
            int dfs_counts = 1;
            int deep = dfs(start);
            //连通性测试
            for (int i = 1; i < checkTable.length; i++) {
                if (!checkTable[i]) {
                    dfs(i);
                    dfs_counts++;
                }
            }
            if (dfs_counts == 1) {
                deepTable.offer(new Node(start, deep));
            }
            return dfs_counts;
        }

        /**
         * dfs 返回最大深度
         *
         * @param start
         * @return
         */
        private int dfs(int start) {
            checkTable[start] = true;
            int maxDeep = 0;
            LinkedList<Integer> ids = table[start];
            if (ids == null) return maxDeep;
            for (Integer id : ids) {
                if (!checkTable[id]) {
                    int d = dfs(id) + 1;
                    if (d > maxDeep) {
                        maxDeep = d;
                    }
                }
            }
            return maxDeep;
        }
    }

    /**
     * 1021 Deepest Root (25)（25 分）
     * checkPoint 3 time out
     */
    public static void main(String[] args) throws IOException {
        Graph graph = new Graph();
        int compoments = graph.travel();
        if (compoments > 1) {
            System.out.printf("Error: %d components\n", compoments);
        } else {
            PriorityQueue<Node> deepTable = graph.deepTable;
            int max = deepTable.peek().value;
            while (!deepTable.isEmpty()) {
                Node poll = deepTable.poll();
                if (poll.value < max) {
                    break;
                }
                System.out.println(poll.id);
            }
        }
    }
}
