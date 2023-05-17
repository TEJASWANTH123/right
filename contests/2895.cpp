class Solution {
public:
    int minProcessingTime(vector<int>& processorTime, vector<int>& tasks) {
        sort(processorTime.begin(),processorTime.end());sort(tasks.begin(),tasks.end());int mx=0;int j=0;
        for(int i=tasks.size()-1;i>0;i-=4){
            mx=max(tasks[i]+processorTime[j],mx);j++;
        }
        return mx;
    }
};