// adjList.cpp
// Dianne Foreback
// Sept. 2018
// Demo building an adjacency list
// via a vector of linked lists
//
// if adjList is printed, output is
// 0
// 0 1
// 0 1 2
// 0 1 2 3

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
    vector<list <int> > adjList;
    list<int> mtLst;  // an empty list
/*
    for (int i=0; i<4; ++i)
    {
        adjList.push_back(mtLst); // push an empty list onto the adjList
        for (int j=0; j<=i; ++j)
            adjList[i].push_back(j);  // populate the list just pushed onto the vector

    }
*/


  string line;
  ifstream myfile ("graph.dat");
  int countV = 0, countL = 0;

      if (myfile.is_open())
      {
        //Iterate through vector:
        while ( getline (myfile,line) )
        {
          adjList.push_back(mtLst);
          istringstream iss(line);
          // Fill the linked list:
            do
            {
                string subs;
                //iss >> subs;
                //adjList[countV].push_back(subs);
                //cout << "Substring: " << subs; //put on list
                countL++;

                copy(istream_iterator<string>(iss),
                     istream_iterator<string>(),
                     back_inserter(adjList[countV]));

            }while(iss);

          cout << endl;
          countV++;
        }
        myfile.close();
      }

      else cout << "Unable to open file";

    //list<string>::iterator it;
    //for (it = adjList[12].begin(); it != adjList[12].end(); ++it){
    //    std::cout << *it;
    //}
    //std::list<string>::iterator nums=adjList[12].begin();
    //list<int> myList;
    //myList.begin() = *adjList[12].begin();
    //list<int>::iterator intIter;
    //cout << "Testing the function find_gt: ";
    //cout << *find_gt(adjList[12].begin(), adjList[12].end(), 3);
    return 0;
}

list<int>::iterator find_gt(list<int>::iterator start, list<int>::iterator stop,int x)
{
    std::list<int>::iterator temp = start;
    while(start != stop)
    {
        if(*start > x)
            return start;
    }
    return temp;
}
