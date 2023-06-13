class Solution{
public:	
	vector<int> kLargest(int arr[], int n, int k) {
	    priority_queue<int, vector<int>, greater<int>> pq;
	    
	    for(int i = 0; i < k; i++)
	        pq.push(arr[i]);
	        
	    for(int i = k; i < n; i++){
	        if(arr[i] > pq.top()){
	            pq.pop();
	            pq.push(arr[i]);
	        }
	    }
	    
	    vector<int> ans(k);
	    for(int i = k - 1; i > -1; i--){
	        ans[i] = pq.top();
	        pq.pop();
	    }
	    
	    return ans;
	}

};
