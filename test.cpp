// #include<iostream>
// using namespace std;

// void f(int x, int y) {
//     if (x > 0, y > 0) {
//         cout << x << " ";
//         f(x - 2, y);
//          cout << x << " ";
//          cout << y << " ";
//     }
// }

// int main(){
//    cout << "===== Student Management System =====" << endl; 
//   f(10, 5);
//  return 0;
//  }


// #include<iostream>
// using namespace std;

    
// void Updatefn(int x)
// {
// x = x + 2;
// }
// int main() {
// int a = 5;
// Updatefn(a);
// cout << a;
// }

#include<iostream>
using namespace std;

void Updatefn(int x, int y)
{
    x = y+2;
    y = x+20;
}

int main() {
    int a = 5;
    int b = 3;
    // cout << a+10;
    
    cout << a << " " << b;
    Updatefn(a,b);
}

