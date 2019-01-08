#include <iostream>

using namespace std;

class Singleton {
	private:
		static bool instance_flag;
		static Singleton *instance;
		Singleton() {
		}
		
	public:
		static Singleton *get_instance();
		void my_method();
		~Singleton() {
			instance_flag = false;
		}
};


bool Singleton::instance_flag = false;
Singleton *Singleton::instance = NULL;

Singleton *Singleton::get_instance() {
	if (!instance_flag) {
		instance = new Singleton();
		instance_flag = true;
	}
	return instance;
}

void Singleton::my_method() {
	cout << "Samo sam jedan na svijetu i to na adresi: " << this << endl; 
}

int main() {
	Singleton *novi = Singleton::get_instance();
	novi->my_method();
}
