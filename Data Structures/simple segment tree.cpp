struct segtree{
    vector<long long int> tree;
    segtree(int n){
        tree.resize(4*n);
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
        if(l>q or r<p)
            return 0;
        if(p<=l and r <= q)
            return tree[no];
        int m = (l+r)/2;
        long long int left = query(no*2,l,m,p,q);
        long long int right = query(no*2+1,m+1,r,p,q);
        return left+right;
    }
    void update(int no,int l,int r,int pos,int val){
        if(l==r){
            tree[no] = val;
            return;
        }
        int m = (l+r)/2;
        if(pos > m)
            update(no*2+1,m+1,r,pos,val);
        else
            update(no*2,l,m,pos,val);
        tree[no] = tree[no*2] + tree[no*2+1];
    }
};
