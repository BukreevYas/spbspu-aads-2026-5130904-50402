#ifndef COMMANDS_HPP
#define COMMANDS_HPP

#include <string>
#include <list.hpp>
#include "graph.hpp"

namespace bukreev
{
  void commandLoad(List< std::string > args, GraphMap& map);
  void commandWidth(List< std::string > args, Canvas& canvas);
  void commandHeight(List< std::string > args, Canvas& canvas);
  void commandAdd(List< std::string > args, GraphMap& map, List< std::string >& names);
  void commandRemove(List< std::string > args, List< std::string >& names);
  void commandClear(List< std::string >& names);
  void commandDisplay(
    GraphMap& map,
    List< std::string >& names,
    Canvas& canvas,
    std::ostream& out
  );
  void commandSave(
    List< std::string > args,
    GraphMap& map,
    List< std::string >& names,
    Canvas& canvas
  );
}

#endif
