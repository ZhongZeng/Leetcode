
/*
Leetcode 281. Zigzag Iterator

Companies 
Google
Related Topics 
Design
Similar Questions 
Binary Search Tree Iterator, Flatten 2D Vector,
Peeking Iterator, Flatten Nested List Iterator

Next challenges: Peeking Iterator

Test Cases:
[1,2]
[3,4,5,6]
[]
[]

Runtime: 21 ms
Your runtime beats 34.05 % of cpp submissions.

*/

class ZigzagIterator {
public:
    ZigzagIterator(vector<int>& v1, vector<int>& v2) {
        // this can be modified for n vectors
        vv.push_back(v1);
        vv.push_back(v2);
        for(int i=0; i<2; i++)  ls.push_back(i);
        i=0;
        for(it=ls.begin(); it!=ls.end(); ){
            if(vv[*it].size()<1){
                jt=it++;
                ls.erase(jt);
            }else{
                it++;
            }
        }
        it=ls.begin();
    }

    int next() {// make iterator go to next element 
        int rt=vv[*it][i];
        //cout<<rt<<" ";
        
        it++;
        if(it==ls.end()){
            it=ls.begin();
            i++;
        }
        
        while(vv[*it].size()-1<i){
            jt=it++;
            ls.erase(jt);
            if(0<ls.size()){
                if(it==ls.end()){
                    it=ls.begin();
                    i++;
                }                
            }else{
                return rt;
            }
        }
        
        return rt;
    }

    bool hasNext() {
        return ls.size()!=0;
    }
    
    int i;
    list<int> ls;
    list<int>::iterator it, jt;
    vector<vector<int>> vv;
};

/**
 * Your ZigzagIterator object will be instantiated and called as such:
 * ZigzagIterator i(v1, v2);
 * while (i.hasNext()) cout << i.next();
 */
