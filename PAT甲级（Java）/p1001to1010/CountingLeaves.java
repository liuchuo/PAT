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

    private static int[] readerLine() throws IOException {
        String[] split = reader.readLine().split(" ");
        int[] result = new int[split.length];
        for (int i = 0; i < split.length; i++) {
            result[i] = Integer.valueOf(split[i]);
        }
        return result;
    }
    //tree nodes
    static int[][] nodes = new int[100][];
//    static LinkedList<Integer>[] nodes = new LinkedList[100];
    //id => level
    static int[] level=new int[100];
    //counts of level
    static int [] book=new int[100];
    //最大层数
    static int max_level=-1;
    /**
     * 广度优先,层序遍历
     */
    private static void bfs() {
        Queue<Integer> queue = new LinkedList<>();
        queue.offer(1);

        while (!queue.isEmpty()) {
            int poll = queue.poll();

            int[] children = nodes[poll];
//            LinkedList<Integer> children = nodes[poll];

            max_level=Math.max(level[poll],max_level);
            if (children == null||children.length==0) {
//            if (children == null||children.size()==0) {
               book[level[poll]]++;
            } else {
                for (int aChildren : children) {
                    queue.add(aChildren);
                    level[aChildren] = level[poll] + 1;
                }
            }
        }
    }

    /**
     * 卡在测试点4
     * 完全找不到原因.....,c++就可以过
     * @param args
     * @throws IOException
     */
    public static void main(String[] args) throws IOException {
        int[] ints = readerLine();

        int lines = ints[1];
        for (int i = 0; i < lines; i++) {
            int[] line = readerLine();
            int id = line[0];
            int size = line.length - 2;
            nodes[id] = new int[size];
            System.arraycopy(line, 2, nodes[id], 0, size);
//            if(nodes[id]==null){
//                nodes[id] = new LinkedList<>();
//            }
//            for (int j = 2; j < line.length; j++) {
//               nodes[id].add(line[j]);
//            }
        }
        bfs();
        StringBuilder builder = new StringBuilder(100);
        builder.append(book[0]);
        for (int i = 1; i <= max_level; i++) {
            builder.append(" ").append(book[i]);
        }
        System.out.println(builder);
    }
}
