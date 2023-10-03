#include<iostream>
#include<string>
#include<stack>

using namespace std;

bool checkchar(char c){

    if(c >= 'a' && c <= 'z'){
        return 1;
    }
    return 0;

}

string convert(string s){
    stack<string> st;
    string output;
    string temp;
    char c;

    for(int i = 0; i < s.length(); i++){
        c = s[i];
        if(st.empty() || (checkchar(c))){
            temp = c;
            st.push(temp);
        }
        else if(c == '+' || c == '-' || c == '*' || c == '/'){
            string op1 = st.top();
            st.pop();
            string op2 = st.top();
            st.pop();

            temp = '(' + op2 + c + op1 +')';
            st.push(temp);
        }
    }

    output = st.top();
    return output;
}

int main(){

    string a = "abcd+ef+-*+";

    a = convert(a);

    cout << a;


}