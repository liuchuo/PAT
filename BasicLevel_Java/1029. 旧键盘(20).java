import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;

public class Main {
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        char[] c1 = br.readLine().toUpperCase().toCharArray();
        char[] c2 = br.readLine().toUpperCase().toCharArray();
        boolean[] flag = new boolean[85];
        for (int i = 0; i < c2.length; i++) {
            flag[c2[i] - '0'] = true;
        }
        for (int i = 0; i < c1.length; i++) {
            if (!flag[c1[i] - '0']) {
                System.out.print(c1[i]);
                flag[c1[i] - '0'] = true;
            }
        }
    }
}
