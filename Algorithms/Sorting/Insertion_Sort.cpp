#include <iostream>
using namespace std;
int main() {
    int i =0;
    
    int size = 0;
    cout<<"Enter the Size Of Array L "<<endl;
    cin>>size;
    int A[size] ;
    cout<<"Enter The Element Of Array : "<<endl;
    for(i = 0;i<size;i++){
        cin>>A[i];
    }
    for( i =1; i<size; i++){
        int temp = A[i];
        for(int j = i;j>0;j--){
            if(temp<A[j-1]){
                A[j] = A[j-1];
                A[j-1] = temp;
            }
        }
    }
    cout<<"Sorted Using Insertion Sort : "<<endl;
    for( i =0;i<size;i++){
        cout<<A[i]<<" ";
    }
    return 0;
}
