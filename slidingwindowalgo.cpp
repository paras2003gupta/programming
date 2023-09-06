 vector<int> max_of_subarrays(vector<int> arr, int n, int k) {
        deque<int>dq;
        vector<int>ans;
        
        for(int i = 0;i<n;i++){
            // removal of out of bound elements
            if(dq.size()>0&&dq.front()==i-k){
                dq.pop_front();
            }
            // once you checked that it is wondow of sized k find maximum
           
            while(!dq.empty()&&(arr[i]>arr[dq.back()]))    {
                dq.pop_back();
            
            }
            dq.push_back(i);
            if(i>=k-1){
                ans.push_back(arr[dq.front()]);
            }
        }
        return ans;
    }