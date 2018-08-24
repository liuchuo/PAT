import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.ArrayList;

public class Main {
    private static ArrayList<Integer> toPalindromic(int number, int base) {
        ArrayList<Integer> list = new ArrayList<>(31);
        if (number == 0) {
            list.add(0);
            return list;
        }
        while (number != 0) {
            int bit = number % base;
            list.add(bit);
            number = number / base;
        }
        return list;
    }

    static boolean isPalindromic(ArrayList<Integer> list) {
        int length = list.size();
        for (int i = 0, j = length - 1; i < length / 2; i++, j--) {
            if (!list.get(i).equals(list.get(j))) {
                return false;
            }
        }
        return true;
    }

    public static void main(String[] args) throws IOException {
        BufferedReader reader = new BufferedReader(new InputStreamReader(System.in));
        String[] split = reader.readLine().split(" ");
        int number = Integer.valueOf(split[0]);
        int base = Integer.valueOf(split[1]);
        ArrayList<Integer> builder = toPalindromic(number, base);
        System.out.println(isPalindromic(builder) ? "Yes" : "No");
        for (int i = builder.size() - 1; i >= 0; i--) {
            System.out.printf("%d%s", builder.get(i), i == 0 ? "\n" : " ");
        }
    }
}