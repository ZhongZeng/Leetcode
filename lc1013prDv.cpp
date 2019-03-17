/*
1013. Pairs of Songs With Total Durations Divisible by 60

Test Cases:
[30,20,150,100,40]
[60,60,60]
[15,63,451,213,37,209,343,319]

Companies	Goldman Sachs 
Related Topics	Array 

Runtime: 40 ms
Memory Usage: 11.8 MB

*/

class Solution {
public:
    int numPairsDivisibleBy60(vector<int>& time) {
        // hash table, math; O(60+N) time 
        int r, sum=0;
        unordered_map<int,int> um;
        unordered_map<int,int>::iterator umi, umj;
        
        for( int i=0; i<time.size(); i++){
            r=time[i]%60;
            umi=um.find(r);
            if(umi!=um.end())   umi->second+=1;
            else    um.emplace(r,1);
        }
        
        for( umi=um.begin(); umi!=um.end(); umi++){
            if(umi->first==0||umi->first==30){
                sum+=(umi->second)*(umi->second-1);// corner case 30, 60
            }else{
                umj=um.find(60-umi->first);
                if(umj!=um.end())  sum+=(umi->second)*(umj->second);
            }
        }
        
        return sum/2;
    }
};