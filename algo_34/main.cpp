#include <iostream>
#include <bits/stdc++.h>

using namespace std;

//class Vector2D {
//public:
//    vector<int> array;
//    int pos = -1;
//      //构造函数复杂度比较高
//    Vector2D(vector<vector<int>> &vec) {
//        for (const auto &row: vec) {
//            for (const auto &key: row) {
//                array.push_back(key);
//            }
//        }
//    }
//
//    int next() {
//        if (hasNext()) {
//            return array[++pos];
//        }
//        return -1;
//    }
//
//    bool hasNext() {
//        if (pos + 1 >= array.size()) {
//            return false;
//        }
//        return true;
//    }
//};

//内外双指针
//外部指向一维数组
//内部指向一维数组的元素


class Vector2D {
private:
    vector<vector<int>> vec;
    int outer;
    int inner;
public:
    Vector2D(vector<vector<int>> &vec) {
        this->vec = vec;
        this->outer = 0;
        this->inner = 0;//使用后在加一
    }

    //移动指针直到有元素为止
    void advanceNext() {
        if (outer < vec.size() && inner < vec[outer].size()) {
            return;
        }
        inner = 0;
        outer++;
        while (outer < vec.size() && inner >= vec[outer].size()) {
            outer++;
        }
    }

    int next() {
        advanceNext();
        if (outer < vec.size()) {
            return vec[outer][inner++];
        }
        return -1;
    }

    bool hasNext() {
        advanceNext();
        if (outer >= vec.size()) {
            return false;
        }
        return true;
    }

};


int main() {
    vector<vector<int>> v = {{1, 2},
                             {3},
                             {4}};
    Vector2D vector2D = Vector2D(v);
    cout << vector2D.next() << "\n";
    cout << vector2D.next() << "\n";
    cout << vector2D.next() << "\n";
    cout << vector2D.hasNext() << "\n";
    cout << vector2D.hasNext() << "\n";
    cout << vector2D.next() << "\n";
    cout << vector2D.hasNext() << "\n";

    return 0;
}
