
/*
Leetcode 486. Predict the Winner

Tags: Dynamic Programming Minimax
Similar Problems
Next challenges: (M) Can I Win

You are here! 
Your runtime beats 34.35 % of cpp submissions.	3 ms

Test Cases:
[1,1,1]
[1,5,2]
*/

class Solution {
public:
    bool PredictTheWinner(vector<int>& nums) {
		// wondering if there are mathematical solutions
        int n=nums.size();
        return predictWin(nums.begin(), n, 0, 0, true);
    }
    
    
protected:
    bool predictWin(vector<int>::iterator inums, int n, int sum1, int sum2, bool pl) {
        if(pl==true){ // sum1 wins
            if(n==1){
                return sum2<=(sum1+*inums);
            }else if(n==2){
                if(*inums<*(inums+1)){
                    return (sum2+*inums)<=(sum1+*(inums+1));
                }else{
                    return (sum2+*(inums+1))<=(sum1+*inums);
                }
            }else{
                return !predictWin( inums, n-1, sum2, sum1+*(inums+n-1), false) \ // !pl
                    || !predictWin( inums+1, n-1, sum2, sum1+*inums, false); // !pl
            }
        }else{ // sum2 wins
            if(n==1){
                return sum2>(sum1+*inums);
            }else if(n==2){
                if(*inums>*(inums+1)){
                    return (sum2+*inums)>(sum1+*(inums+1));
                }else{
                    return (sum2+*(inums+1))>(sum1+*inums);
                }
            }else{
                return !predictWin( inums, n-1, sum2, sum1+*(inums+n-1), true) \ // !pl
                    || !predictWin( inums+1, n-1, sum2, sum1+*inums, true); // !pl
            }
        }
    }
    
};
