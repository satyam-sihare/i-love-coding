#define pb push_back
class Solution {
public:
    int minMeetingRooms(vector<vector<int>>& intervals) {
        vector<int> s,e;
        for(auto itr:intervals){
            s.pb(itr[0]);
            e.pb(itr[1]);
        }
        sort(s.begin(),s.end());
        sort(e.begin(),e.end());
        int ptrs=0,ptre=0,ans=1,cnt=0;

        s.pb(INT_MAX);
        e.pb(INT_MAX);
        while(s[ptrs]!=INT_MAX || e[ptre]!=INT_MAX){
            if(s[ptrs]<e[ptre]){
                cnt++;
                ptrs++;
            }
            else{
                cnt--;
                ptre++;
            }
            ans=max(ans,cnt);
        }
        return ans;
    }
};
