package basicLevel;
//
//1007 素数对猜想 （20 分）
//        让我们定义d
//        ​n
//        ​​ 为：d
//        ​n
//        ​​ =p
//        ​n+1
//        ​​ −p
//        ​n
//        ​​ ，其中p
//        ​i
//        ​​ 是第i个素数。显然有d
//        ​1
//        ​​ =1，且对于n>1有d
//        ​n
//        ​​ 是偶数。“素数对猜想”认为“存在无穷多对相邻且差为2的素数”。
//
//        现给定任意正整数N(<10
//        ​5
//        ​​ )，请计算不超过N的满足猜想的素数对的个数。
//
//        输入格式:
//        输入在一行给出正整数N。
//
//        输出格式:
//        在一行中输出不超过N的满足猜想的素数对的个数。
//
//        输入样例:
//        20
//        输出样例:
//        4


import java.util.Scanner;

public class T1007 {
    public static void main(String[] args) {
//        long n = new Scanner(System.in).nextInt();
//        int count = 0;
//        for (int i = 3 ; i <= n ;i++){
//            if (fun(i) && fun(i + 2)) {
//                count++;
//            }
//        }
//        System.out.print(count);
//
//    }
//    private static boolean fun(int n){
//        if (n == 2 || n == 3){
//            return true;
//        }
//        if (n % 6 !=1 && n % 6 != 5 )
//            return false;
//        for (int i = 5 ;i < Math.sqrt(n); i+=6){
//            if (n % i == 0 | n % (i + 2) == 0)
//                return false;
//        }
//        return true;
//    }
        int n = new Scanner(System.in).nextInt();
        int i, j ,cnt = 0;
        int pre = 2;
        for (i = 3 ;i <= n;i++){
            for (j = 2 ;j < Math.sqrt(i);j++){
                if (i % j == 0)
                    break;
            }
            if (j > Math.sqrt(i)){
                if (i - pre == 2){
                    cnt++;
                }
                pre = i;
            }
        }
        System.out.print(cnt);
    }
}
