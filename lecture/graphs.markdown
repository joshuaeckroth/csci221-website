---
title: Graphs
layout: default
---

Graphs are defined by nodes and connections between
nodes. Mathematically, it can be defined as $G = (V,E)$ where $V$ is
the set of nodes ("vertices"), and $E$ is the set of connections
("edges"). Each connection is a pair of nodes, e.g., $(n_1, n_2)$.

Here is a graph: $G = (\\\{n_1, n_2, n_3\\\}, \\\{(n_1, n_2), (n_1, n_3), (n_2,
n_3)\\\}).$ This graph is "directed" because some connections do not
have a corresponding reverse connection ($n_3$ is not connected back
to $n_1$). You can visualize the graph like this:

<div style="text-align: center">
<img src="/images/graph-simple.png" />
</div>

## Graph algorithms

There exist many algorithms that operate on graphs. For these notes,
we'll only consider a few important ones.

### Add/delete nodes and connections

Of course, we'll want support for adding/deleting nodes and
connections. Depending on the data structure, this is easy or not so
easy.

### Contains?

Does a graph contain a certain node $n$? In mathematical notation,
this is as simple as asking if $V$ contains $n$. However, this could
be a difficult question to answer with code, depending on the data
structure we use.

### Reachable?

Is $n_2$ reachable from $n_1$? In other words, is there some path of
connections between $n_1$ and $n_2$? This requires some kind of graph
traversal, a.k.a., graph search. Nearly all such algorithms follow the
same basic pattern:

<pre>
1. create an empty linked list called "closed"; this list will contain
   nodes that have been visited

2. create a linked list called "open" that contains just the starting
   node n1; this list contains nodes that have not been visited but
   have been found to be connected to visited nodes

4. while the open list is not empty:

   a. grab a node from the open list (and remove it);
      put it in the closed list (since we're now looking at it)

   b. if that node is the target, hey we're done! the answer is, "yes,
      n2 is reachable from n1."

   c. if it's not the target node, then for each node that is
      connected from this node,

       i. if this next node is in the closed list (it has been visited
          before), ignore it

      ii. if this next node is not already in the open list, put it in
          the open list

   d. (repeat the loop)

5. if the open list is empty and we never found the target, then the
answer is, "no, n2 is not reachable by n1."
</pre>

Depending on how nodes are pulled out of the "open" list, you get
breadth-first or depth-first search:

- breadth-first search: visit the oldest node in the "open" list
  first.

- depth-first search: visit the newest node in the "open" list first.

### Topological sort

We can produce a "sorted" list of all the nodes in the (directed,
acyclic) graph. This
sorted list respects the connections of the nodes, so that if $n_1$ is
connected to $n_2$, then $n_1$ appears earlier than $n_2$ in the
topologically-sorted list of nodes.

For the graph above, this is a topological sort of the nodes: $n_1,
n_2, n_3$. In fact, that is the only possibility ($n_3$ cannot come
before $n_2$ since $n_2$ connects to $n_3$; and of course, nothing can
come before $n_1$).

Here is the general algorithm, attributed to Arther Kahn, and adapted
from [Wikipedia](http://en.wikipedia.org/wiki/Topological_sorting):

<pre>
L = Empty list that will contain the sorted nodes
Tm = A list of nodes temporarily "marked"
Pm = A list of noded permanently "marked"

while there are unmarked nodes:
- select an unmarked node n
- topo_visit(n) 

function topo_visit(node n)
- if n has a temporary mark then:
  - stop (not an acyclic graph)
- if n is not marked (i.e. has not been visited yet) then:
  - mark n temporarily
  - for each node m connected from n:
    - topo_visit(m)
  - mark n permanently
  - unmark n temporarily
  - add n to front of L
</pre>

Depending on the data structure, it might be easy or hard to produce
the initial list `S` of nodes with no incoming connections, and to
remove connections from the graph as the loop processes.

## Data structures for graphs

There exist a variety of data structures to represent graphs. They
each have their advantages and disadvantages.

### Direct pointers

We can represent nodes as a `GraphNode` class and the connections as a
fixed set of pointers in the class. E.g.,

{% highlight cpp %}
class GraphNode
{
public:
    int val;
    GraphNode *c1; // maximum of two connections for each node
    GraphNode *c2;
};

GraphNode n1 = new GraphNode;
GraphNode n2 = new GraphNode;
GraphNode n3 = new GraphNode;
n1->c1 = n2;
n1->c2 = n3;
n2->c1 = n3;
n2->c2 = NULL;
n3->c1 = NULL;
n3->c2 = NULL;
{% endhighlight %}

The "graph" itself may be a pointer to one of the nodes, such as `n1`,
if the reset of the graph is reachable by `n1`, or alternatively, an
array or linked list containing pointers to all of the graph's nodes.

#### Graph algorithms

#### Advantages and disadvantages

Advantages:

- The data structure is simple. It just uses pointers for the
  connections. All other data structures for graphs will use pointers
  as well, but this is the simplest way to do so.

Disadvantages:

- Requires knowing ahead of time how many connections are allowed from
  each node (assuming you don't use a linked list of pointers for the
  connections).

- Traversing the graph requires walking through the pointers in each
  node. There is no global record of the connections, so if you find
  that some node is not connected to any others (you reach a dead
  end), you have to start over from the beginning, or back out.

- Deleting nodes is very difficult because you have to check all nodes
  to see if they are connected to the node that is to be
  deleted. These connections must be replaced with `NULL`.

### Adjacency lists

<div style="text-align: center">
<img src="/images/adjacency-list-of-graph.jpg" width=600 />
<br/>
Image from: <a
href="http://sourcecodemania.com/graph-implementation-in-cpp/">sourcecodemania.com/graph-implementation-in-cpp</a>
</div>

### Adjacency matrices

<div style="text-align: center">
<img src="/images/adjacency-matrix-of-graph.jpg" width=600 />
<br/>
Image from: <a
href="http://sourcecodemania.com/graph-implementation-in-cpp/">sourcecodemania.com/graph-implementation-in-cpp</a>
</div>

