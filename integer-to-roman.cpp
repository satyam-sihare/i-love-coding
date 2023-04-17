#include<bits/stdc++.h>
using namespace std;
class Solution {
    string roman[3][3]={{"I","V","X"},{"X","L","C"},{"C","D","M"}};
    string fun(int place,int digit){
        string res="";
        if(place==4){
            for(int i=0;i<digit;i++)
            res+="M";
        }
        else{
            if(digit==9)
                res+=roman[place-1][0]+roman[place-1][2];
            else if(digit>=5){
                res+=roman[place-1][1];
                for(int i=6;i<=digit;i++)
                res+=roman[place-1][0];
            }
            else if(digit==4)
                res+=roman[place-1][0]+roman[place-1][1];
            else{
                for(int i=0;i<digit;i++)
                res+=roman[place-1][0];
            }
        }
        return res;
    }
public:
    string itoro(string s1){
        int sz=s1.size(),place;
        place=sz;
        string res="";
        for(int i=0;i<sz;i++){
            res+=fun(place,s1[i]-'0');
            place--;
        }
        return res;
    }
};
int main(){
    Solution s1;
    string ans=s1.itoro("3");
    cout<<ans<<endl;
}