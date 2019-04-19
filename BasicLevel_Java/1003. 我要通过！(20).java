import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        Scanner in = new Scanner(System.in);
        int n = in.nextInt();
        String k = in.nextLine();
        while (n > 0) {
            //pat字母的 前中后的字符个数
            int q = 0, z = 0, h = 0;
            int p = 0, a = 0, t = 0;
            int f = 1; // 1 前 2 中 3 后
            boolean flag = false; //其他字符 是否存在 存在

            String str = in.nextLine();
            char[] chars = str.toCharArray();
            for (int i = 0; i < chars.length; i++) {
                if (chars[i] == 'P') {
                    p++;
                    f = 2;
                } else if (chars[i] == 'A') {
                    a++;
                } else if (chars[i] == 'T') {
                    t++;
                    f = 3;
                } else {
                    flag = true;
                }
                switch (f) {
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
            if (p == 1 && a != 0 && t == 1 && q * z == h && !flag) {
                System.out.println("YES");
            } else {
                System.out.println("NO");
            }
            n--;
        }
    }
}
