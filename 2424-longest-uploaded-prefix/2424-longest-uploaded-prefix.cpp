class LUPrefix {
public:
    int size;
    vector<int> videos;
    vector<int> leftBlockIndex;
    vector<int> rightBlockIndex;
    
    LUPrefix(int n) {
        size = n;
        videos.resize(size + 1, -1);
        leftBlockIndex.resize(size + 1);
        rightBlockIndex.resize(size + 1);
    }
    
    void upload(int video) {
        int leftEnd = -1;
        int rightEnd = -1;
        
        if (video != 1 && video != size && videos[video - 1] != -1 && videos[video + 1] != -1) {
            leftEnd = leftBlockIndex[video - 1];
            rightEnd = rightBlockIndex[video + 1];
        } else if (video != size && videos[video + 1] != -1) {
            leftEnd = video;
            rightEnd = rightBlockIndex[video + 1];
        } else if (video != 1 && videos[video -  1] != -1) {
            leftEnd = leftBlockIndex[video - 1];
            rightEnd = video;
        } else {
            leftEnd = video;
            rightEnd = video;
        }
        
        rightBlockIndex[leftEnd] = rightEnd;
        leftBlockIndex[rightEnd] = leftEnd;
        videos[video] = 1;
    }
    
    int longest() {
        return rightBlockIndex[1];
    }
};

/**
 * Your LUPrefix object will be instantiated and called as such:
 * LUPrefix* obj = new LUPrefix(n);
 * obj->upload(video);
 * int param_2 = obj->longest();
 */

// TC: O(total number of calls to upload() and longest())
// SC: O(n)