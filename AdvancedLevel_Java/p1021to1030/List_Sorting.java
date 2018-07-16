package p1021to1030;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.Arrays;
import java.util.Comparator;

/**
 * 1028 List Sorting (25)（25 分）
    point 6 time out
 */
public class List_Sorting {
    static class Student implements Comparable<Student>{
        String id;
        String name;
        String score;

        Student(String id, String name, String score) {
            this.id = id;
            this.name = name;
            this.score = score;
        }

        @Override
        public int compareTo(Student o) {
            return id.compareTo(o.id);
        }
    }
    /**
     * 1028 List Sorting (25)（25 分）
     point 6 time out
     读取输入并输出就会超时。。。 没有办法
     */
    public static void main(String[] args) throws IOException {
        BufferedReader reader = new BufferedReader(new InputStreamReader(System.in));
        String[] split = reader.readLine().split(" ");
        int counts = Integer.valueOf(split[0]);
        Student[] studentArray = new Student[counts];
        for (int i = 0; i < counts; i++) {
            String[] s = reader.readLine().split(" ");
            studentArray[i] = new Student(s[0], s[1], s[2]);
        }
        switch (split[1]) {
            case "1":
                Arrays.sort(studentArray);
                break;
            case "2":
                Arrays.sort(studentArray, new Comparator<Student>() {
                    @Override
                    public int compare(Student o1, Student o2) {
                        int compare=o1.name.compareTo(o2.name);
                        return compare==0?o1.id.compareTo(o2.id):compare;
                    }
                });
                break;
            case "3":
                Arrays.sort(studentArray, new Comparator<Student>() {
                    @Override
                    public int compare(Student o1, Student o2) {
                        int compare=o1.score.compareTo(o2.score);
                        return compare==0?o1.id.compareTo(o2.id):compare;
                    }
                });
                break;
        }
        for (Student s:studentArray){
            System.out.printf("%s %s %s\n",s.id,s.name,s.score);
        }
    }
}
