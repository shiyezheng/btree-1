//  example/bulk_load_map.cpp

//  Copyright Beman Dawes 2013

//  Distributed under the Boost Software License, Version 1.0.
//  See http://www.boost.org/LICENSE_1_0.txt

#include <boost/btree/btree_map.hpp>
#include <iostream>
#include <boost/detail/lightweight_main.hpp> 

using std::cout;
using namespace boost::btree;

int cpp_main(int, char *[])
{
  typedef btree_set<std::string> BT;
  BT bt("bulk_load_map.btr", flags::truncate);


  for (BT::iterator itr = bt.begin(); itr != bt.end(); ++itr)
    cout << itr->first << ", " << itr->second << '\n';
}