#include "queue_class.h"

#include "iostream"

const int kCirclarQueueSize = 10;

CirclarQueue::CirclarQueue()
    : pqueue_(new int[kCirclarQueueSize]), front_(0), rear_(0) {}

CirclarQueue::~CirclarQueue() { delete[] pqueue_; }

bool CirclarQueue::Empty() {
  if (rear_ == front_) {
    return true;
  } else {
    return false;
  }
}

bool CirclarQueue::Full() {
  if ((rear_ + 1) % kCirclarQueueSize == front_) {
    return true;
  } else {
    return false;
  }
}

int CirclarQueue::Enqueue(int data) {
  if (!Full()) {
    rear_ = (rear_ + 1) % kCirclarQueueSize;
    pqueue_[rear_] = data;
    return 0;
  } else {
    std::cout << "queue is full" << std::endl;
    return -1;
  }
}

int CirclarQueue::Dequeue() {
  if (!Empty()) {
    front_ = (front_ + 1) % kCirclarQueueSize;
    return pqueue_[front_];
  } else {
    std::cout << "queue is empty" << std::endl;
    return -1;
  }
}

int CirclarQueue::Front() {
  if (!Empty()) {
    return pqueue_[(front_ + 1) % kCirclarQueueSize];
  } else {
    std::cout << "queue is empty" << std::endl;
    return -1;
  }
}

int CirclarQueue::Rear() {
  if (!Empty()) {
    return pqueue_[rear_];
  } else {
    std::cout << "queue is empty" << std::endl;
    return -1;
  }
}