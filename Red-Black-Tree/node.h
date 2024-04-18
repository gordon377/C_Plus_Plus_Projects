#ifndef NODE_H
#define NODE_H

using namespace std;

class Node {
 public:
  Node();
  ~Node();

  bool returnRed();
  int returnValue();
  Node* returnParent();
  Node* returnLeft();
  Node* returnRight();

  void recolor(Node*);
  void makeParent(Node*);
  void makeRight(Node*);
  void makeLeft(Node*);
  void makeValue(int);

 private:
  bool red;
  int value;
  Node* parent;
  Node* right;
  Node* left;

};
#endif
