class Solution{

public:

    int LargButMinFreq(int arr[], int n) {

        // code here

    

        

        unordered_map<int, int> mp;

        int mini = INT_MAX;

        int ans =-1;

        for(int i =0; i<n; i++)

        {

            mp[arr[i]]++;

        }

        

        for(auto key : mp)

        {

            if(key.second < mini)

            {

                mini = key.second;

                ans = key.first;

            }

            if(key.second == mini)

            {

                ans = max(ans, key.first);

            }

        }

        return ans;

    }

};

//{ Driver Code Starts.

int main() {

    int t;

    cin >> t;

    // Iterating over testcases

    while (t--) {

        int n;

        cin >> n;

        int arr[n];

        for (int i = 0; i < n; i++) cin >> arr[i];

        Solution ob;

        cout << ob.LargButMinFreq(arr, n) << endl;

    }

}

// } Driv
