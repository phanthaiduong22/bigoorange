#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

typedef struct block {
    int dimension[3];

    block (int x, int y, int z) {
        dimension[0] = x; 
        dimension[1] = y; 
        dimension[2] = z;
    }
    
    bool CanStack (const struct block& other) {
        if (dimension[0] < other.dimension[0] && dimension[1] < other.dimension[1]) return true;
        return false;
    }

    bool operator < (const block &x) const {
		for (int i = 0; i < 3; ++i) {
            if (dimension[i] > x.dimension[i]) 
                return true;
            else if (dimension[i] < x.dimension[i])
                return false;
        }
        return true;
	}
} block;

void GetBlocks(vector<block>& blocks, int a, int b, int c) {
    int arr[] = {a, b, c};
    sort(arr, arr + 3);
    do {
        blocks.push_back(block(arr[0], arr[1], arr[2]));
    }
    while (next_permutation(arr, arr + 3));
}

int LIS(vector<block>& blocks) {
    int res = 0;
    vector<int> height(blocks.size());
    for (int i = 0; i < blocks.size(); ++i) {
        height[i] = blocks[i].dimension[2];
        for (int j = 0; j < i; ++j) {
            if (blocks[i].CanStack(blocks[j]))
                height[i] = max(height[i], height[j] + blocks[i].dimension[2]);
        }
        res = max(res, height[i]);
    }
    return res;
}

int main() {
    freopen("input.inp","r",stdin);
    freopen("output.out","w",stdout);
	int n, a, b, c, cases = 1;
	cin >> n;

	while (n != 0) {
		vector<block> blocks;
		for (int i = 0; i < n; ++i) {
			cin >> a >> b >> c;
			GetBlocks(blocks, a, b, c);
		}
        sort(blocks.begin(), blocks.end());
        
		cout << "Case " << cases++ << ": maximum height = " << LIS(blocks) << endl;
		cin >> n;
	}

	return 0;
}