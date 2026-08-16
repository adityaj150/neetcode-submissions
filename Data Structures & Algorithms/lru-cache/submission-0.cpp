#include <unordered_map>
#include <list>

using namespace std;

class Node {
public: 
	int key;
	int value;
	Node* prev;
	Node* next;

	Node(int key, int value) : key(key), value(value), prev(nullptr), next(nullptr) {}
};

class LRUCache {
private:
	int capacity;
	unordered_map<int, Node*> cache;
	Node* head;
	Node* tail;

	void moveToFront(Node* node) {
		if (node == nullptr) {
			return;
		}
		removeNode(node);
		insertAtFront(node);
	}

	void removeNode(Node* node) {
        if (node == nullptr) {
            return;
        }
        if (node == head) {
            node->next->prev = nullptr;
            head = node->next;
        }
        else if (node == tail) {
            tail = node->prev;
            node->prev->next = nullptr;
        }
        else {
            node->prev->next = node->next;
            node->next->prev = node->prev;
        }
	}

	void insertAtFront(Node* node) {
		node->next = head->next;
		node->prev = head;
		head->next->prev = node;
		head->next = node;
	}
    
public:
	LRUCache(int capacity) : capacity(capacity) {
		head = new Node(-1, -1);
		tail = new Node(-1, -1);
		head->next = tail;
		tail->prev = head;
	}

	int get(int key) {
		if (cache.find(key) != cache.end()) {
			Node* node = cache[key];

			moveToFront(node);
			return node->value;
		}
		return -1;
	}

	void put(int key, int value) {
		if (cache.find(key) != cache.end()) {
			Node* node = cache[key];
			node->value = value;
			moveToFront(node);
		}
		else {
			if (cache.size() >= capacity) {
				Node* lru = tail->prev;
				removeNode(lru);
				cache.erase(lru->key);
				delete lru;
			}
			Node* newNode = new Node(key, value);
			insertAtFront(newNode);
			cache[key] = newNode;
		}
	}

	~LRUCache() {
		Node* node = head;
		while (node != nullptr) {
			Node* nextNode = node->next;
			delete node;
			node = nextNode;
		}
	}

};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */