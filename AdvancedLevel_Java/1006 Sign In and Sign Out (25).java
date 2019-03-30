import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.text.DateFormat;
import java.text.ParseException;
import java.text.SimpleDateFormat;
import java.util.Date;

public class Main {
    static class Record {
        static DateFormat format = new SimpleDateFormat("HH:mm:ss");
        String id;
        Date start;
        Date end;

        Record(String id, String start, String end) throws ParseException {
            this.id = id;
            this.start = format.parse(start);
            this.end = format.parse(end);
        }
    }

    public static void main(String[] args) throws Exception {
        BufferedReader reader = new BufferedReader(new InputStreamReader(System.in));
        int record_counts = Integer.valueOf(reader.readLine());


        String[] split = reader.readLine().split(" ");
        Record record = new Record(split[0], split[1], split[2]);
        Record earliest = record, latest = record;
        for (int i = 1; i < record_counts; i++) {
            split = reader.readLine().split(" ");
            Record newRecord = new Record(split[0], split[1], split[2]);
            if (newRecord.start.compareTo(earliest.start) < 0) {
                earliest = newRecord;
            }
            if (newRecord.end.compareTo(latest.end) > 0) {
                latest = newRecord;
            }
        }
        System.out.println(earliest.id + " " + latest.id);
    }
}