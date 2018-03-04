
/*
Leetcode 163. Missing Ranges


Companies 
Google
Related Topics 
Array 
Similar Questions 
Summary Ranges

Next challenges: Word Search, Maximum Length of Repeated Subarray, Candy Crush

Test Cases:
[0,1,3,50,75]
0
99
[50]
0
99
[]
0
99
[1,1,1]
1
1
[-2147483648,-2147483648,0,2147483647,2147483647]
-2147483648
2147483647

Runtime: 2 ms
Your runtime beats 15.34 % of cpp submissions.

*/

class Solution {
public:
    vector<string> findMissingRanges(vector<int>& nums, int lower, int upper) {
        // the range of elements are in the inclusive range [lower, upper]
        vector<string> vs;
        string s;
        
        if(nums.size()<1){
            if(lower!=upper){
                s.append(to_string(lower));
                s.append("->");
                s.append(to_string(upper));
            }else{
                s.append(to_string(lower));
            }
            vs.push_back(s);
            return vs;
        }
        
        missLo(lower, nums[0], vs);
        for(int i=1; i<nums.size(); i++)    missRg(nums[i-1],nums[i],vs);
        missHi(nums.back(), upper, vs);
        
        return vs;
    }
    
protected:    
    void missLo(int a, int b, vector<string>& vs){// last&this element 
        if(a==2147483647||b<a+1){
        }else if(a+1<b){
            string s;
            s.append(to_string(a));
            s.append("->");
            s.append(to_string(b-1));
            vs.push_back(s);            
        }else{
            vs.push_back(to_string(a));
        }
        return ;
    }
    
    void missHi(int a, int b, vector<string>& vs){// last&this element 
        if(a==2147483647||b<a+1){
        }else if(a+1<b){
            string s;
            s.append(to_string(a+1));
            s.append("->");
            s.append(to_string(b));
            vs.push_back(s);            
        }else{
            vs.push_back(to_string(b));
        }
        return ;
    }      
    
    void missRg(int a, int b, vector<string>& vs){// last&this element 
        if(a==2147483647||a==2147483646||b<a+2){
        }else if(a+2<b){
            string s;
            s.append(to_string(a+1));
            s.append("->");
            s.append(to_string(b-1));
            vs.push_back(s);            
        }else{
            vs.push_back(to_string(a+1));
        }
        return ;
    }
};