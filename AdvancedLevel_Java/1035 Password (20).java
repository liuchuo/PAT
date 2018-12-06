import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.ArrayList;


public class Main {
    static class Node {
        String username;
        char[] password;

        public Node(String username, char[] password) {
            this.username = username;
            this.password = password;
        }
    }

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        int n = Integer.parseInt(br.readLine());
        ArrayList<Node> list = new ArrayList<Node>();
        
        for (int i = 0; i < n; i++) {
            String[] line = br.readLine().split(" ");
            char[] chs = line[1].toCharArray();
            
            boolean flag = false;
            for (int j = 0; j < chs.length; j++) {
                if (chs[j] == '1') {
                    chs[j] = '@';
                    flag = true;
                } else if (chs[j] == '0') {
                    chs[j] = '%';
                    flag = true;
                } else if (chs[j] == 'l') {
                    chs[j] = 'L';
                    flag = true;
                } else if (chs[j] == 'O') {
                    chs[j] = 'o';
                    flag = true;
                }
            }
            if (flag) {
                Node node = new Node(line[0], chs);
                list.add(node);
            }
        }
        if (list.size() == 0) {
            if (n == 1) {
                System.out.println("There is " + n + " account and no account is modified");
            } else {
                System.out.println("There are " + n + " accounts and no account is modified");
            }
        } else {
            System.out.println(list.size());
            for (Node item : list) {
                System.out.print(item.username + " ");
                System.out.println(item.password);
            }
        }

    }

}
