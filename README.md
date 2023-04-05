# TransitConnectionCounter

TransitConnectionCounter is a C++ script that, using matrix exponentiation, can calculate several properties of a transit network.


## Glossary
- **Node** - a transit stop or a group of stops, that are closely located and can therefore be considered a single entity.
- **Line** - a transit line, that is represented by a list of nodes.


## Available actions
- **a2n**  -  Find the minimal number of transfers required to travel between any two nodes
- **s2n**  -  Find the minimal number of transfers required to travel between two selected nodes
- **rts**  -  Find the number of possible routes between selected nodes using no more than N transfers
- **exp**  -  Export the calculated connection table to a CSV file


## Input examples (separator: _ )
Two transit lines, that cross in node2
```
lineA_node1_node2_node3
lineB_node4_node2_node5_node6
```
Three transit lines, that form a triangle
```
lineA_node1_node2_node3
lineB_node3_node4_node5
lineC_node5_node6_node1
```
