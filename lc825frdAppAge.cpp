
/*
Leetcode 825. Friends Of Appropriate Ages

Companies 
Facebook
Related Topics 
Array 

Test Cases:
[16,16]
[16,17,18]
[20,30,100,110,120]

Runtime: 111 ms

*/

class Solution {
public:
    int numFriendRequests(vector<int>& ages) {
        // O(n*log(n)) time; O(n**2) is trival, TLE; sort, binary search 
        // B <= 0.5 * A + 7; B > A; B > 100 && A < 100 (redundant) 
        // A/2+7 < B <= A 
        int sum=0;
        
        mergeSort( ages, 0, ages.size() );
        //for(auto e:ages)    cout<<e<<" ";   cout<<endl;
        
        for(int i=0, bb, be; i<ages.size(); i++){// A2B
            if(14<ages[i]){
                bb=findBb(ages, i);
                be=findBe(ages, i);
                sum+=be-bb;
                //cout<<bb<<","<<be<<"; ";
            }
        }
        
        return sum;
    }
    
    int findBb(vector<int>& ages, int i){
        // Binary Search: O(log(n)), find smallest element > t=A/2+7
        int b=-1, e=ages.size()-1, mid, t=ages[i]/2+7;// ages[b]<=t && t<B<=A<=ages[e] 
        while(b+1<e){
            mid=b+(e-b)/2;
            if(t<ages[mid]) e=mid;
            else    b=mid;
        }
        return e;
    }
    
    int findBe(vector<int>& ages, int i){
        // Binary Search: O(log(n)), find greatest element <= A 
        int b=i, e=ages.size(), mid, t=ages[i];// ages[b]==t && t<ages[e] 
        while(b+1<e){
            mid=b+(e-b)/2;
            if(t<ages[mid]) e=mid;
            else    b=mid;
        }
        return b;
    }    
    
    void mergeSort(vector<int>& ages, int b, int e){// [b, e) 
        if(e<b+2)   return ;
            
        int mid=b+(e-b)/2;
        
        mergeSort(ages, b, mid);
        mergeSort(ages, mid, e);
        merge(ages, b, mid, e);
        
        return ;
    }
    
    
    void merge(vector<int>& ages, int b, int mid, int e){
        vector<int> vc;
        for(int i=b; i<mid; i++)    vc.push_back(ages[i]);
        
        for(int i=0, j=mid, k=b; i<vc.size(); k++){
            if(j==e||vc[i]<ages[j]) ages[k]=vc[i++];
            else    ages[k]=ages[j++];
        }
        
        return ;
    }
};
