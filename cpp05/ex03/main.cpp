# include "Bureaucrat.hpp"
# include "ShrubberyCreationForm.hpp"
# include "RobotomyRequestForm.hpp"
# include "PresidentialPardonForm.hpp"
# include "Intern.hpp"

int	main()
{
	// /*-----------------------------------------------------------------------------------------------------------*/
	// // Tree Form
	
	// std::cout << "TREE FORM" << std::endl;
	// Bureaucrat	bTree("bTree");
	// std::cout << bTree;

	// AForm	*treeForm = new ShrubberyCreationForm("home");

	// try
	// {
	// 	treeForm->AFormsActions(bTree);
	// }
	// catch (AForm::GradeTooHighException& e)
	// {
	// 	std::cerr << e.what() << '\n';
	// }

	// std::cout << *treeForm;

	// treeForm->getIsSigned() == 0 ? std::cout << "form " << treeForm->getName() << " Not signed" : std::cout << "form " << treeForm->getName() << " signed" << std::endl;

	// std::cout << "\n" << std::endl;
	// bTree.setGrade("1");
	// try
	// {
	// 	treeForm->AFormsActions(bTree);
	// }
	// catch (AForm::GradeTooHighException& e)
	// {
	// 	std::cerr << e.what() << '\n';
	// }

	// treeForm->getIsSigned() == 0 ? std::cout << "form " << treeForm->getName() << " Not signed" << std::endl : std::cout << "form " << treeForm->getName() << " signed" << std::endl;
	// std::cout << *treeForm;

	// delete treeForm;
	// /*-----------------------------------------------------------------------------------------------------------*/
	// // President form

	// std::cout << "PRESIDENT FORM" << std::endl;
	// std::cout << "\n" << std::endl;

	// AForm	*presidentForm = new PresedientialPardonForm("toto");

	// Bureaucrat bPresident("bPresident");

	// try
	// {
	// 	presidentForm->AFormsActions(bPresident);
	// }
	// catch (AForm::GradeTooHighException& e)
	// {
	// 	std::cerr << e.what() << '\n';
	// }

	// presidentForm->getIsSigned() == 0 ? std::cout << "form " << presidentForm->getName() << " Not signed" << std::endl : std::cout << "form " << presidentForm->getName() << " signed" << std::endl;
	// std::cout << *presidentForm;

	// bPresident.setGrade("1");

	// try
	// {
	// 	presidentForm->AFormsActions(bPresident);
	// }
	// catch (AForm::GradeTooHighException& e)
	// {
	// 	std::cerr << e.what() << '\n';
	// }

	// presidentForm->getIsSigned() == 0 ? std::cout << "form " << presidentForm->getName() << " Not signed" << std::endl : std::cout << "form " << presidentForm->getName() << " signed" << std::endl;
	// std::cout << *presidentForm;

	// delete presidentForm;


	// /*-----------------------------------------------------------------------------------------------------------*/
	// // Robot Form

	// std::cout << "ROBOT FORM" << std::endl;

	// AForm	*robotForm = new RobotMyRequestForm("totoRobot");
	// Bureaucrat bRobot("bRobot");

	// try
	// {
	// 	robotForm->AFormsActions(bRobot);
	// }
	// catch (AForm::GradeTooHighException& e)
	// {
	// 	std::cerr << e.what() << '\n';
	// }

	// robotForm->getIsSigned() == 0 ? std::cout << "form " << robotForm->getName() << " Not signed" << std::endl : std::cout << "form " << robotForm->getName() << " signed" << std::endl;
	// std::cout << *robotForm;

	// bRobot.setGrade("1");

	// try
	// {
	// 	robotForm->AFormsActions(bRobot);
	// }
	// catch (AForm::GradeTooHighException& e)
	// {
	// 	std::cerr << e.what() << '\n';
	// }

	// robotForm->getIsSigned() == 0 ? std::cout << "form " << robotForm->getName() << " Not signed" << std::endl : std::cout << "form " << robotForm->getName() << " signed" << std::endl;
	// std::cout << *robotForm;

	// delete robotForm;

	AForm *a;
    AForm *b;
    AForm *c;

    std::cout << std::endl;

    Intern Arnaldo;

    a = Arnaldo.makeForm("robotoMyRequest", "Ebil");
    std::cout << std::endl;
    b = Arnaldo.makeForm("presidentPardon", "Ebil");
    std::cout << std::endl;
    c = Arnaldo.makeForm("shrubberyCreation", "Ebil");
    std::cout << std::endl;

    Arnaldo.makeForm("foo", "Ebil");
    std::cout << std::endl;

    delete a;
    delete b;
    delete c;
	return 0;
}