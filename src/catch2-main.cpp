/** @file catch2-main.cpp
 * @brief Unit tests for Assignments
 *
 * @author Derek Harter
 * @note   class: COSC 2336, Summer 2021
 * @note   ide  : VS Code Server 3.9.3
 * @note   assg : all assignments
 * @date   June 1, 2021
 *
 * The catch2 framework main function is compiled by this source file into
 * tests-main.o.  This is mainly so that the framework needs to be only compiled
 * 1 time normally.  The framework can take a significant amount of time to compile.
 * Thus it is useful to avoid this recompilation during normal build/test
 * iterations.
 */
#define CATCH_CONFIG_MAIN
#include "catch.hpp"

#include <iostream>
#include <map>
#include <queue>
#include <stack>

// Example 1
int getQueueFront(std::queue<int>& q)
{
  if (q.empty())
  {
    throw std::runtime_error("Queue is empty!");
  }
  return q.front();
}

bool isParenthesisMatching(const std::string& str)
{
  std::stack<char> s;
  for (char ch : str)
  {
    if (ch == '(')
      s.push(ch);
    else if (ch == ')')
    {
      if (s.empty())
        return false;
      s.pop();
    }
  }
  return s.empty();
}

int testCaseOne()
{
  // Test case 1
  std::queue<int> q;
  q.push(1);
  q.push(2);
  q.push(3);
  try
  {
    std::cout << "Front of queue: " << getQueueFront(q) << "\n"; // Output: 1
  }
  catch (const std::exception& e)
  {
    std::cout << e.what() << "\n";
  }

  std::string testStr = "(()())";
  std::cout << "Parenthesis Matching: " << (isParenthesisMatching(testStr) ? "Yes" : "No") << "\n"; // Output: Yes

  return 0;
}

// Example 2
std::map<std::string, int> MapOperations()
{
  std::map<std::string, int> myMap;
  myMap["John"] = 30;
  myMap["Bob"] = 25;
  myMap["Mike"] = 35;
  return myMap;
}

// Test case 2
void testMapOperations()
{
  std::map<std::string, int> result = MapOperations();
  assert(result["John"] == 30);
  assert(result["Bob"] == 25);
  assert(result["Mike"] == 35);
  assert(result.size() == 3);
}

// Example 3
std::stack<int> StackOperations()
{
  std::stack<int> s;
  s.push(100);
  s.push(200);
  s.push(300);
  s.pop();
  return s;
}

// Test case 3
void testStackOperations()
{
  std::stack<int> result = StackOperations();
  assert(result.size() == 2);
  assert(result.top() == 200);
  result.pop();
  assert(result.top() == 100);
}

// Example 4
std::vector<int> exampleVectorOperations()
{
  std::vector<int> vec;
  vec.push_back(1);
  vec.push_back(2);
  vec.push_back(3);
  vec[1] = 42;
  return vec;
}

// Test case 4
void testExampleVectorOperations()
{
  std::vector<int> result = exampleVectorOperations();
  assert(result.size() == 3);
  assert(result[0] == 1);
  assert(result[1] == 42);
  assert(result[2] == 3);
}