#include<iostream>
using namespace std;

class smart_delivery{
	public:
		int id;
		double delivery_cost;
		string name;
		void display(int id,double delivery_cost,string name){
			cout<<" Delivery Information"<<endl;
			cout<<" Id:"<<id<<endl;
			cout<<" Cost:"<<delivery_cost<<endl;
			cout<<" Customer:"<<name<<endl;
		}
};

	class Express_delivery : public smart_delivery{
		public:
			string quality;
			using smart_delivery::display;
			void display(int id,double delivery_cost,string name,string quality)
			{
			cout<<"Express Delivery information"<<endl;
			cout<<" Id:"<<id<<endl;
			cout<<" Cost:"<<delivery_cost<<endl;
			cout<<" Customer:"<<name<<endl;
			cout<<" priority:"<<quality<<endl;
		}
	};
	
			
	
int main(){
	Express_delivery e1,e2;
	e1.display(101,806.2,"Shahab");
	cout<<endl;
	e2.display(215,2340.98,"Saqib","High");
	
}
	
	
	
	