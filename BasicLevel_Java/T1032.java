package basicLevel;
//
//1032 挖掘机技术哪家强 （20 分）
//        为了用事实说明挖掘机技术到底哪家强，PAT 组织了一场挖掘机技能大赛。现请你根据比赛结果统计出技术最强的那个学校。
//
//        输入格式：
//        输入在第 1 行给出不超过 10
//        ​5
//        ​​  的正整数 N，即参赛人数。随后 N 行，每行给出一位参赛者的信息和成绩，包括其所代表的学校的编号（从 1 开始连续编号）、及其比赛成绩（百分制），中间以空格分隔。
//
//        输出格式：
//        在一行中给出总得分最高的学校的编号、及其总分，中间以空格分隔。题目保证答案唯一，没有并列。
//
//        输入样例：
//        6
//        3 65
//        2 80
//        1 100
//        2 70
//        3 40
//        3 0
//        输出样例：
//        2 150



import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;

public class T1032 {
    public static int[] school = new int[100005];
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        int n = Integer.parseInt(br.readLine());
        int i,max = -1,maxId = 0;
        for (i = 0 ;i < n;i++){
            String[] str = br.readLine().split(" ");
            int id = Integer.parseInt(str[0]);
            int score = Integer.parseInt(str[1]);
            school[id] += score;
        }
        for (i = 1 ; i <= n ;i++){
            if (school[i] > max){
                max = school[i];
                maxId = i;
            }
        }
        System.out.println(maxId + " " + max);
    }
}
