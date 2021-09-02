//https://programmers.co.kr/learn/courses/30/lessons/43163

public class Words {
    public static void main(String[] args) {
        System.out.println(new Solution4().solution("hit", "cog", new String[]{"hot","dot","dog","lot","log","cog"}));
    }
}

class Solution4 {

    int answer = 0;
    public int solution(String begin, String target, String[] words) {

        String last = begin; // 이전 문자열

        change(last, target, words, 0);

        return answer;
    }
    public void change(String last, String target, String[] words, int cnt){
        if(answerCheck(last, target)){
            if(answer==0 || cnt < answer){
                answer = cnt;
            }
            return;
        }
        if(words.length == 0)
            return;

        String[] deleted = new String[words.length-1];
        for (int i = 0; i < words.length; i++){
            String current = words[i];

            if(check(last, current)){
                System.arraycopy(words, 0, deleted, 0, i);
                System.arraycopy(words, i+1, deleted, i, words.length-i-1);

                change(current, target, deleted, cnt+1);
            }

        }
    }
    public boolean answerCheck(String begin, String target){
        if(begin.equals(target)){
            return true;
        }
        return false;
    }
    public boolean check(String begin, String target){
            int cnt = 0;
            for(int i = 0; i < begin.length(); i++){
                if(begin.charAt(i) == target.charAt(i)){
                    cnt++;
                }
            }
            if(cnt + 1 == begin.length()){
                return true;
            }

        return false;
    }
}