#ifndef EXCEPTIONS_H_
#define EXCEPTIONS_H_

#include <stdexcept>

struct ErrnoException: public std::runtime_error {
    explicit ErrnoException(const char *baseMsg = nullptr) noexcept;
};

#endif /* EXCEPTIONS_H_ */
