package p1141to1150;
import java.util.Scanner;

/**
 * checkpoint 4 time out
 * 1147 Heaps（30 point(s)）
 */
public class Heaps {
    private static final String[] TYPES=new String[]{"Min Heap","Not Heap","Max Heap"};

    /**
     * postorder travel
     * @param heap heap
     * @param index start index
     */
    private static void travel(int[] heap,int index){
        if(index>=heap.length){
            return;
        }
        int left=index<<1;
        int right=left+1;
        travel(heap,left);
        travel(heap,right);
        System.out.printf("%d%s",heap[index],index==1?"\n":" ");
    }

    /**
     * 判断堆的类型
     * @param heap heap
     * @return -1 min ;0 not ;1 max
     */
    private static int type(int[] heap){
        int index = 2;
        int type = 0;
        final int length=heap.length;
        out:while (index < length) {
            for (int i = index; i<length&&i < (index << 1); i++) {
                int diff =( heap[i/2] - heap[i])>0?1:-1;
                if(type==0){
                    type=diff;
                }else {
                    if(type*diff<0){
                        type=0;
                        break out;
                    }
                }
            }
            index = index << 1;
        }
        return type;
    }
    private static void checkAndSet(final int[] heap) {
        int type = type(heap);
        System.out.println(TYPES[type+1]);
        travel(heap,1);
    }

    /**
     * checkpoint 4 time out
     * 1147 Heaps（30 point(s)）
     */
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        String[] split=scanner.nextLine().split(" ");
        final int counts = Integer.valueOf(split[0]);
        final int length = Integer.valueOf(split[1]);
        for (int i = 0; i < counts; i++) {
            int[] ints=new int[length+1];
            for (int j = 0; j < length; j++) {
                ints[j+1]=scanner.nextInt();
            }
            checkAndSet(ints);
        }
    }
}
