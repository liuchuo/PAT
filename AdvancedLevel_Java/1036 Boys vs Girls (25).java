import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;


public class Main {

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        int T = Integer.parseInt(br.readLine());
        
        int max = -1;
        int min = 101;

        String male = "", female = "";
        for (int i = 0; i < T; i++) {
            String[] col = br.readLine().split(" ");
            int score =  Integer.parseInt(col[3]);

            if (col[1].equals("M")) {
                if (score < min) {
                    min = score;
                    male = col[0] + " " + col[2]; 
                }
            } else {
                if (score > max) {
                    max = score;
                    female = col[0] + " " + col[2];
                }
            }
        }
        
        if (max != -1) {
            System.out.println(female);
        } else {
            System.out.println("Absent");
        }
        if (min != 101) {
            System.out.println(male);
        } else {
            System.out.println("Absent");
        }
        if (max != -1 && min != 101) {
            System.out.println(Math.abs(max-min));
        } else {
            System.out.println("NA");
        }
        
    }
}
