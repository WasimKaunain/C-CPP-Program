//Program 19
// Icrement and Decrement operator overloading

#include<iostream>
#include<string>
using namespace std;

struct Student
	{
		private:
		int rollNo;
		string name;
		int age;
		
		public:
		setData(int rollNo,string name,int age)
			{
				this->rollNo=rollNo;
				this->name=name;
				this->age;
			}
			
		getData()
			{
				cout<<"NAME	: "<<name<<endl;
				cout<<"ROLL NO	: "<<rollNo<<endl;
				cout<<"AGE	: "<<age<<endl<<endl;
			}
			
		void operator ++()
			{
				++this->rollNo;
			}
			
		void operator ++ (int)
			{
				this->rollNo++;
			}
		
	} ;
	
	typedef Student student;
	
int main()
{
	student s1;
	s1.setData(001,"Wasim Kaunain",22);
	s1.getData();
	++s1;
	s1.getData();
	s1++;
	s1.getData();
	return 0;
}


