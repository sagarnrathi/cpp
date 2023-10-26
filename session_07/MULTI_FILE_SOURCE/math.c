double cpa_pow(double x ,int n)
{
    int i;
    double result = 1.0 ;

    for(i=0;i<n;i++)
            result = result * x;
    return result ;
}

int cpa_fact(int n)
{
    if(n<=1)
        return 1;
    else 
       return (n *cpa_fact(n-1));
}

double cpa_sin(double x)
{
    int i;
    int nr_terms = 9;
    double result  = 0.0 ;

    for(i = 1 ;i<nr_terms ;i++)
        result  = cpa_pow(-1,(i / 2)) * (cpa_pow(x,i)/cpa_fact(i));
    return result;
}

double cos(double x)
{
    return (1 - cpa)
}