
/*
819. Most Common Word

Weekly Contest 80  
Rank: 744 / 2570

Test Cases:
"Bob hit a ball, the hit BALL flew far after it was hit."
["hit"]
"L, P! X! C; u! P? w! P. G, S? l? X? D. w? m? f? v, x? i. z; x' m! U' M! j? V; l. S! j? r, K. O? k? p? p, H! t! z' X! v. u; F, h; s? X? K. y, Y! L; q! y? j, o? D' y? F' Z; E? W; W' W! n! p' U. N; w? V' y! Q; J, o! T? g? o! N' M? X? w! V. w? o' k. W. y, k; o' m! r; i, n. k, w; U? S? t; O' g' z. V. N? z, W? j! m? W! h; t! V' T! Z? R' w, w? y? y; O' w; r? q. G, V. x? n, Y; Q. s? S. G. f, s! U? l. o! i. L; Z' X! u. y, Q. q; Q, D; V. m. q. s? Y, U; p? u! q? h? O. W' y? Z! x! r. E, R, r' X' V, b. z, x! Q; y, g' j; j. q; W; v' X! J' H? i' o? n, Y. X! x? h? u; T? l! o? z. K' z' s; L? p? V' r. L? Y; V! V' S. t? Z' T' Y. s? i? Y! G? r; Y; T! h! K; M. k. U; A! V? R? C' x! X. M; z' V! w. N. T? Y' w? n, Z, Z? Y' R; V' f; V' I; t? X? Z; l? R, Q! Z. R. R, O. S! w; p' T. u? U! n, V, M. p? Q, O? q' t. B, k. u. H' T; T? S; Y! S! i? q! K' z' S! v; L. x; q; W? m? y, Z! x. y. j? N' R' I? r? V! Z; s, O? s; V, I, e? U' w! T? T! u; U! e? w? z; t! C! z? U, p' p! r. x; U! Z; u! j; T! X! N' F? n! P' t, X. s; q'"
["m","i","s","w","y","d","q","l","a","p","n","t","u","b","o","e","f","g","c","x"]

Runtime: 6 ms
Sorry. We do not have enough accepted submissions to show runtime distribution chart.

*/

class Solution {
public:
    string mostCommonWord(string paragraph, vector<string>& banned) {
        // O(n)
        // paragraph only consists of letters, spaces, or the punctuation symbols !?',;.
        int mx=0, t;
        string s;
        unordered_map<string, int> cm;
        unordered_map<string, int>::iterator cmi;
        unordered_set<string> ba;
        for(int i=0; i<banned.size(); i++)  ba.emplace(banned[i]);
        
        // Emplace Strings
        for(int i=0; i<paragraph.size(); i++){
            t=paragraph[i]-'A';
            if(-1<t&&t<26){
                s.push_back(paragraph[i]+32);
            }else if(31<t&&t<58){
                s.push_back(paragraph[i]);
            }else{
                if(!s.empty()){
                    cmi=cm.find(s);
                    if(cmi!=cm.end())   cmi->second+=1;
                    else    cm.emplace(s,1);
                    s.clear();                    
                }                
            }
        }
        if(!s.empty()){
            cmi=cm.find(s);
            if(cmi!=cm.end())   cmi->second+=1;
            else    cm.emplace(s,1);
            s.clear();                    
        } 
        
        // Find Most Frequent
        for(cmi=cm.begin(); cmi!=cm.end(); cmi++){
            if(ba.find(cmi->first)==ba.end()){
                if(mx<cmi->second){
                    mx=cmi->second;
                    s=cmi->first;
                }
            }
        }
        
        return s;
    }
};