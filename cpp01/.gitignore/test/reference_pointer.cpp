# include <iostream>

using namespace std;

int	main()
{
	int	ball = 42;

	int *ball_ptr = &ball;
	int& ball_ref = *ball_ptr;

	cout << ball << " " << *ball_ptr << " " << ball_ref << endl;

	ball_ref = 2;
	cout << ball << " " << *ball_ptr << " " << ball_ref << endl;

}