import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;

public class Main {

    private static BufferedReader bufferedReader = new BufferedReader(new InputStreamReader(System.in));
    
    public static void main(String[] args) throws IOException {
        
        String s = bufferedReader.readLine();

        int length = 0;

        for (int i = 1; i < s.length() - 1; i++) {

            if (s.charAt(i - 1) == s.charAt(i + 1)){

                int flag = 1;
                while ((i - flag) >= 0 && (i + flag) <= s.length() - 1 && s.charAt(i - flag) == s.charAt(i + flag)){
                    flag++;
                }
                int tem = flag * 2 - 1;
                if (length < tem){
                    length = tem;
                }
            }
        }

        for (int i = 0; i < s.length() - 1; i++) {

            if (s.charAt(i) == s.charAt(i + 1)){
                int flag = 1;

                while ((i - flag + 1) >= 0 && (i + flag) <= s.length() - 1 && s.charAt(i - flag + 1) == s.charAt(i + flag)){
                    flag++;
                }
                int tem = flag * 2 - 2;
                if (length < tem){
                    length = tem;
                }
            }
        }
        if (length == 0)
            System.out.println(1);
        else 
            System.out.println(length);
    }
}