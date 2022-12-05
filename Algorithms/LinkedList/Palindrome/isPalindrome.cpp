// Problem Link : https://leetcode.com/problems/palindrome-number/solution/
// Solution Number 1 By Converting to String 

// Time Complexity : O(n)
// Space Comlexity : O(1)

class Solution {
public:
    bool isPalindrome(int x) {

        int i = 0 ;
        string s = to_string(x);
        int k = s.length();

        if (k <1)
            return true;
        
        
        while(k){
            if (s[i] != s[k-1])
                return false;
            k--;
            i++;
        }   
        
        return true;
    }
};


////////////////////////////////////////////////////////////


// Solution Number two By Math :

// Time Complexity : O(log10(n))
// Space Comlexity : O(1)

class Solution {
     bool IsPalindrome(int x) {
        if(x < 0 || (x % 10 == 0 && x != 0)) {
            return false;
        }

        int revertedNumber = 0;
        while(x > revertedNumber) {
            revertedNumber = revertedNumber * 10 + x % 10;
            x /= 10;
        }

        return x == revertedNumber || x == revertedNumber/10;
    }
}