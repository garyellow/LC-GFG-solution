class TimeMap {
public:
    vector<pair<pair<int,string>,string>>vp;
TimeMap() {
    
}

void set(string key, string value, int timestamp) {
    vp.push_back({{timestamp,value},key});
}

string get(string key, int timestamp) {
    for(int i=vp.size()-1;i>=0;i--){
        if(vp[i].second==key && vp[i].first.first<=timestamp){
            return vp[i].first.second;
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