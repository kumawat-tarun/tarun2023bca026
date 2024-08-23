#include<stdio.h>
#include<stdbool.h>
int binary_search(int arr[],int key,int start,int end){
    int mid=(start+end-1)/2;
    char ch=false;
    if(start<=end){
        if(arr[mid]==key){
            ch=true;
            return ch;
        }
        if(arr[mid]>key){
            return binary_search(arr,key,start,mid-1);
        }
        else if(arr[mid]<key){
            return binary_search(arr,key,mid+1,end);
        }
    }
    return ch;
    
}
int main(){
    int arr[10]={1,2,3,4,5,6,7,8,9,10};
    int key;
    printf("Enter a number which are search in array:-");
    scanf("%d",&key);
    int t=binary_search(arr,key,0,10);
    
    if(t==true) printf("Element is founded");
    else printf("Element is not founded");
    return 0;
}