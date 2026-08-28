class Solution {
public:

    bool isVowel(char c)
    {
        return c=='a' ||
               c=='e' ||
               c=='i' ||
               c=='o' ||
               c=='u';
    }

    int maxVowels(string s, int k) {

        int count = 0;

        // First window
        for(int i = 0; i < k; i++)
        {
            if(isVowel(s[i]))
                count++;
        }

        int ans = count;

        // Slide window
        for(int i = k; i < s.length(); i++)
        {
            if(isVowel(s[i-k]))
                count--;

            if(isVowel(s[i]))
                count++;

            ans = max(ans, count);
        }

        return ans;
    }
};