#define L(i,s,e) for(int i=0;i<=e;i++)
class Solution {
public:
    string convert(string s, int numRows) {
        if(numRows==1)
        return s;
        int gap=(numRows-1)*2,ttl=(numRows-1)*2;
        string ans;
        for(int i=1;i<=numRows;i++){
            int in=i-1,rem=gap,l_in=-1;
            while(in<s.size()){
                if(in!=l_in)
                ans+=s[in];
                l_in=in;
                in+=rem;
                rem=ttl-rem;
                //cout<<ans<<endl;
            }
            gap-=2;
            if(gap==0)
            gap=ttl;
        }
        return ans;
    }
};
