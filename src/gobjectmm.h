#ifndef GOBJECTMM_H_
#define GOBJECTMM_H_

#include <memory>
#include <stdexcept>
#include <glib-object.h>

template<typename T>
class gobject_ptr: public std::shared_ptr<T> {
    using B = std::shared_ptr<T>;

    static void deleter(T *ptr) noexcept {
      if (ptr != NULL && G_IS_OBJECT(ptr))
        g_object_unref(ptr);
    }

  public:
    gobject_ptr(T *ptr = NULL) noexcept : B(ptr, deleter) {
      g_warn_if_fail(ptr == NULL || G_IS_OBJECT(ptr));
    }
};

template<typename T, void (*D)(T*)>
class gshared_ptr: public std::shared_ptr<T> {
    using B = std::shared_ptr<T>;

    static void deleter(T *ptr) {
      if (ptr)
        D(ptr);
    }

  public:
    gshared_ptr(T *ptr = NULL) : B(ptr, deleter) {
    }
};

template<typename T, void (*D)(T*)>
class gunique_ptr: public std::unique_ptr<T, typeof(D)> {
    using B = std::unique_ptr<T, typeof(D)>;

    static void deleter(T *ptr) {
      if (ptr)
        D(ptr);
    }

  public:
    gunique_ptr(T *ptr = NULL) : B(ptr, deleter) {
    }
};

#endif /* GOBJECTMM_H_ */
