#include <iostream>
#include <string>

using namespace std;

enum dogBREED {Lab, GermanShepheard, GoldenRetriever, FrnechBulldog, Beagle};
enum catBREED {MaineCoon, Bengal, Siamese, Siberian, Ragdoll};
enum pigBREED {Berkshire, ChesterWhite, Duroc, Hampshire, Landrace, Potbellied};

class MAMMAL
{
	private:
		int* pItsAge = new int;
		int* pItsWeight = new int;
	
	public:
		MAMMAL(){*pItsAge = 1; *pItsWeight = 5; cout << "MAMMAL Constructor" << endl;}
		~MAMMAL();
		void SetAge(int age) {*pItsAge = age;}
		int GetAge() {return *pItsAge;}
		void SetWeight(int weight) {*pItsWeight = weight;}
		int GetWeight() {return *pItsWeight;}
		void Speak() const {cout << "Unintelligible mammal mumble. ";};
		void Sleep() const {cout << "ahhh, I'm sleeping. ";}
		
};

MAMMAL::~MAMMAL()
{	
	delete pItsAge;
	delete pItsWeight;
	
	pItsAge = NULL;
	pItsWeight = NULL;

	cout << "MAMMAL Destructor" << endl;
}

class DOG:public MAMMAL
{
	private:
		dogBREED itsBreed;
	
	public:
		DOG():itsBreed(Lab) {cout << "DOG Constructor" << endl;}
		~DOG() {cout << "DOG Destructor" << endl;}
		void SetBreed(dogBREED breed) {itsBreed = breed;}
		dogBREED GetBreed() {return itsBreed;}
		void WagTail() const { cout << "Tail wagging. ";}
		void BegForFood() const {cout << "Begging for food. ";}	
		void Speak() const {cout << "Arf, Arf. ";}	
};

class CAT:public MAMMAL
{
	private:
		catBREED itsBreed;
		
	public:
		CAT():itsBreed(Siamese) {cout << "CAT Constructor" << endl;}
		~CAT() {cout << "CAT Destructor" << endl;}
		void SetBreed(catBREED breed) {itsBreed = breed;}
		catBREED GetBreed() {return itsBreed;}	
		void Speak() const {cout << "Meow. ";}
		void Sleep() const {cout << "Prrrr. ";}	
};

class PIG: public MAMMAL
{
	private:
		pigBREED itsBreed;
		
	public:
		PIG():itsBreed(Hampshire) {cout << "PIG Constructor" << endl;}
		~PIG() {cout << "PIG Destructor" << endl;}
		void SetBreed(pigBREED breed) {itsBreed = breed;}
		pigBREED GetBreed() {return itsBreed;}
		void Speak(int soundCt);	
		void Sleep() const {cout << "\"Zzzz\". ";}	
		void BreedType(int breedNum);
};

void PIG::Speak(int soundCt)	
{		
	for (int ctr = 0; ctr < soundCt; ctr++ )
	{
		cout << "Oink ";	
	};
	cout << "." << endl;
}

void PIG::BreedType(int breedNum)
{
	switch (breedNum)
	{
		case 0: {cout << "Berkshire"; break;} 
		case 1: {cout << "ChesterWhite"; break;}
		case 2: {cout << "Duroc"; break;}
		case 3: {cout << "Hampshire"; break;}
		case 4: {cout << "Landrace"; break;}
		case 5: {cout << "Potbellied"; break;}	
	}
}

int main()
{
	DOG fido;	
	cout << "Fido is " << fido.GetAge() << " years old." << endl;
	cout << "Speak Fido... "; fido.Speak(); 
	cout << "\nGood boy. "; fido.WagTail();
	cout << "\nLay down Fido; "; fido.Sleep(); cout << endl << endl;
	
	CAT boots;	
	boots.SetAge(5);
	boots.SetWeight(5);
	cout << "Boots is " << boots.GetAge() << " years old." << endl;
	cout << "And weighs " << boots.GetWeight() << " pounds." << endl;
	cout << "Speak Boots... "; boots.Speak();
	cout << "\nLay down and go to sleep Boots. "; boots.Sleep(); boots.Sleep(); boots.Sleep(); cout << endl << endl;
	
	PIG arnold;
	arnold.SetAge(3);
	arnold.SetBreed(Potbellied);
	arnold.SetWeight(10);
	cout << "Arnold is a " << arnold.GetAge() << " year old, "; arnold.BreedType(arnold.GetBreed());
	cout << " pig who weighs " << arnold.GetWeight() << " pounds." << endl;
	cout << "Soooo-Eeee Arnold... "; arnold.Speak(2);
	cout << "How old are you Arnold? "; arnold.Speak(arnold.GetAge());
	cout << "I know I shouldn't ask, but how much do you weigh Arnold? "; 
	arnold.Speak(arnold.GetWeight());
	cout << "Arnold, are you asleep? "; arnold.Sleep(); cout << endl << endl;
	return 0;
}
