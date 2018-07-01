package p1011to1020;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;

/**
 * 1013 Battle Over Cities (25)（25 分）
 */
public class Battle_Over_Cities {

    //矩阵
    static int[][] cityMap;
    //访问检查table
    static int[] checkTable;


    /**
     * deep first
     * 遍历图,统计非连通区域
     *
     * @return 非通区域数
     */
    static int dfs() {
        int dfs_counts = 0;
        for (int i = 1; i < checkTable.length; i++) {
            if (checkTable[i] != 1) {
                dfs_counts++;
                dfs(i);
            }
        }
        return dfs_counts <= 1 ? 0 : dfs_counts - 1;
    }

    private static void dfs(int start) {
        checkTable[start] = 1;
        int[] list = cityMap[start];
        for (int i = 1; i < list.length; i++) {
            if (checkTable[i] != 1 && list[i] != 0) {
                dfs(i);
            }
        }
    }
    static BufferedReader reader = new BufferedReader(new InputStreamReader(System.in),1024*1024);

    /**
     * 会超时..... 邻接矩阵和邻接表都一样
     * 数据都读不完。。。,估计是最大路径n*(n-1)
     * 试了一下c++版本,需要176ms
     * nnd
     * @param args
     * @throws IOException
     */
    public static void main(String[] args) throws IOException {
        //node size
        int cityNumbers;
        String line = reader.readLine();
        String[] split = line.split(" ");
        //节点数
        cityNumbers = Integer.valueOf(split[0]);
        //下标从1开始,用了一个空位置
        cityMap = new int[cityNumbers + 1][cityNumbers + 1];
        checkTable = new int[cityNumbers + 1];

        for (int i = 0; i < Integer.valueOf(split[1]); i++) {
            String[] roads = reader.readLine().split(" ");
            int c1 = Integer.valueOf(roads[0]);
            int c2 = Integer.valueOf(roads[1]);
            cityMap[c1][c2] = 1;
            cityMap[c2][c1] = 1;
        }
        //check list 需要检查的城市列表
        //checked 1 ;; unchecked 0
        String[] checkList = reader.readLine().split(" ");
        for (String number : checkList) {
            checkTable[Integer.valueOf(number)] = 1;
            int dfs = dfs();
            System.out.println(dfs);
            checkTable = new int[cityNumbers + 1];
        }
    }
}
