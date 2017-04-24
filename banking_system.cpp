/****************PROJECT ON BANKING SYSTEM***********************/


#include<iostream>
using namespace std;
/***************************************************/
/*                 CLASS DEFINED				   */
/***************************************************/

class BankingSystem
{
		private:
			long int account_number,mob_number,balance,newbalance,amount;
			string name,address,email;
			char choice,ch;
		public:
			void open_new_account(int n,BankingSystem *ob);
			void account_info();
			void withdraw();
			void deposit();
			void balance_info();
			int check(long int account_number,BankingSystem *ob,int n); 
			int  ret();
};

/**************************************************/
/*        FUNCTION FOR OPENING NEW ACCOUNT        */
/**************************************************/

void BankingSystem::open_new_account(int n,BankingSystem *ob)
{
		newbalance=0,balance=0;
		int f=0;
		cout<<"HEY YOU ARE OUR "<<(n+1)<<" CUSTOMER"<<endl<<endl;
		cout<<"ENTER THE DESIRED ACCOUNT NUMBER"<<endl;
		do{
			cin>>account_number;
			if(account_number==check(account_number,ob,n))
			{
				cout<<"ACCOUNT NUMBER ALREADY EXISTS ENTER UNIQUE ONE"<<endl;
				f=1;
			}
			else
				f=0;
		}while(f==1);
		getline(cin,name);
		cout<<"YOUR NAME PLEASE"<<endl;
		getline(cin,name);
		cout<<"YOUR ADDRESS"<<endl;
		getline(cin,address);
		cout<<"YOUR MOBILE NUMBER"<<endl;
		cin>>mob_number;
		getline(cin,address);
		cout<<"ENTER YOUR VALID EMAIL ID"<<endl;
		getline(cin,email);
		cout<<"DO YOU WANT DEPOSIT AMOUNT Y/N"<<endl;
			cin>>choice;
		do{
			if(toupper(choice)=='Y')
			{
				cout<<"ENTER THE AMOUNT"<<endl;
				cin>>newbalance;
				balance=balance+newbalance;
			}
			else if(toupper(choice)=='N')
			{
				cout<<"NO WORRIES, YOU CAN ALSO HAVE ZERO BALANCE ACCOUNT"<<endl;
				break;
			}
			else
				cout<<"ENTER VALID CHOICE PLEASE"<<endl;
			cout<<"WANT TO ADD MORE DEPOSIT ? Y/N"<<endl;	
			cin>>ch;
		}while(toupper(ch)=='Y');	
		cout<<endl;
		cout<<"HELLO "<<name<<" YOUR ACCOUNT NUMBER "<<account_number<<" HAS BALANCE->"<<balance<<endl<<endl;
}

/**************************************************/
/*   FUNCTION FOR CHECKING THE ACCOUNT EXISTANCE  */
/**************************************************/

int BankingSystem::check(long int x,BankingSystem *ob,int n)
{
	for(int i=0;i<n;i++)
	{
		if(ob[i].ret()==x)
			return x;
	}
	return 0;
	
}

/******************************************************************/
/*   FUNCTION FOR GETTING ACCOUNT NUMBER OF A PARTICULAR RECORD  */
/******************************************************************/

int  BankingSystem::ret()
{
	return account_number;
}

/**************************************************/
/*   FUNCTION FOR CHECKING THE ACCOUNT INFO  */
/**************************************************/

void BankingSystem::account_info()
{
		cout<<"HELLO "<<name<<" YOUR ACCOUNT NUMBER "<<account_number<<" HAS BALANCE->"<<balance<<endl;
}

/**************************************************/
/*   FUNCTION FOR WITHDRAWING THE AMOUNT  */
/**************************************************/

void BankingSystem::withdraw()
{
			cout<<"HELLO "<<name<<" HAS BALANCE-> "<<balance<<endl<<" ENTER THE AMOUNT TO BE WITHDRAWN"<<endl;
			do{	
				cin>>amount;
				if(balance<amount)
					cout<<"INSUFFICIENT BALANCE"<<endl;
				else
					balance-=amount;
				cout<<"DO YOU WANT TO CONTINUE WITHDRAWING -Y/N"<<endl;		
				cin>>ch;	
			}while(toupper(ch)=='Y');
		cout<<"NEW BALANCE IS "<<balance<<endl;
}

/**************************************************/
/*   FUNCTION FOR DEPOSITING THE AMOUNT  */
/**************************************************/

void BankingSystem::deposit()
{
			cout<<"HELLO "<<name<<" HAS BALANCE-> "<<balance<<endl<<" ENTER THE AMOUNT TO DEPOSIT"<<endl;
			do{
				cin>>amount;
				balance+=amount;
				cout<<"DO YOU WANT TO CONTINUE DEPOSITING -Y/N"<<endl;		
				cin>>ch;	
			}while(toupper(ch)=='Y');
	cout<<"NEW BALANCE IS "<<balance<<endl;	
}

/**************************************************/
/*   FUNCTION FOR CHECKING THE BALANCE INFO  */
/**************************************************/

void BankingSystem::balance_info()
{
			cout<<"HELLO "<<name<<" YOU HAS BALANCE-> "<<balance<<endl;
}

/**************************************************/
/*            MAIN FUNCTION DEFINED               */
/**************************************************/

int main(void)
{
		int wish,i=0,n=0,f=0;;
		char demand;
		BankingSystem ob[100];
		long int tmp=ob[0].ret();
		do{
		    f=0;
			cout<<"\t\t\t"<<"WELCOME TO SECTION C BANK "<<endl<<endl;
			cout<<"PRESS 1 TO OPEN NEW ACCOUNT"<<endl;
			cout<<"PRESS 2 TO CHECK YOUR ACCOUNT INFO"<<endl;
			cout<<"PRESS 3 TO WITHDRAW AMOUNT"<<endl;
			cout<<"PRESS 4 TO DEPOSIT AMOUNT"<<endl;
			cout<<"PRESS 5 TO CHECK YOUR BALANCE INFO"<<endl;
			cout<<"PRESS 6 TO EXIT"<<endl<<endl;
			cout<<"ENTER YOUR WISH"<<endl;
			cin>>wish;
			switch(wish)
			{
				case 1:
					ob[i].open_new_account(n,ob);
					n=n+1;
					i=i+1;
					break;
				case 2:
				do{
					cout<<"ENTER YOUR ACCOUNT NUMBER"<<endl;
					cin>>tmp;
					for(int j=0;j<=n-1;j++){
						if(tmp==ob[j].ret()){
							ob[j].account_info();
							f=1;
							break;
					    }	
					}
					if(f==0)
						cout<<"INVALID ACCOUNT NUMBER"<<endl;
					cout<<"DO YOU WANT TO CHECK OTHER ACCOUNT DETAILS -Y/N"<<endl;
			        cin>>demand;
			        }while(toupper(demand)=='Y');
						break;
				case 3:
						cout<<"ENTER YOUR ACCOUNT NUMBER"<<endl;
						cin>>tmp;
						for(int j=0;j<=n-1;j++){
							if(tmp==ob[j].ret()){
								ob[j].withdraw();
								f=1;
								break;
							}
						}	
						if(f==0)
							cout<<"INVALID ACCOUNT NUMBER"<<endl;
						break;
				case 4:
						cout<<"ENTER YOUR ACCOUNT NUMBER"<<endl;
						cin>>tmp;
						for(int j=0;j<=n-1;j++){
							if(tmp==ob[j].ret()){
								ob[j].deposit();
								f=1;
							    break;
							}
						}
						if(f==0)
						cout<<"INVALID ACCOUNT NUMBER"<<endl;
						break;
				case 5:
				        do{
				    		cout<<"ENTER YOUR ACCOUNT NUMBER"<<endl;
						    cin>>tmp;
						    for(int j=0;j<=n-1;j++){
							    if(tmp==ob[j].ret()){
							    	ob[j].balance_info();
						    		f=1;
						    		break;
							    }
					    	}
				    		if(f==0)
					    		cout<<"INVALID ACCOUNT NUMBER"<<endl;
							cout<<"DO YOU WANT TO CHECK OTHER ACCOUNT DETAILS -Y/N"<<endl;
			            cin>>demand;
			            }while(toupper(demand)=='Y');
						break;
				case 6:
						cout<<"THANK YOU"<<endl;
						demand='N';
						break;
				default:
						cout<<"INVALID CHOICE";
						break;
			}	
			cout<<"DO YOU WANT TO CONTINUE BANKING-Y/N"<<endl;
			cin>>demand;
		}while(toupper(demand)=='Y');
}
