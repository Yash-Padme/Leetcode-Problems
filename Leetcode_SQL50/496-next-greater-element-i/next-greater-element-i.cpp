class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        stack<int> s;
        unordered_map<int, int> nextGreater;

        // Find next greater element for nums2
        for (int i = nums2.size() - 1; i >= 0; i--) {
            int curr = nums2[i];

            while (!s.empty() && curr >= s.top()) {
                s.pop();
            }

            if (s.empty()) {
                nextGreater[curr] = -1;
            } else {
                nextGreater[curr] = s.top();
            }

            s.push(curr);
        }

        // Build answer for nums1
        vector<int> ans;

        for (int num : nums1) {
            ans.push_back(nextGreater[num]);
        }

        return ans;
    }
};