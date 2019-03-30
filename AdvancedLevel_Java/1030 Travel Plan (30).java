import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.LinkedList;
import java.util.PriorityQueue;

public class Main {
    static BufferedReader reader = new BufferedReader(new InputStreamReader(System.in));

    static class Info {
        int distance, cost;

        Info(int distance, int cost) {
            this.distance = distance;
            this.cost = cost;
        }
    }

    static class Graph {
        private final int vertex, edges, end, start;
        private final Info[][] tables;

        Graph() throws IOException {
            String[] split = reader.readLine().split(" ");
            this.vertex = Integer.valueOf(split[0]);
            this.edges = Integer.valueOf(split[1]);
            this.start = Integer.valueOf(split[2]);
            this.end = Integer.valueOf(split[3]);

            tables = new Info[vertex][vertex];
            for (int i = 0; i < edges; i++) {
                String[] lineInfo = reader.readLine().split(" ");
                int s = Integer.valueOf(lineInfo[0]);
                int e = Integer.valueOf(lineInfo[1]);
                int distance = Integer.valueOf(lineInfo[2]);
                int cost = Integer.valueOf(lineInfo[3]);
                tables[s][e] = new Info(distance, cost);
                tables[e][s] = new Info(distance, cost);
            }
        }

        Node bfs() {
            Node node = new Node(start);
            boolean[] checkTable = new boolean[vertex];
            PriorityQueue<Node> queue = new PriorityQueue<>();
            queue.add(node);
            while (!queue.isEmpty()) {
                Node poll = queue.poll();
                if (poll.id == end) {
                    return poll;
                }
                checkTable[poll.id] = true;
                for (int i = 0; i < vertex; i++) {
                    Info info = tables[poll.id][i];
                    if (info != null && !checkTable[i]) {
                        Node newNode = new Node(i);
                        newNode.previous = poll;
                        newNode.distance = poll.distance + info.distance;
                        newNode.cost = poll.cost + info.cost;
                        queue.offer(newNode);
                    }
                }
            }
            return null;
        }
    }

    static class Node implements Comparable<Node> {
        int id, distance, cost;
        Node previous;

        Node(int id) {
            this.id = id;
        }

        @Override
        public int compareTo(Node o) {
            int compare = distance - o.distance;
            if (compare == 0) {
                compare = id - o.id;
            }
            return compare == 0 ? cost - o.cost : compare;
        }
    }

    public static void main(String[] args) throws IOException {
        Graph graph = new Graph();
        Node bfs = graph.bfs();
        LinkedList<String> list = new LinkedList<>();
        list.addFirst(String.valueOf(bfs.cost));
        list.addFirst(String.valueOf(bfs.distance));
        while (bfs != null) {
            list.addFirst(String.valueOf(bfs.id));
            bfs = bfs.previous;
        }
        int last = list.size() - 1;
        int start = 0;
        for (String o : list) {
            System.out.printf("%s%s", o, start == last ? "\n" : " ");
            start++;
        }
    }
}