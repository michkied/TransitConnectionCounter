#ifndef TRANSITCONNECTIONCOUNTER_OPERATIONS_H
#define TRANSITCONNECTIONCOUNTER_OPERATIONS_H

#include "Matrix.h"
#include "NodeMap.h"

int any_nodes(const Matrix& mx);
int selected_nodes(const Matrix& mx, const NodeMap& map);
int routes(const Matrix& mx, const NodeMap& map);

#endif //TRANSITCONNECTIONCOUNTER_OPERATIONS_H
