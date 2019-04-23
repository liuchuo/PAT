import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;

public class Main {
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        char[] c = br.readLine().toCharArray();
        long t = 0,at = 0, pat = 0;
        for (int i = c.length - 1; i>= 0; i--) {
            if (c[i] == 'T')
                t++;
            else if (c[i] == 'A')
                at = (t + at) % 1000000007 ;
            else
                pat = (pat + at) % 1000000007;
        }
        System.out.print(pat % 1000000007 );
    }
}
