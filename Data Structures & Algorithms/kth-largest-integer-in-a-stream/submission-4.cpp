class KthLargest {
private:
    int k_;
    std::priority_queue<int, std::vector<int>, std::greater<int>> pq;

public:
    KthLargest(int k, std::vector<int> &nums) 
        : k_{k} {
        for (int &num : nums) {
            if (pq.size() < k_) {
                pq.push(num);
            } else {
                if (num > pq.top()) {
                    pq.pop();
                    pq.push(num);
                }
            }
        }
    }
    
    int add(int val) {
        if (pq.size() < k_) {
            pq.push(val);
        } else if (val > pq.top()) {
            pq.pop();
            pq.push(val);
        } 

        return pq.top();
    }
};
