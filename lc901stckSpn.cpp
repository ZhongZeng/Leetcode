
/*
Leetcode 901. Online Stock Span

Companies   
Microsoft 
Related Topics 
Stack

Next challenges: Remove Duplicate Letters, Decoded String at Index, Sum of Subarray Minimums

Runtime: 172 ms
Your runtime beats 97.25 % of cpp submissions.

*/

class StockSpanner {
public:
    StockSpanner() {// O(n) time, every element accessed at most twice, pushed into & out stack vc 
        timeStamp=0;
    }
    
    int next(int price) {
        timeStamp++;
		int rt=0;
		while(!st.empty()&&st.back().first<=price)	st.pop_back();
		rt=st.empty()?timeStamp:timeStamp-st.back().second;
		st.push_back({price,timeStamp});
		
		return rt;
    }

protected:
	vector<pair<int,int>> st;// price, time stamp 
	int timeStamp;
};

/**
 * Your StockSpanner object will be instantiated and called as such:
 * StockSpanner obj = new StockSpanner();
 * int param_1 = obj.next(price);
 */
