#include <iostream>
#include<fstream>
#include<stdlib.h>
#include<string.h>
using namespace std;
class groceries
{
	private:
		char buf[60],groceries_name[20],floor[10],rack[10],price[10];
		public:
			void read()
			{
				cout<<"Enter the Groceries_name"<<endl;
				cin>>groceries_name;
				cout<<"Enter the floor"<<endl;
				cin>>floor;
				cout<<"Enter the rack"<<endl;
				cin>>rack;
				cout<<"Enter the price\n";
				cin>>price;
			}
			void pack(fstream & ofile)
			{
				read();
				strcpy(buf,"");
				strcat(buf,groceries_name);
				strcat(buf,"|");
				strcat(buf,floor);
				strcat(buf,"|");
				strcat(buf,rack);
				strcat(buf,"|");
				strcat(buf,price);
				strcat(buf,"|");
				while(strlen(buf)<60)
				strcat(buf,"!");
				strcat(buf,"\n");
				ofile.write(buf,strlen(buf));
			}
			void unpack(fstream & ifile)
			{
				char extra[60];
				cout<<"\tGroceries_name\tFloor\tRack\tPrice\n";
				while(!ifile.eof())
				{
					ifile.getline(groceries_name,20,'|');
					ifile.getline(floor,20,'|');
					ifile.getline(rack,5,'|');
					ifile.getline(price,10,'|');
					ifile.getline(extra,60,'\n');
					cout<<"\t"<<groceries_name<<"\t"<<floor<<"\t"<<rack<<"\t"<<price<<"\n";
				}
			}
			int search_item(fstream & ifile,char key[])
			{
				int ic=0;
				char extra[60];
				cout<<"\nSearched item details are:"<<endl;
				cout<<"\tGroceries_name\tFloor\tRack\tprice\t"<<endl;
				while(!ifile.eof())
				{
					ifile.getline(groceries_name,20,'|');
					ifile.getline(floor,20,'|');
					ifile.getline(rack,5,'|');
					ifile.getline(price,10,'|');
					ifile.getline(extra,60,'\n');
					if(strcmp(groceries_name,key)==0)
					{
						cout<<"\t"<<groceries_name<<"\t"<<floor<<"\t"<<rack<<"\t"<<price<<endl;
						ic++;
					}
				}
				if(ic==0)
				return 0;
				return 1;
			}
			int search_floor(fstream & ifile,char input[10])
			{
				int fc=0;
				char extra[60];
				cout<<"\nFloor "<<input<<"contains following items...."<<endl;
				cout<<"\tGroceries_name\tRack\tPrice"<<endl;
				while(!ifile.eof())
				{
					ifile.getline(groceries_name,20,'|');
					ifile.getline(floor,10,'|');
					ifile.getline(rack,5,'|');
					ifile.getline(price,10,'|');
					ifile.getline(extra,60,'\n');
					if(strcmp(floor,input)==0)
					{
						cout<<"\t"<<groceries_name<<"\t"<<rack<<"\t"<<price<<"\n";
						fc++;
					}
				}
				if(fc==0)
				return 0;
				return 1;
			}
};
int operation()
{
	int ch,n,i,sch;
	char key[20],extra[60],buf[60],groceries_name[20],floor[10],rack[10],price[10];
	int floor1,res;
	groceries gro;
	fstream ifile,ofile,iofile,f1,f2,f3,f4,f5;
	ofile.open("groceries.txt",ios::out|ios::app);
	ifile.open("groceries.txt",ios::in);
	iofile.open("groceries.txt",ios::in|ios::out);
	ofile.close();
	ifile.close();
	iofile.close();
	for(;;)
	{
		cout<<"1:Insert\n2:Display\n3:Search\n4:Modify\n5:Exit"<<endl;
		cout<<"Enter the choice:"<<endl;
		cin>>ch;
		switch(ch)
		{
			case 1:f1.open("groceries.txt",ios::in|ios::app);
			cout<<"Enter the number of items :"<<endl;
			cin>>n;
			for(i=0;i<n;i++)
			{
				gro.pack(f1);
			}
			f1.close();
			cout<<"Items are added successfully......\n\n";
			break;
			case 2:f2.open("groceries.txt",ios::in);
			gro.unpack(f2);
			f2.close();
			break;
			case 3:cout<<"Enter the choice of search \n";
			cout<<"1:Floor wise\n2:Item wise"<<endl;
			cin>>sch;
			switch(sch)
			{
				case 1:cout<<"Floor wise searching \n\n";
				f3.open("groceries.txt",ios::in);
				cout<<"Enter the floor number...\n\n";
				cin>>floor;
				if(gro.search_floor(f3,floor)==0)
				cout<<"\t\tFloor not found...."<<endl;
				f3.close();
				break;
				
				case 2:cout<<"Item wise searching....!"<<endl;
				f4.open("groceries.txt",ios::in);
				cout<<"Enter the Item name to be searched:"<<endl;
				cin>>key;
				if(gro.search_item(f4,key)==0)
				cout<<"Item not found....."<<endl;
				f4.close();
				break;
			}
			cout<<"\t\t\tSearch Done.....!\t\t"<<endl;
			break;
			case 4:f5.open("groceries.txt",ios::in|ios::out);
			cout<<"Enter the item name to be modified :"<<endl;
			cin>>key;
			while(!f5.eof())
			{
				f5.getline(groceries_name,20,'|');
				if(!strcmp(groceries_name,key))
				{
					f5.getline(floor,10,'|');
					f5.getline(rack,10,'|');
					f5.getline(price,10,'|');
					f5.getline(extra,60,'\n');
					cout<<"\t\t\tRecord found...!"<<endl;
					cout<<"\t\tgroceries_name\tfloor\track\tprice"<<endl;
					cout<<"\t\t"<<groceries_name<<"\t"<<floor<<"\t"<<rack<<"\t"<<price<<endl;
					cout<<"Enter the modification details:"<<endl;
					cout<<"Enter new groceries name :"<<endl;
					cin>>groceries_name;
					cout<<"Enter the floor:"<<endl;
					cin>>floor;
					cout<<"Enter the rack:"<<endl;
					cin>>rack;
					cout<<"Enter the price:"<<endl;
					cin>>price;
					strcpy(buf,"");
					strcat(buf,groceries_name);
					strcat(buf,"|");
					strcat(buf,floor);
					strcat(buf,"|");
					strcat(buf,rack);
					strcat(buf,"|");
					strcat(buf,price);
					strcat(buf,"|");
					while(strlen(buf)<60)
					strcat(buf,"!");
					strcat(buf,"\n");
					f5.seekp(-61,ios::cur);
					if(f5<<buf)
					cout<<"\t\tRecord updated....!"<<endl;
					else
					cout<<"Something went wrong....!!!"<<endl;
					f5.close();
					break;
				}
				else
				{
					char a[60];
					f5.getline(a,60,'\n');
				}
			}
			break;
			case 5:exit(0);		
		}
	}
	return 0;
}

int main()
{   
	groceries gro;
	fstream f2;
	int sh;
	int pass;
	pass=2522;
	cout<<"Which login do you choose :"<<endl;
	cout<<"1:Admin Login\n2:Customer Login"<<endl;
	cin>>sh;
	
	if(sh==1)
	{
	cout<<"Enter the password :"<<endl;
	cin>>pass;
	if(pass==2522)
	{
	operation();
	}
	else
	{
	cout<<"Wrong Password :"<<endl;
	}
    }	    
	else if(sh==2)
	{
	cout<<"\t\t Available Items are :"<<endl;
	       f2.open("groceries.txt",ios::in);
	       gro.unpack(f2);
		   f2.close();     
	}
	else
	{
	cout<<"\t\t Invalid Input"<<endl;	
	}
    
	return 0;
}