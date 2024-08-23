#include<stdio.h>
#include<stdbool.h>
int main(){
    int arr[10]={1,3,5,7,9,2,4,5,6,8};
    //sortinf of array in decending order
    for(int i=0;i<10;i++){
        for (int j=i+1;j<10;j++){
            if(arr[i]>arr[j]){
                continue;
            }
            else{
                int a=arr[i];
                arr[i]=arr[j];
                arr[j]=a;
            }
        }
     printf("%d ",arr[i]);   
    }
    
    
    //iterative binary search
    
    
    char ch=false;
    int e;
    printf("\nEnter a element which search in array:-");
    scanf("%d",&e);
    int start=0;
    int end=sizeof(arr)/sizeof(int)-1;
    while(start<=end){
        int mid=(start+end)/2;
         if(arr[mid]==e){
             printf("element is founded ");
             ch=true;
             break;
         }
         else if(arr[mid]<e){
             end = mid-1;
         }
         else if(arr[mid]>e){
             start = mid+1;
         }
    }
    // if element not found in array
    if(ch==false){
        printf("Element is not founded in array");
    }
    
}