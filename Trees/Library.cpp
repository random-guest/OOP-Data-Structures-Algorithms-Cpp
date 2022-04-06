//
// Created by atras on 1/20/2022.
//
#include <iostream>
using namespace std;

#include "Library.h"
Library::Library() {
    root = nullptr;
}
BookNode* Library ::insert(int id, BookNode* root) {
    if(root == nullptr){
        root = new BookNode(id);
    }
    else if(root->id > id){
        root->smallerBook = insert(id, root->smallerBook);
    }
    else if(root->id < id){
        root->biggerBook = insert(id, root->biggerBook);
    }
    return root;
}

void Library::clear() {
    root = nullptr;
}

void Library::insert(int id) {
    root = insert(id, root);
}

BookNode* Library::getRoot(){
    return root;
}

int Library::subtreeRootIdSearch(BookNode * book, int id1, int id2){
    int big = id2 > id1 ? id2 : id1;
    int small = id2 < id1 ? id2 : id1;
    if (book->id < big && book->id > small || book->id == id2 || book->id == id1){
        return book->id;
    }
    else if (book->id > big && book->smallerBook != nullptr){
        return subtreeRootIdSearch(book->smallerBook,id1, id2);
    }
    else if (book->id < big && book->biggerBook != nullptr){
        return subtreeRootIdSearch(book->biggerBook,id1, id2);
    }
}