vector<int> Solution::repeatedNumber(const vector<int> &A)
{
    int n = A.size();
    long long S = 0, S2 = 0;
    long long Sn = (n * (n + 1)) / 2;
    long long S2n = (n * (n + 1) * (2 * n + 1)) / 6;

    for (auto a : A)
    {
        S += (long long)a;
        S2 += (long long)a * (long long)a;
    }

    long long val1 = S - Sn;
    long long val2 = S2 - S2n;
    val2 = val2 / val1;

    long long x = (val1 + val2) / 2;
    long long y = abs(val2 - x);

    return {(int)x, (int)y};
}