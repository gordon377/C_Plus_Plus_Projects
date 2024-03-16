#ifndef NODE_H
#define NODE_H

using namespace std;

class Node {
 public:
  Node();
  ~Node();

  Node* returnRight();
  Node* returnLeft();
  char* returnValue();
  Node* returnNext();

  void makeRight(Node*);
  void makeLeft(Node*);
  void makeValue(char*);
  void makeNext(Node*);

 private:
  Node* right;
  Node* left;
  char* value;
  Node* next;

  
};
#endif
