#include "commands.hpp"
#include <iostream>
#include <fstream>

void bukreev::commandLoad(List< std::string > args, GraphMap& map)
{
  if (args.size() > 4 || args.size() < 3)
  {
    std::cout << "<INVALID COMMAND>\n";
    return;
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

  if (args.size() == 3)
  {
    symbol = '*';
  }

  if (!file.is_open())
  {
    std::cout << "<INVALID COMMAND>\n";
    return;
  }

  Graph* graph = new Graph;

  while (file)
  {
    size_t x, y;
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

void bukreev::commandAdd(List< std::string > args, GraphMap& map, List< std::string >& names)
{
  if (args.size() != 2)
  {
    std::cout << "<INVALID COMMAND>\n";
    return;
  }

  std::string name;
  size_t i = 0;
  for (LCIter< std::string > it = args.cbegin(); it != args.cend(); it++, i++)
  {
    if (i == 1)
    {
      name = *it;
    }
  }

  if (!map.count(name))
  {
    std::cout << "<INVALID COMMAND>\n";
    return;
  }

  names.pushBack(name);
}

void bukreev::commandRemove(List< std::string > args, List< std::string >& names)
{
  if (args.size() != 2)
  {
    std::cout << "<INVALID COMMAND>\n";
    return;
  }

  std::string name;
  size_t i = 0;
  for (LCIter< std::string > it = args.cbegin(); it != args.cend(); it++, i++)
  {
    if (i == 1)
    {
      name = *it;
    }
  }

  if (!names.remove(name))
  {
    std::cout << "<INVALID COMMAND>\n";
    return;
  }
}

void bukreev::commandClear(List< std::string >& names)
{
  names.clear();
}

void bukreev::commandWidth(List< std::string > args, Canvas& canvas)
{
  if (args.size() != 2)
  {
    std::cout << "<INVALID COMMAND>\n";
    return;
  }

  size_t width;
  size_t i = 0;
  for (LCIter< std::string > it = args.cbegin(); it != args.cend(); it++, i++)
  {
    if (i == 1)
    {
      width = std::stoull(*it);
    }
  }

  if (width < 2)
  {
    std::cout << "<INVALID COMMAND>\n";
    return;
  }

  canvas.setSize(width, canvas.getHeight());
}

void bukreev::commandHeight(List< std::string > args, Canvas& canvas)
{
  if (args.size() != 2)
  {
    std::cout << "<INVALID COMMAND>\n";
    return;
  }

  size_t height;
  size_t i = 0;
  for (LCIter< std::string > it = args.cbegin(); it != args.cend(); it++, i++)
  {
    if (i == 1)
    {
      height = std::stoull(*it);
    }
  }

  if (height < 2)
  {
    std::cout << "<INVALID COMMAND>\n";
    return;
  }

  canvas.setSize(canvas.getWidth(), height);
}

void bukreev::commandDisplay(
  GraphMap& map,
  List< std::string >& names,
  Canvas& canvas,
  std::ostream& out
)
{
  canvas.clear();
  for (LCIter< std::string > it = names.cbegin(); it != names.cend(); it++)
  {
    canvas.drawGraph(map[*it]);
  }

  canvas.display(out);
}

void bukreev::commandSave(
  List< std::string > args,
  GraphMap& map,
  List< std::string >& names,
  Canvas& canvas
)
{
  if (args.size() != 2)
  {
    std::cout << "<INVALID COMMAND>\n";
    return;
  }

  std::string filename;
  size_t i = 0;
  for (LCIter< std::string > it = args.cbegin(); it != args.cend(); it++, i++)
  {
    if (i == 1)
    {
      filename = *it;
    }
  }

  std::ofstream file(filename);
  commandDisplay(map, names, canvas, file);
}
