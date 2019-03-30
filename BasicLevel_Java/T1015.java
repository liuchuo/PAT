package basicLevel;



import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.util.Collections;
import java.util.Vector;

public class T1015 {
    public static void main(String[] args) throws Exception{
        int sum = 0;
        Vector<Stu> v1 = new Vector<>();
        Vector<Stu> v2 = new Vector<>();
        Vector<Stu> v3 = new Vector<>();
        Vector<Stu> v4 = new Vector<>();
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        String da = br.readLine();
        String[] str = da.split(" ");
        int n = Integer.parseInt(str[0]);
        int M = Integer.parseInt(str[1]);
        int T = Integer.parseInt(str[2]);
        for (int i = 0;i < n;i++){
            String string = br.readLine();
            String[] strings = string.split(" ");
            String id = strings[0];
            int m = Integer.parseInt(strings[1]);
            int t = Integer.parseInt(strings[2]);
            Stu s = new Stu(id,m,t);
            if (s.getM() >= M && s.getT() >= M){
                sum++;
                if (s.getM() >= T && s.getT() >= T){
                    v1.add(s);
                }else if (s.getM() >= T && s.getT() < T){
                    v2.add(s);
                }else if (s.getM() < T && s.getT() < T && s.getM() >= s.getT()){
                    v3.add(s);
                }else {
                    v4.add(s);
                }
            }
        }
        Collections.sort(v1,Collections.reverseOrder());
        Collections.sort(v2);
        Collections.sort(v3);
        Collections.sort(v4);
        System.out.println(sum);
        for (Stu s : v1){
            s.printinfo();
        }
//        for (Stu s : v2){
//            s.printinfo();
//        }
//        for (Stu s : v3){
//            s.printinfo();
//        }
//        for (Stu s : v4){
//            s.printinfo();
//        }

    }


}
class Stu implements Comparable<Stu>{
    private String id;
    private int m;
    private int t;

    public String getId() {
        return id;
    }

    public void setId(String id) {
        this.id = id;
    }

    public int getM() {
        return m;
    }

    public void setM(int m) {
        this.m = m;
    }

    public int getT() {
        return t;
    }

    public void setT(int t) {
        this.t = t;
    }

    public Stu(String id, int m, int t) {
        this.id = id;
        this.m = m;
        this.t = t;
    }

    @Override
    public int compareTo(Stu o) {
        if ((this.getM() + this.getT()) != (o.getM() + o.getT())){
            System.out.println(this.getId() + " "  + o.getId());
            return (((this.getM() + this.getT()) > (o.getM() + o.getT()))? 1:0);
        }else {
            if (this.getM() != o.getM()){
                System.out.println(this.getId() + " "  + o.getId());
                return ((this.getM() > o.getM())?1:0);
            }else {
                System.out.println(this.getId() + " "  + o.getId());
                return ((this.getId().compareTo(o.getId())) < 0?0:1);
            }
        }
    }
    public void printinfo(){
        System.out.println(this.getId() +" " + this.getM() + " " + this.getT());
    }
}
