#ifndef AFORM_HPP
# define AFORM_HPP

# include "Bureaucrat.hpp"
# include <string>
# include <exception>
# include <iostream>

class Bureaucrat;

class AForm
{
    private: 
        const std::string _name;
        bool _isSigned;
        const int _gradeToSign;
        const int _gradeToExecute;
        const std::string _target;

    public:
        AForm(const std::string& name, int gradeToSign, int gradeToExecute, const std::string& target);
        virtual ~AForm();

        AForm(const AForm &other);
        AForm &operator=(const AForm &other);

        const std::string& getName() const;
        bool getIsSigned() const;
        int getGradeToSign() const;
        int getGradeToExecute() const;
        const std::string& getTarget() const;

        void beSigned(const Bureaucrat& b);

        // Pure virtual → makes AForm abstract
        virtual void execute(Bureaucrat const &executor) const = 0;

        class GradeTooHighException : public std::exception {
            public:
                const char *what() const throw();
        };

        class GradeTooLowException : public std::exception {
            public:
                const char *what() const throw();
        };

        class FormNotSignedException : public std::exception {
            public:
                const char *what() const throw();
        };
};

std::ostream &operator<<(std::ostream &out, const AForm &b);

#endif
