package basicLevel;
//美国总统奥巴马不仅呼吁所有人都学习编程，甚至以身作则编写代码，成为美国历史上首位编写计算机代码的总统。2014 年底，为庆祝“计算机科学教育周”正式启动，奥巴马编写了很简单的计算机代码：在屏幕上画一个正方形。现在你也跟他一起画吧！
//
//        输入格式：
//        输入在一行中给出正方形边长 N（3≤N≤20）和组成正方形边的某种字符 C，间隔一个空格。
//
//        输出格式：
//        输出由给定字符 C 画出的正方形。但是注意到行间距比列间距大，所以为了让结果看上去更像正方形，我们输出的行数实际上是列数的 50%（四舍五入取整）。
//
//        输入样例：
//        10 a
//        输出样例：
//        aaaaaaaaaa
//        a        a
//        a        a
//        a        a
//        aaaaaaaaaa

// 思路：找到图形的特点，即第一行 最后一行满行，其余行除第一个为输入字符，其余为空白 找到规律判断即可，四舍五入为 (int)((n * 0.5) + 0.5)


import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;

public class T1036 {
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        String[] str = br.readLine().split(" ");
        int n = Integer.valueOf(str[0]);
        char c = str[1].charAt(0);
        int m = (int) ((n * 0.5) + 0.5);
        for (int i = 0; i < m; i++){
            for (int j = 0; j < n; j++){
               if (i == 0 || i == m - 1){
                   System.out.print(c);
               }else {
                   if (j == 0 || j == n - 1){
                       System.out.print(c);
                   }else {
                       System.out.print(" ");
                   }
               }
            }
            System.out.println();
        }

    }
}
