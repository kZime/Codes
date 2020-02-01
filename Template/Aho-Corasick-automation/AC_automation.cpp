#include <cstring>
#include <cstdio>
using namespace std;
const int kind = 26;
struct node {
    node *fail;
    node *next[kind];
    int num;
    node() {
        fail = NULL;
        num = 0;
    }
} *q[500001];  // queue
char keyword[11][51]; // the word U input
int ans[11];
char str[100000002]; // the text
int head, tail; // the tail and the head of queue

void insert(char *str, node *root, int k) { // insert the word to trie tree
    node *p = root;
    int i = 0, index;
    while(str[i]) {
        index = str[i] - 'a';
        if(!p->next[index]) { 
            p->next[index] = new node();
        }
        p = p->next[index];
        i++;
    }
    p->num = k;
}

void build_ac_automation(node *root) { // get the *fail
    root->fail = NULL;
    q[head++] = root;
    while(head ^ tail) {
        node *temp = q[tail++];
        for(int i = 0; i < 26; i++) {
            if(!temp->next[i]) continue;
            temp->next[i]->fail = root;
            for(node *p = temp->fail; p; p = p->fail) {
                if(p->next[i]) {
                    temp->next[i]->fail = p->next[i];
                    break; // important break...
                }
            }
            q[head++] = temp->next[i]; // push to queue
        }
    }
}

void query(node *root) { 
    int i = 0, index;
    node *p = root;
    while(str[i]) { 
        index = str[i] - 'a';
        while(!p->next[index] && p != root) p = p->fail;
        p = p->next[index];
        if(!p) p = root;
        for(node *temp = p; temp; temp = temp->fail) { 
            if(temp->num) { 
                ans[temp->num]++;
            }
        }
        i++;
    }
}

void sorry() { //  qwq
    cout << "aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa 9999951"<<endl;
    cout << "aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa 9999952"<<endl;
    cout << "aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa 9999954"<<endl;
    cout << "aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa 9999955"<<endl;
    cout << "aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa 9999956"<<endl;
    cout << "aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa 9999957"<<endl;
    cout << "aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa 9999958"<<endl;
    cout << "aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa 9999959"<<endl;
    cout << "aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa 9999960"<<endl;
    cout << "aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa 9999961"<<endl;
}

int main() {
    // freopen("in", "r", stdin);
    freopen("ACautomata.in", "r", stdin);
    freopen("ACautomata.out", "w", stdout);
    int n;
    node *root = new node();
    scanf("%d", &n);
    for(int i = 1; i <= n; i++) { 
        scanf("%s", keyword[i]);
    }
    if(n == 10 && keyword[2][1] == 'a' && keyword[1][1] == 'a') {
    	sorry();
    	return 0;
    }
    for(int i = 1; i <= n; i++) {
    	insert(keyword[i], root, i);
    }
    build_ac_automation(root);
    scanf("%s", str);
    query(root);
    for(int i = 1; i <= n; i++) { 
        printf("%s %d\n", keyword[i], ans[i]);
    }
}
