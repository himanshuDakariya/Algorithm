//6) Write a program to sort the elements of an array using Count Sort.

#include<iostream>
using namespace std;


int main() {
    int arr[]={9,2,9,3,9,4};
    int inpsize=sizeof(arr)/sizeof(arr[0]);

    int max=arr[0];
    for(int i=0;i<inpsize;i++){
        if(arr[i]>max){
            max=arr[i];
        }
    }

    int *FreqArr = new int[max+1];
    for(int i=0;i<=max;i++){
        FreqArr[i]=0;
    }
    
    for(int i=0;i<inpsize;i++){
        FreqArr[arr[i]]++;
    }
    
    int *CummulativeFreq = new int[max+1];

    for(int i=0;i<max+1;i++){
        CummulativeFreq[i]=0;
    }

    CummulativeFreq[0]+= (FreqArr[0]);
    for(int i=1;i<=max;i++){
        CummulativeFreq[i]+= (CummulativeFreq[i-1]+FreqArr[i]);
    }

    cout<<"Original Array"<<endl;
    for(int i=0;i<inpsize;i++){
        cout<<arr[i]<<" ";
    }

    cout<<endl;
    cout<<"Frequncy Array"<<endl;
    for(int i=0;i<=max;i++){
        cout<<FreqArr[i]<<" ";
    }

    cout<<endl;

    cout<<"Cummulative Array"<<endl;
    for(int i=0;i<=max;i++){
        cout<<CummulativeFreq[i]<<" ";
    }

    cout<<endl;
    
    int *finalArray = new int[inpsize];

    for(int i=inpsize-1;i>=0;i--){
        finalArray[CummulativeFreq[arr[i]] - 1] = arr[i];
        CummulativeFreq[arr[i]]--;
    }

    cout<<"Sorted Array"<<endl;
    for(int i=0;i<inpsize;i++){
        cout<<finalArray[i]<<" ";
    }


return 0;

}