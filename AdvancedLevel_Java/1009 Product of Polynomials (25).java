import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;

public class Main {
    static final int MAXN = 1005;
    static final int MAXN_Double = 2005;
    static double[] A = new double[MAXN];
    static double[] B = new double[MAXN];
    static double[] C = new double[MAXN_Double];

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));

        String[] aLine = br.readLine().split(" ");
        String[] bLine = br.readLine().split(" ");

        int M = Integer.parseInt(aLine[0]);
        int N = Integer.parseInt(bLine[0]);

        for (int i = 0, j = 1; i < M; i++) {
            int p = Integer.parseInt(aLine[j++]);
            double q = Double.parseDouble(aLine[j++]);
            A[p] += q;
        }
        for (int i = 0, j = 1; i < N; i++) {
            int p = Integer.parseInt(bLine[j++]);
            double q = Double.parseDouble(bLine[j++]);
            B[p] += q;
        }
        for (int i = 0; i < MAXN; i++) {
            if (A[i] != 0) {
                for (int j = 0; j < MAXN; j++) {
                    if (B[j] != 0) {
                        C[i + j] += A[i] * B[j];
                    }
                }
            }
        }
        int count = 0;
        for (int i = 0; i < MAXN_Double; i++) {
            if (C[i] != 0) {
                count++;
            }
        }
        System.out.print(count);
        for (int i = MAXN_Double - 1; i >= 0; i--) {
            if (C[i] != 0) {
                System.out.print(" " + i + " " + String.format("%.1f", C[i]));
            }
        }
    }
}
