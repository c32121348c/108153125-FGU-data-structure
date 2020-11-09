#include <iostream>

using namespace std;

int a[3][3] = {{11, 22, 33},{44, 55, 66},{77, 88, 99}};

int get(int i, int j){
    i--;
    j--;
    return *(*a+(i*3)+j);
}
void set(int i, int j, int v){
    i--;
    j--;
    *(*a+(i*3)+j) = v;
}
void dump(){
        cout << "已知二維陣列 轉 一維陣列 = ";
        cout << endl;
        for(int i=0; i<sizeof(a)/sizeof(int); i++){
            cout << *(*a+i) << " ";
        }
        cout << endl;
    }

int main(){
    dump();
    cout << "get(2, 2) 第2列 第2行 = " << get(2, 2) << endl;
    set(2, 2, 99);
    cout << "set(2, 2, 99) 變更第2列 第2行 = " << get(2, 2) << endl;
}