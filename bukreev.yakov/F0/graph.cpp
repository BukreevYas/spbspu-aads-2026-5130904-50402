#include "graph.hpp"

bukreev::Canvas::Canvas(size_t width, size_t height)
{
  mSymbols = new char[width * height];
  mWidth = width;
  mHeight = height;

  mSymbols[0] = '+';

  for (size_t i = 1; i < width; i++)
  {
    mSymbols[i] = '-';
  }

  for (size_t i = 1; i < height; i++)
  {
    mSymbols[i * width] = '|';
  }

  for (size_t i = 1; i < height; i++)
  {
    for (size_t j = 1; j < width; j++)
    {
      mSymbols[i * width + j] = ' ';
    }
  }

  mSymbols[(height - 1) * width] = '^';
  mSymbols[width - 1] = '>';
}

void bukreev::Canvas::drawGraph(const Graph* graph)
{
  for (LCIter< point_t > it = graph->points.cbegin(); it != graph->points.cend(); it++)
  {
    point_t pt = *it;
    mSymbols[pt.y * mWidth + pt.x] = graph->symbol;
  }
}

void bukreev::Canvas::display(std::ostream& out)
{
  for (size_t i = mHeight - 1; i > 0; i--)
  {
    for (size_t j = 0; j < mWidth; j++)
    {
      out << mSymbols[i * mWidth + j];
    }
    out << '\n';
  }

  for (size_t j = 0; j < mWidth; j++)
  {
    out << mSymbols[j];
  }
  out << '\n';
}
