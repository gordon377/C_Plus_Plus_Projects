#ifndef NODE_H
#define NODE_H

using namespace std;

class Node {
 public:
  Node();
  ~Node();

  Node* returnRight();
  Node* returnLeft();
  char* returnData();
  Node* returnNext();

  void makeRight(Node*);
  void makeLeft(Node*);
  void makeData(Node*);
  void makeNext(char*);

 private:
  Node* right;
  Node* left;
  char* data;
  Node* next;

  
};
#endif
