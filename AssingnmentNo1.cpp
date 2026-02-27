#include<iostream>
using namespace std;

class Library{
	public:
		string title;
		string author;
		string idnumber;

		Library(string title,string author,string idnumber){
			this->title = title;
			this->author = author;
			this->idnumber = idnumber;
		}

		virtual void showdetails(){
			cout << "TITLE: " << title << endl;
			cout << "AUTHOR: " << author << endl;
			cout << "ID NUMBER: " << idnumber << endl;
		}
};

class Book : public Library{
	private:
		short numberofpages;
		string genre;

	public:
		Book(string title,string author,string idnumber,
		     short numberofpages,string genre)
		: Library(title,author,idnumber){

			this->numberofpages = numberofpages;
			this->genre = genre;
		}

		void showdetails() override{
		    cout << " BOOK DETAILS: "<< endl;
			Library::showdetails(); 
			cout << "NUMBER OF PAGES: " << numberofpages << endl;
			cout << "GENRE: " << genre << endl;
			cout << "--------------------------" << endl;
		}
};

class Magazine : public Library{
	private:
		int issuenumber;
		string month;

	public:
		Magazine(string title,string author,string idnumber,
		         int issuenumber,string month)
		: Library(title,author,idnumber){

			this->issuenumber = issuenumber;
			this->month = month;
		}

		void showdetails() override{
			cout << "MAGAZINE DETAILS: "<< endl;
			Library::showdetails();
			cout << "ISSUE NUMBER: " << issuenumber << endl;
			cout << "PUBLICATION MONTH: " << month << endl;
			cout << "--------------------------" << endl;
		}
};

class Audiobook : public Library{
	private:
		float duration;
		string narratorname;

	public:
		Audiobook(string title,string author,string idnumber,
		          float duration,string narratorname)
		: Library(title,author,idnumber){

			this->duration = duration;
			this->narratorname = narratorname;
		}

		void showdetails() override{
            cout << " AUDIO BOOK DETAILS: "<< endl;
			Library::showdetails();
			cout << "DURATION (hours): " << duration << endl;
			cout << "NARRATOR NAME: " << narratorname << endl;
			cout << "--------------------------" << endl;
		}
};

int main(){

	Book b1("C++ Programming","Peter","1",80,"Logical");
    Book b2("C++ Programming","Peter","1",80,"Logical");

	Audiobook a1("Learn OOP","Smeed","3",4.5,"David");
    Audiobook a2("Learn OOP","Smeed","3",4.5,"David");

	Magazine m1("Tech Monthly","Jason","2",102,"March");
    Magazine m2("Tech Monthly","Jason","2",102,"March");

	b1.showdetails();
	b2.showdetails();

	a1.showdetails();
	a2.showdetails();

	m1.showdetails();
	m2.showdetails();


	return 0;
}

