#include "commands.hpp"
#include <iostream>
#include <fstream>

void bukreev::commandLoad(List< std::string > args, GraphMap& map)
{
  if (args.size() > 4 || args.size() < 3)
  {
    std::cout << "<INVALID COMMAND>\n";
  }

  std::ifstream file;
  std::string name;
  char symbol;
  size_t i = 0;
  for (LCIter< std::string > it = args.cbegin(); it != args.cend(); it++, i++)
  {
    if (i == 1)
    {
      name = *it;
    }
    else if (i == 2)
    {
      file.open(*it);
    }
    else if (i == 3)
    {
      symbol = (*it)[0];
    }
  }

  if (!file.is_open())
  {
    std::cout << "<INVALID COMMAND>\n";
    return;
  }

  Graph* graph = new Graph;

  while (file)
  {
    int x, y;
    file >> x;
    if (!file)
    {
      break;
    }

    file >> y;
    if (!file)
    {
      delete graph;
      std::cout << "<INVALID COMMAND>\n";
      return;
    }

    graph->points.pushBack({x, y});
  }

  graph->symbol = symbol;

  if (map.count(name))
  {
    delete graph;
    std::cout << "<INVALID COMMAND>\n";
    return;
  }

  map[name] = graph;
}
