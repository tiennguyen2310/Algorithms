# Problem Statement

The maximum flow problem in a network requires finding the maximum compatible flow in a flow network with one source and one sink. 
The max-flow min-cut theorem states that the maximum flow from s to t (source to sink) is equal to the value of the smallest cut in the network.

**Task:** Try to solve the maximum flow problem in a network: given a flow network, find the maximum flow.

## **Input**

The first line contains 4 positive integers `n`, `m`, `s`, `t`, the number of vertices, the number of edges in the graph, and the indices of the source and sink.

In the next `m` lines: each line contains three numbers `u, v, c` separated by at least one space, representing an edge `(u, v)` in the network with capacity `c`.

## **Output**
Prints a single number representing the maximum flow on the network.

## **Sample Input**
```
6 8 1 6
1 2 5
1 3 5
2 4 6
2 5 3
3 4 3
3 5 1
4 6 6
5 6 6
```
## **Sample Output**
```
9
```
