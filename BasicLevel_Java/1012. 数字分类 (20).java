import java.util.Scanner;

public class Main {
    static int[] num = new int[1005];

    public static void main(String[] args) {
        Scanner in = new Scanner(System.in);
        int N = in.nextInt();
        int i;
        int a1 = 0, a2 = 0, a3 = 0, a5 = -1;
        int a4 = 0;
        int cout4 = 0;
        int flag = 1;
        boolean a22 = false;
        for (i = 0; i < N; i++) {
            num[i] = in.nextInt();
            if (num[i] % 5 == 0 && num[i] % 2 == 0) {
                a1 += num[i];
            }
            if (num[i] % 5 == 1) {
                a2 += (num[i] * flag);
                flag = flag * (-1);
                a22 = true;
            }
            if (num[i] % 5 == 2) {
                a3++;
            }
            if (num[i] % 5 == 3) {
                cout4++;
                a4 += num[i];
            }
            if (num[i] % 5 == 4) {
                if (a5 < num[i]) {
                    a5 = num[i];
                }
            }
        }
        if (a1 != 0) {
            System.out.print(a1 + " ");
        } else {
            System.out.print("N ");
        }
        if (a22) {
            System.out.print(a2 + " ");
        } else {
            System.out.print("N ");
        }
        if (a3 != 0) {
            System.out.print(a3 + " ");
        } else {
            System.out.print("N ");
        }
        if (cout4 != 0) {
            System.out.printf("%.1f", (1.0 * a4 / cout4));
            System.out.print(" ");
        } else {
            System.out.print("N ");
        }
        if (a5 != -1) {
            System.out.print(a5);
        } else {
            System.out.print("N");
        }

    }
}
