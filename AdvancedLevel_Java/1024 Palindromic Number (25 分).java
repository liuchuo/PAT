import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.math.BigDecimal;
import java.math.BigInteger;
import java.util.Scanner;

public class Main {
    private static Scanner scanner = new Scanner(System.in);
    private static BufferedReader bufferedReader = new BufferedReader(new InputStreamReader(System.in));

    public static void main(String[] args) throws IOException {


        BigInteger a = scanner.nextBigInteger();
        int b = scanner.nextInt();
        trans(a,b);


    }

    private static void trans(BigInteger num,int loop){
        for (int i = 0; i < loop; i++) {
            if (isPalindromic(num)){
                System.out.println(num);
                System.out.println(i);
                System.exit(0);
            }
            String s = num + "";
            StringBuilder stringBuilder = new StringBuilder(s);
            num = num.add(new BigInteger(stringBuilder.reverse().toString()));
        }
        System.out.println(num);
        System.out.println(loop);
    }

    private static boolean isPalindromic(BigInteger m){
        String s = m + "";
        StringBuilder stringBuilder = new StringBuilder(s);
        stringBuilder = stringBuilder.reverse();
        return s.equals(stringBuilder.toString());
    }

}