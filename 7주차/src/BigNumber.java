// https://programmers.co.kr/learn/courses/30/lessons/42883

class BigNumber {
    public String solution(String number, int k) {
        StringBuilder sb = new StringBuilder(number);
        int len = sb.length();

        for (int i = 0; i < k; i++) {
            for(int j = 0; j < len-1; j++) {
                if(sb.charAt(j)<sb.charAt(j+1)) {
                    sb.deleteCharAt(j);
                    len = sb.length();
                    break;
                }
                if(j == len-2) {
                    sb.deleteCharAt(len-1);
                    len = sb.length();
                }
            }
        }
        return sb.toString();
    }
}
