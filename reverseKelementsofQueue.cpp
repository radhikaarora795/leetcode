#include <iostream>
#include <queue>
#include <stack>
using namespace std;

void print_queue(queue<int> qTemp) { // Pass by value to work on a copy
    while (!qTemp.empty()) {
        cout << qTemp.front() << " ";
        qTemp.pop();
    }
    cout << endl;
}

queue<int> reverseQueue(queue<int> q,int k){
    if(k<=0 || k>q.size()){
        return q;
    }

    queue<int> ans;
    stack<int> s;

    for(int i=0;i<k;i++){
        s.push(q.front());
        q.pop();
    }

    while(!s.empty()){
        ans.push(s.top());
        s.pop();
    }

    while(!q.empty()){
        ans.push(q.front());
        q.pop();
    }

    return ans;
}

void spiralTraversal(int **m,int r,int c){
    int top=0;  // top row
    int left=0; // left col
    int bottom=r-1; // bottom row
    int right=c-1;  // right col

    while(top<=bottom && left<=right){
        for(int i=left;i<=right;i++){
            cout<<m[top][i]<<" ";
        }
        top++;
        for(int i=top;i<=bottom;i++){
            cout<<m[i][right]<<" ";
        }
        right--;
        if(top<=bottom){
            for(int i=right;i>=left;i--){
                cout<<m[bottom][i]<<" ";
            }
            bottom--;
        }
        if(left<=right){
            for(int i=bottom;i>=top;i--){
                cout<<m[i][left]<<" ";
            }
            left++;
        }
    }
}

int balancedParentheses(string str){
    stack<char> s;
    int score=0;
    for(char ch:str){
        if(ch == '('){
            s.push(ch);
        }
        else{
            if(s.empty()){
                return 0;
            }
            char top=s.top();
            if(top=='(' && ch==')'){
                s.pop();
                score++;
                continue;
            }
            else{
                return 0;
            }
        }
    }
    return score;
}

vector<int> greatestNumber(int **arr,int m,int n){
    int greatest=arr[0][0];
    vector<int> coordinates;
    for(int i=0;i<m;i++){
        for(int j=0;j<n;j++){
            if(arr[i][j]>greatest){
                greatest=arr[i][j];
            }
        }
    }
    for(int i=0;i<m;i++){
        for(int j=0;j<n;j++){
            if(arr[i][j]==greatest){
                coordinates.push_back(i);
                coordinates.push_back(j);
            }
        }
    }
    return coordinates;
}

int main() {
    queue<int> q;
    int n,k,j;
    cout<< " Enter no of items in queue ";
    cin >> n;
    cout<< " Enter no of items to reverse ";
    cin >> k;
    cout<< " Enter items ";
    for( int i=0;i<n;i++){
        cin >> j;
        q.push(j); 
    }
    queue<int> ans=reverseQueue(q,k);
    print_queue(ans);

    /*int **m;
    int r,c;
    cout<<"Enter r: ";
    cin>>r;
    cout<<"Enter c: ";
    cin>>c;

    m=new int*[r];
    for(int i=0;i<r;i++){
        m[i]=new int[c];
    }

    for(int i=0;i<r;i++){
        for(int j=0;j<c;j++){
            cin>>m[i][j];
        }
    }*/

    // spiralTraversal(m,r,c);

    // cout<<balancedParentheses("(()())");

    // vector<int> v=greatestNumber(m,r,c);
    // for(int i:v){
    //     cout<<i<<" ";
    // }
    
    return 0;
}