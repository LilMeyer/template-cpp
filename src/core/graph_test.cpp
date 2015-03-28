#include <iostream>                  // for std::cout
#include <utility>                   // for std::pair
#include <algorithm>                 // for std::for_each
#include <boost/graph/graph_traits.hpp>
#include <boost/graph/adjacency_list.hpp>
#include <boost/graph/dijkstra_shortest_paths.hpp>
#include <vector>

#include <cppunit/TestAssert.h>
#include <cppunit/TestCaller.h>
#include <cppunit/TestCase.h>
#include <cppunit/TestFixture.h>
#include <cppunit/ui/text/TestRunner.h>
#include <cppunit/TestSuite.h>

// http://www.boost.org/doc/libs/1_57_0/libs/graph/doc/quick_tour.html

using namespace boost;

typedef std::pair<int, int> Edge;
typedef adjacency_list<vecS, vecS, bidirectionalS> Graph;
typedef typename graph_traits<Graph>::vertex_descriptor Vertex;
typedef property_map<Graph, vertex_index_t>::type IndexMap;
class GraphTest : public CppUnit::TestFixture {

private:
  enum { A, B, C, D, E, F, G, N };
  const int num_vertices = N;
  // declare a graph object
  Graph g;
  std::vector<Edge> edge_array;

public:

  GraphTest() : g(N) {
    /* CONSTRUCTING A GRAPH */
    edge_array.push_back(Edge(A, B));
    edge_array.push_back(Edge(A, D));
    edge_array.push_back(Edge(C, A));
    edge_array.push_back(Edge(D, C));
    edge_array.push_back(Edge(C, E));
    edge_array.push_back(Edge(B, D));
    edge_array.push_back(Edge(D, E));
  }

  static CppUnit::Test *suite() {
    CppUnit::TestSuite *suiteOfTests = new CppUnit::TestSuite("GraphTest");

    suiteOfTests->addTest(new CppUnit::TestCaller<GraphTest>("Test1 - Unique Solution.",
            &GraphTest::test1));
    return suiteOfTests;
  }

  /* Setup method */
  void setUp() {}

  /* Teardown method */
  void tearDown() {}

protected:

  void test1() {
    std::cout << std::endl;


    // Make convenient labels for the vertices
    const char* name = "ABCDE";

    // add the edges to the graph object
    for (unsigned int i = 0; i < edge_array.size(); ++i) {
      add_edge(edge_array[i].first, edge_array[i].second, g);
    }


    // get the property map for vertex indices
    IndexMap index = get(vertex_index, g);

    std::cout << "vertices(g) = ";
    typedef graph_traits<Graph>::vertex_iterator vertex_iter;
    std::pair<vertex_iter, vertex_iter> vp;
    for (vp = vertices(g); vp.first != vp.second; ++vp.first) {
      Vertex v = *vp.first;
      std::cout << index[v] <<  " ";
    }
    std::cout << std::endl;

    /* ACCESSING THE EDGE SET */
    std::cout << "edges(g) = ";
    graph_traits<Graph>::edge_iterator ei, ei_end;
    for (boost::tie(ei, ei_end) = edges(g); ei != ei_end; ++ei)
        std::cout << "(" << index[source(*ei, g)]
                  << "," << index[target(*ei, g)] << ") ";
    std::cout << std::endl;

    // exercise_vertex<Graph> ev(g);


  }
};


int main(int argc, char* argv[]) {

  CppUnit::TextUi::TestRunner runner;
  std::cout << "Creating Test Suites:" << std::endl;
  runner.addTest(GraphTest::suite());
  std::cout<< "Running the unit tests."<< std::endl;
  runner.run();

  return 0;
}
