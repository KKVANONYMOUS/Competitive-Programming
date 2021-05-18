#include <bits/stdc++.h>
using namespace std;

class MinHeap{
    public:
        int capacity;
        int heap_size;
        int *arr;

        MinHeap(int n){
            capacity=n;
            heap_size=n;
            arr=new int[n];
        }

        int left(int i){
            return (2*i+1);
        }
        int right(int i){
            return (2*i+2);
        }
        int parent(int i){
            return (i-1)/2;
        }

        void minHeapify(int i){
            int l=left(i); 
            int r=right(i); 
            int smallest=i;

            if(l<heap_size && arr[l]<arr[i]) smallest=l;
            if(r<heap_size && arr[r]<arr[smallest]) smallest=r;

            if(smallest!=i){
                swap(arr[smallest],arr[i]);
                minHeapify(smallest);
            }
        }

        int extractMin(){
            if(heap_size<=0) return INT_MAX;
            if(heap_size==0){
                heap_size--;
                return arr[0];
            }

            int root=arr[0]; 
            arr[0]=arr[heap_size-1]; 
            heap_size--; 
            minHeapify(0); 
            return root;
        }

        // Time Complexity:O(Nlog(N))
        void heapSort(){
            // to extract min heap value till the heap_size is 0
            for(int i=0;i<capacity;i++){
                cout<<extractMin()<<" "; //extract min heap value 
            }
        }
};
int main(){
    int n;
    cout<<"Enter array size\n";
    cin>>n;
    MinHeap obj(n);
    cout<<"Enter array elements\n";
    int x;
    for(int i=0;i<n;i++){
        cin>>x;
        obj.arr[i]=x;
    }
    //heapify all node - bottom to up
    //start from second last level
    for(int i=(n/2-1);i>=0;i--){
        obj.minHeapify(i);
    }
    
    cout<<"Sorted Array: ";
    obj.heapSort();
    return 0;
}