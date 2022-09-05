/*
 * Name: John Ruane
 * Date Submitted: 
 * Lab Section:
 * Assignment Name: Lab 1
 */

#pragma once

#include <iostream>
#include <string>
#include "Node.h"
using namespace std;

//This class represents a linked list of node objects
//Do not modify anything in the class interface
template <class T>
class List{

 private:
  Node<T> * start; //pointer to the first node in this list
  int mySize;  //size (or length) of this list

 public:
  List();
  ~List();
  int size();
  bool empty();
  void insertStart(T);
  void insertEnd(T);
  void insertAt(T, int);
  void removeStart();
  void removeEnd();
  void removeAt(int);
  T getFirst();
  T getLast();
  T getAt(int);
  int find(T);

  //Print the name and this list's size and values to stdout
  //This function is already implemented (no need to change it)
  void print(string name){
    cout << name << ": ";
    cout << "size = " << size();
    cout << ", values = ";
    Node<T> * iterator = start;
    while(iterator != nullptr){
      cout << iterator->value << ' ';
      iterator = iterator->next;
    }
    cout << endl;
  }

}; //end of class interface (you may modify the code below)

//Implement all of the functions below
//Construct an empty list by initializig this list's instance variables
template <class T>
List<T>::List(){
  mySize = 0;
}

//Destroy all nodes in this list to prevent memory leaks
template <class T>
List<T>::~List(){
}

//Return the size of this list
template <class T>
int List<T>::size(){
  return mySize;
}

//Return true if this list is empty
//Otherwise, return false
template <class T>
bool List<T>::empty(){
  return mySize == 0 ? true:false;
}

//Create a new node with value, and insert that new node
//into this list at start
template <class T>
void List<T>::insertStart(T value){
  Node n = start;
  start.next = &n;
  start.value = value; 
  mySize++;
}

//Create a new node with value, and insert that new node
//into this list at end
template <class T>
void List<T>::insertEnd(T value){
  Node n = start;
  Node o = Node(value);

  for(int i = 0; i < mySize; i++){
    n = n.next;
  }
  n.next = &o;
  mySize++;
}

//Create a new node with value <value>, and insert that new node at position j
template <class T>
void List<T>::insertAt(T value, int j){
  Node n = start;
  Node o = Node(value);

  for(int i = 0; i < j; i++){
    n = n.next;
  }
  o.next = n.next;
  n.next = &o;
  mySize++;
}

//Remove node at start
//Make no other changes to list
template <class T>
void List<T>::removeStart(){
  Node n = &start.next;
  Node d = &start;
  start = n;
  delete &d;
  mySize--;
}

//Remove node at end
//Make no other changes to list
template <class T>
void List<T>::removeEnd(){
  Node n = start;

  for(int i = 0; i < mySize - 1; i++){
    n = n.next;
  }
  delete &n.next;
  n.next = nullptr;
  mySize--;
}

//Remove node at position j
//Make no other changes to list
template <class T>
void List<T>::removeAt(int j){
  Node n = start;
  Node o;
  Node d;

  for(int i = 0; i < j - 1; i++){
    n = n.next;
  }
  d = n.next
  o = d.next;
  n.next = &o;
  delete &d;
  mySize--;
}

//Return the value of the first node in the Linked List,
//If no first node, return the default constructed value: T()
template <class T>
T List<T>::getFirst(){
  return start;
}

//Return the value of the last node in the Linked List,
//If no first node, return the default constructed value: T()
template <class T>
T List<T>::getLast(){
  Node n = start;
  for(int i = 0; i < mySize; i++){
    n = n.next;
  }
  return n;
}

//Return the value of the node at position j in the Linked List,
//If no first node, return the default constructed value: T()
template <class T>
T List<T>::getAt(int j){
  Node n = start;
  for(int i = 0; i < j; i++){
    n = n.next;
  }
  return n;
}

//Return the position of the (first) node whose value is equal to the key
//Otherwise, return -1
template <class T>
int List<T>::find(T key){
  Node n = start;
  int count = 0;

  while(n.value != key || count == mySize - 1){
    n = n.next;
    count++;
  }
  if(count == mySize - 1)
    count = -1;
  
  return count;
}
