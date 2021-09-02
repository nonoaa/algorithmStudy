// https://programmers.co.kr/learn/courses/30/lessons/42883

class BigNumber {
    public String solution(String number, int k) {
        StringBuilder sb = new StringBuilder(number);
        int len = sb.length();
        boolean check = false;
        for (int i = 0; i < k; i++) {
            for(int j = 0; j < len-1; j++) {
                if(sb.charAt(j)<sb.charAt(j+1)) {
                    sb.deleteCharAt(j);
                    len = sb.length();
                    check = true;
                    break;
                }
            }
            if(check == false){
                sb.delete(len-k, len);
                break;
            }
        }
        return sb.toString();
    }
}
