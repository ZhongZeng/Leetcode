
/*
Leetcode 735. Asteroid Collision

Related Topics 
Stack 
Similar Questions 
Can Place Flowers 

Next challenges: Largest Rectangle in Histogram, 
Basic Calculator, Tag Validator

Runtime: 29 ms
Sorry. We do not have enough accepted submissions to show runtime distribution chart.

*/

class Solution {
public:
    vector<int> asteroidCollision(vector<int>& asteroids) {
        // Each asteroid will be a non-zero integer in the range [-1000, 1000].
        stack<int> si;
        vector<int> vc;
        int c;
        for(vector<int>::iterator it=asteroids.begin(); it!=asteroids.end(); it++){
            // can't traverse: ex. [-2,2,-1,1]
            if(si.empty()){
                si.push(*it);
            }else{
                if( 0<si.top() && *it<0 ){                    
                    while( !si.empty() ){
                        if(0<si.top()){
                            if( *it+si.top()<0 ){
                                si.pop();
                            }else if( 0<*it+si.top() ){
                                break;
                            }else{
                                si.pop();
                                *it=0;
                                break;
                            }                            
                        }else{
                            si.push(*it);
                            break;
                        }                    
                    }    
                    if(si.empty()&&*it!=0)  si.push(*it);
                }else{
                    si.push(*it);
                }
            }
        }
        
        while(!si.empty()){
            vc.push_back(si.top());
            si.pop();
        }
        
        for(int i=0, j=vc.size()-1; i<j; i++, j--){
            c=vc[i];
            vc[i]=vc[j];
            vc[j]=c;
        }
        
        return vc;
    }
};