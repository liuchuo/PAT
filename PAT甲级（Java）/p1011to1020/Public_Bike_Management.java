package p1011to1020;

import java.util.LinkedList;
import java.util.PriorityQueue;
import java.util.Scanner;

/**
 * 1018 Public Bike Management (30)（30 分）
 * check point 9  error
 */
public class Public_Bike_Management {
    static Scanner scanner = new Scanner(System.in);

    static class Node implements Comparable<Node> {
        int id;
        int score;
        Node previous;
        int weight;

        Node(int id, int score, int weight) {
            this.id = id;
            this.score = score;
            this.weight = weight;
        }

        @Override
        public int compareTo(Node o) {
            int compare = this.score - o.score;
            if(compare==0){
                compare= id-o.id;
                if(compare==0){
                    return hashCode()-o.hashCode();
                }
            }
            return compare;
        }

        @Override
        public String toString() {
            return "Node{" +
                    "id=" + id +
                    ", score=" + score +
                    ", previous=" + previous +
                    '}';
        }
    }

    static class Graph {
        //节点权重最大值
        private static int vertex_capacity;
        //问题节点
        private static int problem_index;
        //节点数
        private final int vertex_quantity;
        //邻接表
        int[][] table;
        //节点权重 table
        int[] vertex_weight;

        Graph() {
            vertex_capacity = scanner.nextInt();
            this.vertex_quantity = scanner.nextInt() + 1;
            problem_index = scanner.nextInt();
            int edges = scanner.nextInt();
            table = new int[vertex_quantity][vertex_quantity];
            vertex_weight = new int[vertex_quantity];
            for (int i = 1; i < vertex_quantity; i++) {
                int weight = scanner.nextInt();
                vertex_weight[i] = weight;
            }

            for (int i = 0; i < edges; i++) {
                int start = scanner.nextInt();
                int end = scanner.nextInt();
                int distance = scanner.nextInt();
                table[start][end] = distance;
                table[end][start] = distance;
            }


        }

        /**
         * 求最短路径
         *
         * @return 所有最短路径列表
         */
        LinkedList<Node> dijkstra() {
            final int start = 0;
            int[] checkTable = new int[vertex_capacity];
            PriorityQueue<Node> queue = new PriorityQueue<>(501);
            queue.offer(new Node(start, 0, 0));
            LinkedList<Node> minPathList = new LinkedList<>();


            while (queue.size() > 0) {
                Node poll = queue.poll();
                if (poll.id == problem_index) {
                    minPathList.add(poll);
                    while (queue.size() > 0) {
                        Node node = queue.poll();
                        if (node.id == poll.id && node.score == poll.score) {
                            minPathList.add(node);
                        } else {
                            break;
                        }
                    }
                    return minPathList;
                } else {
                    checkTable[poll.id] = 1;
                }

                for (int i = 0; i < vertex_quantity; i++) {
                    int distance = table[poll.id][i];
                    if (distance != 0 && checkTable[i] != 1) {
                        Node next = new Node(i,
                                distance + poll.score,
                                vertex_weight[i]);
                        next.previous = poll;
                        queue.offer(next);
                    }
                }
            }


            return minPathList;
        }
    }

    /**
     * 1018 Public Bike Management (30)（30 分）
     * check point 9 error
     * @param args
     * @throws Exception
     */
    public static void main(String[] args) throws Exception {
        Graph graph = new Graph();
        int healthCapacity = Graph.vertex_capacity / 2;
        LinkedList<Node> dijkstra = graph.dijkstra();

        int minNeed = Integer.MAX_VALUE;
        int minBack = Integer.MAX_VALUE;
        StringBuilder minPath = null;
        //回溯所有结果,找出符合条件的结果
        for (Node node : dijkstra) {
            Node tail = node;
            int need = 0;
            int back = 0;
            StringBuilder builder = new StringBuilder();
            while (tail.id != 0) {
                builder.append(tail.id);
                int weight = tail.weight;
                int remain = weight - healthCapacity;
                need = need - remain;
                if (need < 0) {
                    back -= need;
                    need = 0;
                }
                tail = tail.previous;
            }
//            outPut(builder,need,back);
            if (need == minNeed && back < minBack) {
                minNeed = need;
                minBack = back;
                minPath = builder;
            } else if (need < minNeed) {
                minNeed = need;
                minBack = back;
                minPath = builder;
            }
        }
        outPut(minPath,minNeed,minBack);
    }
    private static void outPut(StringBuilder minPath, int minNeed, int minBack) throws Exception {
        if (minPath == null) {
            throw new Exception("no path!");
        }
        System.out.printf("%d%s", minNeed, " 0-");
        int lastIndex = minPath.length() - 1;
        for (int i = lastIndex; i >= 0; i--) {
            int id = minPath.charAt(i) - 48;
            System.out.printf("%s%d%s", ">", id, i == 0 ? " " : "-");
        }
        System.out.println(minBack == Integer.MAX_VALUE ? 0 : minBack);
    }
}
