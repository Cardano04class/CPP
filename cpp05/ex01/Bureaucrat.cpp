#include "Bureaucrat.hpp"
#include "Form.hpp"

Bureaucrat::Bureaucrat(const std::string &name, int grade) : name(name)
{
    if (grade < 1)
        throw GradeTooHighException();
    else if (grade > 150)
        throw GradeTooLowException();
    this->grade = grade;
    std::cout << "Parameterized constructor for " << name << std::endl;
}

Bureaucrat::Bureaucrat(const Bureaucrat &other) : name(other.name), grade(other.grade)
{
    std::cout << "Bureaucrat Copy Constructor" << std::endl;
}

Bureaucrat &Bureaucrat::operator=(const Bureaucrat &other)
{
    if(this != &other)
        this->grade = other.grade;

    std::cout << "Copy Assignment Operator" << std::endl;
    return *this;
}

Bureaucrat::~Bureaucrat(){
    std::cout << "Bureaucrat Destructor for " << name << std::endl;
}

std::string Bureaucrat::getName() const{
    return name;
}

int Bureaucrat::getGrade() const{
    return grade;
}

void Bureaucrat::incrementGrade()
{
    if (grade <= 1)
        throw GradeTooHighException();
    --grade;
    std::cout << name << "'s grade incremented to " << grade << std::endl;
}

void Bureaucrat::decrementGrade()
{
    if (grade >= 150)
        throw GradeTooLowException();
    ++grade;
    std::cout << name << "'s grade decremented to " << grade << std::endl;
}

const char *Bureaucrat::GradeTooHighException::what() const throw()
{
    return "Grade Too High";
}

const char *Bureaucrat::GradeTooLowException::what() const throw()
{
    return "Grade Too Low";
}

std::ostream &operator<<(std::ostream &out, const Bureaucrat &b)
{
    out << b.getName() << " , bureaucrat grade " << b.getGrade();
    return out;
}

void Bureaucrat::signForm(Form &form)
{
    try{
        form.beSigned(*this);
        std::cout << name << " signed " << form.getName() << std::endl;
    }
    catch (std::exception &e)
    {
        std::cout << name << " couldn’t sign " << form.getName() << " because " << e.what() << std::endl;
    }
}
