import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.text.ParseException;
import java.text.SimpleDateFormat;
import java.util.Calendar;
import java.util.Date;
import java.util.LinkedList;

public class Main {
    static class Bank {
        final static int WorkingTime = 9 * 60;
        static final SimpleDateFormat format = new SimpleDateFormat("HH:mm");
        static Date TimeStart;

        static {
            try {
                TimeStart = format.parse("08:00");
            } catch (ParseException e) {
                e.printStackTrace();
            }
        }

        final int window_quantity, window_limit, customer_quantity;
        //客户查询索引
        final int[] customer_index;
        //排队客户 id list
        final LinkedList<Integer>[] queues;

        Bank(int window_quantity, int window_limit, int customer_quantity) {
            this.window_quantity = window_quantity;
            this.window_limit = window_limit;
            this.customer_quantity = customer_quantity;
            this.customer_index = new int[customer_quantity + 1];
            queues = new LinkedList[window_quantity];
            for (int i = 0; i < queues.length; i++) {
                queues[i] = new LinkedList<>();
            }
        }

        /**
         * 根据customer id 获取排队时间
         */
        String index(String id) {
            int idi = Integer.valueOf(id);
            int time_offset = this.customer_index[idi];
            if (time_offset == 0) {
                return "Sorry";
            }
            Calendar instance = Calendar.getInstance();
            instance.setTime(TimeStart);
            instance.add(Calendar.MINUTE, time_offset);
            return format.format(instance.getTime());
        }

        //计算时间
        void calculate(String[] customer_cost_array) {
            //每个队列的时间片
            int[] window_time_offset = new int[window_quantity];

            for (int index = 0;
                 index < customer_quantity;
                 index++) {
                int customer_id = index + 1;
                int customer_cost_time = Integer.valueOf(customer_cost_array[index]);

                int window_index = -1;
                //容量之内,按顺序放
                if (index < window_quantity * window_limit) {
                    window_index = index % window_quantity;
                } else { //容量之外,排在等待时间最小的
                    //求队头最小值,并出队
                    int min_customer_cost = Integer.MAX_VALUE;
                    for (int i = 0; i < window_quantity; i++) {
                        Integer cost = queues[i].peekFirst();
                        if (cost != null && cost < min_customer_cost) {
                            min_customer_cost = cost;
                            window_index = i;
                        }
                    }
                    queues[window_index].removeFirst();
                }
                //能排上队的,记一下时间
                if (window_time_offset[window_index] < WorkingTime) {
                    window_time_offset[window_index] = window_time_offset[window_index] + customer_cost_time;
                    queues[window_index].add(window_time_offset[window_index]);
                    customer_index[customer_id] = window_time_offset[window_index];
                }
            }
        }
    }

    public static void main(String[] args) throws IOException {
        BufferedReader reader = new BufferedReader(new InputStreamReader(System.in));
        String[] split = reader.readLine().split(" ");
        Bank bank = new Bank(Integer.valueOf(split[0]), Integer.valueOf(split[1]), Integer.valueOf(split[2]));
        String[] line = reader.readLine().split(" ");
        bank.calculate(line);
        for (String id : reader.readLine().split(" ")) {
            System.out.println(bank.index(id));
        }
    }
}