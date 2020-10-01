// Problem: https://www.hackerrank.com/challenges/frequency-queries/problem
// Score: 40


#include <map>
using namespace std;


struct default_long_long_int{
    int value = 0;
};


struct custom_struct{
public:
    void insert(int num){
        arr[num].value++;
        frequencies[arr[num].value].value++;
        frequencies[arr[num].value - 1].value--;
    }

    void remove(int num){
        if (arr[num].value != 0){
            arr[num].value--;
            frequencies[arr[num].value].value++;
            frequencies[arr[num].value + 1].value--;
        }

        if (arr[num].value == 0){
            arr.erase(num);
        }
    };

    int check(int value){
        if (frequencies[value].value != 0) return 1;
        else return 0;
    }

private:
    map<int, default_long_long_int> arr;
    map<int, default_long_long_int> frequencies;
};


int main(){
    int q;
    scanf("%d",&q);
    custom_struct arr;

    for (int i = 0; i < q; i++){
        int command, value;
        scanf("%d",&command);
        scanf("%d",&value);

        if (command == 1){
            arr.insert(value);
        }
        if (command == 2){
            arr.remove(value);
        }
        if (command == 3){
            printf("%d \n", arr.check(value));
        }
    }
    return 0;
}
