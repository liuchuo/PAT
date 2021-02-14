import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStream;
import java.io.InputStreamReader;
import java.math.BigInteger;
import java.util.StringTokenizer;

public class Main {

    /*
    * Case 4: 耗时200ms.内存20242KB；服务器好的时候能过，不好的时候就绿了
    * Case 5: 将下面的两个数组开到100000即可过掉。
    */

    static int[] ints = new int[100001];
    static int[] ints1 = new int[100001];


    public static void main(String[] args) throws IOException {
        Reader.init(System.in);

        int nums = Reader.nextInt();

        for (int i = 0; i < nums; i++) {
            int val = Reader.nextInt();
            ints[i] = val;
            ints1[val]++;
        }

        for (int i = 0; i < nums; i++) {
            if(ints1[ints[i]] == 1) {
                System.out.println(ints[i]);
                return;
            }
        }
        System.out.println("None");
    }
}
class Reader {
    static BufferedReader reader;
    static StringTokenizer tokenizer;

    static void init(InputStream input) {
        reader = new BufferedReader(
                new InputStreamReader(input) );
        tokenizer = new StringTokenizer("");
    }

    static String next() throws IOException {
        while ( ! tokenizer.hasMoreTokens() ) {
            //TODO add check for eof if necessary
            tokenizer = new StringTokenizer(
                    reader.readLine() );
        }
        return tokenizer.nextToken();
    }

    static int nextInt() throws IOException {
        return Integer.parseInt( next() );
    }

    static double nextDouble() throws IOException {
        return Double.parseDouble( next() );
    }

    static BigInteger nextBigInteger() throws IOException {
        return new BigInteger( next() );
    }
}