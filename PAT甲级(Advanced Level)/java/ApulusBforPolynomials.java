package PTA;


import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;

/**
 * 1002 A+B for Polynomials (25)（25 分）
 *
 * This time, you are supposed to find A+B where A and B are two polynomials.
 * <p>
 * Sample Input
 * <p>
 * 2 1 2.4 0 3.2  //2.4x+3.2
 * 2 2 1.5 1 0.5  //1.5x^2+0.5x
 * Sample Output
 * <p>
 * 3 2 1.5 1 2.9 0 3.2
 */
public class ApulusBforPolynomials {
    /**
     * 多项式
     */
    static class Polynomial {
        private static int MAX_SIZE=1001;
        /**
         * double array 保存多项式
         * index 作为指数
         * value 作为系数
         */
        private double[] coefficients;
        Polynomial(String[] splits) {
            coefficients = new double[MAX_SIZE];
            for (int i = 1; i < splits.length; i += 2) {
                int exp = Integer.valueOf(splits[i]);
                coefficients[exp]=Double.valueOf(splits[i+1]);
            }
        }

        Polynomial() {
            coefficients = new double[MAX_SIZE];
        }

        /**
         * 加法
         *
         * @param other other polynomial
         * @return sum of the polynomials
         */
        public Polynomial add(Polynomial other) {
            Polynomial result = new Polynomial();
            for (int i = 0; i < MAX_SIZE; i++) {
                double v = this.coefficients[i] + other.coefficients[i];
                v=Math.round(v*10)/10.0;
                if(v!=0.0){
                   result.coefficients[i]=v;
                }
            }
            return result;
        }

        @Override
        public String toString() {
            StringBuilder stringBuilder = new StringBuilder();

            int size=0;
            for (int i = coefficients.length-1; i >=0 ; i--) {
                double v=coefficients[i];
                if(v!=0.0){
                    stringBuilder.append(i).append(" ").append(v).append(" ");
                    size++;
                }
            }
            stringBuilder.insert(0,size+" ");
            stringBuilder.deleteCharAt(stringBuilder.length() - 1);
            return stringBuilder.toString();
        }
    }

    private static BufferedReader reader = new BufferedReader(new InputStreamReader(System.in));

    public static String[] readLine() throws IOException {
        return reader.readLine().split(" ");
    }

    public static void main(String[] args) throws IOException {
        Polynomial add = new Polynomial(readLine()).add(new Polynomial(readLine()));
        System.out.println(add);
    }
}
