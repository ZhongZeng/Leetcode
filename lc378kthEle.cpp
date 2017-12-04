/*
Leetcode 378. Kth Smallest Element in a Sorted Matrix

Related Topics 
Binary Search Heap 
Similar Questions 
Find K Pairs with Smallest Sums, Kth Smallest Number in Multiplication Table 
Find K-th Smallest Pair Distance 

Next challenges: 
Find K Pairs with Smallest Sums, Kth Smallest Number in Multiplication Table,
Find K-th Smallest Pair Distance

Test Cases:
[[1,5,9],[10,11,13],[12,13,15]]
8
[[0,5,9,13,18],[1,8,10,14,19],[1,8,14,18,20],[2,12,15,19,22],[7,15,19,22,25]]
22
[[10,14],[14,18],[15,19]]
6

Runtime: 49 ms
Your runtime beats 32.55 % of cpp submissions.

*/

class Solution {
public:
    int kthSmallest(vector<vector<int>>& matrix, int k) {
        //each of the rows and columns are sorted in ascending order
        // k belongs [1,n*n]
        // O(k*k) time & less of O(2^k)&O(n) space
        int ct=0, r, c;
        vector<pair<int,pair<int,int>>> hp;// value, row, column
        pair<int,pair<int,int>> pp;
        
        pp.first=matrix[0][0];
        pp.second.first=0;
        pp.second.second=0;
        hp.push_back(pp);
        
        while(++ct!=k){//while(!hp.empty()){
            //cout<<hp[0].first<<" ";
            r=hp[0].second.first;
            c=hp[0].second.second;
            
            hp[0]=*hp.rbegin();
            hp.pop_back();
            topDown(hp);
            
            pushPr(r+1, c, matrix, hp);
            pushPr(r, c+1, matrix, hp);
        }
        
        return hp[0].first;
    }

protected:
    void pushPr(int r, int c, vector<vector<int>>& matrix, vector<pair<int,pair<int,int>>>& hp){
        pair<int,pair<int,int>> pp;
        if( r<matrix.size()&&c<matrix[0].size()&&matrix[r][c]!=matrix[0][0]-1 ){
            pp.first=matrix[r][c];
            pp.second.first=r;
            pp.second.second=c;
            matrix[r][c]=matrix[0][0]-1;
            hp.push_back(pp);
            bottomUp(hp);
        }
        return ;
    }
    
    void topDown(vector<pair<int,pair<int,int>>> & hp){// adjust heap top-down
        int i=0;
        pair<int,pair<int,int>> pp;
        while(2*i+2<hp.size()){
            //cout<<"ts"<<hp[i].first<<"-"<<hp[2*i+1].first<<"-"<<hp[2*i+2].first<<" ";
            if(lessThan(hp[2*i+1],hp[i])&&!(lessThan(hp[2*i+2],hp[2*i+1]))){
                pp=hp[2*i+1];
                hp[2*i+1]=hp[i];
                hp[i]=pp;
                //cout<<"td"<<hp[2*i+1].first<<"-"<<hp[i].first<<" ";
                i=2*i+1;
            }else if(lessThan(hp[2*i+2],hp[i])&&!(lessThan(hp[2*i+1],hp[2*i+2]))){
                pp=hp[2*i+2];
                hp[2*i+2]=hp[i];
                hp[i]=pp;
                //cout<<"td"<<hp[2*i+2].first<<"-"<<hp[i].first<<" ";
                i=2*i+2;
            }else{
                return;
            }
        }
        
        if(2*i+1<hp.size()&&lessThan(hp[2*i+1],hp[i])){
            pp=hp[2*i+1];
            hp[2*i+1]=hp[i];
            hp[i]=pp;
            //cout<<"td"<<hp[2*i+1].first<<"-"<<hp[i].first<<" ";
        }
        
        return ;
    }
    
    void bottomUp(vector<pair<int,pair<int,int>>> & hp){// adjust heap bottom-up
        int i=hp.size()-1;
        pair<int,pair<int,int>> pp;
        while(0<i){
            if(lessThan(hp[i],hp[(i-1)/2])){
                pp=hp[(i-1)/2];
                hp[(i-1)/2]=hp[i];
                hp[i]=pp;
                //cout<<"bu"<<hp[i].first<<"-"<<hp[(i-1)/2].first<<" ";
                i=(i-1)/2;
            }else{
                return;
            }
        }
        return ;
    }
    
    bool lessThan(pair<int,pair<int,int>> & p1, pair<int,pair<int,int>> & p2){
        if(p1.first<p2.first){
            return true;
        }else if(p2.first<p1.first){
            return false;
        }else{
            //if(p1.second.first<p2.second.first||p1.second.second<p2.second.second)  return true;//this is wrong!
            //else    
                return false;
        }
    }
};
