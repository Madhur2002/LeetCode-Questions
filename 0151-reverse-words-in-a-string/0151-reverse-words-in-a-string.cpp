class Solution {
public:
    string reverseWords(string s) {
        int i=0;
        int n = s.size();
        string result;
        while(i<n){
            while(i<n && s[i] == ' '){
                i++;
            }
            if(i>=n) break;
            int j = i+1;
            cout<<i<<" "<<j<<" ";
            while(j<n && s[j] != ' '){
                j++;
            }
            cout<<endl;
            cout<<j<<" ";
            string word = s.substr(i,j-i);
            if(result.length() == 0) result = word;
            else{
                result = word + " " + result;
            }
            i = j+1;
            cout<<result;
        }
        return result;
    }
};