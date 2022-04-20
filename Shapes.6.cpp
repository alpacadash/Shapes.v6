// Programmer: Younghyun Kwon
// Programmer's ID: 1651849
#include <iostream>
#include <iterator>
#include <string>
#include <sstream>
#include <vector>
#include <fstream>
#include <iomanip>
#include <cmath>
#include <cstdlib>
using namespace std;

#include "pShapes.h"

vector<string> parseString(string);
const vector<const Shape*> bag(ifstream&);

int main()
{
  cout << "Programmer: Younghyun Kwon\n";
  cout << "Programmer's ID: 1651849\n";
  cout << "File: " << __FILE__ << endl;
  ifstream fin;
  fin.open("Shapes.input.txt");
  const vector<const Shape*> bags = bag(fin);
  fin.close();
  for (unsigned int i = 0; i < bags.size(); i++)
  {
    cout << *bags[i];
  }
  ofstream fout;
  fout.open("Shapes.output.txt");
  for (unsigned int i = 0; i < bags.size(); i++)
  {
    fout << *bags[i];
  }
  fout.close();
  for (unsigned int i = 0; i < bags.size(); i++)
  {
    delete bags[i];
  }
}

vector<string> parseString(string str)
{
 stringstream s(str);
 istream_iterator<string> begin(s), end;
 return vector<string>(begin, end);
}

const vector<const Shape*> bag(ifstream& in)
{
  string shape;
  vector<string> tokens;
  const vector<const Shape*> myBag;
  while(!in.eof())
  {
    getline(in,shape);
    if(shape.find_first_not_of(" ") != string::npos)
    {
      tokens = parseString(shape);
      if(tokens[0] == "SQUARE")
      {
        const Square* const square = new Square(tokens);
        const_cast<vector<const Shape*>&>(myBag).push_back(square);
      }
      else if(tokens[0] == "RECTANGLE")
      {
        const Rectangle* const rectangle = new Rectangle(tokens);
        const_cast<vector<const Shape*>&>(myBag).push_back(rectangle);
      }
      else if(tokens[0] == "CIRCLE")
      {
        Circle* circle = new Circle(tokens);
        const_cast<vector<const Shape*>&>(myBag).push_back(circle);
      }
      else if(tokens[0] == "TRIANGLE")
      {
        const Triangle* const triangle = new Triangle(tokens);
        const_cast<vector<const Shape*>&>(myBag).push_back(triangle);
      }
      else if(tokens[0] == "CUBE")
      {
        const Cube* const cube = new Cube(tokens);
        const_cast<vector<const Shape*>&>(myBag).push_back(cube);
      }
      else if(tokens[0] == "BOX")
      {
        const Box* const box = new Box(tokens);
        const_cast<vector<const Shape*>&>(myBag).push_back(box);
      }
      else if(tokens[0] == "CYLINDER")
      {
        const Cylinder* const cylinder = new Cylinder(tokens);
        const_cast<vector<const Shape*>&>(myBag).push_back(cylinder);
      }
      else if(tokens[0] == "PRISM")
      {
        const Prism* const prism = new Prism(tokens);
        const_cast<vector<const Shape*>&>(myBag).push_back(prism);
      }
      else if(shape.compare("EOF") == 0) break;
      else{ cout << tokens[0] << " invalid object" << endl; }
    }
  }
  return myBag;
}
