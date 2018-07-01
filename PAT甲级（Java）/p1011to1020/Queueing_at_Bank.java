package p1011to1020;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.text.DateFormat;
import java.text.ParseException;
import java.text.SimpleDateFormat;
import java.util.Iterator;
import java.util.PriorityQueue;
import java.util.TreeSet;

/**
 * 1017 Queueing at Bank (25)（25 分）
 */
public class Queueing_at_Bank {
    public static class Record implements Comparable<Record> {
        static final DateFormat format = new SimpleDateFormat("HH:mm:ss");
        static long START_TIME;
        static long MAX_OFFSET;

        static {
            try {
                START_TIME = format.parse("8:00:00").getTime();
                MAX_OFFSET = format.parse("17:00:00").getTime() - START_TIME;
            } catch (ParseException e) {
                e.printStackTrace();
            }
        }

        long offset;
        int cost;

        Record(String start, int cost) throws Exception {
            this.offset = format.parse(start).getTime() - START_TIME;
            if (this.offset > MAX_OFFSET) {
                throw new Exception();
            }
            this.cost = cost * 60 * 1000;
        }

        @Override
        public int compareTo(Record o) {
            return (int) (this.offset - o.offset);
        }
    }
    /**
     * 1017 Queueing at Bank (25)（25 分）
     * check point 5 over time
     */
    public static void main(String[] args) throws IOException, ParseException {
        BufferedReader reader = new BufferedReader(new InputStreamReader(System.in));
        String[] split = reader.readLine().split(" ");
        final int total_customer_number = Integer.valueOf(split[0]);
        final int window_number = Integer.valueOf(split[1]);


        TreeSet<Record> records = new TreeSet<>();
        PriorityQueue<Long> window_queue = new PriorityQueue<>(window_number);
        for (int i = 0; i < window_number; i++) {
            window_queue.offer(0L);
        }
        int customer_number = 0;
        for (int i = 0; i < total_customer_number; i++) {
            String[] line = reader.readLine().split(" ");
            Record record;
            try {
                record = new Record(line[0], Integer.valueOf(line[1]));
                records.add(record);
                customer_number++;
            } catch (Exception ignored) {

            }
        }
        Iterator<Record> iterator = records.iterator();
        long sum = 0;
        while (iterator.hasNext()) {
            Record next = iterator.next();
            long poll = window_queue.poll();
            long delay = poll - next.offset;
            if (delay <= 0) {
                poll = next.offset + next.cost;
            } else {
                sum += delay;
                poll = poll + next.cost;
            }
            window_queue.offer(poll);
        }
        if(customer_number==0){
            System.out.println("0.0");
            return;
        }
        double result = sum / 1000.0/customer_number;
        int minute= (int) (result/60);
        result=minute+(result-minute*60)/60.0;
        System.out.printf("%.1f\n",result);
    }
}
