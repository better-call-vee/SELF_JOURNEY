/*
☞ Better.Call.Vee ☜
created: 19th October, 2023 12:13:53 GMT+6

https://codeforces.com/contest/847/problem/A
*/
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, prev, nxt;
    cin >> n;

    vector<pair<int, int>> lists;
    lists.push_back({0, 0});
    stack<int> heads;

    for(int i = 1; i <= n; i++) {
        cin >> prev >> nxt;
        if(prev == 0) heads.push(i);
        lists.push_back({prev, nxt});
    }

    int now = heads.top();
    heads.pop(); // one head will be the whole list's head.

    while(!heads.empty()) {
        if(lists[now].second == 0) {
            lists[now].second = heads.top();
            lists[heads.top()].first = now;
            heads.pop();
        }
        now = lists[now].second;
    }

    for(int print = 1; print <= n; print++)
        cout << lists[print].first << " " << lists[print].second << "\n";

    return 0;
}

/*
1. Checking the End of a List:

This step is represented by the condition: if(lists[now].second == 0)

Here, lists is an array (or similar data structure) representing the doubly 
linked lists. Each element in lists has two components:

    .first which points to the previous element.
    .second which points to the next element.

The condition checks if the next pointer (.second) of the current list 
(pointed to by now) is 0. If it is, this means the current element is the last
 element of its list (i.e., the end of the list).

2. Attaching Another List:

If the current element is the end of a list, the code aims to merge another 
list to it. This is done in the following steps:

    lists[now].second = heads.top();
    This line connects the end of the current list to the beginning of another list.
     It sets the next pointer of the current list's end to point to the start of the
      next list (which is the top element of the heads stack).

    lists[heads.top()].first = now;
    This line is crucial for maintaining the "doubly linked" nature of the lists.
     It sets the previous pointer of the next list's starting point (the one we just
      attached) to point back to the current element (now). This ensures that while 
      moving forward we've connected the end of one list to the start of another, we've 
      also established a backward link from the start of the new list to the end of the previous one.

    heads.pop();
    After attaching the new list, its head is no longer needed in the stack, so it's removed.

3. Moving the Pointer:

    now = lists[now].second;
    This line shifts the now pointer to the next element in the merged list. This is 
    important because it allows the code to keep progressing through the merged list, 
    checking each element to see if it's an end and needs another list attached to it.

Summary of the Process:

The loop essentially does the following:

    Check if the current element is the end of its list.
    If it is, attach another list to it.
    Move to the next element.
    Repeat until all lists are merged.
*/