import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStream;
import java.io.InputStreamReader;
import java.math.BigInteger;
import java.util.*;

public class Main {

    public static void main(String[] args) throws IOException {

        Reader.init(System.in);

        int V = Reader.nextInt();
        int E = Reader.nextInt();

        Edge[] edge = new Edge[E];

        for (int i = 0; i < E; i++) {
            edge[i] = new Edge();
            edge[i].start = Reader.nextInt();
            edge[i].end = Reader.nextInt();
        }

        int loop = Reader.nextInt();

        for (int i = 0; i < loop; i++) {
            boolean flag = true;
            int nums = Reader.nextInt();
            boolean[] vertex = new boolean[V];
            for (int j = 0; j < nums; j++) {
                int indice = Reader.nextInt();
                vertex[indice] = true;
            }
            for (Edge value : edge) {
                if (vertex[value.start]) {
                    continue;
                }
                if (vertex[value.end]) {
                    continue;
                }
                flag = false;
                break;
            }

            if (flag)
                System.out.println("Yes");
            else 
                System.out.println("No");
            
        }
    }
}

class Edge{
    int start;
    int end;
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