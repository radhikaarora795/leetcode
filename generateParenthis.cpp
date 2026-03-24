#include <iostream>
using namespace std;

void printPattern() {
    int N;
    cout << "Enter N: ";
    cin >> N;

    int size = 2 * N - 1;

    for(int i = 0; i < size; ++i) {
        for(int j = 0; j < size; ++j) {
            int min_dist = min(min(i, j), min(size - 1 - i, size - 1 - j));
            cout << N - min_dist << " ";
        }
        cout << endl;
    }
}


void generateParenthesis(char *a, int i, int open, int closed, int n) {
    if(i == 2*n){
        a[i]='\0';     
        cout<<a<<endl; 
        return;
    }

    if(open < n){
        a[i]='(';
        generateParenthesis(a, i+1, open+1, closed, n);
    }

    if(closed < open){
        a[i]=')';
        generateParenthesis(a, i+1, open, closed+1, n);
    }
}

void nutsAndBolts(){
    int N = 5;
    char nuts[]  = {'@', '%', '$', '#', '^'};
    char bolts[] = {'%', '@', '#', '$', '^'};

    // Sort both arrays
    sort(nuts, nuts + N);
    sort(bolts, bolts + N);

    // Print nuts
    for(int i = 0; i < N; ++i)
        cout << nuts[i] << " ";
    cout << endl;

    // Print bolts
    for(int i = 0; i < N; ++i)
        cout << bolts[i] << " ";
    cout << endl;
}

int main() {
    int n;
    cout<<"Enter number of pairs: ";
    cin>>n;

    char a[2*n+1];
    
    generateParenthesis(a,0,0,0,n);
    printPattern();
    nutsAndBolts();
    
    return 0;
}