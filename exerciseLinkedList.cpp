#include <iostream>
#include <string>
using namespace std;
class Node {
public:
	int rollNumber;
	string name;
	Node* next;
};
class CircularLinkedList {
private:
	Node* LAST;
public:
	CircularLinkedList() {
		LAST = NULL;
	}
	void addNode();
	bool search(int rollno, Node** previous, Node** current);
	bool listEmpty();
	bool delNode();
	void traverse();
};
void CircularLinkedList::addNode() { 
	//method baru yg akan disi oleh newNode.
	int rollnumber;
	string nm;
	//
	cout << "Masukkan roll number : ";
	cin >> rollnumber;
	cout << "Masukkan nama : ";
	cin >> nm;

	Node* newNode = newNode;
	newNode->rollNumber = rollnumber;
	newNode->name = nm;
	//input output newNode
	
	if (LAST = NULL) {
		LAST = newNode;
		LAST->next = newNode;
	}
	else {
		newNode->next = LAST->next;
		LAST->next = newNode;
		LAST = newNode;
	}
	cout << "Node berhasil ditambahkan!!" << endl;
}
bool CircularLinkedList::search(int rollno, Node** previous, Node** F) {
	*previous = LAST->next;
	*F = LAST->next;
	while (*F != LAST) {
		if (rollno == (*F)->rollNumber) {
			return true;
		}
		*previous = *F;
		*F = (*F)->next;
	}
	if (rollno == LAST->rollNumber) {
		return true;
	}
	else {
		return false;
	}
}
bool CircularLinkedList::listEmpty() {
	return LAST == NULL;
}
bool CircularLinkedList::delNode() { 
	if (listEmpty()) {
		cout << "Node tidak ada!" << endl;
		return false;
	}
	int rollNo;
	cout << "Masukkan roll number yang ingin di hapus : ";
	cin >> rollNo;

	Node* previous = NULL;
	Node* F = NULL;
	if (!search(rollNo, &previous, &F)) {
		cout << "Record not found" << endl;
		return false;
	}

	if (F == LAST && F->next == LAST) {
		delete F;
		LAST = NULL;
	}
	else if (F == LAST) {
		previous->next = LAST->next;
		delete LAST;
		LAST = previous;
	}
	else {
		previous->next = F->next;
		delete F;
	}

	cout << "Record deleted successfully!" << endl;
	return true;
	cout << "Berhasil di hapus" << endl;
	return true;

}
void CircularLinkedList::traverse() {
	if (listEmpty()) {
		cout << "\nList is empty\n";
	}
	else {
		cout << "\nRecords in the list are:\n";
		Node* FNode = LAST->next;
		while (FNode != LAST) {
			cout << FNode->rollNumber << " " << FNode->name << endl;
			FNode = FNode->next;
		}
		cout << LAST->rollNumber << " " << LAST->name << endl;
	}
}
int main() {
	CircularLinkedList obj;
	while (true) {
		try {
			cout << "\nMenu" << endl;
			cout << "1. Add a record to the list" << endl;
			cout << "2. Delete a record from the list" << endl;
			cout << "3. View all the records in the list" << endl;
			cout << "4. Exit" << endl;
			cout << "\nEnter your choice (1-5): ";
			char ch;
			cin >> ch;
			switch (ch) {
			case '1': {
				obj.addNode();
			}
			case '2': {
				obj.delNode();
			}
			case '3': {
				obj.traverse();
				break;
			}
			case '4': {
				return 0;
			}
			default: {
				cout << "Invalid option" << endl;
				break;
			}
			}
		}
		catch (exception& e) {
			cout << e.what() << endl;
		}
	}
	return 0;
}