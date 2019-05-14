import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.ArrayList;
import java.util.Collections;

public class Main {
    static class Cake implements Comparable<Cake> {
        double amount;
        double price;
        double value;

        public Cake(double amount, double price, double value) {
            this.amount = amount;
            this.price = price;
            this.value = value;
        }

        @Override
        public int compareTo(Cake o) {
            return value > o.value ? -1 : 1;
        }

    }

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));

        String[] in = br.readLine().split(" ");
        int n = Integer.parseInt(in[0]);
        int d = Integer.parseInt(in[1]);

        ArrayList<Cake> list = new ArrayList<Cake>();
        String[] w = br.readLine().split(" "), pr = br.readLine().split(" ");

        for (int i = 0; i < n; i++) {
            double m = Double.parseDouble(w[i]);
            double p = Double.parseDouble(pr[i]);
            double value = p / m;
            list.add(new Cake(m, p, value));
        }

        Collections.sort(list);

        double sum = 0;
        for (int i = 0; i < n; i++) {
            if (d - list.get(i).amount >= 0) {
                sum += list.get(i).price;
                d -= list.get(i).amount;
            } else {
                sum += list.get(i).value * d;
                break;
            }
        }
        System.out.println(String.format("%.2f", sum));
    }
}