class EasyStack {
 public:
  EasyStack();
  ~EasyStack();

  int Push(int);
  int Pop();
  int Top();
  bool Empty();
  bool Full();

 private:
  int* ptop_;
  int* pbottom_;
};