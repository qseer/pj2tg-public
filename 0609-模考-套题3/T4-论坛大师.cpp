#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using PII = pair<int, int>;
const int maxn = 1e5 + 10;
int a[maxn], chats[maxn], n, len, opCnt;
char ts[256];

void LOG(char s[]) 
{
    printf("Operation #%d: %s.\n", ++opCnt, s);
}

void add(int u) 
{
    int idx = find(a+1, a+1+len, u) - a;
    if(idx <= len) 
    {
        LOG("same priority");
        return ;
    }
    a[++len] = u;
    LOG("success");
}

void close(int u) 
{
    int idx = find(a+1, a+1+len, u) - a;
    if(idx > len) 
    {
        LOG("invalid priority");
        return ;
    }
    sprintf(ts, "close %d with %d", u, chats[u]);
    for(int i=idx; i<len; ++i) 
    {
        a[i] = a[i+1];
    }
    -- len; chats[u] = 0;
    LOG(ts);
}

void chat(int w)
{
    if(len <= 0) 
    {
        LOG("empty");
        return ;
    }
    int u = a[1]; chats[u] += w;
    LOG("success");
}

void rotate(int x) 
{
    if(x > len || x < 1) 
    {
        LOG("out of range");
        return ;
    }
    int ax = a[x];
    for(int i=x; i>=2; --i) 
    {
        a[i]=a[i-1];
    }
    a[1] = ax;
    LOG("success");
}

void prior() 
{

}

void solve()
{
    cin >> n; 
    while(n--) 
    {
        string op; cin >> op;
        if(op == "Add") 
        {
            int u; cin >> u;
            add(u);
        }
        else if(op == "Close") 
        {
            int u; cin >> u;
            close(u);
        }
        else if(op == "Chat") 
        {
            int w; cin >> w;
            chat(w);
        }
        else if(op == "Rotate") 
        {
            int x; cin >> x;
            rotate(x);
        }
        else if(op == "Prior") 
        {
            prior();
        }
        else if(op == "Choose") 
        {
            int u; cin >> u;
            choose(u);
        }
    }
}

int main() 
{
    int T; cin >> T;
    while(T--) 
    {
        len = 0; opCnt = 0; 
        memset(a, 0, sizeof(a));
        memset(chats, 0, sizeof(chats));
        solve();
    }
}