//  map_example1.cpp  ------------------------------------------------------------------//

//  Copyright Beman Dawes 2011, 2013

//  Distributed under the Boost Software License, Version 1.0.
//  See http://www.boost.org/LICENSE_1_0.txt


#include <map>
#include <utility>
#include <boost/btree/map.hpp>
#include <iostream>
using std::cout;
using std::make_pair;

template <class Map>
void example(Map& map)
{
  map.insert(make_pair<int, long>(2, -2));
  map.insert(make_pair<int, long>(3, -3));
  map.insert(make_pair<int, long>(1, -1));

  for (typename Map::iterator it = map.begin(); it != map.end(); ++it)
    cout << "  " << it->first << " --> " << it->second << '\n';
}

int main()
{
  //  std::map example
  cout << "std::map:\n";
  std::map<int, long> std_map;
  example(std_map);

  //  same example, except use btree_map
  cout << "boost::btree::btree_map:\n";
  boost::btree::btree_map<int, long>
    btree_map("map.btr", boost::btree::flags::truncate);
  example(btree_map);

  // Output:
  //
  //   std::map:
  //     1 --> -1
  //     2 --> -2
  //     3 --> -3
  //   boost::btree::btree_map:
  //     1 --> -1
  //     2 --> -2
  //     3 --> -3

  return 0;
}