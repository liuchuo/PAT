import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;

public class Main {
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));

        String[] input = br.readLine().split("[\\s/]");
        long a1 = Integer.parseInt(input[0]);
        long b1 = Integer.parseInt(input[1]);
        long a2 = Integer.parseInt(input[2]);
        long b2 = Integer.parseInt(input[3]);

        if (b1 != 0 && b2 != 0) {
            add(a1, b1, a2, b2);
            minus(a1, b1, a2, b2);
            mutilply(a1, b1, a2, b2);
            divide(a1, b1, a2, b2);
        }
    }

    public static void tackle(long a, long b) {
        if (a == 0) {
            System.out.print(0);
            return;
        }

        boolean isMinus = a > 0 ? false : true;
        if (isMinus) {
            System.out.print("(-");
            a = -a;
        }

        long gcd = getGcd(a, b);
        a = a / gcd;
        b = b / gcd;
        if (a % b == 0) {
            System.out.print(a / b);
        } else if (Math.abs(a) > b) {
            System.out.print(a / b + " " + (a % b) % b + "/" + b);
        } else if (a == b) {
            System.out.print(1);
        } else {
            System.out.print(a + "/" + b);
        }

        if (isMinus) {
            System.out.print(")");
        }

    }

    public static void divide(long a1, long b1, long a2, long b2) {
        tackle(a1, b1);
        System.out.print(" / ");
        tackle(a2, b2);
        System.out.print(" = ");
        if (a2 == 0) {
            System.out.print("Inf");
        } else if (a2 < 0) {
            tackle(-1 * a1 * b2, -1 * a2 * b1);
        } else {
            tackle(a1 * b2, a2 * b1);
        }
    }

    public static void mutilply(long a1, long b1, long a2, long b2) {
        tackle(a1, b1);
        System.out.print(" * ");
        tackle(a2, b2);
        System.out.print(" = ");
        tackle(a1 * a2, b1 * b2);
        System.out.println();
    }

    public static void minus(long a1, long b1, long a2, long b2) {
        tackle(a1, b1);
        System.out.print(" - ");
        tackle(a2, b2);
        System.out.print(" = ");
        tackle(a1 * b2 - a2 * b1, b1 * b2);
        System.out.println();
    }

    public static void add(long a1, long b1, long a2, long b2) {
        tackle(a1, b1);
        System.out.print(" + ");
        tackle(a2, b2);
        System.out.print(" = ");
        tackle(a1 * b2 + a2 * b1, b1 * b2);
        System.out.println();
    }

    public static long getGcd(long a, long b) {
        while (a % b != 0) {
            long temp = a % b;
            a = b;
            b = temp;
        }
        return b;
    }
}

