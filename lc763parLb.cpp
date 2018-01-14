
/*

763. Partition Labels

Weekly Contest 67

Test Case:
"ababcbacadefegdehijhklij"



*/

class Solution {
public:
    vector<int> partitionLabels(string S) {
        // greedy, O(n) time 
		// every element is visited at most twice for is value and 1 more time for its position 
        vector<int> sum;
        vector<vector<int>> vc(26, sum);
        int lt;
        char c;
        bool st;
        // record first&last position of each letter
        for(int l=0; l<26; l++){
            c=(char)('a'+l);
            for(int i=0; i<S.size(); i++){
                if(S[i]==c){
                    if(vc[l].size()==0){
                        vc[l].push_back(i);
                    }else{
                        if(vc[l].size()!=1)    vc[l].back()=i;
                        else    vc[l].push_back(i);
                    }    
                }
            }            
        }
        // for(int i=0; i<vc.size(); i++)  if(!vc[i].empty())  cout<<((char)('a'+i))<<vc[i][0]<<","<<vc[i].back()<<endl;
        
        // greedy
        for(int i=0; i<S.size(); i=lt+1){
            lt=vc[S[i]-'a'].back();// i==vc[S[i]-'a'][0]
            vc[S[i]-'a'].clear();
            st=true;
            while(st){
                st=false;
                for(int l=0; l<26; l++){
                    if(!vc[l].empty()){
                        if(vc[l][0]<lt){// vc[l][0]!=lt
                            lt=lt<vc[l].back()?vc[l].back():lt;
                            vc[l].clear();
                            st=true;
                        }
                    }
                }                
            }
            sum.push_back(lt-i+1);
            //cout<<i<<","<<lt<<" ";
        }
        
        return sum;
    }
};
