import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        Scanner in = new Scanner(System.in);
        int c1 = in.nextInt();
        int c2 = in.nextInt();
        //考虑四舍五入
        int sum = (c2 - c1 + 50) / 100;
        int h = sum / 3600;
        sum = sum % 3600;
        int m = sum / 60;
        int s = sum % 60;
        System.out.printf("%02d:%02d:%02d", h, m, s);
    }
}
