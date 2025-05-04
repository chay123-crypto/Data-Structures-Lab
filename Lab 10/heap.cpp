#include <iostream>
#include <vector>

using namespace std;

class Maxheap {
private:
    vector<int> heap;

    void heapifyup(int index) {
        while (index > 0) {
            int parent = (index - 1) / 2;
            if (heap[index] > heap[parent]) {
                swap(heap[index], heap[parent]);
                index = parent;
            } else {
                break;
            }
        }
    }

    void heapifydown(int index) {
        int size = heap.size();
        while (true) {
            int left = 2 * index + 1;
            int right = 2 * index + 2;
            int largest = index;
            
            if (left < size && heap[left] > heap[largest]) {
                largest = left;
            }
            if (right < size && heap[right] > heap[largest]) {
                largest = right;
            }
            if (largest == index) break;
            
            swap(heap[index], heap[largest]);
            index = largest;
        }
    }

public:
    void insert(int value) {
        heap.push_back(value);
        heapifyup(heap.size() - 1);
    }

    void deleteValue(int value) {
        int index = -1;
        for (int i = 0; i < heap.size(); ++i) {
            if (heap[i] == value) {
                index = i;
                break;
            }
        }
        if (index == -1) {
            cout << "Value not found in heap." << endl;
            return;
        }
        heap[index] = heap.back();
        heap.pop_back();
        heapifydown(index);
        heapifyup(index);
        cout << "Value deleted successfully." << endl;
    }

    int extractMax() {
        if (heap.empty()) {
            cout << "Heap is empty!" << endl;
            return -1;
        }
        int maxVal = heap[0];
        heap[0] = heap.back();
        heap.pop_back();
        heapifydown(0);
        return maxVal;
    }

    void display() {
        for (int i = 0; i < heap.size(); ++i) {
            cout << heap[i] << " ";
        }
        cout << "Max Heap: ";
        for (int i = 0; i < heap.size(); ++i) {
            cout << heap[i] << " ";
        }
        cout << endl;
    }

    void search(int value) {
        for (int i = 0; i < heap.size(); ++i) {
            if (heap[i] == value) {
                cout << "Value found at index " << i << endl;
                return;
            }
        }
        cout << "Value not found in heap." << endl;
    }

    void heapSort() {
        vector<int> temp = heap;
        vector<int> sorted;
        while (!temp.empty()) {
            swap(temp[0], temp[temp.size() - 1]);
            sorted.push_back(temp.back());
            temp.pop_back();
            int index = 0;
            int size = temp.size();
            while (true) {
                int left = 2 * index + 1;
                int right = 2 * index + 2;
                int largest = index;

                if (left < size && temp[left] > temp[largest]) {
                    largest = left;
                }
                if (right < size && temp[right] > temp[largest]) {
                    largest = right;
                }
                if (largest == index) break;
                swap(temp[index], temp[largest]);
                index = largest;
            }
        }
        cout << "Heap Sort (Descending): ";
        for (int i = 0; i < sorted.size(); ++i) {
            cout << sorted[i] << " ";
        }
        cout << endl;
    }
};

int main() {
    Maxheap h;
    int choice, value;
    do {
        cout << "\nPriority Queue using Max Heap";
        cout << "\n1. Insert";
        cout << "\n2. Delete Value";
        cout << "\n3. Extract Max";
        cout << "\n4. Display";
        cout << "\n5. Search";
        cout << "\n6. Heap Sort";
        cout << "\n7. Exit";
        cout << "\nEnter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                cout << "Enter value to insert: ";
                cin >> value;
                h.insert(value);
                break;
            case 2:
                cout << "Enter value to delete: ";
                cin >> value;
                h.deleteValue(value);
                break;
            case 3:
                cout << "Max value extracted: " << h.extractMax() << endl;
                break;
            case 4:
                h.display();
                break;
            case 5:
                cout << "Enter value to search: ";
                cin >> value;
                h.search(value);
                break;
            case 6:
                h.heapSort();
                break;
            case 7:
                cout << "Exiting..." << endl;
                break;
            default:
                cout << "Invalid choice! Try again." << endl;
        }
    } while (choice != 7);
    
    return 0;
}
