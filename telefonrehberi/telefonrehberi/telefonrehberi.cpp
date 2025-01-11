#include <iostream>
#include <string>
using namespace std;

//Telefon rehberi için bir düðüm(node) sýnýfý
struct Node {
	string name;
	string phone;
	Node* next;

	Node(string name, string phone) {
		this->name = name;
		this->phone = phone;
		this->next = nullptr;
	}
};
class PhoneBook {
private:
	Node* head;
public:
	PhoneBook() {
		head = nullptr;
	}

	//Kiþi ekleme fonksiyonu
	void addContact(string name, string phone) {
		Node* newNode = new Node(name, phone);

		if (head == nullptr || head->name > name) {
			newNode->next = head;
			head = newNode;
		}
		else {
			Node* tmp = head;
			while (tmp->next != nullptr && tmp->next->name < name)
			{
				tmp = tmp->next;
			}
			newNode->next = tmp->next;
			tmp->next = newNode;
		}
		cout << "Kisi eklendi: " << name << "-" << phone << endl;

	}
	//Kiþi silme fonksiyonu
	void deleteContact(string name) {
		if (head == nullptr) {
			cout << "Rehberde kisi bulunmamaktadir!" << endl;
			return;
		}
		if (head->name == name) {
			Node* temp = head;
			head = head->next,
				delete temp;
			cout << "Kisi silidi: " << name << endl;
			return;
		}
		Node* tmp = head;
		while (tmp->next != nullptr && tmp->next->name != name)
		{
			tmp = tmp->next;
		}
		if (tmp->next == nullptr) {
			cout << "Rehberde kisi bulunamadi: " << name << endl;
		}
		else {
			Node* temp = tmp->next;
			tmp->next = tmp->next->next;
			delete temp;
			cout << "Kisi silindi: " << name << endl;
		}
	}
	//Kiþi arama fonksiyonu
	void searchContact(string name) {
		Node* tmp = head;
		while (tmp != nullptr) {
			if (tmp->name == name) {
				cout << "Rehberinizdeki kisi bulundu: " << tmp->name << "-" << tmp->phone << "-" << endl;
				return;
			}
			tmp = tmp->next;
		}
		cout << "Rehberinizdeki kisi bulunamadi: " << name << endl;
	}
	//Rehberi listeleme fonksiyonu
	void displayContacts() {
		if (head == nullptr) {
			cout << "Rehber bos!" << endl;
			return;
		}
		Node* tmp = head;
		while (tmp != nullptr) {
			cout << tmp->name << "-" << tmp->phone << "-" << endl;
			tmp = tmp->next;
		}
	}
	~PhoneBook() {
		while (head != nullptr) {
			Node* temp = head;
			head = head->next;
			delete temp;
		}
	}


};
int main() {
	PhoneBook phoneBook;
	int choice;
	string name, phone;
	do {
		cout << "/n1.Kisi Ekleme/n2.Kisi Silme/n3.Kisi Arama/n4.Kisi Listeleme\n5.Cikis\nSeciminiz: " << endl;
		cin >> choice;
		cin.ignore();
		

		switch (choice) {
		case 1:
			cout << "Ýsim: ";
			getline(cin, name);
			cout << "Tel No: ";
			getline(cin, phone);
			phoneBook.addContact(name, phone);
			break;
		case 2:
			cout << "Silmek istediginiz kisinin adi: ";
			getline(cin, name);
			phoneBook.deleteContact(name);
			break;
		case 3:
			cout << "Aramak istediginiz kisinin ismi:";
			getline(cin, name);
			phoneBook.searchContact(name);
			break;
		case 4:
			phoneBook.displayContacts();
			break;
		case 5:
			cout << "Cikis" << endl;
			break;
		default:
			cout << "Gecersiz secim " << endl;
		}
	} while (choice != 5);
	return 0;
}