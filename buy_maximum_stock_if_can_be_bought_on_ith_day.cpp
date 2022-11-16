/*
	link: https://www.geeksforgeeks.org/buy-maximum-stocks-stocks-can-bought-th-day/
*/


// ----------------------------------------------------------------------------------------------------------------------- //
/*
	TC: O(N logN)
*/
// CPP program to find maximum number of stocks that
// can be bought with given constraints.



 int buyMaximumProducts(int n, int k, int p[]){
       vector<pair<int,int>>v;
       for(int i=0;i<n;i++){
           v.push_back({p[i],i+1});
       }
       sort(v.begin(),v.end());
       int stocks=0;
       for(int i=0;i<n;i++){
           int per=v[i].first;
           int amt=v[i].second;
           if(per*amt <= k){
               stocks+= (amt);
               k-= (per*amt);
           }
           else{
               stocks+= (k/per);
              break;
               
           }
       }
       return stocks;
    }