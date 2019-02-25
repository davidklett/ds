#include <vector>
#include <list>
#include <iostream>
#include <string>
#include <fstream>
#include <sstream>
#include <iterator>

using namespace std;
using std::cout;
using std::endl;
using std::cin;
using std::list;
using std::vector;


list<int>::iterator find_gt(list<int>::iterator start, list<int>::iterator stop,
                            int x);

int main()
{
    vector<list<int>> adjList;
    list<int> mtLst;  // an empty list

  string line;
  ifstream myfile ("graph.dat");
  int countV = 0;

      if (myfile.is_open())
      {
        //Iterate through vector:
        while ( getline (myfile,line) )
        {
          adjList.push_back(mtLst);

                std::istringstream is( line );
                int x;
                //populate the linked-list!
                while( is >> x ) {
                      adjList[countV].push_back(x);
                }

          countV++;
        }
        myfile.close();
      }

      else cout << "Unable to open file";


    std::list<int>::const_iterator iterator;
    for(iterator = adjList[0].begin(); iterator != adjList[0].end(); ++iterator)
    {
        std::cout << *iterator;
    }

    //test find_gt
    find_gt(adjList[0].begin(), adjList[0].end(), 3);

    return 0;
}

list<int>::iterator find_gt(list<int>::iterator start, list<int>::iterator stop,int x)
{
  std::list<int>::const_iterator temp_iter;
  for(temp_iter = start; temp_iter != stop; ++temp_iter)
  {
        if(*temp_iter > x)
            return temp_iter;
  }
}
