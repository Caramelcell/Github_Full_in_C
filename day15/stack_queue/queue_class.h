class CirclarQueue {
 public:
  CirclarQueue();
  ~CirclarQueue();

  int Enqueue(int);
  int Dequeue();
  int Front();
  int Rear();
  bool Empty();
  bool Full();

 private:
  int front_;
  int rear_;
  int* pqueue_;
};

// class Node {
//  public:
//   Node();
//   ~Node();

//  private:
//   int data_;
//   Node* pnext_;
// };

// class Queue {
//  public:
//   Queue();
//   ~Queue();

//  private:
//   Node* pfront_;
//   Node* prear_;
// };