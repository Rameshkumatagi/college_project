/*Provide user following information
  1.Total number of students in a branch
  2.Topper of branch
  3.Branch wise pass percentage
  4.Student details based on name
 */


#include<iostream>
#include"students.hpp"
#include<fstream>      
#include<vector>     
#include<sstream>     //stringstream
#include<cctype>      // toupper
using namespace std;

vector<student*> objs;

int display()
{
		cout<<"1: Total number of students in science branch"<<endl;
		cout<<"2: Total number of students in arts branch"<<endl;
		cout<<"3: Pass percentage of science branch"<<endl;	
		cout<<"4: Pass percentage of arts branch"<<endl;
		cout<<"5: Science topper details"<<endl;
		cout<<"6: Arts topper details"<<endl;
		cout<<"7: Student details based on name"<<endl;
		cout<<"8: Quit"<<endl;
}

void readFile()
{
		ifstream file("studentdata.txt");
		string buffer;
		string name, branch;
		int std;
		float score;

		if(file.is_open())
		{
				student *stdobj	;
				// 3 getlines to be ignored
				getline(file,buffer);

				getline(file,buffer);

				getline(file,buffer);
			while(!file.eof()){
				getline(file,buffer);
				if(buffer.size() != 0)
				{
						string temp;
						stringstream ss(buffer);
						getline(ss,temp,',');
						name = temp;	

						getline(ss,temp,',');
						std = stoi(temp);	
						getline(ss,temp,',');
						branch = temp;
						getline(ss,temp,',');
						score = stof(temp);
						stdobj = new student(name,std,branch,score);
						objs.push_back(stdobj);
				}

			}	
		}
		else
		{
				throw "Failed to open file" ;
		}			

}
string convertToUpper(string str)
{
	for(int i=0;i<str.size();i++)
	{
		str[i] = toupper(str[i]);
	}
	return str;
}


void printStudentDetails(string name)
{
		bool found = false;
		name = convertToUpper(name);
		string sname;
		for(int i=0;i<objs.size();i++)
		{
				sname = convertToUpper(objs[i]->getName());
				if(sname == name)
				{
						found = true;
						cout<<"Name="<<objs[i]->getName()<<endl;
						cout<<"Class="<<objs[i]->getCls()<<endl;
						cout<<"Branch="<<objs[i]->getBranch()<<endl;
						cout<<"Score="<<objs[i]->getScore()<<endl;
						break;
				}
		}
		if(!found)
			cout<<"No student with name "<<name <<" are registered\n";

}

void freeMem()
{
	for(int i=0;i<objs.size();i++)
		delete objs[i];

}

void printTopper(string branch, int cls)
{
		if(cls != 11 && cls != 12)
		{
			cout<<"Invalid input\n" ;
			return;
		}
		float sc = 0;
		student *topper;
		for(int i=0;i<objs.size();i++)
		{
				if(objs[i]->getBranch() == branch && objs[i]->getCls() == cls)
				{
						if(objs[i]->getScore() > sc)
						{
								sc = objs[i]->getScore();
								topper = objs[i];	
						}
				}
		}
		cout<<"Name="<<topper->getName()<<"\t";
		cout<<"Score="<<topper->getScore()<<endl;

}

int main()
{
		cout<<"Welcome!! please select an option"<<endl;
		display();
		int ch ;
		try
		{
				readFile();
		}
		catch(const char* error)
		{
				cout<<error<<endl;
				return -1;
		}
		do{
				int cls;
				string name;
				cin >> ch;
				switch(ch)
				{
						case 1:
								cout<<student::getSciCnt()<<endl;
								break;
						case 2:
								cout<<student::getArtCnt()<<endl;
								break;
						case 3:
								cout<<student::getSciPassPercent()<<endl;
								break;
						case 4:
								cout<<student::getArtPassPercent()<<endl;			
								break;
						case 5:
								cout<<"Enter class: 11 or 12?"<<endl;
								cin>>cls;
								printTopper("science",cls);
								break;
						case 6:
								cout<<"Enter class: 11 or 12?"<<endl;
								cin>>cls;
								printTopper("arts",cls);		
								break;
						case 7:
								cout<<"Enter name of the student"<<endl;
								cin>>name;
								printStudentDetails(name);
								break;
						case 8:
								freeMem();
								cout<<"Thak you"<<endl;
								break;
						default:
								cout<<"Wrong choice"<<endl;
								break;
				}	
		}while(ch != 8);	

}
