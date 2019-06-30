/*
1104. Path In Zigzag Labelled Binary Tree

Tag: Binary Tree (suggested)

Test Cases:
1
14
26

Runtime: 0 ms
Memory Usage: 8.3 MB
*/

class Solution {
public:
    vector<int> pathInZigZagTree(int label) {
        // O(log(n)) time&space
        int i, p;
        vector<int> vb={1}, ve={1}, rt;
        
        while(ve.back()<label){
            vb.push_back(vb.back()<<1);
            ve.push_back((ve.back()<<1)+1);
        }
        
        p=vb.size()%2==0?vb.back()+ve.back()-label:label;
        for( i=vb.size()-1; 0<p; p=p>>1, i--){// (0<p) == (-1<i)
            rt.push_back(i%2==0?p:vb[i]+ve[i]-p);
        }
        reverse( rt.begin(), rt.end());
        
        return rt;
    }
};