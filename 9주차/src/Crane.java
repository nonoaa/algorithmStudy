// https://programmers.co.kr/learn/courses/30/lessons/64061

import java.util.Stack;

public class Crane {
    public static void main(String[] args) {
    }
}

class Solution {
    public int solution(int[][] board, int[] moves) {
        int answer = 0;
        int [] top = new int[board.length]; // 현재 맨위에 있는 인형들
        int [] topIndex = new int[board.length]; //현재 맨위에 있는 인형들의 Index
        Stack<Integer> box = new Stack<>(); //인형담는 바구니

        for(int i = 0; i<board.length; i++){
            for (int j = 0; j<board.length; j++){
                if(board[j][i]!=0){
                    top[i] = board[j][i];
                    topIndex[i] = j;
                    break;
                }
            }
        }

        box.push(top[moves[0]-1]);
        topIndex[moves[0]-1]++;
        if(topIndex[moves[0]-1] >= board.length){
            top[moves[0]-1] = 0;
        }
        else{
            top[moves[0]-1] = board[topIndex[moves[0]-1]][moves[0]-1];
        }

        for(int i = 1; i<moves.length; i++){
            if(box.size() != 0){ //바구니에 하나라도 담겨있으면
                if(box.peek() == top[moves[i]-1]){ // 박스 맨위의 인형과 담으려는 인형이 같으면
                    box.pop();
                    answer+=2;
                    // board의 맨위에있는 인형 정보 갱신
                    topIndex[moves[i]-1]++;
                    if(topIndex[moves[i]-1] >= board.length){
                        top[moves[i]-1] = 0;
                    }
                    else{
                        top[moves[i]-1] = board[topIndex[moves[i]-1]][moves[i]-1];
                    }
                    // board의 맨위에있는 인형 정보 갱신
                }
                else if (top[moves[i]-1] != 0){
                    box.push(top[moves[i]-1]);

                    // board의 맨위에있는 인형 정보 갱신
                    topIndex[moves[i]-1]++;
                    if(topIndex[moves[i]-1] >= board.length){
                        top[moves[i]-1] = 0;
                    }
                    else{
                        top[moves[i]-1] = board[topIndex[moves[i]-1]][moves[i]-1];
                    }
                    // board의 맨위에있는 인형 정보 갱신
                }
            }
            else if (top[moves[i]-1] != 0){ //바구니에 아무것도 담겨있지않고 담을 수 있는 인형이있으면
                box.push(top[moves[i]-1]);

                // board의 맨위에있는 인형 정보 갱신
                topIndex[moves[i]-1]++;
                if(topIndex[moves[i]-1] >= board.length){
                    top[moves[i]-1] = 0;
                }
                else{
                    top[moves[i]-1] = board[topIndex[moves[i]-1]][moves[i]-1];
                }
                // board의 맨위에있는 인형 정보 갱신
            }
        }


        return answer;
    }
}
