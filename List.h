/*
 * Name: John Ruane
 * Date Submitted: 
 * Lab Section: 001
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
  start = nullptr;
}

//Destroy all nodes in this list to prevent memory leaks
template <class T>
List<T>::~List(){
  //make dummy nodes
  Node<T> * n = start->next;
  Node<T> * d = start;

  //for loop that delets all the used nodes
  for(int i = 0; i < mySize - 1; i++){
    delete d; 
    d = n;
    n = n->next;
  }

  //sets size to 0
  mySize = 0;
}

//Return the size of this list
template <class T>
int List<T>::size(){
  //returns size
  return mySize;
}

//Return true if this list is empty
//Otherwise, return false
template <class T>
bool List<T>::empty(){
  //checks if size is 0, if it is true is returned
  return mySize == 0 ? true:false;
}

//Create a new node with value, and insert that new node
//into this list at start
template <class T>
void List<T>::insertStart(T value){
  Node<T> *s = new Node(value);
  if(start == nullptr){
    start = s;
  } else {
    s->next = start;
    start = s;
  }
  mySize++;
}

//Create a new node with value, and insert that new node
//into this list at end
template <class T>
void List<T>::insertEnd(T value){
  Node<T> *n = start;
  Node<T> *o = new Node(value);
  //if size is not zero iterate through nodes until you get to the last one then set new node to the next of last
  if(mySize != 0){
    for(int i = 0; i < mySize - 1; i ++){
      n = n->next;
    }
    n->next = o;
    n->next->next = nullptr;
   } else {
    //else set start to new node
    start = o;
   }
  mySize++;

}

//Create a new node with value <value>, and insert that new node at position 
template <class T>
void List<T>::insertAt(T value, int j){
  //dummy nodes
  Node<T> *n = start;
  Node<T> *o = new Node(value);
  //if start isnt set set new node to start
  if(start == nullptr){
    start = o;
  }else if(j == 0){
    //if inserting at start 
    o->next = start;
    start = o;
  } else{
    //run through nodes till you get to the right node
    for(int i = 0; i < j - 1; i ++){
      if(n->next != nullptr){
        n = n->next;
      }
    }
    //moves pointers around new nodes
    o->next = n->next;
    n->next = o;
  }
  mySize++;
}

//Remove node at start
//Make no other changes to list
template <class T>
void List<T>::removeStart(){
  //if start.next is not nullptr delete start then set the next node to start
  if(start->next != nullptr){
    Node<T> *n = start->next;
    delete start;
    start = n;
  }else 
  //if it is delete start
    delete start;
  mySize--;
}

//Remove node at end
//Make no other changes to list
template <class T>
void List<T>::removeEnd(){
  Node<T> * n = start;
  //run through nodes till you get to the second to last one
  for(int i = 0; i < mySize - 1; i++){
    n = n->next;
  }
  //delete the next node and set next pointer to nullptr
  delete n->next;
  n->next = nullptr;
  mySize--;
}

//Remove node at position j
//Make no other changes to list
template <class T>
void List<T>::removeAt(int j){
  Node<T> * n = start;

  //runs through nodes till the one before j
  for(int i = 0; i < j - 1; i++){
    n = n->next;
  }
  //dummy node at the next node for the jth node
  Node<T> *o = n->next->next;
  //delete jth node
  delete n->next;
  //set next node to dummy
  n->next = o;
  mySize--;
}

//Return the value of the first node in the Linked List,
//If no first node, return the default constructed value: T()
template <class T>
T List<T>::getFirst(){
  //returns the value of start
  return start->value;
}

//Return the value of the last node in the Linked List,
//If no first node, return the default constructed value: T()
template <class T>
T List<T>::getLast(){
  //dummy node
  Node<T> * n = start;
  
  //runs through all the nodes till its up to my size - 1
  for(int i = 0; i < mySize - 1; i++){
    n = n->next;
  }
  return n->value;
}

//Return the value of the node at position j in the Linked List,
//If no first node, return the default constructed value: T()
template <class T>
T List<T>::getAt(int j){
  //dummy node
  Node<T> *n = start;
  //run through nodes till up to j
  for(int i = 0; i < j; i++){
    n = n->next;
  }
  //return the value of the jth node
  return n->value;
}

//Return the position of the (first) node whose value is equal to the key
//Otherwise, return -1
template <class T>
int List<T>::find(T key){
  //dummy variable and count
  Node<T> *n = start;
  int count = 0;

  //while the right node has not been found or when count is not my size -1
  while(n.value != key || count == mySize - 1){
    n = n->next;
    count++;
  }
  //if never found set count to -1
  if(count == mySize - 1)
    count = -1;
  
  return count;
}
