#include<iostream>
using namespace std;

void CountSort(int arr[],int inpsize,int exp){
    
    int max=arr[0];
    for(int i=0;i<inpsize;i++){
        if(arr[i]>max){
            max=arr[i];
        }
    }

    int *FreqArr = new int[10];
    for(int i=0;i<10;i++){
        FreqArr[i]=0;
    }
    
    for(int i=0;i<inpsize;i++){
        FreqArr[arr[i]/exp % 10]++;
    }
    
    int *CummulativeFreq = new int[10];

    for(int i=0;i<10;i++){
        CummulativeFreq[i]=0;
    }

    CummulativeFreq[0]+= (FreqArr[0]);
    for(int i=1;i<10;i++){
        CummulativeFreq[i]+= (CummulativeFreq[i-1]+FreqArr[i]);
    }


    int *finalArray = new int[inpsize];

    for(int i=inpsize-1;i>=0;i--){
        finalArray[CummulativeFreq[arr[i]/exp % 10] - 1] = arr[i];
        CummulativeFreq[arr[i]/exp % 10]--;
    }

    for (int i = 0; i < inpsize; i++) {
        arr[i] = finalArray[i];  // Copying sorted elements back to original array
    }
    cout<<endl;
}


int main (){

    int arr[]={931,
               123,
               427,
               567,
               429,
               100};
    int inpsize=sizeof(arr)/sizeof(arr[0]);

    int max=arr[0];
    for(int i=0;i<inpsize;i++){
        if(arr[i]>max){
            max=arr[i];
        }
    }
    // cout<<max;

    int exp=1; //how many times we r going to run countsort()
    while(exp<max){
        CountSort(arr,inpsize,exp);
        cout<<"Array After sorting on "<<exp<<"s digit:"<<endl;
        for(int i=0;i<inpsize;i++){
        cout<<arr[i]<<" ";
    }
        exp*=10;
    }

    // cout<<"Sorted Array"<<endl;
    // for(int i=0;i<inpsize;i++){
    //     cout<<arr[i]<<" ";
    // }

return 0;

}