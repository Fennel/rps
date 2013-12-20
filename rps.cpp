#include <iostream>
#include <stdio.h>

//some modification
<<<<<<< HEAD
<<<<<<< HEAD
//new line is new
=======
//this code needs to be rewritten
>>>>>>> upstream/master
using namespace std;
=======
>>>>>>> upstream/master

class Tool {
	int strength;
protected:
	char type;
public:
	void setStrength(int strength){
		this->strength = strength;
	};
	bool fight(Tool);
	char get_type(){
		return type;
	}
};
using namespace std;
const char* stringify(Tool* pt){
	char type = pt->get_type();
	const char* result;
	switch(type){
		case 'r':
			result = "Rock";
			break;
		case 'p':
			result = "Paper";
			break;
		case 's':
			result = "Scissors";
			break;
		default:
			break;
	}
	return result;
}

bool Tool::fight(Tool t){
	printf("Before bonus: %s %d VS %s %d\n",stringify(this),strength,stringify(&t),t.strength);
	
	int tmp = strength;
	if(type == 'r'){
		if(t.type == 's')
			tmp *= 2;
		else if(t.type == 'p')
			tmp /= 2;
	}
	if(type == 'p'){
		if(t.type == 's')
			tmp /= 2;
		else if(t.type == 'r')
			tmp *= 2;
	}
	if(type == 's'){
		if(t.type == 'p')
			tmp *= 2;
		else if(t.type == 'r')
			tmp /= 2;
	}
	printf("After bonus: %s %d VS %s %d\n",stringify(this),tmp,stringify(&t),t.strength);
	bool result = tmp > t.strength;
	/*
	if(result){
		cout << "WIN" << endl;
	}else{
		cout << "LOSE" << endl;
	}*/
	//cout << result << endl;
	return result;
}

/*
	Implement class Scissors
*/
class Scissors : public Tool{
public:
	Scissors(int strength){
		setStrength(strength);
		type = 's';
	};
};

/*
	Implement class Paper
*/
class Paper : public Tool{
public:
	Paper(int strength){
		setStrength(strength);
		type = 'p';
	};
};

/*
	Implement class Rock
*/
class Rock : public Tool{
public:
	Rock(int strength){
		setStrength(strength);
		type = 'r';
	};
};

int main() {
	// Example main function
	// You may add your own testing code if you like

	Scissors s1(5);
	Paper p1(7);
	Rock r1(15);
	cout << s1.fight(p1) << p1.fight(s1) << endl;
	cout << p1.fight(r1) << r1.fight(p1) << endl;
	cout << r1.fight(s1) << s1.fight(r1) << endl;

	return 0;
}
