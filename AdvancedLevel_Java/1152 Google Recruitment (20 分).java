import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.math.BigDecimal;

public class Main {

    private static BufferedReader bufferedReader = new BufferedReader(new InputStreamReader(System.in));

    public static void main(String[] args) throws IOException {
        String s = bufferedReader.readLine();
        String[] ss = s.split(" ");
        int num = Integer.parseInt(ss[1]);
        s = bufferedReader.readLine();

        for (int i = 0; i < s.length() - num + 1; i++) {
            String x = s.substring(i,i + num);
            int m = Integer.parseInt(x);

            if (isPrime(m)){
                System.out.println(x);
                System.exit(0);
            }
        }
        System.out.println(404);
    }
    private static boolean isPrime(int x){
        int xx = (int) Math.sqrt(x) + 1;
        for (int i = 2; i < xx; i++) {
            if (x % i == 0)
                return false;
        }
        return true;
    }
}
