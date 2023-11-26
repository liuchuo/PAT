import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStream;
import java.io.InputStreamReader;
import java.math.BigInteger;
import java.util.StringTokenizer;

public class Main {

    static BufferedReader bufferedReader = new BufferedReader(new InputStreamReader(System.in));
    static boolean[] booleans = new boolean[200];
    public static void main(String[] args) throws IOException {
//        Reader.init(System.in);

        String s1 = bufferedReader.readLine();
        String s2 = bufferedReader.readLine();

        for (int i = 0; i < s1.length(); i++) {

            if (!booleans[s1.charAt(i)])

                booleans[s1.charAt(i)] = true;

        }

        for (int i = 0; i < s2.length(); i++) {
            if (booleans[s2.charAt(i)]){
                booleans[s2.charAt(i)] = false;
            }
        }

        StringBuilder stringBuilder = new StringBuilder();
        for (int i = 0; i < s1.length(); i++) {
            char c = s1.charAt(i);
            if (booleans[c])
                stringBuilder.append(c);
        }
        System.out.println(stringBuilder);
    }
}
