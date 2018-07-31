import java.io.IOException;
import java.io.InputStream;

public class Main {
    static String[] words_table = new String[]{"zero",
            "one", "two", "three", "four", "five",
            "six", "seven", "eight", "nine"};

    public static void main(String[] args) throws IOException {
        InputStream reader = System.in;
        int input, sum = 0;
        while ((input = reader.read()) != '\n') {
            sum += input - 48;
        }
        char[] chars = (sum + "").toCharArray();
        for (int i = 0; i < chars.length; i++) {
            System.out.print(words_table[chars[i] - 48]);
            if (i == chars.length - 1) {
                System.out.println();
            } else {
                System.out.print(" ");
            }
        }
    }
}