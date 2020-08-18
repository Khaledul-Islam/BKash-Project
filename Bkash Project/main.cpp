#include<iostream>
#include<fstream>
#include<cctype>
#include<iomanip>
#include<cstdlib>
using namespace std;





class bkash
{
	int acno;
	char name[50];
	int deposit;


public:
	void create_account();
	void show_account() const;
	void modify();
	void dep(int);
	void draw(int);
	void report() const;
	int retacno() const;
	int retdeposit() const;
	char rettype() const;	                    //class ends here
};

void bkash::create_account()
{
	cout<<"\n\n\tEnter Mobile No. :";
	cin>>acno;
	cout<<"\n\n\tEnter Your Name :";
	cin.ignore();
	cin.getline(name,50);

	cout<<"\n\n\tEnter The Initial amount Up To 200 : ";
	cin>>deposit;
	cout<<"\n\n\tYour Bkash Account Created..";
	 cout<<"\n\n\tPress Enter To Return Main Menu.";
}

void bkash::show_account() const
{
	cout<<"\n\n\tBkash Account No. : "<<acno;
	cout<<"\n\n\tBkash Account Holder Name: ";
	cout<<name;

	cout<<"\n\n\tBalance amount : "<<deposit;
}


void bkash::modify()
{
	cout<<"\n\n\tBkash Account No. : "<<acno;
	cout<<"\n\n\tModify Bkash Account Holder Name : ";
	cin.ignore();
	cin.getline(name,50);

}


void bkash::dep(int x)
{
	deposit+=x;
}

void bkash::draw(int x)
{
	deposit-=x;
}

void bkash::report() const
{
	cout<<" "<<name<<setw(10)<<" "<<acno<<setw(15)<<deposit<<endl;
}


int bkash::retacno() const
{
	return acno;
}

int bkash::retdeposit() const
{
	return deposit;
}





void write_account();
void display_sp(int);
void edit_account(int);
void delete_account(int);
void display_all();
void deposit_withdraw(int, int);
void intro();


int check(string bob)
{
    if(bob.length()!=11)
        return 0;
    for(int i=0;i<bob.length();i++)
    {
        if(bob[i]<48||bob[i]>57)
          return 0;

    }

    return 1;
}

int main()
{
	char ch;
	int num;
	intro();
	do
	{

		system("cls");
		intro();
		cout<<"\n\n\t\t\t...::::\xB2\xB2       WELCOME TO BKASH          \xB2\xB2:::::....\n\n";
		cout<<"\n\n\t\t\t\t\tMAIN MENU\n\n";
		cout<<"\n\n\t\t\t\t\t[1]. CREAT A BKASH ACCOUNT";
		cout<<"\n\n\t\t\t\t\t[2]. CASH  IN";
		cout<<"\n\n\t\t\t\t\t[3]. CASH OUT ";
		cout<<"\n\n\t\t\t\t\t[4]. SEND MONEY";
		cout<<"\n\n\t\t\t\t\t[5]. BUY AIRTIME ";
		cout<<"\n\n\t\t\t\t\t[6]. CHEACK BALANCE";
		cout<<"\n\n\t\t\t\t\t[7]. ALL ACCOUNT HOLDER LIST";
		cout<<"\n\n\t\t\t\t\t[8]. DELETE AN ACCOUNT";
		cout<<"\n\n\t\t\t\t\t[9]. EDIT AN ACCOUNT";
		cout<<"\n\n\t\t\t\t\t[0]. EXIT";
        cout<<"\n\n\n\n\n\t\t\t\t    \xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2";
        cout<<"\n\n\n\n\t\t\t\tEnter Your Choice:";
		cin>>ch;

		switch(ch)
		{
		case '1':
			write_account();
			break;
		case '2':
			cout<<"\n\n\tEnter The account No. : "; cin>>num;
			deposit_withdraw(num, 1);
			break;
		case '3':
			cout<<"\n\n\tEnter The account No. : "; cin>>num;
			deposit_withdraw(num, 2);
			break;
		case '4':
			cout<<"\n\n\tEnter The account No. : "; cin>>num;
			deposit_withdraw(num, 3);
			break;
        case '5':
            cout<<"\n\n\tEnter Your Account No: "; cin>>num;
            deposit_withdraw(num, 4);
            break;
        case '6':
			cout<<"\n\n\tEnter The account No. : "; cin>>num;
			display_sp(num);
			break;
		case '7':
			display_all();
			break;
		case '8':
			cout<<"\n\n\tEnter The account No. : "; cin>>num;
			delete_account(num);
			break;
		 case '9':
			cout<<"\n\n\tEnter The account No. : "; cin>>num;
			edit_account(num);
			break;
		 case '0':
			cout<<"\n\n\tThanks for using Bkash System :) :)";
			break;
		 default :cout<<"Invalid Number.";
		}
		cin.ignore();
		cin.get();
	}while(ch<='9');
	return 0;
}




void write_account()
{
	bkash ac;
	ofstream outFile;
	outFile.open("bkash.dat",ios::binary|ios::app);
	ac.create_account();
	outFile.write(reinterpret_cast<char *> (&ac), sizeof(bkash));
	outFile.close();
}



void display_sp(int n)
{
	bkash ac;
	bool flag=false;
	ifstream inFile;
	inFile.open("bkash.dat",ios::binary);
	if(!inFile)
	{
		cout<<"\n\n\tFile could not be open !! Press any Key...";
		return;
	}
	cout<<"\n\n\tBALANCE DETAILS\n";

    	while(inFile.read(reinterpret_cast<char *> (&ac), sizeof(bkash)))
	{
		if(ac.retacno()==n)
		{
			ac.show_account();
			flag=true;
		}
	}
	inFile.close();
	if(flag==false)
		cout<<"\n\n\tAccount number does not exist";
		cout<<"\n\n\tPress Enter To Return Main Menu.";

}




void edit_account(int n)
{
	bool found=false;
	bkash ac;
	fstream File;
	File.open("bkash.dat",ios::binary|ios::in|ios::out);
	if(!File)
	{
		cout<<"\n\n\tFile could not be open !! Press any Key...";
		return;
	}
	while(!File.eof() && found==false)
	{
		File.read(reinterpret_cast<char *> (&ac), sizeof(bkash));
		if(ac.retacno()==n)
		{
			ac.show_account();
			cout<<"\n\n\tEnter The New Details of account"<<endl;
			ac.modify();
			int pos=(-1)*static_cast<int>(sizeof(bkash));
			File.seekp(pos,ios::cur);
			File.write(reinterpret_cast<char *> (&ac), sizeof(bkash));
			cout<<"\n\n\t Record Updated";
			cout<<"\n\n\tPress Enter To Return Main Menu.";
			found=true;
		  }
	}
	File.close();
	if(found==false)
		cout<<"\n\n\t Record Not Found ";
}




void delete_account(int n)
{
	bkash ac;
	ifstream inFile;
	ofstream outFile;
	inFile.open("bkash.dat",ios::binary);
	if(!inFile)
	{
		cout<<"\n\n\tFile could not be open !! Press any Key...";
		return;
	}
	outFile.open("Temp.dat",ios::binary);
	inFile.seekg(0,ios::beg);
	while(inFile.read(reinterpret_cast<char *> (&ac), sizeof(bkash)))
	{
		if(ac.retacno()!=n)
		{
			outFile.write(reinterpret_cast<char *> (&ac), sizeof(bkash));
		}
	}
	inFile.close();
	outFile.close();
	remove("bkash.dat");
	rename("Temp.dat","bkash.dat");
	cout<<"\n\n\tRecord Deleted ..";
	 cout<<"\n\n\tPress Enter To Return Main Menu.";
}



void display_all()
{
	bkash ac;
	ifstream inFile;
	inFile.open("bkash.dat",ios::binary);
	if(!inFile)
	{
		cout<<"\n\n\tFile could not be open !! Press any Key...";
		return;
	}
	cout<<"\n\n\t\tACCOUNT HOLDER LIST\n\n\n\n";

	cout<<"NAME                  A/c no.           Balance\n\n";

	while(inFile.read(reinterpret_cast<char *> (&ac), sizeof(bkash)))
	{
		ac.report();

	}
	inFile.close();
}



void deposit_withdraw(int n, int option)
{
	int amt;
	char no;
	string robi;
	string jum;
	bool found=false;
	bkash ac;
	fstream File;
	File.open("bkash.dat", ios::binary|ios::in|ios::out);
	if(!File)
	{
		cout<<"\n\n\tFile could not be open !! Press any Key...";
		return;
	}
	while(!File.eof() && found==false)
	{
		File.read(reinterpret_cast<char *> (&ac), sizeof(bkash));
		if(ac.retacno()==n)
		{
			ac.show_account();
			if(option==1)
			{
				cout<<"\n\n\tTO CASH IN ";
				cout<<"\n\n\tEnter The amount to be Cash in: ";
				cin>>amt;
				ac.dep(amt);
				cout<<"\n\n\tMoney Add To Your Account.";
			}
			if(option==2)
			{
				cout<<"\n\n\tTO CASH OUT ";
				 cout<<"\n\n\tEnter Agent Bkash account number :";
                cin>>jum;
				cout<<"\n\n\tEnter The amount to be Cash out: ";
				cin>>amt;
				int bal=ac.retdeposit()-amt;
				if(bal<=50 ){
					cout<<"\n\n\tInsufficient Balance";
					 cout<<"\n\n\tPress Enter To Return Main Menu.";
				}
				else
					ac.draw(amt);
					cout<<"\n\n\tCash Out Successful.";
			}
			if(option==3)
            {
                cout<<"\n\n\tSend Money";
                cout<<"\n\n\tEnter The Number To Send:";
                cin>>jum;
                cout<<"\n\n\tEnter The amount to be Send:";
                cin>>amt;
                cout<<"\n\n\tYOUR MONEY SEND TO : "<<jum;

                int bal=ac.retdeposit()-amt;
                if(bal<50 ){
                    cout<<"\n\n\tInsufficient Balance";
                     cout<<"\n\n\tPress Enter To Return Main Menu.";
                }
                else
                    ac.draw(amt);
                    cout<<"\n\n\tYour Money Send To: "<<jum;
            }
            if(option==4)
            {
                cout<<"\n\n\tBuy Airtime";
                cout<< "\n";
                cout<<"\n\n\t[1] Robi.\n";
                cout<<"\n\n\t[2] Airtel.\n";
                cout<<"\n\n\t[3] Teletalk.\n";
                cout<<"\n\n\t[4] Banglalink.\n";
                cout<<"\n\n\t[5] Grameenphone.\n\n\n\n";

              cout<<"\n\n\tEnter Your choice:";
              cin>>no;
              int bal;

              switch(no)
              {
           case '1':

                cout<<"\n\n\tEnter Your Robi  Number : ";
                cin>>robi;
                if(check(robi)){
                if(robi[0]=='0'&&robi[1]=='1'&&robi[2]=='8'){
                cout<<"\n\n\tEnter Your Amount: ";
                cin>>amt;

                bal=ac.retdeposit()-amt;
                if(bal<50 ){
                    cout<<"\n\n\tInsufficient balance";

                }
                else
                    ac.draw(amt);
                    cout<<"\n\n\tYour Money Send To: "<<robi;


                }
                else
                    cout<<"\n\n\tEnter Robi Number.";


                }
                else
                    cout<<"\n\n\tEnter Valid Number.";

                break;

           case '2':

               cout<<"\n\n\tEnter Your Number : ";
                cin>>robi;
                if(check(robi)){
                if(robi[0]=='0'&&robi[1]=='1'&&robi[2]=='6'){
                cout<<"Enter Your Amount: ";
                cin>>amt;

                 bal=ac.retdeposit()-amt;
                if(bal<50 ){
                    cout<<"\n\n\tInsufficient Balance";

                }
                else
                    ac.draw(amt);
                    }
                else
                    cout<<"\n\n\tEnter Airtel Number.";

                }
                else
                    cout<<"\n\n\tEnter Valid Number.";

                break;

           case '3':
                cout<<"\n\n\tEnter Your Number :";
                cin>>robi;
                if(check(robi)){
                if(robi[0]=='0'&&robi[1]=='1'&&robi[2]=='5'){
                cout<<"\n\n\tEnter Your Amount: ";
                cin>>amt;

                 bal=ac.retdeposit()-amt;
                if(bal<50 )
                    cout<<"\n\n\tInsufficient Balance";

                else
                    ac.draw(amt);
                     }
                else
                    cout<<"\n\n\tEnter Telitalk Number.";


                }
                else
                    cout<<"\n\n\tEnter Valid Number.";

                break;

           case '4':
                cout<<"\n\n\tEnter Your Banglalink Number : ";
                cin>>robi;
                if(check(robi)){
                if(robi[0]=='0'&&robi[1]=='1'&&robi[2]=='9'){
                cout<<"\n\n\tEnter Your Amount: ";
                cin>>amt;

                 bal=ac.retdeposit()-amt;
                if(bal<50 ){
                    cout<<"\n\n\tInsufficient Balance";

                }
                else
                    ac.draw(amt);
                     }
                else
                    cout<<"\n\n\tEnter Banglalink Number.";


                }
                else
                    cout<<"\n\n\tEnter Valid Number.";

                break;

            case '5':
                cout<<"\n\n\tEnter Your Grameenphone Number :";
                cin>>robi;
                if(check(robi)){
                if(robi[0]=='0'&&robi[1]=='1'&&robi[2]=='7'){
                cout<<"\n\n\tEnter Your Amount: ";
                cin>>amt;

                 bal=ac.retdeposit()-amt;
                if(bal<50 ){
                    cout<<"\n\n\tInsufficient Balance";

                }
                else
                    ac.draw(amt);
                    cout<<"\n\n\t Your Money Send Succsecfully\n\n";

                     }
                else
                    cout<<"\n\n\tEnter Grameenphone Number.";


                }
                else
                    cout<<"\n\n\tEnter Valid Number.";

                break;

              }




            }

			int pos=(-1)*static_cast<int>(sizeof(ac));
			File.seekp(pos,ios::cur);
			File.write(reinterpret_cast<char *> (&ac), sizeof(bkash));

			found=true;
	       }
         }
	File.close();
	if(found==false)
		cout<<"\n\n\t Record Not Found ";
        cout<<"\n\n\tPress Enter To Return Main Menu.";
}





void intro()
{
	cout<<"\n\n\t\t\t\t\t\t SHUVO \n\n"<<endl;
  cout<<"\t\tNTERNATIONAL UNIVERSITY OF BUSSINESS AGRICULTURE AND TECHNOLOGY \n\n\n\n\n";

}

