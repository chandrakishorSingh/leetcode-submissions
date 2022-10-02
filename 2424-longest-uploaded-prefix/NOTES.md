if (size[a] < size[b]) swap(a, b);
​
parent[b] = a;
size[a] += size[b];
components--;
}
​
int find(int a) {
if (a == parent[a]) return a;
​
int root = find(parent[a]);
parent[a] = root;
​
return root;
}
};
​
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