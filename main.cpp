#include <iostream>
#include <fstream>
#include <vector>

#define fast std::ios::sync_with_stdio(0); std::cin.tie(0); std::cout.tie(0);

struct Node{
    int value;
    Node* L = nullptr;
    Node* R = nullptr;
    int h;
    int children = 0;

    Node(int value, Node* par = nullptr){
        this->value = value;
    }
};

class BinTree{
private:
    int value;
    int counter = 0;
    Node* root = nullptr;

    void DFS(Node* node, std::ofstream* out){
        if(node != nullptr){
            *out << node->value << "\n";
            Node* next_right = node->R;
            Node* next_left = node->L;
            DFS(next_left, out);
            DFS(next_right, out);
        }
    }

    Node*& search(Node*& node, int value) {
        if (!node) return node;
        if (node->value == value) return node;
        else return search(node->value > value ? node->L : node->R, value);
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

    Node*& search(int value) {
        return search(root, value);
    }

    void Delete (int value) {
        Node*& del = (search(value));
        if(!del) return;
        if(!del->R && !del->L) {
            del = nullptr;
        } else if(!del->L && del->R)  {
            del = del->R;
        } else if(!del->R && del->L) {
            del = del->L;
        } else {
            Node* min_max_left = del->R;
            Node* prev = del;

            if (!min_max_left->L) {
                prev->R = min_max_left->R;
                prev->value = min_max_left->value;
            } else {
                while (min_max_left->L) {
                    prev = min_max_left;
                    min_max_left = min_max_left->L;
                }

                del->value = min_max_left->value;
                prev->L = min_max_left->R;
            }
        }
    }

    int height(Node* node) {
        if(node == nullptr) {
            return 0;
        }
        if(node->L != nullptr) {
            node->L->h = height(node->L);
        }

        if(node->R != nullptr) {
            node->R->h = height(node->R);
        }

        int max = -1;
        if (node->R && node->L) {
            max = std::max(node->L->h, node->R->h);
        } else if(node->R && !node->L) {
            max = node->R->h;
        } else if(node->L && !node->R) {
            max = node->L->h;
        }
//        int maximal = node->L->h > node->R->h ? node->L->h : node->R->h;

        return max + 1;
    }

    int children (Node* node) {
        int left_children = 0;
        int right_children = 0;

        if (!node->L && !node->R) {
            return 1;
        }

        if(node->L) {
            left_children = children(node->L);
            node->children += left_children;
        } else {
            left_children = 0;
        }

        if(node->R) {
            right_children = children(node->R);
            node->children += right_children;
        } else {
            right_children = 0;
        }

        return left_children + right_children + 1;
    }

    Node*& finMin (Node*& node) {
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

    void inLeft(Node* node) {

        if(node != nullptr){
            Node* next_right = node->R;
            Node* next_left = node->L;
            inLeft(next_left);
            if(next_left && next_right && node->L->children != node->R->children && node->L->h == node->R->h) {
                counter++;
            }
//            *out << node->value << "\n";
            inLeft(next_right);

        }
    }

    void inLeft_counter(Node* node, int half_count) {
        if(node != nullptr){
            Node* next_right = node->R;
            Node* next_left = node->L;
            inLeft_counter(next_left, half_count);

            if(next_left && next_right &&
             node->L->children != node->R->children &&
             node->L->h == node->R->h) {
                counter++;
                if (counter == half_count) {
                    Delete(node->value);
                }
            }
            inLeft_counter(next_right, half_count);
        }


    }

    int count(Node* node) {
        inLeft(node);
        int half_count = counter/2 + 1;
        if (counter % 2){
            counter = 0;
            inLeft_counter(node, half_count);
        }
    }

    void main_function(std::ofstream* out) {
        count(this->root);
        PreOrderTraversal(out);
    }

    void inOrderTraversal() {
        inLeft(this->root);
    }

};

int main() {
    fast
    std::ifstream file;
    file.open("in.txt");
    int num = 0;
    std::vector<int> numbers;
    int victim = 0;
//    file >> victim;

    while (file >> num) {
        numbers.push_back(num);
    }


    BinTree tree(numbers[0]);

    for (int i = 1; i < numbers.size(); ++i) {
        tree.insert(numbers[i]);
    }

    Node* root = tree.getRoot();

//    tree.Delete(victim);

//    root = tree.DeleteRec(root, victim);

//    tree.DeleteRec(root,victim);
    std::ofstream out("out.txt");
    tree.children(root);
    root->h = tree.height(root);
    tree.main_function(&out);
//    tree.inOrderTraversal();


//    tree.PreOrderTraversal(&out);


    out.close();

    file.close();

    return 0;
}