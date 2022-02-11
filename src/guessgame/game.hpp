#pragma once
#include <string>

#define NUMBERS 4

using namespace std;

class GuessGame {
	private:
		int m_numbers[4];
	private:
		void init();
		bool guess(const int* numbers, const int* inputs, string& result);
	public:
		int run();
};
