#include<iostream>
#include<fstream>
#include<string.h>
#include<conio.h>
#include<iomanip>
#include<windows.h>
#include<ctime>
using namespace std;

class Menu
{
protected:
int num;
char pizza[22]={0};     //Name of Pizza
int price_small,price_medium,price_large;
static int total_num_items;
friend class Orders;
friend class Initializer;
public:
Menu()   //Default Constructor
{

}
Menu(const int num,const char pizza[15],const int price_small,const int price_medium,const int price_large)
{
this->num=num;
strcpy(this->pizza,pizza);
this->price_small=price_small;
this->price_medium=price_medium;
this->price_large=price_large;
total_num_items++;
}

void add_new_pizza()
{
cout<<"Enter Serial No. :";
cin>>num;
cout<<"Enter the Name of Pizza: ";
cin>>pizza;
cout<<"Enter price of small pizza:";
cin>>price_small;
cout<<"Enter price of medium pizza:";
cin>>price_medium;
cout<<"Enter price of large pizza:";
cin>>price_large;
total_num_items++;
cout<<"Pizza added to menu Successfully.\n";
}
void display_all_pizza()
{
ifstream fin;
fin.open("Menu.txt");

	if(!fin)
	{
		cout<<"File cannot opened...!!"<<endl;
	}
	else
	{
    cout << left <<setw(10)<<"S.NO:" << "Pizza Name:"<< right <<setw(17)  << "Small:"<< right <<setw(10);
    cout <<"Medium:"<< right <<setw(10)  << "Large:"<<endl;
	
	do	
    {	
	if((fin.read((char*)this, sizeof(*this))))
	{

		display();
	}
	
	else
	{
		break;
	}
}while(!fin.eof());

fin.close();
}	
}

void store()
{
ofstream file;
file.open("Menu.txt",ios::app);
if(file.is_open())
{
	file.write( (char*)this , sizeof(*this) );
	file.close();
}
else
{
	cout<<"File doesn't open...!!"<<endl;
}
}


void display()
{
    int i;
 cout << left <<setw(10)<<num; 
 for(i=0;i<22;i++)
 {
     if(pizza[i]==0)
     cout<<" ";
     else
    cout<< pizza[i];
 }  
 cout<<"  "<<left <<setw(10)<< price_small;
 cout <<price_medium<< right <<setw(10)  << price_large<<endl;
}

int get_total_num_of_items() const
{
	return total_num_items;
}

};
int Menu::total_num_items=0;
//-------------------------------------------------------------------------------------------------------------------

class Deals
{
int num;
char deal_name[35]={0};
int price;
static int total_deals;
friend class Orders;

public:
Deals()
{

}
Deals(const int num,const char deal_name[35],const int price)
{
this->num=num;
strcpy(this->deal_name,deal_name);
this->price=price;
total_deals++;
}

void dispaly_deal(Deals d[])
{
int i,j;
cout << left <<setw(10)<<"S.NO:" << "Deal Name:"<< right <<setw(38)  << "Price:"<<endl;
for(i=0;i<total_deals;i++)
{
cout << left <<setw(10)<<d[i].num ;
for(j=0;j<30;j++)
cout<< d[i].deal_name[j];
cout<< right <<setw(17)<<d[i].price<<endl;
}
}

void store()
{
ofstream file;
file.open("Deals.txt",ios::app);
if(file.is_open())
{
	file.write((char*)this , sizeof(*this));
	file.close();
}
else
{
	cout<<"File doesn't open...!!"<<endl;
}
}
};
int Deals::total_deals=0;


class Branch:public Menu
{
protected:
int branch_num;
char branch_name[30];
char branch_address[30];
int earnings;
static int total_Branches;
friend class orders;
friend class Initializer;
public:

Branch()
{

}

Branch(const int branch_num,const char branch_name[20],const char branch_address[20])
{
this->branch_num=branch_num;
strcpy(this->branch_name,branch_name);
strcpy(this->branch_address,branch_address);
this->earnings=0;
total_Branches++;
}

void set_New_Branch()
{
cout<<"Please enter the number of Branch: ";
cin>>branch_num;
cout<<"Please enter the name of Branch: ";
cin>>branch_name;
cout<<"Please enter the address of Branch: ";
cin>>branch_address;
earnings=0;
total_Branches++;
}

void update_earning(int x)
{
earnings=earnings+x;
delete_everything();
}

int get_earning()
{
	return earnings;
}


void display_name()
{
cout<<branch_name;	
}

int get_branch_num() const
{
	return branch_num;
} 

void delete_everything()
{
ofstream file;
file.open("Branch.txt",ios::trunc);
file.close();
}

void read_Branch_file()
{
ifstream fin;
fin.open("Branch.txt");

	if(!fin)
	{
		cout<<"File cannot opened...!!"<<endl;
	}
	else
	{	
	do	
    {	
	if((fin.read((char*)this, sizeof(*this))))
	{

		display_branch();
	}
	
	else
	{
		break;
	}
}while(!fin.eof());

fin.close();
}	
}


void display_total_earning()
{
	cout<<"Total Branch Earnings: "<<earnings<<endl;
}


void display_branch()
{
cout<<"Branch No:      "<<branch_num<<endl;
cout<<"Branch Name:    "<<branch_name<<endl;
cout<<"Branch Address: "<<branch_address<<endl;
cout<<"Total Earnings: "<<earnings<<endl;	
}
};
int Branch::total_Branches=0;

class Person
{
protected:
char username[15];
char password[15];
char name[15];
char address[30];
char email[20];
long long int phone;
friend class Orders;
friend class Initializer;

public:
virtual void display()=0;

};

class Customer:public Person
{
int customer_id;
static int last_id;
static int total_customer;
public:
Customer()
{

}

Customer(const char email[20],const char password[15],const char name[15],const char address[30],const char username[15],const long long int phone)
{
strcpy(this->username,username);
strcpy(this->password,password);
strcpy(this->name,name);
strcpy(this->address,address);
strcpy(this->email,email);
this->phone=phone;
customer_id = get_id();
total_customer++;
}


void add_new_account()
{
cout<<"Enter your Name: ";
cin>>name;
cout<<"Enter your e-mail: ";
cin>>email;
cout<<"Please set a passwrord: ";
cin>>password;
cout<<"Enter your address: ";
cin>>address;
again:
cout<<"Enter your phone Number: ";
cin>>phone;
if(phone<1000000000)
{
	cout<<"Please enter a correct phone number...!\n";
	goto again;
}
cout<<"Please enter a user-name for your account: ";
cin>>username;
customer_id = get_id();
total_customer++;
cout<<"Customer account added Successfully....!\n";
cout<<"Press any key to continue...!\n";
getch();
}


int get_id() const
{
    last_id = last_id + 1 ;
    return last_id;
}

int check_id(int id,Customer c[])
{
int i;
for(i=0;i<total_customer;i++)
{
	if(c[i].customer_id==id)
	{
		return 1;
	}
}
return 0;
}




void store()
{
ofstream file,out,out1;
file.open("customer.txt",ios::app);
out.open("last_id.txt");
out1.open("total_customer.txt");
if(file.is_open())
{
	file.write( (char*)this , sizeof(*this) );
	out<<last_id;
	out1<<total_customer;
	file.close();
	out.close();
	out1.close();
}
else
{
	cout<<"File doesn't open...!!"<<endl;
}
}

static void id_initializer()
{

ifstream i,i2;
static int n;
i.open("last_id.txt");
i2.open("total_customer.txt");	
	if(i.is_open())
	{
		
		i>>n;
		i.close();
		last_id=n;
	}
	else
	{
	last_id = 10000;
	}

if(i2.is_open())
	{
		
		i2>>n;
		i2.close();
		total_customer=n;
	}
	else
	{
	total_customer=0;
	}
}

int log_in(Customer c1[],const char email[],const char pass[])  //For order purpose
{
int i,c=0;
try
{
for(i=0;i<total_customer;i++)
{
	if( (strcmp(c1[i].email,email)==0) && (strcmp(c1[i].password,pass)==0) )  
	{
		cout<<"Sucessfully Logged in."<<endl;
		cout<<"Welcome Back "<<c1[i].name<<"."<<endl;
		c++;
		Sleep(1300);
	    return c1[i].customer_id;	
	}
	
}
if(c==0)
{
	throw "error";
}

}
catch(...)
{
cout<<"E-mail or Password is wrong...!"<<endl;
getch();
return 0;
}
}

static int get_total_customer() 
{
return total_customer;	
}


void display_all_customer(Customer c[])
{
int i;
if(total_customer==0)
{
cout<<"No customers to display...!\n";
}
else
{
for(i=0;i<total_customer;i++)
{
	c[i].display();
}
}
}


void display_all_membership_account(Customer c[])
{

int i=0,n,ch=0;
ifstream fin;
fin.open("membership.txt");
while(fin>>n)
{
if(c[i].customer_id==n)
{
c[i].display();
i++;	
ch++;
}

}
fin.close();
if(ch==0)
{
	cout<<"No membership accounts to display...!\n";
}
}


void store_last_customer(Customer c[])
{
int i=0;
ifstream fin;
fin.open("customer.txt");
fin.seekg(0,ios::beg);
if(!fin)
	{
		cout<<"Customer.txt not found."<<endl;
	}
	else
	{
	do	{	
	if((fin.read((char*)this, sizeof(*this))))
	{
       strcpy(c[i].username,username);
       strcpy(c[i].password,password);
       strcpy(c[i].name,name);
       strcpy(c[i].address,address);
       strcpy(c[i].email,email);
       c[i].phone=phone;
       c[i].customer_id = customer_id; 
   i++;
   }
}while(i<Customer::get_total_customer());    //(!fin.eof());
fin.close();
}
}


void sign_up_membership(Customer c1[])
{
char mail[20],pass[20];
int id;
cout<<"Sign in to your account first.\n";
cout<<"Enter your e-mail:   ";cin>>mail;
cout<<"Enter your password: ";cin>>pass;
id=log_in(c1,mail,pass);
if(id!=0)
{
int c,check=0;
cout<<"Pay Rs.500 to sign up for membership.\n1.Yes\n2.No\nChoice:";
cin>>c;
int n;
if(c==1)
{
fstream out;
out.open("membership.txt",ios::app|ios::in);
if(out.is_open())
{

  std::ifstream ifs("membership.txt", std::ios::ate); 

if(ifs.tellg() == 0)
{
check++;
out<<id<<endl;
out.close();
}

else
{
    while(out>>n)
	{
		if(id==n)
		{
		cout<<"Membership account already exist...!\n";
		out.close();
		}
		else
		{
			check++;
			out<<id<<endl;
         	out.close();
        }
	}
}	
}
else
{
	cout<<"File doesn't open...!!"<<endl;
}
}
else
{
	cout<<"Membership account not created.\n";
}
if(check!=0)
{
cout<<"Membership account created successfully...!\n";
}
getch();
}
}

int check_membership(const int id)
{
int i,check=0,n;
ifstream fin;
fin.open("membership.txt");

while(fin>>n)
{
if(id==n)
{
	return 1;
	check++;
}
}

if(check==0)
{
	cout<<"Membership account not found...!\nNo Discount given on total\nPress any key to continue...!\n";
	getch();
	return 0;
}
}

void delete_membership(const int id)
{
int i,check=0,n;
fstream fin;
ofstream newfile;
fin.open("membership.txt",ios::in|ios::out);
newfile.open("temp.txt",ios::app);
while(fin>>n)
{
if(id==n)
{
cout<<"Membership account deleted successfully.\n";
check++;
}
else
{
newfile<<n;
}
}
newfile.close();
fin.close();
if(check!=0)
{
remove("membership.txt");

if (rename("temp.txt", "membership.txt") != 0)
	perror("Error renaming file");
	else
	cout << "Membership account file updated successfully.\n";
}
if(check==0)
{
	cout<<"Membership account not found...!\n";

}
}

void display()
{
cout<<"Name:         "<<name<<endl;
cout<<"Customer ID:  "<<customer_id<<endl;
cout<<"E-mail:       "<<email<<endl;
cout<<"Address:      "<<address<<endl;
cout<<"Phone Number: "<<phone<<endl;
cout<<"------------------------------\n";
}

template<class x>
friend void search(x data,Customer c[]);


};
int Customer::last_id=10000;
int Customer::total_customer=0;


template<class x>
void search(x data,Customer c[])
{
int i,ch=0;
for(i=0;i<c[i].total_customer;i++)
{
if(c[i].customer_id==data)
{
c[i].display();
ch++;
break;
}
if(ch==0)
{
	cout<<"No details found...!\n";
}
}

}



class Admin:public Person,public Branch
{
int branch;
int admin_id;
public:
Admin()
{

}
Admin(const int branch,const int admin_id,const char email[20],const char password[15],const char name[15],const char address[30],const char username[15],const long long int phone)
{
this->branch=branch;
this->admin_id=admin_id;
strcpy(this->username,username);
strcpy(this->password,password);
strcpy(this->name,name);
strcpy(this->address,address);
strcpy(this->email,email);
this->phone=phone;
}


Admin(const int branch,const int admin_id,const char email[20],const char password[15],const char name[15],const char address[30],const char username[15],const long long int phone,const int branch_num,const char branch_name[20],const char branch_address[20]):Branch(branch_num,branch_name,branch_address)
{
this->branch=branch;
this->admin_id=admin_id;
strcpy(this->username,username);
strcpy(this->password,password);
strcpy(this->name,name);
strcpy(this->address,address);
strcpy(this->email,email);
this->phone=phone;
}

void store_branch()
{
ofstream file;
file.open("Branch.txt",ios::app);
if(file.is_open())
{
	file.write((char*)this , sizeof(*this));
	file.close();
}
else
{
	cout<<"File doesn't open...!!"<<endl;
}
}



void store_Admin()
{
ofstream file;
file.open("Admin.txt",ios::app);
if(file.is_open())
{
	file.write( (char*)this , sizeof(*this) );
	file.close();
}
else
{
	cout<<"File doesn't open...!!"<<endl;
}
}

int log_in_admin(Admin a1[],const char email[],const char pass[])
{                
int i,c=0;
try
{
for(i=0;i<3;i++)
{
	if( (strcmp(a1[i].email,email)==0) && (strcmp(a1[i].password,pass)==0) )  
	{
	    
		cout<<"Sucessfully Logged in as Admin."<<endl;
		cout<<"Welcome "<<a1[i].name<<"."<<endl;
		c++;
		Sleep(1300);
	    return 1;	
	}
	
}
if(c==0)
{
	throw "error";
}

}
catch(...)
{
cout<<"E-mail or Password is wrong...!"<<endl;
getch();
return 0;
}
}

void store_last_data_Brach(Admin b[])
{
int i=0;
ifstream fin;
fin.open("Branch.txt");
if(!fin)
	{
		cout<<"Branch.txt not Found."<<endl;
	}
	else
	{
	do	{
	if((fin.read((char*)this, sizeof(*this))))
	{
       strcpy(b[i].branch_name,branch_name);
       strcpy(b[i].branch_address,branch_address);
       b[i].branch_num=branch_num;
       b[i].earnings = earnings; 
       i++;
   }
}while(!fin.eof());//while(i<3);  
fin.close();
}
}

void display()
{
cout<<"Name:               "<<name<<endl;
cout<<"Admin ID:           "<<admin_id<<endl;
cout<<"Admin of Branch No: "<<branch_num<<endl;
cout<<"E-mail:             "<<email<<endl;
cout<<"Address:            "<<address<<endl;
cout<<"Phone Number:       "<<phone<<endl;
cout<<"---------------------------------\n";
}

};

class Manager:public Person
{
int manager_id;
public:


Manager()
{

}
Manager(const int manager_id,const char email[20],const char password[15],const char name[15],const char address[30],const char username[15],const long long int phone)
{
this->manager_id=manager_id;
strcpy(this->username,username);
strcpy(this->password,password);
strcpy(this->name,name);
strcpy(this->address,address);
strcpy(this->email,email);
this->phone=phone;
}

void store_Manager()
{
ofstream file;
file.open("Manager.txt",ios::app);
if(file.is_open())
{
	file.write( (char*)this , sizeof(*this) );
	file.close();
}
else
{
	cout<<"File doesn't open...!!"<<endl;
}
}

int log_in_Manager(Manager &a1,const char email[],const char pass[])
{                
int i,c=0;
try
{
for(i=0;i<3;i++)
{
	if( (strcmp(a1.email,email)==0) && (strcmp(a1.password,pass)==0) )  
	{
	    
		cout<<"Sucessfully Logged in as Manager."<<endl;
		cout<<"Welcome "<<a1.name<<"."<<endl;
		c++;
		Sleep(1300);
	    return 1;	
	}
	
}
if(c==0)
{
	throw "error";
}

}
catch(...)
{
cout<<"E-mail or Password is wrong...!"<<endl;
getch();
return 0;
}
}

void display()
{
cout<<"Name:                 "<<name<<endl;
cout<<"Manager ID:           "<<manager_id<<endl;
cout<<"E-mail:               "<<email<<endl;
cout<<"Address:              "<<address<<endl;
cout<<"Phone Number:         "<<phone<<endl;
}


};

class Orders
{
int total;
int order_id;
int quantity[20],id[20],size[20];
int total_items;
int day,month,year,hour,mint,sec;
int branch_no;
friend class Person;
friend class Initializer;

public:
Orders()
{
total=0;
quantity[20]={0};
id[20]={0};
size[20]={0};
total_items=0;
}

int get_branch_num() const
{
	return branch_no;
}



void take_order(Menu m[],const int c_id,Admin &b,Admin B[])
{
int count=0,c=1,i;
order_id=c_id;
branch_no=b.get_branch_num();
cout << left <<setw(10)<<"S.NO:" << "Pizza Name:"<< right <<setw(17)  << "Small:"<< right <<setw(10);
cout <<"Medium:"<< right <<setw(10)  << "Large:"<<endl;

for(i=0;i<15;i++)
{
m[i].display();
}
	
cout<<"Press 0 to end your Order.\n";
	
	while(c!=0)   //To make it run infinite
	{
		id_again:
		cout<<"Enter the order Id: ";
		cin>>id[count];
		
	if(id[count]<0 || id[count]>m[count].total_num_items)
	{
		cout<<"Please enter correct S.No.\n";
		goto id_again;
	}	
		
		
	if(id[count]==0)
		{
			int choice;
			total_items=count;
			cout<<"Pay with membership account to get 30% discount on total.\n1.Yes\n2.No\nChoice: ";
			cin>>choice;
			if(choice==1)
			{
				int c;
				Customer temp;
				c=temp.check_membership(c_id);
                if(c==1)
				{
					int n;
					n=(total*30)/100;
					total=total-n;
				}
			}
			b.update_earning(total);
			int i;
			for(i=0;i<3;i++)
			{
				B[i].store_branch();
			}
    		print_bill(id,size,quantity,count,m,total,order_id,b);
 		   	break;
		}
while(size[count]<1 || size[count]>3)
{
cout<<"Enter the size of pizza.(1-3)\n1.small\n2.Medium\n3.Large\nChoice: ";
cin>>size[count];
}

quantity_again:
cout<<"Enter quantity of Pizza (1-XX): ";
cin>>quantity[count];
if(quantity[count]<1)
{
	goto quantity_again;
}

for(i=0;i<15;i++)
{
if(m[i].num==id[count])
{
cout<<"Pizza found in Menu !"<<endl;
if(size[count]==1)
{
total=total+(m[i].price_small*quantity[count]);
cout<<"Price has been added in Bill...!!"<<endl;
}
else if(size[count]==2)
{
total=total+(m[i].price_medium*quantity[count]);
cout<<"Price has been added in Bill...!!"<<endl;
}
else if(size[count]==3)
{
total=total+(m[i].price_large*quantity[count]);
cout<<"Price has been added in Bill...!!"<<endl;
}
}
}
count++;
}
}

int get_total_bill() const
{
return total;
}

void set_time_date()
{
time_t ttime = time(0);
tm *local_time = localtime(&ttime);
day=local_time->tm_mday;
month=1+local_time->tm_mon;
year=1900+local_time->tm_year;
hour=0+local_time->tm_hour;
mint=0+local_time->tm_min;
sec=0+local_time->tm_sec;
}


void print_bill(const int id[],const int size[],const int quantity[],const int count,Menu m[],const int total_bill,const int c_id,Admin b)
{
int i,j,k,n=0;
set_time_date();
cout<<"\t\t\t\t\xB2\xB2\xB2\xB2 "; b.display_name(); cout<<" \xB2\xB2\xB2\xB2"<<endl<<endl;
cout<<"\t\t\t\t Customer Bill Receipt"<<endl;
cout<<"\t\t\t\t ---------------------"<<endl;
cout<<"Date:"<<day<<"/"<<month<<"/"<<year<<endl;
cout << "Time: "<<hour<<":"<<mint<<":"<<sec<<endl;
cout<<endl;
cout<<"Customer ID: "<<c_id<<endl<<endl;
cout << left <<setw(10)<<"S.NO:" << "Name:"<< right <<setw(25)  << "Size:"<< right <<setw(17) <<"Quantity:";
cout << right <<setw(10)<<"Ammount:"<<endl;
for(i=0;i<count;i++)
{
for(j=0;j<15;j++)
{
if(id[i]==m[j].num)
{
 cout << left <<setw(10)<<i+1; 
 for(k=0;k<22;k++)
 {
     if(m[j].pizza[k]==0)
     cout<<" ";
     else
    cout<< m[j].pizza[k];
 }  
cout<<right <<setw(8);
if(size[i]==1)
{
cout<<"Small"<<right <<setw(12)<<quantity[i] <<right <<setw(12)<<m[j].price_small*quantity[i]<<endl;
n=n+m[j].price_small*quantity[i];
}
else if(size[i]==2)
{
cout<<"Medium"<<right <<setw(12)<<quantity[i]<<right <<setw(12) <<m[j].price_medium*quantity[i]<<endl;
n=n+m[j].price_medium*quantity[i];
}
else if(size[i]==3)
{
cout<<"Large"<<right <<setw(12)<<quantity[i]<<right <<setw(12)<<m[j].price_large*quantity[i]<<endl;
n=n+m[j].price_large*quantity[i];
}

}
}   
}

if(n>total)
{
cout<<endl<<"Total Bill after 30% discount: "<<total_bill<<endl<<endl<<endl;
cout<<"Press any key to Continue....!\n";
}
else
{
cout<<endl<<"Total Bill: "<<total_bill<<endl<<endl<<endl;
cout<<"Press any key to Continue....!\n";
}
getch();
}


void store_bill() 
{
int i;
ofstream file;
file.open("all_bills.txt",ios::app);
if(file.is_open())
{
    file<<order_id<<endl;
	file<<total_items<<endl;
	file<<branch_no<<endl;
	for(i=0;i<total_items;i++)
	{
		file<<id[i]<<endl;
		file<<quantity[i]<<endl;
		file<<size[i]<<endl;
	}  
	file<<total<<endl;  		
	file<<day<<endl;
	file<<month<<endl;
	file<<year<<endl;
	file<<hour<<endl;
	file<<mint<<endl;
	file<<sec<<endl;
file.close();
}
else
{
	cout<<"File doesn't open...!!"<<endl;
}
}

void show_all_bills(Menu m[],Admin b[],Deals d[])
{
ifstream fin;
fin.open("all_bills.txt");
int i;
	if(!fin)
	{
		cout<<"File cannot opened...!!"<<endl;
	}
	else

while(fin>>order_id)	
    {
    
	fin>>total_items;
	fin>>branch_no;
	for(i=0;i<total_items;i++)
	{
		fin>>id[i];
		fin>>quantity[i];
		fin>>size[i];
	}  
    fin>>total;  		
	fin>>day;
	fin>>month;
	fin>>year;
	fin>>hour;
	fin>>mint;
	fin>>sec;
	if(size[0]==0)
	{
    display_Deals_bill(d,b);
	}
	else
	{
  	display_bill(m,b);
    }
}

fin.close();
	
}


void display_bill(Menu m[],Admin b[])
{
int i,j,k;
cout<<"\t\t\t\t\xB2\xB2\xB2\xB2 ";b[branch_no-1].display_name(); cout<<" \xB2\xB2\xB2\xB2"<<endl<<endl;
cout<<"\t\t\t\t Customer Bill Receipt"<<endl;
cout<<"\t\t\t\t ---------------------"<<endl;
cout<<"Date:"<<day<<"/"<<month<<"/"<<year<<endl;
cout <<"Time: "<<hour<<":"<<mint<<":"<<sec<<endl;
cout<<endl;
cout<<"Customer ID: "<<order_id<<endl;
cout << left <<setw(10)<<"S.NO:" << "Name:"<< right <<setw(25)  << "Size:"<< right <<setw(17) <<"Quantity:";
cout << right <<setw(10)<<"Ammount:"<<endl;
for(i=0;i<total_items;i++)
{
for(j=0;j<15;j++)
{
if(id[i]==m[j].num)
{
 cout << left <<setw(10)<<i+1; 
 for(k=0;k<22;k++)
 {
     if(m[j].pizza[k]==0)
     cout<<" ";
     else
    cout<< m[j].pizza[k];
 }  
cout<<right <<setw(8);
if(size[i]==1)
{
cout<<"Small"<<right <<setw(12)<<quantity[i] <<right <<setw(12)<<m[j].price_small*quantity[i]<<endl;
}
else if(size[i]==2)
{
cout<<"Medium"<<right <<setw(12)<<quantity[i]<<right <<setw(12) <<m[j].price_medium*quantity[i]<<endl;
}
else if(size[i]==3)
{
cout<<"Large"<<right <<setw(12)<<quantity[i]<<right <<setw(12)<<m[j].price_large*quantity[i]<<endl;
}

}
}   
}
cout<<endl<<"Total Bill was: "<<total<<endl<<endl<<endl;
}   //getch to be putted when this function is called


void search_history(const int b_no,Menu m[],const int c_id,Admin a1[])
{
int c=0;
ifstream fin;
fin.open("all_bills.txt");
int i;
	if(!fin)
	{
		cout<<"File cannot opened...!!"<<endl;
	}
	else
	{
    while(fin>>order_id)	
    {
	if(order_id==c_id)    
    {
	c++;
	fin>>total_items;
	fin>>branch_no;
	for(i=0;i<total_items;i++)
	{
		fin>>id[i];
		fin>>quantity[i];
		fin>>size[i];
	}  
    fin>>total;  		
	fin>>day;
	fin>>month;
	fin>>year;
	fin>>hour;
	fin>>mint;
	fin>>sec;
	if(b_no==branch_no)
	{
	display_bill(m,a1);
	}   
	}
	
}
}
fin.close();
if(c==0)
	{
		cout<<"No account found with the given ID.\n";
	}
	else
	{
cout<<"All Order history of the Customer displayed....!\n";
	}
cout<<"Press any key to Continue....!\n";

}


void search_history_specific(Menu m[],const int c_id,Admin a1[])
{
int c=0;
ifstream fin;
fin.open("all_bills.txt");
int i;
	if(!fin)
	{
		cout<<"File cannot opened...!!"<<endl;
	}
	else
	{
    while(fin>>order_id)	
    {
	if(order_id==c_id)    
    {
	c++;
	fin>>total_items;
	fin>>branch_no;
	for(i=0;i<total_items;i++)
	{
		fin>>id[i];
		fin>>quantity[i];
		fin>>size[i];
	}  
    fin>>total;  		
	fin>>day;
	fin>>month;
	fin>>year;
	fin>>hour;
	fin>>mint;
	fin>>sec;
	
	display_bill(m,a1);   
	}
	
}
}
fin.close();
if(c==0)
	{
		cout<<"No account found with the given ID.\n";
	}
	else
	{
cout<<"All Order history of the Customer displayed....!\n";
	}
cout<<"Press any key to Continue....!\n";

}


void Dine_in(Menu m[],const int c_id,Admin &b,Admin B[],const int choice)
{
int count=0,c=1,i;
order_id=c_id;
branch_no=b.get_branch_num();
cout << left <<setw(10)<<"S.NO:" << "Pizza Name:"<< right <<setw(17)  << "Small:"<< right <<setw(10);
cout <<"Medium:"<< right <<setw(10)  << "Large:"<<endl;
for(i=0;i<15;i++)
{
m[i].display();
}
	
cout<<"Press 0 to end your Order.\n";
	
	while(c!=0)   //To make it run infinite
	{
		id_again:
		cout<<"Enter the order Id: ";
		cin>>id[count];
		
	if(id[count]<0 || id[count]>m[count].total_num_items)
	{
		cout<<"Please enter correct S.No.\n";
		goto id_again;
	}	
		
		
	if(id[count]==0)
		{
				total_items=count;
				int c=0;
				Customer temp;
				if(choice==1)
				{
				c=temp.check_membership(c_id);
                if(c==1)
				{
					int n;
					n=(total*30)/100;
					total=total-n;
				}
				}
			b.update_earning(total);
			int i;
			for(i=0;i<3;i++)
			{
				B[i].store_branch();
			}
    		print_bill(id,size,quantity,count,m,total,order_id,b);
 		   	break;
		}
while(size[count]<1 || size[count]>3)
{
cout<<"Enter the size of pizza.(1-3)\n1.small\n2.Medium\n3.Large\nChoice: ";
cin>>size[count];
}

quantity_again:
cout<<"Enter quantity of Pizza (1-XX): ";
cin>>quantity[count];
if(quantity[count]<1)
{
	goto quantity_again;
}

for(i=0;i<15;i++)
{
if(m[i].num==id[count])
{
cout<<"Pizza found in Menu !"<<endl;
if(size[count]==1)
{
total=total+(m[i].price_small*quantity[count]);
cout<<"Price has been added in Bill...!!"<<endl;
}
else if(size[count]==2)
{
total=total+(m[i].price_medium*quantity[count]);
cout<<"Price has been added in Bill...!!"<<endl;
}
else if(size[count]==3)
{
total=total+(m[i].price_large*quantity[count]);
cout<<"Price has been added in Bill...!!"<<endl;
}

}
}
count++;
}
}

void store_earning_per_day()
{
string s;
time_t now = time(0);
tm *ltm = localtime(&now);
ofstream file;
    file.open("name.txt");
    if(file.is_open())
    {
    file<< ltm->tm_mday<<"-";
	file<<1 + ltm->tm_mon<<"-";
	file<<1900 + ltm->tm_year;
    }
    else
    cout<<"Unable to create file";
    file.close();

ifstream i1;
i1.open("name.txt");
	while(!i1.eof())
		{			
        getline(i1, s);
		}
		i1.close();

remove("name.txt");

int i;
ofstream file1;
file1.open(s.c_str(),ios::app);
if(file1.is_open())
{
    file1<<order_id<<endl;
	file1<<total_items<<endl;
	file1<<branch_no<<endl;
	for(i=0;i<total_items;i++)
	{
		file1<<id[i]<<endl;
		file1<<quantity[i]<<endl;
		file1<<size[i]<<endl;
	}  
	file1<<total<<endl;  		
	file1<<day<<endl;
	file1<<month<<endl;
	file1<<year<<endl;
	file1<<hour<<endl;
	file1<<mint<<endl;
	file1<<sec<<endl;
    file1.close();
}
else
{
	cout<<"File doesn't open...!!"<<endl;
}
}

void read_daily_earning_file(Menu m[],Admin b[],Deals d[])
{
string s;
time_t now = time(0);
tm *ltm = localtime(&now);
ofstream file;
    file.open("name.txt");
    if(file.is_open())
    {
    file<< ltm->tm_mday<<"-";
	file<<1 + ltm->tm_mon<<"-";
	file<<1900 + ltm->tm_year;
    }
    else
    cout<<"Unable to create file";
    file.close();

ifstream i1;
i1.open("name.txt");
	while(!i1.eof())
		{			
        getline(i1, s);
		}
		i1.close();

remove("name.txt");
ifstream fin;
fin.open(s.c_str());
int i;
	if(!fin)
	{
		cout<<"File cannot opened...!!"<<endl;
	}
	else

while(fin>>order_id)	
    {
    fin>>total_items;
	fin>>branch_no;
	for(i=0;i<total_items;i++)
	{
		fin>>id[i];
		fin>>quantity[i];
		fin>>size[i];
	}  
    fin>>total;  		
	fin>>day;
	fin>>month;
	fin>>year;
	fin>>hour;
	fin>>mint;
	fin>>sec;
	if(size[0]==0)
	{
    display_Deals_bill(d,b);
	}
	else
	{
  	display_bill(m,b);
	}
}
}


void read_specific_Branch_orders(Menu m[],Admin a1[],const int c_id,Deals d[])
{

ifstream fin;
fin.open("all_bills.txt");
int i,c=0;
	if(!fin)
	{
		cout<<"File cannot opened...!!"<<endl;
	}
	else
	{
    while(fin>>order_id)	
    {
		fin>>total_items;
	fin>>branch_no;
	for(i=0;i<total_items;i++)
	{
		fin>>id[i];
		fin>>quantity[i];
		fin>>size[i];
	}  
    fin>>total;  		
	fin>>day;
	fin>>month;
	fin>>year;
	fin>>hour;
	fin>>mint;
	fin>>sec;
	if(branch_no==c_id)    
    {
	c++;

    if(size[0]==0)
	{
    display_Deals_bill(d,a1);
	}
    else
    {
   display_bill(m,a1);
    }	
}   

	
}
}
fin.close();
if(c!=0)
{
cout<<"All Order history of the Branch displayed....!\n";
}
else
{
	cout<<"No order history of Branch to Display...!\n";
}
cout<<"Press any key to Continue....!\n";
}

void display_earnings_per_day(Admin b[])
{
int money=0;
string s;
time_t now = time(0);
tm *ltm = localtime(&now);
ofstream file;
    file.open("name.txt");
    if(file.is_open())
    {
    file<< ltm->tm_mday<<"-";
	file<<1 + ltm->tm_mon<<"-";
	file<<1900 + ltm->tm_year;
    }
    else
    cout<<"Unable to create file";
    file.close();

ifstream i1;
i1.open("name.txt");
	while(!i1.eof())
		{			
        getline(i1, s);
		}
		i1.close();

remove("name.txt");
ifstream fin;
fin.open(s.c_str());
int i;
	if(!fin)
	{
		cout<<"File cannot opened...!!"<<endl;
	}
	else

while(fin>>order_id)	
    {
    fin>>total_items;
	fin>>branch_no;
	for(i=0;i<total_items;i++)
	{
		fin>>id[i];
		fin>>quantity[i];
		fin>>size[i];
	}  
    fin>>total;
	money=money+total;  		
	fin>>day;
	fin>>month;
	fin>>year;
	fin>>hour;
	fin>>mint;
	fin>>sec;
  	
}

cout<<"Total Earnings made per day by all Branches is: "<<money<<endl;
}

void display_overall_earning_all_branches(Admin a[])
{
int money=0,i;
for(i=0;i<3;i++)
{
money=money+a[i].get_earning();
}
cout<<"Total Earnings made by all branches yet is: "<<money<<endl;
}


void display_earnings_per_day_specific_Branch(const int num)
{
int money=0;
string s;
time_t now = time(0);
tm *ltm = localtime(&now);
ofstream file;
    file.open("name.txt");
    if(file.is_open())
    {
    file<< ltm->tm_mday<<"-";
	file<<1 + ltm->tm_mon<<"-";
	file<<1900 + ltm->tm_year;
    }
    else
    cout<<"Unable to create file";
    file.close();

ifstream i1;
i1.open("name.txt");
	while(!i1.eof())
		{			
        getline(i1, s);
		}
		i1.close();

remove("name.txt");
ifstream fin;
fin.open(s.c_str());
int i;
	if(!fin)
	{
	cout<<"File cannot opened...!!"<<endl;
	}
	else

while(fin>>order_id)	
    {
    fin>>total_items;
	fin>>branch_no;
	for(i=0;i<total_items;i++)
	{
		fin>>id[i];
		fin>>quantity[i];
		fin>>size[i];
	}  
    fin>>total;
	if(branch_no==num)
	{
	money=money+total;  		
	}
	fin>>day;
	fin>>month;
	fin>>year;
	fin>>hour;
	fin>>mint;
	fin>>sec;
  	
}
cout<<"Total Earnings made per day by Branch is: "<<money<<endl;
}

void take_deal_order(Deals d[],const int c_id,Admin &b,Admin B[])
{
int i,count=0,c=1;
order_id=c_id;
branch_no=b.get_branch_num();
d[0].dispaly_deal(d);
cout<<"Press 0 to end your Order.\n";
	
	while(c!=0)   //To make it run infinite
	{
		id_again:
		cout<<"Enter the order Id: ";
		cin>>id[count];
		
	if(id[count]<0 || id[count]>d[count].total_deals)
	{
		cout<<"Please enter correct S.No.\n";
		goto id_again;
	}	
		
		
	if(id[count]==0)
		{
			total_items=count;
			b.update_earning(total);
			int i;
			for(i=0;i<3;i++)
			{
				B[i].store_branch();
			}
    	    print_deal_bill(id,quantity,count,d,total,order_id,b);
 		   	break;
		}


quantity_again:
cout<<"Enter quantity of Pizza (1-XX): ";
cin>>quantity[count];
if(quantity[count]<1)
{
	goto quantity_again;
}

for(i=0;i<5;i++)
{
if(d[i].num==id[count])
{
size[i]=0;
cout<<"Deal found in Menu !"<<endl;
total=total+(d[i].price*quantity[count]);
}
}
count++;
}
}


void print_deal_bill(const int id[],const int quantity[],const int count,Deals d[],const int total_bill,const int c_id,Admin b)
{
int i,j,k,n=0;
set_time_date();
cout<<"\t\t\t\t\xB2\xB2\xB2\xB2 "; b.display_name(); cout<<" \xB2\xB2\xB2\xB2"<<endl<<endl;
cout<<"\t\t\t\t Customer Bill Receipt"<<endl;
cout<<"\t\t\t\t ---------------------"<<endl;
cout<<"Date:"<<day<<"/"<<month<<"/"<<year<<endl;
cout << "Time: "<<hour<<":"<<mint<<":"<<sec<<endl;
cout<<endl;
cout<<"Customer ID: "<<c_id<<endl<<endl;
cout << left <<setw(10)<<"S.NO:" << "Deal Name:"<< right <<setw(32)  <<"Quantity:";
cout << right <<setw(10)<<"Ammount:"<<endl;
for(i=0;i<count;i++)
{
for(j=0;j<5;j++)
{
if(id[i]==d[j].num)
{
 cout << left <<setw(10)<<i+1; 
 for(k=0;k<30;k++)
 {
     if(d[j].deal_name[k]==0)
     cout<<" ";
     else
    cout<< d[j].deal_name[k];
 }  
cout<<right <<setw(8)<<quantity[i]<<right <<setw(11)<<d[j].price*quantity[i]<<endl;
}
}   
}

cout<<endl<<endl<<"Total Bill: "<<total_bill<<endl<<endl<<endl;
cout<<"Press any key to Continue....!\n";
}



void display_Deals_bill(Deals d[],Admin b[])
{
int i,j,k,n=0; 
cout<<"\t\t\t\t\xB2\xB2\xB2\xB2 "; b[branch_no-1].display_name(); cout<<" \xB2\xB2\xB2\xB2"<<endl<<endl;
cout<<"\t\t\t\t Customer Bill Receipt"<<endl;
cout<<"\t\t\t\t ---------------------"<<endl;
cout<<"Date:"<<day<<"/"<<month<<"/"<<year<<endl;
cout << "Time: "<<hour<<":"<<mint<<":"<<sec<<endl;
cout<<endl;
cout<<"Customer ID: "<<order_id<<endl<<endl;
cout << left <<setw(10)<<"S.NO:" << "Deal Name:"<< right <<setw(32)  <<"Quantity:";
cout << right <<setw(10)<<"Ammount:"<<endl;
for(i=0;i<total_items;i++)
{
for(j=0;j<5;j++)
{
if(id[i]==d[j].num)
{
 cout << left <<setw(10)<<i+1; 
 for(k=0;k<30;k++)
 {
     if(d[j].deal_name[k]==0)
     cout<<" ";
     else
    cout<< d[j].deal_name[k];
 }  
cout<<right <<setw(8)<<quantity[i]<<right <<setw(11)<<d[j].price*quantity[i]<<endl;
}
}   
}

cout<<endl<<endl<<"Total Bill was: "<<total<<endl<<endl<<endl;
cout<<"Press any key to Continue....!\n";

}   
};

class Initializer
{
public:
int check_Menu()
{
ifstream file;
file.open("Menu.txt");
if(!file)
	{
		return 0;
	}
	else
	{
        return 1;
    }
    file.close();
}

int check_Branch()
{
ifstream file;
file.open("Branch.txt");
if(!file)
	{
		return 0;
	}
	else
	{
        return 1;
    }
    file.close();
}

int check_Admin()
{
ifstream file;
file.open("Admin.txt");
if(!file)
	{
		return 0;
	}
	else
	{
        return 1;
    }
    file.close();
}

int check_Manager()
{
ifstream file;
file.open("Manager.txt");
if(!file)
	{
		return 0;
	}
	else
	{
        return 1;
    }
    file.close();
}

int check_Deals()
{
ifstream file;
file.open("Deals.txt");
if(!file)
	{
		return 0;
	}
	else
	{
        return 1;
    }
    file.close();
}

int check_random_id()
{
ifstream file;
file.open("random_id.txt");
if(!file)
	{
		return 0;
	}
	else
	{
        return 1;
    }
    file.close();
}



void store_random_id(int num)
{
ofstream fout;
fout.open("random_id.txt");

if(fout.is_open())
{
	fout<<num;
	fout.close();
}
else
cout<<"Unable to open file...!\n";

}

int get_random_id()
{
int n;
ifstream fin;
fin.open("random_id.txt");
if(fin.is_open())
{
fin>>n;
fin.close();
}
return n;
}
};

int main()
{
    Initializer i1;
    int i;
	Customer::id_initializer();
    Customer *c_ptr,temp_cus;
	int customer_count = Customer::get_total_customer();
	c_ptr = new Customer[1000];
	temp_cus.store_last_customer(c_ptr);
		
    Menu m[15]={ 
	{1,"Chicken Tikka",410,625,900} , {2,"Chicken Fajita",410,625,900} ,
	{3,"Cheese Lover",400,610,850} , {4,"Chicken Tikka Supreme",450,650,930} ,
	{5,"Chicken Fajita Supreme",450,650,930} , {6,"Chilli Chicken",400,550,800} ,
	{7,"Afghani Tikka",500,650,990} , {8,"Fajita Sicillian",450,650,930} ,
	{9,"BBQ Buzz",440,640,920} , {10,"Chicken Supreme",420,640,925} ,
	{11,"Behari",430,630,910} , {12,"Spicy Ranch",450,650,940} ,
	{13,"Super Sicillian",435,630,925} , {14,"Creamy Melt",410,625,900} ,
	{15,"Very Veggie",400,600,850} 
	};

    
	if(i1.check_Menu()==0)
	{
	for(i=0;i<15;i++)
	{
		m[i].store();
	}
	cout<<"Menu Stored in File.\n";
	}

	
	Deals d[5]={
		{1,"1 Pan Pizza & 1 Beverage",249},
		{2,"1 Regular Pizza & 2 Beverages",599},
		{3,"1 Large Pizza & 1 Beverage",899},
		{4,"1 Jumbo Pizza & 1 Beverages",1199},
		{5,"WOW Triple Large Pizza & 2 Beverages",4599}
		};
    
    if(i1.check_Deals()==0)
	{
	for(i=0;i<5;i++)
	{
	d[i].store();
	}
	cout<<"Deals.txt stored in file.\n";
	}


  	
    Admin temp_admin;
	Admin admin[3]=
	{
	{1,1111,"admin1","12345","Amir","Near_Korangi","Amir112",1234567,1,"Defence_Branch","Near_Khayaban-e-Ittehad_Road"},
    {2,2222,"admin2","12345","Shehbaz","Near_Layari","Shehbaz",123457,2,"Malir_Branch","Near_Rizwan_Parlour"},
    {3,3333,"admin3","12345","Faisal","Near_Fast_uni","Innocent_faisu",1234567,3,"Gulshan-e-Iqbal_Branch","Near_Usmania"} 
	};
    
   
   
    if(i1.check_Admin()==0)
	{
	for(i=0;i<3;i++)
	{
	admin[i].store_Admin();
	}
	cout<<"Admins Data Stored in File.\n";
	}

    if(i1.check_Branch()==0)
	{
	for(i=0;i<3;i++)
	{
	admin[i].store_branch();
	}
	cout<<"Branches Data Stored in File\n";
	}

temp_admin.store_last_data_Brach(admin);
  
Manager M(12345,"manager","12345","Ibad_Ullah","Near_Defence","jane_jigr",12345678912);
if(i1.check_Manager()==0)
	{
	M.store_Manager();
    cout<<"Manager Data Stored in File\nLoading....";
	Sleep(1000);
	}


if(i1.check_random_id()==0)
{
i1.store_random_id(20000);
}


Orders *o_ptr,order_temp;
o_ptr = new Orders[1000];
int order_count = 0;

time_t ttime = time(0);
tm *local_time = localtime(&ttime);

int hour=0+local_time->tm_hour;
int mint=0+local_time->tm_min;
int sec=0+local_time->tm_sec;


int ch;
static int num=i1.get_random_id();

while(ch!=4)
	{
		system("cls");
		cout<<"\t\t\t\xB2\xB2\xB2\xB2\xB2 Welcome to Pizza Hut's Online Portal \xB2\xB2\xB2\xB2\xB2"<<endl<<endl;
		cout<<"Who you are?\n1.  User?\n2.  Admin?\n3.  Manager?\n4.  Exit\nChoice: ";
		cin>>ch;
		switch(ch)
		{
			case 1:
				{
					system("cls");
					int i;
					
                   if(hour>=0 && hour<=5)
				   {
					   cout<<"MIDNIGHT DEALS ARE ALSO AVAILIBLE...!\n";
				   }

					cout<<"1.Dine in?\n2.Create an online order?\nChoice: ";
					cin>>i;
					
					if(i==1)
					{
                    
                     if(hour>=0 && hour<=5)
				   {
					   int che,br,idd;
					   cout<<"Make a normal Order or Use special midnight deal.\n1.Midnight Deal\n2.Normal Order.\nChoice: ";
					   cin>>che;
			if(che==1)
				{
					che_again:
                     cout<<"Do you have a Customer ID?\n1.Enter Customer ID\n2.Order Anonymously.\nChoice: ";
					 cin>>che;
					 if(che==1)
					 {
						int check;
						cout<<"Enter ID: ";
						cin>>idd;
						check=temp_cus.check_id(idd,c_ptr);
						if(check==0)
						{
						cout<<"No customer account found with the entered ID...!\nOrdering with random Id.\n";
						num++;
						idd=num;	
						}

					 }
                     else if(che==2)
					 {
						 num++;
						 idd=num;
					 }
					 else
					   {
						   cout<<"Invalid Input....!\nPress any key to enter again.\n";
						   getch();
						   goto che_again;
					   }


                    br_dine_again_deal:
                    cout<<"Please select Branch.\n1.Defence Branch\n2.Malir Branch.\n3.Gulshan-e-Iqbal Branch\n";
					cout<<"Choice: ";
					cin>>br;
                    if(br==1)
					{
				
					o_ptr[order_count].take_deal_order(d,idd,admin[0],admin);
					getch();
                  	o_ptr[order_count].store_bill();
					o_ptr[order_count].store_earning_per_day();
					
                    order_count++;
					}
					else if(br==2)
					{
					o_ptr[order_count].take_deal_order(d,idd,admin[1],admin);
					getch();
                   
				   	o_ptr[order_count].store_bill();
					o_ptr[order_count].store_earning_per_day();
					order_count++;
					} 
					else if(br==3)
					{
					o_ptr[order_count].take_deal_order(d,idd,admin[2],admin);
					getch();
                	o_ptr[order_count].store_bill();
					o_ptr[order_count].store_earning_per_day();
					order_count++;
					}

					else
					{
						cout<<"Invalid Branch Number.\nPlease enter again:\n";
						goto br_dine_again_deal;
					}
					
                    


				}
					   else if(che==2)
					   {
						   goto normal_order;
					   }

					   else
					   {
						   cout<<"Invalid Input....!\nPress any key to continue.\n";
						   getch();
					   }
				}
 
                    else
					{
					normal_order:
					int br,idd,choi;
                    cout<<"Enter membership account number to get 30% discount on total.\n1.Yes\n2.No\n3.Sign up for membership.\nChoice:";
                    cin>>choi;

                    if(choi==1)
					{
						int check=0;
						cout<<"Membership account Number: ";
						cin>>idd;
                        check=temp_cus.check_id(idd,c_ptr);
						if(check==0)
						{
							cout<<"No customer account found with the entered ID...!\nNo discount would be given on total...!\n";
							choi=2;
							num++;
    					    idd=num;

						}

					}
					else if(choi==2)
					{
					 
					 num++;
					 idd=num;

					}
					else if(choi==3)
					{
						temp_cus.sign_up_membership(c_ptr);
						break;
					}
					else
					{
						cout<<"Invalid Input...!\n";
						getch();
						break;
					}

					br_dine_again:
                    cout<<"Please select Branch.\n1.Defence Branch\n2.Malir Branch.\n3.Gulshan-e-Iqbal Branch\n";
					cout<<"Choice: ";
					cin>>br;
                    if(br==1)
					{
					o_ptr[order_count].Dine_in(m,idd,admin[0],admin,choi);
					o_ptr[order_count].store_bill();
					o_ptr[order_count].store_earning_per_day();
					order_count++;
					}
					else if(br==2)
					{
					o_ptr[order_count].Dine_in(m,idd,admin[1],admin,choi);
					o_ptr[order_count].store_bill();
					o_ptr[order_count].store_earning_per_day();
					order_count++;

					} 
					else if(br==3)
					{
					o_ptr[order_count].Dine_in(m,idd,admin[2],admin,choi);
					o_ptr[order_count].store_bill();
					o_ptr[order_count].store_earning_per_day();
					order_count++;
					}
					else
					{
						cout<<"Invalid Branch Number.\nPlease enter again:\n";
						goto br_dine_again;
					}

					}

                   

					}
                    else if(i==2)
					{
                        int a;
						system("cls");
						 if(hour>=0 && hour<=5)
				   {
					cout<<"Do you have an account?\n1.Enter username and Password to create a normal order.\n2.Create an account.\n";
                    cout<<"3.Sign up for membership account.\n4.Order a special Midnight deal.\nChoice: ";

				   }
                    else
					{
						cout<<"Do you have an account?\n1.Enter username and Password.\n2.Create an account.\n";
                        cout<<"3.Sign up for membership account.\nChoice: ";
					}
					    cin>>a;
                        
                        if(a==1)
                        {
                        system("cls");
						
                        char email[20];
	                    char password[15];
                        cout<<"Enter your e-mail:   ";cin>>email;
                        cout<<"Enter your password: ";cin>>password;
                        int branch_no;
						input_Branch_num_again:
						cout<<endl<<"Enter your nearest branch...!!\n1.  Defence Branch?\n";
						cout<<"2.  Malir Branch?\n3.  Gulshan-e-Iqbal Branch?\nChoice: ";
						cin>>branch_no;

                        if(branch_no==1)
						{
						int c_id;
						c_id = temp_cus.log_in(c_ptr,email,password);
						    if(c_id!=0)
	                    {
		                o_ptr[order_count].take_order(m,c_id,admin[0],admin); 
		                o_ptr[order_count].store_bill();
						o_ptr[order_count].store_earning_per_day();
                        order_count++;    
                        }
}
						else if(branch_no==2)
						{
                        int c_id;
						c_id = temp_cus.log_in(c_ptr,email,password);
						    if(c_id!=0)
	                    {
		                o_ptr[order_count].take_order(m,c_id,admin[1],admin); 
		                o_ptr[order_count].store_bill();
						o_ptr[order_count].store_earning_per_day();
                        order_count++;    
                        }

}

						else if(branch_no==3)
						{
                        int c_id;
						c_id = temp_cus.log_in(c_ptr,email,password);
						    if(c_id!=0)
	                    {
		                o_ptr[order_count].take_order(m,c_id,admin[2],admin); 
		                o_ptr[order_count].store_bill();
						o_ptr[order_count].store_earning_per_day();
                        order_count++;    
                        }


}
						else
						{
						system("cls");
                        cout<<"Please enter the correct Branch No...!\n";
                        goto input_Branch_num_again;
						}
}
						
						else if(a==2)
						{
							system("cls");

						   c_ptr[customer_count].add_new_account();
						   c_ptr[customer_count].store();
						   customer_count++;							
							
							
						}
						else if(a==3)
						{
							system("cls");
							
							c_ptr[customer_count].sign_up_membership(c_ptr);
                        }


						else if(a==4 && (hour>=0 && hour<=5) )
						{


                        char email[20];
	                    char password[15];
                        cout<<"Enter your e-mail:   ";cin>>email;
                        cout<<"Enter your password: ";cin>>password;
                        int branch_no;

						input_branch_num_again_deal:
						cout<<endl<<"Enter your nearest branch...!!\n1.  Defence Branch?\n";
						cout<<"2.  Malir Branch?\n3.  Gulshan-e-Iqbal Branch?\nChoice: ";
						cin>>branch_no;

                        if(branch_no==1)
						{
						int c_id;
						c_id = temp_cus.log_in(c_ptr,email,password);
						    if(c_id!=0)
	                    {
		                o_ptr[order_count].take_deal_order(d,c_id,admin[0],admin);
					    getch();
                        o_ptr[order_count].store_bill();
					    o_ptr[order_count].store_earning_per_day();
					    order_count++;
					     }
}
						else if(branch_no==2)
						{
                        int c_id;
						c_id = temp_cus.log_in(c_ptr,email,password);
						    if(c_id!=0)
	                    {
		                o_ptr[order_count].take_deal_order(d,c_id,admin[1],admin);
				    	getch();
						o_ptr[order_count].store_bill();
					    o_ptr[order_count].store_earning_per_day();
					    order_count++;    
                        }

}

						else if(branch_no==3)
						{
                        int c_id;
						c_id = temp_cus.log_in(c_ptr,email,password);
						    if(c_id!=0)
	                    {
		                o_ptr[order_count].take_deal_order(d,c_id,admin[2],admin);
					    getch();
						o_ptr[order_count].store_bill();
					    o_ptr[order_count].store_earning_per_day();
					
                        order_count++;
                        }
                        else
						{
							cout<<"Invalid Branch Number...!\n";
							goto input_branch_num_again_deal;
						}

}

}
						
						else
						{
							cout<<"Invalid.....!!"<<endl;
							cout<<"Press any key...!!"<<endl;
							getch();
						}

}
                       else
					   {
						   cout<<"Invalid Input....!\nPress any key to continue.\n";
						   getch();
					   }

                        }
						break;
			
			case 2:
				{
					system("cls");
					int a;
					cout<<"Enter your branch no. !!\n1.  Defence Branch?\n2.  Malir Branch?"<<endl;
					cout<<"3.  Gulshan-e-Iqbal Branch?\nChoice: ";
					cin>>a;
					if(a==1)
					{
						int q;
						char email[20];
	                    char password[15];
						system("cls");
                        cout<<"Enter your e-mail:   ";cin>>email;
                        cout<<"Enter your password: ";cin>>password;

						system("cls");
						q=admin[0].log_in_admin(admin,email,password);

						if(q==1)
						{
                           int w=1;
						   while(w!=0)
						   {
						system("cls");
                         cout<<"Please choose:\n1.Display total earning of Branch.\n2.Display all orders by specific person by entering customer ID.\n";
						 cout<<"3.check all orders made on Branch.\n4.Display total Earning made per day by Branch.\n\nPress 0 to Log out...!\n\nChoice: ";
                         cin>>w;
						 system("cls");
						 if(w==1)
						 {
							 system("cls");
							 admin[0].display_total_earning();
							 getch();
						 }
						 else if(w==2)
						 
						{
						system("cls");
						int r;
						cout<<"Enter the customer ID.\nID: ";		 
						cin>>r;
						order_temp.search_history(1,m,r,admin);
						getch();
						}
                      
					    else if(w==3)
						{
							system("cls");
							order_temp.read_specific_Branch_orders(m,admin,1,d);
                            getch();

						}
						else if(w==4)
						{
							system("cls");
							order_temp.display_earnings_per_day_specific_Branch(1);
                            getch();

						}

						else
						{
							system("cls");
							cout<<"wrong Input....!\n";
						}
					}
					}
					}
					else if(a==2)
					{
						system("cls");
                         int q;
						char email[20];
	                    char password[15];
                        cout<<"Enter your e-mail:   ";cin>>email;
                        cout<<"Enter your password: ";cin>>password;
                        q=temp_admin.log_in_admin(admin,email,password);

						if(q==1)
						{
							system("cls");
                           int w=1;
						   while(w!=0)
						   {
							   system("cls");
                        cout<<"Please choose:\n1.Display total earning of Branch.\n2.Display all orders by specific person by entering customer ID.\n";
						cout<<"3.check all orders made on Branch.\n4.Display total Earning made per day by Branch.\n\nPress 0 to Log out...!\n\nChoice: ";
                         cin>>w;
						 if(w==1)
						 {
							 system("cls");
							 admin[1].display_total_earning();
						     getch();
						     
						 }
						 else if(w==2)
						{
						system("cls");
						int r;
						cout<<"Enter the customer ID.\nID: ";		 
						cin>>r;
						order_temp.search_history(2,m,r,admin);
						getch();
						}

						else if(w==3)
						{    
							 system("cls");
							order_temp.read_specific_Branch_orders(m,admin,2,d);
                            getch();

						}
                         	else if(w==4)
						{
							system("cls");
							order_temp.display_earnings_per_day_specific_Branch(2);
                            getch();

						}


						else
						{
							system("cls");
							cout<<"wrong Input...!\n";
						}
                    }
					}						
					}
					else if(a==3)
					{
						system("cls");
						
                     int q;
						char email[20];
	                    char password[15];
                        cout<<"Enter your e-mail:   ";cin>>email;
                        cout<<"Enter your password: ";cin>>password;

						system("cls");
						q=admin[2].log_in_admin(admin,email,password);

						if(q==1)
						{
						system("cls");
                           int w=1;
						   while(w!=0)
						   {
							system("cls");
                    cout<<"Please choose:\n1.Display total earning of Branch.\n2.Display all orders by specific person by entering customer ID.\n";
					cout<<"3.check all orders made on Branch.\n4.Display total Earning made per day by Branch.\n\nPress 0 to Log out...!\n\nChoice: ";
                        cin>>w;
						 if(w==1)
						 {
							 system("cls");
							 admin[2].display_total_earning();
                             getch();
						 }
						 else if(w==2)
						 
						{
						system("cls");
						int r;
						cout<<"Enter the customer ID.\nID: ";		 
						cin>>r;
						order_temp.search_history(3,m,r,admin);
						getch();
						}

						else if(w==3)
						{    system("cls");
							order_temp.read_specific_Branch_orders(m,admin,3,d);
                            getch();

						}


                         	else if(w==4)
						{
							system("cls");
							order_temp.display_earnings_per_day_specific_Branch(3);
                            getch();

						}
                        else
						{
							system("cls");
							cout<<"wrong Input...!\n";
						}
                    }
					}
                	}
					else
					{
						system("cls");
						cout<<"Invalid Branch...!!"<<endl;
						cout<<"Press any key...!!"<<endl;
						getch();
					}
				break;
			}
		
		case 3:
			
			{
				system("cls");
				
				int q;
				char email[20];
	            char password[15];
                cout<<"Enter your e-mail:   ";cin>>email;
                cout<<"Enter your password: ";cin>>password;

				system("cls");
				q=M.log_in_Manager(M,email,password);



				if(q==1)
				{  
				manager_again: 	
				int a=1;
				while(a!=0)
				{
                system("cls");
				cout<<"What do you want to do?\n1. Want to see the whole sale of all three branches per day? "<<endl;
				cout<<"2. Want to see sale of particular branch? \n3. Want to see all accounts?\n";
				cout<<"4. Want to see membership account?\n5. To see total earnings made by all branches yet.\n";
	            cout<<"6. Display all Admins data.\n7. Delete a membership account.\n";
				cout<<"8. Display all order history of a specific person.\n9. Display data of specific person.\n";
				cout<<"10.Display my data.\nPress 0 to logout.\n\nChoice: ";
				cin>>a;
				
				if(a==1)
				{
				system("cls");
                order_temp.display_earnings_per_day(admin);
				getch();
				}
				
				
				
				else if(a==2)
				{
				int num;
                system("cls");
				cout<<"1.Defence Branch.\n2.Malir Branch.\n3.Gulshan-e-Iqbal Branch.\nPress 0 to exit.\nChoice: ";
                cin>>num;
				if(num>0 && num<4)
				{
				system("cls");
                 order_temp.display_earnings_per_day_specific_Branch(num);
				 getch();
				}
				else
				{
				system("cls");
                cout<<"Invalid Input....!\n";
				goto manager_again;
				}
                if(num==0)
				{
					goto manager_again;
				}

				}
				


				else if(a==3)
				{
                system("cls");
                temp_cus.display_all_customer(c_ptr);
				getch();
                }

                else if(a==4)
				{
				 system("cls");
                 temp_cus.display_all_membership_account(c_ptr);
				 getch();
				 
				}

				else if(a==5)
				{
					system("cls");
					order_temp.display_overall_earning_all_branches(admin);
					getch();
 
				}


				if(a==6)
				{
				system("cls");
				Person *ptr1,*ptr2,*ptr3;
                ptr1=&admin[0];
				ptr2=&admin[1];
				ptr3=&admin[2];
                ptr1->display();
				ptr2->display();
				ptr3->display();
				getch();          
                }


				if(a==7)
				{
				int id;
                system("cls");
				cout<<"Enter the membership account ID to cancel membership.\nID: ";
                cin>>id;
				temp_cus.delete_membership(id);
				getch();
				}

				if(a==8)
				{
				
                system("cls");
                int r;
				cout<<"Enter the customer ID.\nID: ";		 
				cin>>r;
                order_temp.search_history_specific(m,r,admin);
				getch();
				}

				if(a==9)
				{
				system("cls");
                int r;
				cout<<"Enter the customer ID.\nID: ";		 
				cin>>r;
                search(r,c_ptr);
                getch();
				}
				if(a==10)
				{
				system("cls");
                M.display();
				getch();
				}
				

				if(a==0)
				{
					break;
				}

				
		}
	}
		
	break;
}
		case 4:
			{
				i1.store_random_id(num);
				system("cls");
				cout<<"Exiting...!!"<<endl;
				Sleep(1000);
				system("cls");
				system("color 06");
				cout<<"\t\t\t\xB2\xB2\xB2\xB2 Thanks for choosing Pizza Hut \xB2\xB2\xB2\xB2"<<endl;
				cout<<"\t\t\t   \xB2\xB2\xB2\xB2 Hope to see you Again..! \xB2\xB2\xB2\xB2"<<endl;
			}
		}
	}
}
