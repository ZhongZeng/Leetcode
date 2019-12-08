/*
1128. Number of Equivalent Domino Pairs

Tag:	Hash Table (suggest)

Ranking of Weekly Contest 146  
Rank	Name	Score	Finish Time 	Q1 (3)	Q2 (5)	Q3 (6)	Q4 (7)
1144 / 5074	zhongzeng 	8	1:27:46	 0:11:17	 1:27:46		

Test Cases:
[[1,2],[2,1],[3,4],[5,6]]

Runtime: 40 ms
Memory Usage: 21.3 MB
*/

class Solution {
public:
    int numEquivDominoPairs(vector<vector<int>>& dominoes) {
        // hash table
        int pr=0, a, b;
        unordered_map<int,unordered_map<int,int>> um;
        unordered_map<int,unordered_map<int,int>>::iterator umi;
        unordered_map<int,int>::iterator ui;
        
        for( int i=0; i<dominoes.size(); i++){
            if(dominoes[i][0]<dominoes[i][1]){
                a=dominoes[i][0];
                b=dominoes[i][1];
            }else{
                a=dominoes[i][1];
                b=dominoes[i][0];
            }
            umi=um.find(a);
            if(umi!=um.end()){
                ui=umi->second.find(b);
                if(ui!=umi->second.end())   ui->second+=1;
                else    umi->second.emplace(b,1);
            }else{
                unordered_map<int,int> us;
                us.emplace(b,1);
                um.emplace(a,us);
            }
        }
        
        for( umi=um.begin(); umi!=um.end(); umi++){
            for( ui=umi->second.begin(); ui!=umi->second.end(); ui++){
                pr+=ui->second*(ui->second-1)/2;
            }
        }
        
        return pr;
    }
};