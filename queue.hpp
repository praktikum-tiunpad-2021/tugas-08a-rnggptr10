#pragma once

namespace strukdat {

namespace priority_queue {

/**
 * @brief Implementasi struct untuk elemen, harus ada isi dan prioritas elemen.
 */
template <typename T>
struct Element {
  T data;
  int priority;
  Element* next;
};

template <typename T>
using ElementPtr = Element<T> *;

/**
 * @brief implemetasi struct untuk queue.
 */
template <typename T>
struct Queue {
  ElementPtr<T> Head;
  ElementPtr<T> Tail;
};

/**
 * @brief membuat queue baru
 *
 * @return  queue kosong
 */
template <typename T>
Queue<T> new_queue() {
  Queue<T> q;
  q.Head = nullptr;
  q.Tail = nullptr;
  return q;
}

/**
 * @brief memasukan data sesuai priority elemen.
 *
 * @param q         queue yang dipakai.
 * @param value     isi dari elemen.
 * @param priority  prioritas elemen yang menentukan urutan.
 */
template <typename T>
void enqueue(Queue<T> &q, const T &value, int priority) {
  ElementPtr<T> pBaru, pRev, pBantu;
  
  //ISI DATA
  pBaru = new Element<T>;
  pBaru->data = value;                    
  pBaru->priority = priority;
  pBaru->next = nullptr;

  pRev = nullptr;
  pBantu = q.Head;
  
  //MEMASUKKAN DATA
  if(q.Head == nullptr && q.Tail == nullptr){           // pada saat list kosong
    q.Head = pBaru;
    q.Tail = pBaru; 
  }else{                                                // pada saat list tidak kosong
    while(pBaru->priority <= pBantu->priority){         // cek priority
      if(pBantu->next == nullptr)
        break;
      pRev = pBantu;
      pBantu = pBantu->next;
    }

    //INSERT FIRST
    if(pBaru->priority > pBantu->priority && pBantu == q.Head){
      pBaru->next = pBantu;
      q.Head = pBaru;
    }
    //INSERT LAST 
    else if(pBaru->priority < pBantu->priority && pBantu == q.Tail){
        pBantu->next = pBaru;
        q.Tail = pBaru;
    }
    //INSERT MID
    else{
      pRev->next = pBaru;
      pBaru->next = pBantu;
    }
  }
}

/**
 * @brief mengembalikan isi dari elemen head.
 *
 * @param q   queue yang dipakai.
 * @return    isi dari elemen head.
 */
template <typename T>
T top(const Queue<T> &q) {
  return q.Head->data;
}

/**
 * @brief menghapus elemen head queue (First in first out).
 *
 * @param q   queue yang dipakai.
 */
template <typename T>
void dequeue(Queue<T> &q) {
  ElementPtr<T> pHapus;
  if(q.Head == nullptr && q.Tail == nullptr){     // pada saat list kosong
    pHapus = nullptr;
  }else if(q.Head->next == nullptr){              // pada saat list berisi 1 Node
    pHapus = q.Head;
    q.Head = nullptr;
    q.Tail = nullptr;
  }else{                                          // delete first             
    pHapus = q.Head;
    q.Head = q.Head->next;
    pHapus->next = nullptr;
  }
}

}  // namespace priority_queue

}  // namespace strukdat
