

class Solution {
public:
    int trailingZeroes(int n) {
        int cnt=0;
        while(n/5>0){
            cnt=cnt+n/5;
            n=n/5;
        }

        return cnt;
    }
};