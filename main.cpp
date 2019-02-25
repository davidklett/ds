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

void printAdjList(vector<list<int>> adjList);

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
                    std::list<int>::iterator gt_iter = find_gt(adjList[countV].begin(),adjList[countV].end(), x);
                    //adjList[countV].push_back(x); //use insert and find_gt here?
                    //list<int>::insert(gt_iter, x);
                    adjList[countV].insert(gt_iter, x);
                }

          countV++;
        }
        myfile.close();
      }

      else cout << "Unable to open file";


    std::list<int>::const_iterator iterator;
    for(iterator = adjList[0].begin(); iterator != adjList[0].end(); ++iterator)
    {
        //std::cout << *iterator;
    }

    //test find_gt
    find_gt(adjList[0].begin(), adjList[0].end(), 3);

    //making final adjacency list:
     vector<list<int>> adjListFinal;
    list<int> myList;  // an empty list
    adjListFinal.push_back(myList);
    std::list<int>::iterator temp;
    temp = adjList[0].begin();
    //list::insert(temp, adjList[0].begin()); //not working!!!

    printAdjList(adjList);

    return 0;
}

list<int>::iterator find_gt(list<int>::iterator start, list<int>::iterator stop,int x)
{

  std::list<int>::iterator temp_iter;

  for(temp_iter = start; temp_iter != stop; ++temp_iter)
  {
        if(*temp_iter > x)
            return temp_iter;
  }

  return stop;

}

//print the adjacency list:
void printAdjList(vector<list<int>> adjList)
{
  int numRows = adjList.size();
  std::list<int>::iterator temp;
  for(int i = 0; i < numRows; i++)
  {
    for(temp = adjList[i].begin(); temp != adjList[i].end(); ++temp)
    {
      cout << *temp << " ";
    }

    cout << endl;
  }
}

bool connComponent(const list<int>& a, const list<int>& b)
{
  std::list<int>::iterator aIter = a.begin();
  std::list<int>::iterator bIter = b.begin();
  std::list<int>::iterator temp_iter1, temp_iter2;
  for(temp_iter1 = a.begin(); temp_iter != a.end(); ++temp_iter)
  {
    for(temp_iter2 = b.begin(); bIter != b.end(); ++bIter)
    {
      if(*temp_iter1 == *temp_iter2)
        return true;
    }
  }

  return false;
}

bool merge2(list<int> &a, list<int> &b)
{

}