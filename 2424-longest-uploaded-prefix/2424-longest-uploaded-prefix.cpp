class UF {
 public:
  vector<int> parent;
  vector<int> size;
  int components;

  UF(int n) {
    parent.resize(n + 1);
    size.resize(n + 1, 1);
    components = n;

    for (int i = 1; i <= n; i++) {
      parent[i] = i;
    }
  }

  void unite(int a, int b) {
    a = find(a);
    b = find(b);

    if (a == b) return;

    if (size[a] < size[b]) swap(a, b);

    parent[b] = a;
    size[a] += size[b];
    components--;
  }

  int find(int a) {
    if (a == parent[a]) return a;

    int root = find(parent[a]);
    parent[a] = root;

    return root;
  }

  set<int> getRepresentatives() {
    set<int> representatives;
    for (int i = 1; i <= parent.size() - 1; i++)
      representatives.insert(find(i));

    return representatives;
  }
};

class LUPrefix {
public:
    int size;
    UF* uf;
    vector<int> videoIndex;
    
    LUPrefix(int n) {
        size = n;
        
        uf = new UF(n + 1);
        
        videoIndex.resize(n + 2);
        videoIndex[1] = 1;
    }
    
    void upload(int video) {
        videoIndex[video + 1] = 1;
        
        if (videoIndex[video] == 1) {
            uf->unite(video + 1, video);
        }
        
        if (video != size && videoIndex[video + 2]) {
            uf->unite(video + 1, video + 2);
        }
    }
    
    int longest() {
        return uf->size[uf->find(1)] - 1;
    }
};

/**
 * Your LUPrefix object will be instantiated and called as such:
 * LUPrefix* obj = new LUPrefix(n);
 * obj->upload(video);
 * int param_2 = obj->longest();
 */

// TC: O(n * noOfQueries)
// SC: O(n)