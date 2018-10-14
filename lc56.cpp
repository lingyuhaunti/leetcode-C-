#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

struct Interval {
    int start;
    int end;
    Interval() : start(0), end(0) {}
    Interval(int s, int e) : start(s), end(e) {}
};

struct cmp {
    bool operator()(const Interval &in1, const Interval &in2) {
        return in1.start < in2.start;
    }
};

class Solution {
public:
    vector<Interval> merge(vector<Interval>& intervals) {
        sort(intervals.begin(), intervals.end(), cmp());
        vector<Interval> res(intervals.begin(), intervals.end());
        return res;
    }
};

int main()
{
    return 0;
}
