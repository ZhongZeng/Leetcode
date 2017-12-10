

/* 
Leetcode 556. Next Greater Element III

Related Topics 
String 
Similar Questions 
Next Greater Element I, Next Greater Element II 

Next challenges: Next Greater Element II

Test Cases:
12
21
72438
101
1999999999

Runtime: 3 ms
Your runtime beats 2.65 % of cpp submissions.
Runtime: 0 ms
Your runtime beats 48.24 % of cpp submissions.


*/

class Solution {
public:
    int nextGreaterElement(int n) {
        // O(n) time
        // next great element leads to this, which inspires me
        // 32-bit int max: 2,147,483,647 (2^31 − 1)
        vector<int> vc;
        stack<pair<int,int>> st;
        int rt=0, le, lm=10, loc, t;
        while(0<n){
            vc.push_back(n%10);
            n=n/10;
        }
        le=vc.size();

        for(int i=vc.size()-1; -1<i; i--){
            while(!st.empty()){
                if(st.top().first<vc[i]){
                    le=le<st.top().second?le:st.top().second;
                    st.pop();
                }else{
                    break;
                }
            }   
            st.push(make_pair(vc[i],i));
        }
        //cout<<le<<" "<<vc[le]<<endl;
        
        if(le!=vc.size()){
            for(int i=le; i!=-1 ; i--){
                if(vc[le]<vc[i]&&!(lm<vc[i])){
                    lm=vc[i];
                    loc=i;
                }
            }
            
            t=vc[le];
            vc[le]=vc[loc];
            vc[loc]=t;
                   
            sort(vc.begin(),vc.begin()+le);
            reverse(vc.begin(),vc.begin()+le);
            
            if(lgtInt(vc)){
                for(int i=vc.size()-1; i!=-1; i--)  rt=rt*10+vc[i];
                return rt;
            }else{
                return -1;
            }
        }else{ // ascending
            return -1;
        }
    }
    
    bool lgtInt(vector<int> & vc){
        // 2,147,483,647; 746,384,731,2
        vector<int> vd={7,4,6,3,8,4,7,4,1,2};
        if(vc.size()==10){
            for(int i=9; i!=-1; i--){
                //cout<<vc[i]<<" "<<vd[i]<<endl;
                if(vc[i]<vd[i]){
                    return true;
                }else if(vd[i]<vc[i]){
                    return false;
                }else{
                    continue;
                }
            }
        }
        return true;
    }
};
