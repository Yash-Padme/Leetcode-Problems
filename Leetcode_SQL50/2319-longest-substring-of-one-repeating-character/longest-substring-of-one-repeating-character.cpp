struct SegmentTreeNode {
    int lo;
    int hi;

    char maxLetter;
    char prefixLetter;
    char suffixLetter;

    int maxLength;
    int prefixLength;
    int suffixLength;

    SegmentTreeNode* left;
    SegmentTreeNode* right;

    SegmentTreeNode(
        int lo,
        int hi,
        char maxLetter,
        char prefixLetter,
        char suffixLetter,
        int maxLength,
        int prefixLength,
        int suffixLength,
        SegmentTreeNode* left = nullptr,
        SegmentTreeNode* right = nullptr
    )
        : lo(lo),
          hi(hi),
          maxLetter(maxLetter),
          prefixLetter(prefixLetter),
          suffixLetter(suffixLetter),
          maxLength(maxLength),
          prefixLength(prefixLength),
          suffixLength(suffixLength),
          left(left),
          right(right) {}

    ~SegmentTreeNode() {
        delete left;
        delete right;
    }
};


class SegmentTree {
public:

    explicit SegmentTree(const string& s) {
        root = build(s, 0, s.length() - 1);
    }

    ~SegmentTree() {
        delete root;
    }

    void update(int i, char val) {
        update(root, i, val);
    }

    int getMaxLength() {
        return root->maxLength;
    }

private:

    SegmentTreeNode* root;


    SegmentTreeNode* build(
        const string& s,
        int lo,
        int hi
    ) {

        if (lo == hi) {
            return new SegmentTreeNode(
                lo,
                hi,
                s[lo],
                s[lo],
                s[lo],
                1,
                1,
                1
            );
        }

        int mid = (lo + hi) / 2;

        SegmentTreeNode* left = build(s, lo, mid);
        SegmentTreeNode* right = build(s, mid + 1, hi);

        return merge(left, right);
    }


    void update(
        SegmentTreeNode* node,
        int i,
        char c
    ) {

        // Leaf node
        if (node->lo == node->hi) {

            node->maxLetter = c;
            node->prefixLetter = c;
            node->suffixLetter = c;

            return;
        }

        int mid = (node->lo + node->hi) / 2;

        if (i <= mid) {
            update(node->left, i, c);
        } else {
            update(node->right, i, c);
        }

        // Recalculate current node
        pull(node);
    }


    void pull(SegmentTreeNode* node) {

        SegmentTreeNode* left = node->left;
        SegmentTreeNode* right = node->right;


        // --------------------------------
        // Calculate maximum
        // --------------------------------

        if (left->maxLength >= right->maxLength) {
            node->maxLength = left->maxLength;
            node->maxLetter = left->maxLetter;
        } else {
            node->maxLength = right->maxLength;
            node->maxLetter = right->maxLetter;
        }

        // Check run crossing the middle
        if (left->suffixLetter == right->prefixLetter) {

            int combinedLength =
                left->suffixLength + right->prefixLength;

            if (combinedLength > node->maxLength) {
                node->maxLength = combinedLength;
                node->maxLetter = left->suffixLetter;
            }
        }


        // --------------------------------
        // Calculate prefix
        // --------------------------------

        node->prefixLetter = left->prefixLetter;
        node->prefixLength = left->prefixLength;

        if (left->prefixLength == left->hi - left->lo + 1 &&
            left->prefixLetter == right->prefixLetter) {

            node->prefixLength += right->prefixLength;
        }


        // --------------------------------
        // Calculate suffix
        // --------------------------------

        node->suffixLetter = right->suffixLetter;
        node->suffixLength = right->suffixLength;

        if (right->suffixLength == right->hi - right->lo + 1 &&
            right->suffixLetter == left->suffixLetter) {

            node->suffixLength += left->suffixLength;
        }
    }


    SegmentTreeNode* merge(
        SegmentTreeNode* left,
        SegmentTreeNode* right
    ) {

        char maxLetter;
        int maxLength;

        // Maximum from children
        if (left->maxLength >= right->maxLength) {
            maxLength = left->maxLength;
            maxLetter = left->maxLetter;
        } else {
            maxLength = right->maxLength;
            maxLetter = right->maxLetter;
        }

        // Maximum crossing the boundary
        if (left->suffixLetter == right->prefixLetter) {

            int combinedLength =
                left->suffixLength + right->prefixLength;

            if (combinedLength > maxLength) {
                maxLength = combinedLength;
                maxLetter = left->suffixLetter;
            }
        }


        // Prefix
        char prefixLetter = left->prefixLetter;
        int prefixLength = left->prefixLength;

        if (left->prefixLength == left->hi - left->lo + 1 &&
            left->prefixLetter == right->prefixLetter) {

            prefixLength += right->prefixLength;
        }


        // Suffix
        char suffixLetter = right->suffixLetter;
        int suffixLength = right->suffixLength;

        if (right->suffixLength == right->hi - right->lo + 1 &&
            right->suffixLetter == left->suffixLetter) {

            suffixLength += left->suffixLength;
        }


        return new SegmentTreeNode(
            left->lo,
            right->hi,
            maxLetter,
            prefixLetter,
            suffixLetter,
            maxLength,
            prefixLength,
            suffixLength,
            left,
            right
        );
    }
};


class Solution {
public:

    vector<int> longestRepeating(
        string s,
        string queryCharacters,
        vector<int>& queryIndices
    ) {

        vector<int> ans;

        SegmentTree tree(s);

        for (int i = 0; i < queryIndices.size(); ++i) {

            tree.update(
                queryIndices[i],
                queryCharacters[i]
            );

            ans.push_back(tree.getMaxLength());
        }

        return ans;
    }
};