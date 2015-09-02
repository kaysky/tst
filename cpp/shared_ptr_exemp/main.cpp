/*
 *	Прирем работы с умным указателем
 *
 */
#include <boost/shared_ptr.hpp>
#include <iostream>

using namespace std;

class A
{
	boost::shared_ptr<int> a;
	public:
		A() :a(new int(0) ) { std::cout << "A constructor" << std::endl; }
		// пользовательский конструктор копирования увеличивает счетчик ссылок  только если явно вызвать конструктор копирования локального обьекта
		// конструктор по умолчанию тоже увеличивает счетчик ссылок
		A(const A& ob) :a(ob.a)/* Если убрать инициализацию произойдет удаление указателя и ошибка обращения к памяти */
		{
			std::cout << "copy A constructor" << std::endl;
		}
		~A() { std::cout << "A destructor" << std::endl; }

		void set(int n) { *a = n; }
		int get() { return *a; }
};
/*
 * Копирование по значению обьект не должен изменять свои данные
 * но так как в нем используется указатель, данные изменяются
 * для того чтобы предотвратить изменения по указателю должен быть предусмотрен
 * конструктор копирования
 *
 * Обьекты желательно передовать в функции по константной ссылке
 * */
void fun_change(A a)
{
	std::cout << "changing local value of a: to 20" << std::endl;
	a.set(20);
}


int main(int argc, char *argv[])
{
	std::cout << "test smart ptr programm" << std::endl;
	boost::shared_ptr<A> pa(new A);
	A a;
	a.set(10);

	std::cout << "a = " << a.get() << std::endl;
	fun_change(a);
	std::cout << "a = " << a.get() << std::endl;

	std::cout << "pa count:" << pa.use_count() << std::endl;

	//a(NULL)->get();
	std::cout << "end of the test" << std::endl;
	return 0;
}
