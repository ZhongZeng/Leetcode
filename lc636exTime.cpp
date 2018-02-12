
/*

Leetcode 636. Exclusive Time of Functions

Related Topics 
Stack 

Test Case:
2
["0:start:0","1:start:2","1:end:5","0:end:6"]

Runtime: 24 ms
Your runtime beats 91.13 % of cpp submissions. 

*/

class Solution {
public:
    vector<int> exclusiveTime(int n, vector<string>& logs){
        stack<int> ids, tms;
        vector<int> rt(n,0);
        int id, tm, i, j;
        bool st;
            
        for(i=0; i<logs.size(); i++){
            for( j=0, id=0; logs[i][j]!=':'; j++)   id=id*10+logs[i][j]-'0';
            
            st=logs[i][++j]!='e'?true:false;
            while( logs[i][j++]!=':' ){}
            
            for( tm=0; j<logs[i].size(); j++)   tm=tm*10+logs[i][j]-'0';
            
            if(st){
                if(!ids.empty()) rt[ids.top()]+=tm-tms.top();
                ids.push(id);
                tms.push(tm);
            }else{
                rt[ids.top()]+=tm+1-tms.top();
                ids.pop();
                tms.pop();
                if(!tms.empty())    tms.top()=tm+1;
            }
            //for(auto e:rt)  cout<<e<<" ";   cout<<endl;
        }
        
        return rt;
    }
};