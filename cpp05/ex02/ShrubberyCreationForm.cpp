#include "ShrubberyCreationForm.hpp"

ShrubberyCreationForm::ShrubberyCreationForm(const std::string &target) : AForm("ShrubberyCreationForm", 145, 137, target)
{
    std::cout << "ShrubberyCreationForm constructor for target " << target << std::endl;
}

ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm &other) : AForm(other)
{
    std::cout << "ShrubberyCreationForm copy constructor" << std::endl;
}

ShrubberyCreationForm &ShrubberyCreationForm::operator=(const ShrubberyCreationForm &other)
{
    (void)other;
    std::cout << "ShrubberyCreationForm copy assignment operator" << std::endl;
    return *this;
}

ShrubberyCreationForm::~ShrubberyCreationForm()
{
    std::cout << "ShrubberyCreationForm Destructor" << std::endl;
}

void ShrubberyCreationForm::execute(Bureaucrat const &executor) const
{
    if(!getIsSigned())
        throw FormNotSignedException();
    if(executor.getGrade() > getGradeToExecute())
        throw GradeTooLowException();

    std::ofstream outfile((getTarget() + "_shrubbery").c_str());
    if (!outfile)
    {
        std::cout << "Failed to create file" << std::endl;
        return;
    }

    outfile << "       _-_" << std::endl;
    outfile << "    /~~   ~~\\" << std::endl;
    outfile << " /~~         ~~\\" << std::endl;
    outfile << "{               }" << std::endl;
    outfile << " \\  _-     -_  /" << std::endl;
    outfile << "   ~  \\\\ //  ~" << std::endl;
    outfile << "_- -   | | _- _" << std::endl;
    outfile << "  _ -  | |   -_" << std::endl;
    outfile << "      // \\\\" << std::endl;

    outfile.close();
    std::cout << executor.getName() << " executed ShrubberyCreationForm: file created successfully." << std::endl;
}

