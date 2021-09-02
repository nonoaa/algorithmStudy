//https://programmers.co.kr/learn/courses/30/lessons/64062

public class Bridge {
    public static void main(String[] args) {
        System.out.println(new Solution2().solution(new int[]{2, 4, 5, 3, 2, 1, 4, 2, 5, 1}, 3));
    }
}

class Solution2 {
    int answer = 0;

    public int solution(int[] stones, int k) {
        int cnt = 0;

        for (int i = 0; i < stones.length; i++) {
            if (stones[i] > 0) {
                cnt = 0;
                stones[i]--;
            } else if (stones[i] == 0) {
                cnt++;
                if (cnt >= k) {
                    break;
                }
            }
            if (i == stones.length - 1) {
                answer++;
                solution(stones, k);
            }

        }

        return answer;
    }
}