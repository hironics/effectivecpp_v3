/*
maximum contiguous subarray
*/
#include <iostream>

using namespace std;

// find the starting and end position of the subarray that contains the max sum
template<typename M>
M maxSubarray(M a[], int len, int &i, int &j)
{
    M T = a[0], Vmax = a[0];
    M Tmin = min(0.0, T);
    for(int k=1; k<len; ++k){
        T+=a[k];
        if(T-Tmin>Vmax) { Vmax = T-Tmin; j=k;}
        if(T<Tmin) {Tmin = T; i=(k+1<j)?(k+1):j;}
    }
    return Vmax;
}

int main()
{
    double A[] = {1.0, 2.0, -5.0, 4.0, -3.0, 2.0, 6.0, -5.0, -1.0};
    int i=0,j=0;
    double Vmax= maxSubarray(A, 9, i, j);
    cout << i << " " << j << " " << Vmax << endl;
}
