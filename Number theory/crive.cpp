const int max_prime = 100;
vector<int> crive()
{   
    bitset<max_prime>c;
    vector<int> p_list;
    c[0]=1;c[1]=1;
    for(int i=2;i<=max_prime;i++)
    {
        if(c[i])
            continue;
        p_list.pb(i);
        for(int j=i+i;j<=max_prime;j+=i)
            c[j]=1;
    }
    return p_list;
}
