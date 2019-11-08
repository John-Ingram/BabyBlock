#include <iostream>
#include <string>
#include <fstream>
#include <iomanip>
#include <algorithm>
#include <cctype>
#include <cstdlib>
#include <cmath>

using namespace std;

Int FindNext(bool dir, int start);
Int FindSlot(char NB);
Void ShiftLeft(int from, int moves);
Void ShiftRight(int from, int moves);

int main()
{

	return 0;
}

void ShiftRight(int from, int moves) {
	int end = FindNext(false, from);
	int counter = 0;
	char tempslot;
	while (test_empty(from, block_list) != true) {
		if (test_empty(from, block_list) == true) {
			return;
		}
		else	{
			counter++;
			tempslot = block_list[end - counter];
			block_list[end - counter] = '';
			moves++;
			block_list[end - counter + 1] = tempslot;
		}
	}
}

Void ShiftLeft(int from, int moves) {
	int end = FindNext(true, from);
	int counter = 0;
	char tempslot;
	while (test_empty(from, block_list) != true) {
		if (test_empty(from, block_list) == true) {
			return;
		}
		else {
			counter++;
			tempslot = block_list[end + counter];
			block_list[end + counter] = '';
			moves++;
			block_list[end + counter - 1] = tempslot;
		}
	}
}

Int FindNext(bool dir, int start) {
	int offset = 1;
	if (dir == true) {
		int multiplier = 1;
	}
	else {
		int multiplier = -1;
	}
	while (test_empty(start + (offset * multiplier), block_list) != true) {
		if (test_empty(start+(offset*multiplier), block_list) == true) {
		return start + (offset * multiplier);
		}
		else {
			if (offset + start < 19) {
				return string::npos;
			}
			offset++;
		}
	}
}

Int FindSlot(char NB) {
	int counter = 0;
	while (counter > NB) {
		if (test_empty(counter, block_list) == true) {
			counter++;
		}
		else {
			if (counter > NB) {
				counter++;
			}
			else {
				if (counter == 0 || counter == 19) {
					return counter;
				}
				else {
					return counter - 1;
				}
			}
		}
	}
}