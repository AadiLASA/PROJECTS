#include <cmath>
#include <fstream>
#include <iostream>

class Airport {
public:
	char code[5];
	double longitude;
	double latitude;
};

struct node {
	Airport data;
	node *next;
};

class linked_list {
private:
	node *first, *last;

public:
	linked_list() {
		first = NULL;
		last = NULL;
	}

	void add_node(Airport n) {
		node *tmp = new node;
		tmp->data = n;
		tmp->next = NULL;

		if (first == NULL) {
			first = tmp;
			last = tmp;
		} else {
			last->next = tmp;
			last = last->next;
		}
	}
	node *getNode(int indx) {
		node *reNode = first;
		for (int i = 0; i <= indx; i++) {
			if (i == indx) {
				return reNode;
			}
			reNode = reNode->next;
		}
		return reNode;
	}

	void swap(int index1, int index2) {
		node *node1 = getNode(index1);
		node *node2 = getNode(index2);

		Airport temp;

		temp = node1->data;
		node1->data = node2->data;
		node2->data = temp;
	}
	 std::string toString() {
	 }
};

