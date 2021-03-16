import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        Scanner in = new Scanner(System.in);
        int N = in.nextInt(); // 输入人数 N
        String name = null, date = null; // 定义姓名，出生日期
        int year, month, day, count = 0;
        int maxYear = 1814, maxMonth = 9, maxDay = 6; // 定义最大和最小年月日
        int minYear = 2014, minMonth = 9,minDay = 6;
        String maxName = null; // 定义年纪最大和最小人的姓名
        String minName = null;
        for (int i = 0; i < N; i++) { // 开始循环遍历
            name = in.next(); // 输入姓名
            date = in.next(); // 输入出生日期
            String[] Array = date.split("/"); // 定义一个 Array 数组将字符串转换成整数型
            year = Integer.parseInt(Array[0]);
            month = Integer.parseInt(Array[1]);
            day = Integer.parseInt(Array[2]);
            // 用 if() 排除 1814~2014 年以外的人
            if ( (year > 1814 ||(year == 1814 && month > 9) || (year == 1814 && month ==9 && day >= 6)) &&
                    (year < 2014 || (year == 2014 && month < 9) || (year == 2014 && month == 9 && day < 6))){
                count ++; // 符合条件的人 count 自加 1
                // 判断出年纪大的人
                if((year > maxYear ||(year == maxYear && month > maxMonth) || (year == maxYear && month == maxMonth && day >= maxDay))){
                    maxYear = year;
                    maxMonth = month;
                    maxDay = day;
                    maxName = name;
                }
                // 判断出年纪小的人
                if ((year < minYear || (year == minYear && month < minDay) || (year == minYear && month == minMonth && day <= minDay))){
                    minYear = year;
                    minMonth = month;
                    minDay = day;
                    minName = name;
                }
            }
        }
        System.out.print(count);
        if (count != 0) { // 如果 count 不为 0，则输出年青的人和年长的人
            System.out.println(" " + minName + " " + maxName);
        }
    }
}
