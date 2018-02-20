
/*
Leetcode 251. Flatten 2D Vector

Companies 
Google, Twitter, Airbnb, Zenefits
Related Topics 
Design
Similar Questions 
Binary Search Tree IteratorZigzag IteratorPeeking IteratorFlatten Nested List Iterator

Next challenges: Zigzag Iterator, Peeking Iterator

Test Cases:
[[1,2],[3],[4,5,6]]
[[],[]]
[[]]

Runtime: 16 ms
Your runtime beats 13.66 % of cpp submissions.

*/

class Vector2D {
public:
    Vector2D(vector<vector<int>>& vec2d) {
        for(int i=0; i<vec2d.size(); i++){
            for(int j=0; j<vec2d[i].size(); j++){
                vc.push_back(vec2d[i][j]);
            }
        }
        //for(auto e:vc)  cout<<e<<" ";
        l=-1;
    }

    int next() {
        return vc[++l];
    }

    bool hasNext() {
        return l+1<vc.size();
    }

protected:    
    vector<int> vc;
    int l;
};

/**
 * Your Vector2D object will be instantiated and called as such:
 * Vector2D i(vec2d);
 * while (i.hasNext()) cout << i.next();
 */