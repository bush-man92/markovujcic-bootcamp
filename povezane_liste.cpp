#include <iomanip>
#include <iostream>

using namespace std;

struct Node{
	int value;
	Node *next;
};

void pretrazivanje_liste(Node *&head);
int element_counter(Node *&head);

void insertElementFront(Node *&head, int value) {
	Node *temp = new Node;
	temp -> value = value;
	temp -> next = head;
	head = temp;
}

void deleteHead(Node *&head) {
	Node *temp = head;
	if (temp != 0) {
		head = temp -> next;
		delete temp;
	}
}

void deleting(Node *&head, int pretraga) {
	Node *temp = head;
	int counter = 0;
	if (temp != 0) {
		head = temp -> next;
		counter += 1;
		if (counter == pretraga) {
			head -> next -> next;
			delete temp;
		}
	}
	pretrazivanje_liste(head);
}

void pretrazivanje_liste(Node *&head) {
	int pretraga;
	cin >> pretraga;
	int counter;
	Node *current = head;
	for (int i = 0; i < 1;) {
		if (counter == pretraga) {
			cout << current -> value;
		}
		if (current != 0) {
			current = current -> next;
			counter += 1;
		}
		else {
			break;
		}
	}
	cout << endl;
	cout << "Deleting?" << endl;
	char upit;
	cin >> upit;
	if (upit == 'y') {
		deleting(head, pretraga);
	}
	else {
		cout << element_counter(head);
	}
}

int element_counter(Node *&head) {
	int counter = 0;
	Node *current = head;
	for (int i = 0; i < 1;) {
		if (current != 0) {
			current = current -> next;
			counter += 1;
		}
		else {
			break;
		}
	}
	return(counter);
}

int main() {
	Node *head = NULL;
	Node *tail = NULL;
	
	insertElementFront(head, 1);
	insertElementFront(head, 2);
	insertElementFront(head, 3);
	insertElementFront(head, 4);
	
	cout << element_counter(head) << endl;
	pretrazivanje_liste(head);
	deleteHead(head);
}
