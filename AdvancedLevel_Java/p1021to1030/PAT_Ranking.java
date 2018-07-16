package p1021to1030;

import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.lang.reflect.Field;
import java.util.TreeSet;

/**
 * 1025 PAT Ranking (25)（25 分）
 * check 3  time out
 */
public class PAT_Ranking {
    static class Student implements Comparable<Student> {
        String id;
        int score;
        int region;
        int regionRank;
        int totalRank;

        Student(String id, int score, int region) {
            this.id = id;
            this.score = score;
            this.region = region;
        }

        @Override
        public int compareTo(Student o) {
            int compare = o.score - score;
            return compare == 0 ? id.compareTo(o.id) : compare;
        }
    }

    private static void rank(TreeSet<Student> list, String rankField) throws ReflectiveOperationException {
        int firstRank = 0;
        int index = 0;
        int lastScore = -1;
        Field declaredField = Student.class.getDeclaredField(rankField);
        declaredField.setAccessible(true);
        for (Student s : list) {
            index++;
            if (s.score != lastScore) {
                firstRank = index;
            }
            declaredField.set(s, firstRank);
            lastScore=s.score;
        }
    }
    /**
     * 1025 PAT Ranking (25)（25 分）
     * check 3  time out
     */
    public static void main(String[] args) throws Exception {
        BufferedReader reader = new BufferedReader(new InputStreamReader(System.in));
        Integer region_counts = Integer.valueOf(reader.readLine());
        TreeSet<Student> resultList = null;
        for (int i = 1; i <= region_counts; i++) {
            Integer records = Integer.valueOf(reader.readLine());
            TreeSet<Student> list = new TreeSet<>();
            for (int j = 0; j < records; j++) {
                String[] split = reader.readLine().split(" ");
                Student student = new Student(split[0], Integer.valueOf(split[1]), i);
                list.add(student);
            }
            rank(list,"regionRank");
            if(resultList==null) {
                resultList = list;
            }else {
                resultList.addAll(list);
            }
        }
        rank(resultList,"totalRank");
        System.out.println(resultList.size());
        for (Student student : resultList) {
            System.out.printf("%s %d %d %d\n",
                    student.id,
                    student.totalRank,
                    student.region,
                    student.regionRank);
        }
    }
}
