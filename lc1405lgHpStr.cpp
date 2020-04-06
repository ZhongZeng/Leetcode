/*
1405. Longest Happy String

Company	Wayfair
Related Topics	Dynamic Programming, Greedy 

Test Cases:
1
1
7
2
2
1
7
1
0

Runtime: 0 ms	Your runtime beats 100.00 % of cpp submissions.
Memory Usage: 6.4 MB

https://leetcode.com/problems/longest-happy-string/discuss/566107/C%2B%2B-O(n)-Time-Greedy%2BHeap-Similar-to-621
*/

class Solution {
public:
    string longestDiverseString(int a, int b, int c) {
        // greedy, heap (only 3 elements, doesn't need heap)
		// similar to 621. Task Scheduler
        // AT MOST there is always such string 
        string str;
        vector<pair<char,int>> vp={make_pair('a',a), make_pair('b',b), make_pair('c',c)};
        
        while(true){
            if(1<str.size() && str.back()==str[str.size()-2]){
                if(!pickAndPushChar( vp, str, str.back()))  break;
            }
            if(!pickAndPushChar( vp, str))  break;
        }
        
        return str;
    }
    
protected:
    bool pickAndPushChar( vector<pair<char,int>> & vp, string & str, char c){
        int t=-1;
        for( int i=0; i<vp.size(); i++)
            if(vp[i].first!=c&&(t==-1||vp[t].second<vp[i].second))  t=i;
        if(t==-1||vp[t].second==0)  return false;
        str.push_back(vp[t].first);
        vp[t].second--;
        return true;
    }
    
    bool pickAndPushChar( vector<pair<char,int>> & vp, string & str){
        int t=-1;
        for( int i=0; i<vp.size(); i++)
            if(t==-1||vp[t].second<vp[i].second)    t=i;
        if(t==-1||vp[t].second==0)  return false;
        str.push_back(vp[t].first);
        vp[t].second--;
        return true;
    }
};

/*
// Wrong Solution
class Solution {
public:
    string longestDiverseString(int a, int b, int c) {
        // greedy, heap 
        string str;
        if(b<=a&&c<=a)  pushChar( a, 'a', str);
        else if(a<b&&c<b)   pushChar( b, 'b', str);
        else    pushChar( c, 'c', str);
            
        while( 0<a+b+c ){
            switch(str.back()){
                case 'a':
                    if(b<c) pushChar( c, 'c', str);
                    else    pushChar( b, 'b', str);
                    if(str.back()=='a') return "";
                    break;
                case 'b':
                    if(a<c) pushChar( c, 'c', str);
                    else    pushChar( a, 'a', str);
                    if(str.back()=='b') return "";
                    break;
                case 'c':
                    if(a<b) pushChar( b, 'b', str);
                    else    pushChar( a, 'a', str);
                    if(str.back()=='c') return "";
                    break;
            }
        }
        
        return str;
    }
    
protected:
    void pushChar( int & i, char c, string & str){
        for( int j=0; 0<i&&j<2; i--, j++)
            str.push_back(c);
        return ;
    }
};
*/