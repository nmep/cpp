# include "AForm.hpp"

AForm::AForm( void ) : _name("random default Aform"),
					_is_signed(false),
					_grade_to_sign_form(150),
					_grade_to_execute_form(150) {}

AForm::AForm( AForm& copy ) :	_name("random copy Aform"),
							_is_signed(false),
							_grade_to_sign_form(1),
							_grade_to_execute_form(2)
{
	this->_is_signed = copy._is_signed;
}

AForm::AForm( const std::string& name, int grade_ts, int grade_te ) : _name(name),
																	_is_signed(false),
																	_grade_to_sign_form(grade_ts),
																	_grade_to_execute_form(grade_te)
{
	if (grade_ts > 150)
		throw AForm::GradeTooHighException();
	else if (grade_ts < 1)
		throw AForm::GradeTooLowException();
	if (grade_te > 150)
		throw AForm::GradeTooHighException();
	else if (grade_te < 1)
		throw AForm::GradeTooLowException();
}

AForm::~AForm() {}

void	AForm::setIsSigned( bool value )
{
	this->_is_signed = value;
}

const std::string AForm::getName( void ) const
{
	return this->_name;
}

bool	AForm::getIsSigned( void ) const
{
	return this->_is_signed;
}

int	AForm::getGradeToSignForm( void ) const
{
	return this->_grade_to_sign_form;
}

int	AForm::getGradeToExecuteForm( void ) const
{
	return this->_grade_to_execute_form;
}

AForm&	AForm::operator=( AForm& other )
{
	this->_is_signed = other.getIsSigned();
	return *this;
}

const char	*AForm::GradeTooLowException::what( void ) const throw()
{
	return ("the grade of this Aform is too low");
}

const char	*AForm::GradeTooHighException::what( void ) const throw()
{
	return ("the grade of this Aform is too high");
}

void	AForm::beSigned( Bureaucrat& frog )
{
	if (frog.getGrade() > this->getGradeToSignForm() || frog.getGrade() > this->getGradeToExecuteForm())
		return throw AForm::GradeTooLowException();
	if (this->_is_signed == 1)
	{
		std::cout << this->getName() << " is already signed and has been executed" << std::endl;
		return ;
	}
	this->_is_signed = 1;
	std::cout << this->getName() << " this form is now signed by " << frog.getName() << std::endl;
}

void	AForm::execute(Bureaucrat const & executor) const
{
	if (executor.getGrade() <= this->getGradeToExecuteForm() && executor.getGrade() <= this->getGradeToSignForm())
	{
		// apelle la fonction qui va exec le form
	}
	else
	{
		std::cout << executor.getName() << " can't execute the \"" << this->getName() << "\" Form" << std::endl;
		throw AForm::GradeTooHighException();
		// throw exeption
	}
}


std::ostream& operator<<( std::ostream& out, AForm& Aform )
{
	return out << "AForm\n\tName:" << Aform.getName() 
				<< "\n\tIs Signed : " << Aform.getIsSigned() 
				<< "\n\tGrade To Sign It: " << Aform.getGradeToSignForm() 
				<< "\n\tGrade to execute it: " << Aform.getGradeToExecuteForm() << std::endl; 
}

