class SmallestInfiniteSet {
private:
    int current;

    priority_queue<int, vector<int>, greater<int>> minHeap;

    unordered_set<int> present;

public:
    SmallestInfiniteSet() {
        current = 1;
    }

    int popSmallest() {

        if (!minHeap.empty()) {
            int num = minHeap.top();
            minHeap.pop();
            present.erase(num);
            return num;
        }

        return current++;
    }

    void addBack(int num) {

        if (num < current && present.find(num) == present.end()) {
            minHeap.push(num);
            present.insert(num);
        }
    }
};