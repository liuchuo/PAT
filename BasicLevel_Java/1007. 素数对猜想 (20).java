import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        int n = new Scanner(System.in).nextInt();
        int i, j, cnt = 0;
        int pre = 2;
        for (i = 3; i <= n; i++) {
            for (j = 2; j < Math.sqrt(i); j++) {
                if (i % j == 0)
                    break;
            }
            if (j > Math.sqrt(i)) {
                if (i - pre == 2) {
                    cnt++;
                }
                pre = i;
            }
        }
        System.out.print(cnt);
    }
}
