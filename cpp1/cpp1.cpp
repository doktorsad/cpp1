#include <iostream>
#include <fstream>

int *creat_array(std::fstream& in, int &size) {
    in >> size;
    int *array = new int[size];
    for (int i = 0; i < size; i++) {
        in >> array[i];
    }
    return array;
}


int main()
{
    int size_n = 0, size_m = 0;
    std::fstream in("in.txt");
    if (!in.is_open()) {
        std::cout << "fail <in.txt> is not open";
        exit(0);
    }
    int *n = creat_array(in, size_n);
    int *m = creat_array(in, size_m);
    in.close();
    std::fstream out;
    out.open("out.txt");
    if (!out.is_open()) {
        std::cout << "fail <out.txt> is not open";
        exit(0);
    }
    out << size_m << '\n' << m[size_m - 1] << ' ';
    for (int i = 0 ; i < size_m -1; i++){
        out << m[i] << ' ';
    }
    out << '\n' << size_n << '\n';
    for (int i = 1; i < size_n; i++) {
        out << n[i] << ' ';
    }
    out << n[0];
    out.close();
    delete[] n;
    delete[] m;
    return 0;
}

