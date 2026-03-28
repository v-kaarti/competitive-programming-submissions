class CoverSquare {
public:
    vector<int> cover(int s, vector<int> blankets) {
        sort(blankets.begin(), blankets.end(), greater<int>());
        if (blankets[0] >= s) return {0, 0};
        vector<int> r;
        int cy = 0, idx = 0;
        while (cy < s && idx < blankets.size()) {
            int cx = 0;
            int lbs = 0, rsidx = idx;
            while (cx < s && idx < blankets.size()) {
                int sidel = blankets[idx];
                cx += sidel;
                lbs = max(lbs, sidel);
                idx++;
            }
            cx = 0;
            for (int i = rsidx; i < idx; i++) {
                r.push_back(cx), r.push_back(cy);
                cx += blankets[i];
            }
            cy += lbs;
        }
        return r;
    }
};