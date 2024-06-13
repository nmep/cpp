# include "Span.hpp"

int main()
{
	Span sp = Span(5);
	sp.addNumber(6);
	sp.addNumber(3);
	sp.addNumber(17);
	sp.addNumber(9);
	sp.addNumber(11);
	std::cout << "copy must be the same" << std::endl;
	Span copy(sp);
	std::cout << copy;
	std::cout << "shortest" << std::endl;
	std::cout << sp.shortestSpan() << std::endl;
	std::cout << "longest" << std::endl;
	std::cout << sp.longestSpan() << std::endl;
	std::cout << sp;

	Span equal;
	std::cout << equal.getSize() << std::endl;
	equal.printV();
	equal = sp;
	std::cout << equal.getSize() << std::endl;
	equal.printV();
	return 0;
}