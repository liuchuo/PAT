package basicLevel;
//
//1018 锤子剪刀布 （20 分）
//        大家应该都会玩“锤子剪刀布”的游戏：两人同时给出手势，胜负规则如图所示：
//
//        FigCJB.jpg
//
//        现给出两人的交锋记录，请统计双方的胜、平、负次数，并且给出双方分别出什么手势的胜算最大。
//
//        输入格式：
//        输入第 1 行给出正整数 N（≤10
//        ​5
//        ​​ ），即双方交锋的次数。随后 N 行，每行给出一次交锋的信息，即甲、乙双方同时给出的的手势。C 代表“锤子”、J 代表“剪刀”、B 代表“布”，第 1 个字母代表甲方，第 2 个代表乙方，中间有 1 个空格。
//
//        输出格式：
//        输出第 1、2 行分别给出甲、乙的胜、平、负次数，数字间以 1 个空格分隔。第 3 行给出两个字母，分别代表甲、乙获胜次数最多的手势，中间有 1 个空格。如果解不唯一，则输出按字母序最小的解。


import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;

public class T1018 {
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        String str = br.readLine();
        String[] strs = str.split(" ");
        int n = Integer.parseInt(strs[0]);
        int s = 0,p = 0,b = 0; //针对于甲来说
        int jc = 0,jb = 0,jj = 0;
        int yc = 0,yb = 0,yj = 0;
        for (int i = 0 ; i< n ;i++){
            String br1 = br.readLine();
            String[] brs1 = br1.split(" ");
            char j = brs1[0].charAt(0);
            char y = brs1[1].charAt(0);
            if(j == 'C' && y == 'J'){
                s++;
                jc++;
            }
            if(j == 'B' && y == 'C'){
                s++;
                jb++;
            }
            if(j == 'J'&& y == 'B'){
                s++;
                jj++;
            }
            if(y == 'C' && j == 'J'){
                b++;
                yc++;
            }
            if(y == 'B' && j == 'C'){
                b++;
                yb++;
            }
            if(y == 'J' && j == 'B'){
                b++;
                yj++;
            }
        }
        p = n - s - b;
        System.out.println(s +" " + p + " " + b);
        System.out.println(b +" " + p + " " + s);
        printMax(jj,jc,jb);
        System.out.print(" ");
        printMax(yj,yc,yb);

    }
    public static void printMax(int cntJ, int cntC, int cntB)//通过甲/乙三种出拳手势赢的次数判断哪种手势赢的次数最多
    {
        if(cntB >= cntJ && cntB >= cntC)
            System.out.print("B");
        else if(cntC > cntB && cntC >= cntJ)
            System.out.print("C");
        else if(cntJ > cntB && cntJ > cntC)
            System.out.print("J");
    }

}
