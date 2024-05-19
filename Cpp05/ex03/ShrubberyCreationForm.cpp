#include "ShrubberyCreationForm.hpp"
#include <fstream>

ShrubberyCreationForm::ShrubberyCreationForm(void) : AForm::AForm("Shrubbery Creation", 145, 137), Target("Default")
{

}

ShrubberyCreationForm::ShrubberyCreationForm(std::string target) : AForm::AForm("Shrubbery Creation", 145, 137), Target(target)
{

}

ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm& copy) : AForm::AForm("Shrubbery Creation", 145, 137)
{
	*this = copy;
}

ShrubberyCreationForm &ShrubberyCreationForm::operator=(const ShrubberyCreationForm& copy)
{
	if (this != &copy)
		Target = copy.Target;
	return *this; 
}

ShrubberyCreationForm::~ShrubberyCreationForm(void)
{

}

/* void ShrubberyCreationForm::Executor() const
{
	std::ofstream o((Target + ".shrubbery"));

	o << "                                                         .\n";
	o << "                                              .         ;  \n";
	o << "                 .              .              ;%     ;;   \n";
	o << "                   ,           ,                :;%  %;   \n";
	o << "                    :         ;                   :;%;'     .,   \n";
	o << "           ,.        %;     %;            ;        %;'    ,;\n";
	o << "             ;       ;%;  %%;        ,     %;    ;%;    ,%'\n";
	o << "              %;       %;%;      ,  ;       %;  ;%;   ,%;' \n";
	o << "               ;%;      %;        ;%;        % ;%;  ,%;'\n";
	o << "                `%;.     ;%;     %;'         `;%%;.%;'\n";
	o << "                 `:;%.    ;%%. %@;        %; ;@%;%'\n";
	o << "                    `:%;.  :;bd%;          %;@%;'\n";
	o << "                      `@%:.  :;%.         ;@@%;'   \n";
	o << "                        `@%.  `;@%.      ;@@%;         \n";
	o << "                          `@%%. `@%%    ;@@%;        \n";
	o << "                            ;@%. :@%%  %@@%;       \n";
	o << "                              %@bd%%%bd%%:;     \n";
	o << "                                #@%%%%%:;;\n";
	o << "                                %@@%%%::;\n";
	o << "                                %@@@%(o);  . '         \n";
	o << "                                %@@@o%;:(.,'         \n";
	o << "                            `.. %@@@o%::;         \n";
	o << "                               `)@@@o%::;         \n";
	o << "                                %@@(o)::;        \n";
	o << "                               .%@@@@%::;         \n";
	o << "                               ;%@@@@%::;.          \n";
	o << "                              ;%@@@@%%:;;;. \n";
	o << "                          ...;%@@@@@%%:;;;;,..  \n";
	o.close();
} */

void ShrubberyCreationForm::Executor() const 
{
	std::ofstream outFile(this->Target + ".shrubbery");
	if (!outFile) 
	{
		std::cerr << "can't open/create" << this->Target + ".shrubbery" << std::endl;
		return ;
	}
	outFile <<
	"            # #### ####\n"
	"        ### \\/#|### |/####\n"
	"        ##\\/#/ \\||/##/_/##/_#\n"
	"       ###  \\/###|/ \\/ # ###\n"
	"    ##_\\_#\\_\\## | #/###_/_####\n"
	"    ## #### # \\ #| /  #### ##/##\n"
	"    __#_--###`  |{,###---###-~\n"
	"                \\ }{\n"
	"                }}{\n"
	"                }}{\n"
	"        akarafi {{}\n"
	"        , -=-~{ .-^- _\n"
	"                `}\n"
	"                 {"
	<< std::endl;
}

