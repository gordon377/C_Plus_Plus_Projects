#ifndef VTEX_H
#define VTEX_H

using namespace std;

class vtex {
 public:
  vtex();
  ~vtex();
  
  //make functions
  void mkIndex(int);
  void mkName(char);
  void mkEdge(int, int);
  
  //return functions
  int returnIndex();
  char returnName();
  int returnEdge(int);

private:
  int index;
  char name;
  int edges[20];
  
};
#endif
