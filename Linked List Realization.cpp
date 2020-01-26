#include <iostream>
using namespace std;

struct node {
	int val;
	node *next;
};

class llist {
	private:
		node *head, *tail;
		
	public:
		
	llist() {
		head = NULL;
		tail = NULL;
	}
	
	void addEnd(int val) {
		node *tmp = new node;
		tmp->val = val;
		tmp->next = NULL;
		
		if(head == NULL) {
			head = tmp;
			tail = tmp;
			tmp = NULL;
		} else {
			tail->next = tmp;
			tail = tmp;
		}
	}
	
	void deleteEnd() {
		node *prev = new node;
		node *cur = new node;
		cur = head;
		
		while(cur->next != NULL) {
			prev = cur;
			cur = cur->next;
		}
		
		tail = prev;
		prev->next = NULL;
		delete cur;
	}
	
	void display() {
		node *tmp = new node;
		tmp = head;
		
		while(tmp != NULL) {
			cout << tmp->val << " ";
			tmp = tmp->next;
		}
	}
	
	void addStart(int val) {
		node *tmp = new node;
		tmp->val = val;
		tmp->next = head;
		head = tmp;
	}
	
	void deleteStart() {
		node *tmp = new node;
		tmp = head;
		head = tmp->next;
		delete tmp;
	}
	
	void addAtPos(int val, int pos) {
		node *cur = new node;
		node *prev = new node;
		node *tmp = new node;
		cur = head;
		
		for(int i = 0; i < pos; i++) {
			prev = cur;
			cur = cur->next;
		}
		
		prev->next = tmp;
		tmp->next = cur;
		tmp->val = val;
	}
	
	void deleteAtPos(int pos) {
		node *cur = new node;
		node *prev = new node;
		cur = head;
		
		for(int i = 0; i < pos; i++) {
			prev = cur;
			cur = cur->next;
		}
		
		prev->next = cur->next;
		delete cur;
	}
};

int main() {
	llist lst;
	lst.addEnd(4);
	lst.addEnd(6);
	lst.addStart(56);
	lst.addAtPos(2, 1);
	lst.deleteAtPos(2);
	lst.display();
}
