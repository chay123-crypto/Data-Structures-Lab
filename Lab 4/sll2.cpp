/*Ascending sort and merge lists in linked lists using classes*/
#include <iostream>
#include "functions.h"
using namespace std;

int main()
{
    linkedl arr1, arr2, merged;
    int choice, size, val;

    do
    {
        cout << "//MENU//" << endl;
        cout << "1. Create the first list using insert ascending" << endl;
        cout << "2. Create the second list using insert ascending" << endl;
        cout << "3. Merge the two lists and display the merged list" << endl;
        cout << "4. Display the created lists" << endl;
        cout << "5. Exit the program" << endl;
        cout << "Enter your choice: ";
        cin >> choice;

        if(choice > 5)
        {
            cout << "Enter a valid choice!" << endl;
        }
        if(choice == 1)
        {
            cout << "Enter size of first list: ";
            cin >> size;
            arr1.create(size);
        }

        if(choice == 2)
        {
            cout << "Enter size of second list: ";
            cin >> size;
            arr2.create(size);
        }
        if(choice == 3)
        {
            merged.merge(arr2);
            cout << "Lists merged successfully." << endl;
            merged.display();
        }
        if(choice == 4)
        {
            cout << "First list: ";
            arr1.display();
            cout << "Second list: ";
            arr2.display();
        }
        if(choice == 5)
        {
            cout<<"Exiting the program..." << endl;
        }
    } while (choice != 5);
    return 0;
}
