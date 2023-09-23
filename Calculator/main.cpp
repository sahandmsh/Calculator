#include <iostream>
#include <string>
#include <stack>
using namespace std;

int calculator(string s){
    stack<int> operands;
    int i=-1, ans=0;
    if (s.size() == 0){return 0;}
    if (s[0]>='0' && s[0] <='9'){s.insert(s.begin(),'+');}
    while (++i<s.size()){
        if (s[i] == '*'){
            int x = operands.top();
            operands.pop();
            int y = static_cast<int>(s[++i]-48);
            operands.push(x*y);
        }
        else{
            int sgn = (s[i]=='+')?1:-1;
            operands.push(sgn* (static_cast<int>(s[++i])-48) );
        }
    }
    while (operands.size()){
        ans += operands.top();
        operands.pop();
    }
    return ans;
}

int main(int argc, const char * argv[]) {
    string s1="1+2-3-4*5*2-3+4";
    cout<<s1<<"= "<<calculator_stack(s1)<<endl;
}
