/*
	link: https://practice.geeksforgeeks.org/problems/fractional-knapsack-1587115620/1
	sol: https://www.geeksforgeeks.org/fractional-knapsack-problem/
*/


// ----------------------------------------------------------------------------------------------------------------------- //
bool cmp(Item a, Item b)
{
    return a.value/(a.weight*1.0)>b.value/(b.weight*1.0);
}
class Solution
{
    public:
    //Function to get the maximum total value in the knapsack.
    double fractionalKnapsack(int w, Item arr[], int n)
    {
       sort(arr,arr+n,cmp);
       
      int i;
      double sum=0.0;
      
      for(i=0;i<n;i++)
      {
          if(w-arr[i].weight>=0)
          {
              sum+=arr[i].value;
              w-=arr[i].weight;
            //   cout<<sum<<" ";
          }
          else
          {
              sum+=w*(arr[i].value/(arr[i].weight*1.0));
              break;
          }
      }
       return sum;
    }
        
};