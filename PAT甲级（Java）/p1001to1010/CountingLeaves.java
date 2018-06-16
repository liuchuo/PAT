package PTA.p1001to1010;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.LinkedList;
import java.util.Queue;

/**
 * 1004 Counting Leaves (30)（30 分）
 */
public class CountingLeaves {
    static BufferedReader reader = new BufferedReader(new InputStreamReader(System.in));

    static int[] readerLine() throws IOException {
        String[] split = reader.readLine().split(" ");
        int[] result = new int[split.length];
        for (int i = 0; i < split.length; i++) {
            result[i] = Integer.valueOf(split[i]);
        }
        return result;
    }

    static class Tree {
        //tree nodes
        int[][] nodes = new int[100][];
        int node_numbers = 0;

        /**
         * build Tree
         *
         * @throws IOException
         */
        public Tree() throws IOException {
            int[] ints = readerLine();
            this.node_numbers = ints[0];

            int lines = ints[1];
            for (int i = 0; i < lines; i++) {
                ints = readerLine();
                nodes[ints[0]] = ints;
            }

        }

        /**
         * 广度优先,层序遍历
         */
        String bfs() {
            int leaves = 0;
            int now_level = 0;
            int[] node_levels = new int[100];
            StringBuilder builder = new StringBuilder();
            Queue<Integer> queue = new LinkedList<>();
            queue.add(1);
            while (!queue.isEmpty()) {
                int poll = queue.poll();
                int[] children = nodes[poll];
                final int node_level = node_levels[poll];

                if (now_level < node_level) {
                    builder.append(leaves).append(" ");
                    leaves = 0;
                    now_level++;
                }
                if (children == null) {
                    leaves++;
                } else {
                    //初始下标为2
                    for (int i = 2; i < children.length; i++) {
                        queue.add(children[i]);
                        node_levels[children[i]] = node_level + 1;
                    }
                }
            }
            builder.append(leaves);
            return builder.toString();
        }
    }

    /**
     * 卡在测试点4
     * @param args
     * @throws IOException
     */
    public static void main(String[] args) throws IOException {
        Tree tree = new Tree();
        System.out.println(tree.bfs());
    }
}
