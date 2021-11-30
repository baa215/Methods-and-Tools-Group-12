#include <iostream>
#include <iomanip>
#include <fstream>
#include <string>

using namespace std;

void addRecord(fstream&);
void viewRecord(fstream&);
void changeRecord(fstream&);
int menu();

const int DESC_SIZE = 21;
const int DATE_SIZE = 11;



int menu()
{
    int menuSelection = 0;//initialize

    cout << fixed << showpoint << setprecision(2);
    cout << "----------Inventory----------" << endl;
    cout << "1 - View inventory" << endl;
    cout << "2 - Add an item" << endl;
    cout << "3 - Edit an item" << endl;
    cout << "4 - End Program" << endl;

    //*** flush cin, this is inside a loop, it can cause problems
    cin.clear();
    fflush(stdin);
    cin >> menuSelection;

    return menuSelection;
}

int main()
{
    fstream dataFile("inventory.dat", ios::in | ios::out | ios::binary);
    if (dataFile.fail())
    {
        // The file does not exist, so create it.
        dataFile.open("inventory.dat", ios::out);
        dataFile.close();
    }

    for (;;)
    {
        int selection = menu();
        if (selection == 4)
            break;

        switch (selection)
        {
        case 1:
            viewRecord(dataFile);
            break;
        case 2:
            addRecord(dataFile);
            break;
        case 3:
            changeRecord(dataFile);
            break;
        default:
            cout << "Invalid - Please use 1 to 4" << endl;
            break;
        }
    }

    return 0;
}

void viewRecord(fstream& notused)
{
    fstream dataFile("inventory.dat", ios::in | ios::out | ios::binary);
    inventoryData item;
    while (dataFile)
    {
        dataFile.read(reinterpret_cast<char*>(&item), sizeof(item));
        // Display the record.
        cout << "Description: " << item.desc << endl;
        cout << "Quantity: " << item.quantity << endl;
        cout << "Wholesale Cost: " << item.wholesale << endl;
        cout << "Retail Cost: " << item.retail << endl;
        cout << "Date: " << item.date << endl;
        cout << endl;
    }
}

void addRecord(fstream& notused)
{
    fstream file("inventory.dat", ios::in | ios::out | ios::app | ios::binary);
    inventoryData item;

    cout << "Please enter the following data about the item" << endl;
    cout << "Description: ";
    cin.ignore();
    cin.getline(item.desc, DESC_SIZE);

    cout << "Quantity: ";
    cin >> item.quantity;

    cout << "Wholesale cost: ";
    cin >> item.wholesale;

    cout << "Retail price: ";
    cin >> item.retail;

    cout << "Date (Please use MO/DA/YEAR format: ";
    cin.getline(item.desc, DATE_SIZE);

    file.write(reinterpret_cast<char*>(&item), sizeof(item));

    return;
}