
/*
Leetcode 401. Binary Watch

Companies 
Google
Related Topics 
Backtracking, Bit Manipulation 
Similar Questions 
Letter Combinations of a Phone Number, Number of 1 Bits

Next challenges: Single Number II, Maximum XOR of Two Numbers in an Array, Number Complement

Test Cases:
1
2
4
7

Your runtime beats 100.00 % of cpp submissions.
Runtime: 0 ms

*/

class Solution {
public:
    vector<string> readBinaryWatch(int num) {
        vector<string> rt;
        
        for( int i=num-6<0?0:num-6; i<=num&&i<5; i++)   backTrack( i, num-i, rt);// num-7<i
        
        return rt;
    }
    
    void backTrack( int i, int j, vector<string>& rt){// DFS
        int h=0, m=0;
        vector<int> vh={1,2,4,8}, vm={1,2,4,8,16,32};
        vector<string> uh, um;
        
        combH( i, 0, 0, vh, uh);// combination 
        combM( j, 0, 0, vm, um);
        
        //cout<<i<<" "<<j<<" :"<<endl;
        //for(auto e:uh)  cout<<e<<" ";   cout<<endl;
        //for(auto e:um)  cout<<e<<" ";   cout<<endl;
        
        for( int k=0; k<uh.size(); k++){
            for( int l=0; l<um.size(); l++){
                string s;
                s.append(uh[k]);
                s.push_back(':');
                s.append(um[l]);
                rt.push_back(s);
            }
        }
        
        return ;
    }
    
    void combH( int i, int k, int sum, vector<int>& vc, vector<string>& uc){// # elements, current sum, position in vc 
        if(i==0){
            if(sum<12)  uc.push_back(to_string(sum));
            return ;
        }
        if(k==vc.size())    return ;
        
        combH( i-1, k+1, sum+vc[k], vc, uc);
        combH( i, k+1, sum, vc, uc);
        
        return ;
    }
    
    void combM( int i, int k, int sum, vector<int>& vc, vector<string>& uc){// # elements, current sum, position in vc 
        if(i==0){
            if(sum<10){
                string s="0";
                s.append(to_string(sum));
                uc.push_back(s);
            }else if(sum<60){
                uc.push_back(to_string(sum));
            }
            return ;
        }
        if(k==vc.size())    return ;
        
        combM( i-1, k+1, sum+vc[k], vc, uc);
        combM( i, k+1, sum, vc, uc);
        
        return ;
    }
};
