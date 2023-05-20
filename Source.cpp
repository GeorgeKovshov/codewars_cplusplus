#include "Header.h"

class mylist {
public:
	int value;
	mylist* next;
	mylist() {
		value = 0;
		next = nullptr;
	}
	void print() {
		cout << value << " ";
		mylist* tmp = next;
		while (tmp) {
			cout << tmp->value << " ";
			tmp = tmp->next;
		}
	}

	void add(int new_value) {
		mylist* tmp = next;
		while (tmp->next) {
			tmp = tmp->next;
		}
		mylist* new_m = new mylist;
		new_m->value = new_value;
		tmp->next = new_m;
	}
	/*
	~mylist() {
		mylist* tmp = next;
		while (tmp) {
			mylist* tmp2 = new mylist;
			tmp2 = tmp->next;
			delete tmp;
			tmp = tmp2;
		}
	}*/

	void sort() {
		mylist* x = this;
		while (x) {
			mylist* y = x->next;
			while (y) {
				if (x->value > y->value) {
					int z = x->value;
					x->value = y->value;
					y->value = z;
				}
				y = y->next;
			}
			x = x->next;
			
		}
	}

	
};


mylist* reverse_mylist(mylist* previous, mylist* current) {
	if (current != nullptr) {
		mylist* tmp = current->next;
		current->next = previous;
		reverse_mylist(current, tmp);
	}
	else {
		return previous;
	}
}


int main(void) {
	mylist m1;
	mylist m2, m3, m4, m5;
	m1.value = 1;

	m2.value = 2;
	m1.next = &m2;

	m3.value = 3;
	m2.next = &m3;

	m4.value = 4;
	m3.next = &m4;

	m5.value = 5;
	m4.next = &m5;

	m1.add(6);
	m1.add(60);

	for (int x = 0; x < 20; x++) {
		m1.add(x * x);
	}

	//m1.~mylist();
	//m1.print();
	//cout << endl;
	mylist* pm2 = reverse_mylist(nullptr, &m1);
	pm2->print();
	cout << endl;
	pm2->sort();
	pm2->print();
	//m1.sort();
	//m1.print();
	

}