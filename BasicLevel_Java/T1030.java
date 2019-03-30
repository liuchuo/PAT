package basicLevel;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.Arrays;

public class T1030 {
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        String[] str1 = br.readLine().split(" ");
        int n = Integer.parseInt(str1[0]);
        double p = Double.parseDouble(str1[1]);
        String[] c = br.readLine().split(" ");
        int i,j;
        int[] num = new int[n];
        for (i = 0 ; i < c.length; i ++){
            num[i] = Integer.parseInt(c[i]);
        }
        Arrays.sort(num);
        int ans = 0;
        for(j = 0; j < i; j++)
        {
            for(int k = j + ans; k < i; k++)  //k从最大长度开始，减少循环次数，防止超时
            {
                if(num[k] > num[j] * p)
                    break;
                if(k-j+1 > ans)
                {
                    ans = k - j + 1;
                }
            }
        }
        System.out.print(ans);
    }
}
