/** @file assg-tests.cpp
 * @brief Unit tests for Assignment Classes: practice on classes and user
 *   defined types.
 *
 * @author Derek Harter
 * @note   class: COSC 2336, Summer 2021
 * @note   ide  : VS Code Server 3.9.3 and Gnu/Make build tools
 * @note   assg : Assignment STL
 * @date   December 7, 2021
 *
 * Assignment Standard Template Library STL.
 */
#include "catch.hpp"
#include <iostream>
#include <list>
#include <map>
#include <queue>
#include <stack>
#include <vector>
using namespace std;

/** Task 1 example test task.  Demonstarte using an STL list
 * container.
 */
TEST_CASE("<list> test list STL container", "[task1]")
{
  // list of integers
  list<int> l1;

  // list should be initially empty
  CHECK(l1.empty());

  // add item, it is now not empty
  l1.push_front(5);
  CHECK_FALSE(l1.empty());
  CHECK(l1.size() == 1);
}

// Example 1
int getQueueFront(std::queue<int>& q)
{
  if (q.empty())
  {
    throw std::runtime_error("Queue is empty!");
  }
  return q.front();
}

TEST_CASE("STL <queue>: Test queue front and exception handling", "Example 1")
{
  // Test case 1
  std::queue<int> q;
  q.push(1);
  q.push(2);
  q.push(3);

  REQUIRE_NOTHROW(getQueueFront(q));
  CHECK(getQueueFront(q) == 1);

  std::queue<int> emptyQueue;
  CHECK_THROWS_AS(getQueueFront(emptyQueue), std::runtime_error);
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
TEST_CASE("STL <map>: Test map operations", "Example 2")
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
TEST_CASE("STL <stack>: Test stack push, pop, and top", "Example 3")
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
TEST_CASE("STL <vector>: Test vector push_back and access", "Example 4")
{
  std::vector<int> result = exampleVectorOperations();
  assert(result.size() == 3);
  assert(result[0] == 1);
  assert(result[1] == 42);
  assert(result[2] == 3);
}