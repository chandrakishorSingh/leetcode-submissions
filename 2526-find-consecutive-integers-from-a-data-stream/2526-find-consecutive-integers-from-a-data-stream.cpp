class DataStream {
public:
    int k;
    int freq;
    int value;
    
    DataStream(int value, int k) {
        this->freq = 0;
        this->value = value;
        this->k = k;
    }
    
    bool consec(int num) {
        if (num == this->value) {
            this->freq = min(this->freq + 1, k);
        } else {
            this->freq = 0;
        }
        
        return this->freq == this->k;
    }
};

/**
 * Your DataStream object will be instantiated and called as such:
 * DataStream* obj = new DataStream(value, k);
 * bool param_1 = obj->consec(num);
 */

// TC: O(1), all methods
// SC: O(1), all methods