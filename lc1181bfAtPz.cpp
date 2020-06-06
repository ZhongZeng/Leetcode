/*
1181. Before and After Puzzle

Medium 
Companies	clutter
Related Topics	String

Test Cases:
["a","a c","a b","b e"]
["ghanuo qxi b vxbjg stdsoe xylid e jss skzkhfy f dihh id","vxbjg","wy uia bbg ulfoyo wmss e uia qznglzi kuoqsjm jjarip sdfrvleh agq qznglzi dihh skfm","wmss b chyfiw z chyfiw uvq qjrfodti pgjuaolq id aee ncbd cjmnmexu zclfup gwgeyw qxi aee id skzkhfy","wmss uia xylid bbg jjarip agq chyfiw skzkhfy uhmc aee ddicv e sdfrvleh nq","jss wj f agq uhmc pkore vxbjg ghanuo ddicv","qjrfodti e jss uhmc agq qznglzi nq id nq z aee vnckr skzkhfy pgjuaolq zclfup ulfoyo","pgjuaolq rwlxefgf gwgeyw kuoqsjm wj wmss b e","e aekq wmss agq uhmc vlyp wj qxi jss uhmc uvq ncbd vn wj agq","skfm jjarip wy agq pxqqtzw vn skfm z yoskkg zclfup e qjrfodti vlyp jjarip wj e b","sdfrvleh qznglzi uhmc id aee qznglzi z agq stdsoe","kuoqsjm cfjo skzkhfy rwlxefgf aekq chyfiw sdfrvleh nq e zclfup vlyp","qxi","agq kuoqsjm z skfm z jjarip aekq qznglzi skfm jss pxqqtzw ddicv skzkhfy e cfjo skzkhfy wy e","vxbjg qxi jjarip vn","id z jjarip jjarip yoskkg ncbd uia uia cjmnmexu","rwlxefgf cfjo pxqqtzw f chyfiw ddicv gwgeyw qxi vlyp jjarip pkore uvq f skzkhfy","wy uhmc vxbjg agq ghanuo zclfup z aee","bbg uia rwlxefgf skfm z z","z uvq zclfup wj agq stdsoe vnckr vlyp jjarip z ncbd b vnckr vlyp dihh f dihh vlyp agq pxqqtzw f","aekq z qznglzi chyfiw uia aee zclfup zclfup stdsoe z aee gwgeyw uhmc uyotjsgg thifuxm f","qznglzi cjmnmexu wy pkore vnckr wj wj wj","xylid z wmss e cfjo ulfoyo wy vn bbg ncbd yoskkg ghanuo b qznglzi ncbd xylid","gwgeyw pxqqtzw vnckr dihh sdfrvleh f z","e jjarip aekq bbg aekq wj z ghanuo pkore pgjuaolq","vn chyfiw uhmc id uvq","f vnckr z rwlxefgf f skzkhfy ncbd qznglzi thifuxm qjrfodti stdsoe uyotjsgg z id","kuoqsjm qznglzi wj yoskkg cjmnmexu gwgeyw gwgeyw thifuxm","gwgeyw f e ncbd aee xylid ddicv vlyp yoskkg ulfoyo z yoskkg chyfiw b qxi qjrfodti bbg","z vnckr sdfrvleh aekq uyotjsgg e vxbjg wy ulfoyo aekq skzkhfy wj f rwlxefgf pxqqtzw","e jjarip vnckr skfm rwlxefgf qjrfodti sdfrvleh aee wmss f","aee qznglzi qjrfodti uyotjsgg e z b vn uia cfjo ghanuo f thifuxm cjmnmexu aee z uhmc thifuxm pkore","wy uhmc sdfrvleh aekq zclfup kuoqsjm kuoqsjm z aee","qjrfodti z jss skzkhfy wj wy","bbg pgjuaolq zclfup wy","vxbjg vn wy","z e pxqqtzw vnckr pxqqtzw pkore b wmss gwgeyw uia ghanuo z cjmnmexu wj wj chyfiw jss","thifuxm vn kuoqsjm z vnckr wj yoskkg ncbd uvq kuoqsjm skzkhfy jss yoskkg chyfiw vlyp skfm dihh wy b","uvq uia qjrfodti cjmnmexu dihh vlyp jjarip qznglzi wmss wj","uvq z vn vn stdsoe uyotjsgg qxi z","uhmc aee stdsoe","f cfjo ddicv bbg skfm kuoqsjm qjrfodti e","chyfiw id f uhmc ddicv e qxi zclfup z vn e","id pkore e dihh uhmc stdsoe wj vn","aee skzkhfy jjarip uyotjsgg z aekq e wj pkore uvq wy dihh jss f","wy qznglzi pkore qjrfodti vlyp agq qxi","cjmnmexu dihh sdfrvleh stdsoe vnckr vxbjg uvq cjmnmexu uhmc agq xylid b","e z cjmnmexu uhmc qxi ddicv jss cjmnmexu vnckr e jjarip jjarip aekq ncbd e dihh","wmss vn qznglzi id skfm ncbd aee ghanuo zclfup wj pxqqtzw ulfoyo id","rwlxefgf stdsoe cjmnmexu f qxi ghanuo e uvq agq thifuxm stdsoe jss ulfoyo vlyp b ddicv e z"]
["writing code","code rocks"]
["mission statement", "a quick bite to eat", "a chip off the old block", "chocolate bar", "mission impossible", "a man on a mission", "block party", "eat my words", "bar of soap"]
["a","b","a"]

Runtime: 20 ms, faster than 40.28% of C++ online submissions for Before and After Puzzle.
Memory Usage: 10.7 MB, less than 70.59% of C++ online submissions for Before and After Puzzle.
Next challenges: Shortest Palindrome, Design Log Storage System, Index Pairs of a String
*/

class Solution {
public:
    vector<string> beforeAndAfterPuzzles(vector<string>& phrases) {
        // Sort, String; O(n*log(n)*m) time
        vector<string> pz;
        unordered_set<string> us;// return distinct string
        unordered_map<string, vector<int>> firsts;
        
        for( int i=0; i<phrases.size(); i++){// O(n*m) time
            string first;
            for( int j=0; j<phrases[i].size()&&phrases[i][j]!=' '; j++)
                first.push_back(phrases[i][j]);
            if(firsts.find(first)!=firsts.end())    firsts[first].push_back(i);
            else    firsts[first]={i};
        }
		
        for( int i=0; i<phrases.size(); i++){// O(n*m) time
            string last;
            for( int j=phrases[i].size()-1; -1<j&&phrases[i][j]!=' '; j--)
                last.push_back(phrases[i][j]);
            reverse( last.begin(), last.end());
            unordered_map<string, vector<int>>::iterator it=firsts.find(last);
            if(it!=firsts.end()){
                string p=phrases[i];
                for( int j=p.size()-1; -1<j&&p[j]!=' '; j--)    p.pop_back();//remove last word
                for( int j=0; j<it->second.size(); j++){
                    if(i==it->second[j])    continue;
                    string q=p;
                    q.append(phrases[it->second[j]]);
                    if(us.find(q)!=us.end())    continue;// ensure uniqueness
                    us.emplace(q);
                    pz.push_back(q);
                }
            }
        }
      
        sort(pz.begin(), pz.end(), lessThan);
        
        return pz;
    }
    
protected:
    static bool lessThan( string & s1, string & s2){
        if(s2.size()<s1.size()) return !lessThan(s2, s1);
        for( int i=0; i<s1.size(); i++){
            if(s1[i]<s2[i]) return true;
            else if(s2[i]<s1[i])    return false;
        }
        return s1.size()<s2.size();
    }
};

/*
Wrong Answer
Failed Test Case: ["a","a c","a b","b e"]
*/
class Solution {
public:
    vector<string> beforeAndAfterPuzzles(vector<string>& phrases) {
        // Sort, String; O(n*log(n)) time
        vector<string> pz;
        unordered_set<string> us;// return distinct string
        unordered_map<string, vector<int>> firsts;
        sort( phrases.begin(), phrases.end(), lessThan);
        
        for( int i=0; i<phrases.size(); i++){
            string first;
            for( int j=0; j<phrases[i].size()&&phrases[i][j]!=' '; j++)
                first.push_back(phrases[i][j]);
            if(firsts.find(first)!=firsts.end())    firsts[first].push_back(i);
            else    firsts[first]={i};
        }
        
        for( int i=0; i<phrases.size(); i++){
            string last;
            for( int j=phrases[i].size()-1; -1<j&&phrases[i][j]!=' '; j--)
                last.push_back(phrases[i][j]);
            reverse( last.begin(), last.end());
            unordered_map<string, vector<int>>::iterator it=firsts.find(last);
            if(it!=firsts.end()){
                string p=phrases[i];
                for( int j=p.size()-1; -1<j&&p[j]!=' '; j--)    p.pop_back();
                for( int j=0; j<it->second.size(); j++){
                    if(i==it->second[j])    continue;
                    string q=p;
                    q.append(phrases[it->second[j]]);
                    if(us.find(q)!=us.end())    continue;
                    us.emplace(q);
                    pz.push_back(q);
                }
            }
        }
        
        return pz;
    }
    
protected:
    static bool lessThan( string & s1, string & s2){
        if(s2.size()<s1.size()) return !lessThan(s2, s1);
        for( int i=0; i<s1.size(); i++){
            if(s1[i]<s2[i]) return true;
            else if(s2[i]<s1[i])    return false;
        }
        return s1.size()<s2.size();
    }
};