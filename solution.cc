// Given s1, s2, s3, find whether s3 is formed by the interleaving of s1 and s2.

// For example,
// Given:
// s1 = "aabcc",
// s2 = "dbbca",

// When s3 = "aadbbcbcac", return true.
// When s3 = "aadbbbaccc", return false.

class Solution {
public:
    bool isInterleave(string s1, string s2, string s3) {
        int n1 = s1.size();
        int n2 = s2.size();
        int n3 = s3.size();
        if(n1 == 0) return (s2 == s3);
        if(n2 == 0) return (s1 == s3);
        if(n1+n2 != n3) return false;
        
        vector<bool> table(n2+1, false);
        table[0] = true;
        for(int i = 1; i <= n2; ++i) {
            table[i] = (s3[i-1] == s2[i-1]) && table[i-1];
        }
        for(int i = 0; i < n1; ++i) {
            table[0] = table[0] && (s3[i] == s1[i]);
            for(int j = 1; j <= n2; ++j) {
                table[j] = ((s3[i+j] == s1[i]) && table[j]) || ((s3[i+j] == s2[j-1]) && table[j-1]);
            }
        }
        return table[n2];
    }
};
