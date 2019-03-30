import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.HashMap;
import java.util.stream.Stream;

public class Main {
    private static BufferedReader reader = new BufferedReader(new InputStreamReader(System.in));

    static class Course {
        enum Name {
            C(2), M(3), E(4), A(1);
            final int rank;

            Name(int rank) {
                this.rank = rank;
            }
        }

        static Name[] names = Name.values();
        final int score;
        final int course_rank;
        final int id;
        final String name;

        Course(int id, int score) {
            this.score = score;
            this.course_rank = names[id].rank;
            this.id = id;
            this.name = names[id].toString();
        }
    }

    static class Student {
        String id;
        Course[] courses;

        Student(String id, Course[] courses) {
            this.id = id;
            this.courses = courses;
        }
    }

    static String readLine() throws IOException {
        return reader.readLine();
    }

    public static void main(String[] args) throws IOException {
        String[] split = readLine().split(" ");
        int student_nums = Integer.valueOf(split[0]);
        int check_student = Integer.valueOf(split[1]);

        //偷个懒,就都用数组存储
        //score  table
        //0,1,2,3 => C,M,E,A
        //[0-100] score=>counts
        int[][] scoreTable = new int[4][101];
        //course,score=>course_rank
        int[][] rankTable = new int[4][101];

        HashMap<String, Student> students = new HashMap<>(1024, 1);
        for (int i = 0; i < student_nums; i++) {
            String[] line = readLine().split(" ");
            String id = line[0];

            //准备课程
            Course[] courses = new Course[4];
            int sum = 0, index = 0;
            for (int j = 1; j < line.length; j++, index++) {
                Integer score = Integer.valueOf(line[j]);
                sum += score;
                courses[index] = new Course(index, score);
                scoreTable[index][score]++;
            }
            //处理平均值
            int avg_score = sum / index;
            courses[index] = new Course(index, avg_score);
            scoreTable[index][avg_score]++;
            //准备学生
            Student student = new Student(id, courses);
            //存储学生
            students.put(id, student);
        }
        //计算rank
        for (int i = 0; i < scoreTable.length; i++) {
            int[] scores = scoreTable[i];
            int rank = 1;
            for (int j = scores.length - 1; j >= 0; j--) {
                int counts = scores[j];
                if (counts > 0) {
                    rankTable[i][j] = rank;
                    rank += counts;
                }
            }
        }
        for (int i = 0; i < check_student; i++) {
            String id = readLine();
            Student student = students.get(id);
            if (student == null) {
                System.out.println("N/A");
            } else {
                Course course = Stream.of(student.courses).min((o1, o2) -> {
                    int rank_1 = rankTable[o1.id][o1.score];
                    int rank_2 = rankTable[o2.id][o2.score];
                    int compare = rank_1 - rank_2;
                    return compare == 0 ? o1.course_rank - o2.course_rank : compare;
                }).get();
                int rank = rankTable[course.id][course.score];
                System.out.println(rank + " " + course.name);
            }
        }
    }
}