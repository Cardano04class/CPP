#include "AForm.hpp"
#include "Bureaucrat.hpp"

AForm::AForm(const std::string &name, int gradeToSign, int gradeToExecute, const std::string &target)
    : _name(name), _isSigned(false), _gradeToSign(gradeToSign), _gradeToExecute(gradeToExecute), _target(target)
{
    if (gradeToSign < 1 || gradeToExecute < 1)
        throw GradeTooHighException();
    if (gradeToSign > 150 || gradeToExecute > 150)
        throw GradeTooLowException();
    std::cout << "AForm Constructor For " << _name << std::endl;
}

AForm::AForm(const AForm &other)
    : _name(other._name), _isSigned(other._isSigned), _gradeToSign(other._gradeToSign),
      _gradeToExecute(other._gradeToExecute), _target(other._target)
{
    std::cout << "AForm Copy Constructor" << std::endl;
}

AForm &AForm::operator=(const AForm &other)
{
    if (this != &other)
        _isSigned = other._isSigned; // only mutable field
    std::cout << "AForm Copy Assignment Operator" << std::endl;
    return *this;
}

AForm::~AForm()
{
    std::cout << "AForm Destructor" << std::endl;
}

const char *AForm::GradeTooHighException::what() const throw()
{
    return "AForm grade Too High";
}

const char *AForm::GradeTooLowException::what() const throw()
{
    return "AForm grade Too Low";
}

const char *AForm::FormNotSignedException::what() const throw()
{
    return "AForm not signed, cannot execute";
}

const std::string &AForm::getName() const
{
    return _name;
}

bool AForm::getIsSigned() const
{
    return _isSigned;
}

int AForm::getGradeToSign() const
{
    return _gradeToSign;
}

int AForm::getGradeToExecute() const
{
    return _gradeToExecute;
}

const std::string &AForm::getTarget() const
{
    return _target;
}

void AForm::beSigned(const Bureaucrat &b)
{
    if (b.getGrade() > _gradeToSign)
        throw GradeTooLowException();
    _isSigned = true;
}

std::ostream &operator<<(std::ostream &out, const AForm &form)
{
    out << "Form name: " << form.getName()
        << ", Signed: " << (form.getIsSigned() ? "Yes" : "No")
        << ", Grade required to sign: " << form.getGradeToSign()
        << ", Grade required to execute: " << form.getGradeToExecute()
        << ", Target: " << form.getTarget();
    return out;
}
