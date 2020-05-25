/*
1451. Rearrange Words in a Sentence

Companies	Expedia
Related Topics	String, Sort

Test Cases:
"Leetcode is cool"
"Keep calm and code on"
"To be or not to be"

Runtime: 196 ms	Your runtime beats 42.35 % of cpp submissions.
Memory Usage: 17.7 MB
*/

struct comp{
    bool operator ()(pair<string,int> & p1, pair<string,int> & p2){
        if(p1.first.size()<p2.first.size()) return true;
        else if(p2.first.size()<p1.first.size())    return false;
        else    return p1.second<p2.second;
    }
};

class Solution {
public:
    string arrangeWords(string text) {
        //O(n*log(n)*m) time
        if(text.size()<1)   return "";
        int i, len;
        string word={(char)(text[0]+32)};
        vector<pair<string,int>> words;
        string rt;
        
        for( i=1; i<text.size(); i++){
            if(text[i]==' '){
                words.push_back(make_pair(word,i));
                word.clear();
            }else{
                word.push_back(text[i]);
            }
        }
        words.push_back(make_pair(word,i));
        
        sort( words.begin(), words.end(), comp());
        
        word=words[0].first;
        word[0]=(char)(word[0]-32);
        rt.append(word);
        for( i=1; i<words.size(); i++){
            rt.push_back(' ');
            rt.append(words[i].first);
        }
        
        return rt;
    }
};