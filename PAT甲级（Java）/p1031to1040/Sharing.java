package p1031to1040;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;

/**
 * 1032 Sharing (25)（25 分）
 * point 5 timeout
 */
public class Sharing {
    static class Node {
        int next;
        int refrence = 1;

        Node(int next) {
            this.next = next;
        }
    }

    static BufferedReader reader = new BufferedReader(new InputStreamReader(System.in));

    /**
     * 1032 Sharing (25)（25 分）
     * point 5 timeout
     */
    public static void main(String[] args) throws IOException {
        String[] split = reader.readLine().split(" ");
        int counts = Integer.valueOf(split[2]);
        int startA = Integer.valueOf(split[0]);
        int startB = Integer.valueOf(split[1]);
        Node[] nodes=new Node[100000];
        for (int i = 0; i < counts; i++) {
            String[] line = reader.readLine().split(" ");
            int address = Integer.valueOf(line[0]);
            int nextAddress = Integer.valueOf(line[2]);
            nodes[address]=new Node(nextAddress);
        }
        int key=startA;
        while (key!=-1){
            Node node = nodes[key];
            node.refrence=0;
            key = node.next;
        }
        key=startB;
        while (key!=-1){
            Node node = nodes[key];
            if(node.refrence==0){
                break;
            }
            key = node.next;
        }
        if(key==-1){
            System.out.println(-1);
        }else {
            System.out.printf("%05d\n",key);
        }
    }
}
