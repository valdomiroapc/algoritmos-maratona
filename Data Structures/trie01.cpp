struct trie01
{
    vector<pair<int,int> > tr;
    trie01(){
        tr.pb({-1,-1});
    }
    void insert_num(int x){
        int idx = 0;
        for(int i=30;i>=0;i--){
            if(x&(1<<i)){
                if(tr[idx].second==-1){
                    tr[idx].second = tr.size();
                    tr.pb({-1,-1});
                }
                idx = tr[idx].second;
            }
            else{
                if(tr[idx].first==-1){
                    tr[idx].first = tr.size();
                    tr.pb({-1,-1});
                }
                idx = tr[idx].first;
            }
        }
    }
    void print_elements(int node, int value,int p){
        if(tr[node].first == -1 and tr[node].second==-1){
            printf("%d\n",value);
            return;
        }
        if(tr[node].first != -1)
            print_elements(tr[node].first,value,p-1);
        if(tr[node].second != -1)
            print_elements(tr[node].second,value+(1<<p),p-1);
    }
};
