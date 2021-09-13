/**
 * Stack data structure implementation using linked list
 *
 * @file   stack.h
 * @author maxrt101
 */

#ifndef _STACK_H
#define _STACK_H

#include <stdexcept>

template <typename T>
class Frame {
 private:
  Frame* m_prev = nullptr;
  Frame* m_next = nullptr;
  T m_data;
 
 public:
  inline Frame(T& data) : m_data(data) {}
  inline Frame(T& data, Frame* prev) : m_data(data), m_prev(prev) {}
  inline ~Frame() {}

  inline T& data() {
    return m_data;
  }

  inline Frame*& prev() {
    return m_prev;
  }

  inline Frame*& next() {
    return m_next;
  }
};

template <typename T>
class Stack {
 public:
  using FrameType = Frame<T>;
  using SizeType = size_t;

 private:
  FrameType* m_head = nullptr;
  FrameType* m_top = nullptr;
  SizeType m_size = 0;
 
 public:
  inline Stack() {}
  inline ~Stack() {
    clear();
  }

  inline void push(T data) {
    if (!m_top) {
      m_top = new FrameType(data);
      m_head = m_top;
    } else {
      FrameType* prev = m_top;
      m_top = new FrameType(data, prev);
      prev->next() = m_top;
    }
    m_size++;
  }
  
  inline T pop() {
    if (!m_top) {
      throw std::underflow_error("Cannot pop from empty stack");
    }

    T data = m_top->data();
    FrameType* frame = m_top;
    
    if (m_top->prev()) {
      m_top = m_top->prev();
      m_top->next() = nullptr;
    } else {
      m_top = nullptr;
      m_head = nullptr;
    }
    
    delete frame;
    m_size--;
    
    return data;
  }
  
  inline T peak(int depth = 0) const {
    FrameType* frame = m_top;
    for (int i = 0; i < depth; i++) {
      frame = frame->prev();
    }
    return frame->data();
  }

  inline void clear() {
    while (m_head) {
      FrameType* frame = m_head;
      m_head = m_head->next();
      delete frame;
      m_size--;
    }
  }

  inline SizeType size() const {
    return m_size;
  }

  inline SizeType find(const T& data) const {
    SizeType depth = 0;

    FrameType* frame = m_top;
    while (frame->data() != data) {
      frame = frame->prev();
      depth++;
    }

    return depth;
  }
};

#endif

