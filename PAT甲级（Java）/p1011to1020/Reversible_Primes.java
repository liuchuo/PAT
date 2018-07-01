package p1011to1020;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.math.BigInteger;

/**
 * 1015 Reversible Primes (20)（20 分）
 */
public class Reversible_Primes {
    /**
     * @param number number with radix 10
     * @return true or false
     */
    private boolean isPrime(String number) {
        int value = Integer.valueOf(number);
        if (value <= 1) return false;
        if(value==2) return true;
        if (value %2==0) return false;
        int maxLimit = (int) Math.sqrt(value);
        for (int i = 3; i <= maxLimit; i += 2) {
            if (value % i == 0) {
                return false;
            }
        }
        return true;
    }

    /**
     * 反转素数
     *
     * @param number >0
     * @param radix
     * @return
     */
    private String reversePrime(String number, int radix) {
        int value = Integer.valueOf(number);
        StringBuilder builder = new StringBuilder();
        for (; value != 0; value = value / radix) {
            int bit = value % radix;
            builder.append(bit);
        }
        return new BigInteger(builder.toString(), radix).toString();
    }

    public static void main(String[] args) throws IOException {
        BufferedReader reader = new BufferedReader(new InputStreamReader(System.in));
        Reversible_Primes rp = new Reversible_Primes();
        String[] split = reader.readLine().split(" ");
        for (; split.length > 1; split = reader.readLine().split(" ")) {
            String number = split[0];
            int radix = Integer.valueOf(split[1]);
            if (rp.isPrime(number)&&
                    rp.isPrime(rp.reversePrime(number, radix))){
                System.out.println("Yes");
            }else {
                System.out.println("No");
            }
        }
    }
}
