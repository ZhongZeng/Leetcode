
/*
Leetcode 552. Student Attendance Record II

Companies 
Google 
Related Topics 
Dynamic Programming
Similar Questions 
Student Attendance Record I

Next challenges: Split Array Largest Sum, Sentence Screen Fitting, Remove Boxes

Test Cases:
1
2
3
5
40000

Runtime: 30 ms
Your runtime beats 86.51 % of cpp submissions.

*/

class Solution {
public:
    int checkRecord(int n) {
        if(n<1) return 0;
        else if(n<2)    return 3;
        else if(n<3)    return 8;
        
        vector<int> va={1,3,8}, vb={1,2,4}, va1(5,0), vb1(3,0);
        // 1A: LL, P/A L, *P/A; 0A: LL, PL, *P
        
        for( int i=3; i<n; i++){
            dp(va1, vb1, va, vb);
            if(n-1<++i) return rt(va1, vb1);
            dp(va, vb, va1, vb1);
        }
        
        return rt(va, vb);
    }
    
    int rt(vector<int>& va, vector<int>& vb){
        int r=0;
        for(int i=0; i<3; i++)  r=(r+va[i])%1000000007;
        for(int i=0; i<3; i++)  r=(r+vb[i])%1000000007;
        return r;
    }
    
    void dp(vector<int>& va1, vector<int>& vb1, vector<int>& va, vector<int>& vb){
        // A: LL, P/A L, *P/A; 0A: LL, PL, *P; A breaks L!
        vb1[0]=vb[1];
        vb1[1]=vb[2];
        vb1[2]=((vb[0]+vb[1])%1000000007+vb[2])%1000000007;
        va1[0]=va[1];// LL
        va1[1]=va[2];// P/A L
        va1[2]=(((vb1[2]+va[0])%1000000007+va[1])%1000000007+va[2])%1000000007;// *A/P
        //for(auto e:va1)   cout<<e<<" ";   cout<<endl;
        return ;
    }
};
