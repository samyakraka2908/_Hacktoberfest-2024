#include<iostream>
using namespace std;

class Search {
public:
    int arr[100];
    int n;

    void input() {
        cout << "Enter the size of array :" << endl;
        cin >> n;
        cout << "Enter the numbers" << endl;
        for (int i = 0; i < n; i++) {
            cin >> arr[i];
        }
    }
// Binary Search Function
    int BinarySearch(int key) {
        int start = 0;
        int end = n - 1;
        int mid;
        cout << "\n start \t end \t mid";

        while (start <= end) {
            mid = (start + end) / 2;
            cout << "\n" << start << "\t" << end << "\t" << mid;
            if (arr[mid] == key)
                return mid;
            else if (arr[mid] < key)
                start = mid + 1;
            else
                end = mid - 1;
        }
        return -1;
    }
    // Recursive Binary Search Function
    int rcb(int key,int start,int end){
    cout << "\n start \t end \t mid";
     if(start>end)
     return -1;
     int mid=(start+end)/2;
     cout << "\n" << start << "\t" << end << "\t" << mid;
     if(arr[mid]==key)
     return mid;
     else if(arr[mid]<key)
     return rcb(key,mid+1,end);
     else
     return rcb(key,start,mid-1);
   
   
     }
  // Bubble Sort function
    void bubblesort() {
        for (int i = 1; i < n; i++) {
            for (int j = i; j > 0; j--) {
                if (arr[j] < arr[j - 1])
                    swap(arr[j], arr[j - 1]);
                else
                    break;
            }
        }
        for (int i = 0; i < n; i++) {
            cout << arr[i] << " ";
        }
        cout << endl;
    }
   
   
   
   

};

int main() {
    Search obj;
    int choice;
    do {
        cout << "1. Input Array" << endl;
        cout << "2. Binary Search" << endl;
        cout<< " 3. RecursiveBinary search"<<endl;
        cout << "4. Bubble Sort" << endl;
        cout << "5. Exit" << endl;
        cin >> choice;

        switch (choice) {
            case 1:
                obj.input();
                break;
            case 2: {
                int key;
                cout << "Enter the number to be searched" << endl;
                cin >> key;
                int result = obj.BinarySearch(key);
                if (result != -1) {
                cout<<endl;
                    cout << "Number found at index " << result << endl;
                } else {
                    cout << "Number not found" << endl;
                }
                break;
            }
            case 3: {
             int key;
             cout <<"Enter the number to be searched" <<endl;
             cin>>key;
             int result =obj.rcb(key,0,obj.n-1);
             if(result != -1) {
             cout<<endl;
             cout<< "Number found at index " <<result <<endl;
               }
               else {
                       cout<<" Number not found" <<endl;
                    }
                    break;
                   }
            case 4:
             obj.bubblesort();
                break;
               
                case 5:
                cout << "Exiting..." << endl;
                break;
               
            default:
                cout << "Invalid choice" << endl;
        }
    } while (choice != 5);

    return 0;
}
