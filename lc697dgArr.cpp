
/*
Leetcode 697. Degree of an Array

Related Topics 
Array 
Similar Questions 
Maximum Subarray 

Next challenges: Merge Intervals, Word Ladder II, Split Array with Equal Sum

Runtime: 55 ms
You are here! 
Your runtime beats 36.56 % of cpp submissions.

*/


struct ele{
    int first;
    int second;    
    ele(int i, int j) { first=i; second = j;}
};

class Solution {
public:
    int findShortestSubArray(vector<int>& nums) {
        unordered_map<int, int> um;
        unordered_map<int, int>::iterator umi;
        unordered_map<int, ele> me;
        unordered_map<int, ele>::iterator mei;
        int mf=1, ml, len;
        ele ele1(-1, -1);
        for(vector<int>::iterator it=nums.begin(); it!=nums.end(); it++){
            umi=um.find(*it);
            if( umi!=um.end() ){
                umi->second++;
                mf = mf<umi->second ? umi->second : mf;
            }else{
                um.emplace(*it, 1);
                //cout<<*it<<' ';
            }                 
        }
        //cout<<endl;
        
        // construct a map of max-fq element
        for(umi=um.begin(); umi!=um.end(); umi++){
            if( umi->second==mf ){
                me.emplace(umi->first, ele1);
                //cout<<umi->first<<' ';
            }
        }     
        //cout<<endl;
        
        // find the 1st position
        for(int i=0; i!=nums.size(); i++){
            mei=me.find( nums[i] );
            if( mei!=me.end() && mei->second.first==-1 ){
                mei->second.first = i;
                //cout<<i<<' ';
            }          
        }
        //cout<<endl;
        
        // find the last position
        for(int i=nums.size()-1; i!=-1; i--){
            mei=me.find( nums[i] );
            if( mei!=me.end() && mei->second.second==-1 ){
                mei->second.second = i;
                //cout<<i<<' ';
            }          
        }
        //cout<<endl;
        
        mei = me.begin();
        ml = mei->second.second - mei->second.first;
        while( ++mei!=me.end() ){
            cout<<mei->second.second<<' '<<mei->second.first<<endl;
            len = mei->second.second - mei->second.first ;
            ml = len<ml ? len : ml;
        }
        
        return ml+1;
    }
};

