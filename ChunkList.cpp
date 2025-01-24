//
// Your code here
//

#include "ChunkList.h"


template<class T>
ChunkList<T>::ChunkList() {
    head = nullptr;
    tail = nullptr;
    iterNode = nullptr;
    arrPos = 0;
    listLen = 0;
    numChunks = 0;

}

template<class T>
ChunkList<T>::ChunkList(T *arr, int arrLen) {
    head = nullptr;
    tail = nullptr;
    listLen = 0;
    numChunks = 0;

    if (arrLen < 0) {
        throw InvalidArrayLength();
    }
    for (int i = 0; i < arrLen; i++){
        Append(arr[i]);
    }
    ResetIterator();
}


template<class T>
ChunkList<T>::~ChunkList() {
    Node* temp = head;
    while (temp != nullptr){
        Node* del = temp;
        temp = temp -> next;
        delete del;
    }
    listLen = 0;
    numChunks = 0;
}



template<class T>
void ChunkList<T>::Append(T value) {
    if (IsEmpty()) {
        Node *currN = new Node;
        currN->next = nullptr;
        currN->len = 0;
        currN->values[currN->len] = value;
        if (listLen == 0) {
            head = tail = currN;
        } else {
            tail = currN;
            head->next = tail;
        }
        head->len = 1;
        listLen++;
        numChunks++;
        return;
    } else if (tail != nullptr && tail-> len < 8){
        tail -> values[tail -> len] = value;
        tail -> len++;
        listLen++;
        return;
    } else {
        Node *tnode = new Node;
        tnode -> next = nullptr;
        tnode -> len = 0;
        tnode -> values[tnode -> len] = value;
        tnode -> len = 1;
        tail -> next = tnode;
        tail = tnode;
        listLen++;
        numChunks++;
        return;
    }

}


template<class T>
void ChunkList<T>::Remove(T value) {
    if (IsEmpty()){
        throw EmptyList();
    }

    Node *currN = head;
    Node *prevN = nullptr;
    while (currN != nullptr) {
        for (int i = 0; i < currN->len; i++) {
            if (currN->values[i] == value) {
                if (currN->len == 1) {
                    if (currN == head) {
                        head = currN->next;
                        numChunks--;
                        delete currN;
                        listLen--;
                        return;
                    }
                    if (currN == tail) {
                        tail = prevN;
                        numChunks--;
                        delete currN;
                        listLen--;
                        return;
                    }
                    else {
                        prevN->next = currN->next;
                        numChunks--;
                        delete currN;
                        listLen--;
                        return;
                    }

                } else {
                    for (int j = i; j < currN-> len - 1; j++) {
                        currN->values[j] = currN->values[j + 1];
                    }
                    listLen--;
                    currN->len--;
                    return;
                }
            }
        }

        prevN = currN;
        currN = currN->next;
    }
}


template<class T>
int ChunkList<T>::GetLength() {
    return listLen;
}


template<class T>
double ChunkList<T>::LoadFactor() {
    if (IsEmpty()){
        throw EmptyList();
    }
    double load = static_cast<double>(listLen) / (ARRAY_SIZE * numChunks);
    return static_cast<double>(load);
}


template<class T>
bool ChunkList<T>::Contains(T value) {
    if (IsEmpty()){
        throw EmptyList();
    }
    Node *CNode = head;
    while (CNode != nullptr){
        for (int i = 0; i < CNode -> len; i++) {
            if (CNode -> values[i] == value) {
                return true;
            }
        }
        CNode = CNode -> next;
    }
    return false;
}


template<class T>
T ChunkList<T>::GetIndex(int i) {
    if (IsEmpty()){
        throw EmptyList();
    }
    if (arrPos < 0|| i < 0 || i >= listLen) {
        throw IndexOutOfBounds();
    }
    Node *INode = new Node;
    while (INode != nullptr) {
        if (i < INode -> len) {
            return INode -> values[i];
        }
        i = i - INode -> len;
        INode -> next = INode;
    }
    return INode -> values[i];
}


template<class T>
void ChunkList<T>::ResetIterator() {
    iterNode = head;
    arrPos = 0;
}


template<class T>
T ChunkList<T>::GetNextItem() {
    if (IsEmpty()){
        throw EmptyList();
    }
    if (iterNode == nullptr) {
        throw IteratorOutOfBounds();
    }

    if (arrPos >= iterNode->len) {
        if (iterNode -> next == nullptr) {
            throw IteratorOutOfBounds();
        }
        iterNode = iterNode -> next;
        arrPos = 0;
    }

    T currentItem = iterNode -> values[arrPos];
    arrPos++;
    return currentItem;

}

template<class T>
bool ChunkList<T>::IsEmpty() {
    if (head == nullptr) {
        return true;
    }
    return false;
}
