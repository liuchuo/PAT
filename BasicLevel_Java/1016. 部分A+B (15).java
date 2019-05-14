import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;

public class Main {
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        String str = br.readLine();
        String[] strs = str.split(" ");
        char[] a1 = strs[0].toCharArray();
        int d1 = Integer.parseInt(strs[1]);
        char[] a2 = strs[2].toCharArray();
        int d2 = Integer.parseInt(strs[3]);
        int i, sum1 = 0, sum2 = 0;
        for (i = 0; i < a1.length; i++) {
            if ((a1[i] - '0') == d1) {
                sum1 = sum1 * 10 + d1;
            }
        }
        for (i = 0; i < a2.length; i++) {
            if ((a2[i] - '0') == d2) {
                sum2 = sum2 * 10 + d2;
            }
        }
        System.out.println(sum1 + sum2);
    }
}
