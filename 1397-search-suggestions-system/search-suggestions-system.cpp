class Solution {
public:
    vector<vector<string>> suggestedProducts(vector<string>& products,
                                             string searchWord) {

        sort(products.begin(), products.end());

        vector<vector<string>> ans;
        string prefix = "";

        for(char ch : searchWord) {

            prefix += ch;

            auto it = lower_bound(products.begin(),
                                  products.end(),
                                  prefix);

            vector<string> curr;

            for(int i = 0; i < 3 && it + i != products.end(); i++) {

                string word = *(it + i);

                if(word.substr(0, prefix.size()) == prefix)
                    curr.push_back(word);
                else
                    break;
            }

            ans.push_back(curr);
        }

        return ans;
    }
};