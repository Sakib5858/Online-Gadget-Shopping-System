//Online Gadget shopping System in C++ programming language
//Author: Afzal Hossain Sakib

//   *********Important notice***********

//In this program in user interface username: sakib  --> password: 1234

//In this program in user interface username: afzal  --> password: 4567

#include<bits/stdc++.h>
using namespace std;

struct productt
{

    int p_quantity;
    int p_price;
    string p_name;
};
struct productt computerr;
struct productt compu[100];
struct productt mobile_phon;
struct productt mob[100];

int mcount,ccount;
int mgloblavar = 0;
int cgloblavar = 0;

void log_in_system(int n)
{
    int password;
    string username;
    switch(n)
    {
    case 1:
    {
user1:
        cout<<"     -----------------------------------------------------------------------------------------------------------------\n";
        cout<<"\n     Enter your username : ";
        cin>>username;
        if(username.compare("sakib")==0 && n==1)
        {
pass1:
            cout<<"\n     Enter your password : ";
            cin>>password;
            if(password!=1234)
            {
                cout<<"\nPassword is wrong !!!!>>>>>>Plese enter the correct password:";
                goto pass1;
            }
        }
        else
        {
            printf("\n     !!!!!!!!Username is wrong !!!!!!>>>>>>Put correct username: \n");
            goto user1;
        }
    }
    break;
    case 2:
    {
user2:
        cout<<"\n     Enter your username :";
        cin>>username;
        if(username.compare("afzal")==0 && n==2)
        {
pass2:
            cout<<"     Enter your password :";
            cin>>password;
            if(password!=4567)
            {
                cout<<"\n     Password is wrong !!!!>>>>>>>Plese enter the correct password:";
                goto pass2;
            }
        }
        else
        {
            printf("\n     Username is wrong !!!!!!>>>>>>>>Put correct username:\n");
            goto user2;
        }
    }
    break;
    }
}

int Display()
{
    int ch,i=0;
    cout<<"\n     -----------------------------------------------------------------------------------------------------------------\n";
    cout<<"\n\n     1. Computer accessories\n     2. Mobile accessories\n\n     Enter your choice :";
    cin>>ch;
    if(ch==1)
    {
        if(compu[i].p_name.length() == 0)
            cout<<"\n     Sorry!! No product are available!!!\n";
        else
        {
            cout<<"\n\n-------------          ---------        -----------\n"<<"Product Name\t\tPrice\t \tQuantity\n"<<"---------------          -------        ----------\n";
            while(i<ccount)
            {
                cout<<i+1<<". "<<compu[i].p_name<<"                 "<<compu[i].p_price<<"        "<<compu[i].p_quantity<<endl;
                i++;
            }
            return 1;
        }
    }
    else if(ch==2)
    {
        if(mob[i].p_name.length() == 0)
            cout<<"\n     Sorry!! No product are available!!!\n";
        else
        {
            cout<<"\n\n-------------          ---------        ----------\n"<<"Product Name\t\tPrice\t \t Quantity\n"<<"---------------          -------        ----------\n";
            while(i<mcount)
            {
                cout<<i+1<<". "<<mob[i].p_name<<"                 "<<mob[i].p_price<<"        "<<mob[i].p_quantity<<endl;
                i++;
            }
            return 2;
        }
    }
}

void add_product()
{
    int ch,cho;
    cout<<"     1. Computer accessories\n     2. Mobile accessories\n\n     Enter your choice :";
    cin>>ch;
    if(ch==1)
    {
level2:
        fstream computer;
        computer.open("computer_details_pro.txt",ios::out|ios::app);
        cout<<"\n\n     Enter product name :";
        // getline(cin,computerr.p_name);
        cin>>computerr.p_name;
        computer<<computerr.p_name<< endl;
        cin.ignore();
        computer.close();

        fstream computerprice;
        computerprice.open("computer_details_pri.txt",ios::out|ios::app);
        cout<<"\n     Enter product price :";
        cin>>computerr.p_price;
        computerprice<< computerr.p_price <<endl;
        cin.ignore();
        computerprice.close();

        fstream c_quan;
        c_quan.open("computer_quantity_details.txt",ios::out|ios::app);
        cout<<"\n     Enter product quantity :";
        cin>>computerr.p_quantity;
        c_quan<< computerr.p_quantity <<endl;
        cin.ignore();
        c_quan.close();
        cout<<"\n\n     1. Add more\n     2. Don't add any more\n     Enter your choice :";
        cin>>cho;
        if(cho==1)
            goto level2;
    }
    else if(ch==2)
    {
level22:
        fstream mobile;
        mobile.open("Mobilephone_details_pro.txt",ios::out|ios::app);
        cout<<"     Enter product name :";
        getline(cin,computerr.p_name);
        cin>>mobile_phon.p_name;
        mobile<< mobile_phon.p_name << endl;
        cin.ignore();
        mobile.close();

        fstream mobilepri;
        mobilepri.open("Mobilephone_details_pri.txt",ios::out|ios::app);
        cout<<"     Enter product price :";
        cin>>mobile_phon.p_price;
        mobilepri<< mobile_phon.p_price <<endl;
        cin.ignore();
        mobilepri.close();

        fstream m_quan;
        m_quan.open("Mobile_quantity_details.txt",ios::out|ios::app);
        cout<<"\n     Enter product quantity :";
        cin>>computerr.p_quantity;
        m_quan<< computerr.p_quantity <<endl;
        cin.ignore();
        m_quan.close();
        cout<<"\n\n     1. Add more\n     2. Don't add any more\n     Enter your choice :";
        cin>>cho;
        if(cho==1)
            goto level2;
    }
}
void update_product()
{
    int i,c,ch,uprice,uquan;
    cout<<"\n     Which product do you want to update :\n";
    ch=Display();
    cout<<"\n     Enter the choice :";
    cin>>c;
    cout<<"\n     Enter updated price :";
    cin>>uprice;
    cout<<"\n     Enter updated quantity :";
    cin>>uquan;
    if(ch==1)
    {
        cout<<"\n\n<<<<<<<<<"<<compu[c-1].p_price<<" are updated to "<<uprice<<">>>>>>>>>>\n";
        cout<<"\n\n<<<<<<<<<"<<compu[c-1].p_quantity<<" quantity are updated to "<<uquan<<">>>>>>>>>>\n";
        compu[c-1].p_price=uprice;
        fstream computerprice;
        computerprice.open("computer_details_pri.txt",ios::out|ios::trunc);
        for(i=0; i<ccount; i++)
            computerprice<< compu[i].p_price << endl;
        computerprice.close();

        fstream c_quan;
        c_quan.open("computer_quantity_details.txt",ios::out|ios::trunc);
        for(i=0; i<ccount; i++)
            c_quan<< compu[i].p_quantity <<endl;
        cin.ignore();
        c_quan.close();

    }
    else if(ch==2)
    {
        cout<<"\n\n<<<<<<<<<"<<mob[c-1].p_price<<" are updated to "<<uprice<<">>>>>>>>>>\n";
        cout<<"\n\n<<<<<<<<<"<<compu[c-1].p_quantity<<" quantity are updated to "<<uquan<<">>>>>>>>>>\n";
        mob[c-1].p_price=uprice;
        fstream mobilepri;
        mobilepri.open("Mobilephone_details.txt",ios::out|ios::trunc);
        for(i=0; i<mcount; i++)
            mobilepri<<mob[i].p_price<<endl;
        mobilepri.close();

        fstream m_quan;
        m_quan.open("Mobile_quantity_details_pri.txt",ios::out|ios::trunc);
        for(i=0; i<ccount; i++)
            m_quan<< mob[i].p_quantity <<endl;
        m_quan.close();
    }
}
int delet_product()
{
    int i,ch,position;
    ch=Display();
    cout<<"\n     Which product do you want to delete :\n";
    cout<<"\n     Enter the choice :";
    cin>>position;
    position=position-1;

    if(ch==1)
    {
        cout<<"\n\n     >>>>>"<<compu[position].p_name<<" are deleted <<<<<<\n\n";
        for(i=position; i<ccount; i++)
        {
            compu[i].p_name=compu[i+1].p_name;
            compu[i].p_price=compu[i+1].p_price;
            compu[i].p_quantity=compu[i+1].p_quantity;
        }
        ccount=ccount-1;
        return 1;
    }

    else if(ch==2)
    {
        cout<<"\n\n     >>>>>"<<mob[position].p_name<<" are deleted <<<<<<\n\n";
        for(i=position; i<ccount; i++)
        {
            mob[i].p_name=mob[i+1].p_name;
            mob[i].p_price=mob[i+1].p_price;
            mob[i].p_quantity=mob[i+1].p_quantity;
        }
        mcount=mcount-1;
        return 2;
    }

}

void store_data()
{
    int a,i=0;
    string myText;

    ifstream computerprice("computer_details_pri.txt");
    while(computerprice >> a)
    {
        compu[i].p_price=a;
        i++;
    }
    computerprice.close();
    ccount=i;

    i=0;
    ifstream computer("computer_details_pro.txt");
    while(getline(computer,computerr.p_name))
    {
        compu[i].p_name=computerr.p_name;
        i++;
    }
    computer.close();

    i=0;
    ifstream c_quan("computer_quantity_details.txt");
    while(c_quan >> a)
    {
        compu[i].p_quantity=a;
        i++;
    }
    c_quan.close();

    i=0;
    ifstream mobile("Mobilephone_details_pro.txt");
    while(getline(mobile,mobile_phon.p_name))
    {
        mob[i].p_name=mobile_phon.p_name;
        i++;
    }
    mobile.close();
    mcount=i;

    i=0;
    ifstream mobilepri("Mobilephone_details_pri.txt");
    while(mobilepri >> a)
    {
        mob[i].p_price=a;
        i++;
    }
    mobilepri.close();

    i=0;
    ifstream m_quan("Mobile_quantity_details.txt");
    while(m_quan >> a)
    {
        mob[i].p_quantity=a;
        i++;
    }
    m_quan.close();
}

void update_file(int a)
{
    int i;
    if(a==1)
    {
        fstream computer;
        computer.open("computer_details_pro.txt",ios::out|ios::trunc);
        for(i=0; i<ccount; i++)
            computer<< compu[i].p_name << endl;
        computer.close();

        fstream computerprice;
        computerprice.open("computer_details_pri.txt",ios::out|ios::trunc);
        for(i=0; i<ccount; i++)
            computerprice<< compu[i].p_price << endl;
        computerprice.close();

        fstream c_quan;
        c_quan.open("computer_quantity_details.txt",ios::out|ios::trunc);
        for(i=0; i<ccount; i++)
            c_quan<< compu[i].p_quantity << endl;
        c_quan.close();
    }
    else
    {
        fstream mobile;
        mobile.open("Mobilephone_details_pro.txt",ios::out|ios::trunc);
        for(i=0; i<mcount; i++)
            mobile<<mob[i].p_name<<endl;
        mobile.close();

        fstream mobilepri;
        mobilepri.open("Mobilephone_details_pri.txt",ios::out|ios::trunc);
        for(i=0; i<mcount; i++)
            mobilepri<<mob[i].p_price<<endl;
        mobilepri.close();

        fstream m_quan;
        m_quan.open("Mobile_quantity_details.txt",ios::out|ios::trunc);
        for(i=0; i<mcount; i++)
            m_quan<< mob[i].p_quantity << endl;
        m_quan.close();
    }
}

int sort_display()
{
    int i,k,j,size;
    cout<<"\n     -----------------------------------------------------------------------------------------------------------------\n";
    cout<<"     1. Computer accesories\n     2. Mobile accesories\n     Enter your choice :";
    cin>>k;
    if(k==1)
    {
        size=ccount;
        for(j=0; j<size-1; j++)
        {
            for(i=0; i<size-1-j; i++)
            {
                if(compu[i].p_price>compu[i+1].p_price)
                {
                    swap(compu[i].p_price,compu[i+1].p_price);
                    compu[i].p_name.swap(compu[i+1].p_name);
                    swap(compu[i].p_quantity,compu[i+1].p_quantity);
                }
            }
        }
        cout<<"\n\n     -------------          ---------        ----------\n"<<"     Product Name\t     Price\t      Quantity\n"<<"     -------------          -------        ----------\n";

        for(i=0; i<size; i++)
            cout<<"     "<<i+1<<". "<<compu[i].p_name<<"                 "<<compu[i].p_price<<"        "<<compu[i].p_quantity<<endl;

        return 1;
    }
    else
    {
        size=mcount;
        for(j=0; j<size-1; j++)
        {
            for(i=0; i<size-1-j; i++)
            {
                if(mob[i].p_price>mob[i+1].p_price)
                {
                    swap(mob[i].p_price,mob[i+1].p_price);
                    mob[i].p_name.swap(mob[i+1].p_name);
                    swap(mob[i].p_quantity,mob[i+1].p_quantity);
                }
            }
        }
        cout<<"\n\n-------------          ---------        ----------\n"<<"Product Name\t\tPrice\t \t Quantity\n"<<"---------------          -------        ----------\n";

        for(i=0; i<size; i++)
            cout<<i+1<<". "<<mob[i].p_name<<"                 "<<mob[i].p_price<<"        "<<mob[i].p_quantity<<endl;

        return 2;
    }
}

void searchh()
{
    int i,j;
    cout<<"\n\n     1. Computer accesories\n     2. Mobile accesories\n     Enter your choice :";
    cin>>i;
    if(i==1)
    {
        cout<<"\n     Enter the product name :";
        cin>>computerr.p_name;
        for(j=0; j<ccount; j++)
        {
            if(computerr.p_name.compare(compu[j].p_name)==0)
            {
                cout<<"\n     ---------------------\nProduct found !!\n     Product name :"<<compu[j].p_name<<"\n     Price :"<<compu[j].p_price<<"\n     Quantity :"<<compu[i].p_quantity<<endl<<endl;
                break;
            }
        }
    }
    else
    {
        cout<<"\n\n     Enter the product name :";
        cin>>computerr.p_name;
        for(j=0; j<mcount; j++)
        {
            if(computerr.p_name.compare(mob[j].p_name)==0)
            {
                cout<<"\n     ----------------------\nProduct found !!\n     Product name :"<<mob[j].p_name<<"\n     Price :"<<mob[j].p_price<<"\n     Quantity :"<<mob[i].p_quantity<<endl<<endl;
                break;
            }
        }
        if(j==mcount)
            cout<<"Sorry!!The product is no longer available..\n";
    }
}

int main()
{
    int choice[2],sum=0;
    cout<<"\t\t\t\t\t----------------------------------\n";
    cout<<"\t\t\t\t\tWelcome to Tech source Gadget Shop \n";
    cout<<"\t\t\t\t\t----------------------------------\n\n";
home:
    store_data();
    cout<<"\n\n     1. Customer Interface\n     2. Manager Interface\n     3. Exit\n\n\n     Enter your choice  :  ";
    cin>>choice[0];
    switch(choice[0])
    {
    case 1:
    {
        if(mgloblavar==0)
        {
             log_in_system(1);
            mgloblavar++;
        }
previous1:

        cout<<"\n     -----------------------------------------------------------------------------------------------------------------\n";
        cout<<"\n     1. Display Product\n     2. Buy product \n     3. Search product\n     4. Exit\n     Enter your choice :";
        cin>>choice[0];
        switch(choice[0])
        {
        case 1:
            cout<<"\n     -----------------------------------------------------------------------------------------------------------------\n";
            cout<<"\n     1. Sorted display\n     2. Random display\n\n     Enter your choice :";
            cin>>choice[1];
            if(choice[1]==1)
                sort_display();
            else
                Display();
            cout<<"\n\n\n     1. Home page\n     2. Previous page\n\n     Enter your choice :";
            cin>>choice[1];
            if(choice[1]==1)
                goto home;
            else if(choice[1]==2)
                goto previous1;
            break;
        case 2:
        {
            sum=0;
            cout<<endl<<endl;
            int i=sort_display();
            cout<<"\n\n     Which product do you want to buy ?  ";
            cin>>choice[0];
            if(i==1 && compu[choice[0]-1].p_quantity>0 ||i==2 && mob[choice[0]-1].p_quantity>0)
            {
                cout<<"\n     Enter the quantity :";
                cin>>choice[1];
                if(i==1)
                {
                    sum=sum+(choice[1]*compu[choice[0]-1].p_price);
                    cout<<"\n\n     -----------------------------------------------------------------------------------------------------------------";
                    cout<<"       $$$$$$$$ Total bill is  :"<<sum<<" BDT$$$$$$$$";
                    cout<<"\n     -----------------------------------------------------------------------------------------------------------------\n";
                    compu[choice[0]-1].p_quantity=compu[choice[0]-1].p_quantity - choice[1];
                    update_file(1);
                }
                else
                {
                    sum=sum+(choice[0]*mob[choice[0]-1].p_price);
                    cout<<"\n\n     *****Total bill is  :"<<sum<<" BDT\n\n";
                    mob[choice[0]-1].p_quantity=mob[choice[0]-1].p_quantity - choice[1];
                    update_file(2);
                }



                fstream p_details;
                p_details.open("Person_details.txt",ios::out|ios::app);
                cout<<"\n     Enter your name :";
                cin>>computerr.p_name;
                p_details<<"\n------------Person Details\n--------------\nName :"<< computerr.p_name << endl;
                cout<<"\n     Enter your Address :";
                cin>>computerr.p_name;
                p_details<<"\nAddress :"<< computerr.p_name << endl;
                cout<<"\n     Enter your Contact number :";
                cin>>computerr.p_name;
                p_details<<"\n    Contact number :"<< computerr.p_name <<endl;
                if(i==1)
                {
                    p_details<<"\nProduct name :"<< compu[choice[0]-1].p_name<<"\nQuantity :"<<choice[1]<<"\nTotal bill :"<<sum<<endl;
                }
                else
                    p_details<<"\nProduct name :"<< mob[choice[0]].p_name<<"\nQuantity :"<<choice[1]<<"\nTotal bill :"<<sum<<endl;
                cin.ignore();
                p_details.close();

                cout<<"\n\n     *****Thanks for purchasing from us*********\n";
            }
            else
                    cout<<"\n\n     !!!!Sorry,Sufficient product are not avaiable!!!!!\n";

            cout<<"\n\n     1. Home page\n     2. Previous page\n\n     Enter your choice :";
            cin>>choice[1];
            if(choice[1]==1)
                goto home;
            else if(choice[1]==2)
                goto previous1;
        }
        break;

        case 3:
            searchh();
            cout<<"\n\n\n     1. Home page\n     2. Previous page\n\n     Enter your choice :";
            cin>>choice[1];
            if(choice[1]==1)
                goto home;
            else if(choice[1]==2)
                goto previous1;
            break;
        case 4:
            cout<<"\n\n\t***********Thanks for visiting our shop*************\n\n";
            return 0;
            break;
        }
    }
    break;
    case 2:
    {
previous:
        if(cgloblavar==0)
        {
             log_in_system(2);
            cgloblavar++;
        }
        cout<<"\n\n     1. Display\n     2. Add new product\n     3. Product Update\n     4. Delete product \n\n     Enter your choice  ";
        cin>>choice[0];
        switch(choice[0])
        {
        case 1:
            Display();
            cout<<"\n\n     1. Home page\n     2. Previous page\n\n     Enter your choice :";
            cin>>choice[1];
            if(choice[1]==1)
                goto home;
            else if(choice[1]==2)
                goto previous;
            break;
        case 2:
            add_product();
            store_data();
            cout<<"\n\n\n     1. Home page\n     2. Previous page\n\n    Enter your choice :";
            cin>>choice[1];
            if(choice[1]==1)
                goto home;
            else if(choice[1]==2)
                goto previous;
            break;
        case 3:
            update_product();
            cout<<"\n\n     1. Home page\n     2. Previous page\n\n     Enter your choice :";
            cin>>choice[1];
            if(choice[1]==1)
                goto home;
            else if(choice[1]==2)
                goto previous;
            break;
        case 4:
        {
            int d= delet_product();
            update_file(d);
            cout<<"\n\n\n     1. Home page\n     2. Previous page\n\n     Enter your choice :";
            cin>>choice[1];
            if(choice[1]==1)
                goto home;
            else if(choice[1]==2)
                goto previous;
        }
        break;
        }
    }
    case 3:
        cout<<"\n\n\t***********Thanks for visiting our shop*************\n\n\n";
        return 0;
    }
}

