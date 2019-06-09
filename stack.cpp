#include <iostream>
#include  <vector>
#include <Windows.h>
using namespace std;


class stack {

private:
	vector<int> v;

public:
	int temp;

	int pop() {
		if (v.empty()) {
			cout << "there is notting in stack";
			return 0;
		}else {
			temp = v.back();
			v.pop_back();
			return temp;
		}
	};
  
	void push() {
		int vin;
		cin >> vin;
		v.push_back(vin);
	};

	void show_stack() {
	};

}




int main() {
  stack s;
	int in;
	char menu;

	while (1) {

		cin >> menu;
		if (menu=='u') {
			s.push();
		}else if(menu =='o' ) {
			in = s.pop();
			cout << in;
	  }
  }	
	//system("pause");
	return 0;
}

