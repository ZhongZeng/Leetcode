/*
1449. Form Largest Integer With Digits That Add up to Target

Companies	 Google
Related Topics	String, Dynamic Programming

Test Cases:
[4,3,2,5,6,7,2,5,5]
9
[2,4,6,2,4,6,4,4,4]
5

Runtime: 264 ms, faster than 62.91% of C++ online submissions for Form Largest Integer With Digits That Add up to Target.
Memory Usage: 62.6 MB, less than 100.00% of C++ online submissions for Form Largest Integer With Digits That Add up to Target.
Next challenges: Maximum Vacation Days, Max Difference You Can Get From Changing an Integer
Destination City

https://leetcode.com/problems/form-largest-integer-with-digits-that-add-up-to-target/discuss/652377/C%2B%2B-Dynamic-Programming-O(10*target)-TimeandSpace
*/

class Solution {
public:
    string largestNumber(vector<int>& cost, int target) {
        // Dynamic Programming, Greedy, BFS; Knapsack problem; O(10*target) time&space; target&cost in [1,5000]
        // we can think we have 0-8 while 0 can be leading digit
        string num;
        vector<char> ch={'1','2','3','4','5','6','7','8','9'};
        vector<vector<int>> digits(target+1, vector<int> (10,0));
        for( int i=0; i<target; i++){
            if(i==0||0<digits[i].back()){// some targets're unachieveable
                for( int j=0; j<cost.size(); j++){
                vector<int> vc=digits[i];
                vc[j]+=1;
                vc.back()+=1;
                int this_cost=i+cost[j];
                if(this_cost<=target&&lessThan(digits[this_cost],vc))// digits.size()==target+1
                    digits[this_cost]=vc;
                }
            }
        }
        
        for( int i=digits.back().size()-2; -1<i; i--){// digits.back().back() is sum of digits.back()
            for( int j=0; j<digits.back()[i]; j++){
                num.push_back(ch[i]);
            }
        }
            
        return num!=""?num:"0";
    }
    
protected:
    bool lessThan(vector<int> & vc1, vector<int> & vc2){//vc1.size()==vc2.size()==10; # of 1-9 and total counts
        for( int i=vc1.size()-1; -1<i; i--)
            if(vc1[i]<vc2[i])   return true;
            else if(vc2[i]<vc1[i])  return false;
        return false;
    }
};