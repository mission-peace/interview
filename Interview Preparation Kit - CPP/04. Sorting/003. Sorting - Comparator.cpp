// Problem: https://www.hackerrank.com/challenges/ctci-comparator-sorting
// Score: 35


#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
using namespace std;

class player {
public:
    player(string name, int score): name_(name), score_(score){}

    string get_name() const{
        return name_;
    }

    int get_score() const{
        return score_;
    }

    void print() const{
        cout << name_ << " " << score_ << '\n';
    }

private:
    string name_;
    int score_;
};


bool compare_players(player const & p1, player const & p2){
    if (p1.get_score() > p2.get_score()) return true;
    else if (p1.get_score() == p2.get_score()) return p1.get_name() < p2.get_name();
    else return false;
}


int main(){
    int n;
    cin >> n;

    vector<player> arr;

    for (int i = 0; i < n; i++){
        string name;
        int score;
        cin >> name >> score;
        player tmp(name, score);
        arr.push_back(tmp);
    }

    sort(arr.begin(), arr.end(), compare_players);

    for (player const & el: arr){
        el.print();
    }

    return 0;
}
