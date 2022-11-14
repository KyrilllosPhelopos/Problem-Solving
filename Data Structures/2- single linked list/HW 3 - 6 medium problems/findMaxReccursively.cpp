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
        {
            cout<<"@ address: "<<cur<<"  data =   ";
            cout << cur->data << " ";
            cout << "\n";

        }
			
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


	Node* get_nth(int n) {
		int cnt = 0;
		for (Node* cur = head; cur; cur = cur->next)
			if (++cnt == n)
				return cur;

		return nullptr;	// still more steps needed - NOT found
	}

    	//////////////////////////////New Functions/////////////////////////////////

    Node* get_nth_back(int n)
    {
        int cnt = 0;
		for (Node* cur = head; cur; cur = cur->next , cnt++)
			if ((length - cnt) == n)
				return cur;
		
		return nullptr;	// still more steps needed - NOT found

    }

    	//////////////////////////////New Functions/////////////////////////////////

    bool is_same(LinkedList * list2)
    {
        if(this->length != list2->length)
        return 0;

        Node* list1_head = this->head;
        Node* list2_head = list2->head;

        while(list1_head)
        {
            if(list1_head->data != list2_head->data)
            return 0;

            list1_head = list1_head->next;
            list2_head = list2_head->next;
        }
        return 1;
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
    void delete_node_with_key(int n)
    {
        Node* toBeDelted ;
        if(n > length)
        return ;

        if(n ==1)
        {
            toBeDelted = head;
            head = head->next;
            delete toBeDelted;
            return ;
        }
        else
        {
            Node* cur = head; 
            Node* pre;
            for (int i = 1; i<= length ;i++)
            {
                if(i == n && n!=length)
                {
                    pre->next = cur->next;
                    delete cur;
                    return ;
                }
                pre = cur;
                cur = cur->next;
            }
            if(n == length)
            {
                tail = pre;
                delete tail; 
            }

        }


    }
    //////////////////////////////Swap Pairs/////////////////////////////////
    void swap_pairs()
    {
        if(!head || !head->next)
        return ;

        Node* cur = head;
        int temp;
        while (cur && cur->next)
        {
            temp = cur->data;
            cur->data = cur->next->data;
            cur->next->data = temp;

            cur = cur->next->next;
        }
    }
	//////////////////////////////void swap head & tail/////////////////////////////////
    void swap_head_tail()
    {
        Node* cur = head;
        while(cur)
        {
            if(cur->next == tail)
            break;

            cur = cur->next;
        }
        if(cur == nullptr)
        return ;

        tail->next = head->next;
        cur->next = head;
        head->next = nullptr;
        //store the value of the head in cur pointer
        cur = head;
        head = tail;
        tail = cur;
        return;
    }

	//////////////////////////////get max reccursevily/////////////////////////////////
    int max(Node* head = nullptr , bool is_first_call = true)
    {
        if(is_first_call)
        return this->max(this->head , false);

        if(head == nullptr)
        return INT_MIN;

        return std::max(head->data , this->max(head->next , false));
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


cout << "************************************\n\n";
    cout<<"max value in the list is: "<<list.max()<<endl;
	list.insert_end(1);
	list.insert_end(2);
	list.insert_end(3);
    cout << "************************************\n\n";
    cout<<"max value in the list is: "<<list.max()<<endl;
	list.insert_end(4);
    list.insert_end(20);
	list.insert_end(5);
    list.insert_end(30);
    list.insert_end(10);
    list.insert_end(15);
	
  // list.print();
   cout << "************************************\n\n";
    cout<<"max value in the list is: "<<list.max()<<endl;





	return 0;
}

