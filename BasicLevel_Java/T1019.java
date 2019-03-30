package basicLevel;

//1019 数字黑洞 （20 分）
//        给定任一个各位数字不完全相同的 4 位正整数，如果我们先把 4 个数字按非递增排序，再按非递减排序，然后用第 1 个数字减第 2 个数字，将得到一个新的数字。一直重复这样做，我们很快会停在有“数字黑洞”之称的 6174，这个神奇的数字也叫 Kaprekar 常数。
//
//        例如，我们从6767开始，将得到
//
//        7766 - 6677 = 1089
//        9810 - 0189 = 9621
//        9621 - 1269 = 8352
//        8532 - 2358 = 6174
//        7641 - 1467 = 6174
//        ... ...
//        现给定任意 4 位正整数，请编写程序演示到达黑洞的过程。
//
//        输入格式：
//        输入给出一个 (0,10
//        ​4
//        ​​ ) 区间内的正整数 N。
//
//        输出格式：
//        如果 N 的 4 位数字全相等，则在一行内输出 N - N = 0000；否则将计算的每一步在一行内输出，直到 6174 作为差出现，输出格式见样例。注意每个数字按 4 位数格式输出。
//
//        输入样例 1：
//        6767
//        输出样例 1：
//        7766 - 6677 = 1089
//        9810 - 0189 = 9621
//        9621 - 1269 = 8352
//        8532 - 2358 = 6174
//        输入样例 2：
//        2222
//        输出样例 2：
//        2222 - 2222 = 0000


import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.Arrays;


public class T1019 {
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        String str = br.readLine();
        int num = Integer.parseInt(str);
        while (true){
            int m = inc(num);
            int n = desc(num);
            num = m - n;
            System.out.printf("%04d - %04d = %04d\n",m,n,num);
            if (num == 6174 || num == 0){
                break;
            }
        }
    }
    public static int desc(int number) {
        char[] array = String.format("%04d", number).toCharArray();
        Arrays.sort(array);
        int temp = 0;
        for (int i = 0; i < 4; i++) {
            temp = temp * 10 + (array[i] - '0');
        }
        return temp;
    }

    public static int inc(int number) {
        char[] array = String.format("%04d", number).toCharArray();
        Arrays.sort(array);
        int temp = 0;
        for (int i = 3; i >= 0; i--) {
            temp = temp * 10 + (array[i] - '0');
        }
        return temp;
    }
}
