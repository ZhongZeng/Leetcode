

/*
Leetcode 60. Permutation Sequence

Related Topics 
Math Backtracking 
Similar Questions 
Next Permutation Permutations 
Next challenges: Fraction to Recurring Decimal, Number of Digit One, 4 Keys Keyboard


Test Cases:
6
300
6
120

Runtime: 3 ms
You are here! 
Your runtime beats 49.61 % of cpp submissions.

*/


class Solution {
public:
    string getPermutation(int n, int k) {
        // n will be between 1 and 9 inclusive
        vector<int> vf={ 1, 2, 6, 24, 120, 720, 5040, 40320, 362880}, vi;
        string s;
        int j;
        for(int i=1; i!=n+1; i++)   vi.push_back(i);
        for(int i=n-2; i!=-1; i--){
            j = k/vf[i];
            k = k%vf[i] ; 
            if(k==0){
                k=vf[i];
                --j;
            }
            s.push_back( (char)(vi[j]+'0') );              
            vi.erase( vi.begin()+j );  
            // cout << i <<' '<<s<< endl;
        }
        s.push_back( (char)(vi[0]+'0') ) ; 
        return s;
    }
};


