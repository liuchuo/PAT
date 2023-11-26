import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStream;
import java.io.InputStreamReader;
import java.math.BigInteger;
import java.text.DecimalFormat;
import java.util.*;

public class Main {

    static DecimalFormat format = new DecimalFormat("0000");

    public static void main(String[] args) throws IOException {

        Reader.init(System.in);
        int x = Reader.nextInt();
        String s = format.format(x);
        char[] chars = s.toCharArray();
        Arrays.sort(chars);

        StringBuilder builder = new StringBuilder();
        builder.append(chars);

        f(builder);
    }

    static void f(StringBuilder builder){

        int x1 = Integer.parseInt(builder.toString());
        int x2 = Integer.parseInt(builder.reverse().toString());

        int x3 = x2 - x1;
        System.out.println(format.format(x2) + " - " + format.format(x1) + " = " + format.format(x3));
        if (x3 == 0 || x3 == 6174)
            System.exit(0);
        builder = new StringBuilder();

        char[] chars = format.format(x3).toCharArray();
        Arrays.sort(chars);

        builder.append(chars);
        f(builder);
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