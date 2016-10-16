#include <iostream>
#include <string>
#include <vector>
#include <queue>
#include <regex>
#include <tuple>
#include <set>
#include <array>
using namespace std;
 
class Board
{
public:
  vector<vector<char>> sData, dData;
  int px, py;
 
  Board(string b)
  {
    regex pattern("([^\\n]+)\\n?");
    sregex_iterator end, iter(b.begin(), b.end(), pattern);
 
    int w = 0;
    vector<string> data;
    for(; iter != end; ++iter){
      data.push_back((*iter)[1]);
      w = max(w, (*iter)[1].length());
    }
 
    for(int v = 0; v < data.size(); ++v){
      vector<char> sTemp, dTemp;
      for(int u = 0; u < w; ++u){
        if(u > data[v].size()){
          sTemp.push_back(' ');
          dTemp.push_back(' ');
        }else{
          char s = ' ', d = ' ', c = data[v][u];
 
          if(c == '#')
            s = '#';
          else if(c == '.' || c == '*' || c == '+')
            s = '.';
 
          if(c == '@' || c == '+'){
            d = '@';
            px = u;
            py = v;
          }else if(c == '$' || c == '*')
            d = '*';
 
          sTemp.push_back(s);
          dTemp.push_back(d);
        }
      }
 
      sData.push_back(sTemp);
      dData.push_back(dTemp);
    }
  }
 
  bool move(int x, int y, int dx, int dy, vector<vector<char>> &data)
  {
    if(sData[y+dy][x+dx] == '#' || data[y+dy][x+dx] != ' ') 
      return false;
 
    data[y][x] = ' ';
    data[y+dy][x+dx] = '@';
 
    return true;
  }
 
  bool push(int x, int y, int dx, int dy, vector<vector<char>> &data)
  {
    if(sData[y+2*dy][x+2*dx] == '#' || data[y+2*dy][x+2*dx] != ' ')
      return false;
 
    data[y][x] = ' ';
    data[y+dy][x+dx] = '@';
    data[y+2*dy][x+2*dx] = '*';
 
    return true;
  }
 
  bool isSolved(const vector<vector<char>> &data)
  {
    for(int v = 0; v < data.size(); ++v)
      for(int u = 0; u < data[v].size(); ++u)
        if((sData[v][u] == '.') ^ (data[v][u] == '*'))
          return false;
    return true;
  }
 
  string solve()
  {
    set<vector<vector<char>>> visited;
    queue<tuple<vector<vector<char>>, string, int, int>> open;
 
    open.push(make_tuple(dData, "", px, py));
    visited.insert(dData);
 
    array<tuple<int, int, char, char>, 4> dirs;
    dirs[0] = make_tuple(0, -1, 'u', 'U');
    dirs[1] = make_tuple(1, 0, 'r', 'R');
    dirs[2] = make_tuple(0, 1, 'd', 'D');
    dirs[3] = make_tuple(-1, 0, 'l', 'L');
 
    while(!open.empty())
	{
      vector<vector<char>> temp, cur = get<0>(open.front());
      string cSol = get<1>(open.front());
      int x = get<2>(open.front());
      int y = get<3>(open.front());
      open.pop();
 
      for(int i = 0; i < 4; ++i)
	  {
        temp = cur;
        int dx = get<0>(dirs[i]);
        int dy = get<1>(dirs[i]);
 
        if(temp[y+dy][x+dx] == '*')
		{
          if(push(x, y, dx, dy, temp) && (visited.find(temp) == visited.end()))
		  {
            if(isSolved(temp))
              return cSol + get<3>(dirs[i]);
            open.push(make_tuple(temp, cSol + get<3>(dirs[i]), x+dx, y+dy));
            visited.insert(temp);
          }
        }
		else if(move(x, y, dx, dy, temp) && (visited.find(temp) == visited.end()))
		{
          if(isSolved(temp))
            return cSol + get<2>(dirs[i]);
          open.push(make_tuple(temp, cSol + get<2>(dirs[i]), x+dx, y+dy));
          visited.insert(temp);
        }
      }
    }
 
    return "No solution";
  }
};
 
int main()
{
  string level =
    "#######\n"
    "#     #\n"
    "#     #\n"
    "#. #  #\n"
    "#. $$ #\n"
    "#.$$  #\n"
    "#.#  @#\n"
    "#######";
 
  Board b(level);
 
  cout<<level<<endl;
  cout<<"\n The solution is : \n";
  string temp = b.solve();
  cout<<temp<<endl;

  cin.get();
  cin.get();

  return 0;
}