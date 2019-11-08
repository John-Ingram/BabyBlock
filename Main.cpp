//
//John Ingram
//
#include <iostream>
#include <fstream>
#include <iomanip>
#include <string>

using namespace std;


int main(void)
{
    unsigned int position = 10;
    char chars[20] = {};
    char robot;

    //initial setup
    for(int i = 0; i < 20; i++) chars[i] = NULL;

    // place first block
    robot = get_block();
    put_block(robot, position, chars);

    
    

	
	system("pause");
	return 0;
}





// ------------------------------------------------------------------------ //
//																			//
//																			//
//				Instructor provided Functions for robot operations			//
//																			//
//																			//
// ------------------------------------------------------------------------ //

//
// Function get_block
// Reads in a single character value from the keyboard 
// This is the input from the chute
// Returns: a single character in uppercase
//
// Example function call: 	block = get_block();

char get_block(void)
{
	char block;
	cout << "Enter one block: ";
	cin >> block;
	return toupper(block);
}
//
// Function print_slots
// Prints the contents of the slots array in a well formatted form.
// Input: Array of slots
// Returns: Nothing (void)
//
// Example function call: print_slots(slot_array);

void print_slots(char slots[])
{
	unsigned int j = 1;
	for (j = 1; j <= 20; j++)
	{
		cout << setw(3) << j;
	}
	cout << endl;
	for (j = 0; j < 20; j++)
	{
		cout << setw(3) << slots[j];
	}
	cout << endl;
}

// Function put_block
// This function stores a character into the character array representing the slots
//
// Inputs: 
// block - type char - The character to be inserted into a slot
// position - type unsigned int - index of the slot where the block will go
// array - type char - array of slots containing the blocks
//
// Returns:
// position - type unsigned int - the index of the slot where the block was placed
//
// Example function call: 	put_block(block, position, slots);

unsigned int put_block(char block, unsigned int position, char array[])
{
	bool debug = true;
	array[position] = block;
	if (debug)
		cout << "Block " << block << " inserted into slot " << position << endl;
	return position;
}

// Function remove_block
// This function removes a block from the slot array
// The slot where the block is removed is then set to a space
//
// Inputs: 
// position - type unsigned int - index of the slot where block is located
// array - type char - array of slots containing the blocks
//
// Returns:
// block - type char - the block removed from the slot
//
// Example function call: 	remove_block(position, slots);

unsigned int remove_block(unsigned int position, char array[])
{
	bool debug = true;
	char block = ' ';
	block = array[position];
	array[position] = ' ';  // Reset slot to blank after block removed
	if (debug)
		cout << "Block " << block << " removed from slot " << position + 1 << endl;
	return block;
}


// Function shift_right
// This function increments the index simulating a movement of the robot 
// to the next higher slot (index) of the array
// 
// Inputs:
// position - type unsigned int - current slot position
//
// Returns:
// position - type unsigned int - The updated position which is input position + 1
//
// Example function call:  position = shift_right(position)
//

unsigned int shift_right(unsigned int position)
{
	bool debug = true;
	if(position < 19) 
	{
		position++;
		if (debug)
			cout << "Position right shifted to " << position << endl;
	}
	return position;
}

// Function shift_left
// This function decrements the index simulating a movement of the robot 
// to the next lower slot (index) of the array
// 
// Inputs:
// position - type unsigned int - current slot position
//
// Returns:
// position - type unsigned int - The updated position which is input position - 1
//
// Example function call: position = shift_left(position)
//

unsigned int shift_left(unsigned int position)
{
	bool debug = true;
	if(position > 0) position--;
	{
		if (debug)
			cout << "Position left shifted to " << position << endl;
	}
	return position;
}

// Function robot_ltoreq_slot
// This function compares the value of the block held by the robot 
// with the value of the block in a slot 
// 
// Inputs:
// robot - type char - value of block held by robot
// in_slot - type char - value of block in the slot
//
// Returns:
// true or false
// TRUE if block held by robot is LESS than or equal to the block in slot
// FALSE if block held by robot is GREATER than block in slot
//
// Example function call: if ( compare_blocks(robot_block, slot_block) )
//
bool robot_ltoreq_slot(char robot, char in_slot)
{
	bool debug = true;
	if (debug)
		cout << endl <<  "Comparing robot block " << robot << " with block in slot " << in_slot << endl;
	if (robot <= in_slot)
	{
		if (debug)
			cout << "Returning true. Robot block LESS than or EQUAL to block in slot. " << endl;
		return true;
	}
	else
	{
		if (debug)
			cout << "Returning false. Robot block GREATER than block in slot. " << endl;
		return false;
	}
}
// Function switch_blocks
// This function switches the block held by the robot with a block in a slot. 
// After the switch the robot is holding the block removed from the slot.
// 
// Inputs: 
// robot - type char - The block to be inserted into a slot
// position - type unsigned int - index of the slot where the block will go
// array - type char - array of slots containing the blocks
//
// Returns:
// robot - type char. The value of the block removed from the slot.
//
// Example function call: block = switch_blocks(block,  position, array);
//

char switch_blocks(char robot, unsigned int position, char array[])
{
	char temp_hold;
	bool debug = true;
	if (debug)
		cout << "Switching blocks " << robot << " with " << array[position] << endl;
	temp_hold = robot;
	robot = array[position];
	array[position] = temp_hold;
	return robot;
}
// Function test_empty
// This function tests the array to determine if a slot is empty (NULL) 
// or if the slot contains a blank. The slot array must be intialized to 
// all NULL or all blanks (spaces) before any blocks are added.
// 
// Inputs:
// position - type unsigned int - index of slot to be tested
//
// Returns:
// true or false as value o function
// TRUE if slot is empty
// FALSE if the slot contains a block
//
// Example function call: if ( test_empty(index, array) )
//
bool test_empty(unsigned int position, char array[])
{
	char blank = ' '; // Blank space
	bool debug = true;
	if  (array[position] == NULL || array[position] == blank)
	{
		if (debug)
			cout << "Slot " << position << " empty. " << endl;
		return true;
	}
	else
	{
		if (debug)
			cout << "Slot " << position << " contains a block " << endl;
		return false;
	}

}

// ------------------------------------------------------------------------ //
//																			//
//																			//
//				Functions for robot test cases								//
//																			//
//																			//
// ------------------------------------------------------------------------ //

//
// Function get_block_testcase
// Returns blocks for a given test case one at a time
// This function can be used for all five test cases.
//
// Input: Unsigned int case designating test case 1-5.
// Input: Index of letter desired 0 - 19.
// Returns: a single uppercase character
//
// Example function call: 	block = get_block_testcase(1, 0);
// Returns first letter of test case 1.

char get_block_testcase(unsigned int testcase, unsigned int index)
{
	string testcases[5] = { "AXFIUTRPQVWSEYJINYTB",
		"ABFGHIJKMOPRSTUVWXYZ",
		"ZYXWVUTSRPOKJIIHGFBA",
		"AAAAAYYYYYQQQQQXXXXX",
		"XXXAAAZZZAAYYVVVVQQQ" };

	return testcases[testcase - 1].at(index);
}


//
// Function get_block_testone
// Returns blocks for test case one one at a time
// Returns: a single character
//
// Example function call: 	block = get_block_testone();

char get_block_testone(void)
{
	static unsigned int index = 0;
	char test_case_one[21] = "AXFIUTRPQVWSEYJINYTB";
	return test_case_one[index++];
}



//
// Function get_block_testtwo
// Returns blocks for test case two one at a time
// Returns: a single character
//
// Example function call: 	block = get_block_testtwo();

char get_block_testtwo(void)
{
	static unsigned int index = 0;
	char test_case_two[21] = "ABFGHIJKMOPRSTUVWXYZ";
	return test_case_two[index++];
}

//
// Function get_block_testthree
// Returns blocks for test case three one at a time
// Returns: a single character
//
// Example function call: 	block = get_block_testthree();

char get_block_testthree(void)
{
	static unsigned int index = 0;
	char test_case_three[21] = "ZYXWVUTSRPOKJIIHGFBA";
	return test_case_three[index++];
}
//
// Function get_block_testfour
// Returns blocks for test case four one at a time
// Returns: a single character
//
// Example function call: 	block = get_block_testfour();

char get_block_testfour(void)
{
	static unsigned int index = 0;
	char test_case_four[21] = "AAAAAYYYYYQQQQQXXXXX";
	return test_case_four[index++];
}

//
// Function get_block_testfive
// Returns blocks for test case five one at a time
// Returns: a single character
//
// Example function call: 	block = get_block_testfive();

char get_block_testfive(void)
{
	static unsigned int index = 0;
	char test_case_five[21] = "XXXAAAZZZAAYYVVVVQQQ";
	return test_case_five[index++];
}


// Functions

bool robot_gtoreq_slot(char robot, char in_slot)
{
	bool debug = true;
	if (debug)
		cout << endl <<  "Comparing robot block " << robot << " with block in slot " << in_slot << endl;
	if (robot >= in_slot)
	{
		if (debug)
			cout << "Returning true. Robot block LESS than or EQUAL to block in slot. " << endl;
		return true;
	}
	else
	{
		if (debug)
			cout << "Returning false. Robot block GREATER than block in slot. " << endl;
		return false;
	}
}

// returns -1 when 'robot' is < 'in_slot'
// returns 0 when 'robot' is == 'in_slot'
// returns 1 when 'robot' is > 'in_slot'

int compareBlocks(char robot, char in_slot) 
{
	if(robot_ltoreq_slot(robot, in_slot) == true)
	{
		if(robot_gtoreq_slot(robot, in_slot) == true) return 0;
	}
}

//finds a valid spot for 'block' in 'array' and moves the robot there
unsigned int findSpot(char block, char array[], unsigned int position) 
{
	position = move_to(0, position);
	while(true)
	{
		if (test_empty(position, array))
		{
			position = shift_right(position);	
		} else if (compareBlocks(block, array[position]) == 0)// IF block is same as one in slot
		{
			return position;
		} else if ((compareBlocks(block, array[position]) == -1)) // IF block is less than one in slot
		{
			if (position == 0) return position;
			else return position - 1;
		} else // IF block is greater than one in slot
		{
			shift_right(position); 
		}
		
	}
	return position;
}

unsigned int move_to(unsigned int target, unsigned int position) // input must be =<19 and >=0
{
	while(true)
	{
		if(target < position) position = shift_left(position);
		else if(target > position) position = shift_right(position);
		else return position;
	}
}

unsigned int nextEmpty(unsigned int position, char array[])// moves the robot to the nearest empty slot
{
	unsigned int nextLeft, nextRight, oldPosition = position;
	//Look to the left
	while (!test_empty(position, array) || position == 0)
	{
		position = shift_left(position);
	}
	if(test_empty(position, array)) nextLeft = position;
	else nextLeft = 9999;
	//reset position
	position = move_to(oldPosition, position);
	//Look to the right
	while (!test_empty(position, array) || position == 19)
	{
		position = shift_right(position);
	}
	if(test_empty(position, array)) nextRight = position;
	else nextRight = 9999;
	
	// Calculate the smaller distance, and move there
	if(nextLeft == 9999) 
	{
		position = move_to(nextRight, position);
		return position;
	}

	if(nextRight == 9999) 
	{
		position = move_to(nextLeft, position);
		return position;
	}

	unsigned int deltaLeft = oldPosition - nextLeft;
	unsigned int deltaRight = nextRight - oldPosition;

	if (deltaLeft < deltaRight) position = move_to(nextLeft, position);
	if (deltaLeft > deltaRight) position = move_to(nextRight, position);
	return position;
}

