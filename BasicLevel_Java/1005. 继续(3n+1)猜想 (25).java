import java.util.Arrays;
import java.util.Scanner;

public class Main {
    static int[] a = new int[105];

    public static void main(String[] args) {
        Arrays.fill(a, -1);
        Scanner in = new Scanner(System.in);
        int k = in.nextInt();
        int i;
        for (i = 0; i < k; i++) {
            int num = in.nextInt();
            a[num] = 0;
        }
        int n;
        for (i = 0; i < 105; i++) {
            if (a[i] != 0) {
                continue;
            }
            n = i;
            while (n != 1) {
                if (n % 2 == 0) {
                    n = n / 2;
                    if (n < 100) {
                        a[n] = 1;
                    }
                } else {
                    n = 3 * n + 1;
                    n = n / 2;
                    if (n < 100) {
                        a[n] = 1;
                    }
                }
            }
        }
        for (i = 104; i > 0; i--) {
            if (a[i] == 0) {
                System.out.print(i);
                break;
            }
        }
        for (i = i - 1; i > 0; i--) {
            if (a[i] == 0) {
                System.out.print(" " + i);
            }
        }
    }
}