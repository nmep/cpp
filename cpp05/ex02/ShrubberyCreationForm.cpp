# include "ShrubberyCreationForm.hpp"

ShrubberyCreationForm::ShrubberyCreationForm( void ) :	AForm("default target", 145, 137) {}

ShrubberyCreationForm::ShrubberyCreationForm( const std::string& target ) :	AForm(target, 145, 137) {}

ShrubberyCreationForm::ShrubberyCreationForm( ShrubberyCreationForm& copy ) : AForm(copy.getName() + "_copy", copy.getGradeToSignForm(), copy.getGradeToExecuteForm()) {}

ShrubberyCreationForm::~ShrubberyCreationForm() {}

ShrubberyCreationForm& ShrubberyCreationForm::operator=( ShrubberyCreationForm& rhs )
{
	(void)rhs;
	return *this;
}

void	ShrubberyCreationForm::Create_tree( void )
{
	std::string outputfile_name = this->getName() + "_shrubbery";
	std::ofstream outfile (outputfile_name.c_str());
	outfile << "        /\\\n";
	outfile << "       /\\*\\\n";
	outfile << "      /\\O\\*\\\n";
	outfile << "     /\\/\\/\\/\\\n";
	outfile << "    /\\O\\/\\*\\/\\\n";
	outfile << "   /\\*\\/\\*\\/\\/\\\n";
	outfile << "  /\\O\\/\\/*/\\/O/\\\n";
	outfile << "        ||\n";
	outfile << "        ||\n";
	outfile << "        ||\n";

	outfile.close();
}

void	ShrubberyCreationForm::AFormsActions( Bureaucrat const & executor )
{
	if (!this->getIsSigned() && (executor.getGrade() <= this->getGradeToSignForm() && executor.getGrade() <= this->getGradeToExecuteForm()))
	{
		this->Create_tree();
		this->setIsSigned(1);
		return ;
	}
	throw AForm::GradeTooHighException();
}

std::ostream& operator<<( std::ostream& o, ShrubberyCreationForm& other )
{
	return o << "target = " << other.getName() << " grade to sign = " << other.getGradeToSignForm() << " grade to execute " << other.getGradeToExecuteForm() << std::endl;
}