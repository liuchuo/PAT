

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;

public class Main {
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        char[] chs = br.readLine().toCharArray();
        int[] flag = new int[128];
        for (int i = 0; i < chs.length; i++) {
            flag[chs[i]]++;
        }
        while (flag['P'] > 0|| flag['A'] > 0|| flag['T'] > 0|| flag['e'] > 0|| flag['s'] > 0||flag['t'] > 0) {
            if (flag['P'] -- > 0) {
                System.out.print("P");
            }
            if (flag['A'] -- > 0) {
                System.out.print("A");
            }
            if (flag['T'] -- > 0) {
                System.out.print("T");
            }
            if (flag['e'] -- > 0) {
                System.out.print("e");
            }
            if (flag['s'] -- > 0) {
                System.out.print("s");
            }
            if (flag['t'] -- > 0) {
                System.out.print("t");
            }

        }
    }
}
