#include <iostream>
#include <fstream>
#include <vector>

#define fast std::ios::sync_with_stdio(0); std::cin.tie(0); std::cout.tie(0);

struct Node{
    int value;
    Node* L = nullptr;
    Node* R = nullptr;
    Node* parent = nullptr;

    Node(int value, Node* par = nullptr){
        this->value = value;
        this->parent = par;
    }
};

class BinTree{
private:
    int value;
    Node* root = nullptr;

    void DFS(Node* node, std::ofstream* out){
        if(node != nullptr){
            // *out << value->value << std::endl;
            std::cout << node->value << "\n";
            Node* next_right = node->R;
            Node* next_left = node->L;
            DFS(next_left, out);
            DFS(next_right, out);
        }
    }
public:
    BinTree(int value){
        root = new Node(value);
    }

    void newChild(Node* young, Node* old){
        if(!old->parent){
            root = young;
        } else if (old->parent->L) {
            old->parent->L = young;
        } else if (old->parent->R){
            old->parent->R = young;
        }
    }

    void insert(int value){
        Node* cur = root;
        Node* next = root;

        while (next != nullptr){
            cur = next;
            if(cur->value < value) {
                next = cur->R;
            } else if (cur->value > value){
                next = cur->L;
            }

            if (cur->value == value) return;
        }

        if(next == nullptr && cur->value < value){
            cur->R = new Node(value, cur);
        } else if (next == nullptr && cur->value > value){
            cur->L = new Node(value, cur);
        }
    }

    Node* search (int value){
        Node* cur = root;
        Node* next = root;

        // if (x != nullptr) == if (x)
        // if (x == nullptr) == if (!x)

        while (next != nullptr) {
            cur = next;

            if(cur->value < value) {
                next = cur->R;

            } else if (cur->value > value){
                next = cur->L;
            }
            if (cur->value == value)
                return cur;
        }

        Node* none = nullptr;
        return none;
    }

    void removal(int v) {
        Node* cur = search(v);
        // bool isCurL = cur->L != nullptr;

        if(!cur->R && !cur->L) {
            if(cur->parent->L->value == v) {
                cur->parent->L = nullptr;
            } else {
                cur->parent->R = nullptr;
            }
            delete cur;
        } else if(cur->L && !cur->R && cur->parent == nullptr) {
            root = cur->L;
            cur->L->parent = nullptr;
        } else if(!cur->L && cur->R && cur->parent == nullptr) {
            root = cur->R;
            cur->R->parent = nullptr;
        } else if(cur->L && !cur->R && cur->parent->L->value == v ) {
            cur->parent->L = cur->L;
        } else if (!cur->L && cur->R && cur->parent->R->value == v ) {
            cur->parent->R = cur->R;
        } else if (cur->L && cur->R && cur->parent->R->value == v) {
            Node* min = finMin(cur->R);
            if(min->R) {
                min->parent->L = min->R;
                min->R = nullptr;
            }

            min->parent->R = cur->R;
            min->parent->L = cur->L;
            min->parent = cur->parent;

        } else if (cur->L && cur->R && cur->parent->L->value == v) {
//            Node* min = finMin(cur->R);
//            if (min->R) {
//                min->parent->L = min->R;
////                min->R = nullptr;
//            }
////            min = cur;
//            min->parent = cur->parent;
//
//            if(min->value != cur->R->value ){
//                min->R = cur->R;
//            }
//
//            if(min->value != cur->L->value){
//                min->L = cur->L;
//            }



        }



    }

    Node* finMin (Node* node) {
        if(node->L){
            return finMin(node->L);
        } else {
            return node;
        }
    }


    void out() {
        DFS(root, nullptr);
    }
};

int main() {
    fast
    std::ifstream file;
    file.open("input.txt");
    int num = 0;
    std::vector<int> numbers;
    int victim;
    file >> victim;

    while (file >> num){
        numbers.push_back(num);
    }


    BinTree tree(numbers[0]);

    for (int i = 1; i < numbers.size(); ++i) {
        tree.insert(numbers[i]);
    }

    tree.removal(victim);

    tree.out();
//    std::cout << "Hello, World!" << std::endl;
    file.close();

    return 0;
}
