import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStream;
import java.io.InputStreamReader;
import java.math.BigInteger;
import java.util.*;

public class Main {

    private static boolean f = false;

    public static void main(String[] args) throws IOException {

        Reader.init(System.in);
        int loop = Reader.nextInt();
        for (int i = 0; i < loop; i++) {
            int num = Reader.nextInt();
            f = false;

            if (num == 0){
                System.out.println("Yes");
                continue;
            }

            TreeNode treeNode = new TreeNode();
            treeNode.val = Reader.nextInt();

            boolean flag = true;

            TreeNode root = treeNode;
            Stack<TreeNode> stack = new Stack<>();

            for (int j = 1; j < num; j++) {
                stack.add(treeNode);
                TreeNode t = new TreeNode();
                t.val = Reader.nextInt();

                if (Math.abs(t.val) < Math.abs(stack.peek().val)){
                    stack.peek().left = t;

                    if (stack.peek().val < 0 && t.val < 0){
                        flag = false;
                        continue;
                    }
                    treeNode = t;
                    continue;
                }
                while (!stack.isEmpty() && Math.abs(stack.peek().val) < Math.abs(t.val)){
                    treeNode = stack.pop();
                }
                treeNode.right = t;

                if (treeNode.val < 0 && t.val < 0){
                    flag = false;
                    continue;
                }
                treeNode = t;
            }

            if (!flag){
                System.out.println("No");
                continue;
            }
            if (root.val < 0) {
                System.out.println("No");
                continue;
            }

            RBT(root);

            if (!f) 
                System.out.println("Yes");
            else 
                System.out.println("No");
        }
    }

    private static int RBT(TreeNode treeNode) {

        if (f) return -1;
        
        if (treeNode == null) 
            return 0;
        
        if (treeNode.val < 0){
            if (treeNode.left != null && treeNode.left.val < 0)
                f = true;
            
            if (treeNode.right != null && treeNode.right.val < 0)
                f = true;
        }
        
        if (treeNode.val < 0)
            treeNode.val = 0;
        else
            treeNode.val = 1;
        
        int left = RBT(treeNode.left);
        int right = RBT(treeNode.right);

        if (left != right)
            f = true;
        
        treeNode.val = treeNode.val + left;
        return treeNode.val;
    }
}

class TreeNode{
    int val;
    TreeNode left;
    TreeNode right;
}

class Reader {
    static BufferedReader reader;
    static StringTokenizer tokenizer;

    static void init(InputStream input) {
        reader = new BufferedReader(
                new InputStreamReader(input) );
        tokenizer = new StringTokenizer("");
    }

    static String next() throws IOException {
        while ( ! tokenizer.hasMoreTokens() ) {
            //TODO add check for eof if necessary
            tokenizer = new StringTokenizer(
                    reader.readLine() );
        }
        return tokenizer.nextToken();
    }

    static int nextInt() throws IOException {
        return Integer.parseInt( next() );
    }

    static double nextDouble() throws IOException {
        return Double.parseDouble( next() );
    }

    static BigInteger nextBigInteger() throws IOException {
        return new BigInteger( next() );
    }
}