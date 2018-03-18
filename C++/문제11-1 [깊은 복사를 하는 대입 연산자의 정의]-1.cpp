#include <iostream>
using namespace std;

class Gun
{
private:
	int bullets;
	
public:
	Gun(int b = 5) : bullets(b) { }
	int get_b() const
	{
		return bullets;
	}
	
	void shoot()
	{
		bullets--;
	}
};

class Police
{
private:
	int handcuffs;
	Gun * pistol;
public:
	Police(int h, int b) : handcuffs(h)
	{
		pistol = new Gun(b);
	}
	
	Police(Police& ref)
	{
		this = ref;
	}
	
	void Shot()
	{
		if(pistol->get_b())
		{
			cout<<"Bang!"<<endl;
			pistol->shoot();
		}else
			cout<<"Tick! No bullet!"<<endl;
	}
	
	void ShowBullets() const
	{
		cout<<"Left bullets : "<<pistol->get_b()<<endl;
	}
	
	Police& operator=(const Police& ref)
	{
		handcuffs = ref.handcuffs;
		if(pistol != NULL)
			delete pistol;
		pistol = new Gun(ref.pistol->get_b());
	}
};

int main(void)
{
	Police kim(2, 6);
	Police sim(3, 5);
	sim = kim;
	sim.ShowBullets();
	sim.Shot();
	sim.Shot();
	sim.Shot();
	sim.Shot();
	sim.Shot();
	sim.Shot();
	sim.Shot();
	
	return 0;
}
