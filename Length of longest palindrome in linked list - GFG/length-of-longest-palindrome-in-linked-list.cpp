//{ Driver Code Starts
// C program to find n'th Node in linked list
#include <stdio.h>
#include <stdlib.h>
#include<iostream>
using namespace std;

/* Link list Node */
struct Node
{
    int data;
    struct Node* next;
    
    Node(int x){
        data = x;
        next = NULL;
    }
    
};

void append(struct Node** head_ref, struct Node **tail_ref,
            int new_data)
{
    struct Node* new_node = new Node(new_data);
    
    if (*head_ref == NULL)
        *head_ref = new_node;
    else
        (*tail_ref)->next = new_node;
    *tail_ref = new_node;
}

/* Function to get the middle of the linked list*/
int maxPalindrome(Node *);


/* Driver program to test above function*/
int main()
{
    int T,n,l;
    cin>>T;

    while(T--)
    {
        struct Node *head = NULL,  *tail = NULL;

        cin>>n;
        for (int i=1; i<=n; i++)
        {
            cin>>l;
            append(&head, &tail, l);
        }
      

       cout << maxPalindrome(head)<<endl;
    }
    return 0;
}



// } Driver Code Ends


/* The Node is defined 
  /* Link list Node
struct Node
{
    int data;
    struct Node* next;
    
    Node(int x){
        data = x;
        next = NULL;
    }
    
};
*/
#include <vector>
#include <queue>
#include <utility>
/*The function below returns an int denoting
the length of the longest palindrome list. */
int maxPalindrome(Node *head)
{
    vector<int> record;
    for(; head; head = head->next)
        record.push_back(head->data);
        
    queue<pair<int,int>> bfs;
        
    int cnt = 0;
    for(int i = 0; i < record.size(); i++)
        bfs.push({i, i});
    
    for(int i = 1; i < record.size(); i++)
        if(record[i - 1] == record[i])
            bfs.push({i - 1, i});
    
    while(bfs.size())
    {
        auto temp = bfs.front();
        cnt = max(cnt, temp.second - temp.first + 1);
        if(temp.first - 1 >= 0 && temp.second + 1 < record.size() && record[temp.first - 1] == record[temp.second + 1])
            bfs.push({temp.first - 1, temp.second + 1});
            
        bfs.pop();
    }
    
    return cnt;
}