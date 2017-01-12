1064. 朋友数(20)
如果两个整数各位数字的和是一样的，则被称为是“朋友数”，而那个公共的和就是它们的“朋友证号”。例如123和51就是朋友数，因为1+2+3 = 5+1 = 6，而6就是它们的朋友证号。给定一些整数，要求你统计一下它们中有多少个不同的朋友证号。注意：我们默认一个整数自己是自己的朋友。

输入格式：

输入第一行给出正整数N。随后一行给出N个正整数，数字间以空格分隔。题目保证所有数字小于104。

输出格式：

首先第一行输出给定数字中不同的朋友证号的个数；随后一行按递增顺序输出这些朋友证号，数字间隔一个空格，且行末不得有多余空格。

输入样例：
8
123 899 51 998 27 33 36 12
输出样例：
4
3 6 9 26

import java.util.Scanner;
import java.util.Set;
import java.util.TreeSet;

public class Main {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        int numOfInteger = scanner.nextInt();
        Set<Integer> set = new TreeSet<Integer>();
        for (int i = 0; i < numOfInteger; i++) {
            int temp = scanner.nextInt();
            set.add(getFriendId(temp));
        }
        scanner.close();
        System.out.println(set.size());
        boolean isFirst = true;
        for (int id : set) {
            if (!isFirst) {
                System.out.print(" ");
            }
            System.out.print(id);
            isFirst = false;
        }
    }

    private static int getFriendId(int num) {
        int sum = 0;
        while(num != 0) {
            sum += num % 10;
            num /= 10;
        }
        return sum;
    }
}