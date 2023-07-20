class Solution {
public:
    vector<int> asteroidCollision(vector<int>& asteroids) {
        vector<int> st;
        
        for(auto &&asteroid : asteroids) {
            if(st.empty()) {
                st.push_back(asteroid);
            }
            else {
                bool destory = false;
                while(st.size()) {
                    if(st.back() < 0 || asteroid > 0) {
                        break;
                    }
                    else {
                        if(st.back() > abs(asteroid)) {
                            destory = true;
                            break;
                        }
                        else if(st.back() == abs(asteroid)) {
                            st.pop_back();
                            destory = true;
                            break;
                        }
                        else {
                            st.pop_back();
                        }
                    }
                }
                if(!destory) st.push_back(asteroid);
            }
        }
        
        return st;
    }
};