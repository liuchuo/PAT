package basicLevel;

//1014 福尔摩斯的约会 （20 分）
//        大侦探福尔摩斯接到一张奇怪的字条：我们约会吧！ 3485djDkxh4hhGE 2984akDfkkkkggEdsb s&hgsfdk d&Hyscvnm。大侦探很快就明白了，字条上奇怪的乱码实际上就是约会的时间星期四 14:04，因为前面两字符串中第 1 对相同的大写英文字母（大小写有区分）是第 4 个字母 D，代表星期四；第 2 对相同的字符是 E ，那是第 5 个英文字母，代表一天里的第 14 个钟头（于是一天的 0 点到 23 点由数字 0 到 9、以及大写字母 A 到 N 表示）；后面两字符串第 1 对相同的英文字母 s 出现在第 4 个位置（从 0 开始计数）上，代表第 4 分钟。现给定两对字符串，请帮助福尔摩斯解码得到约会的时间。
//
//        输入格式：
//        输入在 4 行中分别给出 4 个非空、不包含空格、且长度不超过 60 的字符串。
//
//        输出格式：
//        在一行中输出约会的时间，格式为 DAY HH:MM，其中 DAY 是某星期的 3 字符缩写，即 MON 表示星期一，TUE 表示星期二，WED 表示星期三，THU 表示星期四，FRI 表示星期五，SAT 表示星期六，SUN 表示星期日。题目输入保证每个测试存在唯一解。
//
//        输入样例：
//        3485djDkxh4hhGE
//        2984akDfkkkkggEdsb
//        s&hgsfdk
//        d&Hyscvnm
//        输出样例：
//        THU 14:04


import java.util.Scanner;

public class T1014 {
    final static String[] week = new String[]{"MON","TUE","WED","THU","FRI","SAT","SUN"};
    public static void main(String[] args) {
        Scanner in = new Scanner(System.in);
        String str1 = in.nextLine();
        String str2 = in.nextLine();
        String str3 = in.nextLine();
        String str4 = in.nextLine();
        char a1=' ', a2= ' ';
        int a3 = -1;
        boolean a11 = true;
        int i;
        char[] c1 = str1.toCharArray();
        char[] c2 = str2.toCharArray();
        char[] c3 = str3.toCharArray();
        char[] c4 = str4.toCharArray();
        for (i = 0; i < (c1.length > c2.length ? c2.length : c1.length); i++) {
                if (c1[i] == c2[i] && a11 && c1[i] >= 'A' && c1[i] <= 'G') {
                    a1 = c1[i];
                    a11 = false;
                    i++;
                }
                if (!a11 && c1[i] == c2[i] && (c1[i] >='A' && c1[i] <= 'N' || c1[i] >= '0' && c1[i] <= '9')){
                    a2 = c1[i];
                    break;
                }
        }
        for (i = 0; i < (c3.length > c4.length ? c4.length : c3.length); i++) {
            if (c3[i] == c4[i] && c3[i] >= 'A' && c3[i] <= 'z'){
                a3 = i;
                break;
            }
        }
        System.out.print(week[a1 - 65] + " " + (a2 > '9'?(a2 - 55):("0" + a2)) + ":" + (a3 > 9 ?a3:("0" +a3)));
    }
}