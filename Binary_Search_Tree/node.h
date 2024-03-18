#ifndef NODE_H
#define NODE_H

using namespace std;

class Node {
 public:
  Node();
  ~Node();

  int returnValue();

  void makeRight(Node*);
  void makeLeft(Node*);
  

 private:
  int value;


};
#endif
