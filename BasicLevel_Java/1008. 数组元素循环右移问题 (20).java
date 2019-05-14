import java.util.Scanner;

public class Main {
    static int[] a = new int[105];

    public static void main(String[] args) {
        Scanner in = new Scanner(System.in);
        int N = in.nextInt();
        int M = in.nextInt();
        int i, j;
        for (i = 0; i < N; i++) {
            a[i] = in.nextInt();
        }
        for (i = 0; i < M; i++) {
            int tmp = a[N - 1];
            for (j = N - 1; j > 0; j--) {
                a[j] = a[j - 1];
            }
            a[0] = tmp;
        }
        for (i = 0; i < N - 1; ++i) {
            System.out.print(a[i] + " ");
        }
        System.out.print(a[N - 1]);
    }
}
