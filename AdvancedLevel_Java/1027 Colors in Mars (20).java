import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;

public class Main {
    private static char[] signTables = "0123456789ABC".toCharArray();

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