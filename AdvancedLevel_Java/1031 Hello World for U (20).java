import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;

public class Main {
    public static void main(String[] args) throws IOException {
        BufferedReader reader = new BufferedReader(new InputStreamReader(System.in));
        final char[] chars = reader.readLine().toCharArray();
        final int length = chars.length + 2;
        final int rows = length / 3;
        final int columns = length / 3 + length % 3;
        final char[][] table = new char[rows][columns];
        int index = 0;
        //left
        for (int i = 0; i < rows; i++, index++) {
            table[i][0] = chars[index];
        }
        //bottom
        for (int i = 1; i < columns - 1; i++, index++) {
            table[rows - 1][i] = chars[index];
        }
        //right
        for (int i = rows - 1; i >= 0; i--, index++) {
            table[i][columns - 1] = chars[index];
        }
        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < columns; j++) {
                char c = table[i][j] == 0 ? ' ' : table[i][j];
                System.out.printf("%c", c);
                if (j == columns - 1) {
                    System.out.println();
                }
            }
        }
    }
}