#include <iostream>

using namespace std;

class Car
{
private:
	int gasolineGauge;
public:
	Car(int gg) : gasolineGauge(gg) {}
	
	int GetGasGauge(void) const
	{
		return gasolineGauge;
	}
	
	void ShowCurrentGauge(void) const
	{
		cout<<"ÀÜ¿© °¡¼Ö¸° : "<<gasolineGauge<<endl;
	}
};

class HybridCar : public Car
{
private:
	int electricGauge;
public:
	HybridCar(int gg, int eg) : Car(gg), electricGauge(eg) {}
	
	int GetElecGauge(void) const
	{
		return electricGauge;
	}
	
	void ShowCurrentGauge(void) const
	{
		Car::ShowCurrentGauge();
		cout<<"ÀÜ¿© Àü±â·® : "<<electricGauge<<endl;
	}
};

class HybridWaterCar : public HybridCar
{
private:
	int waterGauge;
public:
	HybridWaterCar(int gg, int eg, int wg) : HybridCar(gg, eg), waterGauge(wg) {}
	
	void ShowCurrentGauge(void) const
	{
		HybridCar::ShowCurrentGauge();
		cout<<"ÀÜ¿© ¿öÅÍ·® : "<<waterGauge<<endl;
	}
};

int main(void)
{
	Car tico(30);
	tico.ShowCurrentGauge();
	
	cout<<endl;
	
	HybridCar bentz(100, 70);
	bentz.ShowCurrentGauge(); 
	
	cout<<endl;
	
	HybridWaterCar dream(90, 80, 70);
	dream.ShowCurrentGauge();
	return 0;
}
