package p1021to1030;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;

/**
 * 1029 Median（25 分）
 * java启动20m .. 内存超限
 */
public class Median {
    /**
     * 1029 Median（25 分）
     */
    public static void main(String[] args) throws IOException {
        BufferedReader reader = new BufferedReader(new InputStreamReader(System.in));
        String[] line1 = reader.readLine().split(" ");
        String[] line2 = reader.readLine().split(" ");
        int[] resultLine = new int[line1.length + line2.length - 2];

        int start1 = 1, start2 = 1, rStart = 0;
        while (start1 < line1.length && start2 < line2.length) {
            int i1 = Integer.valueOf(line1[start1]);
            int i2 = Integer.valueOf(line2[start2]);
            if (i1 <= i2) {
                resultLine[rStart] = i1;
                start1++;
            } else {
                resultLine[rStart] = i2;
                start2++;
            }
            rStart++;
        }
        addRemain(start1, line1, rStart, resultLine);
        addRemain(start2, line2, rStart, resultLine);
        int index = (resultLine.length - 1) / 2;
        System.out.println(resultLine[index]);
    }

    private static void addRemain(int start, String[] line, int rStart, int[] resultLine) {
        if (start < line.length) {
            for (int i = start; i < line.length; i++) {
                resultLine[rStart] = (Integer.valueOf(line[i]));
            }
        }

    }
}
