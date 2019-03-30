import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;

public class Main {
    static class Bet {
        static String[] names = new String[]{"W", "T", "L"};
        String name;
        double value;

        Bet(int index, double value) {
            this.name = names[index];
            this.value = value;
        }
    }

    static BufferedReader reader = new BufferedReader(new InputStreamReader(System.in));

    public static void main(String[] args) throws IOException {
        StringBuilder builder = new StringBuilder();
        double sum = 1;
        for (int i = 0; i < 3; i++) {
            Bet bet = getBet();
            builder.append(bet.name).append(" ");
            sum = sum * bet.value;
        }
        double profit = 2 * (sum * 0.65 - 1);
        //四舍五入就可以, 可以无视example
        builder.append(String.format("%.2f", profit));
        System.out.println(builder);
    }

    private static Bet getBet() throws IOException {
        String[] split = reader.readLine().split(" ");
        int max_index = 0;
        double max_bet = -1.0;
        for (int i = 0; i < split.length; i++) {
            double v = Double.valueOf(split[i]);
            if (v > max_bet) {
                max_index = i;
                max_bet = v;
            }
        }
        return new Bet(max_index, max_bet);
    }
}