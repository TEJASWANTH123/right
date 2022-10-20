class Solution {
public:
   
 long long numberOfWays(string s) {
        int n=s.size();
       long long ans=0;
       vector<long long >zero(n,0);
        vector<long long>one(n,0);
        zero[0]=s[0] == '0';
        one[0]=s[0] == '1';
      //step-1 : count the no of ones and zeros in ana prefix array
           for(int i=1; i<s.size(); i++)
        {
            zero[i] = zero[i-1] + (s[i] == '0');
            one[i] = one[i-1] + (s[i] == '1');
              
        }
        //now there are two possibilities 010 and 101
        for(int i=1;i<s.size();i++){
            //for 010 case if one then our ans will be product of 0's before 1 zero[i] * (zeros after ith index) same goes for 101 case
            //for finding no of 0's after 1 subtract last element's prefix sum-(no of zeros before this index) that is zero[n-1]-zero[i];
            if(s[i] == '1'){
               ans+=(long long)(zero[i] * (zero[n-1]-zero[i]));
            }
            else{
                ans+=(long long)(one[i] * (one[n-1]-one[i]));
            }
        }
        return ans;
         }};