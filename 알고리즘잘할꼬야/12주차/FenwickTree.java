import java.util.Scanner;

public class FenwickTree {
    static long[] arr = new long[1000001];
    static long[] tree = new long[1000001];
    static long[] res = new long[1000001];
    public static void main(String[] args) {
        int n, m, k;
        Scanner sc = new Scanner(System.in);
        n = sc.nextInt();
        m = sc.nextInt();
        k = sc.nextInt();
        int cnt = 0;


        for(int i = 1; i <= n; i++){
            arr[i] = sc.nextLong();
            update(i, arr[i], n);
        }

        for(int i = 0; i < m + k; i++){
            long x;
            x = sc.nextLong();
            if(x == 1){
                int y = sc.nextInt();
                long z = sc.nextLong();
                update(y, z-arr[y], n);
                arr[y] = z;
            }
            else{
                int y = sc.nextInt();
                int z = sc.nextInt();
                res[cnt] = (sum(z) - sum(y-1));
                cnt++;
            }
        }
        for(int i = 0; i< k; i++){
            System.out.println(res[i]);
        }
    }
    static void update(int index, long value, int n){
        while(index <= n){
            tree[index] += value;
            index += (index & -index);
        }
    };
    static long sum(int index){
        long res = 0;
        while(index>0){
            res += tree[index];
            index -= (index & -index);
        }
        return res;
    }
}
