import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;

public class Main {
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        int n = Integer.parseInt(br.readLine());
        int[] res = new int[1001];
        int max = res[0];
        int index = 0;
        for (int i = 0; i < n; i++) {
            String[] str0 = br.readLine().split(" ");
            String[] str1 = str0[0].split("-");
            res[Integer.parseInt(str1[0])]  += Integer.parseInt(str0[1]);
            if (max < res[Integer.parseInt(str1[0])]) {
                max = res[Integer.parseInt(str1[0])];
                index = Integer.parseInt(str1[0]);
            }
        }
        System.out.println(index + " " + max);
    }
}
