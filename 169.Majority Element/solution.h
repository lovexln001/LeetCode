int majorityElement(int num[], int n) {
    int cnt = 0, res;
    for (int i = 0; i < n; ++i) {
        if (cnt == 0) res = num[i];
        if (res == num[i]) ++cnt;
        else --cnt;
    }
    return res;
}