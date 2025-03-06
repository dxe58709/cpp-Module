#include "Form.hpp"

int main()
{
	try {
		Bureaucrat john("John", 1);
		Bureaucrat ken("Ken", 42);
		Bureaucrat nao("Nao", 150);
		std::cout << john << ken << nao;

		Form letter("Letter", 30, 50);//署名は30　実行は50
		Form document("Document", 45, 10);

		std::cout << "====== Letter ========" << std::endl;
		nao.signForm(letter);
		std::cout << letter << std::endl;
		std::cout << "======================" << std::endl;
		john.signForm(letter);
		std::cout << letter << std::endl;
		std::cout << "======================" << std::endl;
		ken.signForm(letter);
		std::cout << letter << std::endl;
		std::cout << "======================" << "\n" << std::endl;

		std::cout << "====== Document ======" << std::endl;
		nao.signForm(document);
		std::cout << document << std::endl;
		std::cout << "======================" << std::endl;
		ken.signForm(document);
		std::cout << document << std::endl;
		std::cout << "======================" << std::endl;
		john.signForm(document);
		std::cout << document << std::endl;
		std::cout << "======================" << std::endl;

	} catch (std::exception &e) {
		std::cerr << "Exception caught: " << e.what() << std::endl;
	}
	return 0;
}