import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;

public class Main {
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        String[] str = br.readLine().split(" ");
        String[] s1 = str[0].split("\\.");
        String[] s2 = str[1].split("\\.");
        int a = Integer.valueOf(s1[0]) * 17 * 29 + Integer.valueOf(s1[1]) * 29 + Integer.valueOf(s1[2]);
        int b = Integer.valueOf(s2[0]) * 17 * 29 + Integer.valueOf(s2[1]) * 29 + Integer.valueOf(s2[2]);
        int tmp = Integer.MAX_VALUE;
        if (a > b) {
            tmp = a - b;
            System.out.print("-");
        } else {
            tmp = b - a;

        }
        System.out.println(tmp / (17 * 29) + "." + tmp % (17 * 29) / 29 + "." + (tmp - (tmp / (17 * 29)) * (17 * 29)
                - (tmp % (17 * 29) / 29) * 29));
    }
}
