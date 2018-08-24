import java.util.LinkedList;
import java.util.Scanner;

public class Main {
    static Scanner scanner = new Scanner(System.in);

    static class Node {
        int value;
        Node left;
        Node right;

        Node(int value) {
            this.value = value;
        }

        @Override
        public String toString() {
            return "Node{" +
                    "value=" + value +
                    ", left=" + left +
                    ", right=" + right +
                    '}';
        }
    }

    private static Node bulidTree() {
        int size = scanner.nextInt();
        int[] postOrder = new int[size];
        int[] inOrder = new int[size];
        for (int i = 0; i < size; i++) {
            postOrder[i] = scanner.nextInt();
        }
        for (int i = 0; i < size; i++) {
            inOrder[i] = scanner.nextInt();
        }
        Node root = build(postOrder, inOrder,
                0, size - 1,
                0, size - 1);
        return root;
    }

    private static Node build(int[] postOrder, int[] inOrder, int postStart, int postEnd, int inStart, int inEnd) {
        if (postStart > postEnd) {
            return null;
        }
        if (postStart == postEnd) {
            return new Node(postOrder[postStart]);
        }
        int root = postOrder[postEnd--];

        //find root in inOrder
        int inIndex = -1;
        for (int i = inStart; i <= inEnd; i++) {
            if (root == inOrder[i]) {
                inIndex = i;
                break;
            }
        }
        //recursion build
        int leftSize = inIndex - inStart;
        int rightSize = inEnd - inIndex;
        Node rootNode = new Node(root);
        rootNode.left = build(postOrder, inOrder,
                postStart, postStart + leftSize - 1,
                inStart, inIndex - 1);
        rootNode.right = build(postOrder, inOrder, postEnd - rightSize + 1, postEnd, inIndex + 1, inEnd);
        return rootNode;
    }

    public static void main(String[] args) {
        Node root = bulidTree();
        LinkedList<Node> queue = new LinkedList<>();
        queue.add(root);
        while (!queue.isEmpty()) {
            Node poll = queue.poll();
            if (poll.left != null) {
                queue.add(poll.left);
            }
            if (poll.right != null) {
                queue.add(poll.right);
            }
            System.out.printf("%d%s", poll.value, queue.isEmpty() ? "\n" : " ");
        }
    }
}