import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.HashMap;
import java.util.Map;

public class Main {

    static class Stu{
        String id;
        String award = "Chocolate";
        boolean checked = false;
    }

    static BufferedReader bufferedReader = new BufferedReader(new InputStreamReader(System.in));

    public static void main(String[] args) throws IOException {

        int nums = Integer.parseInt(bufferedReader.readLine());

        Map<String,Stu> map = new HashMap<>();

        for (int i = 0; i < nums; i++) {
            String id = bufferedReader.readLine();
            Stu stu = new Stu();
            stu.id = id;

            if (i == 0){
                stu.award = "Mystery Award";
            }
            if (isPrime(i + 1)){
                stu.award = "Minion";
            }
            map.put(id,stu);
        }

        int tasks = Integer.parseInt(bufferedReader.readLine());
        StringBuilder stringBuilder = new StringBuilder();

        for (int i = 0; i < tasks; i++) {
            String id = bufferedReader.readLine();
            Stu stu = map.getOrDefault(id,null);

            if (stu == null){

                stringBuilder.append(id).append(": Are you kidding?\n");
                continue;
            }
            if (stu.checked){
                stringBuilder.append(id).append(": Checked\n");
                continue;
            }

            stu.checked = true;
            stringBuilder.append(id).append(": ").append(stu.award).append("\n");
        }
        System.out.println(stringBuilder.substring(0,stringBuilder.lastIndexOf("\n")));

    }
    private static boolean isPrime(int val){
        if (val == 1) return false;
        if (val == 2) return true;
        if (val % 2 == 0) return false;
        for (int i = 2; i < Math.sqrt(val) + 1; i++) {
            if (val % i == 0)
                return false;
        }
        return true;
    }
}