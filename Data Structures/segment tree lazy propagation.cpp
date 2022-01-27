
struct segtree{
    vector<long long int> tree;
    vector<long long int> lazy;
    segtree(int n){
        tree.assign(4*n,0);
        lazy.assign(4*n,0);
    }
    void build(int no,int l,int r,vector<int> &v){
        if(l==r){
            tree[no] = v[l];
            return;
        }
        int m = (l+r)/2;
        build(no*2,l,m,v);build(no*2+1,m+1,r,v);
        tree[no] = tree[no*2]+tree[no*2+1];
    }
    long long int query(int no,int l,int r,int p,int q){
        if(lazy[no]){
            tree[no]+=lazy[no]*(r-l+1);
            if(l<r){
                lazy[no*2]+=lazy[no];
                lazy[no*2+1]+=lazy[no];
            }
            lazy[no] = 0;
        }
        if(l>q or r<p)
            return 0;
        if(p<=l and r <= q)
            return tree[no];
        int m = (l+r)/2;
        long long int left = query(no*2,l,m,p,q);
        long long int right = query(no*2+1,m+1,r,p,q);
        return left+right;
    }
    void update(int no,int l,int r,int p,int q,int val){
        if(lazy[no]){
            tree[no] += lazy[no]*(r-l+1);
            if(l<r){
                lazy[no*2]+=lazy[no];
                lazy[no*2+1]+=lazy[no];
            }
            lazy[no]=0;
        }
        if(l>q or r<p)
            return;
        if(p<=l and r<=q){
            lazy[no]+=val;
            tree[no]+=lazy[no]*(r-l+1);
            if(l<r){
                lazy[no*2]+=lazy[no];
                lazy[no*2+1]+=lazy[no];
            }
            lazy[no] = 0;
            return;
        }
        int m = (l+r)/2;
        update(no*2+1,m+1,r,p,q,val);
        update(no*2,l,m,p,q,val);
        tree[no] = tree[no*2] + tree[no*2+1];
    }
};
