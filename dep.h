#ifndef DEP_H_
#define DEP_H_

#include "transitive.h"

int dep_return42();

inline int dep_return42_inline() { return transitive_return42(); }

#endif // DEP_H_
