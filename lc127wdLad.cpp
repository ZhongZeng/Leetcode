
/*
Leetcode 127. Word Ladder

Related Topics 
Breadth-first Search
Similar Questions 
Word Ladder II, Minimum Genetic Mutation

Test Case:
"hit"
"cog"
["hot","dot","dog","lot","log","cog"]


*/


class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        // BFS
		// O(n*word.size()*26) time 
		// Runtime: 259 ms
		// Your runtime beats 34.67 % of cpp submissions.
		// The difference b/t this solution&1242 ms is how to construct hash_table. 		
        int i=1, len=wordList[0].size();
        string s;
        unordered_map<string, unordered_set<string>> um;
        unordered_map<string, unordered_set<string>>::iterator umi;
        unordered_set<string> us, words, qu, qv;
        unordered_set<string>::iterator usi, qi;
        
        for(vector<string>::iterator it=wordList.begin(); it!=wordList.end(); it++)
            words.emplace(*it);
        if(words.find(endWord)==words.end())    return false;
        
        // construct hash_table
        for(vector<string>::iterator it=wordList.begin(); it!=wordList.end(); it++){
            us.clear();
            for(int j=0; j<len; j++){
                for(int k=0; k<26; k++){
                    s=*it;
                    s[j]='a'+k;
                    if(*it!=s&&words.find(s)!=words.end())  us.emplace(s);
                }
            }
            um.emplace(*it,us);
        }
        
        if(um.find(beginWord)==um.end()){
            us.clear();
            for(vector<string>::iterator jt=wordList.begin(); jt!=wordList.end(); jt++){
                if(beginWord!=*jt&&isLad(beginWord,*jt))    us.emplace(*jt);
            }
            um.emplace(beginWord,us);
        }
        
        //for(auto ele:um){
        //    cout<<ele.first<<": ";
        //    for(auto el:ele.second)   cout<<el<<" ";    cout<<endl;
        //}
        
        // BFS
        qu.emplace(beginWord);
        while(!(um.empty()||qu.empty())){
            i++;
            qv.clear();
            for(qi=qu.begin(); qi!=qu.end(); qi++){
                //cout<<*qi<<": ";
                umi=um.find(*qi);
                if(umi!=um.end()){
                    for(usi=umi->second.begin(); usi!=umi->second.end(); usi++){
                        //cout<<*usi<<" ";
                        if(*usi!=endWord){
                            if(qv.find(*usi)==qv.end()) qv.emplace(*usi);
                        }else{
                            return i;
                        }    
                    }
                    um.erase(umi);
                }
                //cout<<endl;
            }
            
            i++;
            qu.clear();
            for(qi=qv.begin(); qi!=qv.end(); qi++){
                //cout<<*qi<<": ";
                umi=um.find(*qi);
                if(umi!=um.end()){
                    for(usi=umi->second.begin(); usi!=umi->second.end(); usi++){
                        //cout<<*usi<<" ";
                        if(*usi!=endWord){
                            if(qu.find(*usi)==qu.end()) qu.emplace(*usi);
                        }else{
                            return i;
                        }    
                    }
                    um.erase(umi);
                }
                //cout<<endl;
            }
        }
        
        return 0;
    }
    
protected:    
    bool isLad(string & s1, string & s2){
        // assuming s1.size()==s2.size()
        if(s1==s2)  return false;
        int d=0;
        for(int i=0; i<s1.size(); i++){
            if(s1[i]!=s2[i])    d++;
            if(1<d) return false;
        }
        return true;
    }
    
};


/*
// Runtime: 1242 ms
// Your runtime beats 3.81 % of cpp submissions.
class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        // BFS
		// O(n*n) time 
        int i=1;
        unordered_map<string, unordered_set<string>> um;
        unordered_map<string, unordered_set<string>>::iterator umi;
        unordered_set<string> us, qu, qv;
        unordered_set<string>::iterator usi, qi;
        
        // construct hash_table
        for(vector<string>::iterator it=wordList.begin(); it!=wordList.end(); it++){
            us.clear();
            for(vector<string>::iterator jt=wordList.begin(); jt!=wordList.end(); jt++){
                if(*it!=*jt&&isLad(*it,*jt))    us.emplace(*jt);
            }
            um.emplace(*it,us);
        }
        
        if(um.find(endWord)==um.end())  return false;
        
        if(um.find(beginWord)==um.end()){
            us.clear();
            for(vector<string>::iterator jt=wordList.begin(); jt!=wordList.end(); jt++){
                if(beginWord!=*jt&&isLad(beginWord,*jt))    us.emplace(*jt);
            }
            um.emplace(beginWord,us);
        }
        
        //for(auto ele:um){
        //    cout<<ele.first<<": ";
        //    for(auto el:ele.second)   cout<<el<<" ";    cout<<endl;
        //}
        
        // BFS
        qu.emplace(beginWord);
        while(!(um.empty()||qu.empty())){
            i++;
            qv.clear();
            for(qi=qu.begin(); qi!=qu.end(); qi++){
                //cout<<*qi<<": ";
                umi=um.find(*qi);
                if(umi!=um.end()){
                    for(usi=umi->second.begin(); usi!=umi->second.end(); usi++){
                        //cout<<*usi<<" ";
                        if(*usi!=endWord){
                            if(qv.find(*usi)==qv.end()) qv.emplace(*usi);
                        }else{
                            return i;
                        }    
                    }
                    um.erase(umi);
                }
                //cout<<endl;
            }
            
            i++;
            qu.clear();
            for(qi=qv.begin(); qi!=qv.end(); qi++){
                //cout<<*qi<<": ";
                umi=um.find(*qi);
                if(umi!=um.end()){
                    for(usi=umi->second.begin(); usi!=umi->second.end(); usi++){
                        //cout<<*usi<<" ";
                        if(*usi!=endWord){
                            if(qu.find(*usi)==qu.end()) qu.emplace(*usi);
                        }else{
                            return i;
                        }    
                    }
                    um.erase(umi);
                }
                //cout<<endl;
            }
        }
        
        return 0;
    }
    
protected:    
    bool isLad(string & s1, string & s2){
        // assuming s1.size()==s2.size()
        if(s1==s2)  return false;
        int d=0;
        for(int i=0; i<s1.size(); i++){
            if(s1[i]!=s2[i])    d++;
            if(1<d) return false;
        }
        return true;
    }
    
};
*/
