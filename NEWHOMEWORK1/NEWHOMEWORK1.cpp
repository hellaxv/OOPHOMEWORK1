#include <iostream>
#include <cmath>
#include <cstdint>
#include <cassert> // для assert
#include <iomanip> // для setw

using namespace std;

void obzac()
{
	cout << "\n\n//====================================HomeWork====================================//\n\n";
}

/*newhomework1
Создать класс Power, который содержит два вещественных числа. 
Этот класс должен иметь две переменные-члена для хранения этих вещественных чисел. 
Еще создать два метода: один с именем set, который позволит присваивать значения переменным, 
второй — calculate, который будет выводить результат возведения первого числа в степень второго числа. 
Задать значения этих двух чисел по умолчанию.
*/
class Power
{
private:
	double x_pain;
	double v_pain;
public:
	Power() : x_pain(1.1), v_pain(1.2) {
		setlocale(LC_ALL, "rus");
		cout << "Task 1" << endl;
		cout << "\n" << "Power(Конструктор)\n" << "x_pain - " << x_pain << "\nv_pain - " << v_pain << endl;
	}

	void setPower(double duracel, double energy) {

		x_pain = duracel;
		v_pain = energy;
		cout << "\n" << "setPower:\n" << "first - " << duracel << "\n" << "second - " << energy << endl;
	}

	void calculate()
	{
		setlocale(LC_ALL, "rus");

		cout << "\nРезультат возведения первого числа (first) в степень второго числа (second) = " << pow(x_pain, v_pain) << endl;
	}
	/*newhomework1
	  END
	*/
};



/*newhomework2
Написать класс с именем RGBA, который содержит 4 переменные-члена типа std::uint8_t: m_red, m_green, m_blue и m_alpha 
(#include cstdint для доступа к этому типу). Задать 0 в качестве значения по умолчанию для m_red, m_green, m_blue и 255 для m_alpha. 
Создать конструктор со списком инициализации членов, который позволит пользователю передавать значения для m_red, m_blue, m_green и m_alpha. 
Написать функцию print(), которая будет выводить значения переменных-членов.
*/
class RGBA
{
private:
	uint8_t m_red;
	uint8_t m_green;
	uint8_t m_blue;
	uint8_t m_alpha;

public:
	RGBA() {
		m_red = 0;
		m_green = 0;
		m_blue = 0;
		m_alpha = 255;
	}
	RGBA(uint8_t r, uint8_t g, uint8_t b, uint8_t a) {
		m_red = r;
		m_green = g;
		m_blue = b;
		m_alpha = a;
	}
	void Print()
	{
		std::cout << "r = " << static_cast<int>(m_red) <<
			" g = " << static_cast<int>(m_green) <<
			" b = " << static_cast<int>(m_blue) <<
			" a = " << static_cast<int>(m_alpha) << '\n';
	}
	/*newhomework2
      END
    */
};



/*NEWHOMEWORK3
Написать класс, который реализует функциональность стека. Класс Stack должен иметь:
private-массив целых чисел длиной 10;
private целочисленное значение для отслеживания длины стека;
public-метод с именем reset(), который будет сбрасывать длину и все значения элементов на 0;
public-метод с именем push(), который будет добавлять значение в стек. push() должен возвращать значение false, если массив уже заполнен, и true в противном случае;
public-метод с именем pop() для вытягивания и возврата значения из стека. Если в стеке нет значений, то должно выводиться предупреждение;
public-метод с именем print(), который будет выводить все значения стека.
*/
class Stack
{
private:
	int m_array[10]; // это будут данные нашего стека 
	int m_next; // это будет индексом следующего свободного элемента стека

public:

	void reset()
	{
		m_next = 0;
		for (int i = 0; i < 10; ++i)
			m_array[i] = 0;
	}

	bool push(int value)
	{
		// Если стек уже заполнен, то возвращаем false
		if (m_next == 10)
			return false;

		m_array[m_next++] = value; // присваиваем следующему свободному элементу значение value, а затем увеличиваем m_next
		return true;
	}

	int pop()
	{
		assert(m_next > 0);
		return m_array[--m_next];
	}

	void print()
	{
		std::cout << "( ";
		for (int i = 0; i < m_next; ++i)
			std::cout << m_array[i] << ' ';
		std::cout << ")\n";
	}
	/*newhomework3
	  END
	*/
};






int main()
{
	{   //newhomework1
		obzac();
		Power method;
		method.setPower(6.6, 66.6);
		method.calculate();

	}




	{   //newhomework2
		obzac();
		int ri, gi, bi, ai;

		cout << "m_red = ";
		cin >> ri;
		cout << "m_green = ";
		cin >> gi;
		cout << "m_blue = ";
		cin >> bi;
		cout << "m_alpha = ";
		cin >> ai;
		RGBA rgba((uint8_t(ri)), (uint8_t(gi)), (uint8_t(bi)), (uint8_t(ai)));
		rgba.Print();
	}




	{   //newhomework3
		obzac();

		Stack stack;
		stack.reset();

		stack.print();

		stack.push(3);
		stack.push(7);
		stack.push(5);
		stack.print();

		stack.pop();
		stack.print();

		stack.pop();
		stack.pop();

		stack.print();

	}
	return 0;
};