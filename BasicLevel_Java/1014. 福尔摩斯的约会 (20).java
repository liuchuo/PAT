import java.util.Scanner;

public class Main {
    final static String[] week = new String[]{"MON", "TUE", "WED", "THU", "FRI", "SAT", "SUN"};

    public static void main(String[] args) {
        Scanner in = new Scanner(System.in);
        String str1 = in.nextLine();
        String str2 = in.nextLine();
        String str3 = in.nextLine();
        String str4 = in.nextLine();
        char a1 = ' ', a2 = ' ';
        int a3 = -1;
        boolean a11 = true;
        int i;
        char[] c1 = str1.toCharArray();
        char[] c2 = str2.toCharArray();
        char[] c3 = str3.toCharArray();
        char[] c4 = str4.toCharArray();
        for (i = 0; i < (c1.length > c2.length ? c2.length : c1.length); i++) {
            if (c1[i] == c2[i] && a11 && c1[i] >= 'A' && c1[i] <= 'G') {
                a1 = c1[i];
                a11 = false;
                i++;
            }
            if (!a11 && c1[i] == c2[i] && (c1[i] >= 'A' && c1[i] <= 'N' || c1[i] >= '0' && c1[i] <= '9')) {
                a2 = c1[i];
                break;
            }
        }
        for (i = 0; i < (c3.length > c4.length ? c4.length : c3.length); i++) {
            if (c3[i] == c4[i] && c3[i] >= 'A' && c3[i] <= 'z') {
                a3 = i;
                break;
            }
        }
        System.out.print(week[a1 - 65] + " " + (a2 > '9' ? (a2 - 55) : ("0" + a2)) + ":" + (a3 > 9 ? a3 : ("0" + a3)));
    }
}