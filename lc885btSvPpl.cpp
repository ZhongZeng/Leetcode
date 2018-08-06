
/*
Leetcode 885. Boats to Save People

Companies  

Related Topics 
Two Pointer, Greedy 

Test Cases:
[1,2]
3
[3,2,2,1]
3
[3,5,3,4]
5
[3,2,2,3,2]
6

Next challenges: Best Time to Buy and Sell Stock with Transaction Fee, 
Candy Crush, Score After Flipping Matrix

Runtime: 112 ms

*/


class Solution {
public:
    int numRescueBoats(vector<int>& people, int limit) {
        // greedy, 2-pointer
        int sum=0, b, e;
        
        mergeSort( people, 0, people.size());
        //for(auto e:people)  cout<<e<<" ";
        
        for( b=0, e=people.size()-1; b<e; e--, sum++){
            if(people[b]+people[e]<=limit)  b++;
        }
        
        if(b==e)    sum++;
        
        return sum;
    }
    
    void mergeSort(vector<int>& vc, int b, int e){// [b,e) 
        if(e<b+2)   return ;
        
        int mid=b+(e-b)/2;
        mergeSort(vc, b, mid);
        mergeSort(vc, mid, e);
        merge(vc, b, mid, e);
        
        return;
    }
    
    void merge(vector<int>& vc, int b, int mid, int e){
        vector<int> vt;
        for( int i=b; i<mid; i++)   vt.push_back(vc[i]);
        
        for( int i=0, j=mid, k=b; i<vt.size(); k++){
            if(j==e||vt[i]<vc[j])   vc[k]=vt[i++];
            else    vc[k]=vc[j++];
        }
        
        return ;
    }
};