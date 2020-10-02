// Problem: https://www.hackerrank.com/challenges/fraudulent-activity-notifications/problem
// Score: 40


#include <iostream>
#include <queue>
using namespace std;


class moving_median{
public:

    explicit moving_median(int target_size): target_size(target_size){}

    void add(int value){
        if (current_size < target_size){
            current_size++;
        }
        else {
            check_operation(value);
            arr[q.front()]--;
            q.pop();
        }

        arr[value]++;
        q.push(value);
    }

    int get_n_notifications(){
        return n_notifications;
    }


private:
    void check_operation(int value){
        if (value >= two_medians()) n_notifications++;
    };


    int find_i_element(int num){
        int count = 0;
        for (int i = 0; i < 201; i++){
            count += arr[i];
            if (count >= num) return i;
        }
        return 200;
    };


    int two_medians(){
        return (find_i_element(target_size / 2 + 1) + find_i_element(target_size / 2 + target_size % 2));
    };


    int n_notifications = 0;
    int target_size;
    int current_size = 0;
    int arr[201] = {0};
    queue<int> q;
};


int main(){
    int n, d;
    cin >> n >> d;

    moving_median data(d);

    for (int i = 0; i < n; i++){
        int tmp;
        cin >> tmp;
        data.add(tmp);
    }

    cout << data.get_n_notifications();
    return 0;
}
