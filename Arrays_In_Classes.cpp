#include <iostream>

using namespace std;

class Shop
{
    int itemCount = 0;
    int *itemId;
    int *itemPrice;

public:
    void getItem(void);
    void displayItem(void);
};

void Shop::getItem(void)
{
    cout << "Enter the number of items in your shop: ";
    cin >> itemCount;

    itemId = new int[itemCount];
    itemPrice = new int[itemCount];

    for (int i = 0; i < itemCount; i++)
    {
        cout << "Enter the id of item " << i + 1 << ": ";
        cin >> itemId[i];
        cout << "Enter the price of item " << i + 1 << ": ";
        cin >> itemPrice[i];
    }
}

void Shop::displayItem(void)
{
    for (int i = 0; i < itemCount; i++)
    {
        cout << "The item with ID: " << itemId[i] << " is Rs. " << itemPrice[i] << '\n';
    }
}

int main(void)
{
    Shop dukaan;
    dukaan.getItem();
    dukaan.displayItem();
    return 0;
}