#include <iostream>
using namespace std;

struct ListNode {
    int val;
    ListNode *next;
};
ListNode* crearNodo(int val){
    ListNode* nuevo = new ListNode();
    nuevo->val = val;
    nuevo->next = nullptr;
    return nuevo;
}

void push_front(ListNode* &head, int val){
    ListNode*nuevo= crearNodo(val);
    nuevo->next = head;
    head = nuevo;
}
void display(ListNode* head){
    ListNode* aux = head;
    while(aux!= nullptr){
        cout << aux->val << " ";
        aux = aux->next;
    }
    cout << endl;
}

void push_back(ListNode* &head, int val){
    ListNode* nuevo = crearNodo(val);
    if(head == nullptr){
        head = nuevo;
    }else{
        ListNode* temp = head;
        while(temp->next != nullptr){
            temp = temp->next;
        }
        temp->next = nuevo;
    }
}

void pop_front(ListNode* &head){
    if(head == nullptr){
        return;
    }
    ListNode* temp = head;
    head = head->next;
    delete temp;
}

void pop_back(ListNode* &head){
    if(head == nullptr){
        return;
    }
    if(head->next == nullptr){
        delete head;
        head = nullptr;
        return;
    }
    ListNode* temp = head;
    while(temp->next->next != nullptr){
        temp = temp->next;
    }
    delete temp->next;
    temp->next = nullptr;
}

//T operator[ ](int); // Retorna el elemento en la posición indicada

bool empty(ListNode* head){
    return head == nullptr;
}

int size(ListNode* head){
    int cont = 0;
    ListNode* temp = head;
    while(temp != nullptr){
        cont++;
        temp = temp->next;
    }
    return cont;
}

void clear(ListNode* &head){
    while(head != nullptr){
        pop_front(head);
    }
}

void sort(ListNode* head){
    ListNode* temp = head;
    while(temp != nullptr){
        ListNode* temp2 = temp->next;
        while(temp2 != nullptr){
            if(temp->val > temp2->val){
                swap(temp->val, temp2->val);
            }
            temp2 = temp2->next;
        }
        temp = temp->next;
    }
}

void reverse(ListNode* &head){
    ListNode* prev = nullptr;
    ListNode* current = head;
    ListNode* next = nullptr;
    while(current != nullptr){
        next = current->next;
        current->next = prev;
        prev = current;
        current = next;
    }
    head = prev;
}

//Mezclar dos listas ordenadas en una nueva lista también ordenada O(n)
ListNode* merge(ListNode* head1, ListNode* head2){
    ListNode* head = nullptr;
    while(head1 != nullptr && head2 != nullptr){
        if(head1->val < head2->val){
            push_back(head, head1->val);
            head1 = head1->next;
        }else{
            push_back(head, head2->val);
            head2 = head2->next;
        }
    }
    while(head1 != nullptr){
        push_back(head, head1->val);
        head1 = head1->next;
    }
    while(head2 != nullptr){
        push_back(head, head2->val);
        head2 = head2->next;
    }
    return head;
}


//Hallar la intersección de dos listas ordenadas en tiempo O(n).
ListNode* intersection(ListNode* head1, ListNode* head2){
    ListNode* head = nullptr;
    while(head1 != nullptr && head2 != nullptr){
        if(head1->val == head2->val){
            push_back(head, head1->val);
            head1 = head1->next;
            head2 = head2->next;
        }else if(head1->val < head2->val){
            head1 = head1->next;
        }else{
            head2 = head2->next;
        }
    }
    return head;
}

//Implementar el algoritmo de Insertion Sort con listas enlazadas O(n^2).

void insertionSort(ListNode* head){
    ListNode* temp = head;
    while(temp != nullptr){
        ListNode* temp2 = temp->next;
        while(temp2 != nullptr){
            if(temp->val > temp2->val){
                swap(temp->val, temp2->val);
            }
            temp2 = temp2->next;
        }
        temp = temp->next;
    }
}

int main() {
    ListNode* head = nullptr;

    // Agregar elementos al principio
    push_front(head, 10);
    push_front(head, 12);
    push_front(head, 6);
    push_front(head, 4);

    // Agregar un elemento al final
    push_back(head, 12);

    cout << "Lista inicial: ";
    display(head);

    // Eliminar el primer elemento
    pop_front(head);
    cout << "Lista después de eliminar el primer elemento: ";
    display(head);

    // Eliminar el último elemento
    pop_back(head);
    cout << "Lista después de eliminar el último elemento: ";
    display(head);

    // Verificar si la lista está vacía
    cout << "¿La lista está vacía? " << (empty(head) ? "Sí" : "No") << endl;

    // Calcular el tamaño de la lista
    cout << "Tamaño de la lista: " << size(head) << endl;

    // Ordenar la lista
    sort(head);
    cout << "Lista ordenada: ";
    display(head);

    // Invertir la lista
    reverse(head);
    cout << "Lista invertida: ";
    display(head);

    // Crear una nueva lista
    ListNode* head2 = nullptr;
    push_back(head2, 5);
    push_back(head2, 7);
    push_back(head2, 12);
    cout << "Segunda lista: ";
    display(head2);

    // Fusionar dos listas ordenadas
    ListNode* merged = merge(head, head2);
    cout << "Lista fusionada: ";
    display(merged);

    // Encontrar la intersección de dos listas ordenadas
    ListNode* intersectionList = intersection(head, head2);
    cout << "Intersección de las dos listas: ";
    display(intersectionList);

    // Ordenar una lista usando Insertion Sort
    insertionSort(head);
    cout << "Lista ordenada usando Insertion Sort: ";
    display(head);

    // Limpiar la lista
    clear(head);
    cout << "Lista después de limpiar: ";
    display(head);

    return 0;
}
