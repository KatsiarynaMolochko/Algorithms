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
            *out << node->value << "\n";
//            std::cout << node->value << "\n";
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



    Node* DeleteRec(Node* node, int value) {
        if (!node) { return nullptr; } //если одна вершина в дереве

        if (value < node->value) {     // если удаляемая вершина меньше той, в которой мы находимся
            node->L = DeleteRec(node->L, value);
            return node;
        } else if (value > node->value) {  //если удаляемая вершина, больше той, в которой мы находимся
            node->R = DeleteRec(node->R, value);
            return node;
        }


        if (!node->L && !node->R) {
            return nullptr;
        }
        else if (!node->L) {  // если одно правое поддерево
//            node->value = node->R->value;
//            node->R = node->R->R;
//            node->L = node->R->L;

            return node;
        } else if (!node->R) {  //если одно левое поддерево
//            node->value = node->L->value;
//            node->R = node->L->R;
//            node->L = node->L->L;
            return node;
        } else {  //если два поддерева
            Node* min = finMin(node->R);
            node->value = min->value;
            node->R = DeleteRec(node->R,min->value);
            return node;
        }
    }

    Node* finMin (Node* node) {
        if(node->L){
            return finMin(node->L);
        } else {
            return node;
        }
    }

    Node* getRoot() {
        return this->root;
    }

    void PreOrderTraversal(std::ofstream* out) {
        DFS(this->root, out);
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
    int victim = 0;
    file >> victim;

    while (file >> num){
        numbers.push_back(num);
    }


    BinTree tree(numbers[0]);

    for (int i = 1; i < numbers.size(); ++i) {
        tree.insert(numbers[i]);
    }

    Node* root = tree.getRoot();

    root = tree.DeleteRec(root, victim);

//    tree.DeleteRec(root,victim);
    std::ofstream out("output.txt");
    tree.PreOrderTraversal(&out);

    out.close();


//    std::cout << "Hello, World!" << std::endl;
    file.close();

    return 0;
}