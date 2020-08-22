class BigNumber {
    public String BigNumber(String number, int k) {
        String answer = "";
        String made = number;

        for (int i = 0; i < k; i++) {
            for(int j = 0; j < made.length()-1; j++) {
                if(made.charAt(j)<made.charAt(j+1)) {
                    made = made.substring(0,j) + made.substring(j+1);
                    break;
                }
                if(j == made.length()-2) {
                    made = made.substring(0, made.length()-1);
                }
            }
        }

        
        answer = made;
        return answer;
    }
}
