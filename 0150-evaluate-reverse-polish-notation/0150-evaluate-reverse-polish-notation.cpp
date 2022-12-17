class Solution {
private:
    int Operate(int a, int b, string token){
        if(token == "+"){
            return a + b;
        }
        if(token == "-"){
            return b - a;
        }
        if(token == "*"){
            return long(a) * long(b);
        }
        if(token == "/"){
            return b / a;
        }
        return -1;
    }
public:
    int evalRPN(vector<string>& s) {
        stack<int>st;
        for(int i=0; i<s.size(); i++){
            if(s[i] == "+" || s[i] == "-" || s[i] == "*" || s[i] == "/"){
                int x = st.top();
                st.pop();
                int y = st.top();
                st.pop();
                int result = Operate(x, y, s[i]);
                st.push(result);
            }else{
                st.push(stoi(s[i]));
            }
        }
        return st.top();
    }
};