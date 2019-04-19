import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;

public class Main {
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        char[] chars = br.readLine().toCharArray();
        int[] count = new int[11];
        for (int i = 0; i < chars.length; i++) {
            count[chars[i] - '0']++;
        }
        for (int i = 0; i < 11; i++) {
            if (count[i] != 0) {
                System.out.println(i + ":" + count[i]);
            }
        }
    }
}
