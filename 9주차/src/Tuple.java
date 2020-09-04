import java.util.Arrays;

public class Tuple {
    public static void main(String[] args) {
        System.out.println(Arrays.toString(new Solution2().solution("{{4,2,3},{3},{2,3,4,1},{2,3}}")));
    }
}
class Solution2 {
    public int[] solution(String s) {
        //중괄호 제거
        String onlyNum = s.replace("{", "");
        onlyNum = onlyNum.replace("}","");
        // 콤마 단위로 나눔
        String[] splNum = onlyNum.split(",");
        int [] cnt = new int[100001];
        int [] index = new int[1000001];
        int max = 0;
        int maxIndex = 0;
        int length = 0;

        for(int i = 0; i<splNum.length; i++){
            int idx = Integer.parseInt(splNum[i]);
            if(cnt[idx] == 0){
                index[i] = idx;
                length ++;
            }
            cnt[idx]++;
        }

        int [] answer = new int[length];

        for (int i =0; i<answer.length; i++){
            for(int j = 0; j<index.length; j++){
                if(cnt[index[j]] > max){
                    max = cnt[index[j]];
                    maxIndex = index[j];
                }
            }
            answer[i] = maxIndex;
            cnt[maxIndex] = 0;
            maxIndex = 0;
            max = 0;
        }


        return answer;
    }
}