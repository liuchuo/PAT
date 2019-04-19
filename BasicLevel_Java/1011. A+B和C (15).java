import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        Scanner in = new Scanner(System.in);
        int T = in.nextInt();
        int i = 1;
        while (i <= T) {
            double a = in.nextDouble();
            double b = in.nextDouble();
            double c = in.nextDouble();
            System.out.println("Case #" + i + ": " + ((a + b) - c < 0.000000000000001 ? "false" : "true"));
            i++;
        }
    }
}
