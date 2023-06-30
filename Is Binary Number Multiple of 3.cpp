class Solution{
public:	
		
	int isDivisible(string s){
	    int cur = 0;
	    
	    for(auto i : s){
	        cur = (cur * 2 + (i - '0')) % 3;
	    }
	    
	    return cur == 0;
	}

};
