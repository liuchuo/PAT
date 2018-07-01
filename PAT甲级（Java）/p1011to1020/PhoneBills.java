package p1011to1020;


import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.text.SimpleDateFormat;
import java.util.*;

/**
 * 1016 Phone Bills (25)（25 分）
 */
public class PhoneBills {
    static class Record implements Comparable<Record> {
        static SimpleDateFormat outFormat = new SimpleDateFormat("dd:HH:mm");
        String name;
        Date date;
        // true on-line/false off-line
        boolean status;

        Record(String name, Date data, boolean status) {
            this.name = name;
            this.date = data;
            this.status = status;
        }

        @Override
        public int compareTo(Record o) {
            int compare = name.compareTo(o.name);
            if (compare == 0) {
                return date.compareTo(o.date);
            } else {
                return compare;
            }
        }

        @Override
        public String toString() {
            return outFormat.format(date);
        }
    }

    static class BillManager {

        static class Bill {
            int minute;
            int cost;
            String start;
            String end;
            int month;

            public Bill(int minute, int cost, String start, String end, int month) {
                this.minute = minute;
                this.cost = cost;
                this.start = start;
                this.end = end;
                this.month = month;
            }
        }

        int[] bills_for_hour = new int[24];
        Map<String, List<Bill>> billMap = new TreeMap<>();

        BillManager(String[] bills_for_hour) {
            for (int i = 0; i < bills_for_hour.length; i++) {
                int s = Integer.valueOf(bills_for_hour[i]);
                this.bills_for_hour[i] = s;
            }
        }

        static final Calendar CALENDAR = Calendar.getInstance();

        void recordBill(Record recordFirst, Record recordEnd) {
            Date start=recordFirst.date;
            Date end=recordEnd.date;
            String name=recordEnd.name;
            int month=start.getMonth()+1;
            int[] calls_per_hour = new int[24];
            CALENDAR.setTime(end);
            while (CALENDAR.getTime().compareTo(start) > 0) {
                int minute = CALENDAR.get(Calendar.MINUTE);
                int hour = CALENDAR.get(Calendar.HOUR_OF_DAY);
                if (minute == 0) {
                    //回退一小时
                    CALENDAR.add(Calendar.HOUR_OF_DAY, -1);
                    hour = CALENDAR.get(Calendar.HOUR_OF_DAY);
                    calls_per_hour[hour] = calls_per_hour[hour] + 60;
                } else {
                    calls_per_hour[hour] = minute;
                    CALENDAR.set(Calendar.MINUTE, 0);
                }
            }
            if (CALENDAR.getTime().compareTo(start) < 0) {
                int hours = start.getHours();
                int minutes = start.getMinutes();
                calls_per_hour[hours] = calls_per_hour[hours] - minutes;
            }
            int sum = 0;
            int total_minute = 0;
            for (int i = 0; i < calls_per_hour.length; i++) {
                int minute = calls_per_hour[i];
                if (minute != 0) {
                    sum = sum + minute * bills_for_hour[i];
                    total_minute += minute;
                }
            }
            List<Bill> bills = billMap.computeIfAbsent(name, k -> new LinkedList<>());
            bills.add(new Bill(total_minute,
                    sum,
                    recordFirst.toString(),
                    recordEnd.toString(),
                    month));
        }
    }

    public static void main(String[] args) throws Exception {
        BufferedReader reader = new BufferedReader(new InputStreamReader(System.in));
        SimpleDateFormat format = new SimpleDateFormat("MM:dd:HH:mm");
        BillManager manager = new BillManager(reader.readLine().split(" "));

        TreeSet<Record> records = new TreeSet<>();
        int record_counts = Integer.valueOf(reader.readLine());
        //read record
        for (int i = 0; i < record_counts; i++) {
            String[] split = reader.readLine().split(" ");
            String name = split[0];
            Date parse = format.parse(split[1]);
            boolean status = split[2].equals("on-line");
            Record record = new Record(name, parse, status);
            records.add(record);
        }
        Record last = null;
        for (Record r : records) {
            if (last != null && r.name.equals(last.name) && last.status && !r.status) {
                manager.recordBill(last,r);
                last = null;
            } else {
                last = r;
            }
        }
        manager.billMap.forEach((k, v) -> {
            int month=v.get(0).month;
            System.out.printf("%s %02d\n",k,month);
            int sum = 0;
            for (BillManager.Bill bill : v) {
                System.out.printf("%s %s %d $%.2f\n",bill.start,bill.end,bill.minute,bill.cost/100.0);
                sum += bill.cost;
            }
            System.out.printf("Total amount: $%.2f\n",sum/100.0);

        });
    }
}
