#ifndef COMMANDS_HPP
#define COMMANDS_HPP

#include <string>
#include <list.hpp>
#include "graph.hpp"

namespace bukreev
{
  void commandLoad(List< std::string > args, GraphMap& map);
  void commandAdd(List< std::string > args, GraphMap& map, List< std::string >& names);
  void commandDisplay(
    GraphMap& map,
    List< std::string >& names,
    Canvas& canvas,
    std::ostream& out
  );
}

#endif
