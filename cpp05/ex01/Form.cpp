# include "Form.hpp"

Form::Form( void ) : _name("random default form"),
					_is_signed(false),
					_grade_to_sign_form(150),
					_grade_to_execute_form(150) {}

Form::Form( Form& copy ) :	_name("random copy form"),
							_grade_to_sign_form(1),
							_grade_to_execute_form(2)
{
	this->_is_signed = copy._is_signed;
}

Form::Form( const std::string& name, int grade_ts, int grade_te ) : _name(name),
																	_grade_to_sign_form(grade_ts),
																	_grade_to_execute_form(grade_te)
{
	if (grade_ts > 150)
		throw Form::GradeTooHighException();
	else if (grade_ts < 1)
		throw Form::GradeTooLowException();
	if (grade_te > 150)
		throw Form::GradeTooHighException();
	else if (grade_te < 1)
		throw Form::GradeTooLowException();
}

Form::~Form() {}

void	Form::setIsSigned( bool value )
{
	if (value == true)
		this->_is_signed = true;
	else if (value == false)
		this->_is_signed = false;
}

const std::string Form::getName( void ) const
{
	return this->_name;
}

bool	Form::getIsSigned( void ) const
{
	return this->_is_signed;
}

int	Form::getGradeToSignForm( void ) const
{
	return this->_grade_to_sign_form;
}

int	Form::getGradeToExecuteForm( void ) const
{
	return this->_grade_to_execute_form;
}

Form&	Form::operator=( Form& other )
{
	this->_is_signed = other.getIsSigned();
	return *this;
}

const char	*Form::GradeTooLowException::what( void ) const throw()
{
	return ("the grade of this form is too low");
}

const char	*Form::GradeTooHighException::what( void ) const throw()
{
	return ("the grade of this form is too high");
}

void	Form::beSigned( Bureaucrat& frog )
{
	if (frog.getGrade() > this->getGradeToSignForm() || frog.getGrade() > this->getGradeToExecuteForm())
		return throw Form::GradeTooLowException();
	if (this->_is_signed == 1)
	{
		std::cout << this->getName() << " is already signed and has been executed" << std::endl;
		return ;
	}
	this->_is_signed = 1;
	std::cout << this->getName() << " this form is now signed by " << frog.getName() << std::endl;
}

std::ostream& operator<<( std::ostream& out, Form& form )
{
	return out << "Form\n\tName:" << form.getName() 
				<< "\n\tIs Signed : " << form.getIsSigned() 
				<< "\n\tGrade To Sign It: " << form.getGradeToSignForm() 
				<< "\n\tGrade to execute it: " << form.getGradeToExecuteForm() << std::endl; 
}

