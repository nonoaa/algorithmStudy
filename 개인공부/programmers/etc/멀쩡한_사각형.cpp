//https://programmers.co.kr/learn/courses/30/lessons/62048

using namespace std;

int gcd(int l, int h)
{
    if (h % l == 0)
        return l;
    else
        return gcd(h%l, l);
}

long long solution(int w,int h) {
    long long answer = 1;
    
    if (w > h)
    {
        int temp = h;
        h = w;
        w = temp;
    }
    
    answer = (long long)w * (long long)h - (w + h - gcd(w, h)); 
    
    return answer;
}