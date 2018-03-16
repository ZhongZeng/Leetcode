
/*

Leetcode 360. Sort Transformed Array

Companies 
Google
Related Topics 
Math, Two Pointers 

Next challenges: Strobogrammatic Number III, Super Pow, Candy Crush

Test Cases:
[-4,-2,2,4]
1
3
5
[-4,-2,2,4]
-1
3
5
[-95,-95,-93,-92,-89,-89,-88,-82,-81,-79,-71,-71,-66,-66,-65,-65,-62,-61,-60,-54,-54,-51,-50,-48,-47,-45,-43,-37,-35,-35,-32,-32,-29,-24,-24,-22,-20,-20,-17,-14,-13,-12,-12,-4,1,8,11,14,16,16,22,24,26,28,28,28,29,30,31,36,44,46,49,60,60,60,62,64,65,73,76,86,87,89,91,92,93,94,94,96,96,97]
41
45
-89
[-4,-2,2,4]
0
3
5

Runtime: 12 ms
Your runtime beats 26.15 % of cpp submissions.

*/

class Solution {
public:
    vector<int> sortTransformedArray(vector<int>& nums, int a, int b, int c) {
        // math
        if(nums.size()<2)   return nums;
        
        if(a<0){
            double md=0-b/2.0/a; 
            if(nums.back()<md){
                return func(nums, a, b, c);
            }else if(md<nums[0]){
                return rev(nums, a, b, c);
            }else{
                int i=0, j=nums.size()-1, im=a*nums[i]*nums[i]+b*nums[i]+c, jm=a*nums[j]*nums[j]+b*nums[j]+c;
                vector<int> rt;
                while( i<j ){
                    if(im<jm){
                        rt.push_back(im);
                        i++;
                        im=a*nums[i]*nums[i]+b*nums[i]+c;
                    }else{
                        rt.push_back(jm);
                        j--;
                        jm=a*nums[j]*nums[j]+b*nums[j]+c;
                    }
                }
                rt.push_back(a*nums[i]*nums[i]+b*nums[i]+c);
                return rt;
            }
        }else if(0<a){
            double md=0-b/2.0/a; 
            if(nums.back()<md){
                return rev(nums, a, b, c);
            }else if(md<nums[0]){
                return func(nums, a, b, c);
            }else{
                int i=0, j=nums.size()-1, im=a*nums[i]*nums[i]+b*nums[i]+c, jm=a*nums[j]*nums[j]+b*nums[j]+c;
                vector<int> rt;
                while( i<j ){
                    if(im>jm){
                        rt.push_back(im);
                        i++;
                        im=a*nums[i]*nums[i]+b*nums[i]+c;
                    }else{
                        rt.push_back(jm);
                        j--;
                        jm=a*nums[j]*nums[j]+b*nums[j]+c;
                    }
                }
                rt.push_back(a*nums[i]*nums[i]+b*nums[i]+c);
                return rev(rt);
            }            
        }else{
            if(b<0){
                return rev(nums, b, c);
            }else if(0<b){
                return func(nums, b, c);
            }else{
                vector<int> rt( nums.size(), c);
                return rt;
            }
        }
    }
    
protected:    
    vector<int> rev(vector<int>& nums){
        vector<int> vc;
        for(int i=nums.size()-1; -1<i; i--) vc.push_back(nums[i]);
        return vc;
    }    
    
    vector<int> func(vector<int>& nums, int& a, int& b, int& c){
        vector<int> vc;
        for(int i=0; i<nums.size(); i++)    vc.push_back(a*nums[i]*nums[i]+b*nums[i]+c);
        return vc;
    }
    
    vector<int> rev(vector<int>& nums, int& a, int& b, int& c){
        vector<int> vc;
        for(int i=nums.size()-1; -1<i; i--) vc.push_back(a*nums[i]*nums[i]+b*nums[i]+c);
        return vc;
    }
    
    vector<int> func(vector<int>& nums, int& b, int& c){
        vector<int> vc;
        for(int i=0; i<nums.size(); i++)    vc.push_back(b*nums[i]+c);
        return vc;
    }  
    
    vector<int> rev(vector<int>& nums, int& b, int& c){
        vector<int> vc;
        for(int i=nums.size()-1; -1<i; i--) vc.push_back(b*nums[i]+c);
        return vc;
    }    
};

