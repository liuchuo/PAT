import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;

public class Main {
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        String str = br.readLine();
        String[] strs = str.split(" ");
        char[] c = strs[0].toCharArray();
        int n = Integer.parseInt(strs[1]);
        int t = 0, tmp = 0;
        t = (c[0] - '0') / n;
        if (t != 0 && c.length > 1 || c.length == 1) {
            System.out.print(t);
        }
        tmp = (c[0] - '0') % n;
        for (int i = 1; i < c.length; i++) {
            t = (tmp * 10 + c[i] - '0') / n;
            System.out.print(t);
            tmp = (tmp * 10 + c[i] - '0') % n;
        }
        System.out.print(" " + tmp);
    }
}
