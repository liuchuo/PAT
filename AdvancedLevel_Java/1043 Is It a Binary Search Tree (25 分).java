import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStream;
import java.io.InputStreamReader;
import java.util.ArrayList;
import java.util.List;
import java.util.StringTokenizer;

public class Main {

    private static boolean flag = true;
    private static StringBuilder stringBuilder = new StringBuilder();

    public static void main(String[] args) throws IOException {
        Reader.init(System.in);
        int nums = Reader.nextInt();

        List<Integer> list = new ArrayList<>();
        for (int i = 0; i < nums; i++) {
            list.add(Reader.nextInt());
        }
        TreeNode treeNode = createTree(list);
        if (flag){
            postf(treeNode);
            System.out.println("YES");
            System.out.println(stringBuilder.substring(1));
        }else {
            flag = true;
            TreeNode treeNode1 = createMirrorTree(list);
            if (flag){
                postf(treeNode1);
                System.out.println("YES");
                System.out.println(stringBuilder.substring(1));
            }else {
                System.out.println("NO");
            }
        }
    }

    private static void postf(TreeNode treeNode){
        if (treeNode == null){
            return;
        }
        postf(treeNode.left);
        postf(treeNode.right);
        stringBuilder.append(" ").append(treeNode.val);
    }

    private static TreeNode createMirrorTree(List<Integer> list){

        if (list.size() == 0){
            return null;
        }

        int k = 1;

        while (k < list.size() && list.get(k) >= list.get(0)){
            k++;
        }

        List<Integer> right = list.subList(k,list.size());
        for (int i:right) {
            if (i >= list.get(0)){
                flag = false;
                return null;
            }
        }

        TreeNode treeNode = new TreeNode();
        treeNode.val = list.get(0);

        treeNode.left = createMirrorTree(list.subList(1,k));
        treeNode.right = createMirrorTree(list.subList(k,list.size()));

        return treeNode;
    }

    private static TreeNode createTree(List<Integer> list){

        if (list.size() == 0){
            return null;
        }

        int k = 1;

        while (k < list.size() && list.get(k) < list.get(0)){
            k++;
        }

        List<Integer> right = list.subList(k,list.size());
        for (int i:right) {
            if (i < list.get(0)){
                flag = false;
                return null;
            }
        }

        TreeNode treeNode = new TreeNode();
        treeNode.val = list.get(0);

        treeNode.left = createTree(list.subList(1,k));
        treeNode.right = createTree(list.subList(k,list.size()));

        return treeNode;
    }
}

class TreeNode{
    int val;
    TreeNode left;
    TreeNode right;
}

class Reader{

    static BufferedReader reader;
    static StringTokenizer tokenizer;

    static void init(InputStream inputStream){
        reader = new BufferedReader(new InputStreamReader(inputStream));
        tokenizer = new StringTokenizer("");
    }

    static String next() throws IOException{
        while (! tokenizer.hasMoreTokens()){
            tokenizer = new StringTokenizer(reader.readLine());
        }
        return tokenizer.nextToken();
    }
    static int nextInt() throws IOException {
        return Integer.parseInt( next() );
    }
}