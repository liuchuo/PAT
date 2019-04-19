import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        Scanner in = new Scanner(System.in);
        int flag = 0;
        while (in.hasNext()) {
            int x = in.nextInt();
            int n = in.nextInt();
            if (n != 0) {
                if (flag == 0) {
                    System.out.print(x * n);
                } else {
                    System.out.print(" " + x * n);
                }
                System.out.print(" " + (n - 1));
                flag = 1;
            }
        }
        if (flag == 0) {
            System.out.print("0 0");
        }
    }
}
