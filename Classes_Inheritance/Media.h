//Header Guard Protection
#ifndef MEDIA
#define MEDIA

#inclde <iostream>

using namespace std;

class Media{

 public:
  Media();
  char* getTitle();
  virtual void Info();
  int getYear();

 protected:
  int id;
  int year;
  char title[80];
};


#endif
