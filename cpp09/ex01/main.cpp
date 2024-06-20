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
	int	n1, n2, result;
	while (ss >> token)
	{
		if (token.size() > 1)
		{
			std::cerr << "Error: " << token << "\nArgument can only be\n\tNumber: 0 to 10\n\tSigne: + - * or /" << std::endl;
			return 1;
		}
		if (token == "+" || token == "-" || token == "*" || token == "/")
		{
			if (stack.size() <= 1)
			{
				std::cout << "Error: operator need at least two operand to be done" << std::endl;
				return 1;
			}
			// si un calcule est applique il faut prendre les deux operand du haut de la stack et pop le resultat
			n1 = stack.top();
			stack.pop();
			n2 = stack.top();
			stack.pop();
			std::cout << "n1 = " << n1 << " n2 = " << n2 << std::endl;
			// +
			if (token == "+")
			{
				if (n1 > INT_MAX - n2)
				{
					std::cout << n1 << " - " << n2 << " will overflow" << std::endl;
					return 2;
				}
				result = n1 + n2;
				stack.push(result);
			}
			// -
			else if (token == "-")
			{
				result = n1 - n2;
				stack.push(result);
			}
			// *
			else if (token == "*")
			{
				if (n1 > INT_MAX / n2)
				{
					std::cout << n1 << " * " << n2 << " will overflow" << std::endl;
					return 2;
				}
				result = n1 * n2;
				stack.push(result);
			}
			else
			{
				if (n2 == 0)
				{
					std::cerr << "can't be divide by 0" << std::endl;
					return 1;
				}
				result = n1 / n2;
				stack.push(result);
			}
			// /
		}
		else
		{
			for (size_t i = 0; i < token.length(); i++)
			{
				if (token[i] < 48 || token[i] > 57)
				{
					std::cout << "Error: \'" << token << "\' cannot be accepted" << std::endl;
					return 1;
				}
			}
			stack.push(atoi(token.c_str()));
		}
	}
	if (stack.size() != 1)
	{
		std::cerr << "Not enough operator" << std::endl;
		return 1;
	}
	print(stack);
	return (0);
}