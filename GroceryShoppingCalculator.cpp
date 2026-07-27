// GroceryShoppingCalculator.cpp
// Console-based grocery shopping calculator
// Author: Kelvin Kyei Baffour

#include <iostream>
#include <iomanip>
#include <string>

using namespace std;

int main() 
{

    string name;
    double price1, price2;
    int quantity1, quantity2;
    const double TAX_RATE = 0.07;

    // User input
    cout << "Enter your name: ";
    getline(cin, name);

    cout << "\nEnter the price of item 1: ";
    cin >> price1;
    cout << "Enter the quantity of items purchased: ";
    cin >> quantity1;

    cout << "\nEnter the price of item 2: ";
    cin >> price2;
    cout << "Enter the quantity of items purchased: ";
    cin >> quantity2;

    double subtotal = (price1 * quantity1) + (price2 * quantity2);

    // The single IF
    if (subtotal >= 200.0 && subtotal <= 800.0) 
    {
        cout << "\nYou are close to the discount threshold!\n";
    }

    int choice = 0;

    cout << "\nWhich Offer would you like to choose?\n";
    cout << "1. BOGO - Buy one get one free\n";
    cout << "2. Purchase goods only to get 5% discount\n";
    cout << "3. Choose your own discount (1-5%)\n";
    cout << "4. If you have an account with us you gain 10% discount\n";
    cout << "5. Quit with no goods made\n";
    cout << "choice (1-5): ";
    cin >> choice;

    cout << "Your choice was " << choice << endl;

    // Checking Of Range
    if (choice < 1 || choice > 5) 
    {
        cout << "\nInvalid choice. Exiting \n";
        return 0;
    }

    // The two outcomes of IF-ELSE
    if (choice == 5) 
    {
        cout << "\nYou chose to quit. Thank you! \n";
        return 0;
    }
    else {
        cout << "\nGreat! This is your Total per your choice \n";
    }

    double discountChosen = 0.0;
    double newSubtotal = subtotal;

    // IF-ELSEIF-ELSE
    if (choice == 1) 
    {
        int paymentofQuantity1 = (quantity1 / 2) + (quantity1 % 2);
        int paymentofQuantity2 = (quantity2 / 2) + (quantity2 % 2);
        newSubtotal = (price1 * paymentofQuantity1) + (price2 * paymentofQuantity2);
    }
    else if (choice == 2) 
    {
        discountChosen = 5.0;
    }
    else if (choice == 3) 
    {
        cout << "\nEnter your discount percent (1-5): ";
        cin >> discountChosen;

        if (discountChosen < 1 || discountChosen > 5) {
            cout << "\nInvalid Choice of discount. Exiting \n";
            return 0;
        }
    }
    else { // this is when the choice == 4
        discountChosen = 10.0;
    }

    // Calculation of the total shopping
    double discountOFAmount = newSubtotal * (discountChosen / 100.0);
    double taxable = newSubtotal - discountOFAmount;
    double salestax = taxable * TAX_RATE;
    double total = taxable + salestax;

    cout << fixed << setprecision(2) << showpoint;

    cout << "\nCustomer:       " << name << endl;
    cout << "Subtotal:                   $" << newSubtotal << endl;
    cout << "Discount:                    $" << discountOFAmount << endl;
    cout << "Sales Tax:                   $" << salestax << endl;
    cout << "------------------------------------\n";
    cout << "Total Cost:                 $" << total << endl;

    return 0;
}
