# include "PresidentialPardonForm.hpp"

PresedientialPardonForm::PresedientialPardonForm( void ) : AForm("default presidiential form", 25, 5) {}

PresedientialPardonForm::PresedientialPardonForm( const std::string& target ) : AForm(target, 25, 5) {}

PresedientialPardonForm::~PresedientialPardonForm() {}

PresedientialPardonForm::PresedientialPardonForm( PresedientialPardonForm& copy ) : AForm(copy.getName() + "_copy", copy.getGradeToSignForm(), copy.getGradeToExecuteForm()) {}

void PresedientialPardonForm::PresidentialApology( void ) const
{
	std::cout << this->getName() << " has been pardoned by Zaphod Beeblebrox" << std::endl;
}

void	PresedientialPardonForm::AFormsActions( Bureaucrat const & executor )
{
	if (!this->getIsSigned() && (executor.getGrade() <= this->getGradeToSignForm() && executor.getGrade() <= this->getGradeToExecuteForm()))
	{
		this->PresidentialApology();
		this->setIsSigned(1);
		return ;
	}
	throw AForm::GradeTooHighException();
}

PresedientialPardonForm&	PresedientialPardonForm::operator=( PresedientialPardonForm& rhs )
{
	(void)rhs;
	return *this;
}

std::ostream& operator<<(std::ostream& o, PresedientialPardonForm& other )
{
	return o << "target = " << other.getName() << " grade to sign = " << other.getGradeToSignForm() << " grade to execute " << other.getGradeToExecuteForm() << std::endl;
}