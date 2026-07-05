class Solution {
public:
    bool isPalindrome(string s) {
        int st = 0;
        int end = s.length() - 1;
        
        while (st < end) { // '<=' ki jagah '<' bhi chalega kyunki single element humesha palindrome hota hai
            
            // FIX 1: Jab tak 'st < end' hai, sirf tabhi tak skip karo!
            if (st < end && !isalnum(s[st])) {
                st++;
            }
            // FIX 2: Jab tak 'st < end' hai, sirf tabhi tak end ko peeche lao!
            else if (st < end && !isalnum(s[end])) {
                end--;
            }
            else {
                if (tolower(s[st]) != tolower(s[end])) {
                    return false;
                }
                st++;
                end--;
            }
        }
        return true;
    }
};