import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;

public class Main {
    final static char[] arr = {'0', '1', '2', '3', '4', '5', '6', '7', '8', '9', 'J', 'Q', 'K'};
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        String[] str = br.readLine().split(" ");
        int len1 = str[0].length();
        int len2 = str[1].length();
        int max = Math.max(len1, len2);
        int min = Math.min(len1, len2);

        String res = "";
        if (len1 < len2) {
            for (int i = 0 ; i < len2 - len1; i++) {
                str[0] = '0' + str[0];
            }
        }else {
            for (int i = 0 ; i < len1 - len2; i++) {
                str[1] = '0' + str[1];
            }
        }
        char[] c1 = str[0].toCharArray();
        char[] c2 = str[1].toCharArray();
        for (int i = max - 1; i >= 0; i--) {
            int index = max - i;
            if (index % 2 == 1) {
                res = arr[(c1[i] - '0' + c2[i] - '0') % 13] + res;
            }
            if (index % 2 == 0) {
                res = arr[(((c2[i] - '0') - (c1[i] - '0')) + 10) % 10] + res;
            }
        }
        System.out.println(res);
    }
}
