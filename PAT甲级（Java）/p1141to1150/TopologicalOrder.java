package p1141to1150;

import java.io.IOException;
import java.util.Scanner;

/**
 * 1146 Topological Order（25 point(s)）
 *      * check point 4 time out
 */
public class TopologicalOrder {
    private static Scanner scanner = new Scanner(System.in);
    static private class Graph {
        private final int node_quantity;
        int[][] nodes_map;
        int[] check_table;

        Graph() throws IOException {
            int node_quantity = scanner.nextInt();
            int edge_quantity = scanner.nextInt();
            this.node_quantity = node_quantity;
            this.nodes_map = new int[node_quantity + 1][node_quantity + 1];
            check_table = new int[node_quantity + 1];
            init(edge_quantity);
        }

        void init(final int total) throws IOException {
            for (int i = 0; i < total; i++) {
                int from = scanner.nextInt();
                int to = scanner.nextInt();
                nodes_map[from][to] = 1;
            }
        }

        void checkAll() {
            final int check_counts = scanner.nextInt();
            StringBuilder builder = new StringBuilder();
            for (int i = 0; i < check_counts; i++) {
                if (!check()) {
                    builder.append(i).append(" ");
                }
                check_table = new int[node_quantity + 1];
            }
            builder.deleteCharAt(builder.length() - 1);
            System.out.println(builder);
        }

        boolean check() {
            boolean isTopology = true;
            for (int j = 0; j < node_quantity; j++) {
                int node_index = scanner.nextInt();
                if (!isTopology) {
                    continue;
                }
                check_table[node_index] = 1;
                for (int i = 1; i <= node_quantity; i++) {
                    int node = nodes_map[i][node_index];
                    if (node == 1 && check_table[i] != 1) {
                        isTopology = false;
                        break;
                    }
                }
            }
            return isTopology;
        }
    }

    /**
     * 1146 Topological Order（25 point(s)）
     * check point 4 time out
     */
    public static void main(String[] args) throws IOException {
        Graph graph = new Graph();
        graph.checkAll();
    }
}
