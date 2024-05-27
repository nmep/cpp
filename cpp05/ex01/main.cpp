# include "Bureaucrat.hpp"
# include "Form.hpp"

int	main()
{
	Bureaucrat b1;
	Bureaucrat* b2 = NULL;

	try
	{
		Bureaucrat b2("Michel", "151");
	}
	catch (Bureaucrat::GradeTooHighException())
	{
		std::cout << "the grade of " << b2->getName() << " is too high, it's now set to 150" << std::endl;
		b2->setGrade("150");
	}

	std::cout << "b1 " << b1.getName() << std::endl;
	// std::cout << "b2 " << b2.getName() << std::endl;
	std::cout << "set b1 grade to > int max" << std::endl;
	b1.setGrade("2147483648");
	std::cout << "set b1 grade to 0" << std::endl;
	b1.setGrade("0");
	std::cout << "set b1 grade to negative grade" << std::endl;
	b1.setGrade("-1");
	std::cout << "apres " << b1.getGrade() << std::endl;

	try
	{
		b1.incrementGrade();
	}
	catch ( const std::out_of_range& e)
	{
		std::cerr << '\t' << e.what() << '\n';
	}

	try
	{
		b1.decrementGrade();
	}
	catch (const std::out_of_range& e)
	{
		std::cerr << '\t' << e.what() << '\n';
	}
	std::cout << "apres " << b1.getGrade() << std::endl;
	b1.setGrade("1");
	std::cout << "b1 grade set a 1 = " << b1.getGrade() << std::endl;

	try
	{
		b1.incrementGrade();
	}
	catch(const std::exception& e)
	{
		std::cerr << '\t' << e.what() << '\n';
	}

	std::cout << "<< overload" << std::endl;
	std::cout << b1;

	Form	*c = new Form();

	std::cout << "\tgrade can't be instantiate" << std::endl;
	try
	{
		c = new Form("formulaire d'impot", 151, 0);
	}
	catch (Form::GradeTooHighException& e)
	{
		std::cerr << e.what() << std::endl;
		delete c;
	}
	catch (Form::GradeTooLowException& e)
	{
		delete c;
		std::cout << c->getName();
		// delete c;
	}
	Form	form;
	std::cout << "\tForm is signed" << std::endl;
	try
	{
		form.beSigned(b1);
	}
	catch(Form::GradeTooLowException& e)
	{
		std::cerr << e.what() << std::endl;
	}
	std::cout << "\tForm is already signed" << std::endl;
	try
	{
		form.beSigned(b1);
	}
	catch(Form::GradeTooLowException& e)
	{
		std::cerr << e.what() << std::endl;
	}

	Form	form2("formulaire d'impot", 1, 1);
	std::cout << "\tFrog grade can signe this form" << std::endl;
	try
	{
		form2.beSigned(b1);
	}
	catch (Form::GradeTooLowException& e)
	{
		std::cerr << e.what() << std::endl;
	}
	b1.setGrade("3");
	try
	{
		form2.beSigned(b1);
	}
	catch (Form::GradeTooLowException& e)
	{
		std::cerr << e.what() << std::endl;
	}
}