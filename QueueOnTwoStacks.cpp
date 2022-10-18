#include <iostream>
#include <stack>

template <class T>
class QueueOnTwoStacks {
	std::stack <T> steck1, steck2;
public:
	QueueOnTwoStacks() {}

	QueueOnTwoStacks(const T& other)
		:steck1(other.steck1), steck2(other.steck2) {
	}

	QueueOnTwoStacks operator=(const QueueOnTwoStacks& other) {
		steck1 = other.steck1;
		steck2 = other.steck2;
	}

	int size() {
		return steck1.size() + steck2.size();
	}

	bool IsEmpty() {
		return (steck1.empty() && steck2.empty());
	}

	void push(const T& value) {
		steck1.push(value);
	}

	void pop() {
		if (size() == 0)
			throw "ERROR: this steck is empty";
		else {
			if (steck2.size() == 0) {
				while (!steck1.empty()) {
					steck2.push(steck1.top());
					steck1.pop();
				}
			}
			steck2.pop();
		}
	}

	T back() {
		if (size() == 0) {
			throw "ERROR: this steck is empty";
			return T();
		}
		else {
			if (steck1.size() == 0) {
				while (!steck2.empty()) {
					steck1.push(steck2.top());
					steck2.pop();
				}
			}
			return steck1.top();
		}
	}

	T front() {
		if (size() == 0) {
			throw "ERROR: this steck is empty";
			return T();
		}
		else {
			if (steck2.size() == 0) {
				while (!steck1.empty()) {
					steck2.push(steck1.top());
					steck1.pop();
				}
			}
			return steck2.top();
		}
	}
};

int main() {
	QueueOnTwoStacks<int> other;

	for (int count = 0; count < 100; count++) {
		other.push(count);
	}

	if (other.IsEmpty())
		std::cout << "YES" << std::endl;
	else
		std::cout << "NOUP" << std::endl;

	for (int count = 0; count < 100; count++) {
		std::cout << other.front() << "\t";
		other.pop();
	}

	std::cout << std::endl;

	QueueOnTwoStacks<int> other2;
	for (int count = 0; count < 100; count++) {
		other2.push(count);
	}

	if (other2.IsEmpty())
		std::cout << "YES" << std::endl;
	else
		std::cout << "NOUP" << std::endl;

	for (int count = 0; count < 10; count++) {
		std::cout << other2.back() << std::endl;
		other2.push(count + 1000);
	}
}
