import java.util.Scanner;


public class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        while (sc.hasNext()) {
            String str = sc.nextLine().trim().toLowerCase();
            char[] chs = str.toCharArray();  //°Ñ×Ö·û´®²ð·Ö
            int max = 0;
            int index = 0;
            int[] count = new int[1000];
            for (int i = 0; i < chs.length; i++) {
                count[chs[i]] += 1;
            }
            for (int i = 0; i < 1000; i++) {
                if (((char)(i) >= 'a' && (char)(i)  <= 'z') && count[i] > max) {
                    max = count[i];
                    index = i;
                }
            }
            System.out.println((char) index + " " + max);

        }
    }
}