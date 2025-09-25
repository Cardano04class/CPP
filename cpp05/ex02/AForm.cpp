#include "Form.hpp"
#include "Bureaucrat.hpp"

Form::Form(const std::string &name, int gradeToSign, int gradeToExecute) : name(name),isSigned(false), gradeToSign(gradeToSign), gradeToExecute(gradeToExecute)
{
    if (gradeToSign < 1 || gradeToExecute < 1)
        throw GradeTooHighException();
    if (gradeToSign > 150 || gradeToExecute > 150)
        throw GradeTooLowException();
    std::cout << "Form Constructor For " << name << std::endl;
}

Form::Form(const Form& other) : name(other.name), isSigned(other.isSigned), gradeToSign(other.gradeToSign), gradeToExecute(other.gradeToExecute)
{
    std::cout << "Form Copy Constructor" << std::endl;
}

Form &Form::operator=(const Form& other)
{
    if (this != &other)
    {
        this->isSigned = other.isSigned;
    }
    std::cout << "Copy assignment operator" << std::endl;
    return *this;

}

Form::~Form()
{
    std::cout << "Form Destructor" << std::endl;
}

const char* Form::GradeTooHighException::what() const throw()
{
    return "Form grade Too High";
}

const char* Form::GradeTooLowException::what() const throw()
{
    return "Form grade Too Low";
}

const std::string& Form::getName() const{
    return name;
}

bool Form::getIsSigned() const{
    return isSigned;
}

int Form::getGradeToSign() const{
    return gradeToSign;
}

int Form::getGradeToExecute() const{
    return gradeToExecute;
}

void Form::beSigned(const Bureaucrat& b)
{
    if (b.getGrade() > gradeToSign)
        throw GradeTooLowException();
    isSigned = true;
}

std::ostream &operator<<(std::ostream &out, const Form &form)
{
    out << "Form name: " << form.getName()
        << ", Signed: " << (form.getIsSigned() ? "Yes" : "No")
        << ", Grade required to sign: " << form.getGradeToSign()
        << ", Grade required to execute: " << form.getGradeToExecute();
    return out;
}