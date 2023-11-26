import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStream;
import java.io.InputStreamReader;
import java.math.BigInteger;
import java.util.HashSet;
import java.util.Set;
import java.util.StringTokenizer;

public class Main {

    public static void main(String[] args) throws IOException {

        Reader.init(System.in);

        int vertices = Reader.nextInt();
        int edges = Reader.nextInt();

        int[] Vertices = new int[vertices];
        Edge[] edge = new Edge[edges];

        for (int i = 0; i < edges; i++) {
            edge[i] = new Edge();
            edge[i].start = Reader.nextInt();
            edge[i].end = Reader.nextInt();
        }

        int loop = Reader.nextInt();

        for (int i = 0; i < loop; i++) {
            for (int j = 0; j < vertices; j++) {
                Vertices[j] = Reader.nextInt();
            }

            boolean flag = true;
            for (int j = 0; j < edges; j++) {
                if (Vertices[edge[j].start] == Vertices[edge[j].end]){
                    System.out.println("No");
                    flag = false;
                    break;
                }
            }
            
            if (flag){
	//目测Case 2 存在孤立顶点。所以Set的使用要在着色的时候而非遍历边的时候。
                Set<Integer> set = new HashSet<>();
                for (int j = 0; j < vertices; j++) 
                    set.add(Vertices[j]);
            
                System.out.println(set.size() + "-coloring");
            }
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