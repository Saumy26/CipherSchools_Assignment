#include<iostream>
using namespace std;
int getMin(int val1, int val2)
{
    return (val1 < val2 ? val1 : val2);
}
int getMinimumSum(int arr[3][3])
{
    for(int i=0; i<3; i++) {
        for(int j=0; j<3; j++) {
            if(i==0 && j == 0) {
                continue;
            }
            else if(i==0) {
                arr[i][j] = arr[i][j] + arr[i][j-1];
            }
            else if(j==0) {
                arr[i][j] = arr[i][j] + arr[i-1][j];
            }
            else {
                arr[i][j] = getMin(arr[i-1][j]+arr[i][j], arr[i][j-1]+arr[i][j]);
            }
        }
    }
    return arr[2][2];
}

int main()
{
    int arr[3][3] = {{1,3,4},
                    {2,0,2},
                    {2,0,1}};
                            
    cout<<getMinimumSum(arr);
    return 0;
}
