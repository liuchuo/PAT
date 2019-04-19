import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.Arrays;

public class Main {
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        String str = br.readLine();
        int num = Integer.parseInt(str);
        while (true) {
            int m = inc(num);
            int n = desc(num);
            num = m - n;
            System.out.printf("%04d - %04d = %04d\n", m, n, num);
            if (num == 6174 || num == 0) {
                break;
            }
        }
    }

    public static int desc(int number) {
        char[] array = String.format("%04d", number).toCharArray();
        Arrays.sort(array);
        int temp = 0;
        for (int i = 0; i < 4; i++) {
            temp = temp * 10 + (array[i] - '0');
        }
        return temp;
    }

    public static int inc(int number) {
        char[] array = String.format("%04d", number).toCharArray();
        Arrays.sort(array);
        int temp = 0;
        for (int i = 3; i >= 0; i--) {
            temp = temp * 10 + (array[i] - '0');
        }
        return temp;
    }
}
