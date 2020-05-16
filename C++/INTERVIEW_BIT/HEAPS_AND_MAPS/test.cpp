vector<int> Solution::solve(vector<int> &A, vector<int> &B)
{
    sort(A.begin(), A.end());
    sort(B.begin(), B.end());
    priority_queue<int, vector<int>, greater<int>> maxElement;
    int n = A.size();
    bool toBreak;
    for (int i = n - 1; i >= 0 || toBreak; i--)
    {
        toBreak = true;
        for (int j = n - 1; j >= 0; j--)
        {
            if (maxElement.size() < n)
            {
                toBreak = false;
                maxElement.push(A[i] + B[j]);
                // cout<<"pushing A["<<i<<"] B["<<j<<"]\tValues are:\t"<<A[i]<<" "<<B[j]<<endl;
            }
            else if (maxElement.size() == n)
            {
                if (A[i] + B[j] > maxElement.top())
                {
                    toBreak = false;
                    maxElement.pop();
                    maxElement.push(A[i] + B[j]);
                    // cout<<"pushing A["<<i<<"] B["<<j<<"]\tValues are:\t"<<A[i]<<" "<<B[j]<<endl;
                }
            }
        }
        if (toBreak)
        {
            break;
        }
    }

    vector<int> ans;
    for (int i = 0; i < n; i++)
    {
        ans.push_back(maxElement.top());
        maxElement.pop();
    }
    reverse(ans.begin(), ans.end());
    return ans;
}