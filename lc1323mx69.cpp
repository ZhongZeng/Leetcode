/*
1323. Maximum 69 Number

Ranking of Weekly Contest 172 
Rank	Name	Score	Finish Time 	Q1 (3)	Q2 (4)	Q3 (5)	Q4 (6)
2806 / 6604	zhongzeng 	12	1:21:45	 0:04:03	 0:35:52	 1:16:45  1	

Company	HRT
Related Topics	Math

Test Cases:
9669
9996
9999

Runtime: 0 ms
Memory Usage: 8.3 MB
*/ 

class Solution {
public:
    int maximum69Number (int num) {
        // O(m) time&space
        int rt=0;
        vector<int> vc;
        for( int i=num; 0<i; i=i/10)    vc.push_back(i%10);
        for( int i=vc.size()-1; -1<i; i--){
            if(vc[i]==6){
                vc[i]=9;
                break;
            }
        }
        for( int i=vc.size()-1; -1<i; i--)  rt=rt*10+vc[i];
        return rt;
    }
};