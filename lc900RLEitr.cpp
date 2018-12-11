
/*900. RLE Iterator

Related Topics: Array 

Test Cases: 
["RLEIterator","next","next","next","next","next","next","next","next","next","next","next","next","next","next","next","next","next","next","next","next"]
[[[923381016,843,898173122,924,540599925,391,705283400,275,811628709,850,895038968,590,949764874,580,450563107,660,996257840,917,793325084,82]],[612783106],[486444202],[630147341],[845077576],[243035623],[731489221],[117134294],[220460537],[794582972],[332536150],[815913097],[100607521],[146358489],[697670641],[45234068],[573866037],[519323635],[27431940],[16279485],[203970]]
["RLEIterator","next","next","next","next"]
[[[3,8,0,9,2,5]],[2],[1],[1],[2]]

Runtime: 4 ms, faster than 100.00% of C++ online submissions for RLE Iterator.

*/

class RLEIterator {
public:
    RLEIterator(vector<int> A) {
		// O(n) time 
		loc=0;
        sum=0;
		
		cnt.push_back(0);
		num.push_back(-1); 
		for( int i=0; i<A.size(); i+=2){
			cnt.push_back(cnt.back()+A[i]); 
			num.push_back(A[i+1]); 
		}
    }
    
    int next(int n) {
        // O(log(n)) time
		sum+=n;
		if(cnt.back()<sum)	return -1;
		
		int b=loc, e=cnt.size()-1, mid;// (b,e]
		while(b+1<e){
			mid=b+(e-b)/2;
			if(cnt[mid]<sum)	b=mid;
			else	e=mid;
		}
		loc=b;
		
		return num[e];
    }
	
protected:
	int loc;// current location 
	long sum;// total count 
	vector<long> cnt;// count 
	vector<int> num;// number value 
};

/**
 * Your RLEIterator object will be instantiated and called as such:
 * RLEIterator obj = new RLEIterator(A);
 * int param_1 = obj.next(n);
 */
