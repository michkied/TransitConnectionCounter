#ifndef TRANSITCONNECTIONCOUNTER_OPERATIONS_H
#define TRANSITCONNECTIONCOUNTER_OPERATIONS_H

#include "Matrix.h"
#include "NodeMap.h"

int changes(const Matrix& mx);
int min_changes(const Matrix& mx, const NodeMap& map);
int connections(const Matrix& mx, const NodeMap& map);

#endif //TRANSITCONNECTIONCOUNTER_OPERATIONS_H
