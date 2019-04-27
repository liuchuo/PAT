import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;

public class Main {
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        int n = Integer.parseInt(br.readLine());
        int j = 0,y = 0;
        for (int i = 0; i < n; i++) {
            String[] str = br.readLine().split(" ");
            boolean jj = false, yy = false;
            if (Integer.parseInt(str[0]) + Integer.parseInt(str[2]) == Integer.parseInt(str[1])) {
               jj = true;
            }
            if (Integer.parseInt(str[0]) + Integer.parseInt(str[2]) == Integer.parseInt(str[3])) {
                yy = true;
            }
            if (jj && yy || (!jj && !yy)) {
                continue;
            }else if (jj) {
                j++;
            }else {
                y++;
            }
        }
        System.out.println(y + " " + j);
    }
}