#include<bits/stdc++.h>
#include<unordered_map>
#include<unordered_set>
using namespace std;
class Student {
public:
	int* grade;
	Student(int g) {
		grade = new int(g);
	}
};

class Student1 {
public:
	int* grade;
	Student1(Student1& student) {
		grade = new int(*student.grade);
	}
};
int main() {
	Student a(90);
	Student b = a; //shallow copy
	cout <<a.grade <<" " << *a.grade << endl;
	cout <<b.grade<<" "<< * b.grade << endl;
	*b.grade = 50;
	cout << a.grade << " " << *a.grade<<endl;
	cout << b.grade << " " << *b.grade<<endl;


	int c = 20, c1 = 30;
	cout << &c << " " << &c1 << endl;
	c = c1; //assignment here means copy the values
	cout << &c << " " << &c1 << endl;


	int* p1 = new int(20);
	cout << p1 << " " << *p1;









	unordered_map<int, int>mp;
mp[1]++;
mp[2]++;
mp[3]++;
auto iterator = mp.find(1);

int cnt = mp.count(1);
cout << cnt<< endl;
cout << iterator->first << " " << iterator->second;
cout << (*iterator).first  <<" " << (*iterator).second << endl;
}