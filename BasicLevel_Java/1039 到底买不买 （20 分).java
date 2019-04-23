import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;

public class Main {
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        char[] c1 = br.readLine().toCharArray();
        char[] c2 = br.readLine().toCharArray();
        int[] flag = new int[256];
        for (int i = 0; i < c1.length; i++) {
            flag[c1[i]]++;
        }
        int count = c2.length;
        for (int i = 0; i < c2.length; i++) {
            if (flag[c2[i]] != 0){
                flag[c2[i]]--;
                count--;
            }
        }
        if (count == 0) {
            System.out.print("Yes " + (c1.length - c2.length));
        }else {
            System.out.print("No " + count);
        }
    }
}
