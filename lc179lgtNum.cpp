

/*

Leetcode 179. Largest Number

Related Topics 
Sort

Next challenges: Meeting Rooms, Best Meeting Point, Word Abbreviation

Test Cases:
[1]
[3, 30, 34, 5, 9]
[1,2]
[0,0]

Runtime: 3 ms
Your runtime beats 62.91 % of cpp submissions.

*/

class Solution {
public:
    string largestNumber(vector<int>& nums) {
        string s;
        int e;
        bool z=true;
        vector<string> vs;
        for(int i=0; i<nums.size(); i++){
            e=nums[i];
            if(e!=0){
                s.clear();
                while(e!=0){
                    s.push_back('0'+e%10);
                    e=e/10;
                }
                reverse(s.begin(),s.end());
                vs.push_back(s);
                z=false;
            }else{
                vs.push_back("0");
            }
        }
        
        if(z)   return "0";
        
        mergeSort(vs, 0, vs.size());
        //for(auto ele:vs)    cout<<ele<<" "; cout<<endl;
        
        s.clear();
        for(int i=0; i<vs.size(); i++)  s.append(vs[i]);
        
        return s;
    }
    
protected:
    void mergeSort(vector<string> & vs, int bg, int ed){//[bg,ed)
        if(ed-2<bg)  return;
        int mid=bg+(ed-bg)/2;
        mergeSort(vs, bg, mid);
        mergeSort(vs, mid, ed);
        merge(vs, bg, mid, ed);
        return ;
    }
    
    void merge(vector<string> & vs, int bg, int mid, int ed){
        vector<string> vs2;
        for(int i=bg; i<mid; i++)   vs2.push_back(vs[i]);
        
        for(int i=bg, j=0, k=mid; j<vs2.size(); i++){
            //cout<<vs2[j]<<" "<<vs[k]<<endl;
            if(k==ed||largerThan(vs2[j],vs[k])){// pay attention to the sequence of ||
                vs[i]=vs2[j++];
            }else{
                vs[i]=vs[k++];
            }
            //cout<<i<<" "<<j<<" "<<k<<endl;
        }
        return ;
    }
    
    bool largerThan(string & s1, string & s2){
        // compare s1.append(s2) w/ s2.append(s1)
        if(s1.size()<s2.size()) return !largerThan(s2,s1);
        // s1.size()>=s2.size()
        int i;
        for(i=0; i<s2.size(); i++){
            if(s2[i]<s1[i]){
                return true;
            }else if(s1[i]<s2[i]){
                return false;
            }
        }
        
        for( ; i<s1.size(); i++){
            if(s1[i-s2.size()]<s1[i]){
                return true;
            }else if(s1[i]<s1[i-s2.size()]){
                return false;
            }
        }
        
        for( ; i<s1.size()+s2.size(); i++){
            if(s1[i-s2.size()]<s1[i-s1.size()]){
                return true;
            }else if(s1[i-s1.size()]<s1[i-s2.size()]){
                return false;
            }            
        }
        
        return false;// s1==s2
    }
    
};

