import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        String str = new Scanner(System.in).nextLine();
        char[] chars = str.toCharArray();
        int sum = 0;
        for (int i = 0; i < chars.length; i++) {
            sum += chars[i] - '0';
        }
        char[] c = (sum + "").toCharArray();
        boolean flag = false;
        for (int i = 0; i < c.length; ++i) {
            if (flag) {
                System.out.print(" ");
            }
            out(c[i]);
            flag = true;
        }

    }

    private static void out(char c) {
        switch (c) {
            case '1':
                System.out.print("yi");
                break;
            case '2':
                System.out.print("er");
                break;
            case '3':
                System.out.print("san");
                break;
            case '4':
                System.out.print("si");
                break;
            case '5':
                System.out.print("wu");
                break;
            case '6':
                System.out.print("liu");
                break;
            case '7':
                System.out.print("qi");
                break;
            case '8':
                System.out.print("ba");
                break;
            case '9':
                System.out.print("jiu");
                break;
            case '0':
                System.out.print("ling");
                break;

        }
    }
}
