#include<iostream>
using namespace std;
class Heap{
    public:
        int *arr;
        int capacity;
        int size;

        Heap(int capacity){
            this->arr = new int[capacity];
            this->capacity = capacity;
            this->size = 0;
        }

        void insert(int val){
            if(size == capacity){
                cout << "Heap Overflow" << endl;
                return;
            }

            // size increase karo
            size++;
            int index = size;
            arr[index] = val;

            // take the val of its correct position
            while(index > 1){
                int parentIndex = index/2;
                if(arr[index] > arr[parentIndex]){
                    swap(arr[index],arr[parentIndex]);
                    index = parentIndex;
                }
                else{
                    break;
                }
            }
        }

        void printHeap(){
            for(int i=1;i<=size;i++){
                cout << arr[i] << " ";
            }
        }

        int deleteFromHeap(){
            int answer = arr[1];
            // replacement
            arr[1] = arr[size];
            // last element ko delete uski original position se
            size--;

            int index = 1;
            while(index < size){
                int leftIndex = 2*index;
                int rightIndex = 2*index+1;

                // find out karna h, sabse bada kon
                int largestKaIndex = index;

                // check left child
                if(leftIndex <= size && arr[largestKaIndex] < arr[leftIndex]){
                    largestKaIndex = leftIndex;
                }

                // check right child
                if(rightIndex <= size && arr[largestKaIndex] < arr[rightIndex]){
                    largestKaIndex = rightIndex;
                }

                // no change
                if(index == largestKaIndex){
                    break;
                }
                else{
                    swap(arr[index],arr[largestKaIndex]);
                    index = largestKaIndex;
                }
            }
            return answer;
             
        }
};

int main(){
    Heap h(20);
    // insertion
    h.insert(10);
    h.insert(20);
    h.insert(5);  
    h.insert(11);
    h.insert(6);

    cout << "Printing the content of heap: " << endl;
    h.printHeap();
    cout << endl;
    int ans = h.deleteFromHeap();
    cout << "Answer: " << ans << endl;

}