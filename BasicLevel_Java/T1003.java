package basicLevel;
//
//1003 我要通过！ （20 分）
//        “答案正确”是自动判题系统给出的最令人欢喜的回复。本题属于 PAT 的“答案正确”大派送 —— 只要读入的字符串满足下列条件，系统就输出“答案正确”，否则输出“答案错误”。
//
//        得到“答案正确”的条件是：
//
//        字符串中必须仅有 P、 A、 T这三种字符，不可以包含其它字符；
//        任意形如 xPATx 的字符串都可以获得“答案正确”，其中 x 或者是空字符串，或者是仅由字母 A 组成的字符串；
//        如果 aPbTc 是正确的，那么 aPbATca 也是正确的，其中 a、 b、 c 均或者是空字符串，或者是仅由字母 A 组成的字符串。
//        现在就请你为 PAT 写一个自动裁判程序，判定哪些字符串是可以获得“答案正确”的。
//
//        输入格式：
//        每个测试输入包含 1 个测试用例。第 1 行给出一个正整数 n (<10)，是需要检测的字符串个数。接下来每个字符串占一行，字符串长度不超过 100，且不包含空格。
//
//        输出格式：
//        每个字符串的检测结果占一行，如果该字符串可以获得“答案正确”，则输出 YES，否则输出 NO。
//
//        输入样例：
//        8
//        PAT
//        PAAT
//        AAPATAA
//        AAPAATAAAA
//        xPATx
//        PT
//        Whatever
//        APAAATAA
//        输出样例：
//        YES
//        YES
//        YES
//        YES
//        NO
//        NO
//        NO
//        NO

import java.util.Scanner;

public class T1003 {
    public static void main(String[] args) {
        Scanner in = new Scanner(System.in);
        int n = in.nextInt();
        String k = in.nextLine();
        while (n > 0){
            //pat字母的 前中后的字符个数
            int q = 0,z = 0,h = 0;
            int p = 0,a = 0,t = 0;
            int f = 1; // 1 前 2 中 3 后
            boolean flag = false; //其他字符 是否存在 存在

            String str = in.nextLine();
            char[] chars = str.toCharArray();
            for (int i = 0; i < chars.length; i++){
                if (chars[i] == 'P'){
                    p++;
                    f = 2;
                }else if (chars[i] == 'A'){
                    a++;
                }else if (chars[i] == 'T'){
                    t++;
                    f = 3;
                }else {
                    flag = true;
                }
                switch (f){
                    case 1:
                        q++;
                        break;
                    case 2:
                        if (chars[i] != 'P') {
                            z++;
                        }
                        break;
                    case 3:
                        if (chars[i] != 'T') {
                            h++;
                        }
                        break;
                }
            }
            if (p == 1 && a != 0 && t == 1 && q * z == h && !flag){
                System.out.println("YES");
            }else {
                System.out.println("NO");
            }
            n--;
        }
    }
}
