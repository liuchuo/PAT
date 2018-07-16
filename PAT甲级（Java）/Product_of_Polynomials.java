package PTA.p1001to1010;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.Arrays;

/**
 * 1009 Product of Polynomials (25)（25 分）
 */
public class Product_of_Polynomials {

    public static void main(String[] args) throws IOException {
        BufferedReader reader = new BufferedReader(new InputStreamReader(System.in));
        double[] line1 = Arrays.stream(reader.readLine().split(" "))
                .mapToDouble(Double::valueOf).toArray();
        double[] line2 = Arrays.stream(reader.readLine().split(" "))
                .mapToDouble(Double::valueOf).toArray();
        double[] answer = new double[2001];
        for (int i = 1; i < line1.length; i += 2) {
            for (int j = 1; j < line2.length; j += 2) {
                int exp1 = (int) line1[i];
                int exp2 = (int) line2[j];
                double coeff1 = line1[i + 1];
                double coeff2 = line2[j + 1];
                int exponent = exp1 + exp2;
                double coefficient = coeff1 * coeff2;
                if (coefficient != 0.0) {
                    answer[exponent] += coefficient;
                }
            }
        }
        StringBuilder builder = new StringBuilder();
        int counts = 0;
        for (int i = answer.length - 1; i >= 0; i--) {
            double v = answer[i];
            if (v != 0.0) {
                counts++;
//                String format=Math.floor(v*10)/10.0+"";
                String format=v+"";
//                String format = String.format("%.1f", v);
                builder.append(i).append(" ").append(format).append(" ");
            }
        }
        builder.insert(0, counts + " ");
        builder.deleteCharAt(builder.length() - 1);
        System.out.println(builder);
    }
}
