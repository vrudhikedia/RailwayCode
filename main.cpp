// railway code for ticket booking

#include<iostream>
#include<string>
using namespace std;
string fname;
string lname;
string phno;
int adultcost;
int childcost;
int seniorcost;
int totalcost;
int no_ad;
int no_ch;
int no_se;
int age;
int seat0;
int seat1;
int seat2;
int seat3;

struct node {
    int seat_no;
    string pasname;
    node *next;
};

node *head1 = NULL;
node *head2 = NULL;
node *head3 = NULL;
node *head0 = NULL;

void insertbeg(int seat , node **head)
{
    node *first;
    first = new node;
    first->seat_no=seat;
    string name;
    name = fname + lname;
    first->pasname = name;
    first->next = *head;
    *head = first;
}

void display(node *head)
{
    node *current;
    current = head;
    cout<<"\n ";
    if(current==NULL)
    {
        cout<<"\n Linked lists is empty! ";
    }
    else
    {
        while(current!=NULL)
        {
            cout<<"\t"<<current->seat_no;
            cout<<"\t"<<current->pasname;
            current = current->next;
        }
    }
    cout<<"\n ";
}

int length(node *head)
{
    int len=0;
    node *temp = head;
    if(head==NULL)
    {
        return len;
    }
    else
    {
        while(temp!=NULL)
        {
            temp=temp->next;
            len++;
        }
    }
    return len;
}

void details()
{
    cout<<"\n Enter your first name: ";
    cin>>fname;
    cout<<"\n Enter your last name: ";
    cin>>lname;
    cout<<"\n Enter your phone number: ";
    cin>>phno;
    cout<<"\n Enter this passengers age: ";
    cin>>age;
    if(age<=5)
    {
        no_ch++;
    }
    else if(age>=60)
    {
        no_se++;
    }
    else
    {
        no_ad++;
    }
}

void firstclass(int no_ad , int no_ch , int no_se , node *head)
{
    adultcost = 3000;
    childcost = 1500;
    seniorcost = 2000;
    cout<<"\n Cost for Adults: "<<adultcost;
    cout<<"\n Cost for Children (below 5): "<<childcost;
    cout<<"\n Cost for Senior Citizens (above 60): "<<seniorcost;
    int ch;
    cout<<"\n 1. Book \t 2. Exit";
    cin>>ch;
    if (ch==1)
    {
        totalcost = (no_ad*adultcost) + (no_ch*childcost) + (no_se*seniorcost);
        cout<<"\n\n The cost to be paid is: "<<totalcost;
    }
    else
    {
        node *temp = head;
        head= head->next;
        delete temp;
        seat1--;
    }
}

void secondclass(int no_ad , int no_ch , int no_se , node *head)
{
    adultcost = 2500;
    childcost = 1250;
    seniorcost = 1500;
    cout<<"\n Cost for Adults: "<<adultcost;
    cout<<"\n Cost for Children (below 5): "<<childcost;
    cout<<"\n Cost for Senior Citizens (above 60): "<<seniorcost;
    int ch;
    cout<<"\n 1. Book \t 2. Exit";
    cin>>ch;
    if (ch==1)
    {
        totalcost = (no_ad*adultcost) + (no_ch*childcost) + (no_se*seniorcost);
        cout<<"\n\n The cost to be paid is: "<<totalcost;
    }
    else
    {
        node *temp = head;
        head= head->next;
        delete temp;
        seat2--;
    }
}

void thirdclass(int no_ad , int no_ch , int no_se , node *head)
{
    adultcost = 2100;
    childcost = 1050;
    seniorcost = 1100;
    cout<<"\n Cost for Adults: "<<adultcost;
    cout<<"\n Cost for Children (below 5): "<<childcost;
    cout<<"\n Cost for Senior Citizens (above 60): "<<seniorcost;
    int ch;
    cout<<"\n 1. Book \t 2. Exit";
    cin>>ch;
    if (ch==1)
    {
        totalcost = (no_ad*adultcost) + (no_ch*childcost) + (no_se*seniorcost);
        cout<<"\n\n The cost to be paid is: "<<totalcost;
    }
    else
    {
        node *temp = head;
        head= head->next;
        delete temp;
        seat3--;
    }
}

void sleeperclass(int no_ad , int no_ch , int no_se , node *head)
{
    adultcost = 1500;
    childcost = 750;
    seniorcost = 900;
    cout<<"\n Cost for Adults: "<<adultcost;
    cout<<"\n Cost for Children (below 5): "<<childcost;
    cout<<"\n Cost for Senior Citizens (above 60): "<<seniorcost;
    int ch;
    cout<<"\n 1. Book \t 2. Exit";
    cin>>ch;
    if (ch==1)
    {
        totalcost = (no_ad*adultcost) + (no_ch*childcost) + (no_se*seniorcost);
        cout<<"\n\n The cost to be paid is: "<<totalcost;
    }
    else
    {
        node *temp = head;
        head= head->next;
        delete temp;
        seat0--;
    }
}

void cancel(node *head , string name)
{
    node *temp = head;
    node *del = head->next;
    while(temp!=NULL)
    {
        if(name == temp->pasname)
        {
            del = temp;
            temp = temp->next;
            head = temp;
            delete del;
        }
        else
            temp = temp->next;
    }
    display(head);
}

int main()
{
    int n, cl,ch;
    seat0 = 1 ;
    seat1 = 1 ;
    seat2 = 1 ;
    seat3 = 1 ;
    no_ad = 0;
    no_ch = 0;
    no_se = 0;
    do
    {
        cout<<"\n Enter 1. Book tickets \t 2. Cancel Booking \t 3. Exit ";
        cin>>ch;
        switch(ch)
        {
        case 1:
            {
                cout<<"\n Enter 0. Sleeper class \t 1. First class \t 2. Second class \t 3. Third class \n";
                cin>>cl;
                switch(cl)
                {
                case 0:
                    {
                        cout<<"\n Enter the number of passengers traveling: ";
                        cin>>n;
                        for(int i = 0; i < n; i++)
                        {
                            details();
                            insertbeg(seat0, &head0);
                            seat0++;
                        }
                        sleeperclass(no_ad,no_ch,no_se, head0);
                        display(head0);
                        break;
                    }
                case 1:
                    {
                        cout<<"\n Enter the number of passengers traveling: ";
                        cin>>n;
                        for(int i = 0; i < n; i++)
                        {
                            details();
                            insertbeg(seat1, &head1);
                            seat1++;
                        }
                        firstclass(no_ad,no_ch,no_se,head1);
                        display(head1);
                        break;
                    }
                case 2:
                    {
                        cout<<"\n Enter the number of passengers traveling: ";
                        cin>>n;
                        for(int i = 0; i < n; i++)
                        {
                            details();
                            insertbeg(seat2, &head2);
                            seat2++;
                        }
                        secondclass(no_ad,no_ch,no_se,head2);
                        display(head2);
                        break;
                    }
                case 3:
                    {
                        cout<<"\n Enter the number of passengers traveling: ";
                        cin>>n;
                        for(int i = 0; i < n; i++)
                        {
                            details();
                            insertbeg(seat3, &head3);
                            seat3++;
                        }
                        thirdclass(no_ad,no_ch,no_se,head3);
                        display(head3);
                        break;
                    }
                }
                break;
            }
        case 2:
            {
                int ch;
                string name;
                cout<<"\n Enter the class of booking: ";
                cout<<"\n 1. First class \t 2. Second class \t 3. Third class \t 0. Sleeper class: ";
                cin>>ch;
                cout<<"\n Enter first name: ";
                cin>>fname;
                cout<<"\n Enter last name: ";
                cin>>lname;
                name = fname + lname;
                if(ch==1)
                {
                    cancel(head1 , name);
                }
                else if(ch==2)
                    cancel(head2 , name);
                else if(ch==3)
                    cancel(head3 , name);
                else if (ch==0)
                    cancel(head0 , name);
                else
                    cout<<"\n Invalid choice!";
                break;
            }
        }
    }while(ch!=3);
    return 0;
}
