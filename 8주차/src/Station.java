//https://programmers.co.kr/learn/courses/30/lessons/12979

public class Station {
    public static void main(String[] args) {
        System.out.println(new Solution3().solution(4, new int[]{4, 11}, 1));
    }
}

class Solution3 {
    public int solution(int n, int[] stations, int w) {
        int answer = 0;
        int remain = 0;
        int temp = 1; // 가장 마지막에 전파가 안닿아있는 범위

        for(int i = 0; i< stations.length; i++){
            if(stations[i] - w > temp){ //새로운 기지국이 이전범위에 포함되어있지 않으면
                remain= stations[i] - w - temp;
                temp = stations[i] + w + 1;
            }
            else{
                remain = 0;
                temp = stations[i] + w + 1;
            }
            answer += remain / (2*w+1);
            if(remain % (2*w+1) != 0){
                answer++;
            }
        }
        if(stations[stations.length-1] + w < n){ // 마지막부분이 있으면
            int last =  n - temp + 1;
            answer += last /(2*w+1);
            if(last % (2*w+1) != 0){
                answer++;
            }
        }

        return answer;
    }
}