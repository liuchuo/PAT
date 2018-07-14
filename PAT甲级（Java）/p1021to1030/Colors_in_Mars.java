package p1021to1030;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;

/**
 * 1027 Colors in Mars (20)（20 分）
    AC
 */
public class Colors_in_Mars {
    private static char[] signTables = "0123456789ABC".toCharArray();
    /**
     * 1027 Colors in Mars (20)（20 分）
     AC
     */
    public static void main(String[] args) throws IOException {
        BufferedReader reader = new BufferedReader(new InputStreamReader(System.in));
        String[] split = reader.readLine().split(" ");
        System.out.print("#");
        for (String aSplit : split) {
            Integer integer = Integer.valueOf(aSplit);
            System.out.printf("%c%c", signTables[integer / 13], signTables[integer % 13]);
        }
        System.out.println();

    }
}
