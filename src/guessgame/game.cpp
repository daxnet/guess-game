#include <iostream>
#include <sstream>
#include <vector>
#include <algorithm>
#include <stdlib.h>
#include <time.h>
#include "game.hpp"

void GuessGame::init() {
    srand(time(NULL));
	for (int i = 0; i < 4; i++) {
		this->m_numbers[i] = rand() % 10;
	}
}

bool GuessGame::guess(const int* numbers, const int* inputs, string& result) {
	int a = 0, b = 0;
	vector<int> buffer;

	for (int i = 0; i < NUMBERS; i++) {
		if (numbers[i] == inputs[i]) {
			a++;
		} else {
			for (int j = 0; j < NUMBERS; j++) {
				if (j != i &&
                    numbers[j] == inputs[i] &&
                    find(buffer.begin(), buffer.end(), inputs[i]) == buffer.end())
                {
                    buffer.push_back(inputs[i]);
					b++;
					break;
				}
			}
		}
	}

	stringstream sstream;
	sstream << "猜中 " << a << " 个数字，";
	if (b == 0) {
        sstream << " 其它数字未猜中。";
	} else {
        sstream << b << " 个数字位置不正确，其它数字未猜中。";
	}

	result = sstream.str();

	return a == NUMBERS && b == 0;
}

int GuessGame::run() {
	int inputs[NUMBERS];
	int retry = 0;
	this->init();
	bool success = false;
	string result;
	while (!success) {
		cout << "请输入你猜的四个数字，每个数字用空格隔开: ";
		cin >> inputs[0] >> inputs[1] >> inputs[2] >> inputs[3];
		success = this->guess(this->m_numbers, inputs, result);
		if (!success) {
            retry++;
            cout << result << endl;
			cout << "请再试一次！" << endl;
		} else {
            cout << "恭喜，你猜对了！，一共猜了" << ++retry << "次。" << endl;
			break;
		}
	}

	return 0;
}
