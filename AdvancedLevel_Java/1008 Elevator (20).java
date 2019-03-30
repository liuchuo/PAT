import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;

public class Main {
    public static void main(String[] args) throws IOException {
        BufferedReader reader = new BufferedReader(new InputStreamReader(System.in));
        String[] split = reader.readLine().split(" ");
        int sum = 0;
        int lastFloor = 0;
        for (int i = 1; i < split.length; i++) {
            int value = Integer.valueOf(split[i]);
            int diff = value - lastFloor;
            if (diff > 0) {
                sum += diff * 6 + 5;
            } else if (diff < 0) {
                sum += -diff * 4 + 5;
            } else {
                sum += 5;
            }
            lastFloor = value;
        }
        System.out.println(sum);
    }
}