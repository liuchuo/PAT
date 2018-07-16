package p1021to1030;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.time.LocalTime;
import java.time.format.DateTimeFormatter;
import java.util.Arrays;
import java.util.Comparator;
import java.util.Iterator;
import java.util.TreeSet;

/**
 * 1026 Table Tennis (30)（30 分）

 * point 3 error
 * point 8 time out
 */
public class TableTennis {
    interface Marking {
        int getTime();
        boolean isVip();
    }
    static class Table implements Comparable<Table>,Marking {
        static int START = LocalTime.parse("08:00:00").toSecondOfDay();
        static int END = LocalTime.parse("21:00:00").toSecondOfDay();
        int id;
        int time;
        int serves;
        boolean vip;

        Table(int id) {
            this.id = id;
            this.time = START;
        }

        @Override
        public int compareTo(Table o) {
            int compare = time - o.time;
            return compare == 0 ? id - o.id : compare;
        }

        Table update(Pair pair) {
            time = Math.max(time,pair.getTime()) + pair.tookTime;
            serves++;
            return this;
        }

        @Override
        public int getTime() {
            return time;
        }

        @Override
        public String toString() {
            return "Table{" +
                    "id=" + id +
                    ", time=" + LocalTime.ofSecondOfDay(time) +
                    ", serves=" + serves +
                    ", vip=" + vip +
                    '}';
        }

        @Override
        public boolean isVip() {
            return vip;

        }
    }

    static class Pair implements Comparable<Pair>,Marking {
        int arriveTime;
        int tookTime;
        int serveTime;
        int waitingTime;
        boolean vip;

        Pair(int arriveTime, int tookTime, boolean vip) {
            this.arriveTime = arriveTime;
            this.tookTime = tookTime;
            this.vip = vip;
            this.serveTime = arriveTime;
            this.waitingTime = 0;
        }

        @Override
        public int compareTo( Pair o) {
            return arriveTime - o.arriveTime;
        }

        void update(final Table table){
            waitingTime = table.time - arriveTime;
            serveTime = table.time;
        }
        @Override
        public int getTime() {
            return arriveTime;
        }

        @Override
        public boolean isVip() {
            return vip;
        }
    }
    /**
     * 1026 Table Tennis (30)（30 分）

     * point 3 error
     * point 8 time out
     */
    public static void main(String[] args) throws IOException {
        BufferedReader bReader = new BufferedReader(new InputStreamReader(System.in));
        Integer pairCounts = Integer.valueOf(bReader.readLine());
        TreeSet<Pair> pairs = new TreeSet<>();
        TreeSet<Table> tables = new TreeSet<>();
        // prepare data
        for (int i = 0; i < pairCounts; i++) {
            String[] split = bReader.readLine().split(" ");
            LocalTime parse = LocalTime.parse(split[0]);
            int tookTime = Integer.valueOf(split[1]);
            boolean vip = split[2].equals("1");
            Pair pair = new Pair(parse.toSecondOfDay(),
                    tookTime > 120 ? 120 * 60 : tookTime * 60,
                    vip);
            pairs.add(pair);
        }
        String[] split = bReader.readLine().split(" ");
        Integer tableCounts = Integer.valueOf(split[0]);
        int vipCounts=Integer.valueOf(split[1]);
        if(vipCounts>0){
            String[] vips = bReader.readLine().split(" ");
            for (String vip : vips) {
                Integer id = Integer.valueOf(vip);
                Table table = new Table(id);
                table.vip = true;
                tables.add(table);
            }
        }
        for (int i = 1; i <= tableCounts; i++) {
            Table table = new Table(i);
            tables.add(table);
        }
        //serve
        while (pairs.size() > 0) {
            Table firstTable = tables.first();
            //超时,不提供服务了
            if (firstTable.time >= Table.END) {
                break;
            }
            Pair firstPair = pairs.first();
            Pair pair;
            //无等待,多桌抢人
            if (firstTable.time <= firstPair.arriveTime) {
                pair = pairs.pollFirst();
                Table table = fitTable(tables, firstPair);
                tables.add(table.update(pair));
            }
            //有等待,多人抢桌
            else {
                Table table = tables.pollFirst();
                pair = fitPair(pairs, firstTable);
                pair.update(table);
                tables.add(table.update(pair));
            }
            outPutPair(pair);
        }
        Object[] objects = tables.toArray();
        Arrays.sort(objects, Comparator.comparingInt(o -> ((Table) o).id));
        for (int i = 0; i < objects.length; i++) {
            Table table = (Table) objects[i];
            System.out.printf("%d%s", table.serves, i == objects.length - 1 ? "\n" : " ");
        }
    }

    private static void outPutPair(Pair pair) {
        String arriveTime = LocalTime.ofSecondOfDay(pair.arriveTime).format(DateTimeFormatter.ISO_TIME);
        String serveTime = LocalTime.ofSecondOfDay(pair.serveTime).format(DateTimeFormatter.ISO_TIME);

        System.out.printf("%s %s %.0f\n",
                arriveTime,
                serveTime,
                pair.waitingTime / 60.0);
    }

    private  static<T extends Marking,O extends Marking> T finOne(TreeSet<T> many, O one){
        int time = one.getTime();
        if (one.isVip()) {
            Iterator<T> iterator = many.iterator();
            while (iterator.hasNext()) {
                T next = iterator.next();
                if (next.getTime() > time) {
                    break;
                }
                if (next.isVip()) {
                    iterator.remove();
                    return next;
                }
            }
        }

        return many.pollFirst();
    }
    private static Table fitTable(TreeSet<Table> tables, Pair pair) {
        return finOne(tables, pair);
    }
    private static Pair fitPair(TreeSet<Pair> pairs, Table table) {
        return finOne(pairs, table);
    }
}

