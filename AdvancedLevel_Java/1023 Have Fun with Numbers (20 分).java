import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.math.BigDecimal;
import java.math.BigInteger;
import java.util.Arrays;
import java.util.Map;
import java.util.Scanner;
import java.util.TreeMap;

public class Main {
    private static Scanner scanner = new Scanner(System.in);
    private static BufferedReader bufferedReader = new BufferedReader(new InputStreamReader(System.in));

    public static void main(String[] args) throws IOException {
        BigInteger bigInteger = scanner.nextBigInteger();
        String string = bigInteger.toString();

        BigInteger bigInteger1 = bigInteger.add(bigInteger);
        String string1 = bigInteger1.toString();

        char[] chars = string.toCharArray();
        Arrays.sort(chars);
        String s = String.valueOf(chars);

        char[] chars1 = string1.toCharArray();
        Arrays.sort(chars1);
        String s1 = String.valueOf(chars1);

        if (s.equals(s1)) System.out.println("Yes");
        else System.out.println("No");
        System.out.println(string1);
    }
}