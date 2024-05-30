# include "RobotomyRequestForm.hpp"
#include <time.h>

RobotMyRequestForm::RobotMyRequestForm( void ) : AForm("Robot default target", 72, 45) {}

RobotMyRequestForm::RobotMyRequestForm( const std::string& target ) : AForm(target, 72, 45) {}

RobotMyRequestForm::~RobotMyRequestForm() {}

RobotMyRequestForm::RobotMyRequestForm( RobotMyRequestForm& copy ) : AForm(copy.getName() + "_copy", copy.getGradeToSignForm(), copy.getGradeToExecuteForm()) {}

RobotMyRequestForm& RobotMyRequestForm::operator=( RobotMyRequestForm& rhs )
{
	(void)rhs;
	return *this;
}

void	RobotMyRequestForm::Robotomized( void )
{
	std::cout << "`drilling noise`" << std::endl;
	sleep(1);
	std::cout << "`drilling noise`" << std::endl;
	sleep(1);
	std::cout << "`drilling noise`" << std::endl;
	sleep(2);
	srand(time(0));
	if (rand() % 2 == 1)
		std::cout << this->getName() << " has been robotomized successfully" << std::endl;
	else
		std::cout << this->getName() << " hasn't been robotomized" << std::endl;
}

void	RobotMyRequestForm::AFormsActions( Bureaucrat const & executor )
{
	if (!this->getIsSigned() && (executor.getGrade() <= this->getGradeToSignForm() && executor.getGrade() <= this->getGradeToExecuteForm()))
	{
		this->Robotomized();
		this->setIsSigned(1);
		return ;
	}
	throw AForm::GradeTooHighException();
}

std::ostream& operator<<(std::ostream& o, RobotMyRequestForm& other )
{
	return o << "target = " << other.getName() << " grade to sign = " << other.getGradeToSignForm() << " grade to execute " << other.getGradeToExecuteForm() << std::endl;
}