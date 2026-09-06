class Solution {
public:
    vector<int> asteroidCollision(vector<int>& asteroids) {

        stack<int> st;

        for(int asteroid : asteroids)
        {
            bool alive = true;

            while(alive &&
                  !st.empty() &&
                  st.top() > 0 &&
                  asteroid < 0)
            {
                if(abs(asteroid) > st.top())
                {
                    st.pop();
                }
                else if(abs(asteroid) == st.top())
                {
                    st.pop();
                    alive = false;
                }
                else
                {
                    alive = false;
                }
            }

            if(alive)
                st.push(asteroid);
        }

        vector<int> ans(st.size());

        for(int i = st.size()-1; i >= 0; i--)
        {
            ans[i] = st.top();
            st.pop();
        }

        return ans;
    }
};

