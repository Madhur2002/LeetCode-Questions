class Solution {
public:
    bool detectCapitalUse(string word) {
        int countCapital = 0;
        for(char ch: word){
            if(isupper(ch)) countCapital++;
        }
        if(countCapital == word.size() || countCapital == 1 && isupper(word[0]) || countCapital == 0) return true;
        return false;
        // return true;
    }
};