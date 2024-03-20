#ifndef NODE_H
#define NODE_H

using namespace std;

class Node {
 public:
  Node();
  ~Node();

  int returnValue();
  Node* returnLeft();
  Node* returnRight();

  void makeRight(Node*);
  void makeLeft(Node*);
  void makeValue(int);
  

 private:
  int value;
  Node* right;
  Node* left;


};
#endif
