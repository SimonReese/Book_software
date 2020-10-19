// BookFinder.cpp : Software gestione libri
#include <iostream>
#include <vector>
#include <string>

using namespace std;

class Book_software {
public:
	Book_software();
	void add_book();
	void print_books();
	
	class Book {
	public:
		Book(string mtitle, string mauthor, string ISBN, string mcopyright);
		string get_title();
		string get_author();
		string get_ISBN();
		string get_copyright();
		bool is_checked_out();
		vector<string> get_details();
		void print_details();
		void check_book();
		bool operator==(Book& other);
		bool operator!=(Book& other);
	private:
		string title;
		string ISBN;
		string author;
		string copyright;
		bool checked_out;
	};

private:

	std::vector<Book> books;
	bool check_ISBN(string ISBN);

};

int main() {
	Book_software library();
}

Book_software::Book_software() {
	//Aggiungo libri al software
	add_book();
	//Stampo lista libri
	print_books();

	books[1] == books[1];
}

void Book_software::add_book() {
	//Lista titoli inseriti
	vector<string> titles;
	//Chiedo i titoli
	cout << "Inserisci i titoli dei libri da inserire nella lista. Termina scrivendo STOP" << endl;

	//Leggo i titoli
	while (true) {
		string title = "";
		cin >> title;
		if (title == "STOP") { break; } //Controllo se l'inserimento è terminato
		titles.push_back(title);
	}

	//Chiedo i dettagli dei libri
	cout << "Inserisci i dettagli dei libri" << endl;

	for (int i = 0; i < titles.size(); i++) {
		//Chiedo per ogni libro:
		cout << "Titolo: " << titles[i];

		//Autore
		string author = "";
		cout << "\nAutore: ";
		cin >> author;

		//ISBN
		string ISBN = "";
		do
		{
			cout << "\nISBN: ";
			cin >> ISBN;
		} while (!check_ISBN(ISBN)); //Controllo se l'ISBN è valido
		
		//Copyright
		string copyright = "";
		cout << "\nCopyright date: ";
		cin >> copyright;

		//Creo un oggetto di tipo libro
		Book book(titles[i], author, ISBN, copyright);
		//Salvo il libro nel software
		books.push_back(book);
	}
}

void Book_software::print_books() {
	cout << "\nLista libri:" << endl;
	for (int i = 0; i < books.size(); i++) {
		books[i].print_details();
	}
}

bool Book_software::check_ISBN(string ISBN){
	if (ISBN.size() != 13) { return false; }
	for (int i = 0; i < 12 ; i++) {
		if (!isdigit(ISBN.at(i))) { return false; }
	}
	return true;
}

Book_software::Book::Book(string mtitle, string mauthor, string mISBN, string mcopyright)
	:title{ mtitle }, author{ mauthor }, ISBN{ mISBN }, copyright{ mcopyright }, checked_out{ false }
{}

string Book_software::Book::get_title(){
	return title;
}

string Book_software::Book::get_author() {
	return author;
}

string Book_software::Book::get_ISBN() {
	return ISBN;
}

string Book_software::Book::get_copyright() {
	return copyright;
}

bool Book_software::Book::is_checked_out() {
	return checked_out;
}

vector<string> Book_software::Book::get_details() {
	vector<string> details;
	details.push_back(title);
	details.push_back(author);
	details.push_back(ISBN);
	details.push_back(copyright);
	if (checked_out) { details.push_back("1"); }
	else { details.push_back("0"); }
	return details;
}

void Book_software::Book::print_details() {
	cout << "Titolo: " << get_title() << endl
		<< "Autore: " << get_author() << endl
		<< "ISBN: " << get_ISBN() << endl
		<< "Copyright Date: " << get_copyright() << endl
		<< "Checked out: " << is_checked_out() << endl;
}

void Book_software::Book::check_book() {
	checked_out = !checked_out;
}

bool Book_software::Book::operator==(Book& other) {
	if (this->ISBN == other.ISBN) { return true; }
	return false;
}

bool Book_software::Book::operator!=(Book& other) {
	if (this->ISBN != other.ISBN) { return true; }
	return false;
}

ostream& operator<<(ostream& out, Book_software::Book& other) {
	out << "\nTitolo: " << other.get_title() << endl
		<< "Autore: " << other.get_author() << endl
		<< "ISBN: " << other.get_ISBN() << endl;
	return out;
}