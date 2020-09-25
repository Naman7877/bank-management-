#include <iostream>
#include <string>

using namespace std;
class date
{
protected:
    int day;
    int month;
    int year;

public:
    void setdate()
    {
        cout << "enter opning the date,month,year" << endl;
        cin >> day >> month >> year;
    }
    void display_date()
    {
        cout << "the date is " << day << "/" << month << "/" << year << endl;
    }
};

class ammount
{
    char name[20];
    int accountnum;
    char account_type[8];

public:
    void set_account_detail()
    {

        cout << "enter the name of account number" << endl;
        cin >> accountnum;
        cout << "enter account holder name" << endl;
        cin >> name;
        cout << "enter the name of account type (saving / current) " << endl;
        cin >> account_type;
    }

    void show_detail()
    {
        cout << "the detaill of account holder is  " << name << endl;
        cout << "The account number is " << accountnum << endl;
        cout << "the type of accont is " << account_type << endl;
    }
};

class saving : public ammount, public date
{
    int balance;
    int intrest;
    int min_valance;

public:
    void set_saving_account_value()
    {
        set_account_detail();
        cout << "Enter the previos balance of the account holder" << endl;
        cin >> balance;
        min_valance=2000;
        setdate();
    }

    void deposit_money()
    {
        int n;
        cout << "enter the amount deposit in account" << endl;
        cin >> n;
        balance = balance + n;
    }

    void withdrawl_money()
    {
        int n;
        cout << "enter the amount withdrawl in account" << endl;
        cin >> n;
        if (n < balance)
            balance = balance - n;
        else
        {
            cout << " less balance................ " << endl;
        }
    }

    /*  void deposit_intrest()
    {
        int p=balance;
        int time;

    }*/
    void check_min_balance()
    {
        if (balance > min_valance)
        {
            cout << "your account contain min balance " << balance << endl;
        }
        else
        {
            cout << "your account contain less money than min valance " << endl;
            cout << "then charge fine -😢-" << endl;
            balance = balance - 200;
        }
    }

    void check_balance()
    {
        cout << " your account balance is = " << balance << endl;
    }
    void detail()
    {
        show_detail();
        display_date();
        cout << "The min balance is  " << min_valance << endl;
    }
};

// second class
class current : public ammount, public date
{
    int balance;
    int intrest;
    int min_valance;

public:
    void set_current_account_value()
    {
        set_account_detail();
        cout << "Enter the previos balance of the account holder" << endl;
        cin >> balance;
        min_valance=40000;
        setdate();
    }

    void deposit_money()
    {
        int n;
        cout << "enter the amount deposit in account" << endl;
        cin >> n;
        balance = balance + n;
    }

    void withdrawl_money()
    {
        int n;
        cout << "enter the amount withdrawl in account" << endl;
        cin >> n;
        if (n < balance)
            balance = balance - n;
        else
        {
            cout << " less balance................ " << endl;
        }
    }

    /*  void deposit_intrest()
    {
        int p=balance;
        int time;

    }*/
    void check_minbalance_current()
    {
        if (balance > min_valance)
        {
            cout << "your account contain min balance " << balance << endl;
        }
        else
        {
            cout << "your account contain less money than min valance " << endl;
            cout << "then charge fine -😢-" << endl;
            balance = balance - 200;
        }
    }

    void check_current_balance()
    {
        cout << " your account balance is = " << balance << endl;
    }
    void current_detail()
    {
        show_detail();
        display_date();
        cout << "The min balance is  " << min_valance << endl;
    }
};

int main()
{
    saving s1;
    current c1;
    cout << " Please enter which type of account you want to open type  " << endl;
    cout << " There are two type of account (saving/current) " << endl;
    string type;
    getline(cin, type);
    if (type == "saving")
    {

        while (1)
        {
            int n;
            cout << "enter your choise" << endl;
            cout << "*******************************************" << endl;
            cout << endl;
            cout << "| 1. Fill Detail of saving accoun | " << endl;
            cout << "| 2. Deposit money                | " << endl;
            cout << "| 3. withdwawl money              | " << endl;
            cout << "| 4. check min balance            | " << endl;
            cout << "| 5. display balance              | " << endl;
            cout << "| 6. view account detail          | " << endl;
            cout << "| 7. Exit                         | " << endl;
            cout << endl;
            cout << "*******************************************" << endl;

            cin >> n;
            switch (n)
            {
            case 1:
                s1.set_saving_account_value();

                break;

            case 2:
                s1.deposit_money();
                break;

            case 3:
                s1.withdrawl_money();
                break;

            case 4:
                s1.check_min_balance();
                break;

            case 5:
                s1.check_balance();
                break;
            case 6:
                s1.detail();
                break;
            case 7:
                exit(1);
            }
        }
    }

    else
    {
        while (1)
        {
            int n;
            cout << "enter your choise" << endl;
            cout << "*******************************************" << endl;
            cout << endl;
            cout << "| 1. Fill Detail of current accoun| " << endl;
            cout << "| 2. Deposit money                | " << endl;
            cout << "| 3. withdwawl money              | " << endl;
            cout << "| 4. check min balance            | " << endl;
            cout << "| 5. display balance              | " << endl;
            cout << "| 6. view account detail          | " << endl;
            cout << "| 7. Exit                         | " << endl;
            cout << endl;
            cout << "*******************************************" << endl;

            cin >> n;
            switch (n)
            {
            case 1:
                c1.set_current_account_value();

                break;

            case 2:
                c1.deposit_money();
                break;

            case 3:
                c1.withdrawl_money();
                break;

            case 4:
                c1.check_minbalance_current();
                break;

            case 5:
                c1.check_current_balance();
                break;
            case 6:
                c1.current_detail();
                break;
            case 7:
                exit(1);
            }
        }
    }

    return 0;
}