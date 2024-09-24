class Solution {
public:
    int strStr(string haystack, string needle) {
        if (needle.empty()) return 0; // If needle is empty, return 0.
    size_t pos = haystack.find(needle);
    return (pos != string::npos) ? pos : -1; // Return the index or -1 if not found.
    }
};