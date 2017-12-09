

/*
Leetcode 722. Remove Comments

Related Topics 
String 
Similar Questions 
Mini Parser, Ternary Expression Parser 

Next challenges: Mini Parser, Ternary Expression Parser

Test Cases:
["/*Test program */", "int main()", "{ ", "  // variable declaration ", "int a, b, c;", "/* This is a test", "   multiline  ", "   comment for ", "   testing */", "a = b + c;", "}"]
["test"]
["a/*comment", "line", "more_comment*/b"]
["class test{", "public: ", "   int x = 1;", "   /*double y = 1;*/", "   char c;", "};"]
["test","    ","test"]
["struct Node{", "    /*/ declare members;/**/", "    int size;", "    /**/int val;", "};"]
["void func(int k) {", "// this function does nothing /*", "   k = k*2/4;", "   k = k/2;*/", "}"]
["a/*/b//*c","blank","d/*/e*//f"]

Runtime: 3 ms
You are here! 
Your runtime beats 7.69 % of cpp submissions. beats maturity 

*/

class Solution {
public:
    vector<string> removeComments(vector<string>& source) {
        vector<string> vc;
        string str;
        bool b=false;
        int s;
        for(int i=0; i!=source.size(); i++){
            s=0;
            for(int j=0; ; j++){
                if(j==source[i].size()){
                    if(!b){
                        if(s!=j)    str.append(source[i].substr(s,j-s));
                        //cout<<str<<endl;
                        if(!str.empty()){
                            vc.push_back(str);
                            str.clear();
                        }
                    }
                    break;
                }                 
                
                if(!b&source[i][j]=='/'){
                    if(j!=source[i].size()-1){
                        j++;
                        if(source[i][j]=='/'){ // "//"
                            if(j-1!=s)  str.append(source[i].substr(s,j-1-s));
                            if(!str.empty()){
                                vc.push_back(str);
                                str.clear();
                            }
                            break;
                        }else if(source[i][j]=='*'){ // "/*"
                            if(j-1!=s)  str.append(source[i].substr(s,j-1-s));
                            b=true;
                            continue;
                        }            
                    }
                }
                
                if(b&&source[i][j]=='*'&&j!=source[i].size()-1){
                    j++;
                    if(source[i][j]=='/'){ // "*/"
                        s=j+1;
                        b=false;
                    }else{ //  in case of "**/"
                        j--;
                    }
                }
            } 
        }
        
        return vc;
    }    
};
