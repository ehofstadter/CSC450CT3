#include <iostream>
#include <new>

int main(){

	int firstNum = 0;
	int secondNum = 0;
	int thirdNum = 0;

	std::cout<<"Please begin by entering three valid integers.\n";

	firstNum = retrieveValidatedInt("Enter the first integer: ");
	secondNum = retrieveValidatedInt("Enter the second integer: ");
	thirdNum = retrieveValidatedInt("Enter the third integer: ");

	int*ptr1 = nullptr;
	int*ptr2 = nullptr;
	int*ptr3 = nullptr;

	std::cout<<"\nAllocating dynamic memory pointers for each integer...";
	try {
		ptr1 = new int(firstNum);
		ptr2 = new int(secondNum);
		ptr3 = new int(thirdNum);
		std::cout<<"\n...dynamic memory allocated!\n";
	}
	catch (const std::bad_alloc& e){
		std::cerr<<"ERROR: Dynamic memory allocation failed: " <<e.what()<< "\n";
		deallocate(ptr1);
		deallocate(ptr2);
		deallocate(ptr3);
		return 1;
	}

	std::cout<<"\nDisplaying each variable with stack address, pointer value, and dereferenced pointer.\n";

	std::cout<< "Variable one: "<< firstNum << "; " << &firstNum << "; " << ptr1 << "; " << *ptr1 << ".\n";
	std::cout<< "Variable two: "<< secondNum << "; " << &secondNum << "; " << ptr2 << "; " << *ptr2 << ".\n";
	std::cout<< "Variable three: "<< thirdNum << "; " << &thirdNum << "; " << ptr3 << "; " << *ptr3 << ".\n";

	std::cout<<"\nDeleting pointers to deallocate memory...";
	deallocate(ptr1);
	deallocate(ptr2);
	deallocate(ptr3);

	if(ptr1 == nullptr && ptr2 == nullptr && ptr3 == nullptr){
		std::cout<<"\n...all gone!";
	}

}
int retrieveValidatedInt(const std::string& prompt) {
	int value = 0;
	while (true){
		std::cout << prompt;
		if (std::cin>>value) {
			if (std::cin.peek() == '\n' || std::cin.peek() == ' '){
				return value;
			}
		}

		std::cout << "ERROR: Invalid integer input or overflow.\n";
		std::cin.clear();
		std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
	}
}

void deallocate(int*& ptr) {
	if(ptr != nullptr){
		delete ptr;
		ptr = nullptr;
	}
}


