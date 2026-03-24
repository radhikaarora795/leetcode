/*
Problem: Maximum Sum of Non-Adjacent Elements

Problem Statement:
Given an array of integers, find the maximum possible sum of elements such that no 
two chosen elements are adjacent in the array.
*/

#include <iostream>
#include <vector>
using namespace std;

int maxSum(vector<int>& arr){
    int n=arr.size();
    vector<int> dp(n);
    if(n == 0){
        return 0;
    }
    else if(n == 1){
        return arr[0];
    }
    dp[0]=arr[0];
    dp[1]=max(arr[0],arr[1]);
    for(int i=2;i<n;i++){
        dp[i]=max(dp[i-1],arr[i]+dp[i-2]);
    }
    return dp[n-1];

}

int main() {
    vector<int> arr={2, 1, 4, 9};
    cout<<maxSum(arr);
    
    return 0;
}

// without dp:
int maxSum2(vector<int>& arr) {
    int n = arr.size();

    if (n == 0) return 0;
    if (n == 1) return arr[0];

    int prev2 = arr[0];                  // dp[i-2]
    int prev1 = max(arr[0], arr[1]);     // dp[i-1]

    for (int i = 2; i < n; i++) {
        int curr = max(prev1, arr[i] + prev2);
        prev2 = prev1;
        prev1 = curr;
    }

    return prev1;
}


/*
Good question — this is the **core logic** of the problem. I’ll explain it **step-by-step in proper exam-ready sentences**, not just the formula.

---

## How the Recurrence Relation is Formed

( Maximum Sum of Non-Adjacent Elements )

Let the array be `arr[0 … n−1]`.

Define
[
dp[i] = \text{maximum sum of non-adjacent elements considering elements from index } 0 \text{ to } i
]

---

## Step 1: Think about the choice at index `i`

When we are at element `arr[i]`, **only two valid choices exist**:

---

### **Case 1: Exclude the element `arr[i]`**

* If we do **not** select `arr[i]`, then the maximum sum remains the same as what we obtained till the previous index.
* That value is:
  [
  dp[i-1]
  ]

---

### **Case 2: Include the element `arr[i]`**

* If we select `arr[i]`, then we **cannot select `arr[i-1]`** because elements must be non-adjacent.
* Therefore, the best sum we can add to `arr[i]` is the maximum sum till index `i-2`.
* That value is:
  [
  arr[i] + dp[i-2]
  ]

---

## Step 2: Choose the better of the two cases

To get the **maximum sum**, we choose the better option between including and excluding the current element.

[
\boxed{dp[i] = \max(dp[i-1],; arr[i] + dp[i-2])}
]

This is the **recurrence relation**.

---

## Step 3: Base Conditions (Very Important for Exam)

* For `i = 0`
  [
  dp[0] = arr[0]
  ]
* For `i = 1`
  [
  dp[1] = \max(arr[0], arr[1])
  ]

These handle the smallest subproblems and allow the recurrence to work.

---

## Why this Recurrence is Correct (Exam Language)

> At every index `i`, the problem is reduced to smaller independent subproblems.
> If the current element is selected, the adjacent element must be excluded, leading to the subproblem `dp[i-2]`.
> If the current element is excluded, the solution remains `dp[i-1]`.
> Hence, the optimal solution is obtained by taking the maximum of these two choices.

---

## One-Line Intuition (Easy to Remember)

> **Take it → skip the previous**
> **Skip it → keep the previous**

That logic directly forms:
[
dp[i] = \max(dp[i-1], arr[i] + dp[i-2])
]

---

*/