

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;

public class Main {
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        int n = Integer.parseInt(br.readLine());
        Info[] infos = new Info[n + 1];
        for (int i = 0; i < n; i++) {
            String[] str = br.readLine().split(" ");
            Info info = new Info(Integer.parseInt(str[1]), str[0], Integer.parseInt(str[2]));
            infos[Integer.parseInt(str[1])] = info;
        }
        int m = Integer.parseInt(br.readLine());
        String[] s =  br.readLine().split(" ");
        for (int i = 0; i < m; i++) {

            System.out.println(infos[Integer.parseInt(s[i])].toString());
        }

    }
}
class Info{
    int index;
    String id;
    int seatId;

    public Info() {
    }

    public Info(int index, String id, int seatId) {
        this.index = index;
        this.id = id;
        this.seatId = seatId;
    }

    public int getIndex() {
        return index;
    }

    public void setIndex(int index) {
        this.index = index;
    }

    public String getId() {
        return id;
    }

    public void setId(String id) {
        this.id = id;
    }

    public int getSeatId() {
        return seatId;
    }

    public void setSeatId(int seatId) {
        this.seatId = seatId;
    }

    @Override
    public String toString() {
        return id + " " + seatId;
    }
}
