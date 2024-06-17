# include "RPN.hpp"

void	print(std::stack<int>& s)
{
	std::stack<int> copy = s;

	if (copy.empty())
	{
		std::cout << "empty stack, can't print" << std::endl;
		return ;
	}
	while (!copy.empty())
	{
		std::cout << copy.top() << std::endl;
		copy.pop();
	}
}

int	main(int ac, char **av)
{
	if (ac != 2)
	{
		std::cerr << "Usage ./RPN `polish mathematical expressions` (0 <= N < 10)" << std::endl;
		return 1;
	}
	std::stack<int> stack;
	std::stringstream ss(av[1]);
	std::string token;
	// int	n1;
	// int	n2;
	while (ss >> token)
	{
		if (token.size() > 1)
		{
			std::cerr << "Error: " << token << "\nArgument can only be\n\tNumber: 0 to 10\n\tSigne: + - * or /" << std::endl;
			return 1;
		}
		if (token == "+" || token == "-" || token == "*" || token == "/")
		{
			if (stack.size() == 1)
			{
				std::cout << "Error: operator need two operand to be done" << std::endl;
				return 1;
			}
			// +
			// -
			// *
			// /
		}
		for (size_t i = 0; i < token.length(); i++)
		{
			if (token[i] < 48 || token[i] > 57)
			{
				std::cout << "Error: \'" << token << "\' cannot be accepted" << std::endl;
				return 1;
			}
		}
		std::cout << token << std::endl;
	}
	return (0);
}