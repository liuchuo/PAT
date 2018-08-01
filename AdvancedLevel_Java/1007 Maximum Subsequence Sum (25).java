import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;

public class Main {
    public static void main(String[] args) throws IOException {
        BufferedReader reader = new BufferedReader(new InputStreamReader(System.in));
        reader.readLine();
        String[] split = reader.readLine().split(" ");
        int final_max_sum = Integer.MIN_VALUE;
        int sub_sum = 0, start_index = 0, final_start = 0, final_end = split.length - 1;
        for (int i = 0; i < split.length; i++) {
            int value = Integer.valueOf(split[i]);
            sub_sum = sub_sum + value;
            if (sub_sum >= 0) {
                if (sub_sum > final_max_sum) {
                    final_max_sum = sub_sum;

                    if (start_index != final_start) {
                        final_start = start_index;
                    }
                    final_end = i;
                }
            } else {
                sub_sum = 0;
                start_index = i + 1;
            }
        }
        if (final_max_sum < 0) {
            final_max_sum = 0;
        }
        System.out.print(final_max_sum + " ");
        System.out.print(Integer.valueOf(split[final_start]) + " ");
        System.out.println(Integer.valueOf(split[final_end]));
    }
}