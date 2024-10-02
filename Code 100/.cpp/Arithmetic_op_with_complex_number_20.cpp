//Program 20
// Arithmetic operation with complex number using operator overloading

#include<iostream>
using namespace std;
class Complex
	{
		int a,b;
		
		public:
		void setData(int a,int b)
			{
				this->a=a;
				this->b=b;
			}
			
		void getData()
			{
				if(this->b>=0)
				cout<<a<<" + i"<<b<<endl<<endl;
				else
				cout<<a<<" - i"<<b*(-1)<<endl<<endl;
				
			}
			
		void operator ++()
			{
				++this->a;
				++this->b;
			}
			
		void operator ++(int)
			{
				this->a++;
				this->b++;
			}
			
		Complex operator -(Complex temp)
			{
				Complex res;
				res.a=a - temp.a;
				res.b=b - temp.b;
				return res;
			}
			
		Complex operator +(Complex temp)
			{
				Complex res;
				res.a=a + temp.a;
				res.b=b + temp.b;
				return res;
			}
	};

int main()
{
	Complex x,y,z;
	x.setData(4,5);
	y.setData(6,-8);
	
	cout<<"Value of x :";
	x.getData()	;
	
	cout<<"Value of y :";
	y.getData();
	cout<<"After subtracting y from x and storing result in z..."<<endl; 
	cout<<"Value  of z :";
	z=x-y; 
	
	z.getData();
	
	++z;
	
	cout<<"After incrementing z..."<<endl;	
	
	cout<<"Value  of z :";
	z.getData();
	
	y= z + x;
	
	
	cout<<"After adding z and x and storing result in y..."<<endl;
	cout<<"Value of y : ";
	y.getData();
		
//	++x;
	//x.getData();
	//x++;
	//x.getData();
	return 0;
}


