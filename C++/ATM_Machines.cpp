#include <bits/stdc++.h>
using namespace std;

int i,j=0;

class account
{
private:
    char name[20];
    int time;
    double amount;

public:
    long acno;
    void get_data(char nm[], long n, double am)
    {
        strcpy(name, nm);
        acno = n;
        time = 1;
        cout << "\n Enter Duration ( for 3 yrs / 5 yrs) ..... \n else duration will be considered as 1 yr. ";
        int t;
        cin >> t;
        if (t == 3 || t == 5)
            time = t;
        amount = am;
    }

    void withdrw()
    {
        cout << "\n Enter the time period,that has passed after creating new fixed-deposit A/c :";
        int a;
        cin >> a;
        cout << "\n The amount to be drawn :";
        double d;
        cin >> d;

        if (a >= time / 2)
        {
            if (d <= amount)
                amount = amount - d;
            else
                cout << "\n Balance is less in your account.Abort !";
        }
        else
            cout << "\n Money can not be withdrawn. For details contact helpline.";
    }
    void display()
    {
        cout << "A/C No."
             << "\t"
             << "Name "
             << "\t\t"
             << "Amount"
             << "\n\n";
        cout << acno << "\t" << name << "\t\t" << amount << "\n\n";
    }

    void display_time()
    {
        cout << "\n A/c Duration = " << time << "yrs";
    }
};

int main()
{
    account customer[10];
    char ch = 'y';

    char nam[20];
    long acn;
    double amt;

    /* Input 10 customer's details  */
    for (i = 0; i < 10; i++)
    {
        cout << "\n Do you want to create a new account. Minimum duration is 1 yr";
        cout << "Enter (y /n) :";
        cin >> ch;

        if (ch!= 'y')
        {
            i--;
            break;
        }
        cout << "\n Enter name :";
        //gets(nam);
        cin>>nam;
        cout << "\n Enter A/c No. ";
        cin >> acn;
        cout << "\n Enter amount ";
        cin >> amt;

        customer[i].get_data(nam, acn, amt);
        j++;
    }

    /* Display 10 customer's details */
    for (i = 0; i <j; i++)
    {
        customer[i].display();
    }

    /* withdraw money */
    cout << "\n************** Do you Withdraw Money ........\n";
    cout << "\n You can withdraw money only when, after creating your A/c ,half of the time period has passed . ";
    cout << "\n Enter A/c No.";
    cin >> acn;
    for (i = 0; i <j; i++)
    {
        if (acn == customer[i].acno)
            customer[i].withdrw();
    }

    /* Display 10 customer's details */
    for (i = 0; i <j; i++)
    {
        customer[i].display();
    }

   return 0;
}
