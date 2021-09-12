
#include <stdlib.h>

template <class Type> 
struct Node
{
	Type item;
	
	// must be a pointer to the next node not an actual node, Node*
	Node<Type>* next = NULL;
	Node<Type>* prev = NULL;


};

template <class Type>
class DoubleLinkedList {
	// list members
	Node<Type>* first = NULL;
	Node<Type>* end = NULL;
	int count = 0;

	public:
	// list functions
	void Append(Type item) {
	
	// things inside the function definition only last as long at the function all
	// use node pointer , new produces pointers, new Node() reference to newly alocated node 
	
		Node* node = new Node();

		//(*node).item = item: node->item = item;
		// node has an item field, within the space of node there is space for the memebers of node/ subsets
		node->item = item;

		if (first == NULL) {
		
			first = node;

		} else {
			end->next = node;
		}

		node->prev = end;
		end = node;
		node->next = NULL;
		count++;
	}
	
	std::String toString(Type item) {
		std::stringstream<char> ss;
		for (Node* node = first;  node != NULL; node = node->next) {
			// assuming primitives
			ss << node->item << " ";
		}
		return ss.str();

	}

	void Remove(int index) {
		if (index >= 0 && index <= count ) {
			Node* node = first;
			for (int i = 0; i < index ; i++) {
				node = node->next;
			}
			if (node->prev != NULL) {
				node->prev->next = node->next;
				
			} else {
				first = node->next;
			}

			if (node->next != NULL) {
	
				node->next->prev = node->prev;

			} else {
				 end = node->prev;
			}
			delete node;
			count--;			
		}
	}
	/* check with seth
	*  check if index is 0, check if index is the end, check index in middle
	*  check if list is empty
	*/
	void Insert(Type item, int Index) {
		
		Node* inserted = new Node();
		
		if (index >= 0  && index  <= count) {
			// Normal case
		
			Node* preIndex;
			Node* postIndex;

			// edge case:
			if (index == 0) {
				preIndex = NULL;
				postIndex = first;
			} else {
				preIndex = first;
				// start iteration from the first note
				for (int i = 0; i < index-1; i++) {
					preIndex = preIndex->next;
				}
				// if first node is not null then the list isn't empty
				postIndex = preIndex->next;
			}

			inserted->prev = preIndex;
			inserted->next = postIndex;

			if ( preIndex != NULL) {
				preIndex->next = inserted;
			} else {
				first = inserted;
			}
			
			// edge case: post index can be null or not
			if (postIndex != NULL) {
				postIndex->prev = inserted;// deal with problem close to edge case
			}else { 
				end = inserted;
			}

			count++;
		}
	}

};

int main() {
	DoubleLinkedList<int> list;
	return 50;


}