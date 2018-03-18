#include <iostream>


using namespace std;

class Calculator
{
	private:
		int cnt_Plus;
		int cnt_Minus;
		int cnt_Multi;
		int cnt_Div;
		
	public:
		void Init(void);
		double Add(double a, double b);
		double Min(double a, double b);
		double Mul(double a, double b);
		double Div(double a, double b);
		void ShowOpCount(void);
};

int main(void)
{
	Calculator cal;
	cal.Init();
	cout<<"3.2 + 2.4 = "<<cal.Add(3.2, 2.4)<<endl;
	cout<<"3.2 - 2.4 = "<<cal.Min(3.2, 2.4)<<endl;
	cout<<"3.2 * 2.4 = "<<cal.Mul(3.2, 2.4)<<endl;
	cout<<"3.2 / 2.4 = "<<cal.Div(3.2, 2.4)<<endl;
 	cal.ShowOpCount();
	return 0;
}

void Calculator::Init(void)
{
	cnt_Plus = 0;
	cnt_Minus = 0;
	cnt_Multi = 0;
	cnt_Div = 0;
}

double Calculator::Add(double a, double b)
{
	cnt_Plus++;
	return a + b;
}

double Calculator::Min(double a, double b)
{
	cnt_Minus++;
	return a - b;
}

double Calculator::Mul(double a, double b)
{
	cnt_Multi++;
	return a * b;
}

double Calculator::Div(double a, double b)
{
	if(b != 0)
	{
		cnt_Div++;
		return a / b;
	}
	
	cout<<"0À¸·Î ³ª´­ ¼ö ¾ø¾î¿ä.."<<endl;
	return 0;
}

void Calculator::ShowOpCount(void)
{
	cout<<"µ¡¼À : "<<cnt_Plus<<"  »¬¼À : "<<cnt_Minus<<"  °ö¼À : "<<cnt_Multi<<"  ³ª´°¼À : "<<cnt_Div<<endl;
}
