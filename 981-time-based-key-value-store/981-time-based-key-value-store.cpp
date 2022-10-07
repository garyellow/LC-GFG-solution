class TimeMap {
public:
    vector<tuple<int, string, string>> data;
    TimeMap() {

    }

    void set(string key, string value, int timestamp) {
        data.push_back({timestamp, value, key});
    }

    string get(string key, int timestamp) {
        for(int i = data.size() - 1; i >= 0;i--){
            if(std::get<2>(data[i]) == key && std::get<0>(data[i]) <= timestamp){
                return std::get<1>(data[i]);
            }
        }
        return "";
    }
};

/**
 * Your TimeMap object will be instantiated and called as such:
 * TimeMap* obj = new TimeMap();
 * obj->set(key,value,timestamp);
 * string param_2 = obj->get(key,timestamp);
 */