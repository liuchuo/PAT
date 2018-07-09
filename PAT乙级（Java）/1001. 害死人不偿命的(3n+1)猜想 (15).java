import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;

public class Main {
  public static void main(String[] args) throws IOException {
    BufferedReader bufferedReader = new BufferedReader(new InputStreamReader(System.in));
    int number = Integer.parseInt(bufferedReader.readLine());
    bufferedReader.close();
    int cnt = 0;
    while (number != 1) {
      if (number % 2 != 0) number = 3 * number + 1;
      number /= 2;
      cnt++;
    }
    System.out.print(cnt);
  }
}
