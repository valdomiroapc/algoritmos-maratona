struct unionfind
{
    int *pai;
    int *r;
    void inicializa(int n)
    {
        for(int i=0;i<n;i++)
        {
            pai[i] = i;
            r[i] = 1;
        }
    }
    unionfind(int n)
    {
        pai = new int[n];
        r = new int[n];
        inicializa(n);
    }
    int acha_o_pai(int x)
    {
        if(pai[x] == x)
            return x;
        return pai[x]=acha_o_pai(pai[x]);
    }
    void une_conjunto(int x,int y)
    {
        x = acha_o_pai(x);
        y = acha_o_pai(y);
        if(r[x] > r[y])
        {
            pai[y] = x;
            r[x]++;
        }
        else
        {
            pai[x] = y;
            r[y]++;
        }
    }
    bool ta_junto(int i,int j)
    {
        return acha_o_pai(i)==acha_o_pai(j);
    }
};
