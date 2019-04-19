import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        int n = new Scanner(System.in).nextInt();
        int b = n / 100 % 10;
        int s = n / 10 % 10;
        int g = n % 10;
        System.out.print(fun(b, s, g));
    }

    private static String fun(int b, int s, int g) {
        String str = "";
        int i;
        for (i = 0; i < b; i++) {
            str += 'B';
        }
        for (i = 0; i < s; i++) {
            str += 'S';
        }
        for (i = 1; i <= g; i++) {
            str += i + "";
        }
        return str;
    }
}
