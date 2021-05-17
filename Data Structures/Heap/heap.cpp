#include<bits/stdc++.h>
using namespace std;

class MinHeap{
    public:
        int *arr; // pointer to array of elements
        int capacity; // max possible size of min heap
        int heap_size; // current number of elements in min heap

        MinHeap(int n){
            arr=new int[n];
            capacity=n;
            heap_size=0;
        }

        // TO GET THE INDEX OF PARENT OF CURRENT KEY
        int parent(int i){
            return (i-1)/2;
        }

        // TO GET THE INDEX OF LEFT NODE OF CURRENT KEY
        int left(int i){
            return (2*i+1);
        }

        // TO GET THE INDEX OF RIGHT NODE OF CURRENT KEY
        int right(int i){
            return (2*i+2);
        }

        // A UTILITY FUNCTION TO REBUILD THE HEAP ARRAY AFTER PERFOMING extractMin FUNCTION
        void minHeapify(int i){
            int l=left(i); // extract index of left node of current val
            int r=right(i); // extract index of right node of current val
            int smallest=i;

            //check if the child nodes of current key have lower val then the current key or not
            if(l<heap_size && arr[l]<arr[i]) smallest=l;
            if(r<heap_size && arr[r]<arr[smallest]) smallest=r;

            /*if smallest is not equal to i, then it means we have found a node having lower value then the current key
            Thus we will swap those elements and again call minHeapify by passing smallest index and check further sub trees
            */
            if(smallest!=i){
                swap(arr[smallest],arr[i]);
                minHeapify(smallest);
            }
        }

        // TO INSERT A NEW KEY/VALue IN HEAP
        void insertKey(int k){
            if(heap_size==capacity){
                cout<<"Overflow:Heap Full\n";
                return;
            }
            heap_size++;
            int i=heap_size-1;
            arr[i]=k;

            // swap until the parent of current node is less then the current node
            while(i!=0 && arr[parent(i)]>arr[i]){
                swap(arr[parent(i)],arr[i]);
                i=parent(i);
            }
        }

        // TO DELETE THE MIN VALUE OF HEAP
        int extractMin(){
            // if no node is present
            if(heap_size<=0) return INT_MAX;

            // if only one node is present
            if(heap_size==0){
                heap_size--;
                return arr[0];
            }

            // if more than one nodes are present
            int root=arr[0]; // store the value of min node (that needs to be removed)
            arr[0]=arr[heap_size-1]; // copy the last node to top position (0th index)
            heap_size--; // decrease the size of heap by one and then work on the tree by performing minHeapify operation
            minHeapify(0); // start from the very first index i.e. 0th index
            return root;
        }

        // TO DECREASE THE VAL AT THE SPECIFIED TO INDEX TO MIN AND THEN SHIFT IT TO THE ROOT OF HEAP - UTILITY FUNCTION FOR IMPLEMENTING deleteKey function
        void decreaseKey(int i){
            arr[i]=INT_MIN;
            while(i!=0 && arr[parent(i)]>arr[i]){
                swap(arr[i],arr[parent(i)]);
                i=parent(i);
            }
        }

        // TO DELETE KEY AT THE SPECIFIED INDEX
        void deleteKey(int i){
            if(i>(heap_size-1) || i<0){
                cout<<"Invalid input\n";
                return;
            }
            decreaseKey(i);// first decrease the val at the specified index to min infinite and then shift it to the root of heap
            extractMin(); // after that simply apply extractMin to remove the element which we wilingly shifted to the root position
        }

        // TO SEARCH FOR THE GIVEN VALUE IN THE ARRAY
        void linearSearch(int val){
            for(int i=0;i<heap_size;i++){
                if(arr[i]==val){
                    cout<<"Value found";
                    return;
                }
            }
            cout<<"Value NOT found";
        }

        // TO PRINT THE ARRAY
        void printArray(){
            for(int i=0;i<heap_size;i++){
                cout<<arr[i]<<" ";
            }
            cout<<"\n";
        }

        // TO GET MIN HEAP VALUE
        int getMin(){
            return arr[0];
        }

        // TO FIND THE HEIGHT OF MINHEAP TREE
        int height(){
            return ceil(log2(heap_size+1))-1;
        }
};
int main(){
    int n;
    cout<<"Enter the size of Min Heap\n";
    cin>>n;
    MinHeap obj(n);
    cout<<"Min Heap created successfully\n";
    int option,val;
    do{
            cout << "What operation do you want to perform? " <<
        " Select Option number. Enter 0 to exit." << endl;
        cout << "1. Insert Key/Node" << endl;
        cout << "2. Search Key/Node" << endl;
        cout << "3. Delete Key/Node" << endl;
        cout << "4. Get Min" << endl;
        cout << "5. Extract Min" << endl;
        cout << "6. Height of Heap" << endl;
        cout << "7. Print/Traversal Heap values" << endl;
        cout << "8. Clear Screen" << endl;
        cout << "0. Exit Program" << endl;

        cin>>option;
        switch(option){
            case 0:
                break;
            case 1:
                cout << "INSERT Operation -" << endl;
                cout << "Enter value to INSERT in HEAP: ";
                cin >> val;
                obj.insertKey(val);
                cout << endl;
                break;
            case 2:
                cout << "SEARCH Operation -" << endl;
                cout << "Enter VALUE to SEARCH in HEAP: ";
                cin >> val;
                obj.linearSearch(val);
                break;
            case 3:
                cout << "DELETE Operation -" << endl;
                cout << "Enter INDEX of Heap Array to DELETE: ";
                cin >> val;
                obj.deleteKey(val);
                break;
            case 4:
                cout << "GET Min value : " << obj.getMin();
                cout << endl;
                break;
            case 5:
                cout << "EXTRACT Min value : " << obj.extractMin();
                cout << endl;
                break;
            case 6:
                cout << "HEAP TREE HEIGHT : " << obj.height() << endl;
                break;
            case 7:
                cout << "PRINT Heap Array : " << endl;
                obj.printArray();
                cout << endl;
                break;
            case 8:
                system("cls");
                break;
            default:
                cout << "Enter Proper Option number " << endl;
        }
    
    }while(option!=0);

    return 0;
}