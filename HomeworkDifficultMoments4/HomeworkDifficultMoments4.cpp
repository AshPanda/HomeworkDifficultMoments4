/*
1. Имеется отсортированный массив целых чисел. Необходимо разработать функцию
insert_sorted, которая принимает вектор и новое число и вставляет новое число в
определенную позицию в векторе, чтобы упорядоченность контейнера сохранялась.
Реализуйте шаблонную функцию insert_sorted, которая сможет аналогично работать с любым
контейнером, содержащим любой тип значения.
2. Сгенерируйте вектор a, состоящий из 100 вещественный чисел, представляющий собой
значения аналогового сигнала. На основе этого массива чисел создайте другой вектор целых
чисел b, представляющий цифровой сигнал, в котором будут откинуты дробные части чисел.
Выведите получившиеся массивы чисел. Посчитайте ошибку, которой обладает цифровой
сигнал по сравнению с аналоговым по формуле:
,
𝑖=0
𝑁−1
Σ (𝑎𝑖 − 𝑏𝑖)2
где:
N - количество элементов в векторе,
a - элемент вектора с дробными числами,
b - элемент вектора с целыми числами
Постарайтесь воспользоваться алгоритмическими функциями, не используя циклы.
*/

#include <iostream>
#include <vector>
#include <iomanip>
#include <algorithm>
#include <ctime>
#include <cstdlib>


using namespace std;


//Task #1
template< typename T >
typename vector<T>::iterator
insert_sorted(vector<T>& task1vector, T const& item)
{
    return task1vector.insert
    (
        upper_bound(task1vector.begin(), task1vector.end(), item),
        item
    );
}
//Task #2

void error(int n, vector<double>& task2vector, vector<int>& task22vector)
{
    double sum = 0.0;
    for (int i = 0; i < n; ++i)
    {
        double e = task2vector[i] - task22vector[i];
        sum += e * e;
    }
    cout << sum << endl;
}


int main()
{
    cout << "Task #1" << endl;
    vector<int> task1(10);
    srand(static_cast <unsigned> (time(0)));
    generate(task1.begin(), task1.end(), []() {return (rand() % 150); });
    sort(task1.begin(), task1.end());
    cout << "Sorted vector: " << endl;
    for (int value : task1) {
        cout << value << " ";
    }
    cout << "\n" << endl;
    insert_sorted(task1, 77);
    cout << "Sorted vector with additional number 77: " << endl;
    for (int value : task1) {
        cout << value << " ";
    }
    cout << "\n" << endl;
    cout << "Task #2" << endl;
    cout << "First vector:" << endl;
    int size = 100;
    vector<double> task2(size);

    generate(task2.begin(), task2.end(), []() {return ((double)rand() / (double)(RAND_MAX/150-0)); });
    for (double value : task2) {
        cout << fixed <<setprecision(2) << setw(7) <<value << " ";
    }
    cout << "\n" << endl;
    cout << "Second vector:" << endl;
    vector<int> task22(100);
    copy(task2.begin(), task2.end(), task22.begin());
    for (int value : task22) {
        cout  << setw(7) << value << " ";
    }
    cout << "\n" << endl;
    cout << "Error:" << endl;
    error(size, task2, task22);
}

