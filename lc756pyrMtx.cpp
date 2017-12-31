


/*
Leetcode 756. Pyramid Transition Matrix


Test Cases:
"ABC"
["ABD","BCE","DEF","FFF"]
"XXYX"
["XXX", "XXY", "XYX", "XYY", "YXZ"]
"DACCDGDDCFCGCFAGFADF"
["BGF","AGE","AGC","AGA","CCE","CCD","EGA","CCF","CCA","DCD","DCA","FGE","FGA","FGB","BFB","BFG","BFD","ECC","DBA","FAF","DBF","FDA","FDC","FDE","BEA","BEE","AEA","AEC","AED","EEE","DEA","DEC","EEA","CCG","EEC","DEG","CEE","CED","CEC","CEA","GEC","GEA","GEF","GEE","BDE","BDD","GCE","AFC","DDC","DDB","EFB","EFE","DDE","DDD","CBC","CBE","ACB","ACE","BCD","BCE","BCA","BCB","BCC","DGB","ECF","DGF","ECB","ECA","CGD","CGF","FCE","FEF","BBF","BBD","ADG","ADD","ADA","DFD","DFC","CDE","CDF","CDG","EDF","EDG","EDD","FBA","FBG","FBF","GDF","AAE","AAD","AAC","BAG","BAB","BAC","BAA","CAF","CAD","DAD","DAB","DED","EAD","EAG","EAF","FAC","GAD","GAC","GAB","ABA","ABF","EBD","EBF","EBA","EBB","EBC","CFF","CFE","CFC","GFC","GFA","GFG","GFD"]

Runtime: 249 ms

*/


class Solution {
public:
    bool pyramidTransition(string bottom, vector<string>& allowed){
        // DP, recursion; hash_table
        unordered_map<string, unordered_set<char>> um;
        unordered_map<string, unordered_set<char>>::iterator umi;
        unordered_set<char> us;
        vector<unordered_set<char>> vs;
        
        // hash table; assuming no duplicates in allowed
        for(vector<string>::iterator it=allowed.begin(); it!=allowed.end(); it++){
            umi=um.find(it->substr(0,2));
            if(umi!=um.end()){
                if(umi->second.find(it->back())==umi->second.end())
                    umi->second.emplace(it->back());
            }else{
                us.clear();
                us.emplace(it->back());
                um.emplace(it->substr(0,2), us);                
            }
        }
        //for(auto ele:um)    cout<<ele.first<<" ";
        
        // vector<unordered_set<char>>
        for(int i=0; i<bottom.size(); i++){
            us.clear();
            us.emplace(bottom[i]);
            vs.push_back(us);
        }
        //for(auto ele:vs)    cout<<ele<<" ";
        //cout<<um.find("BF")->first<<endl;
        
        return pyramidTransition(vs, um);
    }

protected:
    bool pyramidTransition(vector<unordered_set<char>>& vs, unordered_map<string, unordered_set<char>>& um){
        if(vs.size()==1)    return true;
        
        vector<unordered_set<char>> vc;
        string s;
        unordered_set<char> c;
        unordered_map<string, unordered_set<char>>::iterator umi;
        for(int i=1; i<vs.size(); i++){
            c.clear();
            for(unordered_set<char>::iterator jt=vs[i-1].begin(); jt!=vs[i-1].end(); jt++){//int j=0; j<vs[i-1].size(); j++
                s.clear();
                s.push_back(*jt);
                for(unordered_set<char>::iterator kt=vs[i].begin(); kt!=vs[i].end(); kt++){//int k=0; k<vs[i].size(); k++
                    s.push_back(*kt);
                    umi=um.find(s);
                    if(umi!=um.end()){
                        for(unordered_set<char>::iterator usi=umi->second.begin(); usi!=umi->second.end(); usi++){
                            if(c.find(*usi)==c.end())   c.emplace(*usi);
                        }
                    }
                    s.pop_back();
                }
            }
            //cout<<c<<" ";
            if(c.empty())   return false;
            else   vc.push_back(c);
        }
        
        //for(auto ele:vc)    cout<<ele<<" ";  cout<<endl;
        return pyramidTransition(vc, um);
    }
    
};


/*
// TLE
class Solution {
public:
    bool pyramidTransition(string bottom, vector<string>& allowed){
        // DP, recursion; hash_table
        unordered_map<string, unordered_set<char>> um;
        unordered_map<string, unordered_set<char>>::iterator umi;
        unordered_set<char> us;
        vector<string> vs;
        
        // hash table
        for(vector<string>::iterator it=allowed.begin(); it!=allowed.end(); it++){
            umi=um.find(it->substr(0,2));
            if(umi!=um.end()){
                if(umi->second.find(it->back())==umi->second.end())
                    umi->second.emplace(it->back());
            }else{
                us.clear();
                us.emplace(it->back());
                um.emplace( it->substr(0,2), us);                
            }
        }
        //for(auto ele:um)    cout<<ele.first<<" ";
        
        // vector<string>
        for(int i=0; i<bottom.size(); i++){
            vs.push_back(bottom.substr(i,1));
        }
        //for(auto ele:vs)    cout<<ele<<" ";
        //cout<<um.find("BF")->first<<endl;
        
        return pyramidTransition(vs, um);
    }

protected:
    bool pyramidTransition(vector<string>& vs, unordered_map<string, unordered_set<char>>& um){
        if(vs.size()==1)    return true;
        
        vector<string> vc;
        string s, c;
        unordered_map<string, unordered_set<char>>::iterator umi;
        for(int i=1; i<vs.size(); i++){
            c.clear();
            for(int j=0; j<vs[i-1].size(); j++){
                s.clear();
                s.push_back(vs[i-1][j]);
                for(int k=0; k<vs[i].size(); k++){
                    s.push_back(vs[i][k]);
                    umi=um.find(s);
                    if(umi!=um.end()){
                        for(unordered_set<char>::iterator usi=umi->second.begin(); usi!=umi->second.end(); usi++)
                            c.push_back(*usi);
                    }
                    s.pop_back();
                }
            }
            //cout<<c<<" ";
            if(c.empty()){
                return false;
            }else{
                vc.push_back(c);
            }    
        }
        
        //for(auto ele:vc)    cout<<ele<<" ";  cout<<endl;
        return pyramidTransition(vc, um);
    }
    
};
*/