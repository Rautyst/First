#include <iostream>
#include <fstream>
#include <vector>
#include <iomanip>
using namespace std;
typedef double T;
// Бинарный поиск границ в массиве
int left_boundary(T x, const vector<T>& A)
{
	int left = 0;
	while (left < int(A.size()) and A[left] < x) left++;
	return left;
}
int right_boundary(T x, const vector<T>& A)
{
	int right = int(A.size())-1;
	while (right > 0 and A[right] > x) right--;
	return right;
}
int binleft_boundary(T x, const vector<T>& A)
{
	int l = 0, r = int(A.size())-1;
	while (r - l > 1)
	{
		int middle = (r + l) / 2;
		if (middle >= x) r = middle;
		else l = middle;
	}
	return l;
}
int binright_boundary(T x, const vector<T>& A)
{
	int l = 0, r = int(A.size()) - 1;
	while (r - l > 1)
	{
		int middle = (r + l) / 2;
		if (middle <= x) l = middle;
		else r = middle;
	}
	return r;
}
void binSearch_for_boundaries_in_vector()
{
	T x; vector<T> A = { 2,2,2,3,3,3,5,5,5,5,5,6,7,7,9,9 }; // Объявление значения для поиска и массива для поиска
	cout << "What to find? x = "; cin >> x;
	int left = left_boundary(x, A); int right = right_boundary(x, A);
	cout << "Noob finder give answer: "
		 << '[' << left << ';' << right << ']' << '\n';
	int binleft = binleft_boundary(x, A); int binright = binright_boundary(x, A);
	cout << "Binsearch finder give answer: "
		<< '[' << left << ';' << right << ']' << '\n';
}
//Бинарный поиск корня в функции f(x)
double f(double x)
{
	return (x - 2.21313) * (x - 7);
}
void binSearch_root()
{
	double a, b; cout << "Enter boundaries [a,b]: "; cin >> a >> b;
	double ERROR; cout << "Enter error: "; cin >> ERROR;
	if (f(a) * f(b) < 0) {
		while ((b - a) / 2. > ERROR) {
			double c = (a + b) / 2;
			if (f(c) == 0) {
				cout << "OMG!!! 1001% answer is: " << c << '\n';
			}
			if (f(a) * f(c) <= 0) b = c;
			else a = c;
		}
		cout << "Answer is: " << setprecision(17) << (a + b) / 2 << '\n';
	}
	else { cout << "Cant use binsearch of root bcs f(a) * f(b) >= 0\n"; }
}
//Действия с массивом
void print_vector(const vector<int>& A)
{
	for (int i = 0; i < int(A.size()); i++)
	{
		cout << A[i] << ',';
	}
	cout << '\n';
}
void shift_right(vector<int>& A)
{
	int x = A[A.size()-1];
	for (int i =int(A.size()) - 1; i > 0; i--)
	{
		A[i] = A[i - 1];
	}
	A[0] = x;
}
void shift_left(vector<int>& A)
{
	int x = A[0];
	for (int i = 0; i < int(A.size())-1; i++)
	{
		A[i] = A[i + 1];
	}
	A[A.size()-1] = x;
}
void reverse(vector<int>& A)
{
	int N = int(A.size());
	for (int i = 0; i <= N/2; i++)
	{
		int x = A[i];
		A[i] = A[N - i - 1];
		A[N - i - 1] = x;
	}
}
//Решение 27 задачи ЕГЭ змейкой
void zmeyka27() {
	const int Q_size = 5;
	int Q[Q_size];
	for (int i = 0; i < Q_size; i++)
	{
		cin >> Q[i];
	}
	int Q_end = 0, max_from_before = -1, N = 15, max_sum = -1;
	for (int i = Q_size; i < N; i++)
	{
		int current, number_leaving_queue = Q[Q_end];
		cin >> current;
		Q[Q_end++] = current;
		if (max_sum < current + max_from_before) max_sum = current + max_from_before;
		if (Q_end == Q_size) Q_end = 0;
		if (number_leaving_queue > max_from_before) max_from_before = number_leaving_queue;
	}
	cout << max_sum << '\n';
}
//Попытка в структуры и оператор
//задача с нахождением ЛЮДЕЙ с максимальным количеством возрастов
struct Person {
	int age;
	string name;
};
ostream& operator << (ostream& out, Person& one) {
	out << '[' << one.name << ']';
	return out;
}
void poisk()
{
	int N; cin >> N;
	vector<int> ages_count(101);
	vector<Person> crowd(N);
	for (int i = 0; i < N; i++)
	{
		Person one;
		cin >> one.name >> one.age;
		crowd[i] = one;
		ages_count[one.age]++;
	}
	int max_count = -1, max_age=0;
	for (int i = 0; i < 101; i++)
	{
		if (ages_count[i] > max_count) {
			max_count = ages_count[i];
			max_age = i;
		}
		//cout << ages_count[i] << '\n';
	}
	for (int i = 0; i < N; i++) {
		if (crowd[i].age == max_age) cout << crowd[i] << '\n';
	}
}
//Проверка на правильность написания разных видов скобок в матем. варажении. Использование СТЕК'а
void skobki()
{
	string a; vector<char> A(10);int THE_END = 0; 
	cout << "Enter the virajenie: ";cin >> a; 
	bool f = 1;
	for (int i = 0; a[i] != '\0'; i++)
	{
		switch (a[i])
		{
		case '[':
			A[THE_END++] = a[i];
			break;
		case '(':
			A[THE_END++] = a[i];
			break;
		case '{':
			A[THE_END++] = a[i];
			break;
		case ')':
			if (A[THE_END - 1] == '(') { A[--THE_END] = '0'; }
			else { f = 0; }
			break;
		case ']':
			if (A[THE_END - 1] == '[') {A[--THE_END] = '0';}
			else { f = 0; }
			break;
		case '}':
			if (A[THE_END - 1] == '[') { A[--THE_END] = '0'; }
			else { f = 0; }
			break;
		default:
			break;
		}
		if (f == 0) {
			cout << "\nERROR SYNTAX ";
			break;
		}
	}
	if (THE_END != 0) { cout << "ERROR\n"; }
	else { cout << "\nCORRECT\n"; }
}
int main()
{
	return 0;
}
