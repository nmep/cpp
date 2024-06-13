# include "MutanStack.hpp"

int main()
{
	MutantStack<int> mstack;
	int array[4] = {10, 20, 30, 40};
	std::cout << "<< overload" << std::endl;
	std::cout << mstack << std::endl;

	mstack.push(5);
	mstack.push(17);

	std::cout << "<< overload after adding 5 and 17" << std::endl;
	std::cout << mstack << std::endl;

	std::cout << "top return le Last In" << std::endl;
	std::cout << mstack.top() << std::endl;
	
	mstack.pop();
	
	std::cout << "<< overload after pop" << std::endl;
	std::cout << mstack << std::endl;

	std::cout << "size return la taille" << std::endl;
	std::cout << mstack.size() << std::endl;
	
	mstack.push(3);
	mstack.push(5);
	mstack.push(737);
	//[...]
	mstack.push(0);
	
	mstack.push_multiple(array, 2);
	std::cout << "<< overload after multiple push" << std::endl;
	std::cout << mstack << std::endl;

	MutantStack<int>::iterator it = mstack.begin();
	MutantStack<int>::iterator ite = mstack.end();
	++it;
	--it;
	while (it != ite)
	{
		std::cout << *it << std::endl;
		++it;
	}
	
	std::cout << "copy" << std::endl;
	std::stack<int> s(mstack);
	std::cout << "<< overload at the end" << std::endl;
	std::cout << mstack << std::endl;
	return 0;
}
