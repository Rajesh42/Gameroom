#include<bits/stdc++.h>
using namespace std;

void drawLine(int n, char symbol);
void rules();

int main()
{
    string Player;
    int amount;
    int bettingAmount;
    int guess;
    int dice;
    char choice;

    srand(time(0));

    drawLine(73, '_');
    cout << "\n\n\n" << "             " << "CASINO GAME\n\n\n\n";
    drawLine(73, '_');
    cout << "\n\nEnter Your Name : ";
    getline(cin, Player);
    do {
        cout << "\nEnter Amount greater than or equal to 100 ₹";
        cout << "\nEnter Deposit amount to play game : ₹ ";
        cin >> amount;
    } while (amount < 100);
    do
    {
        system("cls");
        rules();
        cout << "\nYour current balance is ₹ " << amount << "\n";
        do
        {
            cout << Player << ", enter money to bet : ₹";
            cin >> bettingAmount;
            if (bettingAmount > amount)
                cout << "Your betting amount " << bettingAmount << " is more than your current balance " << amount << "\n" << "\nRe-enter data\n ";
        } while (bettingAmount > amount);
        do
        {
            cout << "Guess your number to bet between 1 to 10 :";
            cin >> guess;
            if (guess <= 0 || guess > 10)
                cout << "Please check the number || should be between 1 to 10\n" << "\nRe-enter data\n ";
        } while (guess <= 0 || guess > 10);

        dice = rand() % 10 + 1;

        if (dice == guess)
        {
            cout << "\nWooo  luck is on your side || You won Rs." << bettingAmount * 10;
            amount = amount + bettingAmount * 15;
        }
        else
        {
            cout << "Bad Luck this time  || You lost Rs " << bettingAmount << "\n";
            amount = amount - bettingAmount;
        }

        cout << "\nThe winning number was : " << dice << "\n";
        cout << "\n" << Player << ", You have Rs " << amount << "\n";
        if (amount == 0)
        {
            cout << "You have no money to play ";
            break;
        }
        cout << "\n\n---->Do you want to play again (y/n)? ";
        cin >> choice;
    } while (choice == 'Y' || choice == 'y');

    cout << "\n\n";
    drawLine(73, '*');
    cout << "\n       Thanks for playing game. Your balance amount is Rs " << amount << "\n\n";
    drawLine(73, '*');

    return 0;
}

void drawLine(int n, char sym)
{
    for (int i = 0; i < n; i++)
        cout << sym;
    cout << "\n" ;
}

void rules()
{
    system("cls");
    cout << "\n\n";
    drawLine(73, '-');
    cout << "  RULES OF THE GAME :\n";
    drawLine(73, '-');
    cout << "  1. Choose any number between 1 to 10\n";
    cout << "  2. If you win you will get 10 times of money you bet\n";
    cout << "  3. If you bet on wrong number you will lose your betting amount\n\n";
    drawLine(73, '-');
}
