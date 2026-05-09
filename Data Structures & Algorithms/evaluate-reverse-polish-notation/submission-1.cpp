class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        stack<int> st;
        for(int i = 0;i<tokens.size();i++){
            if(tokens[i] == "+"){
                int a = st.top(); st.pop();
                int b = st.top(); st.pop();
                int res = a+b;
                st.push(res);
            }else if(tokens[i] == "-"){
                int a = st.top(); st.pop();
                int b = st.top(); st.pop();
                int res = b-a;
                st.push(res);
            }else if(tokens[i] == "*"){
                int a = st.top(); st.pop();
                int b = st.top(); st.pop();
                int res = a*b;
                st.push(res);
            }else if(tokens[i] == "/"){
                int a = st.top(); st.pop();
                int b = st.top(); st.pop();
                int res = b/a;
                st.push(res);
            }else{
                try{
                    int val = stoi(tokens[i]);
                    st.push(val);
                }catch (const invalid_argument& e) {
                    cerr << "Invalid input: " << e.what() <<endl;
                } catch (const std::out_of_range& e) {
                    cerr << "Number out of range: " << e.what() << endl;
                }
            }
        }
        return st.top();
    }
};
