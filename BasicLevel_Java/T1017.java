package basicLevel;

//1017 A除以B （20 分）
//        本题要求计算 A/B，其中 A 是不超过 1000 位的正整数，B 是 1 位正整数。你需要输出商数 Q 和余数 R，使得 A=B×Q+R 成立。
//
//        输入格式：
//        输入在一行中依次给出 A 和 B，中间以 1 空格分隔。
//
//        输出格式：
//        在一行中依次输出 Q 和 R，中间以 1 空格分隔。
//
//        输入样例：
//        123456789050987654321 7
//        输出样例：
//        17636684150141093474 3

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;

public class T1017 {
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        String str = br.readLine();
        String[] strs = str.split(" ");
        char[] c = strs[0].toCharArray();
        int n = Integer.parseInt(strs[1]);
        int t = 0, tmp = 0;
        t = (c[0] - '0')/n;
        if (t != 0 && c.length > 1 || c.length == 1){
            System.out.print(t);
        }
        tmp = (c[0] - '0') % n;
        for (int i = 1 ;i < c.length ;i++){
            t = (tmp * 10 + c[i] - '0') / n;
            System.out.print(t);
            tmp = (tmp * 10 + c[i] - '0') % n;
        }
        System.out.print(" " + tmp);
    }
}
