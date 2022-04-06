//
// Created by atras on 1/20/2022.
//

#ifndef HW4_LIBRARY_H
#define HW4_LIBRARY_H
struct BookNode{
    int id;
    BookNode* biggerBook;
    BookNode* smallerBook;
    BookNode (int val){
        id = val;
        biggerBook = nullptr;
        smallerBook = nullptr;
    }
};
class Library {
private:
    BookNode* root;
public:
    Library();
    void insert(int id);
    BookNode* insert(int id, BookNode* root);
    void clear();
    BookNode* getRoot();
    int subtreeRootIdSearch(BookNode * book, int id1, int id2);
};
#endif //HW4_LIBRARY_H
