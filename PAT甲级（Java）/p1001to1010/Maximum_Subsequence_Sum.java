package PTA.p1001to1010;


import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;

/**
 * 1007 Maximum Subsequence Sum (25)（25 分）
 */
public class Maximum_Subsequence_Sum {
    /**
     * 注意考点
     * -2 0 0 -1
     * @param args
     * @throws IOException
     */
    public static void main(String[] args) throws IOException {
        BufferedReader reader = new BufferedReader(new InputStreamReader(System.in));
        reader.readLine();
        String[] split = reader.readLine().split(" ");



        int final_max_sum =Integer.MIN_VALUE;
        int sub_sum = 0;
        int start_index = 0;
        int final_start=0,final_end=split.length-1;
        for (int i = 0; i < split.length; i++) {
            int value = Integer.valueOf(split[i]);
            sub_sum = sub_sum + value;
            //局部子列和大于等于0
            if (sub_sum >= 0) {
                //局部最大大于全局最大,更新全局最大
                if (sub_sum > final_max_sum) {
                    final_max_sum = sub_sum;

                    if(start_index!=final_start){
                        final_start=start_index;
                    }
                    final_end=i;
                }
            } else {
                //局部子列和<0丢弃
                sub_sum = 0;
                start_index=i+1;
            }
        }
        if(final_max_sum<0){
            final_max_sum=0;
        }
        System.out.print(final_max_sum+" ");
        System.out.print(Integer.valueOf(split[final_start])+" ");
        System.out.println(Integer.valueOf(split[final_end]));
    }
}
