package PTA.p1001to1010;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.math.BigInteger;

/**
 * 1010 Radix (25)（25 分）
 */
public class Radix {
    /**
     * 二分查找,搜索可行的radix
     * @param value 给定的value串
     * @param expect 期望的检索值 10进制表示
     * @return result
     */
    private static String binarySearch(final String value, final BigInteger expect) {
        //重点在于最大值和最小值的界定
        //下界大于 所有位中最大值
        //考虑2 2 1 10 这个case
        BigInteger start = BigInteger.valueOf(maxBitValue(value)+1);
        //上界不小于下界,不大于expect
        //考虑200000 1 1 10 这个case
        BigInteger end = expect.compareTo(start)<0?start:expect;

        BigInteger result_radix = null;
        while (end.compareTo(start)>=0) {
            BigInteger middle = start.add (end).divide(BigInteger.valueOf(2));
            BigInteger ten_value = convert2ten(value, middle);
            int compare = ten_value.compareTo(expect);
            if (compare>=0) {
                if(compare==0&&(result_radix==null||middle.compareTo(result_radix)<0)){
                    result_radix=middle;
                }
                end = middle.subtract(BigInteger.valueOf(1));
            } else {
                start = middle.add(BigInteger.valueOf(1));
            }
        }
        return result_radix==null?"Impossible":result_radix+"";
    }

    /**
     * 任意进制转10进制
     *
     * @param value positive
     * @param radix 2-36
     * @return ten radix value
     */
    private static BigInteger convert2ten(String value, BigInteger radix) {
        char[] chars = value.toCharArray();
        BigInteger sum =BigInteger.ZERO;
        for (char aChar : chars) {
            int v = char2int(aChar);
            if (radix.compareTo(BigInteger.valueOf(v))<0) {
                return BigInteger.valueOf(Long.MAX_VALUE);
            }
            sum=sum.multiply(radix)
                    .add(BigInteger.valueOf(v));
        }
        return sum;
    }

    /**
     * 根据value 求位最大值
     * @param value
     * @return
     */
    private static int maxBitValue(String value){
        int max=0;
        for (char c : value.toCharArray()) {
            int i = char2int(c);
            if(i>max)
                max=i;
        }
        return max;
    }
    /**
     * char convert to int
     *
     * @param c input char [0-9]or[a-z]
     * @return int value between 0-35
     */
    private static int char2int(char c) {
        int ret = c - 48;
        return ret < 10 ? ret : ret - 39;
    }

    /**
     * 越界问题恶心的要死。。。 shit!
     * Java的BigInteger写起来也机器恶心,啥时候kotlin和scala能普及呢?
     * @param args
     * @throws IOException
     */
    public static void main(String[] args) throws IOException {
        BufferedReader reader = new BufferedReader(new InputStreamReader(System.in));
        String[] split = reader.readLine().split(" ");
        String v1 = split[0], v2 = split[1];
        String know_v = v1, unknow_v = v2;
        BigInteger know_radix = BigInteger.valueOf(Integer.valueOf(split[3]));
        if ("2".equals(split[2])) {
            know_v = v2;
            unknow_v = v1;
        }
        //期望值转化为十进制 相当于把输入转化为 N1 N2 1 10
        BigInteger expect = convert2ten(know_v, know_radix);
        String s = binarySearch(unknow_v, expect);
        System.out.println(s);
    }
}
