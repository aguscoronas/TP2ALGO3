#ifndef DISJOINT_SET
#define DISJOINT_SET

#include <vector>

class DisjointSet {
    const int none = -1;
    //p = partent, s = size
    std::vector<int> p, s;
public:
    DisjointSet(int n) {
        p.assign(n, none); s.assign(n, 1);
    }
    
    int find(int i) {
        return p[i] == none ? i : (p[i] = find(p[i]));
    }
    
    void unite(int i, int j) {
        using std::swap;
        i = find(i); j = find(j);
        if(i != j) {
          if(s[i] < s[j]) swap(i, j);
          s[i] += s[j];
          p[j] = i;
        }
    }
};

#endif //DISJOINT_SET
