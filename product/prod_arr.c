int prod_arr(int *p, int n)
{
    // multiply all array values
    int prod = 1;
    for (int i=0; i<n; i++) {
        prod *= *(p+i);
    }

    return prod;
}