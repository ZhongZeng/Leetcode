
/*
Leetcode 681. Next Closest Time

Companies 
Google
Related Topics 
String 

Next challenges: Group Shifted Strings, 
Encode and Decode Strings, Valid Word Abbreviation

Test Cases:
"12:11"
"13:57"

Runtime: 5 ms
Your runtime beats 12.33 % of cpp submissions.

*/

class Solution {
public:
    string nextClosestTime(string time) {
        // format "HH:MM"; greedy 
        vector<int> vc={time[0]-'0',time[1]-'0',time[3]-'0',time[4]-'0'};
        int i, mn=vc[0], lg;
        for( i=1; i<4; i++) mn=vc[i]<mn?vc[i]:mn;
        
		// M2 
        for( i=0; i<4; i++) if(vc[3]<vc[i]){lg=vc[i];break;}
        for( ; i<4; i++)    if(vc[3]<vc[i]&&vc[i]<lg)    lg=vc[i];
        if(vc[3]<lg){
            time[4]=(char)(lg+'0');
            return time;
        }
        
        // M1 
        for( i=0; i<4; i++) if(vc[2]<vc[i]&&vc[i]<6){lg=vc[i];break;}
        for( ; i<4; i++)    if(vc[2]<vc[i]&&vc[i]<6&&vc[i]<lg)  lg=vc[i];
        if(vc[2]<lg&&lg<6){
            time[3]=(char)(lg+'0');
            time[4]=(char)(mn+'0');
            return time;
        }

        if(time[0]!='2'){// =='0'||=='1'
        // H2 
            for( i=0; i<4; i++) if(vc[1]<vc[i]){lg=vc[i];break;}
            for( ; i<4; i++)    if(vc[1]<vc[i]&&vc[i]<lg)    lg=vc[i];
            if(vc[1]<lg){
                time[1]=(char)(lg+'0');
                time[3]=(char)(mn+'0');
                time[4]=(char)(mn+'0');
                return time;
            }
        // H1 
            for( i=0; i<4; i++)    if(vc[i]==2)    lg=vc[i];
            if(lg==2){
                time[0]=(char)(lg+'0');
                time[1]=(char)(mn+'0');
                time[3]=(char)(mn+'0');
                time[4]=(char)(mn+'0');
                return time;
            }        
        }else{// time[0]=='2'
        // H2 
            for( i=0; i<4; i++) if(vc[1]<vc[i]&&vc[i]<5){lg=vc[i];break;}
            for( ; i<4; i++)    if(vc[1]<vc[i]&&vc[i]<lg&&vc[i]<5)   lg=vc[i];
            if(vc[1]<lg&&lg<5){
                time[1]=(char)(lg+'0');
                time[3]=(char)(mn+'0');
                time[4]=(char)(mn+'0');
                return time;
            }                
        }
        
        time[0]=(char)(mn+'0');
        time[1]=(char)(mn+'0');
        time[3]=(char)(mn+'0');
        time[4]=(char)(mn+'0');
        
        return time;
    }
};