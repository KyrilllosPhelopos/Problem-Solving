#include <iostream>
#include <cassert>
using namespace std;

struct Node {
	int data { };
	Node* next { };
	Node(int data) :
			data(data) {
	}
};

class LinkedList {
private:
	Node *head { };
	Node *tail { };
	int length = 0;		// let's maintain how many nodes

public:

	void print() {
		// DON'T change head itself
		for (Node* cur = head; cur; cur = cur->next)
			cout << cur->data << " ";
		cout << "\n";
	}

	void insert_end(int value) {
		Node* item = new Node(value);

		if (!head)
			head = tail = item;
		else {
			tail->next = item;
			tail = item;
		}
		++length;
	}
	//////////////////////////////New Functions/////////////////////////////////

    void insert_front(int value){

        Node* item = new Node(value);

        if(!head)
        head = tail = item ;

        else 
        {
            item->next = head;
            head = item; 
        }

        ++length;

    }

	//////////////////////////////New Functions/////////////////////////////////

    void delete_front()
    {
        if (!head )
        return ;
        else 
        {
            Node* ToBeDeleted = head;
            head = head->next;
            delete ToBeDeleted;
        }
    }

	Node* get_nth(int n) {
		int cnt = 0;
		for (Node* cur = head; cur; cur = cur->next)
			if (++cnt == n)
				return cur;

		return nullptr;	// still more steps needed - NOT found
	}

	int search(int value) {
		int idx = 0;
		for (Node* cur = head; cur; cur = cur->next, idx++)
			if (cur->data == value) // Common Mistake to use head
				return idx;
		return -1;
	}

	int search_improved(int value) {
		int idx = 0;
		Node *prv = nullptr;	// let's keep pointer of prv
		for (Node* cur = head; cur; cur = cur->next, idx++) {
			if (cur->data == value) {
				if (!prv)
					return idx;
				swap(prv->data, cur->data);
				return idx - 1;
			}
			prv = cur;
		}
		return -1;
	}

	int search_improved_v2(int value) {
		int idx = 0;

		for (Node *cur = head, *prv = nullptr; cur; prv = cur, cur = cur->next) {
			if (cur->data == value) {
				if (!prv)
					return idx;
				swap(prv->data, cur->data);
				return idx - 1;
			}
			++idx;
		}
		return -1;
	}

	//////////////////////////////New Functions/////////////////////////////////

    ~LinkedList()
    {
        Node* cur = this->head ;
        Node* next = cur->next;

        while(cur)
        {
            delete cur;
            cur = next;
            next = next->next;
        }
        cout<<"all the created nodes are freed \n";


    }

};


void test(LinkedList &list) {
	list.print();

	Node* res = list.get_nth(2);

	if (res == nullptr)
		cout << "nth = none\n";
	else
		cout << "nth: " << res->data << "\n";

	cout << list.search(15) << "\n";
	cout << list.search_improved(15) << "\n";

	list.print();
	cout << "************************\n";
}

int main() {

	LinkedList list;


	list.insert_end(6);
	list.insert_end(10);
	list.insert_end(8);
	list.insert_end(15);

    list.insert_front(7);
    list.insert_front(5);
    list.insert_front(1);

    cout<<"before deleteing 2 elements from the front \n";
	list.print();
    cout<<"***************************************\n";
    list.delete_front();
    list.delete_front();

    cout<<"after deleteing 2 elements from the front \n";

    list.print();
    cout<<"***************************************\n";


	return 0;
}

