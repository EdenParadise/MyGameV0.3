#include<iostream>
#include<string>
#include<ctime>
using namespace std;

class Equipment;


class Humanoid {
public:
	//Full parameter creation
	Humanoid(string classname,string name,int hp, int dmg, int str)
	{
		this->classname = classname;
		lvl = 1;
		this->name = name;
		this->hp = hp;
		this->dmg = dmg;
		this->str = str;
		this->id = count;

		count++;

		InventoryArray[str];
		FillWithNull();
	}	   
	//Name and class choice creation (FOR PLAYER ONLY)
	Humanoid(string name, int choice)
	{
		switch (choice)		//class choice
		{
		case 1:		//knight
			this->classname = "Knight";
			lvl = 1;
			this->name = name;
			this->hp = 40;
			this->dmg = 7;
			this->str = 8;
			this->id = count;

			count++;
			
			InventoryArray[str];
			FillWithNull();
			break;
		case 2:		//Mage
			this->classname = "Mage";
			lvl = 1;
			this->name = name;
			this->hp = 28;
			this->dmg = 13;
			this->str = 4;
			this->id = count;

			count++;
			
			InventoryArray[str];
			FillWithNull();
			break;
		case 3:		//
			this->classname = "Archer";
			lvl = 1;
			this->name = name;
			this->hp = 32;
			this->dmg = 10;
			this->str = 6;
			this->id = count;

			count++;
			
			InventoryArray[str];
			FillWithNull();
			break;
		}
	}		
	//Default, just creates knight
	Humanoid()
	{
		this->classname = "Knight";
		lvl = 1;
		this->name = name;
		this->hp = 40;
		this->dmg = 7;
		this->str = 8;
		this->id = count;

		

		count++;
		this->InventoryArray[str]; 
		for (int i = 0; i < str; i++)
		{
			 InventoryArray[i] = 0;
		}
		
	}

	//Getters
	string GetClassName(){
		return classname;
	}
	string GetName() {
		return name;
	}
	int GetLvl() {
		return lvl;
	}
	int GetHp() {
		return hp;
	}
	int GetDmg() {
		return dmg;
	}
	int GetStr() {
		return str;
	}
	int GetId() {
		return id;
	}

	static int GetCount(){
		return count;
	}


	//Setters
	void SetClassName(string classname){
		this->classname = classname;
	}
	void SetName(string name) {
		this->name = name;
	}
	void SetLvl(int lvl) {
		this->lvl = lvl;
	}
	void SetHp(int hp) {
		this->hp = hp;
	}
	void SetDmg(int dmg) {
		this->dmg = dmg;
	}
	void SetStr(int str) {
		this->str = str;
	}

	//Methods
		
	//Print humanoid info to console
	void PrintInfo()
	{
		cout << GetName() << " " << GetClassName() << " " << GetLvl()<<endl;
		cout << "Hp: " << GetHp() << endl;
		cout << "Dmg: " << GetDmg() << endl << endl;
		cout << "Inventory: " << invspace << " of " << GetStr() << endl;
	}
	
	//Leveling up, +HP, +DMG, +LVL, +STR
	void LevelUp()
	{
		lvl++;
		hp += 8 + lvl;
		dmg += 4 + lvl;
		lvl % 2 ? str = str : str++;
	}

	void PrintInventoryArray()
	{
		for (int i = 0; i < str; i++)
		{
			cout << InventoryArray[i] << " ";
		}
	}

	//destructor
	~Humanoid()
	{
		delete[]InventoryArray;
	}

	
private:
	void FillWithNull()
	{
		for (int i = 0; i < str; i++)
		{
			InventoryArray[i] = 0;
		}
	}

	int static count;
	string classname = " ";
	string name = " ";
	int lvl = 0;
	int hp = 0;
	int dmg = 0;
	int str = 0;			//strength
	int invspace = 0;

	friend void PrintEquippedItems(Humanoid& entity);
	friend void EquipItem(Humanoid& entity, Equipment& object);

	int id = 0;	
	int* InventoryArray = new int[100];
};

int Humanoid::count = 0;

class Equipment
{
public:
	
	//Full parameter creation
	Equipment(string name, int Bhp, int Bdmg, int weight, int space)
	{
		count++;

		this->name = name;
		this->BonusHp = Bhp;
		this->BonusDmg = Bdmg;
		this->Weight = weight;
		this->Space = space;
		this->id = count;
		EqpStatus = false;
	}
	
	//Getters
	string GetName() {
		return name;
	}
	int GetBonusHp() {
		return BonusHp;
	}
	int GetBonusDmg() {
		return BonusDmg;
	}
	int GetWeight() {
		return Weight;
	}
	int GetSpace() {
		return Space;
	}
	int GetId() {
		return id;
	}
	bool GetEqpStatus()
	{ 
		return EqpStatus;
	}

	static int GetCount()
	{
		return count;
	}

	void PrintInfo()
	{
		cout << "Name: " << GetName() << endl;
		BonusHp != 0 ? cout << "Hp bonus: " << GetBonusHp() << endl : cout << "";
		BonusDmg != 0 ? cout << "Dmg bonus: " << GetBonusDmg() << endl : cout << "";
		cout << "Weight: " << GetWeight() << endl;
		cout << "Space capacity: " << GetSpace() << endl;
		if (EqpStatus)
		{
			cout << "Equipped"<<endl;
		}
		else
		{
			cout << "Unequipped" << endl;
		}
	}

	//Setters
	void SetName(string name) {
		this->name = name;
	}
	void SetBonusHp(int Bhp) {
		this->BonusHp = Bhp;
	}
	void SetBonusDmg(int Bdmg) {
		this->BonusDmg = Bdmg;
	}
	void SetWeight(int Weight) {
		this->Weight = Weight;
	}
	void SetSpace(int Space) {
		this->Space = Space;
	}
	void SetEqpStatus(bool some)
	{
		this->EqpStatus = some;
	}
	
private:
	string name = " ";
	int BonusHp;
	int BonusDmg;
	int Weight;
	int Space;
	int id;
	bool EqpStatus;

	static int count;

	friend void PrintEquippedItems(Humanoid& entity);
	friend void EquipItem(Humanoid& entity, Equipment& object);
	
	

	friend Humanoid;
};

static Equipment* arragorn[20];

int Equipment::count = 0;


void EquipItem(Humanoid& entity, Equipment& object)
{
	if ((object.Weight <= entity.str) && (object.Space <= (entity.str - entity.invspace))&&object.EqpStatus==false)
	{
			int checkSpace = 0;
			for (int j = 0; j < entity.str+1; j++)
			{
				if(entity.InventoryArray[j]==0)
				{
					entity.InventoryArray[j] = object.id;
					checkSpace++;
				}
				if (checkSpace == object.Space)
				{
					break;
				}
			}
		object.EqpStatus = true;
		entity.invspace += object.Space;
		
		entity.SetDmg(entity.GetDmg()+object.GetBonusDmg());
		entity.SetHp(entity.GetHp() + object.GetBonusHp());
		arragorn[object.GetId()] = &object;
	}
	else if(object.Weight > entity.str)
	{
		cout << endl<<"Not enough strenght to equip!"<<endl<<endl;
	}
	else if (object.Space > (entity.str - entity.invspace))
	{
		cout << endl << "Not enough inventory space to equip!" << endl << endl;
	}
	else if (object.EqpStatus != false)
	{
		cout << endl << "Object cannot be equipped!" << endl << endl;
	}
}

void PrintEquippedItems(Humanoid& entity)
{
	for (int i = 1; i <= Equipment::count; i++)
	{
		for (int j = 0; j < entity.str; j++)
		{
			if (entity.InventoryArray[j] == i)
			{
				arragorn[i]->PrintInfo();
				
				cout << endl;
				break;
			}
		}
	}
}

int main()
{
	
	return 0;
}
