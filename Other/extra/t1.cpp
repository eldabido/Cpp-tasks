#include <iostream>

struct Node {
    int data;
    Node* next;
};

class List {
public:
  Node* elem;

    List() {
        elem = nullptr;
    }

    void Append(int num) {
        Node* node_of_elem = new Node;
        node_of_elem->data = num;
        node_of_elem->next = nullptr;
        if (elem == nullptr) {
            elem = node_of_elem;
        } else {
            Node* tmp = elem;
            while (tmp->next != nullptr) {
                tmp = tmp->next;
            }
            tmp->next = node_of_elem;
        }
    }

    void Output() {
        Node* tmp = elem;
        while (tmp != nullptr) {
            std::cout << tmp->data << " ";
            tmp = tmp->next;
        }
        std::cout << "\n";
    }
    
    void Remove(int num) {
        Node* current = elem;
        Node* previous = nullptr;
        while (current != nullptr) {
            if (current->data == num) {
                if (previous == nullptr) {
                    elem = current->next;
                } else {
                    previous->next = current->next;
                }
                delete current;
                return;
            }
            previous = current;
            current = current->next;
        }
    }
    
    void Reverse() {
        Node* previous = nullptr;
        Node* current =elem;
        Node* next = nullptr;
        while (current != nullptr) {
            next = current->next;
            current->next = previous;
            previous = current;
            current = next;
        }
        elem = previous;
    }
    
    void Clear() {
        Node* current = elem;
        Node* next;
    
        while (current != nullptr) {
            next = current->next;
            delete current;
            current = next;
        }
        elem = nullptr;
    }
};

int main() {
  std::cout << "Введите кол-во элементов: ";
  int n;
  std::cin >> n;
  List list = List();
  int elem;
  for (int i = 0; i < n; ++i) {
    std::cin >> elem;
    list.Append(elem);
  }
  list.Output();
  std::cout << "Вот список, введите элемент, который хотите удалить: ";
  std::cin >> elem;
  list.Remove(elem);
  list.Reverse();
  list.Output();
  list.Clear();
}