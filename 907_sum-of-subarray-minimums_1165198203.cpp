class Solution
{
    public:
        int sumSubarrayMins(vector<int> &arr)
        {
           	// explain later
            int n = arr.size();
            int mod = 1e9 + 7;
            vector<int> left(n,-1), right(n,n);
            stack<int> st;

           	// NSL
            for (int i = 0; i < n; i++)
            {
                while (!st.empty() && arr[st.top()] >= arr[i])
                    st.pop();
                if (!st.empty())
                    left[i] = st.top();
                st.push(i);
            }
           	// clear stack for reuse
            while (!st.empty())
                st.pop();

           	// NSR
            for (int i = n - 1; i >= 0; i--)
            {
                while (!st.empty() && arr[st.top()] > arr[i])
                    st.pop();
                if (!st.empty())
                    right[i] = st.top();
                st.push(i);
            }

           	// main logic
            long long sum = 0;
            for (int i = 0; i < n; i++)
            {
                int l = (i - left[i] + mod) % mod;
                int r = (right[i] - i + mod) % mod;
                long long freq = (l *r) % mod;
                long long contri = (arr[i] *freq) % mod;
               	// sum += (arr[i] *freq) % mod;
                sum = (sum + contri) % mod;
            }
            return (int)sum % mod;
        }
};