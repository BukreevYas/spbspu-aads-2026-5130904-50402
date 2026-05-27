#include "eval.hpp"
#include <stdexcept>

bukreev::Expression bukreev::toPostfix(Expression infix)
{
  Expression postfix;
  Stack< std::string > tempStack;

  while (!infix.empty())
  {
    std::string token = infix.pop();
    if (token == "(")
    {
      tempStack.push(token);
      continue;
    }

    if (token == "+" || token == "-" || token == "*" || token == "/" || token == "%")
    {
      while (!tempStack.empty())
      {
        std::string top = tempStack.pop();
        if (top == "(")
        {
          tempStack.push("(");
          break;
        }
        postfix.push(top);
      }
      tempStack.push(token);

      continue;
    }

    if (token == ")")
    {
      while (!tempStack.empty())
      {
        std::string top = tempStack.pop();
        if (top == "(")
        {
          tempStack.push("(");
          break;
        }
        postfix.push(top);
      }

      if (!tempStack.empty())
      {
        tempStack.pop();
      }

      continue;
    }
    postfix.push(token);
  }

  while (!tempStack.empty())
  {
    postfix.push(tempStack.pop());
  }

  return postfix;
}

bukreev::num_t bukreev::evaluatePostfix(Expression postfix)
{
  Stack< num_t > tempStack;
  while (!postfix.empty())
  {
    std::string token = postfix.pop();
    if (token == "+" || token == "-" || token == "*" || token == "/" || token == "%")
    {
      if (tempStack.empty())
      {
        throw std::logic_error("Incorrect expression");
      }

      num_t b = tempStack.pop();
      if (tempStack.empty())
      {
        throw std::logic_error("Incorrect expression");
      }

      num_t a = tempStack.pop();
      tempStack.push(evaluateOperation(token, a, b));
    }
    else
    {
      tempStack.push(std::stoll(token));
    }
  }

  return tempStack.pop();
}

bukreev::num_t bukreev::evaluateOperation(std::string op, num_t a, num_t b)
{
  switch (op[0])
  {
  case '+':
    return a + b;

  case '-':
    return a - b;

  case '*':
    return a * b;

  case '/':
    return a / b;

  case '%':
    return a % b;

  default:
    return 0;
  }
}
