import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.ArrayList;

public class Main {
    static final int n = 54;

    public static void main(String[] args) throws IOException {
        char[] ch = {'S', 'H', 'C', 'D'};
        ArrayList<String> list = new ArrayList<String>();
        for (int i = 0; i < 4; i++) {
            for (int j = 1; j <= 13; j++) {
                StringBuilder bd = new StringBuilder();
                bd.append(ch[i]);
                bd.append(j);
                list.add(bd.toString());
            }
            if (i == 3) {
                list.add("J1");
                list.add("J2");
            }
        }
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        int k = Integer.parseInt(br.readLine());
        String[] s = br.readLine().split(" ");
        int[] num = new int[60];
        for (int i = 0; i < s.length; i++) {
            num[i] = Integer.parseInt(s[i]);
        }
        int[] start = new int[55];
        int[] end = new int[55];
        for (int i = 0; i < n; i++) {
            start[i] = i;
        }

        for (int i = 0; i < k; i++) {
            for (int j = 0; j < n; j++) {
                end[num[j] - 1] = start[j];
            }
            for (int j = 0; j < n; j++) {
                start[j] = end[j];
            }
        }

        for (int i = 0; i < n; i++) {
            if (i != 0) {
                System.out.print(" ");
            }
            System.out.print(list.get(start[i]));

        }
        System.out.println();
    }
}
