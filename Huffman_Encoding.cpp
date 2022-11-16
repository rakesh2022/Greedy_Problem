/*
	link: https://practice.geeksforgeeks.org/problems/huffman-encoding3345/1
	video (just to understand): https://youtu.be/co4_ahEDCho
*/


// ----------------------------------------------------------------------------------------------------------------------- //
/*
	Time complexity: O(nlogn) where n is the number of unique characters. If there are n nodes, extractMin() is called 2*(n – 1) times. extractMin() takes O(logn) time as it calles minHeapify(). So, overall complexity is O(nlogn).
If the input array is sorted, there exists a linear time algorithm. We will soon be discussing in our next post.
Applications of Huffman Coding:
	1. They are used for transmitting fax and text.
	2. They are used by conventional compression formats like PKZIP, GZIP, etc.
 It is useful in cases where there is a series of frequently occurring characters.
*/
// C++ program for Huffman Coding with STL
class Solution
{
	public:
	class Node{
	    public:
	  int val;
	  Node* left,*right;
	  Node(int val_){
	      val=val_;
	      left=NULL;
	      right=NULL;
	  }
	};
	class comp{
	    public:
    bool operator()(Node* a,Node* b){
        return a->val > b->val;
    }
	};
	void preorder(Node* root,string s,vector<string>&ans){
	    if(root==NULL)return;
	    if(root->left==NULL && root->right==NULL)ans.push_back(s);
	    preorder(root->left,s+'0',ans);
	    preorder(root->right,s+'1',ans);
	}
		vector<string> huffmanCodes(string S,vector<int> f,int N)
		{
		    priority_queue<Node*,vector<Node*>,comp>pq;
		    for(int i=0;i<f.size();i++){
		        Node* node=new Node(f[i]);
		        pq.push(node);
		    }
		    while(pq.size()>1){
		        Node* l=pq.top();
		        pq.pop();
		        Node* r=pq.top();
		        pq.pop();
		        Node* parent=new Node(l->val + r->val);
		        parent->left=l;
		        parent->right=r;
		        pq.push(parent);
		    }
		    Node* root=pq.top();
		    vector<string>ans;
		    preorder(root,"",ans);
		    return ans;
		}
};