#include "Object.hpp"
#include <forward_list>
#include <memory>

struct Iterator {
  using DerefFn = Object&(*)(void*);
  using IncrFn  = void(*)(void*);
  using CmpFn   = bool(*)(void*, void*);

  void* ptr;
  DerefFn deref;
  IncrFn incr;
  CmpFn cmp;

  Object& operator*() const { return deref(ptr); }
  Iterator& operator++() { incr(ptr); return *this; }
  bool operator!=(const Iterator& other) const { return !cmp(ptr, other.ptr); }

  ~Iterator() { delete static_cast<char*>(ptr); }
};

struct ObjectList {
  virtual ~ObjectList() = default;
  virtual Object& front() = 0;
  virtual void* get_raw_ptr() = 0;
  virtual struct Iterator begin() = 0;
  virtual struct Iterator end() = 0;
};

// Dla Animal i Fruit (listy wskaźników)
template<typename T>
struct ObjectListImpl : ObjectList {
  std::forward_list<std::unique_ptr<T>>* list;

  ObjectListImpl(std::forward_list<std::unique_ptr<T>>* l) : list(l) {}

  Object& front() override { return *list->front(); }
  void* get_raw_ptr() override { return static_cast<void*>(list); }

  Iterator begin() override {
    using It = typename std::forward_list<std::unique_ptr<T>>::iterator;
    It* it = new It(list->begin());
    return {
      it,
      [](void* p) -> Object& { return *(*(*static_cast<It*>(p))); },
      [](void* p) { ++(*static_cast<It*>(p)); },
      [](void* a, void* b) -> bool { return *static_cast<It*>(a) == *static_cast<It*>(b); }
    };
  }
  Iterator end() override {
    using It = typename std::forward_list<std::unique_ptr<T>>::iterator;
    It* it = new It(list->end());
    return {
      it,
      [](void* p) -> Object& { return *(*(*static_cast<It*>(p))); },
      [](void* p) { ++(*static_cast<It*>(p)); },
      [](void* a, void* b) -> bool { return *static_cast<It*>(a) == *static_cast<It*>(b); }
    };
  }
};

// Specjalizacja dla Corpse (lista obiektów)
template<>
struct ObjectListImpl<Corpse> : ObjectList {
  std::forward_list<Corpse>* list;

  ObjectListImpl(std::forward_list<Corpse>* l) : list(l) {}

  Object& front() override { return *list->begin(); }
  void* get_raw_ptr() override { return static_cast<void*>(list); }

  Iterator begin() override {
    using It = typename std::forward_list<Corpse>::iterator;
    It* it = new It(list->begin());
    return {
      it,
      [](void* p) -> Object& { return *(*static_cast<It*>(p)); },
      [](void* p) { ++(*static_cast<It*>(p)); },
      [](void* a, void* b) -> bool { return *static_cast<It*>(a) == *static_cast<It*>(b); }
    };
  }
  Iterator end() override {
    using It = typename std::forward_list<Corpse>::iterator;
    It* it = new It(list->end());
    return {
      it,
      [](void* p) -> Object& { return *(*static_cast<It*>(p)); },
      [](void* p) { ++(*static_cast<It*>(p)); },
      [](void* a, void* b) -> bool { return *static_cast<It*>(a) == *static_cast<It*>(b); }
    };
  }
};