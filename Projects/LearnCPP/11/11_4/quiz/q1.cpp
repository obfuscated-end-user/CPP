// https://www.learncpp.com/cpp-tutorial/sorting-an-array-using-selection-sort/

/*
Manually show how selection sort works on the following array: { 30, 60, 20, 50, 40, 10 }. Show the array after each swap that takes place.
*/

int main() {
    int array[] { 30, 60, 20, 50, 40, 10 };
    int smaller {};
    for (int i = 1; i < 5; ++i) {
        for (int j = i+1; j < 5; ++j)
    }

    return 0;
}

/*
lol you need to write any kind of code fucking retard
30 60 20 50 40 10
10 60 20 50 40 30
10 20 60 50 40 30
10 20 30 50 40 60
10 20 30 40 50 60
10 20 30 40 50 60 (self-swap)
10 20 30 40 50 60 (self-swap)
*/