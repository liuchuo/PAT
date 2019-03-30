package basicLevel;

//1016 部分A+B （15 分）
//        正整数 A 的“D
//        ​A
//        ​​ （为 1 位整数）部分”定义为由 A 中所有 D
//        ​A
//        ​​  组成的新整数 P
//        ​A
//        ​​ 。例如：给定 A=3862767，D
//        ​A
//        ​​ =6，则 A 的“6 部分”P
//        ​A
//        ​​  是 66，因为 A 中有 2 个 6。
//
//        现给定 A、D
//        ​A
//        ​​ 、B、D
//        ​B
//        ​​ ，请编写程序计算 P
//        ​A
//        ​​ +P
//        ​B
//        ​​ 。
//
//        输入格式：
//        输入在一行中依次给出 A、D
//        ​A
//        ​​ 、B、D
//        ​B
//        ​​ ，中间以空格分隔，其中 0<A,B<10
//        ​10
//        ​​ 。
//
//        输出格式：
//        在一行中输出 P
//        ​A
//        ​​ +P
//        ​B
//        ​​  的值。
//
//        输入样例 1：
//        3862767 6 13530293 3
//        输出样例 1：
//        399
//        输入样例 2：
//        3862767 1 13530293 8
//        输出样例 2：
//        0
import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;

public class T1016 {
    public static void main(String[] args) throws IOException {


        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        String str = br.readLine();
        String[] strs = str.split(" ");
        char[] a1 = strs[0].toCharArray();
        int d1 = Integer.parseInt(strs[1]);
        char[] a2 = strs[2].toCharArray();
        int d2 = Integer.parseInt(strs[3]);
        int i,sum1 = 0,sum2 = 0;
        for (i = 0; i< a1.length;i++){
            if ((a1[i] - '0') == d1){
                sum1 = sum1 * 10 + d1;
            }
        }
        for (i = 0;i < a2.length;i++){
            if ((a2[i] - '0') == d2){
                sum2 = sum2 * 10 + d2;
            }
        }
        System.out.println(sum1 +sum2);
    }
}
