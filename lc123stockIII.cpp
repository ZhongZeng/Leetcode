

/*
Leetcode 123. Best Time to Buy and Sell Stock III

Related Topics 
ArrayDynamic Programming
Similar Questions 
Best Time to Buy and Sell Stock, Best Time to Buy and Sell Stock II, 
Best Time to Buy and Sell Stock IV, Maximum Sum of 3 Non-Overlapping Subarrays

Next challenges: Best Time to Buy and Sell Stock IV, 
Maximum Sum of 3 Non-Overlapping Subarrays

Test Cases:
[]
[1]
[1,2]
[2,1,4]
[1,2,3,0,2]
[7,9,5,11]
[7,26,60,95,12,98,15,95]
[2,8,0,7,2,9]



*/


// Runtime: 8 ms
// Your runtime beats 32.60 % of cpp submissions.
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        if(prices.size()<2) return 0;
        
        int p1=0, p2=0, p11=0, pt, min, min1, min11, i;
        min=prices[0]<prices[1]?prices[0]:prices[1];
        min1=min;
        min11=min;
        
        prices.push_back(prices.back()-1);
        for( i=2; i<prices.size(); i++){
            if(prices[i]<prices[i-1]){
                if(prices[i-1]<prices[i-2]){
                                        
                }else{
                    p2=max(prices[i-1]+p1-min1, prices[i-1]+p11-min11, p2);
                    
                    if(p1<prices[i-1]-min){
                        p11=p1;
                        min11=min1;
                        p1=prices[i-1]-min;
                        min1=prices[i];
                    }
                }
                min=min<prices[i]?min:prices[i];
                min1=min1<prices[i]?min1:prices[i];
            }
        }
        
        return p2;
    }
    
    int max( const int & a, const int & b, const int & c){//
        if(a<b){
            return c<b?b:c;
        }else{
            return c<a?a:c;
        }
    }
};


/*
// Runtime: 10 ms
// Your runtime beats 11.53 % of cpp submissions.
class Solution {
public:
    int maxProfit(vector<int>& prices) {
		// O(n) time, O(1) space
		// DP, inspired by hourse robber; it's difficult to design a DP! 
        if(prices.size()<2) return 0;
        
        int p1=0, p2=0, p11=0, min, min1, min11, i;
        min=prices[0]<prices[1]?prices[0]:prices[1];
        min1=min;
        min11=min;
        
        prices.push_back(prices.back()-1);
        for( i=2; i<prices.size(); i++){
            if(prices[i]<prices[i-1]){
                if(prices[i-1]<prices[i-2]){
                                        
                }else{
                    p2=max(prices[i-1]+p1-min1, prices[i-1]+p11-min11, p2);
                    
                    if(p1<prices[i-1]-min){
                        p11=p1;
                        min11=min1;
                        p1=prices[i-1]-min;
                        min1=prices[i];
                    }
                }
                min=min<prices[i]?min:prices[i];
                min1=min1<prices[i]?min1:prices[i];
            }
        }
        
        return p2;
    }
    
    int max(int a, int b, int c){
        if(a<b){
            return c<b?b:c;
        }else{
            return c<a?a:c;
        }
    }
};
*/