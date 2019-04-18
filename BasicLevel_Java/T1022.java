package basicLevel;

//import java.io.BufferedReader;
//import java.io.IOException;
//import java.io.InputStreamReader;
//import java.util.Arrays;
//
//public class T1022 {
//    public static void main(String[] args) throws IOException {
//        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
//        String[] strs = br.readLine().split(" ");
//        char[] chars = new char[strs.length];
//        Arrays.sort(strs);
//        for (int i = 0; i< strs.length;i++){
//            chars[i] = strs[i].charAt(0);
//        }
//        int flag = -1;
//        for (int i = 0; i < strs.length;i++){
//            if (chars[0] == '0'){
//                if (chars[i] != '0'){
//                    System.out.print(chars[i]);
//                    flag = i;
//                    break;
//                }
//            }
//        }
//        for (int i = 0 ;i < chars.length;i++){
//            if (i != flag){
//                System.out.print(chars[i]);
//            }
//        }
//    }
//}
import java.io.BufferedReader;
import java.io.InputStreamReader;

 class Main {

    public static void main(String[] args) throws Exception {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        String[] in = br.readLine().split(" ");
        boolean b = true;
        for(int i = 1; i < in.length;i++){
            if(Integer.parseInt(in[i]) > 0 && b == true){
                b = false;
                System.out.print(i);
                if(Integer.parseInt(in[0]) > 0){
                    for(int j = 0; j < Integer.parseInt(in[0]);j++)
                        System.out.print("0");

                }
                for(int k = 1;k<Integer.parseInt(in[i]);k++)
                    System.out.print(i);

            }else if(Integer.parseInt(in[i]) > 0){
                for(int k = 0;k<Integer.parseInt(in[i]);k++)
                    System.out.print(i);
            }
        }
    }

}