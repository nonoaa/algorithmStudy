
public class N_Queen {
    public static void main(String[] args) {
        System.out.println(new Solution().solution(4));
    }
}

class Solution {
    int[] matrix = new int[12];
    int answer = 0;
    public int solution(int n) {
        put(0,n);
        return answer;
    }
    void put(int index, int n){
        if(index == n){
            answer ++;
        }
        else{
            for(int i =0; i < n; i++){
                matrix[index] = i;
                if(find(index)){
                    put(index+1, n);
                }
            }
        }

    }
    boolean find(int index){
        for(int i =0; i<index; i++){
            if(matrix[i] == matrix[index] || Math.abs(index - i) == Math.abs(matrix[index] - matrix[i])){
                return false;
            }
        }
        return true;
    }
}
//
//class Solution {
//    int state = 0; // 0일때 0개 배치완료(start), n일때 n개 배치완료(end)
//    int answer = 0;
//    int cnt = 0;
//    public int solution(int n) {
//        int[][] matrix = new int[n][n];
//
//        matrix = put(matrix,0, 0);
//        System.out.println("cnt: "+cnt);
//        return answer;
//    }
//
//    public int[][] put(int matrix[][], int x, int y) {
//        int xIndex=0, yIndex=0;
//        for (int i = x; i < matrix[0].length; i++) {
//            for (int j = y; j < matrix[0].length; j++) {
//                if (find(matrix, i, j)) {
//                    matrix[i][j] = 1;
//                    state++;
//                    matrix = put(matrix, x, y);
//                }
//            }
//        }
//        for (int i = 0; i< matrix.length; i++) {
//            System.out.println(Arrays.toString(matrix[i]));
//        }
//        System.out.println();
//
//        if (state == matrix[0].length) {
//            for (int i = 0; i < matrix.length; i++) {
//                Arrays.fill(matrix[i], 0);
//            }
//            answer++;
//            state = 0;
//        }
//        else{
//
//                Arrays.fill(matrix[state], 0);
//                state--;
//        }
//        System.out.println("state: " + state);
//        System.out.println("answer: "+ answer);
//        cnt++;
//        return matrix;
//    }
//
//    public boolean find(int matrix[][], int x, int y) {
//        for (int i = 0; i < matrix[0].length; i++) {
//            if (matrix[x][i] == 1) { //y축 검사
//                return false;
//            } else if (matrix[i][y] == 1) { //x축 검사
//                return false;
//            }
//            for (int j = 0; j < matrix[0].length; j++) { //대각선 검사
//                if ((Math.abs(i - x) == Math.abs(j - y)) && (matrix[i][j] == 1)) {
//                    return false;
//                }
//            }
//        }
//        return true;
//    }
//
//}