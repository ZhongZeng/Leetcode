
/*
Leetcode 800. Similar RGB Color

Test Cases:
"#09f166"
"#4e3fe1"

*/

class Solution {
public:
    string similarRGB(string color) {
        string rt="#";
        int a, b, c;
        string s="#4e3fe1";
        
        for(int i=1; i<color.size(); i+=2){
            if(color[i]=='0'){
                b=dis(color, i, (char)(color[i]));
                c=dis(color, i, (char)(color[i]+1));
                if(b<c){
                    rt.push_back(color[i]);
                    rt.push_back(color[i]);
                }else{
                    rt.push_back((char)(color[i]+1));
                    rt.push_back((char)(color[i]+1));
                }
            }else if(color[i]=='f'){
                a=dis(color, i, (char)(color[i]-1));
                b=dis(color, i, (char)(color[i]));
                if(a<b){
                    rt.push_back(color[i]-1);
                    rt.push_back(color[i]-1);                    
                }else{
                    rt.push_back(color[i]);
                    rt.push_back(color[i]);
                }
            }else if(color[i]=='9'){
                a=dis(color, i, (char)(color[i]-1));
                b=dis(color, i, (char)(color[i]));
                c=dis(color, i, 'a');
                if(a<b){
                    if(a<c){
                        rt.push_back(color[i]-1);
                        rt.push_back(color[i]-1);
                    }else{
                        rt.push_back('a');
                        rt.push_back('a');
                    }    
                }else{
                    if(b<c){
                        rt.push_back(color[i]);
                        rt.push_back(color[i]);
                    }else{
                        rt.push_back('a');
                        rt.push_back('a');
                    }    
                } 
            }else if(color[i]=='a'){
                a=dis(color, i, '9');
                b=dis(color, i, (char)(color[i]));
                c=dis(color, i, (char)(color[i]+1));
                if(a<b){
                    if(a<c){
                        rt.push_back('9');
                        rt.push_back('9');
                    }else{
                        rt.push_back((char)(color[i]+1));
                        rt.push_back((char)(color[i]+1));
                    }    
                }else{
                    if(b<c){
                        rt.push_back(color[i]);
                        rt.push_back(color[i]);
                    }else{
                        rt.push_back((char)(color[i]+1));
                        rt.push_back((char)(color[i]+1));
                    }    
                }
            }else{
                a=dis(color, i, (char)(color[i]-1));
                b=dis(color, i, (char)(color[i]));
                c=dis(color, i, (char)(color[i]+1));
                if(a<b){
                    if(a<c){
                        rt.push_back(color[i]-1);
                        rt.push_back(color[i]-1);
                    }else{
                        rt.push_back((char)(color[i]+1));
                        rt.push_back((char)(color[i]+1));
                    }    
                }else{
                    if(b<c){
                        rt.push_back(color[i]);
                        rt.push_back(color[i]);
                    }else{
                        rt.push_back((char)(color[i]+1));
                        rt.push_back((char)(color[i]+1));
                    }    
                }                
            }
        }
        return rt;
    }
    
    int dis(string& s, int loc, char c){
        int d1=he2it(s, loc), d2=0, t;
        
        t=c-'0';
        if(-1<t&&t<10){
            d2=t*16+t;
        }else{
            t=c-'a';
            d2=(t+10)*16+t+10;
        }    
        
        return (d1-d2)*(d1-d2);
    }
    
    int he2it(string& s, int loc){// hexadecimal to int
        int dg=0, t;
        
        t=s[loc]-'0';
        if(-1<t&&t<10){
            dg+=t*16;
        }else{
            t=s[loc]-'a';
            dg+=(t+10)*16;
        }    
        
        t=s[loc+1]-'0';
        if(-1<t&&t<10){
            dg+=t;
        }else{
            t=s[loc+1]-'a';
            dg+=t+10;
        }    
        
        return dg;
    }  
};
