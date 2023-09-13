#include <iostream>
#include <map>
#include <string>
using namespace std;

class Solution{
    /*
    * mult_func gets a string including numbers, and +, - , * operations.
     Then, it takes care of multiplications.
     * The +,- operations are then calculated by the summation function.
     * to_int function converts a char to its equivalent int calue.
    */
    void mult_func(string&);
    int summation(string&);
    int to_int(char);
public:
    int calculate(string);
};


int Solution::to_int(char c){
    return static_cast<int>(c)-48;
}

void Solution::mult_func(string& s){
    int l,h,m,i=0, num1,num2;
    while(i<size(s)){
        if (s[i] == '*'){
            m = i;
            l = i-1;
            while (true){
                if (l== 0 || s[l]=='+' || s[l]=='-'||s[l]=='*'){break;}
                else{--l;}
            }
            h = i+1;
            while (true){
                if (h>=s.size()-1 || s[h]=='+' || s[h]=='-' || s[h]=='*'){break;}
                else{++h;}
            }
            if (l!=0){++l;}
            if (h!=size(s)-1){--h;}
            num1 = 0;
            num2 = 0;
            for (int j=l;j<m;++j){
                num1 = num1*10 + to_int(s[j]);
            }
            for (int j=m+1;j<=h;++j){
                num2 = num2*10 + to_int(s[j]);
            }
            s.erase(s.begin()+l,s.begin()+h+1);
            s.insert(l,to_string(num1*num2));
            i = h-1;
        }
        ++i;
    }
}

int Solution::summation(string &s){
    if (s.size()==0){
        return 0;
    }
    int i=0, num=0, sgn=1;
    if (s[0]=='-'){
        sgn = -1;
        ++i;
    }
    else if (s[0]=='+'){++i;}
    while (s[i]!='+' && s[i] != '-' && i<s.size()){
        num = num*10 + to_int(s[i]);
        ++i;
    }
    if (i<s.size()){
        s.erase(s.begin(),s.begin()+i);
        return sgn*num + summation(s);
    }
    return sgn*num;
}

int Solution::calculate(string s){
    mult_func(s);
    return summation(s);
}

#include <iostream>

int main(int argc, const char * argv[]) {
    string s1="1+2-3-4*5*2-3+4";
    Solution S;
    cout<<s1<<"= "<<S.calculate(s1)<<endl;
    
}
