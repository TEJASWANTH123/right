class Solution {
public:
    int edgeScore(vector<int>& edges) {
     map<int,int> mp;int m=INT_MIN;int z=INT_MAX;
     for(int i=0;i<edges.size();i++){
         mp[edges[i]]+=i;
         if(m<mp[edges[i]]){
m=max(m,mp[edges[i]]);
 z=edges[i];    }
 else if(m==mp[edges[i]])
    z=min(edges[i],z);
    }
 
return z;

    }
};
//
class Solution {
public:
    int edgeScore(vector<int>& edges) {
        int n = edges.size(),i;
        vector<vector<int>> v(n);
        for(i = 0; i < n; i++){
            v[edges[i]].push_back(i);
        }
        long long int ans=0,sum=0,k=0;
        for(i=0;i<n;i++){
            sum = 0;
            for(auto &j: v[i])sum += j;
            if(sum>k){
                k = sum;
                ans = i;
            }
        }
        return ans;
    }
};```
