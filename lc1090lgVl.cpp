/*
1090. Largest Values From Labels


Test Cases:
[5,4,3,2,1]
[1,1,2,2,3]
3
1
[5,4,3,2,1]
[1,3,3,3,2]
3
2
[9,8,8,7,6]
[0,0,0,1,1]
3
1
[9,8,8,7,6]
[0,0,0,1,1]
3
2

Runtime: 60 ms
Memory Usage: 18.2 MB
*/

class Solution {
public:
    int largestValsFromLabels(vector<int>& values, vector<int>& labels, int num_wanted, int use_limit) {
        // array, greedy, sort; O(n*log(n)) time, O(n) space; num_wanted, use_limit in [1,values.length]
        int mx=0, ct=0;
        unordered_map<int,int> us;
        unordered_map<int,list<int>> vl;
        
        for( int i=0; i<values.size(); i++){// record value&associated labels
            unordered_map<int,list<int>>::iterator vli=vl.find(values[i]);
            if(vli!=vl.end()){
                vli->second.push_back(labels[i]);
            }else{
                list<int> ls={labels[i]};
                vl.emplace(values[i], ls);
            }
        }
        
        sort( values.begin(), values.end());
        
        for( int i=values.size()-1; -1<i; i--){// pick values greedily & record # picks
            if(i==values.size()-1||values[i]!=values[i+1]){
                unordered_map<int,list<int>>::iterator vli=vl.find(values[i]);// vli!=vl.end() guranteed 
                for( list<int>::iterator it=vli->second.begin(); it!=vli->second.end(); it++){
                    unordered_map<int,int>::iterator usi=us.find(*it);// label
                    if(usi!=us.end()){
                        if(usi->second<use_limit){
                            usi->second+=1;
                            mx+=values[i];
                            ct++;
                        }
                    }else{
                        us.emplace(*it,1);
                        mx+=values[i];
                        ct++;
                    }
                    if(ct==num_wanted)  return mx;
                }
            }
        }
        
        return mx;
    }
};