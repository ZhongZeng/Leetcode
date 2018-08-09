
/*
Leetcode 497. Random Point in Non-overlapping Rectangles

Companies  
Google 
Related Topics 
Binary Search, Random 
Similar Questions 
Random Pick with Weight, Generate Random Point in a Circle

Next challenges: Generate Random Point in a Circle

Test Cases: 
["Solution", "pick", "pick", "pick"]
[[[[1, 1, 5, 5]]], [], [], []]
["Solution","pick","pick","pick","pick","pick"]
[[[[-2,-2,-1,-1],[1,0,3,0]]],[],[],[],[],[]]
["Solution", "pick", "pick", "pick"]
[[[[-58953616,-40483558,-58953446,-40482555],[76369640,94978791,76371036,94979394],[80970826,-37466957,80971657,-37466388],[-79821573,-4177978,-79820536,-4177925]]],[], [], []]
["Solution", "pick", "pick"]
[[[[82918473, -57180867, 82918476, -57180863], [83793579, 18088559, 83793580, 18088560], [66574245, 26243152, 66574246, 26243153], [72983930, 11921716, 72983934, 11921720]]], [], []]

Runtime: 64 ms
Your runtime beats 55.16 % of cpp submissions.

*/

class Solution {
public:
    Solution(vector<vector<int>> rects) {
        // length and width of each rectangle does not exceed 2000.
        rc=rects;
        int i=0;
        ca.push_back((rects[i][2]-rects[i][0]+1)*(rects[i][3]-rects[i][1]+1));
        
        while( ++i<rects.size() ){
            ca.push_back(ca.back()+(rects[i][2]-rects[i][0]+1)*(rects[i][3]-rects[i][1]+1));
            // +1 b/c perimeter included 
        }
        //for(auto e:ca)  cout<<e<<" ";   cout<<endl;
    }
    
    vector<int> pick() {
        int rd=rand()%ca.back(), b=-1, e=ca.size()-1, mid;// [b,e) 
		vector<int> rt; 
		
		while(b+1<e){
			mid=e-(e-b)/2;// corner case b==-1
			if(rd<ca[mid])	e=mid;
			else	b=mid;
		}
		
		rt.push_back( rc[e][0]+rand()%(rc[e][2]-rc[e][0]+1) );
		rt.push_back( rc[e][1]+rand()%(rc[e][3]-rc[e][1]+1) );
		
		return rt;
    }

protected:    
    vector<int> ca; // cumulative areas 
	vector<vector<int>> rc;
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution obj = new Solution(rects);
 * vector<int> param_1 = obj.pick();
 */
 