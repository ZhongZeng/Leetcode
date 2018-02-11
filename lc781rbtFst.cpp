

/*
781. Rabbits in Forest

Weekly Contest 71  Feb 10, 2018

Test Cases:
[1,0,1,0,0]
[1, 1, 2]
[10, 10, 10]
[2,2,2,2,2,2,2]
[]

*/


class Solution {
public:
    int numRabbits(vector<int>& answers) {
        // math, hash_table
        int sum=0;
        unordered_map<int,int> um;
        unordered_map<int,int>::iterator umi;
        for(int i=0; i<answers.size(); i++){
            umi=um.find(answers[i]);
            if(umi!=um.end())   umi->second+=1;
            else    um.emplace(answers[i],1);
        }
        
        for(umi=um.begin(); umi!=um.end(); umi++){
            if(umi->second<umi->first+2){// umi->second<=umi->first+1
                sum+=umi->first+1;
            }else{
                if(umi->second%(umi->first+1)!=0)   sum+=(umi->second/(umi->first+1)+1)*(umi->first+1);
                else    sum+=umi->second;
            }
        }
        
        return sum;
    }
};