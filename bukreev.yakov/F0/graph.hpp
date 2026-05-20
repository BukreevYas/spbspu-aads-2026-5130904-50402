#ifndef GRAPH_HPP
#define GRAPH_HPP

#include <list.hpp>
#include <unordered_map>
#include <string>

namespace bukreev
{
  struct point_t
  {
    int x;
    int y;
  };

  struct Graph
  {
    List< point_t > points;
    char symbol;
  };

  using GraphMap = std::unordered_map< std::string, Graph* >;
}

#endif
