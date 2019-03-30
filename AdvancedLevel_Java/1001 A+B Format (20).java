import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;

public class Main {
    public static void main(String[] args) throws IOException {
        BufferedReader reader = new BufferedReader(new InputStreamReader(System.in));
        String[] split = reader.readLine().split(" ");
        Integer x = Integer.valueOf(split[0]) + Integer.valueOf(split[1]);
        char[] chars = x.toString().toCharArray();
        int modOffset = chars.length % 3;
        for (int i = 0; i < chars.length; i++) {
            if (chars[i] == '-') {
                System.out.print('-');
                continue;
            }
            System.out.print(chars[i] - 48);
            if (i == chars.length - 1) {
                System.out.println();
            } else if ((i + 1) % 3 == modOffset) {
                System.out.print(',');
            }
        }
    }
}