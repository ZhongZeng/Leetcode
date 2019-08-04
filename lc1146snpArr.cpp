/*
1146. Snapshot Array
Related Topics	Array, Suggested: Binary Search, Hash Table

Test Case:
["SnapshotArray","set","snap","set","get"]
[[3],[0,5],[],[0,6],[0,0]]

Runtime: 244 ms
Memory Usage: 76.8 MB

Next challenges: Best Time to Buy and Sell Stock with Transaction Fee, 
Sum of Subsequence Widths, Largest Unique Number
*/
class SnapshotArray {
public:
    SnapshotArray(int length) {
        
    }
    
    void set(int index, int val) {
        unordered_map<int,vector<pair<int,int>>>::iterator umi=um.find(index);
        if(umi!=um.end()){
            umi->second.push_back(make_pair(c_id, val));
        }else{
            vector<pair<int,int>> vp={make_pair(c_id, val)};
            um.emplace(index, vp);
        }
        return ;
    }
    
    int snap() {
        return ++c_id;
    }
    
    int get(int index, int snap_id) {
        unordered_map<int,vector<pair<int,int>>>::iterator umi=um.find(index);
        return umi!=um.end()?getVal(umi->second, snap_id):0;
    }
    
protected:
    int c_id=-1;
    unordered_map<int,vector<pair<int,int>>> um;
    int getVal(vector<pair<int,int>>& vp, int snap_id){
        if(vp.back().first<snap_id) return vp.back().second;
        int b=-1, e=vp.size()-1, mid;
        while( b+1<e ){// (b,e]
            mid=b+(e-b)/2;// mid>b+1>=0
            if(vp[mid].first<snap_id)   b=mid;
            else    e=mid;
        }
        return b==-1?0:vp[b].second;
    }
};

/**
 * Your SnapshotArray object will be instantiated and called as such:
 * SnapshotArray* obj = new SnapshotArray(length);
 * obj->set(index,val);
 * int param_2 = obj->snap();
 * int param_3 = obj->get(index,snap_id);
 */