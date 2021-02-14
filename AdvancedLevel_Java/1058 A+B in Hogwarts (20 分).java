import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStream;
import java.io.InputStreamReader;
import java.math.BigInteger;
import java.util.*;

public class Main {
    public static void main(String[] args) throws IOException {

        Reader.init(System.in);

        String[] s1 = Reader.next().split("\\.");
        String[] s2 = Reader.next().split("\\.");
        int[] s3 = new int[3];
        
        int flag = 0;

        int x1 = Integer.parseInt(s1[2]);
        int x2 = Integer.parseInt(s2[2]);

        s3[2] = (x1 + x2) % 29;
        flag = (x1 + x2) / 29;

        x1 = Integer.parseInt(s1[1]);
        x2 = Integer.parseInt(s2[1]);
        s3[1] = ((x1 + x2) % 17 + flag) % 17;
        flag = (x1 + x2) / 17 + ((x1 + x2) % 17 + flag) / 17;

        x1 = Integer.parseInt(s1[0]);
        x2 = Integer.parseInt(s2[0]);
        s3[0] = x1 + x2 + flag;

        System.out.println(s3[0]+ "." + s3[1]+"."+s3[2]);
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