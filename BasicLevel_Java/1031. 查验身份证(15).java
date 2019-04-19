import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.Arrays;

public class Main {
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));

        char[] m = {'1', '0', 'X', '9', '8', '7', '6', '5', '4', '3', '2'};
        int[] w = {7, 9, 10, 5, 8, 4, 2, 1, 6, 3, 7, 9, 10, 5, 8, 4, 2};
        int n = Integer.parseInt(br.readLine());
        int i, j;
        boolean pass = true;
        for (i = 0; i < n; i++) {
            String str = br.readLine();
            char[] c = str.toCharArray();
            int total = 0;
            boolean isNum = true;
            for (j = 0; j < 17 && isNum; j++) {
                if (c[j] >= '0' && c[j] <= '9') {
                    total += (c[j] - '0') * w[j];
                } else {
                    isNum = false;
                }
            }
            total = total % 11;

            if (c[17] != m[total] || !isNum) {
                pass = false;
                System.out.println(str);
            }

        }
        if (pass) {
            System.out.print("All passed");
        }
    }
}
